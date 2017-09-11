// TimeCardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TimeCard.h"
#include "TimeCardDlg.h"
#include "CardHook.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
CTimeCardDlg *dlg;
void Callhookpro(char * str)
{
	CTime ti = CTime::GetCurrentTime();
	CString Date,Time,CommandText;
	Date.Format("%d-%d-%d",ti.GetYear(),ti.GetMonth(),ti.GetDay());
	Time.Format("%d:%d:%d",ti.GetHour(),ti.GetMinute(),ti.GetSecond());
	CommandText.Format("insert into timeCard(员工工号,打卡日期,打卡时间) \
		values('%s','%s','%s')",str,Date,Time);

	_CommandPtr		m_pCommand;
	m_pCommand.CreateInstance(__uuidof(Command));
	m_pCommand->ActiveConnection = dlg->m_pConnection; 
	m_pCommand->CommandText = (_bstr_t)CommandText; 
	m_pCommand->Execute(NULL, NULL,adCmdText);
	dlg->UpdateCardList();
}

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
// CTimeCardDlg dialog

CTimeCardDlg::CTimeCardDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTimeCardDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTimeCardDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTimeCardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTimeCardDlg)
	DDX_Control(pDX, IDC_EDIT4, m_xl);
	DDX_Control(pDX, IDC_EDIT3, m_sex);
	DDX_Control(pDX, IDC_EDIT2, m_name);
	DDX_Control(pDX, IDC_EDIT1, m_id);
	DDX_Control(pDX, IDC_LIST2, m_cardlist);
	DDX_Control(pDX, IDC_LIST1, m_personlist);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTimeCardDlg, CDialog)
	//{{AFX_MSG_MAP(CTimeCardDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON3, OnClose)
	ON_BN_CLICKED(IDC_BUTTON1, OnAddRow)
	ON_NOTIFY(LVN_ITEMCHANGING, IDC_LIST1, OnItemchangingList1)
	ON_BN_CLICKED(IDC_BUTTON2, OnDeleteRow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimeCardDlg message handlers

BOOL CTimeCardDlg::OnInitDialog()
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
	
	::CoInitialize(NULL);

	try
	{
       m_pConnection.CreateInstance("ADODB.Connection");
	   CString strConnect="Provider=Microsoft.Jet.OLEDB.4.0;\
		   Data Source=shujuku.mdb;Persist Security Info=False";
	   m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox("数据库连接错误",0,0);
	}
	
	m_personlist.InsertColumn(0,"员工工号");
	m_personlist.SetColumnWidth(0,100);
	
	m_personlist.InsertColumn(1,"姓名");
	m_personlist.SetColumnWidth(1,100);

	m_personlist.InsertColumn(2,"性别");
	m_personlist.SetColumnWidth(2,50);

	m_personlist.InsertColumn(3,"学历");
	m_personlist.SetColumnWidth(3,50);

	m_personlist.SetExtendedStyle(LVS_EX_FLATSB | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	InitPersonList();

	m_cardlist.InsertColumn(0,"员工工号");
	m_cardlist.SetColumnWidth(0,100);
	
	m_cardlist.InsertColumn(1,"姓名");
	m_cardlist.SetColumnWidth(1,100);

	m_cardlist.InsertColumn(2,"性别");
	m_cardlist.SetColumnWidth(2,50);

	m_cardlist.InsertColumn(3,"学历");
	m_cardlist.SetColumnWidth(3,50);

	m_cardlist.InsertColumn(4,"打卡时间");
	m_cardlist.SetColumnWidth(4,200);

	m_cardlist.SetExtendedStyle(LVS_EX_FLATSB | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	UpdateCardList();

	installhook();
	initdll(Callhookpro,m_pConnection);
	dlg = this;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTimeCardDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTimeCardDlg::OnPaint() 
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
HCURSOR CTimeCardDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTimeCardDlg::InitPersonList()
{
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	m_pRecordset->Open("select* from picture",m_pConnection.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
	int m = m_pRecordset->GetRecordCount();
	
	CString temp;
	int index = 0;
	m_personlist.DeleteAllItems();
	while(!m_pRecordset->adoEOF)
	{
		temp= (char*)(_bstr_t)m_pRecordset->GetCollect("卡号");
		m_personlist.InsertItem(index,temp);

		m_personlist.SetItemText(index,1,(char*)(_bstr_t)m_pRecordset->GetCollect("姓名"));
		m_personlist.SetItemText(index,2,(char*)(_bstr_t)m_pRecordset->GetCollect("性别"));
		m_personlist.SetItemText(index,3,(char*)(_bstr_t)m_pRecordset->GetCollect("学历"));
		index++;
		m_pRecordset->MoveNext();
	}
}

void CTimeCardDlg::OnDestroy() 
{
	UnHook();
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	
}

void CTimeCardDlg::OnClose() 
{
	CDialog::OnCancel();	
}

void CTimeCardDlg::UpdateCardList()
{
	m_cardlist.DeleteAllItems();
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	m_pRecordset->Open("select a.*,b.打卡日期,b.打卡时间 from picture a,timecard b \
		where a.卡号 = b.员工工号 order by a.卡号",m_pConnection.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
	int count = m_pRecordset->GetRecordCount();
	for (int i =0;i < count ; i++)
	{
		CString time;
		time.Format("%s %s",(char*)(_bstr_t)m_pRecordset->GetCollect("打卡日期"),
			(char*)(_bstr_t)m_pRecordset->GetCollect("打卡时间"));
		m_cardlist.InsertItem(i,(char*)(_bstr_t)m_pRecordset->GetCollect("卡号"));
		m_cardlist.SetItemText(i,1,(char*)(_bstr_t)m_pRecordset->GetCollect("姓名"));
		m_cardlist.SetItemText(i,2,(char*)(_bstr_t)m_pRecordset->GetCollect("性别"));
		m_cardlist.SetItemText(i,3,(char*)(_bstr_t)m_pRecordset->GetCollect("学历"));
		m_cardlist.SetItemText(i,4,time);
		m_pRecordset->MoveNext();
	}
}

void CTimeCardDlg::AddRow()
{
	CString id,name,sex,xl,sql;
	m_id.GetWindowText(id);
	m_name.GetWindowText(name);
	m_sex.GetWindowText(sex);
	m_xl.GetWindowText(xl);
	sql.Format("Select * From picture Where 卡号 = '%s'",id);
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	m_pRecordset->Open((_variant_t)sql,m_pConnection.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
	int count = m_pRecordset->GetRecordCount();
	if (count > 0 )
	{
		MessageBox("卡号已存在不能添加！");
		return ;
	}
	else
	{
		CString CommandText;
		CommandText.Format("insert into picture(卡号,姓名,性别,学历) \
			values('%s','%s','%s','%s')",id,name,sex,xl);

		_CommandPtr		m_pCommand;
		m_pCommand.CreateInstance(__uuidof(Command));
		m_pCommand->ActiveConnection = dlg->m_pConnection; 
		m_pCommand->CommandText = (_bstr_t)CommandText; 
		m_pCommand->Execute(NULL, NULL,adCmdText);
		InitPersonList();
	}
}

void CTimeCardDlg::OnAddRow() 
{
	AddRow();	
}

void CTimeCardDlg::OnItemchangingList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	CString id = m_personlist.GetItemText(pNMListView->iItem,0);
	CString name = m_personlist.GetItemText(pNMListView->iItem,1);
	CString sex = m_personlist.GetItemText(pNMListView->iItem,2);
	CString xl = m_personlist.GetItemText(pNMListView->iItem,3);
	m_id.SetWindowText(id);
	m_name.SetWindowText(name);
	m_sex.SetWindowText(sex);
	m_xl.SetWindowText(xl);
	*pResult = 0;
}

void CTimeCardDlg::DeleteRow()
{
	int index = m_personlist.GetSelectionMark();
	if (index >= 0)
	{
		CString id = m_personlist.GetItemText(index,0);
		
		CString CommandText;
		//CommandText.Format("delete from timecard where 员工工号 = '%s'  \
		//	delete from picture where 卡号 = '%s'",id,id);
		CommandText.Format("delete from timecard where 员工工号 = '%s'",id);
		_CommandPtr		m_pCommand;
		m_pCommand.CreateInstance(__uuidof(Command));
		m_pCommand->ActiveConnection = dlg->m_pConnection; 
		m_pCommand->CommandText = (_bstr_t)CommandText; 
		m_pCommand->Execute(NULL, NULL,adCmdText);

		CommandText.Format("delete from picture where 卡号 = '%s'",id);
		m_pCommand->CommandText = (_bstr_t)CommandText; 
		m_pCommand->Execute(NULL, NULL,adCmdText);
		InitPersonList();
		UpdateCardList();
		MessageBox("删除成功!");
	}	
	else
		MessageBox("删除失败！");
}

void CTimeCardDlg::OnDeleteRow() 
{
	DeleteRow();	
}
