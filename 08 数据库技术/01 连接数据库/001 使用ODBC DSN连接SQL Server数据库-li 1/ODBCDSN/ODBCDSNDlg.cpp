// ODBCDSNDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ODBCDSN.h"
#include "ODBCDSNDlg.h"

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
// CODBCDSNDlg dialog

CODBCDSNDlg::CODBCDSNDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CODBCDSNDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CODBCDSNDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CODBCDSNDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CODBCDSNDlg)
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CODBCDSNDlg, CDialog)
	//{{AFX_MSG_MAP(CODBCDSNDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CODBCDSNDlg message handlers

BOOL CODBCDSNDlg::OnInitDialog()
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
	m_Grid.InsertColumn(0,"编号",LVCFMT_LEFT,95,0);
	m_Grid.InsertColumn(1,"姓名",LVCFMT_LEFT,95,1);
	m_Grid.InsertColumn(2,"性别",LVCFMT_LEFT,95,2);
	m_Grid.InsertColumn(3,"职业",LVCFMT_LEFT,95,3);
	m_Grid.InsertColumn(4,"年龄",LVCFMT_LEFT,95,4);
	CString strname;
	try
	{
		strname.Format("Provider=MSDASQL.1;Persist Security Info=False;User ID=sa;Data Source=shujuku;Initial Catalog=Shujuku");
		m_pConnection.CreateInstance("ADODB.Connection");
		_bstr_t strConnect=strname;
		m_pConnection->Open(strConnect,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
	_bstr_t bstrSQL = "select * from kjbdsjk order by 编号 desc";
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	while(!m_pRecordset->adoEOF)
	{
		m_Grid.InsertItem(0,"");
		m_Grid.SetItemText(0,0,(char*)(_bstr_t)m_pRecordset->GetCollect("编号"));
		m_Grid.SetItemText(0,1,(char*)(_bstr_t)m_pRecordset->GetCollect("姓名"));
		m_Grid.SetItemText(0,2,(char*)(_bstr_t)m_pRecordset->GetCollect("性别"));
		m_Grid.SetItemText(0,3,(char*)(_bstr_t)m_pRecordset->GetCollect("职业"));
		m_Grid.SetItemText(0,4,(char*)(_bstr_t)m_pRecordset->GetCollect("年龄"));
		m_pRecordset->MoveNext();
	}
	if(m_pRecordset!=NULL)
		m_pRecordset->Close();
	m_pConnection->Close();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CODBCDSNDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CODBCDSNDlg::OnPaint() 
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
HCURSOR CODBCDSNDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
