// RenameFileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RenameFile.h"
#include "RenameFileDlg.h"

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
// CRenameFileDlg dialog

CRenameFileDlg::CRenameFileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRenameFileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRenameFileDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRenameFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRenameFileDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRenameFileDlg, CDialog)
	//{{AFX_MSG_MAP(CRenameFileDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTPATHADD, OnPathAdd)
	ON_BN_CLICKED(IDC_BTNAMEADD, OnNameAdd)
	ON_BN_CLICKED(IDC_BTPATHSET, OnPathSet)
	ON_BN_CLICKED(IDC_BTNAMESET, OnNameSet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRenameFileDlg message handlers

BOOL CRenameFileDlg::OnInitDialog()
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

void CRenameFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRenameFileDlg::OnPaint() 
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
HCURSOR CRenameFileDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRenameFileDlg::OnPathAdd() 
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
	pathofpath=strpathname=path;
	CString pathname,temp;
	pathname=path;
	int pos=pathname.Find("\\");
	while(pos>0)
	{
		//temp=pathname;
		pathname=pathname.Right(pathname.GetLength()-1-pos);
		pos=pathname.Find("\\");
	}
	GetDlgItem(IDC_EDPATHNAME)->SetWindowText(pathname);
	pathofpath=pathofpath.Left(pathofpath.GetLength()-pathname.GetLength());
	}
	
}

void CRenameFileDlg::OnNameAdd() 
{
	CFileDialog log(TRUE,"文件","*.*",OFN_HIDEREADONLY|
		OFN_ALLOWMULTISELECT,"FILE(*.*)|*.*||",NULL);
	if(log.DoModal()==IDOK)
	{
		strfilename=log.GetPathName();
		CString filename=log.GetFileName();
		GetDlgItem(IDC_EDNAME)->SetWindowText(filename);
	}
}

void CRenameFileDlg::OnPathSet() 
{
	if(strpathname.IsEmpty())
		return;
	CString edpathname;
	GetDlgItem(IDC_EDPATHNAMESET)->GetWindowText(edpathname);
	if(edpathname.IsEmpty())
		return;
	pathofpath+=edpathname;
	if(::MoveFile(strpathname,pathofpath))
		AfxMessageBox("修改成功");
}

void CRenameFileDlg::OnNameSet() 
{
	if(strfilename.IsEmpty())
		return;
	CString stredfilename;
	GetDlgItem(IDC_EDNAMESET)->GetWindowText(stredfilename);
	if(stredfilename.IsEmpty())
		return;
	CString temp,strtemp;strtemp=temp=strfilename;
	int pos=temp.Find("\\");
	while(pos>0)
	{
		temp=temp.Right(temp.GetLength()-1-pos);
		pos=temp.Find("\\");
	}
	strtemp=strtemp.Left(strtemp.GetLength()-temp.GetLength());
	strtemp+=stredfilename;
	CFile::Rename(strfilename,strtemp);
	AfxMessageBox("修改成功");
}
