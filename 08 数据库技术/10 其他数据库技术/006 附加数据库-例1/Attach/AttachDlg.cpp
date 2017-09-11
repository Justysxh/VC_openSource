// AttachDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Attach.h"
#include "AttachDlg.h"

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
// CAttachDlg dialog

CAttachDlg::CAttachDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAttachDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAttachDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAttachDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAttachDlg)
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAttachDlg, CDialog)
	//{{AFX_MSG_MAP(CAttachDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAttachDlg message handlers

BOOL CAttachDlg::OnInitDialog()
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
	m_Grid.InsertColumn(0,"原文件名",LVCFMT_LEFT,100,0);
	m_Grid.InsertColumn(1,"当前文件位置",LVCFMT_LEFT,230,1);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAttachDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAttachDlg::OnPaint() 
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
HCURSOR CAttachDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAttachDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	m_Grid.DeleteAllItems();
	CFileDialog file(true,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		"All Files(*.*)|*.*| |",AfxGetMainWnd());
	if(file.DoModal()==IDOK)
	{
		strText = file.GetPathName();
		strName = file.GetFileName();
		m_Edit.SetWindowText(strText);
		str = strName.Left(strName.GetLength()-9);
		CString mdfname="",logname="";
		mdfname.Format("%s_Data.MDF",str);
		logname.Format("%s_Log.LDF",str);
		strmdf = strText;
		strlog = strText;
		strlog.Replace("Data.MDF","Log.LDF");
		m_Grid.InsertItem(0,"");
		m_Grid.SetItemText(0,0,mdfname);
		m_Grid.SetItemText(0,1,strmdf);
		m_Grid.InsertItem(1,"");
		m_Grid.SetItemText(1,0,logname);
		m_Grid.SetItemText(1,1,strlog);
	}
}

void CAttachDlg::OnInitADOConn()
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

void CAttachDlg::ExitConnect()
{
	if(m_pRecordset != NULL)
		m_pRecordset->Close();
	m_pConnection->Close();
}

void CAttachDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	OnInitADOConn();
	_bstr_t sql;
	sql = "EXEC sp_attach_db @dbname = N'"+str+"',@filename1 = N'"
		+strmdf+"', @filename2 = N'"+strlog+"'";
	m_pConnection->Execute(sql,NULL,adCmdText);
	ExitConnect();
	MessageBox("附加数据库完成","附加数据库",MB_ICONASTERISK);
}
