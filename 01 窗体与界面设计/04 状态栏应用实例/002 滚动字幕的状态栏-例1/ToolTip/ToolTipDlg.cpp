// ToolTipDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ToolTip.h"
#include "ToolTipDlg.h"

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
// CToolTipDlg dialog

CToolTipDlg::CToolTipDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CToolTipDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CToolTipDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CToolTipDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CToolTipDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CToolTipDlg, CDialog)
	//{{AFX_MSG_MAP(CToolTipDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONUPDATE, OnButtonupdate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToolTipDlg message handlers

BOOL CToolTipDlg::OnInitDialog()
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
	//创建图像列表
	m_ImageList.Create(16,16,ILC_COLOR24|ILC_MASK,1,1);
	//向图像列表中添加图标
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON3));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON4));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON5));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON6));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON7));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON8));
	UINT array[11];
	for(int i=0;i<11;i++)
	{
		if(i==3 || i==7 || i==9)
			array[i] = ID_SEPARATOR; //第4、8、10个按钮为分隔条
		else
			array[i] = i+1001;
	}
	CString str[]={"新建","打开","保存","","剪切","复制","粘贴","","打印","","帮助"};
	//创建工具栏
	m_ToolBar.CreateEx(this,TBSTYLE_FLAT,WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_SIZE_DYNAMIC | CBRS_BORDER_TOP);

	m_ToolBar.SetButtons(array,11);
	for(i=0;i<11;i++)
	{
		m_ToolBar.SetButtonText(i,str[i]);							//设置工具栏按钮文本
	}
	//关联图像列表
	m_ToolBar.GetToolBarCtrl().SetImageList(&m_ImageList);
	m_ToolBar.SetSizes(CSize(24,24),CSize(16,16)); //设置按钮和图标的大小
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);
	m_bText = FALSE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CToolTipDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CToolTipDlg::OnPaint() 
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
HCURSOR CToolTipDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CToolTipDlg::OnButtonupdate() 
{
	// TODO: Add your control notification handler code here
	m_bText = !m_bText;
	UpdateToolBar(m_bText);
}

void CToolTipDlg::UpdateToolBar(BOOL bUpdate)
{
	if(bUpdate)
	{
		m_ToolBar.SetSizes(CSize(32,32),CSize(16,16)); //设置按钮和图标的大小
		m_ToolBar.SetHeight(36);
		RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);
	}
	else
	{
		m_ToolBar.SetSizes(CSize(24,24),CSize(16,16)); //设置按钮和图标的大小
		m_ToolBar.SetHeight(28);
		RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);
	}
}
