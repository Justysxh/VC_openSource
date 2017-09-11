// InternetSetTimeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "InternetSetTime.h"
#include "InternetSetTimeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define WM_ONTRAY WM_USER+1133
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
// CInternetSetTimeDlg dialog

CInternetSetTimeDlg::CInternetSetTimeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInternetSetTimeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInternetSetTimeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CInternetSetTimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInternetSetTimeDlg)
	DDX_Control(pDX, IDC_CMBMINU, m_minu);
	DDX_Control(pDX, IDC_CMBHOUR, m_hour);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CInternetSetTimeDlg, CDialog)
	//{{AFX_MSG_MAP(CInternetSetTimeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTENTER, OnEnter)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BTEXIT, OnExit)
	ON_MESSAGE(WM_ONTRAY,OnTray)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInternetSetTimeDlg message handlers

BOOL CInternetSetTimeDlg::OnInitDialog()
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

	for(int i=0;i<24;i++)
	{
		CString temp;
		temp.Format("%02d",i);
		m_hour.AddString(temp);
	}
	for(int p=0;p<60;p++)
	{
		CString temp;
		temp.Format("%02d",p);
		m_minu.AddString(temp);
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CInternetSetTimeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CInternetSetTimeDlg::OnPaint() 
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

HCURSOR CInternetSetTimeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CInternetSetTimeDlg::OnEnter() 
{
	
	GetDlgItem(IDC_EDADDRESS)->GetWindowText(straddress);
	CString hour,minu;
	m_hour.GetWindowText(hour);
	m_minu.GetWindowText(minu);
	strtime.Format("%s:%s",hour,minu);
	CString temp;temp.Format("你设置的时间是%s",strtime);
	AfxMessageBox(temp);
	SetTimer(1,1000,NULL);

}
void CInternetSetTimeDlg::OnTray(WPARAM wParam,LPARAM lParam)
{
	UINT msg=UINT(lParam);
	if(msg==WM_LBUTTONDBLCLK)
	{
	this->ShowWindow(SW_SHOWNOACTIVATE);
	}
}

void CInternetSetTimeDlg::OnClose() 
{
	this->CloseWindow();
	this->ShowWindow(SW_HIDE);
}

BOOL CInternetSetTimeDlg::DestroyWindow() 
{
	NOTIFYICONDATA data;
	data.cbSize=sizeof(NOTIFYICONDATA);
	data.hWnd=m_hWnd;
	data.uID=IDR_MAINFRAME;
	Shell_NotifyIcon(NIM_DELETE,&data);
	KillTimer(1);
	return CDialog::DestroyWindow();
}

void CInternetSetTimeDlg::OnExit() 
{
	this->OnCancel();	
}

void CInternetSetTimeDlg::OnTimer(UINT nIDEvent) 
{
	CTime tt;
	tt=CTime::GetCurrentTime();
	CString tmp=tt.Format("%H:%M");
	if(!tmp.CompareNoCase(strtime))
	{
	::ShellExecute(this->GetSafeHwnd(),"open",straddress,NULL,NULL,SW_SHOW);
	KillTimer(1);
	}
	CDialog::OnTimer(nIDEvent);
}
