// FileEncryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FileEncry.h"
#include "FileEncryDlg.h"

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
// CFileEncryDlg dialog

CFileEncryDlg::CFileEncryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileEncryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileEncryDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileEncryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileEncryDlg)
	DDX_Control(pDX, IDC_FILEPATH, m_filepath);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFileEncryDlg, CDialog)
	//{{AFX_MSG_MAP(CFileEncryDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTOPEN, OnOpen)
	ON_BN_CLICKED(IDC_BTENCRY, OnEncry)
	ON_BN_CLICKED(IDC_BTUNENCRY, OnUnEncry)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileEncryDlg message handlers

BOOL CFileEncryDlg::OnInitDialog()
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

void CFileEncryDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFileEncryDlg::OnPaint() 
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
HCURSOR CFileEncryDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFileEncryDlg::OnOpen() 
{
	CFileDialog log(TRUE,"文件",NULL,OFN_HIDEREADONLY,"FILE(*.txt)|*.txt||",NULL);
	if(log.DoModal()==IDOK)
	{
	CString tmp,str,path;
	path=log.GetPathName();
	strpathtemp=log.GetFileName();
	int pos=path.Find(strpathtemp);
	strpathtemp=path.Left(pos);
	CStdioFile file;
	try{
	int i=file.Open(path,CFile::modeRead);
	if(i==0)
		return;
	}catch(CFileException *e)
	{
		TCHAR szBuf[256]; 
		e->GetErrorMessage(szBuf,256,NULL);
		MessageBox(szBuf,_T("Warning"));
		e->Delete();
	}
	while(1)
	{
	DWORD i=file.ReadString(str);
	if(i==0)goto end;
	tmp+=str;
	tmp+="\r\n";
	}
	end:
	GetDlgItem(IDC_EDBODY)->SetWindowText(tmp);
	m_filepath.SetWindowText(path);
	}
}

void CFileEncryDlg::OnEncry() 
{
	CString path,desname;
	m_filepath.GetWindowText(path);
	if(path.IsEmpty())return;
	desname.Format("%smingrisofttemp.txt",strpathtemp);
	HANDLE handle=::CreateFile(desname,GENERIC_WRITE,FILE_SHARE_WRITE,0,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,NULL);
	if(handle)::CloseHandle(handle);
	CFile readfile,writefile;
	int i=readfile.Open(path,CFile::modeRead);
	writefile.Open(desname,CFile::modeCreate|CFile::modeReadWrite);
	if(i==0)return;
	char buf[128];
	char desbuf[128];
	while(1)
	{
	ZeroMemory(buf,128);
	ZeroMemory(desbuf,128);
	DWORD i=readfile.Read(buf,128);
	for(int p=0;p<i;p++)
	{
		char m=buf[p];
		desbuf[p]=m^2;
	}
	writefile.Write(desbuf,i);
	if(i==0)goto end;
	}
	end:
	readfile.Close();
	writefile.Close();
	::DeleteFile(path);
	::rename(desname,path);
	AfxMessageBox("加密完成");
	
}

void CFileEncryDlg::OnUnEncry() 
{
	CString path,desname;
	m_filepath.GetWindowText(path);
	if(path.IsEmpty())return;
	desname.Format("%smingrisofttemp.txt",strpathtemp);
	HANDLE handle=::CreateFile(desname,GENERIC_WRITE,FILE_SHARE_WRITE,0,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,NULL);
	if(handle)::CloseHandle(handle);
	CFile readfile,writefile;
	int i=readfile.Open(path,CFile::modeRead);
	writefile.Open(desname,CFile::modeCreate|CFile::modeReadWrite);
	if(i==0)return;
	char buf[128];
	char desbuf[128];
	while(1)
	{
	ZeroMemory(buf,128);
	ZeroMemory(desbuf,128);
	DWORD i=readfile.Read(buf,128);
	for(int p=0;p<i;p++)
	{
		char m=buf[p];
		desbuf[p]=m^2;
	}
	writefile.Write(desbuf,i);
	if(i==0)goto end;
	}
	end:
	readfile.Close();
	writefile.Close();
	::DeleteFile(path);
	::rename(desname,path);
	AfxMessageBox("解密完成");
}
