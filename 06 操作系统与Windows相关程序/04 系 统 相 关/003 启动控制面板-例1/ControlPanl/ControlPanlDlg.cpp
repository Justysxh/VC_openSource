// ControlPanlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ControlPanl.h"
#include "ControlPanlDlg.h"

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
// CControlPanlDlg dialog

CControlPanlDlg::CControlPanlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CControlPanlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CControlPanlDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	internet=AfxGetApp()->LoadIcon(IDI_INTERNET);
	mmsys=AfxGetApp()->LoadIcon(IDI_MMSYS);
	timedate=AfxGetApp()->LoadIcon(IDI_TIMEDATE);
	desk=AfxGetApp()->LoadIcon(IDI_DESK);
	access=AfxGetApp()->LoadIcon(IDI_ACCESS);
	mouse=AfxGetApp()->LoadIcon(IDI_MOUSE);
	keyboard=AfxGetApp()->LoadIcon(IDI_KEYBOARD);
	intl=AfxGetApp()->LoadIcon(IDI_INTL);
	appwiz=AfxGetApp()->LoadIcon(IDI_APPWIZ);
	hdwwiz=AfxGetApp()->LoadIcon(IDI_HDWWIZ);
	sysdm=AfxGetApp()->LoadIcon(IDI_SYSDM);
	telephon=AfxGetApp()->LoadIcon(IDI_TELEPHON);
}

void CControlPanlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CControlPanlDlg)
	DDX_Control(pDX, IDC_BUTTON9, m_button9);
	DDX_Control(pDX, IDC_BUTTON8, m_button8);
	DDX_Control(pDX, IDC_BUTTON7, m_button7);
	DDX_Control(pDX, IDC_BUTTON6, m_button6);
	DDX_Control(pDX, IDC_BUTTON5, m_button5);
	DDX_Control(pDX, IDC_BUTTON4, m_button4);
	DDX_Control(pDX, IDC_BUTTON3, m_button3);
	DDX_Control(pDX, IDC_BUTTON2, m_button2);
	DDX_Control(pDX, IDC_BUTTON12, m_button12);
	DDX_Control(pDX, IDC_BUTTON11, m_button11);
	DDX_Control(pDX, IDC_BUTTON10, m_button10);
	DDX_Control(pDX, IDC_BUTTON1, m_button1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CControlPanlDlg, CDialog)
	//{{AFX_MSG_MAP(CControlPanlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_BN_CLICKED(IDC_BUTTON12, OnButton12)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CControlPanlDlg message handlers

BOOL CControlPanlDlg::OnInitDialog()
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
	SetIcon(m_hIcon, FALSE);	// Set small icon
	
	m_button1.SetIcon(internet);
	m_button1.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_button1.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(0, 0, 200));
		m_button2.SetIcon(mmsys);
	m_button2.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_button2.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(0, 0, 200));
		m_button3.SetIcon(timedate);
	m_button3.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_button3.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(0, 0, 200));
		m_button4.SetIcon(desk);
	m_button4.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_button4.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(0, 0, 200));
		m_button5.SetIcon(access);
	m_button5.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_button5.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(0, 0, 200));
		m_button6.SetIcon(mouse);
	m_button6.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_button6.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(0, 0, 200));
		m_button7.SetIcon(keyboard);
	m_button7.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_button7.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(0, 0, 200));
		m_button8.SetIcon(intl);
	m_button8.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_button8.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(0, 0, 200));
		m_button9.SetIcon(appwiz);
	m_button9.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_button9.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(0, 0, 200));
		m_button10.SetIcon(hdwwiz);
	m_button10.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_button10.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(0, 0, 200));
		m_button11.SetIcon(sysdm);
	m_button11.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_button11.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(0, 0, 200));
		m_button12.SetIcon(telephon);
	m_button12.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_button12.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(0, 0, 200));
	
	  return TRUE;  // return TRUE  unless you set the focus to a control
}

void CControlPanlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CControlPanlDlg::OnPaint() 
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
HCURSOR CControlPanlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CControlPanlDlg::OnButton1() 
{
	//打开 IE4 的设置窗口
	::ShellExecute(NULL,"OPEN","rundll32.exe","shell32.dll Control_RunDLL inetcpl.cpl",NULL,SW_SHOW);
}

void CControlPanlDlg::OnButton2() 
{
	//打开 声音的设置窗口
	::ShellExecute(NULL,"OPEN","rundll32.exe","shell32.dll Control_RunDLL mmsys.cpl @1",NULL,SW_SHOW);
}

void CControlPanlDlg::OnButton3() 
{
	//启动日期和时间设置
	::ShellExecute(NULL,"OPEN","rundll32.exe","shell32.dll Control_RunDLL timedate.cpl",NULL,SW_SHOW);
}

void CControlPanlDlg::OnButton4() 
{
	//启动显示设置面板
	::ShellExecute(NULL,"OPEN","rundll32.exe","shell32.dll Control_RunDLL desk.cpl",NULL,SW_SHOW);
}

void CControlPanlDlg::OnButton5() 
{
	//启动辅助选项
	::ShellExecute(NULL,"OPEN","rundll32.exe","shell32.dll Control_RunDLL access.cpl",NULL,SW_SHOW);
}

void CControlPanlDlg::OnButton6() 
{
	//打开鼠标设置
	::ShellExecute(NULL,"OPEN","rundll32.exe","shell32.dll Control_RunDLL main.cpl @0",NULL,SW_SHOW);
}

void CControlPanlDlg::OnButton7() 
{
	//启动键盘设置
	::ShellExecute(NULL,"OPEN","rundll32.exe","shell32.dll Control_RunDLL main.cpl @1",NULL,SW_SHOW);
}

void CControlPanlDlg::OnButton8() 
{
	//打开区域设置
	::ShellExecute(NULL,"OPEN","rundll32.exe","shell32.dll Control_RunDLL intl.cpl",NULL,SW_SHOW);
}

void CControlPanlDlg::OnButton9() 
{
	//启动添加软件设置
	::ShellExecute(NULL,"OPEN","rundll32.exe","shell32.dll Control_RunDLL appwiz.cpl",NULL,SW_SHOW);
}

void CControlPanlDlg::OnButton10() 
{
	//启动添加硬件设置
	::ShellExecute(NULL,"OPEN","rundll32.exe","shell32.dll Control_RunDLL hdwwiz.cpl",NULL,SW_SHOW);
}

void CControlPanlDlg::OnButton11() 
{
	//打开系统设置
	::ShellExecute(NULL,"OPEN","rundll32.exe","shell32.dll Control_RunDLL sysdm.cpl",NULL,SW_SHOW);
}

void CControlPanlDlg::OnButton12() 
{
	//启动调制解调器设置
	::ShellExecute(NULL,"OPEN","rundll32.exe","shell32.dll Control_RunDLL modem.cpl",NULL,SW_SHOW);
}
