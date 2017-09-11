// ParamExeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ParamExe.h"
#include "ParamExeDlg.h"

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
// CParamExeDlg dialog

CParamExeDlg::CParamExeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CParamExeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CParamExeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CParamExeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CParamExeDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CParamExeDlg, CDialog)
	//{{AFX_MSG_MAP(CParamExeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BACKUP, OnBackup)
	ON_BN_CLICKED(IDC_DETATCH, OnDetatch)
	ON_BN_CLICKED(IDC_STOPSERVER, OnStopserver)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CParamExeDlg message handlers

BOOL CParamExeDlg::OnInitDialog()
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

void CParamExeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CParamExeDlg::OnPaint() 
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
HCURSOR CParamExeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CParamExeDlg::OnOK() 
{

}

//备份数据库
void CParamExeDlg::OnBackup() 
{
	SECURITY_ATTRIBUTES ProSec,ThreadSec;
	
	ProSec.bInheritHandle = TRUE;
	ProSec.nLength = sizeof(ProSec);
	
	ThreadSec.bInheritHandle = TRUE;
	ThreadSec.nLength = sizeof(ThreadSec);

	STARTUPINFO StrInfo;
	memset(&StrInfo,0,sizeof(StrInfo));
	StrInfo.cb = sizeof(StrInfo);
	PROCESS_INFORMATION ProcInfo;

	CreateProcess("DataManage.exe","备份数据*master*c:\\master.bak",NULL,NULL,TRUE,NORMAL_PRIORITY_CLASS|CREATE_NEW_CONSOLE,NULL,NULL,&StrInfo,&ProcInfo);
}

//分离数据库
void CParamExeDlg::OnDetatch() 
{
	SECURITY_ATTRIBUTES ProSec,ThreadSec;
	
	ProSec.bInheritHandle = TRUE;
	ProSec.nLength = sizeof(ProSec);
	
	ThreadSec.bInheritHandle = TRUE;
	ThreadSec.nLength = sizeof(ThreadSec);

	STARTUPINFO StrInfo;
	memset(&StrInfo,0,sizeof(StrInfo));
	StrInfo.cb = sizeof(StrInfo);
	PROCESS_INFORMATION ProcInfo;

	CreateProcess("DataManage.exe","分离数据*pubs",NULL,NULL,TRUE,NORMAL_PRIORITY_CLASS|CREATE_NEW_CONSOLE,NULL,NULL,&StrInfo,&ProcInfo);
}

void CParamExeDlg::OnStopserver() 
{
	SECURITY_ATTRIBUTES ProSec,ThreadSec;
	
	ProSec.bInheritHandle = TRUE;
	ProSec.nLength = sizeof(ProSec);
	
	ThreadSec.bInheritHandle = TRUE;
	ThreadSec.nLength = sizeof(ThreadSec);

	STARTUPINFO StrInfo;
	memset(&StrInfo,0,sizeof(StrInfo));
	StrInfo.cb = sizeof(StrInfo);
	PROCESS_INFORMATION ProcInfo;

	CreateProcess("DataManage.exe","停止服务",NULL,NULL,TRUE,NORMAL_PRIORITY_CLASS|CREATE_NEW_CONSOLE,NULL,NULL,&StrInfo,&ProcInfo);
	
}
