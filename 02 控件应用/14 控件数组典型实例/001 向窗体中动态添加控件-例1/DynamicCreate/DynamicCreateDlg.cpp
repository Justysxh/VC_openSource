// DynamicCreateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DynamicCreate.h"
#include "DynamicCreateDlg.h"

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
// CDynamicCreateDlg dialog

CDynamicCreateDlg::CDynamicCreateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDynamicCreateDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDynamicCreateDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);


}

CDynamicCreateDlg::~CDynamicCreateDlg()
{

	
}

void CDynamicCreateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDynamicCreateDlg)
	DDX_Control(pDX, IDC_TAB1, m_tab);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDynamicCreateDlg, CDialog)
	//{{AFX_MSG_MAP(CDynamicCreateDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	ON_WM_CLOSE()
	ON_EN_CHANGE(IDE_EDITCHANGE, OnChangeEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDynamicCreateDlg message handlers

BOOL CDynamicCreateDlg::OnInitDialog()
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
	
	//add two tab pages
	m_tab.InsertItem(0,"商品信息");
	m_tab.InsertItem(1,"员工信息");

	m_spage1 = m_statics;
	m_epage1 = m_edits1;

	m_spage2 = m_static2;
	m_epage2 = m_edits2;


	m_list1.AddTail("商品编号");
	m_list1.AddTail("商品名称");
	m_list1.AddTail("简称");
	m_list1.AddTail("厂家");
	m_list1.AddTail("价格");
	m_list1.AddTail("保质期");

	m_list.AddTail("员工姓名");
	m_list.AddTail("性别");
	m_list.AddTail("学历");
	m_list.AddTail("地址");
	m_list.AddTail("联系方式");
	m_list.AddTail("工作经验");

	CreateControl();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDynamicCreateDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDynamicCreateDlg::OnPaint() 
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
HCURSOR CDynamicCreateDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDynamicCreateDlg::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CDynamicCreateDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int m_currenttab = m_tab.GetCurSel();
	switch(m_currenttab)
	{
	case 0:
		 {
			for (int i = 0 ;i<6;i++)
			{
				m_edits1[i].ShowWindow(SW_SHOW);
				m_statics[i].ShowWindow(SW_SHOW);
				m_edits2[i].ShowWindow(SW_HIDE);
				m_static2[i].ShowWindow(SW_HIDE);
			}
			break;
		 }
	case 1:
		 {
		 
			for (int i = 0 ;i<6;i++)
			{
				m_edits1[i].ShowWindow(SW_HIDE);
				m_statics[i].ShowWindow(SW_HIDE);
				m_edits2[i].ShowWindow(SW_SHOW);
				m_static2[i].ShowWindow(SW_SHOW);
			}	
			break;
		 }
	
	}
	*pResult = 0;
}

void CDynamicCreateDlg::CreateControl()
{
	CRect m_rect ;
	m_tab.GetClientRect(m_rect);
	m_tab.MapWindowPoints(this,m_rect);
	POSITION pos = m_list1.GetTailPosition();
	int i;
	for ( i = 0; i<6; i++)
	{
		pos = m_list1.FindIndex(i);
		if (pos != NULL)
		{
			//创建控件窗口
			m_spage1[i].Create(m_list1.GetAt(pos) ,WS_CHILD,CRect(20,(i+1)*30+10,100,(i+1)*30+30),&m_tab);
			//显示控件
			m_spage1[i].ShowWindow(SW_SHOW);
		}
		m_epage1[i].Create(WS_BORDER,CRect(m_rect.left+100,m_rect.top+(i+1)*30+5,m_rect.left+250,m_rect.top+(i+1)*30+30),this,IDE_EDITCHANGE);
		m_epage1[i].ShowWindow(SW_SHOW);
	}
	for ( i = 0; i<6; i++)
	{
		pos = m_list.FindIndex(i);
		if (pos != NULL)
		{
			m_spage2[i].Create(m_list.GetAt(pos) ,WS_CHILD,CRect(20,(i+1)*30+10,100,(i+1)*30+30),&m_tab);
		}
		m_epage2[i].Create(WS_BORDER,CRect(m_rect.left+100,m_rect.top+(i+1)*30+5,m_rect.left+250,m_rect.top+(i+1)*30+30),this,4554);
	}
}

void CDynamicCreateDlg::OnClose() 
{
	m_list1.RemoveAll();
	CDialog::OnClose();
}

void CDynamicCreateDlg::OnChangeEdit1() 
{
	CString s_str,s_text;
	CWnd* m_activewnd = this->GetFocus();
	if (m_activewnd != NULL)
		if (m_activewnd->IsKindOf(RUNTIME_CLASS(CEdit)))
		{
			m_activewnd->GetWindowText(s_text);
			SetWindowText("向窗体中动态添加控件"+ s_text);
		}
}
