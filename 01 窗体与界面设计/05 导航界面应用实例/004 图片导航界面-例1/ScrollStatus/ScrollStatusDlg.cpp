// ScrollStatusDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ScrollStatus.h"
#include "ScrollStatusDlg.h"

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
// CScrollStatusDlg dialog

CScrollStatusDlg::CScrollStatusDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScrollStatusDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScrollStatusDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CScrollStatusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScrollStatusDlg)
	DDX_Control(pDX, IDC_PARENT, m_Parent);
	DDX_Control(pDX, IDC_WEB, m_Web);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CScrollStatusDlg, CDialog)
	//{{AFX_MSG_MAP(CScrollStatusDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScrollStatusDlg message handlers

BOOL CScrollStatusDlg::OnInitDialog()
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
	
	// TODO: Add extra initialization here
	//创建状态栏
	m_StatusBar.Create(this);
	
	//添加状态栏面板
	UINT  Indicates[4]; 
	for (int i = 0; i<4;i++)
	{
		Indicates[i] = 50+i;
	}

	m_StatusBar.SetIndicators(Indicates,4);
	CRect rect;
	GetClientRect(rect);
	
	UINT PaneWidth = rect.Width()/6;

	//设置面板宽度
	for(int n = 0;n<3;n++)
	{
		m_StatusBar.SetPaneInfo(n,50+n*10,SBPS_NORMAL,PaneWidth);
	}
	//设置状态栏面板文本

	m_StatusBar.SetPaneInfo(3,111,SBPS_NORMAL,800);
	m_StatusBar.SetPaneText(0,"用户名称");
	m_StatusBar.SetPaneText(1,"明日科技");
	m_StatusBar.SetPaneText(2,"网址");

	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);	


	m_Parent.SetParent(&m_StatusBar);
	
	//获取控件的显示区域
	m_StatusBar.GetStatusBarCtrl().GetRect(3,Rect);
	Rect.DeflateRect(1,1,1,1);

	m_Parent.MoveWindow(Rect);
	m_Parent.GetClientRect(Rect);
	

	m_Web.GetClientRect(rect1);
	m_Web.SetParent(&m_Parent);



	m_Parent.GetClientRect(CurRect);
	CurRect.DeflateRect(0,1,Rect.Width()-rect1.Width(),1);
	m_Web.MoveWindow(CurRect);
	
	SetTimer(1,200,NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CScrollStatusDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CScrollStatusDlg::OnPaint() 
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

	CDC m_dc;
	CDC* pDC = GetDC();
	m_dc.CreateCompatibleDC(pDC);
	
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);
	m_dc.SelectObject(&bitmap);
	
	BITMAPINFO pInfo;
	bitmap.GetObject(sizeof(pInfo),&pInfo);	
	pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&m_dc,0,0,pInfo.bmiHeader.biWidth,pInfo.bmiHeader.biHeight,SRCCOPY);
	
	bitmap.DeleteObject();
	m_dc.DeleteDC();


}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CScrollStatusDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CScrollStatusDlg::OnTimer(UINT nIDEvent) 
{
	if (CurRect.left>=Rect.right)
	{
		CurRect.left = Rect.left-rect1.Width();
		CurRect.right =Rect.left;
	}
	else
	{
		CurRect.left+=4;
		CurRect.right+=4;
	}	
	//调整控件位置
	m_Web.MoveWindow(CurRect);
	
}
