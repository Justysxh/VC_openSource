// MutexSynchDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MutexSynch.h"
#include "MutexSynchDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include <afxmt.h>
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
// CMutexSynchDlg dialog

CMutexSynchDlg::CMutexSynchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMutexSynchDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMutexSynchDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMutexSynchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMutexSynchDlg)
	DDX_Control(pDX, IDC_MUTEX, m_mutex);
	DDX_Control(pDX, IDC_RESULT, m_result);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMutexSynchDlg, CDialog)
	//{{AFX_MSG_MAP(CMutexSynchDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTSTARTONE, OnStartOne)
	ON_BN_CLICKED(IDC_BTSTARTTWO, OnStartTwo)
	ON_BN_CLICKED(IDC_MUTEX, OnMutex)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMutexSynchDlg message handlers

BOOL CMutexSynchDlg::OnInitDialog()
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
	
	bmutex=FALSE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMutexSynchDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMutexSynchDlg::OnPaint() 
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
HCURSOR CMutexSynchDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
CMutex cMutex(FALSE,NULL);
static UINT thread1(LPVOID pParam)
{
	CMutexSynchDlg *pdlg=(CMutexSynchDlg*)pParam;
	//char buf[MAX_PATH];
	CString str;
	if(pdlg->bmutex==TRUE)
	cMutex.Lock();
	for(int i=0;i<20;i++)
	{
		pdlg->m_result.GetWindowText(str);
		str+="A";
		pdlg->m_result.SetWindowText(str);
		Sleep(200);
	}
	cMutex.Unlock();
	return 0;
}
static UINT thread2(LPVOID pParam)
{
	CMutexSynchDlg *pdlg=(CMutexSynchDlg*)pParam;
	CString str;
	if(pdlg->bmutex==TRUE)
	cMutex.Lock();
	for(int i=0;i<20;i++)
	{
		pdlg->m_result.GetWindowText(str);
		str+="B";
		pdlg->m_result.SetWindowText(str);
		Sleep(200);
	}
	cMutex.Unlock();
	return 0;
}
void CMutexSynchDlg::OnStartOne()
{
	AfxBeginThread(thread1,this);
}

void CMutexSynchDlg::OnStartTwo()
{
	AfxBeginThread(thread2,this);
}

void CMutexSynchDlg::OnMutex() 
{
	bmutex=!bmutex;
}
