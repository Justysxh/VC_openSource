// realplayerDlgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "realplayerDlg.h"
#include "realplayerDlgDlg.h"

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
// CRealplayerDlgDlg dialog

CRealplayerDlgDlg::CRealplayerDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRealplayerDlgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRealplayerDlgDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRealplayerDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRealplayerDlgDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRealplayerDlgDlg, CDialog)
	//{{AFX_MSG_MAP(CRealplayerDlgDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTOPEN, OnOpen)
	ON_BN_CLICKED(IDC_BTPAUSE, OnPause)
	ON_BN_CLICKED(IDC_BTSTOP, OnStop)
	ON_BN_CLICKED(IDC_BTSOUNDADD, OnSoundAdd)
	ON_BN_CLICKED(IDC_BTSOUNDSUB, OnSoundSub)
	ON_BN_CLICKED(IDC_BTPROCADD, OnProcAdd)
	ON_BN_CLICKED(IDC_BTPROCSUB, OnProcSub)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRealplayerDlgDlg message handlers

BOOL CRealplayerDlgDlg::OnInitDialog()
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
	CRect rc;
	GetDlgItem(IDC_REALPLAYER)->GetWindowRect(rc);
	ScreenToClient(&rc);
	m_realplayer.Create("",WS_POPUP,rc,this,10000);
	m_realplayer.ShowWindow(SW_SHOW);
	
	
	return TRUE; 
}

void CRealplayerDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRealplayerDlgDlg::OnPaint() 
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
HCURSOR CRealplayerDlgDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRealplayerDlgDlg::OnOpen() 
{
	CString strname;
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,"realplayÎÄ¼þ|*.rm||");
	if(dlg.DoModal()==IDOK){
		strname=dlg.GetPathName();
	}	
	if(strname!="")
	{
		m_realplayer.SetSource(strname);
		m_realplayer.DoPlay();
	}	
}

void CRealplayerDlgDlg::OnPause() 
{
	if(m_realplayer.GetPlayState()==0)return;	
	CString text;
	GetDlgItem(IDC_BUTTON2)->GetWindowText(text);
	if(text=="ÔÝÍ£")
	{
		m_realplayer.DoPause();
		GetDlgItem(IDC_BUTTON2)->SetWindowText("²¥·Å");

	}	
	else
	{
		m_realplayer.DoPlay();
		SetTimer(1,20,NULL);
		GetDlgItem(IDC_BUTTON2)->SetWindowText("ÔÝÍ£");
	}
}

void CRealplayerDlgDlg::OnStop() 
{
	m_realplayer.DoStop();	
}

void CRealplayerDlgDlg::OnSoundAdd() 
{
	short vl=0;
	if(m_realplayer.GetPlayState()==3)
	{
		vl=m_realplayer.GetVolume();
		if(vl<=90)
		{
			m_realplayer.DoPause();
			m_realplayer.SetVolume(vl+10);
			m_realplayer.DoPlay();
		}
	}
	else
	{
		if(vl<=90)
		m_realplayer.SetVolume(vl+10);
	}
}

void CRealplayerDlgDlg::OnSoundSub() 
{
	short vl=0;
	if(m_realplayer.GetPlayState()==3)
	{
		vl=m_realplayer.GetVolume();
		if(vl>=10)
		{
			m_realplayer.DoPause();
			m_realplayer.SetVolume(vl-10);
			m_realplayer.DoPlay();
		}
	}
	else
	{
		if(vl>=10)
		m_realplayer.SetVolume(vl-10);
	}
}

void CRealplayerDlgDlg::OnProcAdd() 
{
	if(m_realplayer.GetPlayState()==3)
	{
		long pos=m_realplayer.GetPosition();
		m_realplayer.DoPause();
		m_realplayer.SetPosition(pos+2000);
		m_realplayer.DoPlay();
	}
}

void CRealplayerDlgDlg::OnProcSub() 
{
	if(m_realplayer.GetPlayState()==3)
	{
		long pos=m_realplayer.GetPosition();
		if(pos<2000)return;
		m_realplayer.DoPause();
		m_realplayer.SetPosition(pos-2000);
		m_realplayer.DoPlay();
	}
}

BOOL CRealplayerDlgDlg::DestroyWindow() 
{
	KillTimer(0);
	return CDialog::DestroyWindow();
}

void CRealplayerDlgDlg::OnTimer(UINT nIDEvent) 
{
	m_realplayer.DoPlay();
	CDialog::OnTimer(nIDEvent);
}
