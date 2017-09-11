// LineColorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LineColor.h"
#include "LineColorDlg.h"

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
// CLineColorDlg dialog

CLineColorDlg::CLineColorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLineColorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLineColorDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLineColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLineColorDlg)
	DDX_Control(pDX, IDC_TREE1, m_Tree);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLineColorDlg, CDialog)
	//{{AFX_MSG_MAP(CLineColorDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLineColorDlg message handlers

BOOL CLineColorDlg::OnInitDialog()
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

	m_ImageList.Create(16,16,ILC_COLOR24|ILC_MASK,1,0);			//创建列表视图窗口
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON1));				//向图像列表中添加图标
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON2)); 				//向图像列表中添加图标
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON3)); 				//向图像列表中添加图标
	m_Tree.SetImageList(&m_ImageList,LVSIL_NORMAL);				//关联图像列表
	HTREEITEM m_Root;										//声明保存根节点的变量
	m_Root = m_Tree.InsertItem("司令",0,0);							//向根节点插入数据
	HTREEITEM m_Child;										//声明保存二级节点的变量
	m_Child = m_Tree.InsertItem("将军甲",1,1,m_Root);					//插入一个二级节点
	m_Tree.InsertItem("士兵甲",2,2,m_Child);							//插入三级节点
	m_Tree.InsertItem("士兵乙",2,2,m_Child);							//插入三级节点
	m_Child = m_Tree.InsertItem("将军乙",1,1,m_Root);					//插入二级节点
	m_Tree.InsertItem("士兵丙",2,2,m_Child);							//插入三级节点
	m_Tree.InsertItem("士兵丁",2,2,m_Child);							//插入三级节点
	m_Tree.Expand(m_Root,TVE_EXPAND);							//展开跟节点

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLineColorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLineColorDlg::OnPaint() 
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
HCURSOR CLineColorDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
