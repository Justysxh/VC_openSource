// ReturnPataDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ReturnPata.h"
#include "ReturnPataDlg.h"

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
// CReturnPataDlg dialog

CReturnPataDlg::CReturnPataDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReturnPataDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReturnPataDlg)
	m_Edit = _T("");
	m_Name = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReturnPataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReturnPataDlg)
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	DDX_Text(pDX, IDC_EDIT1, m_Edit);
	DDX_Text(pDX, IDC_EDIT2, m_Name);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CReturnPataDlg, CDialog)
	//{{AFX_MSG_MAP(CReturnPataDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTRANSFER, OnButtransfer)
	ON_BN_CLICKED(IDC_BUTEXIT, OnButexit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReturnPataDlg message handlers

BOOL CReturnPataDlg::OnInitDialog()
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
	m_Grid.SetExtendedStyle(LVS_EX_FLATSB
		|LVS_EX_FULLROWSELECT
		|LVS_EX_HEADERDRAGDROP
		|LVS_EX_ONECLICKACTIVATE
		|LVS_EX_GRIDLINES);
	m_Grid.InsertColumn(0,"姓名",LVCFMT_LEFT,100,0);
	m_Grid.InsertColumn(1,"联系电话",LVCFMT_LEFT,100,1);
	m_Grid.InsertColumn(2,"移动电话",LVCFMT_LEFT,100,2);
	m_Grid.InsertColumn(3,"QQ",LVCFMT_LEFT,100,3);
	m_Grid.InsertColumn(4,"Email",LVCFMT_LEFT,100,4);
	m_Grid.InsertColumn(5,"地址",LVCFMT_LEFT,100,5);
	OnInitADOConn();
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	CString str;
	str = "select * from friend";
	m_pRecordset->Open((_bstr_t)str,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	while(!m_pRecordset->adoEOF)
	{
		m_Grid.InsertItem(0,"");
		m_Grid.SetItemText(0,0,(char*)(_bstr_t)m_pRecordset->GetCollect("姓名"));
		m_Grid.SetItemText(0,1,(char*)(_bstr_t)m_pRecordset->GetCollect("联系电话"));
		m_Grid.SetItemText(0,2,(char*)(_bstr_t)m_pRecordset->GetCollect("移动电话"));
		m_Grid.SetItemText(0,3,(char*)(_bstr_t)m_pRecordset->GetCollect("QQ"));
		m_Grid.SetItemText(0,4,(char*)(_bstr_t)m_pRecordset->GetCollect("Email"));
		m_Grid.SetItemText(0,5,(char*)(_bstr_t)m_pRecordset->GetCollect("地址"));
		m_pRecordset->MoveNext();
	}
	ExitConnect();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CReturnPataDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CReturnPataDlg::OnPaint() 
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
HCURSOR CReturnPataDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CReturnPataDlg::OnInitADOConn()
{
	CString strConnect;
	try
	{
		m_pConnection.CreateInstance("ADODB.Connection"); 
		strConnect.Format("Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=shujuku;Data Source=.");
		m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}

void CReturnPataDlg::ExitConnect()
{
	if(m_pRecordset!=NULL)
		m_pRecordset->Close();
	m_pConnection->Close();
}

void CReturnPataDlg::OnButtransfer() 
{
	UpdateData(true);
	if(m_Name.IsEmpty())
	{
		MessageBox("姓名不能为空");
		return;
	}
	OnInitADOConn();
	CString str;
	str.Format("declare @c nvarchar(50) exec aaa @name='%s',@college=@c OUTPUT select @c as 移动电话",m_Name);
	m_pRecordset->Open((_bstr_t)str,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	if(!m_pRecordset->adoEOF)
	{
		m_Edit = (char*)(_bstr_t)m_pRecordset->GetCollect("移动电话");
	}
	ExitConnect();
	UpdateData(false);
}

void CReturnPataDlg::OnButexit() 
{
	CDialog::OnCancel();
}
