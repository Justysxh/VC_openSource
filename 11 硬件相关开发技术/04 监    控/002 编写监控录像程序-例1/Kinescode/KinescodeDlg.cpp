// KinescodeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Kinescode.h"
#include "KinescodeDlg.h"

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
// CKinescodeDlg dialog

CKinescodeDlg::CKinescodeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKinescodeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CKinescodeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hVideoWnd = 0;
	m_pThread = NULL;
	m_IsKindscode = FALSE;
}

void CKinescodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKinescodeDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CKinescodeDlg, CDialog)
	//{{AFX_MSG_MAP(CKinescodeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_KINESCODE, OnKinescode)
	ON_BN_CLICKED(IDC_STOPKINESCODE, OnStopkinescode)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKinescodeDlg message handlers

BOOL CKinescodeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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
	
	m_pThread = AfxBeginThread(ThreadFun,(LPVOID)this);
	m_Event.ResetEvent();
	::WaitForSingleObject(m_Event,INFINITE);
	if (m_hVideoWnd)
	{
		if (capDriverConnect(m_hVideoWnd,0)==FALSE)
		{
			MessageBox("连接驱动程序出错");
			return;
		}
		
		::SetParent(m_hVideoWnd,*this);
		::SetWindowLong(m_hVideoWnd,GWL_STYLE,WS_CHILD);
		::SetWindowPos(m_hVideoWnd,NULL,10,10,300,300,SWP_NOREDRAW);
		::ShowWindow(m_hVideoWnd,SW_SHOW);
		capPreviewRate(m_hVideoWnd,10);
		capPreview(m_hVideoWnd,TRUE);
	}

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
		
	return TRUE;  // return TRUE  unless you set the focus to a control
}

//线程执行函数
UINT CKinescodeDlg::ThreadFun( LPVOID wParam )
{
	CKinescodeDlg* temp = (CKinescodeDlg*)wParam;
	temp->m_hVideoWnd = capCreateCaptureWindow("Capture",WS_POPUP,10,10,20,20,*temp,0);
	if (temp->m_hVideoWnd )
	{	
		temp->m_Event.SetEvent();
		MSG msg;
		while (GetMessage(&msg,temp->m_hVideoWnd,0,0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return msg.wParam;
	}
	return 0;
}


void CKinescodeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CKinescodeDlg::OnPaint() 
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

HCURSOR CKinescodeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CKinescodeDlg::OnExit() 
{
	OnCancel();

}

void CKinescodeDlg::OnKinescode() 
{
	CString filename;
	CFileDialog FileDlg(FALSE,"avi");
	if (FileDlg.DoModal()==IDOK)
	{
		filename = FileDlg.GetPathName();
		filename.GetBufferSetLength(filename.GetLength()+2);
		filename.Insert(filename.GetLength(),'0');
		filename.Insert(filename.GetLength()+1,'0');
		capFileSetCaptureFile(m_hVideoWnd,filename.GetBuffer(0));
		capCaptureSequence(m_hVideoWnd);
		m_IsKindscode = TRUE;
	}
}

void CKinescodeDlg::OnCancel()
{
	capDriverDisconnect(m_hVideoWnd);
	if (m_pThread != NULL)
		delete m_pThread;
	CDialog::OnCancel();
}

void CKinescodeDlg::OnStopkinescode() 
{
	//capDlgVideoFormat(m_hVideoWnd);
	if (m_IsKindscode==TRUE)
	{
		m_IsKindscode == FALSE;
		capCaptureStop(m_hVideoWnd);
	}	
}
