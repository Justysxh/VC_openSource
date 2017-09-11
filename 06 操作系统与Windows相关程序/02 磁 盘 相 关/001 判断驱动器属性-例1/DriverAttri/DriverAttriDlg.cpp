// DriverAttriDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DriverAttri.h"
#include "DriverAttriDlg.h"
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
// CDriverAttriDlg dialog

CDriverAttriDlg::CDriverAttriDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDriverAttriDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDriverAttriDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDriverAttriDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDriverAttriDlg)
	DDX_Control(pDX, IDC_TYPE, m_type);
	DDX_Control(pDX, IDC_DRIVERCOMB, m_drivercomb);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDriverAttriDlg, CDialog)
	//{{AFX_MSG_MAP(CDriverAttriDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_DRIVERCOMB, OnSelchangeDrivercomb)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDriverAttriDlg message handlers

BOOL CDriverAttriDlg::OnInitDialog()
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
	/*
	DWORD size;
	size=::GetLogicalDriveStrings(0,NULL);
	if(size!=0)
	{
		HANDLE heap=::GetProcessHeap();
		LPSTR lp=(LPSTR)HeapAlloc(heap,HEAP_ZERO_MEMORY,size*sizeof(TCHAR));
		::GetLogicalDriveStrings(size*sizeof(TCHAR),lp);
		while(*lp!=0)
		{
		m_drivercomb.AddString(lp);
		lp=_tcschr(lp,0)+1;
		}
	}
	*/
	size_t alldriver=::GetLogicalDriveStrings(0,NULL);
	_TCHAR *driverstr;
	driverstr=new _TCHAR[alldriver+sizeof(_T(""))];
	if(GetLogicalDriveStrings(alldriver,driverstr)!=alldriver-1)
		return FALSE;
	_TCHAR *pdriverstr=driverstr;
	size_t driversize=strlen(pdriverstr);
	while(driversize>0)
	{
		m_drivercomb.AddString(pdriverstr);
		pdriverstr+=driversize+1;
		driversize=strlen(pdriverstr);
	}
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDriverAttriDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDriverAttriDlg::OnPaint() 
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
HCURSOR CDriverAttriDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDriverAttriDlg::OnSelchangeDrivercomb() 
{
	CString itemstr;
	int icursel=m_drivercomb.GetCurSel();
	m_drivercomb.GetLBText(icursel,itemstr);
	switch(::GetDriveType(itemstr))
	{
	case 2:
		m_type.SetWindowText("ÈíÇý");
		break;
	case 3:
		m_type.SetWindowText("¹Ì¶¨Ó²ÅÌ");
		break;
	case 5:
		m_type.SetWindowText("¹âÇý");
		break;
	case 4:
		m_type.SetWindowText("ÍøÂçÇý¶¯Æ÷");
		break;
	case 6:
		m_type.SetWindowText("RAM");
		break;
	default:
		m_type.SetWindowText("Î´Öª");
		break;
	}
}
