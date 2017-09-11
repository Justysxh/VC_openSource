// CDAutoRunDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CDAutoRun.h"
#include "CDAutoRunDlg.h"

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
// CCDAutoRunDlg dialog

CCDAutoRunDlg::CCDAutoRunDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCDAutoRunDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCDAutoRunDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCDAutoRunDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCDAutoRunDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCDAutoRunDlg, CDialog)
	//{{AFX_MSG_MAP(CCDAutoRunDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_FORBID, OnForbid)
	ON_BN_CLICKED(IDC_START, OnStart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCDAutoRunDlg message handlers

BOOL CCDAutoRunDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCDAutoRunDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCDAutoRunDlg::OnPaint() 
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
HCURSOR CCDAutoRunDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCDAutoRunDlg::OnForbid() 
{
	DWORD cb;
	HKEY sub;
	DWORD c=0;
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES); 
    sa.bInheritHandle = TRUE; 
    sa.lpSecurityDescriptor = NULL;
	CString skey="System\\CurrentControlSet\\Services\\Cdrom";
	::RegCreateKeyEx(HKEY_LOCAL_MACHINE,skey,0L,"",REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,&sa,&sub,&cb);
	RegSetValueEx(sub,"Autorun",NULL,REG_DWORD,(BYTE*)&c,sizeof(DWORD));
	//CString skey="Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer";
	//RegCreateKey(HKEY_CURRENT_USER,skey,&sub);
	//DWORD value=0x10111101;//禁止软件自动运行，CD可以自动运行
	//RegSetValueEx(sub,"Autorun",NULL,REG_DWORD,(BYTE*)&value,sizeof(DWORD));
	RegCloseKey(sub);
}

void CCDAutoRunDlg::OnStart() 
{
	HKEY sub;
	DWORD c=1;
	CString skey="System\\CurrentControlSet\\Services\\Cdrom";
	::RegCreateKey(HKEY_LOCAL_MACHINE,skey,&sub);
	RegSetValueEx(sub,"Autorun",NULL,REG_DWORD,(BYTE*)&c,sizeof(DWORD));
	//CString skey="Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer";
	//RegCreateKey(HKEY_CURRENT_USER,skey,&sub);
	//DWORD value=0x10010101;//恢复默认值
	//RegSetValueEx(sub,"Autorun",NULL,REG_DWORD,(BYTE*)&value,sizeof(DWORD));
	RegCloseKey(sub);
}
