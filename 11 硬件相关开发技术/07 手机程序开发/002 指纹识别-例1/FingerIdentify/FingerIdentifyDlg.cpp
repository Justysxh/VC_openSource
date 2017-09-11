// FingerIdentifyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FingerIdentify.h"
#include "FingerIdentifyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

typedef struct _Personinfo{
char id[4];
char name[10];
char dept[20];
char finger[100];
bool isuser;
}PersonInfo;

PersonInfo personinfo[999];

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
// CFingerIdentifyDlg dialog

CFingerIdentifyDlg::CFingerIdentifyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFingerIdentifyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFingerIdentifyDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFingerIdentifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFingerIdentifyDlg)
	DDX_Control(pDX, IDC_STATIC1, m_image);
	DDX_Control(pDX, IDC_EDIT3, m_dept);
	DDX_Control(pDX, IDC_EDIT2, m_name);
	DDX_Control(pDX, IDC_EDIT1, m_id);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_ZKFPENGX1, m_zkeng);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFingerIdentifyDlg, CDialog)
	//{{AFX_MSG_MAP(CFingerIdentifyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON6, OnInitfacility)
	ON_BN_CLICKED(IDC_BUTTON5, OnClosefacility)
	ON_BN_CLICKED(IDC_BUTTON4, OnClose)
	ON_NOTIFY(LVN_ITEMCHANGING, IDC_LIST1, OnItemchangingList1)
	ON_BN_CLICKED(IDC_BUTTON2, OnAdd)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON1, OnRegister)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFingerIdentifyDlg message handlers

BOOL CFingerIdentifyDlg::OnInitDialog()
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
	m_list.InsertColumn(0,"员工编号");
	m_list.SetColumnWidth(0,100);
	m_list.InsertColumn(1,"员工姓名");
	m_list.SetColumnWidth(1,100);
	m_list.InsertColumn(2,"员工部门");
	m_list.SetColumnWidth(2,100);

	personinfo[123].isuser = true;
	strcpy(personinfo[123].id,"123");
	strcpy(personinfo[123].name,"张三");
	strcpy(personinfo[123].dept,"C#");

	personinfo[001].isuser = true;
	strcpy(personinfo[001].id,"001");
	strcpy(personinfo[001].name,"李四");
	strcpy(personinfo[001].dept,"软件");
	UpdateList();

	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | 
		LVS_EX_GRIDLINES | LVS_EX_FLATSB);
	m_id.SetLimitText(3);

	IdentifyType = 0;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFingerIdentifyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFingerIdentifyDlg::OnPaint() 
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
HCURSOR CFingerIdentifyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BEGIN_EVENTSINK_MAP(CFingerIdentifyDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CFingerIdentifyDlg)
	ON_EVENT(CFingerIdentifyDlg, IDC_ZKFPENGX1, 9 /* OnEnroll */, OnEnroll, VTS_BOOL VTS_VARIANT)
	ON_EVENT(CFingerIdentifyDlg, IDC_ZKFPENGX1, 8 /* OnImageReceived */, OnImageReceived, VTS_PBOOL)
	ON_EVENT(CFingerIdentifyDlg, IDC_ZKFPENGX1, 10 /* OnCapture */, OnCapture, VTS_BOOL VTS_VARIANT)
	ON_EVENT(CFingerIdentifyDlg, IDC_ZKFPENGX1, 5 /* OnFeatureInfo */, OnFeatureInfo, VTS_I4)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CFingerIdentifyDlg::OnEnroll(BOOL ActionResult, const VARIANT FAR& ATemplate) 
{
  if (!ActionResult)
    MessageBox("注册失败！");
  else
  {
	CString temp;
	m_id.GetWindowText(temp);
	int index = atoi(temp);
	CString sRegTemplate = m_zkeng.GetTemplateAsString();
	strcpy(personinfo[index].finger,sRegTemplate);
    MessageBox("注册成功！");
  }
}

void CFingerIdentifyDlg::OnImageReceived(BOOL FAR* AImageValid) 
{
	CDC *dc = m_image.GetDC();
	CRect rect;
	m_image.GetClientRect(&rect);
	m_zkeng.PrintImageAt((long)dc->m_hDC,0,0,rect.Width(),rect.Height());
}

void CFingerIdentifyDlg::OnCapture(BOOL ActionResult, const VARIANT FAR& ATemplate) 
{
	if (IdentifyType == 1)
	{
		CString temp1,temp2;
		int index = atoi(m_list.GetItemText(m_list.GetSelectionMark(),0));
		temp1 = personinfo[index].finger;
		temp2 = m_zkeng.GetTemplateAsString();
		BOOL RegChanged;
		BSTR btemp = temp1.AllocSysString();
		if (m_zkeng.VerFingerFromStr(&btemp,(LPCTSTR)temp2,false,&RegChanged))
			MessageBox("比对成功！");
		else
			MessageBox("比对失败！");
	}
	else if (IdentifyType == 2)
	{
		CString temp1,temp2;
		temp2 = m_zkeng.GetTemplateAsString();
		BOOL RegChanged;
		bool isok = false;
		for (int i = 0 ; i < 999 ; i++)
		{
			if (personinfo[i].isuser == false)
				continue;
			temp1 = personinfo[i].finger;
			BSTR btemp = temp1.AllocSysString();
			if (m_zkeng.VerFingerFromStr(&btemp,(LPCTSTR)temp2,false,&RegChanged))
				isok = true;
		}
		if (isok)
			MessageBox("比对成功！");
		else
			MessageBox("比对失败！");
	}

	if (IdentifyType != 0)
		IdentifyType = 0;
}

void CFingerIdentifyDlg::OnFeatureInfo(long AQuality) 
{
	int times;
	if (m_zkeng.GetIsRegister())
	{
		times = m_zkeng.GetEnrollIndex() - 1;
		CString temp;
		ltoa(times,temp.GetBuffer(0),10);
		MessageBox("指纹注册还需要按"+temp+"次！");
	}
}

void CFingerIdentifyDlg::OnInitfacility() 
{
	if (m_zkeng.InitEngine() != 0)
		MessageBox("设备初始化失败！");
	else
		MessageBox("设备初始化成功！");
}

void CFingerIdentifyDlg::OnClosefacility() 
{
	m_zkeng.CancelEnroll();
	
}

void CFingerIdentifyDlg::OnClose() 
{
	OnCancel();	
}

void CFingerIdentifyDlg::UpdateList()
{
	m_list.DeleteAllItems();
	for (int i = 0 ; i < 999 ; i++)
	{
		if (personinfo[i].isuser)
		{
			int index = m_list.GetItemCount();
			m_list.InsertItem(index,(char *)personinfo[i].id);
			m_list.SetItemText(index,1,(char *)personinfo[i].name);
			m_list.SetItemText(index,2,(char *)personinfo[i].dept);
		}
	}
}

void CFingerIdentifyDlg::OnItemchangingList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

	if (pNMListView->iItem>=0 && 
		(pNMListView->uNewState & LVIS_SELECTED)) 
	{
		CString temp;
		temp = m_list.GetItemText(pNMListView->iItem,0);
		m_id.SetWindowText(temp);
		temp = m_list.GetItemText(pNMListView->iItem,1);
		m_name.SetWindowText(temp);
		temp = m_list.GetItemText(pNMListView->iItem,2);
		m_dept.SetWindowText(temp);
	}
	*pResult = 0;
}

void CFingerIdentifyDlg::OnAddRow()
{
	CString id,name,dept;
	m_id.GetWindowText(id);
	m_name.GetWindowText(name);
	m_dept.GetWindowText(dept);
	if (id.IsEmpty() || name.IsEmpty() || dept.IsEmpty())
	{
		MessageBox("人员信息不能为空！");
		return;
	}
	int index = atoi(id);
	strcpy(personinfo[index].id,id);
	strcpy(personinfo[index].name,name);
	strcpy(personinfo[index].dept,dept);
	personinfo[index].isuser = true;
	MessageBox("信息添加成功！");
	UpdateList();
}

void CFingerIdentifyDlg::OnAdd() 
{
	OnAddRow();
}

void CFingerIdentifyDlg::OnDestroy() 
{
	OnClosefacility();
	CDialog::OnDestroy();
}

void CFingerIdentifyDlg::OnRegister() 
{
	CString id;
	m_id.GetWindowText(id);
	if (id.IsEmpty())
	{
		MessageBox("请选择注册人员！");
		return;
	}
	m_zkeng.BeginEnroll();
	MessageBox("开始注册！");
}

void CFingerIdentifyDlg::OnButton3() 
{
	if (m_zkeng.GetIsRegister())
		m_zkeng.CancelEnroll();
	IdentifyType = 1;
}

void CFingerIdentifyDlg::OnButton7() 
{
	if (m_zkeng.GetIsRegister())
		m_zkeng.CancelEnroll();
	IdentifyType = 2;	
}
