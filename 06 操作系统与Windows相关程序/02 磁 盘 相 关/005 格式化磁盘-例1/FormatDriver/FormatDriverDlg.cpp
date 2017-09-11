// FormatDriverDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FormatDriver.h"
#include "FormatDriverDlg.h"
#include "winbase.h"

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
// CFormatDriverDlg dialog

CFormatDriverDlg::CFormatDriverDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFormatDriverDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFormatDriverDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFormatDriverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFormatDriverDlg)
	DDX_Control(pDX, IDC_DRIVER, m_driver);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFormatDriverDlg, CDialog)
	//{{AFX_MSG_MAP(CFormatDriverDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTFORMAT, OnFormat)
	ON_CBN_SELCHANGE(IDC_DRIVER, OnSelchangeDriver)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFormatDriverDlg message handlers

BOOL CFormatDriverDlg::OnInitDialog()
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
	
	size_t alldriver=::GetLogicalDriveStrings(0,NULL);
	_TCHAR *driverstr;
	driverstr=new _TCHAR[alldriver+sizeof(_T(""))];
	if(GetLogicalDriveStrings(alldriver,driverstr)!=alldriver-1)
		return FALSE;
	_TCHAR *pdriverstr=driverstr;
	size_t driversize=strlen(pdriverstr);
	while(driversize>0)
	{
		m_driver.AddString(pdriverstr);
		pdriverstr+=driversize+1;
		driversize=strlen(pdriverstr);
	}
	isel=0;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFormatDriverDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFormatDriverDlg::OnPaint() 
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
HCURSOR CFormatDriverDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFormatDriverDlg::OnFormat() 
{
	
	typedef DWORD (WINAPI *MyFunc)(HWND hwnd, 
	UINT drive,UINT fmtID,UINT options);
	HMODULE hModule=::LoadLibrary("shell32.dll");
	if(hModule)
	{
		MyFunc FormatDriver= (MyFunc) GetProcAddress(hModule, "SHFormatDrive");
		if(FormatDriver)
			FormatDriver(this->GetSafeHwnd(),isel,0xFFFF,0);
	}
	
	//keybd_event(VK_RETURN,NULL,NULL,NULL); //模拟按回车键
	
}

void CFormatDriverDlg::OnSelchangeDriver() 
{
	CString strtemp;
	int i=m_driver.GetCurSel();
	m_driver.GetLBText(i,strtemp);
	char *chr;
	chr=new char[1];
	CString str;str=strtemp.Left(1);
	chr=str.GetBuffer(0);
	char ch=chr[0];
	isel=ch-'A';
}
