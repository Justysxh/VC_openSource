// FileRelatDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FileRelat.h"
#include "FileRelatDlg.h"

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
// CFileRelatDlg dialog

CFileRelatDlg::CFileRelatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileRelatDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileRelatDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileRelatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileRelatDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFileRelatDlg, CDialog)
	//{{AFX_MSG_MAP(CFileRelatDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADDICON, OnAddicon)
	ON_BN_CLICKED(IDC_REL, OnRel)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileRelatDlg message handlers

BOOL CFileRelatDlg::OnInitDialog()
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
	
	GetDlgItem(IDC_EDSHELL)->SetWindowText("open");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFileRelatDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFileRelatDlg::OnPaint() 
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
HCURSOR CFileRelatDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CFileRelatDlg::OnAddicon() 
{
	CFileDialog file(NULL,"ico",NULL,OFN_HIDEREADONLY,"ICON文件(*.ico)|*.ico||",this);
	if(file.DoModal()==IDOK)
	{
		strname=file.GetPathName();
		GetDlgItem(IDC_EDICON)->SetWindowText(strname);
	}	
}

void CFileRelatDlg::OnRel() 
{
	CString stricon,strextname,strvalue,strscri,strshell,strcommand,strprint;
	GetDlgItem(IDC_EDNAME)->GetWindowText(strextname);
	GetDlgItem(IDC_EDVALUE)->GetWindowText(strvalue);
	GetDlgItem(IDC_EDSCRI)->GetWindowText(strscri);
	GetDlgItem(IDC_EDSHELL)->GetWindowText(strshell);
	GetDlgItem(IDC_EDCOMMAND)->GetWindowText(strcommand);
	GetDlgItem(IDC_EDPRINT)->GetWindowText(strprint);
	GetDlgItem(IDC_EDICON)->GetWindowText(stricon);
	DWORD c=1;
	HKEY sub;
	CString skey=strextname;
	//建立扩展名
	::RegCreateKey(HKEY_CLASSES_ROOT,skey,&sub);
	//设置扩展名的默认值
	::RegSetValue(sub,NULL,REG_SZ,strvalue,strvalue.GetLength());
	//创建默认值
	::RegCreateKey(HKEY_CLASSES_ROOT,strvalue,&sub);
	::RegSetValue(sub,NULL,REG_SZ,strscri,strscri.GetLength());
	//创建DefaultIcon子项
	skey.Format("%s\\DefaultIcon",strvalue);
	::RegCreateKey(HKEY_CLASSES_ROOT,skey,&sub);
	::RegSetValueEx(sub,NULL,NULL,REG_EXPAND_SZ,(BYTE*)stricon.GetBuffer(0),
		stricon.GetLength());
	//创建shell子项
	skey.Format("%s\\shell",strvalue);
	::RegCreateKey(HKEY_CLASSES_ROOT,skey,&sub);
	//创建shell\open子项
	skey.Format("%s\\shell\\%s",strvalue,strshell);
	::RegCreateKey(HKEY_CLASSES_ROOT,skey,&sub);
	//创建shell\open\command子项
	skey.Format("%s\\shell\\%s\\command",strvalue,strshell);
	::RegCreateKey(HKEY_CLASSES_ROOT,skey,&sub);
	::RegSetValueEx(sub,NULL,NULL,REG_EXPAND_SZ,(BYTE*)strcommand.GetBuffer(0),
		strcommand.GetLength());
	//创建shell\print\command子项
	skey.Format("%s\\shell\\print\\command",strvalue);
	::RegCreateKey(HKEY_CLASSES_ROOT,skey,&sub);
	::RegSetValueEx(sub,NULL,NULL,REG_EXPAND_SZ,(BYTE*)strprint.GetBuffer(0),
		strprint.GetLength());
	RegCloseKey(sub);
}

void CFileRelatDlg::OnExit() 
{
	this->OnCancel();
}
