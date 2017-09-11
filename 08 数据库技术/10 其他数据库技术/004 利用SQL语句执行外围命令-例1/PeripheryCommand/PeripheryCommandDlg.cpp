// PeripheryCommandDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PeripheryCommand.h"
#include "PeripheryCommandDlg.h"

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
// CPeripheryCommandDlg dialog

CPeripheryCommandDlg::CPeripheryCommandDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPeripheryCommandDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPeripheryCommandDlg)
	m_Edit1 = _T("");
	m_Edit2 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPeripheryCommandDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPeripheryCommandDlg)
	DDX_Text(pDX, IDC_EDIT1, m_Edit1);
	DDX_Text(pDX, IDC_EDIT2, m_Edit2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPeripheryCommandDlg, CDialog)
	//{{AFX_MSG_MAP(CPeripheryCommandDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTCOPY, OnButcopy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPeripheryCommandDlg message handlers

BOOL CPeripheryCommandDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPeripheryCommandDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPeripheryCommandDlg::OnPaint() 
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
HCURSOR CPeripheryCommandDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPeripheryCommandDlg::OnInitADOConn()
{
	CString strConnect;
	try
	{
		m_pConnection.CreateInstance("ADODB.Connection"); 
		strConnect.Format("Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=master;Data Source=.");
		m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}

void CPeripheryCommandDlg::ExitConnect()
{
	if(m_pRecordset!=NULL)
		m_pRecordset->Close();
	m_pConnection->Close();
}

void CPeripheryCommandDlg::OnButton1() 
{
	CFileDialog file(true,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"All Files(*.*)|*.*| |",AfxGetMainWnd());
	if(file.DoModal()==IDOK)
	{
		strName = file.GetFileName();
		m_Edit1 = file.GetPathName();
	}
	UpdateData(false);
}

void CPeripheryCommandDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CString ReturnPach;
	TCHAR szPath[_MAX_PATH];
	BROWSEINFO bi;
	bi.hwndOwner=NULL;
	bi.pidlRoot=NULL;
	bi.lpszTitle=_T("请选择文件夹");
	bi.pszDisplayName=szPath;
	bi.ulFlags=BIF_RETURNONLYFSDIRS;
	bi.lpfn=NULL;
	bi.lParam=NULL;
	LPITEMIDLIST pItemIDList=SHBrowseForFolder(&bi);
	if(pItemIDList)
	{
		if(SHGetPathFromIDList(pItemIDList,szPath))
			ReturnPach=szPath;	
	}
	else
		ReturnPach="";
	m_Edit2 = ReturnPach;
	m_Edit2 = m_Edit2 + "\\" + strName;
	UpdateData(false);
}

void CPeripheryCommandDlg::OnButcopy() 
{
	UpdateData(true);
	OnInitADOConn();
	CString bstrSQL;
	bstrSQL.Format("xp_cmdshell 'copy %s %s', NO_OUTPUT",m_Edit1,m_Edit2);
	m_pConnection->Execute((_bstr_t)bstrSQL,NULL,adCmdText);
	ExitConnect();
	MessageBox("复制成功！");
}
