// StartIEDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StartIE.h"
#include "StartIEDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "malloc.h"

#define WM_ONTRAY WM_USER+1111
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
// CStartIEDlg dialog

CStartIEDlg::CStartIEDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStartIEDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStartIEDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStartIEDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStartIEDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CStartIEDlg, CDialog)
	//{{AFX_MSG_MAP(CStartIEDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTSET, OnSet)
	ON_BN_CLICKED(IDC_BTEXIT, OnExit)
	ON_MESSAGE(WM_ONTRAY,OnTray)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStartIEDlg message handlers

BOOL CStartIEDlg::OnInitDialog()
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
	
	NOTIFYICONDATA data;
	data.hWnd=m_hWnd;
	data.uCallbackMessage=WM_ONTRAY;
	data.uFlags=NIF_MESSAGE|NIF_ICON;
	data.hIcon=m_hIcon;
	data.uID=IDR_MAINFRAME;
	Shell_NotifyIcon(NIM_ADD,&data);
	GetDlgItem(IDC_EDADDRESS)->SetWindowText("http://www.mingrisoft.com");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CStartIEDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	//if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	//{
	//	CAboutDlg dlgAbout;
	//	dlgAbout.DoModal();
	//}
	if(nID==SC_CLOSE)
	{
		ShowWindow(SW_HIDE);
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CStartIEDlg::OnPaint() 
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
HCURSOR CStartIEDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CStartIEDlg::OnSet() 
{

	GetDlgItem(IDC_EDADDRESS)->GetWindowText(strcomd);
	SetTimer(1,1000,NULL);
}

void CStartIEDlg::OnTray(WPARAM wParam,LPARAM lParam)
{
	UINT msg=UINT(lParam);
	if(msg==WM_LBUTTONDBLCLK)
	{
	this->ShowWindow(SW_SHOWNOACTIVATE);
	}
}

void CStartIEDlg::OnExit() 
{
	this->OnCancel();	
}

BOOL CStartIEDlg::DestroyWindow() 
{
	NOTIFYICONDATA data;
	data.cbSize=sizeof(NOTIFYICONDATA);
	data.hWnd=m_hWnd;
	data.uID=IDR_MAINFRAME;
	Shell_NotifyIcon(NIM_DELETE,&data);
	KillTimer(1);
	return CDialog::DestroyWindow();
}

void CStartIEDlg::OnTimer(UINT nIDEvent) 
{
	LPRASCONN  lpRasConn = NULL;
	RASCONNSTATUS rasStatus;
	LPHRASCONN g_lphRasConn = NULL;
	DWORD cbBuf=0,cConn=0;
	cbBuf=sizeof(RASCONN);
	lpRasConn=(LPRASCONN)malloc((UINT)cbBuf);
	lpRasConn->dwSize=sizeof(RASCONN);
	::RasEnumConnections(lpRasConn,&cbBuf,&cConn);
	if(cConn>0)
	{
	::ShellExecute(this->GetSafeHwnd(),"open",strcomd,NULL,NULL,SW_SHOW);
	KillTimer(1);
	}
	CDialog::OnTimer(nIDEvent);
}
