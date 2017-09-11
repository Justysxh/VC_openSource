// CriticalSectionSynchDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CriticalSectionSynch.h"
#include "CriticalSectionSynchDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "afxmt.h"
CRITICAL_SECTION hCritial;
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
// CCriticalSectionSynchDlg dialog

CCriticalSectionSynchDlg::CCriticalSectionSynchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCriticalSectionSynchDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCriticalSectionSynchDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCriticalSectionSynchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCriticalSectionSynchDlg)
	DDX_Control(pDX, IDC_CRITICL, m_criticl);
	DDX_Control(pDX, IDC_RESULT, m_result);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCriticalSectionSynchDlg, CDialog)
	//{{AFX_MSG_MAP(CCriticalSectionSynchDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTSTARTONE, OnStartOne)
	ON_BN_CLICKED(IDC_BTSTARTTWO, OnStartTwo)
	ON_BN_CLICKED(IDC_CRITICL, OnCriticl)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCriticalSectionSynchDlg message handlers

BOOL CCriticalSectionSynchDlg::OnInitDialog()
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
	
	bcritical=FALSE;
	InitializeCriticalSection(&hCritial);
	return TRUE;
}

void CCriticalSectionSynchDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCriticalSectionSynchDlg::OnPaint() 
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
HCURSOR CCriticalSectionSynchDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

static UINT thread1(LPVOID pParam)
{
	CCriticalSectionSynchDlg *pdlg=(CCriticalSectionSynchDlg*)pParam;
	CString str;
	char buf[MAX_PATH];
	if(pdlg->bcritical==TRUE)
	EnterCriticalSection(&hCritial);

	for(int i=0;i<20;i++)
	{
		::SendMessage(pdlg->m_result.GetSafeHwnd(), 
			WM_GETTEXT, sizeof(buf)/sizeof(char), (LPARAM)buf);
		strcat(buf,"A");
		UINT len=strlen(buf);
		buf[len]='\0';
		::SendMessage(pdlg->m_result.GetSafeHwnd(),WM_SETTEXT,0,(LPARAM)buf);
		Sleep(200);
	}
	LeaveCriticalSection(&hCritial);
	return 0;

}
static UINT thread2(LPVOID pParam)
{
	CCriticalSectionSynchDlg *pdlg=(CCriticalSectionSynchDlg*)pParam;
	CString str;
	char buf[MAX_PATH];
	if(pdlg->bcritical==TRUE)
	EnterCriticalSection(&hCritial);

	for(int i=0;i<20;i++)
	{
		::SendMessage(pdlg->m_result.GetSafeHwnd(), 
			WM_GETTEXT, sizeof(buf)/sizeof(char), (LPARAM)buf);
		strcat(buf,"B");
		UINT len=strlen(buf);
		buf[len]='\0';
		::SendMessage(pdlg->m_result.GetSafeHwnd(),WM_SETTEXT,0,(LPARAM)buf);
		Sleep(200);
	}
	LeaveCriticalSection(&hCritial);
	return 0;
}

void CCriticalSectionSynchDlg::OnStartOne() 
{
	AfxBeginThread(thread1,this);
}

void CCriticalSectionSynchDlg::OnStartTwo() 
{
	AfxBeginThread(thread2,this);
}

void CCriticalSectionSynchDlg::OnCriticl() 
{
	bcritical=!bcritical;
	InitializeCriticalSection(&hCritial);
}
