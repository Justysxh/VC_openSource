// DetachDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Detach.h"
#include "DetachDlg.h"

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
// CDetachDlg dialog

CDetachDlg::CDetachDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDetachDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDetachDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDetachDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDetachDlg)
	DDX_Control(pDX, IDC_LIST1, m_Database);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDetachDlg, CDialog)
	//{{AFX_MSG_MAP(CDetachDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_DBLCLK(IDC_LIST1, OnDblclkList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDetachDlg message handlers

BOOL CDetachDlg::OnInitDialog()
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
	OnInitADOConn();
	_bstr_t bstrSQL;
	bstrSQL = "select name from sysdatabases";
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,
		adLockOptimistic,adCmdText);
	while(!m_pRecordset->adoEOF)
	{
		m_Database.AddString((char*)(_bstr_t)m_pRecordset->GetCollect("name"));
		m_pRecordset->MoveNext();
	}
	ExitConnect();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDetachDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDetachDlg::OnPaint() 
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
HCURSOR CDetachDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDetachDlg::OnInitADOConn()
{
	CString strConnect;
	try
	{
		m_pConnection.CreateInstance("ADODB.Connection"); 
		strConnect.Format("Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist \
			Security Info=False;Initial Catalog=master;Data Source=.");
		m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}

void CDetachDlg::ExitConnect()
{
	if(m_pRecordset != NULL)
		m_pRecordset->Close();
	m_pConnection->Close();
}

void CDetachDlg::OnDblclkList1() 
{
	// TODO: Add your control notification handler code here
	CString strname,database;
	m_Database.GetText(m_Database.GetCurSel(),database);			
	strname.Format("确定分离数据库%s吗？",database);
	if(MessageBox(strname,"分离数据库",MB_OKCANCEL|MB_ICONQUESTION)==IDOK)
	{
		OnInitADOConn();	//连接数据库
		CString sql;
		sql = "EXEC sp_detach_db '"+database+"','TRUE'";				//设置SQL语句
		m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);	//执行分离命令
		m_pConnection->Close();;							//断开数据库连接
		MessageBox("分离数据库完成！","分离数据库",MB_ICONASTERISK);
	}
}
