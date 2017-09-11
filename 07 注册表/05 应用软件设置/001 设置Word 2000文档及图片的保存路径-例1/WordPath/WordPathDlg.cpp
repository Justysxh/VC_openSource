// WordPathDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WordPath.h"
#include "WordPathDlg.h"

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
// CWordPathDlg dialog

CWordPathDlg::CWordPathDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWordPathDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWordPathDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWordPathDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWordPathDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWordPathDlg, CDialog)
	//{{AFX_MSG_MAP(CWordPathDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTPATH, OnBtpath)
	ON_BN_CLICKED(IDC_BTSET, OnBtset)
	ON_BN_CLICKED(IDC_BTPICPATH, OnAddPicPath)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWordPathDlg message handlers

BOOL CWordPathDlg::OnInitDialog()
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

void CWordPathDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWordPathDlg::OnPaint() 
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
HCURSOR CWordPathDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CWordPathDlg::OnBtpath() 
{
	BROWSEINFO bi;   
	char buffer[MAX_PATH];   
	ZeroMemory(buffer,MAX_PATH);   
	bi.hwndOwner=GetSafeHwnd();   
	bi.pidlRoot=NULL;   
	bi.pszDisplayName=buffer;   
	bi.lpszTitle="选择一个文件夹";   
	bi.ulFlags=BIF_EDITBOX;   
	bi.lpfn=NULL;   
	bi.lParam=0;   
	bi.iImage=0; 
	LPITEMIDLIST pList=NULL;   
	if((pList=SHBrowseForFolder(&bi))!=NULL)   
	{   
	char path[MAX_PATH];
	ZeroMemory(path,MAX_PATH);
	SHGetPathFromIDList(pList,path);
    GetDlgItem(IDC_EDPATH)->SetWindowText(path);
	}
}

void CWordPathDlg::OnBtset() 
{
	HKEY sub;
	CString strpath="",strpicpath="";
	GetDlgItem(IDC_EDPATH)->GetWindowText(strpath);
	GetDlgItem(IDC_EDPICPATH)->GetWindowText(strpicpath);
	CString skey="Software\\Microsoft\\Office\\9.0\\Word\\Options";
	::RegCreateKey(HKEY_CURRENT_USER,skey,&sub);
	RegSetValueEx(sub,"DOC-PATH",NULL,REG_SZ,(BYTE*)strpath.GetBuffer(0),strpath.GetLength());
	RegSetValueEx(sub,"PICTURE-PATH",NULL,REG_SZ,(BYTE*)strpicpath.GetBuffer(0),strpicpath.GetLength());
	RegCloseKey(sub);
}

void CWordPathDlg::OnAddPicPath() 
{
	BROWSEINFO bi;   
	char buffer[MAX_PATH];   
	ZeroMemory(buffer,MAX_PATH);   
	bi.hwndOwner=GetSafeHwnd();   
	bi.pidlRoot=NULL;   
	bi.pszDisplayName=buffer;   
	bi.lpszTitle="选择一个文件夹";   
	bi.ulFlags=BIF_EDITBOX;   
	bi.lpfn=NULL;   
	bi.lParam=0;   
	bi.iImage=0; 
	LPITEMIDLIST pList=NULL;   
	if((pList=SHBrowseForFolder(&bi))!=NULL)   
	{   
	char path[MAX_PATH];
	ZeroMemory(path,MAX_PATH);
	SHGetPathFromIDList(pList,path);
    GetDlgItem(IDC_EDPICPATH)->SetWindowText(path);
	}
}
