// FtpUpLoadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FtpUpLoad.h"
#include "FtpUpLoadDlg.h"

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
// CFtpUpLoadDlg dialog

CFtpUpLoadDlg::CFtpUpLoadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFtpUpLoadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFtpUpLoadDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFtpUpLoadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFtpUpLoadDlg)
	DDX_Control(pDX, IDC_FTPFILELST, m_ftpfilelst);
	DDX_Control(pDX, IDC_NONAME, m_noname);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFtpUpLoadDlg, CDialog)
	//{{AFX_MSG_MAP(CFtpUpLoadDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTCONN, OnConnect)
	ON_BN_CLICKED(IDC_BTUPLOAD, OnUPLoad)
	ON_BN_CLICKED(IDC_NONAME, OnNoname)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFtpUpLoadDlg message handlers

BOOL CFtpUpLoadDlg::OnInitDialog()
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
	bconnect=FALSE;
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFtpUpLoadDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFtpUpLoadDlg::OnPaint() 
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
HCURSOR CFtpUpLoadDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFtpUpLoadDlg::OnConnect() 
{
	GetDlgItem(IDC_EDIP)->GetWindowText(strip);
	GetDlgItem(IDC_EDPORT)->GetWindowText(strport);
	GetDlgItem(IDC_EDUSR)->GetWindowText(strusr);
	GetDlgItem(IDC_EDPWD)->GetWindowText(strpwd);
	if(strip.IsEmpty())
		return;	
	if(strport.IsEmpty())
		return;
	if(strusr.IsEmpty())
		return;
	pInternetSession = new CInternetSession("MR",
		INTERNET_OPEN_TYPE_PRECONFIG);
	try{
	pFtpConnection = pInternetSession->GetFtpConnection(strip,
		strusr,strpwd,atoi(strport));
	bconnect=TRUE;
	}catch(CInternetException* pEx)
	{
		TCHAR szErr[1024];
		pEx->GetErrorMessage(szErr, 1024);
		AfxMessageBox(szErr);
		pEx->Delete();
	}
	m_ftpfilelst.ResetContent();
	CFtpFileFind ftpfind(pFtpConnection);
	BOOL bfind=ftpfind.FindFile(NULL);
	while(bfind)
	{
		
		bfind=ftpfind.FindNextFile();
		CString strpath=ftpfind.GetFileURL();
		m_ftpfilelst.AddString(strpath);
	}

}

void CFtpUpLoadDlg::OnUPLoad() 
{
	CString str;
	CString strname;
	CFileDialog file(true,"file",NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"所有文件|*.*||",this);
	if(file.DoModal()==IDOK)
	{
		str=file.GetPathName();
		strname=file.GetFileName();
	}
	if(bconnect)
	{
		BOOL bput=pFtpConnection->PutFile((LPCTSTR)str,(LPCTSTR)strname);
		if(bput){
			m_ftpfilelst.ResetContent();
			this->OnConnect();
			AfxMessageBox("上传成功");
		}
	}
}

void CFtpUpLoadDlg::OnNoname() 
{
	int icheck=m_noname.GetCheck();
	if(icheck==1)
	{
		GetDlgItem(IDC_EDUSR)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDPWD)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDUSR)->SetWindowText("anonymous");
		GetDlgItem(IDC_EDPWD)->SetWindowText("");
	}else
	{
		GetDlgItem(IDC_EDUSR)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDPWD)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDUSR)->SetWindowText("");
		GetDlgItem(IDC_EDUSR)->SetWindowText("");
	}
}
