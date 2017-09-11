// SQLframeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SQLframe.h"
#include "SQLframeDlg.h"

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
// CSQLframeDlg dialog

CSQLframeDlg::CSQLframeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSQLframeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSQLframeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSQLframeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSQLframeDlg)
	DDX_Control(pDX, IDC_LIST2, m_grid);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSQLframeDlg, CDialog)
	//{{AFX_MSG_MAP(CSQLframeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTCONN, OnButconn)
	ON_LBN_DBLCLK(IDC_LIST1, OnDblclkList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSQLframeDlg message handlers

BOOL CSQLframeDlg::OnInitDialog()
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
	m_grid.SetExtendedStyle(LVS_EX_FLATSB
		|LVS_EX_FULLROWSELECT
		|LVS_EX_HEADERDRAGDROP
		|LVS_EX_ONECLICKACTIVATE
		|LVS_EX_GRIDLINES);
	m_grid.InsertColumn(0,"字段名",LVCFMT_LEFT,100,0);
	m_grid.InsertColumn(1,"类型",LVCFMT_LEFT,100,1);
	m_grid.InsertColumn(2,"大小",LVCFMT_LEFT,100,2);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSQLframeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSQLframeDlg::OnPaint() 
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
HCURSOR CSQLframeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSQLframeDlg::OnButconn() 
{
	// TODO: Add your control notification handler code here
	m_list.ResetContent();
	m_edit.GetWindowText(str);
	OnInitADOConn(str);
	_bstr_t bstrSQL;
	bstrSQL = "select*from sysobjects where xtype='U'";
	CString strText;
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	while(m_pRecordset->adoEOF==0)
	{
		strText=(char*)(_bstr_t)m_pRecordset->GetCollect("name");
		m_list.AddString(strText);
		m_pRecordset->MoveNext();
	}
	ExitConnect();
}

void CSQLframeDlg::OnDblclkList1() 
{
	// TODO: Add your control notification handler code here
	m_grid.DeleteAllItems();
	OnInitADOConn(str);
	CString str1,strname1;
	m_list.GetText(m_list.GetCurSel(),str1);
	strname1.Format("select*from %s",str1);
	_bstr_t bstrSQL;
	bstrSQL = strname1;
	m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	Fields* fields=NULL;
	long countl,sizel;
	BSTR bstr;
	enum DataTypeEnum stype;
	m_pRecordset->get_Fields(&fields);
	countl = fields->Count;
	for(long i=countl-1;i>=0;i--)
	{
		fields->Item[i]->get_Name(&bstr);
		fields->Item[i]->get_Type(&stype);
		fields->Item[i]->get_DefinedSize(&sizel);
		m_grid.InsertItem(0,0);
		m_grid.SetItemText(0,0,(CString)bstr);
		m_grid.SetItemText(0,1,(char*)(_bstr_t)(long)stype);
		m_grid.SetItemText(0,2,(char*)(_bstr_t)sizel);
	}
	fields->Release();
	ExitConnect();
}

void CSQLframeDlg::OnInitADOConn(CString strsjk)
{
	::CoInitialize(NULL);
	strname.Format("Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=%s;Data Source=.",strsjk);
	try
	{
       m_pConnection.CreateInstance("ADODB.Connection");
	   _bstr_t strConnect=strname;
	   m_pConnection->Open(strConnect,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}

void CSQLframeDlg::ExitConnect()
{
	if(m_pRecordset!=NULL)
		m_pRecordset->Close();
	m_pConnection->Close();
	
}
