// barcodeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "barcode.h"
#include "barcodeDlg.h"

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
// CBarcodeDlg dialog

CBarcodeDlg::CBarcodeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBarcodeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBarcodeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBarcodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBarcodeDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBarcodeDlg, CDialog)
	//{{AFX_MSG_MAP(CBarcodeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnLoadData)
	ON_BN_CLICKED(IDC_BUTTON3, OnClose)
	ON_BN_CLICKED(IDC_BUTTON2, OnBalance)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBarcodeDlg message handlers

BOOL CBarcodeDlg::OnInitDialog()
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
	
	m_list.InsertColumn(0,"商品名称");
	m_list.SetColumnWidth(0,100);

	m_list.InsertColumn(1,"条形编码");
	m_list.SetColumnWidth(1,100);

	m_list.InsertColumn(2,"库存数量");
	m_list.SetColumnWidth(2,100);

	m_list.InsertColumn(3,"导入库存数量");
	m_list.SetColumnWidth(3,100);

	m_list.InsertColumn(4,"盘点盈亏数量");
	m_list.SetColumnWidth(4,100);

	m_list.SetExtendedStyle(LVS_EX_FLATSB | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	

	try
	{
       m_pConnection.CreateInstance("ADODB.Connection");
	   CString strConnect="Provider=Microsoft.Jet.OLEDB.4.0;\
		   Data Source=DataBase.mdb;Persist Security Info=False";
	   m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox("数据库连接错误",0,0);
	}

	InitList();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBarcodeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBarcodeDlg::OnPaint() 
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
HCURSOR CBarcodeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBarcodeDlg::InitList()
{
	_RecordsetPtr m_pRecordset;
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	m_pRecordset->Open("select* from 盘点表",m_pConnection.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
	int m = m_pRecordset->GetRecordCount();
	m_list.DeleteAllItems();
	for (int i = 0 ; i < m ; i++)
	{
		m_list.InsertItem(i,(char*)(_bstr_t)m_pRecordset->GetCollect("商品名称"));
		m_list.SetItemText(i,1,(char*)(_bstr_t)m_pRecordset->GetCollect("条形码"));
		m_list.SetItemText(i,2,(char*)(_bstr_t)m_pRecordset->GetCollect("库存数量"));
		m_list.SetItemText(i,3,(char*)(_bstr_t)m_pRecordset->GetCollect("导入库存数量"));
		m_list.SetItemText(i,4,(char*)(_bstr_t)m_pRecordset->GetCollect("盘点盈亏数量"));
		m_pRecordset->MoveNext();
	}
}

void CBarcodeDlg::OnLoadData() 
{
	static char BASED_CODE szFilter[] = "Data Files (*.dat)|*.dat|";

	CFileDialog filedialog(true,NULL,NULL,
			OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
			szFilter,NULL);
	if (filedialog.DoModal() == IDOK)
	{
		CString FileName = filedialog.GetPathName();
		int Size = sizeof(BarCode);
		BarCode barcode;
		CFile f(FileName, CFile::modeRead);

		_CommandPtr		m_pCommand;
		m_pCommand.CreateInstance(__uuidof(Command));
		m_pCommand->ActiveConnection = m_pConnection; 
		for ( int i = 0 ; i < f.GetLength() ; i += Size)
		{
			f.Read(&barcode,Size);
			int pos = strcspn(barcode.code," ");
			barcode.code[pos] = '\0';
			pos = strcspn(barcode.count," ");
			barcode.count[pos] = '\0';
			CString sql;
			sql.Format("Update 盘点表 set 导入库存数量 = %s,\
				 盘点盈亏数量 = %s - 库存数量  Where 条形码 = '%s'",
				barcode.count,barcode.count,barcode.code);
			m_pCommand->CommandText = (_bstr_t)sql; 
			m_pCommand->Execute(NULL, NULL,adCmdText);
		}
		f.Close();
		InitList();
		MessageBox("数据导入成功！");
	}	
}

void CBarcodeDlg::OnClose() 
{
	CDialog::OnCancel();	
}

void CBarcodeDlg::OnBalance() 
{
	_CommandPtr		m_pCommand;
	m_pCommand.CreateInstance(__uuidof(Command));
	m_pCommand->ActiveConnection = m_pConnection; 	
	CString sql = "Update 盘点表 Set 库存数量 = 库存数量 + 盘点盈亏数量 \
		 ,盘点盈亏数量 = 0,导入库存数量 = 0";
	m_pCommand->CommandText = (_bstr_t)sql; 
	m_pCommand->Execute(NULL, NULL,adCmdText);	
	InitList();
	MessageBox("结算成功！");
}
