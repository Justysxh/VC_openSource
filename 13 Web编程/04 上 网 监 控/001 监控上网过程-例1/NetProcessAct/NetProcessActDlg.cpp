// NetProcessActDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetProcessAct.h"
#include "NetProcessActDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define WM_ONTRAY WM_USER+1000
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
// CNetProcessActDlg dialog

CNetProcessActDlg::CNetProcessActDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNetProcessActDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNetProcessActDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNetProcessActDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNetProcessActDlg)
	DDX_Control(pDX, IDC_ACTLIST, m_actlist);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNetProcessActDlg, CDialog)
	//{{AFX_MSG_MAP(CNetProcessActDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BTEXIT, OnExit)
	ON_MESSAGE(WM_ONTRAY,OnTray)
	ON_BN_CLICKED(IDC_BTENTER, OnEnter)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetProcessActDlg message handlers

BOOL CNetProcessActDlg::OnInitDialog()
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
	
	m_actlist.SetExtendedStyle(LVS_EX_GRIDLINES);
	m_actlist.InsertColumn(0, "IEµØÖ·", LVCFMT_LEFT, 200);

	CoInitialize(NULL);
	
	
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNetProcessActDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CNetProcessActDlg::OnPaint() 
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
HCURSOR CNetProcessActDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CNetProcessActDlg::DestroyWindow() 
{
	NOTIFYICONDATA data;
	data.cbSize=sizeof(NOTIFYICONDATA);
	data.hWnd=m_hWnd;
	data.uID=IDR_MAINFRAME;
	Shell_NotifyIcon(NIM_DELETE,&data);
	KillTimer(1);
		CoUninitialize();
	return CDialog::DestroyWindow();
}

void CNetProcessActDlg::OnTimer(UINT nIDEvent) 
{	
	KillTimer(1);
	BOOL bsame=FALSE;
	int n = m_spSHWinds->GetCount();
	for (int i = 0; i < n; i++){
		_variant_t v = (long)i;
		IDispatchPtr spDisp = m_spSHWinds->Item(v);
		SHDocVw::IWebBrowser2Ptr spBrowser(spDisp);  
		MSHTML::IHTMLDocument2Ptr pDoc2=spBrowser->GetDocument();
		if(pDoc2!=NULL)
		{
			BSTR bsurl=pDoc2->Geturl();
			CString strurl=(CString)bsurl;
			int count=m_actlist.GetItemCount();
			for(int p=0;p<=count;p++)
			{
				CString itemstr=m_actlist.GetItemText(p,0);
				if(itemstr==strurl)
				{
					bsame=TRUE;
					goto end;
				}
			}
			if(bsame==FALSE)
				m_actlist.InsertItem(0,strurl,0);
end:
		bsame=FALSE;
		}

	}
	SetTimer(1,2000,NULL);
	CDialog::OnTimer(nIDEvent);
}
void CNetProcessActDlg::OnTray(WPARAM wParam,LPARAM lParam)
{
	UINT msg=UINT(lParam);
	if(msg==WM_LBUTTONDBLCLK)
	{
		this->ShowWindow(SW_SHOWNOACTIVATE);
	}
}

void CNetProcessActDlg::OnExit() 
{
	this->OnCancel();	
}

void CNetProcessActDlg::OnEnter() 
{
	//ShowWindow(SW_HIDE);	
	m_spSHWinds == NULL;
	m_spSHWinds.CreateInstance(__uuidof(SHDocVw::ShellWindows));
	SetTimer(1,2000,NULL);
}
