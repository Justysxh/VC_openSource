// ReportDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Report.h"
#include "ReportDlg.h"

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
// CReportDlg dialog

CReportDlg::CReportDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReportDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReportDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReportDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReportDlg)
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CReportDlg, CDialog)
	//{{AFX_MSG_MAP(CReportDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReportDlg message handlers

BOOL CReportDlg::OnInitDialog()
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
	//设置列表视图的扩展风格
	m_Grid.SetExtendedStyle(LVS_EX_FLATSB			//扁平风格显示滚动条
		|LVS_EX_FULLROWSELECT					//允许整行选中
		|LVS_EX_HEADERDRAGDROP				//允许整列拖动
		|LVS_EX_ONECLICKACTIVATE				//单击选中项
		|LVS_EX_GRIDLINES);						//画出网格线
	//设置表头
	m_Grid.InsertColumn(0,"书名",LVCFMT_LEFT,200,0); 	//设置书名列
	m_Grid.InsertColumn(1,"作者",LVCFMT_LEFT,130,1); 	//设置作者列
	m_Grid.InsertColumn(2,"出版社",LVCFMT_LEFT,130,2); 	//设置出版社列

	m_Grid.InsertItem(0,"Visual C++开发技术大全（第2版）");						//插入第0行
	m_Grid.SetItemText(0,1,"明日科技");				//向第1列插入数据
	m_Grid.SetItemText(0,2,"人民邮电出版社");				//向第2列插入数据
	m_Grid.InsertItem(1,"Visual C++从入门到精通（第2版）");						//插入第1行
	m_Grid.SetItemText(1,1,"明日科技");				//向第1列插入数据
	m_Grid.SetItemText(1,2,"清华大学出版社");				//向第2列插入数据
	m_Grid.InsertItem(2,"Visual C++开发实战宝典");						//插入第2行
	m_Grid.SetItemText(2,1,"明日科技");				//向第1列插入数据
	m_Grid.SetItemText(2,2,"清华大学出版社");				//向第2列插入数据

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CReportDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CReportDlg::OnPaint() 
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
HCURSOR CReportDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
