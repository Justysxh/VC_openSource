// TimeDIY.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "TimeDIY.h"
#include "TimeDIYDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTimeDIYApp
HHOOK  hWndHook ;
int CDrawButton::m_Style = 1;

LRESULT __stdcall DefWindowProc1(HWND hWnd,UINT Msg,WPARAM wParam, 
								 LPARAM lParam )
{
	CPoint pt;
	CDrawButton *pButton=(CDrawButton*)GetWindowLong(hWnd,GWL_USERDATA);
	switch (Msg)
	{
	case WM_LBUTTONDBLCLK:  //屏蔽双击事件
		{
			return TRUE;
			break;
		}
		case WM_PAINT:
			{
				if (pButton->m_Style>0)
					return pButton->OnPaint( hWnd);
				else
					return  CallWindowProc(pButton->m_OldProc, hWnd,Msg,wParam,lParam);
				break;
			}
		case WM_LBUTTONDOWN:
			{
				pt.x = LOWORD(lParam);
				pt.y = HIWORD(lParam);
				if (pButton->m_Style>0)
					return pButton->OnLButtonDown( hWnd, 0, pt );
				else
					return  CallWindowProc(pButton->m_OldProc, hWnd,Msg,wParam,lParam);
				break;
			}
		case WM_LBUTTONUP:
			{
				pt.x = LOWORD(lParam);
				pt.y = HIWORD(lParam);
				if (pButton->m_Style>0)
					return pButton->OnLButtonUp( hWnd, 0,pt );
				else
					return  CallWindowProc(pButton->m_OldProc, hWnd,Msg,wParam,lParam);
				break;
			}
		case WM_MOUSEMOVE:
			{

				pt.x = LOWORD(lParam);
				pt.y = HIWORD(lParam);
				if (pButton->m_Style>0)
					return pButton->OnMouseMove(hWnd,0, pt);
				else
					return  CallWindowProc(pButton->m_OldProc, hWnd,Msg,wParam,lParam);

				break;
			}

		case WM_DESTROY:
			{				
			  	 WNDPROC procOld=pButton->m_OldProc;
				 SetWindowLong(hWnd,GWL_WNDPROC,(long)procOld); //恢复原来的窗口函数

				 pButton->m_Flag = 1;
			     LRESULT ret = ::CallWindowProc(procOld,hWnd,Msg,wParam,lParam);
				 return ret;
			}
		default :
			{
				break;
			}
	}
	return CallWindowProc(pButton->m_OldProc, hWnd, Msg, wParam, lParam );
}


//定义钩子函数
LRESULT CALLBACK HOOKProc( int nCode, WPARAM wParam, LPARAM lParam )
{
	PCWPSTRUCT	wc = (PCWPSTRUCT) lParam;
	HWND  hWnd = wc->hwnd;
	if( hWnd ) 
	{
		char ClassName[MAX_PATH] = "";
		GetClassName( hWnd, ClassName, MAX_PATH );
		if( strcmp( ClassName, "Button" ) == 0 )
		{
			CWnd	*pWnd = CWnd::FromHandle( hWnd );
			BOOL IsGroupButton = pWnd->GetStyle()&BS_GROUPBOX;

			WNDPROC	WndProc;
			WndProc = (WNDPROC) GetWindowLong( hWnd, GWL_WNDPROC );
			
			CDrawButton *pButton=(CDrawButton*)GetWindowLong(hWnd,GWL_USERDATA);
			if (pButton != NULL&& pButton->m_Flag==1 )
			{
				SetWindowLong(hWnd,GWL_USERDATA,0);
				SetWindowLong( hWnd, GWL_WNDPROC, (LONG)pButton->m_OldProc );

				
				pButton->m_OldProc = NULL;
				delete pButton;
			}
			else if (pButton == NULL ) 
			{
				if( WndProc !=DefWindowProc1 )
				{
					if (!IsGroupButton )
					{
						pButton = new CDrawButton;
						pButton->m_OldProc = WndProc;
						SetWindowLong(hWnd,GWL_USERDATA,(long)pButton);
						WndProc =  (WNDPROC) SetWindowLong( hWnd, GWL_WNDPROC, (LONG) DefWindowProc1);
					}
				}
			}
		}
	}
	return CallNextHookEx( hWndHook, nCode, wParam, lParam );
}

//安装钩子
BOOL  RunHook( HMODULE hModule, DWORD dwThreadID)
{
	hWndHook = SetWindowsHookEx(
		WH_CALLWNDPROC, (HOOKPROC) HOOKProc, hModule, dwThreadID );
	return TRUE;
}

//卸载钩子
BOOL  StopHook()
{
	UnhookWindowsHookEx(hWndHook);
	return TRUE;
}

BEGIN_MESSAGE_MAP(CTimeDIYApp, CWinApp)
	//{{AFX_MSG_MAP(CTimeDIYApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimeDIYApp construction

CTimeDIYApp::CTimeDIYApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTimeDIYApp object

CTimeDIYApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CTimeDIYApp initialization

BOOL CTimeDIYApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
	HINSTANCE hModule = GetModuleHandle( NULL );
	RunHook ( hModule, GetCurrentThreadId() );


	CTimeDIYDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CTimeDIYApp::ExitInstance() 
{
	StopHook();		
	return CWinApp::ExitInstance();
}
