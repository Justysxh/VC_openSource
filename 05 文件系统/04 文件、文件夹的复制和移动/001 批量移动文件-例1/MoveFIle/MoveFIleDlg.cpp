// MoveFIleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MoveFIle.h"
#include "MoveFIleDlg.h"

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
// CMoveFIleDlg dialog

CMoveFIleDlg::CMoveFIleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMoveFIleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMoveFIleDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMoveFIleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMoveFIleDlg)
	DDX_Control(pDX, IDC_FILELST, m_filelist);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMoveFIleDlg, CDialog)
	//{{AFX_MSG_MAP(CMoveFIleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTADDFILE, OnAddFile)
	ON_BN_CLICKED(IDC_BTMOVE, OnMove)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMoveFIleDlg message handlers

BOOL CMoveFIleDlg::OnInitDialog()
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
	
	m_filelist.SetExtendedStyle(LVS_EX_GRIDLINES);
	m_filelist.InsertColumn(0,"文件",LVCFMT_LEFT,450);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMoveFIleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMoveFIleDlg::OnPaint() 
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
HCURSOR CMoveFIleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMoveFIleDlg::OnAddFile() 
{
	CFileDialog log(TRUE,"文件","*.*",OFN_HIDEREADONLY|
		OFN_ALLOWMULTISELECT,"FILE(*.*)|*.*||",NULL);
	if(log.DoModal()==IDOK)
	{
		POSITION pos = log.GetStartPosition();
        while(pos != NULL)
        {
		CString pathname= log.GetNextPathName(pos);
		//pathname=log.GetPathName();
		m_filelist.InsertItem(m_filelist.GetItemCount(),pathname);
		}
	}
}

void CMoveFIleDlg::OnMove() 
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

	for(int i=0;i<m_filelist.GetItemCount();i++)
	{
		CString pathtemp;
		pathtemp.Format("%s\\%s",path,GetNameFromPath(m_filelist.GetItemText(i,0)));
		::MoveFile(m_filelist.GetItemText(i,0),pathtemp);
	}
	AfxMessageBox("移动文件完成");
	}
	
	
}
CString CMoveFIleDlg::GetNameFromPath(CString path)
{	
	CString strright;

	int pos=path.Find("\\");
	while(pos>0)
	{
		path=path.Right(path.GetLength()-1-pos);
		pos=path.Find("\\");
	}

	return path;
}
