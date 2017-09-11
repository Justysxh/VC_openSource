// CaptureAppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CaptureApp.h"
#include "CaptureAppDlg.h"
#include <afxmt.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCaptureAppDlg dialog

CCaptureAppDlg::CCaptureAppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCaptureAppDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCaptureAppDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hVideoWnd = 0;
}

void CCaptureAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCaptureAppDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCaptureAppDlg, CDialog)
	//{{AFX_MSG_MAP(CCaptureAppDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCaptureAppDlg message handlers

BOOL CCaptureAppDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);	
	SetIcon(m_hIcon, FALSE);
	
	AfxBeginThread(ThreadFun,(void*)this);   //开始一个线程

	::WaitForSingleObject(m_Event,INFINITE); //等待线程函数的执行 
	if (capDriverConnect(m_hVideoWnd,0))	 //连接驱动程序
	{
		::SetParent(m_hVideoWnd,*this);      //设置父窗口
		::SetWindowLong(m_hVideoWnd,GWL_STYLE,WS_CHILD);
		::SetWindowPos(m_hVideoWnd,NULL,10,10,
                300,300,SWP_NOZORDER);

		::ShowWindow(m_hVideoWnd,SW_SHOW);
		capPreviewRate(m_hVideoWnd,30); //设置预览速率
		capPreview(m_hVideoWnd,true);	//开始预览
	}
	return TRUE;  
}

//定义线程函数
UINT CCaptureAppDlg::ThreadFun( LPVOID lpParam )
{
	CCaptureAppDlg* pTempDlg = (CCaptureAppDlg*)lpParam;
	if (pTempDlg!= NULL)
	{
		HWND hwnd= capCreateCaptureWindow(NULL,WS_POPUP,0,0,200,300,pTempDlg->m_hWnd,0);
		pTempDlg->m_hVideoWnd = hwnd;
		pTempDlg->m_Event.SetEvent();
		
		MSG msg;
		while(GetMessage(&msg,NULL,0,0))
		{
			  TranslateMessage(&msg);
			  DispatchMessage(&msg);		
		}
		return msg.wParam;
	}
	return 0;
}

void CCaptureAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

void CCaptureAppDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CCaptureAppDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCaptureAppDlg::OnOK() 
{

}
