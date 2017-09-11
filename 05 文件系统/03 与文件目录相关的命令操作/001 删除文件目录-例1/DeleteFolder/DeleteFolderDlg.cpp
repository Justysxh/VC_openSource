// DeleteFolderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DeleteFolder.h"
#include "DeleteFolderDlg.h"

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
// CDeleteFolderDlg dialog

CDeleteFolderDlg::CDeleteFolderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDeleteFolderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDeleteFolderDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDeleteFolderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeleteFolderDlg)
	DDX_Control(pDX, IDC_EDIT1, m_path);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDeleteFolderDlg, CDialog)
	//{{AFX_MSG_MAP(CDeleteFolderDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTDELETE, OnButdelete)
	ON_BN_CLICKED(IDC_BUTLIULAN, OnButliulan)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeleteFolderDlg message handlers

BOOL CDeleteFolderDlg::OnInitDialog()
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

void CDeleteFolderDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDeleteFolderDlg::OnPaint() 
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
HCURSOR CDeleteFolderDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDeleteFolderDlg::OnButdelete() 
{
	// TODO: Add your control notification handler code here
	CString str;
	m_path.GetWindowText(str);
	DelFolder(str);
	//目录为空时删除目录
	if(RemoveDirectory(str))
	{
		MessageBox("删除成功！");
		return;
	}
}

void CDeleteFolderDlg::DelFolder(CString path)
{
	CFileFind file;
	if(path.Right(1) != "\\")
		path +="\\*.*";
	BOOL bf;
	bf = file.FindFile(path);
	while(bf)
	{
		bf = file.FindNextFile();
		//是文件时直接删除
		if (!file.IsDots() && !file.IsDirectory())
			DeleteFile(file.GetFilePath());
		else if (file.IsDots())
			continue;
		else if (file.IsDirectory())
		{
			path = file.GetFilePath();
			//是目录时,继续递归调用函数删除该目录下的文件
			DelFolder(path);
			//目录为空后删除目录
			RemoveDirectory(path);
		}
	}
}

void CDeleteFolderDlg::OnButliulan() 
{
	// TODO: Add your control notification handler code here
	CString ReturnPach;
	TCHAR szPath[_MAX_PATH];
	BROWSEINFO bi;
	bi.hwndOwner=NULL;
	bi.pidlRoot=NULL;
	bi.lpszTitle=_T("请选择一个文件夹");
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
	m_path.SetWindowText(ReturnPach);
}
