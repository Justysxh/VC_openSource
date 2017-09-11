// DistillSQLDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DistillSQL.h"
#include "DistillSQLDlg.h"
#include <sql.h>
#include <sqlext.h>
#include "excel9.h"
#include "msword9.h"
#include "atlbase.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#pragma comment(lib,"odbc32.lib")
extern char path[MAX_PATH];
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
// CDistillSQLDlg dialog

CDistillSQLDlg::CDistillSQLDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDistillSQLDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDistillSQLDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDistillSQLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDistillSQLDlg)
	DDX_Control(pDX, IDC_LIST1, m_Frame);
	DDX_Control(pDX, IDC_EDIT2, m_Pwd);
	DDX_Control(pDX, IDC_EDIT1, m_Name);
	DDX_Control(pDX, IDC_COMBO3, m_Table);
	DDX_Control(pDX, IDC_COMBO2, m_Database);
	DDX_Control(pDX, IDC_COMBO1, m_Server);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDistillSQLDlg, CDialog)
	//{{AFX_MSG_MAP(CDistillSQLDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_REFURBISH, OnRefurbish)
	ON_BN_CLICKED(IDC_LOGIN, OnLogin)
	ON_CBN_SELCHANGE(IDC_COMBO3, OnSelchangeCombo3)
	ON_BN_CLICKED(IDC_TOWORD, OnToword)
	ON_BN_CLICKED(IDC_TOEXCEL, OnToexcel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDistillSQLDlg message handlers

BOOL CDistillSQLDlg::OnInitDialog()
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
	CString sServer;
	CString sText=GetServer();
	FormatString(sText,&m_Server);

	m_Server.SetCurSel(0);
	m_Name.SetWindowText("sa");

	//设置列表视图的扩展风格
	m_Frame.SetExtendedStyle(LVS_EX_FLATSB			//扁平风格显示滚动条
		|LVS_EX_FULLROWSELECT					//允许整行选中
		|LVS_EX_HEADERDRAGDROP				//允许整列拖动
		|LVS_EX_ONECLICKACTIVATE				//单击选中项
		|LVS_EX_GRIDLINES);						//画出网格线
	//设置表头
	m_Frame.InsertColumn(0,"字段名",LVCFMT_LEFT,155,0);
	m_Frame.InsertColumn(1,"字段类型",LVCFMT_LEFT,155,1);
	m_Frame.InsertColumn(2,"字段大小",LVCFMT_LEFT,155,2);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDistillSQLDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDistillSQLDlg::OnPaint() 
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
HCURSOR CDistillSQLDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

CString CDistillSQLDlg::GetServer()
{
	CString sSQLChar = "Driver={SQL Server}";
	CString cKey = "SERVER";
	SQLHENV hSqlHenv;
	SQLHDBC hSQLHdbc;
	short sConnStrOut;
	CString Returnstr;
	//分配环境句柄
	int IsSuccess=SQLAllocHandle(SQL_HANDLE_ENV,SQL_NULL_HANDLE,&hSqlHenv);
	if (IsSuccess == SQL_SUCCESS || IsSuccess == SQL_SUCCESS_WITH_INFO)
	{
		//设置环境属性
		IsSuccess = SQLSetEnvAttr(hSqlHenv, SQL_ATTR_ODBC_VERSION, (void *)SQL_OV_ODBC3, 0);
		if (IsSuccess == SQL_SUCCESS || IsSuccess == SQL_SUCCESS_WITH_INFO) 
		{
			//分配一个连接句柄
			IsSuccess = SQLAllocHandle(SQL_HANDLE_DBC, hSqlHenv, &hSQLHdbc);
			if (IsSuccess == SQL_SUCCESS || IsSuccess == SQL_SUCCESS_WITH_INFO) 
			{
				CString szConnStrOut;
				//调用SQLBrowseConnect
				IsSuccess =SQLBrowseConnect(hSQLHdbc, (SQLCHAR *)sSQLChar.GetBuffer(sSQLChar.GetLength())
					,SQL_NTS,(SQLCHAR*)(szConnStrOut.GetBuffer(4824)), 4824, &sConnStrOut);
				szConnStrOut.ReleaseBuffer();
				int nPos=szConnStrOut.Find(cKey);
				if(nPos!=-1)
					nPos=nPos+cKey.GetLength();
				int nBegin=szConnStrOut.Find("{",nPos+1);
				int nEnd=szConnStrOut.Find("}",nPos+1);
				Returnstr=szConnStrOut.Mid(nBegin+1,nEnd-(nBegin+1));
			}
		}
	}
	return Returnstr;
}

void CDistillSQLDlg::FormatString(CString sText, CComboBox *pComboBox)
{
	int nPos=0,nOldPos=0;
	CString sMem;
	while(nPos!=-1)
	{
		nOldPos=nPos;
		nPos=sText.Find(",",nPos+1);
		if(nPos==-1)
			nPos=sText.GetLength();
		if(nOldPos==0)
			sMem=sText.Mid(nOldPos,nPos-nOldPos);
		else
			sMem=sText.Mid(nOldPos+1,nPos-nOldPos-1);
		if(nPos==sText.GetLength())
			nPos=-1;
		if(sMem.IsEmpty())
			continue;
		pComboBox->AddString(sMem);
	}
}

void CDistillSQLDlg::OnRefurbish() 
{
	// TODO: Add your control notification handler code here
	m_Server.ResetContent();
	CString sServer;
	CString sText = GetServer();
	FormatString(sText,&m_Server);
	m_Server.SetCurSel(0);
}

void CDistillSQLDlg::OnLogin() 
{
	// TODO: Add your control notification handler code here
	m_Table.ResetContent();
	m_Database.ResetContent();
	CString strname,server,name,password;
	m_Server.GetWindowText(server);
	m_Name.GetWindowText(name);
	m_Pwd.GetWindowText(password);
	BOOL isConnection;
	if(server.IsEmpty())
	{
		MessageBox("请选择服务器！");
		return;
	}
	else
	{
		isConnection = m_Ado.OnInitADOConn("Master",server,name,password);
	}
	if(isConnection)
	{
		_bstr_t bstrSQL;
		bstrSQL = "select*from sysdatabases where dbid>6";
		CString strText;
		m_Ado.m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_Ado.m_pRecordset->Open(bstrSQL,m_Ado.m_pConnection.GetInterfacePtr(),
			adOpenDynamic,adLockOptimistic,adCmdText);
		while(!m_Ado.m_pRecordset->adoEOF)
		{
			strText=(char*)(_bstr_t)m_Ado.m_pRecordset->GetCollect("name");
			m_Database.AddString(strText);
			m_Ado.m_pRecordset->MoveNext();
		}
		m_Ado.ExitConnect();
		m_Database.SetCurSel(0);
		GetTableList();
	}
}

void CDistillSQLDlg::GetTableList()
{
	CString database,server,name,password;
	m_Database.GetLBText(m_Database.GetCurSel(),database);
	m_Server.GetLBText(m_Server.GetCurSel(),server);
	m_Name.GetWindowText(name);
	m_Pwd.GetWindowText(password);
	m_Ado.OnInitADOConn(database,server,name,password);
	CString bstrSQL;
	bstrSQL.Format("select*from sysobjects where xtype='U'");
	CString strText;
	m_Ado.m_pRecordset.CreateInstance(__uuidof(Recordset));
	m_Ado.m_pRecordset->Open((_bstr_t)bstrSQL,m_Ado.m_pConnection.GetInterfacePtr(),
		adOpenDynamic,adLockOptimistic,adCmdText);
	int i=0;
	while(m_Ado.m_pRecordset->adoEOF==0)
	{
		strText=(char*)(_bstr_t)m_Ado.m_pRecordset->GetCollect("name");
		m_Table.InsertString(i++,strText);
		m_Ado.m_pRecordset->MoveNext();
	}
	m_Ado.ExitConnect();
	m_Table.SetCurSel(0);
	GetTableFrame();
}

void CDistillSQLDlg::OnSelchangeCombo3() 
{
	// TODO: Add your control notification handler code here
	GetTableFrame();
}


void CDistillSQLDlg::GetTableFrame()
{
	m_Frame.DeleteAllItems();
	CString sql,database,server,name,password,table;
	m_Table.GetLBText(m_Table.GetCurSel(),table);	
	sql.Format("sp_mshelpcolumns %s",table);
	m_Server.GetLBText(m_Server.GetCurSel(),server);
	m_Database.GetLBText(m_Database.GetCurSel(),database);
	m_Name.GetWindowText(name);
	m_Pwd.GetWindowText(password);
	m_Ado.OnInitADOConn(database,server,name,password);
	m_Ado.m_pRecordset->Open((_bstr_t)sql,m_Ado.m_pConnection.GetInterfacePtr(),
		adOpenDynamic,adLockOptimistic,adCmdText);
	int i=0;
	while(!m_Ado.m_pRecordset->adoEOF)
	{
		m_Frame.InsertItem(i,"");
		m_Frame.SetItemText(i,0,(char*)(_bstr_t)m_Ado.m_pRecordset->GetCollect("col_name"));
		m_Frame.SetItemText(i,1,(char*)(_bstr_t)m_Ado.m_pRecordset->GetCollect("col_typename"));
		m_Frame.SetItemText(i,2,(char*)(_bstr_t)m_Ado.m_pRecordset->GetCollect("col_len"));
		i++;
		m_Ado.m_pRecordset->MoveNext();
	}
	m_Ado.ExitConnect();
}

void CDistillSQLDlg::OnToword() 
{
	// TODO: Add your control notification handler code here
	_Application1 app;	
	Documents doc;
	CComVariant a (_T("")),b(false),c(0),d(true),aa(1),bb(20);
	_Document doc1;
	Tables tabs;
	Range1 rangestar,range;
	Selection sele;
	COleVariant	colevariant;
	
	//初始化连接
	app.CreateDispatch("word.Application");
	doc.AttachDispatch(app.GetDocuments());
	doc1.AttachDispatch(doc.Add(&a,&b,&c,&d));
	range.AttachDispatch(doc1.GetContent());
	tabs.AttachDispatch(doc1.GetTables());
	tabs.Add(range,m_Frame.GetItemCount()+1,3,colevariant,colevariant);//创建表格
	sele.AttachDispatch(app.GetSelection());
	CString sText[]={"字段名","字段类型","字段大小"};

	for(long num=0;num<3;num++)
	{
		sele.TypeText(sText[num]);//插入数据(char*)(_bstr_t)
		sele.MoveRight((COleVariant)"1",(COleVariant)"1",(COleVariant)"0");
	}
	for(int i=0;i<m_Frame.GetItemCount();i++)
	{
		for(long j=0;j<3;j++)
		{
			sele.TypeText(m_Frame.GetItemText(i,j));
			sele.MoveRight((COleVariant)"1",(COleVariant)"1",(COleVariant)"0");
		}
	}
	app.SetVisible(true);
	tabs.ReleaseDispatch();
	sele.ReleaseDispatch();
	doc.ReleaseDispatch();
	doc1.ReleaseDispatch();
	app.ReleaseDispatch();
}

void CDistillSQLDlg::OnToexcel() 
{
	// TODO: Add your control notification handler code here
	CString strPath,strText="",strFile,name,table;
	m_Table.GetLBText(m_Table.GetCurSel(),table);	
	CFileDialog file(FALSE,NULL,table,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		"EXCEL文件(*.xls)|*.xls| |",AfxGetMainWnd());
	if(file.DoModal()==IDOK)
	{
		strPath=file.GetPathName();
		if(strPath.Right(4) != ".xls")
			strPath +=".xls";
	
		_Application2 app;    
		Workbooks books;
		_Workbook book;
		Worksheets sheets;
		_Worksheet sheet;
		Range2 range;
		COleVariant
			covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

		//创建Excel 2000服务器(启动Excel) 
		if (!app.CreateDispatch("Excel.Application",NULL)) 
		{ 
			AfxMessageBox("创建Excel服务失败!"); 
			exit(1); 
		} 
		app.SetVisible(false); 
		//利用模板文件建立新文档 
		CString ExcelPath = path;
		if(ExcelPath.Right(1) != "\\")
				ExcelPath +="\\";
		ExcelPath += "SQLToExcel";
		books.AttachDispatch(app.GetWorkbooks(),true); 
		book.AttachDispatch(books.Add(_variant_t(ExcelPath)));
		//得到Worksheets 
		sheets.AttachDispatch(book.GetWorksheets(),true);	
		//得到sheet1 
		sheet.AttachDispatch(sheets.GetItem(_variant_t("sheet1")),true);
		CString str1;
		str1 = "第1页";
		sheet.SetName(str1);
		for( int i=0;i<sheets.GetCount()-1;i++)
		{
			sheet = sheet.GetNext();
			str1.Format("第%d页",i+2);
			sheet.SetName(str1);
		}
		sheet.AttachDispatch(sheets.GetItem(_variant_t("第1页")),true);
		//得到全部Cells 
		range.AttachDispatch(sheet.GetCells(),true); 
		CString sText[]={"字段名","字段类型","字段大小"};
		for(int setnum=0;setnum<m_Frame.GetItemCount()+1;setnum++)
		{
			for(int num=0;num<3;num++)
			{
				if(!setnum)
				{
					range.SetItem(_variant_t((long)(setnum+1)),_variant_t((long)(num+1)),
						_variant_t(sText[num]));
				}
				else
				{
					range.SetItem(_variant_t((long)(setnum+1)),_variant_t((long)(num+1)),
						_variant_t(m_Frame.GetItemText(setnum-1,num)));
				}
			}
		}
		sheet.SaveAs(strPath,covOptional,covOptional,covOptional,covOptional,
			covOptional,covOptional,covOptional,covOptional);
		app.SetVisible(true); 
		//释放对象 
		range.ReleaseDispatch(); 
		sheet.ReleaseDispatch(); 
		sheets.ReleaseDispatch(); 
		book.ReleaseDispatch(); 
		books.ReleaseDispatch();
		app.ReleaseDispatch(); 
	}
}
