// INIRegDlg.cpp : implementation file
//

#include "stdafx.h"
#include "INIReg.h"
#include "INIRegDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
char machine[]="01234567";
char susrpart[128];
char susrid[128];
char sregcode[128];
char path[128];
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
// CINIRegDlg dialog

CINIRegDlg::CINIRegDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CINIRegDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CINIRegDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CINIRegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CINIRegDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CINIRegDlg, CDialog)
	//{{AFX_MSG_MAP(CINIRegDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTEXIT, OnExit)
	ON_BN_CLICKED(IDC_BTREG, OnReg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CINIRegDlg message handlers

BOOL CINIRegDlg::OnInitDialog()
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

	::GetCurrentDirectory(128,path);
	strcat(path,"\\reg.ini");
	CString temp;
	GetPrivateProfileString("Registration","userpart","",susrpart,128,path);
	GetPrivateProfileString("Registration","userid","",susrid,128,path);
	GetPrivateProfileString("Registration","regcode","",sregcode,128,path);
	temp.Format("%s",machine);
	if(temp==UnEncrypt(sregcode))
	SetWindowText("利用INI文件对软件进行注册");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CINIRegDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CINIRegDlg::OnPaint() 
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
HCURSOR CINIRegDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CINIRegDlg::OnExit() 
{
	this->OnCancel();	
}

void CINIRegDlg::OnReg() 
{
	CString struserpart,struserid,strregcode;
	GetDlgItem(IDC_EDPART)->GetWindowText(struserpart);
	GetDlgItem(IDC_EDUSR)->GetWindowText(struserid);
	GetDlgItem(IDC_EDREGCODE)->GetWindowText(strregcode);
	
	WritePrivateProfileString(_T(struserpart),_T(struserid),_T(strregcode),_T(path));
	CString temp;temp=machine;
	if(temp==UnEncrypt(strregcode.GetBuffer(0)))
	{
		AfxMessageBox("注册成功");
		SetWindowText("利用INI文件对软件进行注册");
	}
}

CString CINIRegDlg::UnEncrypt(char* strcode)
{

	CString temp;
	for(int i=0;i<8;i++)
	{
		strcode[i]=strcode[i]^1123;	
	}
	temp=strcode;
	return temp;
}