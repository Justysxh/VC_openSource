// CDPlayerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CDPlayer.h"
#include "CDPlayerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define WM_ONTRAY WM_USER+1222
#include <MMSystem.h>
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
// CCDPlayerDlg dialog

CCDPlayerDlg::CCDPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCDPlayerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCDPlayerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCDPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCDPlayerDlg)
	DDX_Control(pDX, IDC_CDCATA, m_cdcata);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCDPlayerDlg, CDialog)
	//{{AFX_MSG_MAP(CCDPlayerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_ONTRAY,OnTray)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_NOTIFY(NM_DBLCLK, IDC_CDCATA, OnDblclkCdcata)
	ON_BN_CLICKED(IDC_BTOPEN, OnOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCDPlayerDlg message handlers

BOOL CCDPlayerDlg::OnInitDialog()
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
	m_cdcata.SetExtendedStyle(LVS_EX_GRIDLINES);
	m_cdcata.InsertColumn(0,"ÇúÄ¿",LVCFMT_LEFT,150);
	
	return TRUE;
}

void CCDPlayerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	//if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	//{
	//	CAboutDlg dlgAbout;
	//	dlgAbout.DoModal();
//	}
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

void CCDPlayerDlg::OnPaint() 
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
HCURSOR CCDPlayerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CCDPlayerDlg::OnTray(WPARAM wParam,LPARAM lParam)
{
	UINT msg=UINT(lParam);
	if(msg==WM_LBUTTONDBLCLK)
	{
	this->ShowWindow(SW_SHOWNOACTIVATE);
	}
}

void CCDPlayerDlg::OnPlay() 
{
	int i;
	i=m_cdcata.GetSelectionMark();
	if(i==-1)return;
	MCI_SET_PARMS SetParms;
	SetParms.dwTimeFormat = MCI_FORMAT_TMSF;
	::mciSendCommand (m_wDeviceID, 
                      MCI_SET, 
                      MCI_WAIT | MCI_SET_TIME_FORMAT, 
                      (DWORD)(LPVOID) &SetParms);
	::mciSendCommand (m_wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, NULL);
	MCI_PLAY_PARMS PlayParms;
	PlayParms.dwFrom=MCI_MAKE_TMSF(i,0,0,0);
	::mciSendCommand (m_wDeviceID, MCI_PLAY, MCI_FROM, 
                          (DWORD)(LPVOID) &PlayParms);
}

void CCDPlayerDlg::OnStop() 
{
	::mciSendCommand (m_wDeviceID, MCI_STOP, NULL, NULL);
}

BOOL CCDPlayerDlg::DestroyWindow() 
{
	::mciSendCommand (m_wDeviceID, MCI_STOP, NULL, NULL);
	NOTIFYICONDATA data;
	data.cbSize=sizeof(NOTIFYICONDATA);
	data.hWnd=m_hWnd;
	data.uID=IDR_MAINFRAME;
	Shell_NotifyIcon(NIM_DELETE,&data);
	::mciSendCommand (m_wDeviceID, MCI_CLOSE, MCI_WAIT, NULL);
	return CDialog::DestroyWindow();
}

void CCDPlayerDlg::OnExit() 
{
	this->OnCancel();	
}

void CCDPlayerDlg::OnDblclkCdcata(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int i;
	i=m_cdcata.GetSelectionMark();
	if(i==-1)return;
	MCI_SET_PARMS SetParms;
	SetParms.dwTimeFormat = MCI_FORMAT_TMSF;
	::mciSendCommand (m_wDeviceID, 
                      MCI_SET, 
                      MCI_WAIT | MCI_SET_TIME_FORMAT, 
                      (DWORD)(LPVOID) &SetParms);
::mciSendCommand (m_wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, NULL);
	MCI_PLAY_PARMS PlayParms;
	PlayParms.dwFrom=MCI_MAKE_TMSF(i,0,0,0);
	::mciSendCommand (m_wDeviceID, MCI_PLAY, MCI_FROM, 
                          (DWORD)(LPVOID) &PlayParms);
	*pResult = 0;
}

void CCDPlayerDlg::OnOpen() 
{
	MCI_OPEN_PARMS OpenParms;
	OpenParms.lpstrDeviceType = (LPCSTR) MCI_DEVTYPE_CD_AUDIO;
	int ireturn=0; 
	ireturn=::mciSendCommand (NULL, 
                      MCI_OPEN, 
                      MCI_WAIT | MCI_OPEN_SHAREABLE|
                      MCI_OPEN_TYPE | MCI_OPEN_TYPE_ID , 
                      (DWORD)(LPVOID) &OpenParms);
	if(ireturn==0)
	{
		m_wDeviceID=OpenParms.wDeviceID;
		MCI_STATUS_PARMS  StatusParms;
		StatusParms.dwItem=MCI_STATUS_MEDIA_PRESENT;
		ireturn=::mciSendCommand (m_wDeviceID, 
                          MCI_STATUS, MCI_STATUS_ITEM, 
                          (DWORD)(LPVOID) &StatusParms);
		if(ireturn==0)
		{
			StatusParms.dwItem = MCI_STATUS_NUMBER_OF_TRACKS;
			mciSendCommand (m_wDeviceID, 
                          MCI_STATUS, MCI_STATUS_ITEM, 
                          (DWORD)(LPVOID) &StatusParms);
			UINT cdnum=StatusParms.dwReturn;
			for(int i=0;i<cdnum;i++)
			{
				CString cdstr;
				cdstr.Format("ÇúÄ¿%d",i+1);
				m_cdcata.InsertItem(i,cdstr);
			}
		}
	}
}
