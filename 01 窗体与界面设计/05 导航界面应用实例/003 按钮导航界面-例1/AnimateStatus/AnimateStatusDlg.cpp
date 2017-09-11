// AnimateStatusDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AnimateStatus.h"
#include "AnimateStatusDlg.h"

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
// CAnimateStatusDlg dialog

CAnimateStatusDlg::CAnimateStatusDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAnimateStatusDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAnimateStatusDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAnimateStatusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAnimateStatusDlg)
	DDX_Control(pDX, IDC_ANIMATE1, m_Animate);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAnimateStatusDlg, CDialog)
	//{{AFX_MSG_MAP(CAnimateStatusDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnimateStatusDlg message handlers

BOOL CAnimateStatusDlg::OnInitDialog()
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
	
	//创建状态栏
	m_StatusBar.Create(this);
	
	//添加状态栏面板
	UINT  Indicates[4]; 
	for (int i = 0; i<4;i++)
	{
		Indicates[i] = 50+i;
	}

	m_StatusBar.SetIndicators(Indicates,4);
	m_StatusBar.GetStatusBarCtrl().SetMinHeight(30);
	CRect rect;
	GetClientRect(rect);
	
	UINT PaneWidth = rect.Width()/5;

	//设置面板宽度
	for(int n = 0;n<4;n++)
	{
		m_StatusBar.SetPaneInfo(n,50+n*10,SBPS_NORMAL,PaneWidth);
	}
	//设置状态栏面板文本

	m_StatusBar.SetPaneText(0,"用户名称");
	m_StatusBar.SetPaneText(1,"明日科技");
	m_StatusBar.SetPaneText(2,"动画");

	m_Animate.SetParent(&m_StatusBar);

	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);	

	CRect Rect;
	m_StatusBar.GetStatusBarCtrl().GetRect(3,&Rect);
	
	CRect ProgRect(Rect.left,2,Rect.right,Rect.Height()+2);
	m_Animate.MoveWindow(ProgRect);

	m_Animate.Open("dmt.avi");

	m_Animate.Play(0,-1,-1);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAnimateStatusDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAnimateStatusDlg::OnPaint() 
{
	CRect rect;
	GetClientRect(&rect);
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);

		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
	CDC* pDC = GetDC();
	CDC mDC;
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);
	BITMAPINFO bInfo;
	bitmap.GetObject(sizeof(bInfo),&bInfo);

	mDC.CreateCompatibleDC(pDC);
	mDC.SelectObject(&bitmap);
	pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&mDC,0,0,bInfo.bmiHeader.biWidth,bInfo.bmiHeader.biHeight,SRCCOPY);


}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAnimateStatusDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAnimateStatusDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	
}
