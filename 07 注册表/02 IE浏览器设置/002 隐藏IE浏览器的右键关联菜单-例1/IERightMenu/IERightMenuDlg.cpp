// IERightMenuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "IERightMenu.h"
#include "IERightMenuDlg.h"

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
// CIERightMenuDlg dialog

CIERightMenuDlg::CIERightMenuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIERightMenuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIERightMenuDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIERightMenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIERightMenuDlg)
	DDX_Control(pDX, IDC_SHOW, m_show);
	DDX_Control(pDX, IDC_HIDE, m_hide);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CIERightMenuDlg, CDialog)
	//{{AFX_MSG_MAP(CIERightMenuDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_HIDE, OnHide)
	ON_BN_CLICKED(IDC_SHOW, OnShow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIERightMenuDlg message handlers

BOOL CIERightMenuDlg::OnInitDialog()
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

	m_hide.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_hide.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0, 0, 200));

	m_show.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_show.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0, 0, 200));
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CIERightMenuDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CIERightMenuDlg::OnPaint() 
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
HCURSOR CIERightMenuDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CIERightMenuDlg::OnHide() 
{
	HKEY sub;
	DWORD cb;
	DWORD val=1;
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES); 
    sa.bInheritHandle = TRUE; 
    sa.lpSecurityDescriptor = NULL;
	CString skey="Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions";
	::RegCreateKeyEx(HKEY_CURRENT_USER,skey,0L,
		"",REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,&sa,&sub,&cb);
	RegSetValueEx(sub,"NoBrowserContextMenu",NULL,REG_DWORD,(BYTE*)&val,sizeof(DWORD));	
}

void CIERightMenuDlg::OnShow() 
{
	HKEY sub;
	DWORD cb;
	DWORD val=0;
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES); 
    sa.bInheritHandle = TRUE; 
    sa.lpSecurityDescriptor = NULL;
	CString skey="Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions";
	::RegCreateKeyEx(HKEY_CURRENT_USER,skey,0L,
		"",REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,&sa,&sub,&cb);
	RegSetValueEx(sub,"NoBrowserContextMenu",NULL,REG_DWORD,(BYTE*)&val,sizeof(DWORD));		
}
