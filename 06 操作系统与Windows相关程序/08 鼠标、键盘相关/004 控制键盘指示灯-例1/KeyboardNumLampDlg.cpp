// KeyboardNumLampDlg.cpp : implementation file
//

#include "stdafx.h"
#include "KeyboardNumLamp.h"
#include "KeyboardNumLampDlg.h"

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
// CKeyboardNumLampDlg dialog

CKeyboardNumLampDlg::CKeyboardNumLampDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKeyboardNumLampDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CKeyboardNumLampDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKeyboardNumLampDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKeyboardNumLampDlg)
	DDX_Control(pDX, IDC_CKSCROLLLOCK, m_scroll);
	DDX_Control(pDX, IDC_CKNUMLOCK, m_num);
	DDX_Control(pDX, IDC_CKCAPSLOCK, m_cap);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CKeyboardNumLampDlg, CDialog)
	//{{AFX_MSG_MAP(CKeyboardNumLampDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CKNUMLOCK, OnNumLock)
	ON_BN_CLICKED(IDC_CKCAPSLOCK, OnCapLock)
	ON_BN_CLICKED(IDC_CKSCROLLLOCK, OnScrollLock)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKeyboardNumLampDlg message handlers

BOOL CKeyboardNumLampDlg::OnInitDialog()
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
	
	BYTE keyState[256];
    GetKeyboardState((LPBYTE)&keyState);
	if(keyState[VK_NUMLOCK]&1)
	{
		m_num.SetCheck(true);
	}
	if(keyState[VK_SCROLL]&1)
	{
		m_scroll.SetCheck(true);
	}
	if(keyState[VK_CAPITAL]&1)
	{
		m_cap.SetCheck(true);
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CKeyboardNumLampDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CKeyboardNumLampDlg::OnPaint() 
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
HCURSOR CKeyboardNumLampDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CKeyboardNumLampDlg::OnNumLock() 
{
	keybd_event(VK_NUMLOCK,0x45,KEYEVENTF_EXTENDEDKEY|0,0);
	keybd_event(VK_NUMLOCK,0x45,KEYEVENTF_EXTENDEDKEY|KEYEVENTF_KEYUP,0);
}

void CKeyboardNumLampDlg::OnCapLock() 
{
	keybd_event(VK_CAPITAL,0x45,KEYEVENTF_EXTENDEDKEY|0,0);
	keybd_event(VK_CAPITAL,0x45,KEYEVENTF_EXTENDEDKEY|KEYEVENTF_KEYUP,0);	
}

void CKeyboardNumLampDlg::OnScrollLock() 
{
	keybd_event(VK_SCROLL,0x45,KEYEVENTF_EXTENDEDKEY|0,0);
	keybd_event(VK_SCROLL,0x45,KEYEVENTF_EXTENDEDKEY|KEYEVENTF_KEYUP,0);
}

BOOL CKeyboardNumLampDlg::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message==WM_KEYUP)
	{
		BYTE keyState[256];
		GetKeyboardState((LPBYTE)&keyState);
	if(keyState[VK_NUMLOCK]&1)
	
		m_num.SetCheck(true);
	
	else
		m_num.SetCheck(false);
	if(keyState[VK_SCROLL]&1)
	
		m_scroll.SetCheck(true);
	else
		m_scroll.SetCheck(false);
	if(keyState[VK_CAPITAL]&1)
	
		m_cap.SetCheck(true);
	else
		m_cap.SetCheck(false);
	}
	return CDialog::PreTranslateMessage(pMsg);
}
