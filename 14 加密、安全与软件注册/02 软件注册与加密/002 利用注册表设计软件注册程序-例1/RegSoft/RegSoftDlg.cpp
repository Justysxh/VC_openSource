// RegSoftDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RegSoft.h"
#include "RegSoftDlg.h"

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
// CRegSoftDlg dialog

CRegSoftDlg::CRegSoftDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRegSoftDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegSoftDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRegSoftDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegSoftDlg)
	DDX_Control(pDX, IDC_SPARE, m_spare);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRegSoftDlg, CDialog)
	//{{AFX_MSG_MAP(CRegSoftDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTSET, OnSet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegSoftDlg message handlers

BOOL CRegSoftDlg::OnInitDialog()
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
	
	HKEY Key;
	CString sKeyPath;

	sKeyPath="Software\\mingrisoft";
	if(RegOpenKey(HKEY_CURRENT_USER,sKeyPath,&Key)==2)
	{
		//在注册表中记录已试用的次数
		::RegCreateKey(HKEY_CURRENT_USER,sKeyPath,&Key);
		::RegSetValueEx(Key,"TryTime",0,REG_SZ,(unsigned char*)"5",2);
		::RegCloseKey(Key);
		m_spare.SetWindowText("您还可以使用5次");
	}
	else //已经存在注册信息
	{
		CString sTryTime;
		int nTryTime;
		LPBYTE Data=new BYTE[80];
		DWORD TYPE=REG_SZ;
		DWORD cbData=80;
		//取出已记载的数量
		::RegQueryValueEx(Key,"TryTime",0,&TYPE,Data,&cbData);
		sTryTime.Format("%s",Data);
		nTryTime=atoi(sTryTime);
		if(nTryTime<1)
		{
			MessageBox("您的最大试用次数已过，只有注册后才允许继续使用！",
			"系统提示",MB_OK|MB_ICONSTOP);

			return FALSE;
		}
		nTryTime--;
		sTryTime.Format("%d",nTryTime);
		::RegSetValueEx(Key,"TryTime",0,REG_SZ,(unsigned char*)sTryTime.GetBuffer(0),2);
		::RegCloseKey(Key);	
		CString temp;
		temp.Format("您还可以使用%d次",nTryTime);
		m_spare.SetWindowText(temp);
	}	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRegSoftDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRegSoftDlg::OnPaint() 
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
HCURSOR CRegSoftDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRegSoftDlg::OnSet() 
{
	HKEY Key;
	CString str;
	CString sKeyPath;
	sKeyPath="Software\\mingrisoft";
	GetDlgItem(IDC_EDSET)->GetWindowText(str);
	::RegCreateKey(HKEY_CURRENT_USER,sKeyPath,&Key);
	::RegSetValueEx(Key,"TryTime",0,REG_SZ,(unsigned char*)str.GetBuffer(0),str.GetLength());
	::RegCloseKey(Key);
	MessageBox("设置成功","系统提示",MB_OK|MB_ICONSTOP);
	GetDlgItem(IDC_EDSET)->SetWindowText("");
}
