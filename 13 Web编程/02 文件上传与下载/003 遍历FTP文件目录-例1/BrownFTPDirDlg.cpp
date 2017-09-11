// BrownFTPDirDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BrownFTPDir.h"
#include "BrownFTPDirDlg.h"



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
// CBrownFTPDirDlg dialog

CBrownFTPDirDlg::CBrownFTPDirDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBrownFTPDirDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBrownFTPDirDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CBrownFTPDirDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBrownFTPDirDlg)
	DDX_Control(pDX, IDC_TREEINFO, m_TreeInfo);
	DDX_Control(pDX, IDC_FTPPORT, m_Port);
	DDX_Control(pDX, IDC_FTPUSER, m_User);
	DDX_Control(pDX, IDC_FTPSERVER, m_Server);
	DDX_Control(pDX, IDC_FTPPASS, m_Pass);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBrownFTPDirDlg, CDialog)
	//{{AFX_MSG_MAP(CBrownFTPDirDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOGIN, OnLogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBrownFTPDirDlg message handlers

BOOL CBrownFTPDirDlg::OnInitDialog()
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

void CBrownFTPDirDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBrownFTPDirDlg::OnPaint() 
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
HCURSOR CBrownFTPDirDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBrownFTPDirDlg::OnOK() 
{

}

void CBrownFTPDirDlg::OnLogin() 
{
	CString server;
	m_Server.GetWindowText(server);
	m_TreeInfo.DeleteAllItems();
	HTREEITEM hRoot =  m_TreeInfo.InsertItem(server,0,0);
	ListDir("",hRoot);
}

void CBrownFTPDirDlg::ListDir(CString dir, HTREEITEM hParent)
{
	CString filename ;
	CString server,port,user,pass;
	m_Server.GetWindowText(server);
	m_Port.GetWindowText(port);
	m_User.GetWindowText(user);
	m_Pass.GetWindowText(pass);

	CInternetSession session;
	CFtpConnection* pTemp  =  session.GetFtpConnection(server,user,pass,atoi(port));

	CFtpFileFind Find(pTemp);
	HTREEITEM hItem = hParent;
	HTREEITEM hSubItem;
	BOOL ret ;
	if (dir.IsEmpty())
		ret = Find.FindFile(NULL,INTERNET_FLAG_EXISTING_CONNECT);
	else
		ret = Find.FindFile(dir,INTERNET_FLAG_EXISTING_CONNECT);
	if (ret)
	{
		while (Find.FindNextFile())
		{
			filename = Find.GetFileName();
			hSubItem = m_TreeInfo.InsertItem(filename,0,0, hParent);

			if (Find.IsDirectory())
			{
				ListDir(dir+"\\"+filename,hSubItem);
			}
		}
		if (!Find.IsDirectory())
		{
			filename = Find.GetFileName();
			m_TreeInfo.InsertItem(filename,0,0,hItem);
	}
		else
		{
			ListDir(dir+"\\"+filename,hItem);
		}
	}
	Find.Close();
	delete pTemp;
	
}

"provider = SQLOLEDB.1; password = ''; Persist Security info = TRUE; User ID = sa; Initial Catalog = '数据库'; Data Source = '.'"
"driver = {SQL Server}; SERVER = .;UID = sa; PWD = '';DATABASE = 数据库"