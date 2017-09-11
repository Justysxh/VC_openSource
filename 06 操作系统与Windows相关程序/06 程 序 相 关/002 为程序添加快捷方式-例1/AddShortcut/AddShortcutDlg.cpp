// AddShortcutDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AddShortcut.h"
#include "AddShortcutDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "objidl.h"
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
// CAddShortcutDlg dialog

CAddShortcutDlg::CAddShortcutDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddShortcutDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddShortcutDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAddShortcutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddShortcutDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAddShortcutDlg, CDialog)
	//{{AFX_MSG_MAP(CAddShortcutDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DESKTOP, OnDesktop)
	ON_BN_CLICKED(IDC_GROUP, OnGroup)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddShortcutDlg message handlers

BOOL CAddShortcutDlg::OnInitDialog()
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
	
	::CoInitialize(NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAddShortcutDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAddShortcutDlg::OnPaint() 
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
HCURSOR CAddShortcutDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAddShortcutDlg::OnAdd() 
{
CFileDialog log(FALSE,"可执行文件","*.EXE",OFN_HIDEREADONLY,"可执行程序|*.exe||",NULL);
	if(log.DoModal()==IDOK)
	{
	pathname=log.GetPathName();
	strname=log.GetFileName();
	GetDlgItem(IDC_EDADD)->SetWindowText(pathname);
	}	
}

void CAddShortcutDlg::OnDesktop() 
{
	if(strname.IsEmpty())return;
	IShellLink *link;
	IPersistFile *file;
	HRESULT res=::CoCreateInstance(CLSID_ShellLink,NULL,
        CLSCTX_INPROC_SERVER,IID_IShellLink,(void **)&link);
	if(FAILED(res))
        return;
	link->SetPath(pathname);
	res=link->QueryInterface(IID_IPersistFile,(void**)&file);
	if(FAILED(res))
        return;
	WORD wsz[MAX_PATH];
	CString linkname;
	LPITEMIDLIST pid;
	char path[MAX_PATH];
	::SHGetSpecialFolderLocation(NULL,CSIDL_DESKTOP,&pid);
	::SHGetPathFromIDList(pid,path);

	CString name;
	int pos=strname.Find(".");
	name=strname.Left(pos);
	linkname.Format("%s\\%s.lnk",path,name);
	MultiByteToWideChar(CP_ACP,0,linkname,-1,wsz,MAX_PATH);
	file->Save(wsz,STGM_READWRITE);
	file->Release();
	link->Release();
	::SHChangeNotify(SHCNE_CREATE|SHCNE_INTERRUPT,SHCNF_FLUSH|SHCNF_PATH,linkname,0);
	::SHChangeNotify(SHCNE_UPDATEDIR|SHCNE_INTERRUPT, 
            SHCNF_FLUSH|SHCNF_PATH,path,0);
}
void CAddShortcutDlg::OnGroup() 
{
	if(strname.IsEmpty())return;
	IShellLink *link;
	IPersistFile *file;
	HRESULT res=::CoCreateInstance(CLSID_ShellLink,NULL,
        CLSCTX_INPROC_SERVER,IID_IShellLink,(void **)&link);
	if(FAILED(res))
        return;
	link->SetPath(pathname);
	res=link->QueryInterface(IID_IPersistFile,(void**)&file);
	if(FAILED(res))
        return;
	WORD wsz[MAX_PATH];
	CString linkname;
	LPITEMIDLIST pid;
	char path[MAX_PATH];
	::SHGetSpecialFolderLocation(NULL,CSIDL_PROGRAMS,&pid);
	::SHGetPathFromIDList(pid,path);

	CString name;
	int pos=strname.Find(".");
	name=strname.Left(pos);
	linkname.Format("%s\\%s.lnk",path,name);
	MultiByteToWideChar(CP_ACP,0,linkname,-1,wsz,MAX_PATH);
	file->Save(wsz,STGM_READWRITE);
	file->Release();
	link->Release();
	::SHChangeNotify(SHCNE_CREATE|SHCNE_INTERRUPT,SHCNF_FLUSH|SHCNF_PATH,linkname,0);
	::SHChangeNotify(SHCNE_UPDATEDIR|SHCNE_INTERRUPT, 
            SHCNF_FLUSH|SHCNF_PATH,path,0);
}
