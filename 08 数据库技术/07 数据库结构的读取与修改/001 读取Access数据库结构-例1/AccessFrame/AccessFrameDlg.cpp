// AccessFrameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AccessFrame.h"
#include "AccessFrameDlg.h"

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
// CAccessFrameDlg dialog

CAccessFrameDlg::CAccessFrameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAccessFrameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAccessFrameDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAccessFrameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAccessFrameDlg)
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
	DDX_Control(pDX, IDC_LIST2, m_List);
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAccessFrameDlg, CDialog)
	//{{AFX_MSG_MAP(CAccessFrameDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_DBLCLK(IDC_LIST2, OnDblclkList2)
	ON_BN_CLICKED(IDC_BUTSJK, OnButsjk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAccessFrameDlg message handlers

BOOL CAccessFrameDlg::OnInitDialog()
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
	m_Grid.InsertColumn(0,"字段名",LVCFMT_LEFT,100,0);
	m_Grid.InsertColumn(1,"字段类型",LVCFMT_LEFT,100,1);
	m_Grid.InsertColumn(2,"字段大小",LVCFMT_LEFT,100,2);	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAccessFrameDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAccessFrameDlg::OnPaint() 
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
HCURSOR CAccessFrameDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAccessFrameDlg::OnDblclkList2() 
{
	// TODO: Add your control notification handler code here
	m_Grid.DeleteAllItems();
	CString sql,str;
	m_List.GetText(m_List.GetCurSel(),str);
	sql.Format("select * from %s",str);
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	m_pRecordset->Open((_bstr_t)sql,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
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
		m_Grid.InsertItem(0,0);
		m_Grid.SetItemText(0,0,(CString)bstr);
		m_Grid.SetItemText(0,1,(char*)(_bstr_t)(long)stype);
		m_Grid.SetItemText(0,2,(char*)(_bstr_t)sizel);
	}
	fields->Release();
}

void CAccessFrameDlg::OnButsjk() 
{
	// TODO: Add your control notification handler code here
	CFileDialog file(true,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"Access(*.mdb)|*.mdb| |",AfxGetMainWnd());
	if(file.DoModal()==IDOK)
	{
		m_List.ResetContent();
		strText=file.GetPathName();
		m_Edit.SetWindowText(strText);
		CString strname,strTable;
		strname.Format("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;Persist Security Info=False",strText);
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
		m_pRecordset = m_pConnection->OpenSchema(adSchemaTables);
		while(!m_pRecordset->adoEOF)
		{
			strTable = (char*)(_bstr_t)m_pRecordset->GetFields()->GetItem("TABLE_TYPE")->Value;
			if(strTable == "TABLE")
			{
				m_List.AddString((char*)(_bstr_t)m_pRecordset->GetFields()->GetItem("TABLE_NAME")->Value);
			}
			m_pRecordset->MoveNext();
		}
	}
}
