// HideMyComputerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HideMyComputer.h"
#include "HideMyComputerDlg.h"

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
// CHideMyComputerDlg dialog

CHideMyComputerDlg::CHideMyComputerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHideMyComputerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHideMyComputerDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	computer = AfxGetApp()->LoadIcon(IDI_COMPUTER);
	recycle = AfxGetApp()->LoadIcon(IDI_RECYCLE);
	network = AfxGetApp()->LoadIcon(IDI_NETWORK);
}

void CHideMyComputerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHideMyComputerDlg)
	DDX_Control(pDX, IDC_BTSHOWRECY, m_srecy);
	DDX_Control(pDX, IDC_BTSHOWNET, m_snet);
	DDX_Control(pDX, IDC_BTSHOWCOMPUTER, m_scomputer);
	DDX_Control(pDX, IDC_BTHIDERECY, m_hrecy);
	DDX_Control(pDX, IDC_BTHIDENET, m_hnet);
	DDX_Control(pDX, IDC_BTHIDECOMPUTER, m_hcomputer);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHideMyComputerDlg, CDialog)
	//{{AFX_MSG_MAP(CHideMyComputerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTHIDECOMPUTER, OnHideComputer)
	ON_BN_CLICKED(IDC_BTSHOWCOMPUTER, OnShowComputer)
	ON_BN_CLICKED(IDC_BTHIDERECY, OnHideRecy)
	ON_BN_CLICKED(IDC_BTSHOWRECY, OnShowRecy)
	ON_BN_CLICKED(IDC_BTHIDENET, OnHideNet)
	ON_BN_CLICKED(IDC_BTSHOWNET, OnShowNet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHideMyComputerDlg message handlers

BOOL CHideMyComputerDlg::OnInitDialog()
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
	
	m_hcomputer.SetIcon(computer);
	m_hcomputer.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_hcomputer.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0, 0, 200));
	m_scomputer.SetIcon(computer);
	m_scomputer.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_scomputer.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(0, 0, 200));
	m_hrecy.SetIcon(recycle);
	m_hrecy.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_hrecy.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(0, 0, 200));
	m_srecy.SetIcon(recycle);
	m_srecy.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_srecy.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(0, 0, 200));
	m_hnet.SetIcon(network);
	m_hnet.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_hnet.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(0, 0, 200));
	m_snet.SetIcon(network);
	m_snet.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_snet.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(0, 0, 200));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHideMyComputerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CHideMyComputerDlg::OnPaint() 
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
HCURSOR CHideMyComputerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CHideMyComputerDlg::OnHideComputer() 
{
	//隐藏我的电脑
	HKEY sub;
	DWORD val=0xffffffff;
	CString skey="CLSID\\{20D04FE0-3AEA-1069-A2D8-08002B30309D}\\ShellFolder";
	::RegCreateKey(HKEY_CLASSES_ROOT,skey,&sub);
	RegSetValueEx(sub,"Attributes",NULL,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	::RegCloseKey(sub);
}

void CHideMyComputerDlg::OnShowComputer() 
{
	// 显示我的电脑
	HKEY sub;
	DWORD val=0;
	CString skey="CLSID\\{20D04FE0-3AEA-1069-A2D8-08002B30309D}\\ShellFolder";
	::RegCreateKey(HKEY_CLASSES_ROOT,skey,&sub);
	RegSetValueEx(sub,"Attributes",NULL,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	::RegCloseKey(sub);
}

void CHideMyComputerDlg::OnHideRecy() 
{
	//隐藏回收站 

	CString skey="Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Desktop\\NameSpace\\{645FF040-5081-101B-9F08-00AA002F954E}";
	LONG ReturnValue=::RegDeleteKey(HKEY_LOCAL_MACHINE,skey);
	if(ReturnValue!=ERROR_SUCCESS)
	{
	AfxMessageBox("隐藏失败");
	}

}

void CHideMyComputerDlg::OnShowRecy() 
{
	// 显示回收站
	HKEY sub;
	CString skey="Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Desktop\\NameSpace\\{645FF040-5081-101B-9F08-00AA002F954E}";
	LONG ReturnValue=::RegCreateKey(HKEY_LOCAL_MACHINE,skey,&sub);
	if(ReturnValue!=ERROR_SUCCESS)
	{
		AfxMessageBox("创建注册表项失败");
	}
	::RegCloseKey(sub);
}

void CHideMyComputerDlg::OnHideNet() 
{
	// 隐藏网上邻居
	HKEY sub;
	DWORD val=1;
	CString skey="Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\";
	::RegCreateKey(HKEY_CURRENT_USER,skey,&sub);
	RegSetValueEx(sub,"NoNetHood",NULL,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	::RegCloseKey(sub);
}

void CHideMyComputerDlg::OnShowNet() 
{
	// 显示网上邻居
	HKEY sub;
	DWORD val=0;
	CString skey="Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\";
	::RegCreateKey(HKEY_CURRENT_USER,skey,&sub);
	RegSetValueEx(sub,"NoNetHood",NULL,REG_DWORD,(BYTE*)&val,sizeof(DWORD));
	::RegCloseKey(sub);
}
