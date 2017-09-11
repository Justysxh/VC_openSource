// FileCopyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FileCopy.h"
#include "FileCopyDlg.h"

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
// CFileCopyDlg dialog

CFileCopyDlg::CFileCopyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileCopyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileCopyDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	readfile=NULL;
	writefile=NULL;
	pvData = NULL; 
}

void CFileCopyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileCopyDlg)
	DDX_Control(pDX, IDC_FILEPROCESSER, m_fileproc);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFileCopyDlg, CDialog)
	//{{AFX_MSG_MAP(CFileCopyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_PUT, OnPut)
	ON_BN_CLICKED(IDC_COPY, OnCopy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileCopyDlg message handlers

BOOL CFileCopyDlg::OnInitDialog()
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
	m_fileproc.SetRange(0,100);
	m_fileproc.SetPos(0);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFileCopyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFileCopyDlg::OnPaint() 
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
HCURSOR CFileCopyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFileCopyDlg::OnAdd() 
{
	CFileDialog log(TRUE,"文件","*.*",OFN_HIDEREADONLY,"FILE(*.*)|*.*||",NULL);
	if(log.DoModal()==IDOK)
	{
	pathname=log.GetPathName();
	strname=log.GetFileName();
	GetDlgItem(IDC_EDADD)->SetWindowText(pathname);
	}
}

void CFileCopyDlg::OnPut() 
{
	if(strname.IsEmpty())
		return;
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
	fullname=path;
	if(fullname.Right(1)!="\\")
	fullname.Format("%s\\%s",path,strname);
	else
	fullname.Format("%s%s",path,strname);
    GetDlgItem(IDC_EDDEST)->SetWindowText(fullname);
	}
}

void CFileCopyDlg::OnCopy() 
{

	if(pathname.IsEmpty())
		return;
	if(fullname.IsEmpty())
		return;
	readfile=new CFile(pathname,CFile::modeRead);
	HANDLE hfile=::CreateFile(fullname,GENERIC_WRITE|GENERIC_WRITE,0,0,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,0);
	CloseHandle(hfile);
	writefile=new CFile(fullname,CFile::modeWrite);
	filelen=readfile->GetLength();
	ldiv_t r;
	r=ldiv(filelen,100);
	long pos=r.quot;
	long ipos;
	ipos=pos;
	int i=0;
	hGlobal = GlobalAlloc(GMEM_MOVEABLE,512);
	pvData = GlobalLock(hGlobal);
	while(1){
	ZeroMemory(pvData,512);
	readlen=readfile->ReadHuge(pvData,512);
	poslen=readfile->GetPosition();
	if(poslen>ipos)
	{
		ipos+=pos;
		i++;
	}
	m_fileproc.SetPos(i);
	m_fileproc.Invalidate();
	writefile->WriteHuge(pvData,readlen);
	if(poslen==filelen)
			break;
	}
	AfxMessageBox("复制完成");
	m_fileproc.SetPos(0);
	GlobalUnlock(hGlobal);
	readfile->Close();
	writefile->Close();
}
