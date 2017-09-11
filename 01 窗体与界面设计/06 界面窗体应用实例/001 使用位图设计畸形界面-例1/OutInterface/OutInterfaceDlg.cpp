// OutInterfaceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OutInterface.h"


#include "OutInterfaceDlg.h"

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
// COutInterfaceDlg dialog

COutInterfaceDlg::COutInterfaceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COutInterfaceDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COutInterfaceDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COutInterfaceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COutInterfaceDlg)
	DDX_Control(pDX, IDC_LIST1, m_List);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COutInterfaceDlg, CDialog)
	//{{AFX_MSG_MAP(COutInterfaceDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COutInterfaceDlg message handlers

BOOL COutInterfaceDlg::OnInitDialog()
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
	//创建图像列表,向图像列表中添加图标
	m_Imagelist.Create(32,32,ILC_COLOR24|ILC_MASK,0,1);

	for (int i=0;i<6;i++)
	{
		m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON1+i));
	}

	//创建工具栏
	if (!m_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS |CBRS_SIZE_DYNAMIC|CBRS_BORDER_TOP ) ||
		!m_ToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);

	//向列表视图控件中添加按钮

	m_List.SetImageLists(&m_Imagelist);
	m_List.AddButton("基础资料管理",500);
	m_List.AddButton("销售组织",501);
	m_List.AddButton("市场管理",502);
	m_List.AddButton("销售业务管理",503);
	m_List.AddButton("销售分析",504);

	//设置回调函数
	m_List.pItemDlbFun = OnItemDouble;

	//向指定按钮添加关联的视图项
	CString str;
	str = "市场反馈";
	m_List.AddButtonItems(2,str);
	str = "市场跟踪";
	m_List.AddButtonItems(2,str);
	str = "市场走势";
	m_List.AddButtonItems(2,str);
	str = "市场行情";
	m_List.AddButtonItems(2,str);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COutInterfaceDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COutInterfaceDlg::OnPaint() 
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
HCURSOR COutInterfaceDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void COutInterfaceDlg::OnOK() 
{
//

}

void COutInterfaceDlg::OnItemDouble(const CListCtrl *pListCtrl, int nIndex)
{
	if (pListCtrl)
	{
		if (nIndex != -1)
		{
			CString str = pListCtrl->GetItemText(nIndex,0);
			AfxMessageBox("欢迎进入"+str+"管理",0,0);
		}	
	}
}
