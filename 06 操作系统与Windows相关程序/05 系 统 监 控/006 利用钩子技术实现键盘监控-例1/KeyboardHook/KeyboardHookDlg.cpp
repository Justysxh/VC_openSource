// KeyboardHookDlg.cpp : implementation file
//

#include "stdafx.h"
#include "KeyboardHook.h"
#include "KeyboardHookDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
HHOOK hKeyHook;
LRESULT CALLBACK KeyHook(int code,WPARAM wParam,LPARAM lParam);
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
// CKeyboardHookDlg dialog

CKeyboardHookDlg::CKeyboardHookDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKeyboardHookDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CKeyboardHookDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKeyboardHookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKeyboardHookDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CKeyboardHookDlg, CDialog)
	//{{AFX_MSG_MAP(CKeyboardHookDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKeyboardHookDlg message handlers

BOOL CKeyboardHookDlg::OnInitDialog()
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	hKeyHook=SetWindowsHookEx(WH_KEYBOARD,(HOOKPROC)KeyHook,(HINSTANCE)AfxGetApp()->m_hInstance,0);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CKeyboardHookDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CKeyboardHookDlg::OnPaint() 
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

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CKeyboardHookDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CKeyboardHookDlg::DestroyWindow() 
{
	UnhookWindowsHookEx(hKeyHook);
	return CDialog::DestroyWindow();
}
LRESULT CALLBACK KeyHook(int code,WPARAM wParam,LPARAM lParam)
{

	char *strkey;	
	switch(wParam)
	{
	case '1':strkey="1";break;
	case '2':strkey="2";break;
	case '3':strkey="3";break;
	case '4':strkey="4";break;	
	case '5':strkey="5";break;
	case '6':strkey="6";break;
	case '7':strkey="7";break;
	case '8':strkey="8";break;
	case '9':strkey="9";break;
	case '0':strkey="0";break;
	case 'A':strkey="a";break;
	case 'B':strkey="b";break;
	case 'C':strkey="c";break;
	case 'D':strkey="d";break;
	case 'E':strkey="e";break;
	case 'F':strkey="f";break;
	case 'G':strkey="g";break;
	case 'H':strkey="h";break;
	case 'I':strkey="i";break;
	case 'J':strkey="j";break;
	case 'K':strkey="k";break;
	case 'L':strkey="l";break;
	case 'M':strkey="m";break;
	case 'N':strkey="n";break;
	case 'O':strkey="o";break;
	case 'P':strkey="p";break;
	case 'Q':strkey="q";break;
	case 'R':strkey="r";break;
	case 'S':strkey="s";break;
	case 'T':strkey="t";break;
	case 'U':strkey="u";break;
	case 'V':strkey="v";break;
	case 'W':strkey="w";break;
	case 'X':strkey="x";break;
	case 'Y':strkey="y";break;
	case 'Z':strkey="z";break;
	case VK_BACK:strkey="back";break;
	case VK_MENU:strkey="alt";break;
	case VK_F1:strkey="f1";break;
	case VK_F2:strkey="f2";break;
	case VK_F3:strkey="f3";break;
	case VK_F4:strkey="f4";break;
	case VK_F5:strkey="f5";break;
	case VK_F6:strkey="f6";break;
	case VK_F7:strkey="f7";break;
	case VK_F8:strkey="f8";break;
	case VK_F9:strkey="f9";break;
	case VK_F10:strkey="f10";break;
	case VK_F11:strkey="f11";break;
	case VK_F12:strkey="f12";break;
	case VK_CAPITAL:strkey="";break;
	case VK_CONTROL:strkey="control";break;
	case VK_DELETE:strkey="delete";break;
	case VK_DOWN:strkey="down";break;
	case VK_RETURN:strkey="enter";break;
	case VK_ESCAPE:strkey="escape";break;
	case VK_HOME:strkey="home";break;
	case VK_INSERT:strkey="insert";break;
	case VK_NEXT:strkey="pagedown";break;
	case VK_PAUSE:strkey="pause";break;
	case VK_PRIOR:strkey="pageup";break;
	case VK_SNAPSHOT:strkey="printscreen";break;
	case VK_SPACE:strkey="space";break;
	case VK_TAB:strkey="tab";break;
	case VK_SCROLL:strkey="scrolllock";break;
	case VK_NUMPAD1:strkey="1";break;
	case VK_NUMPAD2:strkey="2";break;
	case VK_NUMPAD3:strkey="3";break;
	case VK_NUMPAD4:strkey="4";break;
	case VK_NUMPAD5:strkey="5";break;
	case VK_NUMPAD6:strkey="6";break;
	case VK_NUMPAD7:strkey="7";break;
	case VK_NUMPAD8:strkey="8";break;
	case VK_NUMPAD9:strkey="9";break;
	case VK_NUMPAD0:strkey="0";break;
	case VK_END:strkey="end";break;
	case VK_LEFT:strkey="left";break;
	case VK_UP:strkey="up";break;
	case VK_RIGHT:strkey="right";break;
	case VK_NUMLOCK:strkey="numlock";break;
	case VK_ADD:strkey="+";break;
	case VK_DIVIDE:strkey="/";break;
	case VK_SUBTRACT:strkey="-";break;
	case VK_MULTIPLY:strkey="*";break;
	case VK_DECIMAL:strkey=".";break;
	}
	MessageBox(NULL,strkey,"¼üÅÌ°´¼ü",MB_OK);
	return 0;
}
