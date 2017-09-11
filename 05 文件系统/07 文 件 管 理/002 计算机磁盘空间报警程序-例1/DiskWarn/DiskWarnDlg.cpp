// DiskWarnDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DiskWarn.h"
#include "DiskWarnDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define WM_ONTRAY WM_USER+1104
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
// CDiskWarnDlg dialog

CDiskWarnDlg::CDiskWarnDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDiskWarnDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDiskWarnDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDiskWarnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDiskWarnDlg)
	DDX_Control(pDX, IDC_CMBSPACE, m_space);
	DDX_Control(pDX, IDC_DISKLIST, m_disklist);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDiskWarnDlg, CDialog)
	//{{AFX_MSG_MAP(CDiskWarnDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTSET, OnSet)
	ON_MESSAGE(WM_ONTRAY,OnTray)
	ON_BN_CLICKED(IDC_BTEXIT, OnExit)
	ON_CBN_SELCHANGE(IDC_CMBSPACE, OnSelchangeCmbspace)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiskWarnDlg message handlers

BOOL CDiskWarnDlg::OnInitDialog()
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
	
	NOTIFYICONDATA data;
	data.hWnd=m_hWnd;
	data.uCallbackMessage=WM_ONTRAY;
	data.uFlags=NIF_MESSAGE|NIF_ICON;
	data.hIcon=m_hIcon;
	data.uID=IDR_MAINFRAME;
	Shell_NotifyIcon(NIM_ADD,&data);

	m_disklist.SetExtendedStyle(LVS_EX_GRIDLINES);
	m_disklist.InsertColumn(0,"磁盘驱动器",LVCFMT_LEFT,150);
	m_disklist.InsertColumn(1,"驱动器大小",LVCFMT_LEFT,150);
	m_disklist.InsertColumn(2,"可用空间",LVCFMT_LEFT,150);
	imglist.Create(16,16,ILC_COLOR32|ILC_MASK,0,0);
	imglist.Add(::AfxGetApp()->LoadIcon(IDI_DISK));
	m_disklist.SetImageList(&imglist,LVSIL_SMALL);
	DWORD size;
	size=::GetLogicalDriveStrings(0,NULL);
	if(size!=0)
	{
		HANDLE heap=::GetProcessHeap();
		LPSTR lp=(LPSTR)HeapAlloc(heap,HEAP_ZERO_MEMORY,size*sizeof(TCHAR));
		::GetLogicalDriveStrings(size*sizeof(TCHAR),lp);
		int i=0;
		while(*lp!=0)
		{
			m_disklist.InsertItem(i,lp,0);
			m_space.AddString(lp);
			lp=_tcschr(lp,0)+1;
			i++;
		}
	}

	int num=m_disklist.GetItemCount();
	for(int i=0;i<num;i++)
	{
		CString str,temp;
		str=m_disklist.GetItemText(i,0);
		::GetDiskFreeSpaceEx(str,&freesize,&totalsize,&availablesize);
		temp.Format("%ldM",totalsize.QuadPart/1048576);
		m_disklist.SetItemText(i,1,temp);
		temp.Format("%ldM",freesize.QuadPart/1048576);
		m_disklist.SetItemText(i,2,temp);
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDiskWarnDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	//if ((nID & 0xFFF0) == IDM_ABOUTBOX)
//	{
	//	CAboutDlg dlgAbout;
	//	dlgAbout.DoModal();
	//}
	if(nID==SC_CLOSE)
	{
		ShowWindow(SW_HIDE);
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDiskWarnDlg::OnPaint() 
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
HCURSOR CDiskWarnDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CDiskWarnDlg::OnTray(WPARAM wParam,LPARAM lParam)
{
	UINT msg=UINT(lParam);
	if(msg==WM_LBUTTONDBLCLK)
	{
		this->ShowWindow(SW_SHOWNOACTIVATE);
	}
}
void CDiskWarnDlg::OnSet() 
{
	GetDlgItem(IDC_EDSPACE)->GetWindowText(strwarn);
	strfreespace=m_disklist.GetItemText(sel,2);
	if(atoi(strfreespace)<atoi(strwarn))
	{
		AfxMessageBox("设置无效");
		return;
	}
	SetTimer(1,1000,NULL);
	GetDlgItem(IDC_BTSET)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDSPACE)->EnableWindow(FALSE);
	GetDlgItem(IDC_CMBSPACE)->EnableWindow(FALSE);
	ShowWindow(SW_HIDE);
}

BOOL CDiskWarnDlg::DestroyWindow() 
{
	NOTIFYICONDATA data;
	data.cbSize=sizeof(NOTIFYICONDATA);
	data.hWnd=m_hWnd;
	data.uID=IDR_MAINFRAME;
	Shell_NotifyIcon(NIM_DELETE,&data);
	KillTimer(1);
	return CDialog::DestroyWindow();
}

void CDiskWarnDlg::OnExit() 
{
	this->OnCancel();	
}

void CDiskWarnDlg::OnSelchangeCmbspace() 
{
	sel=m_space.GetCurSel();
}

void CDiskWarnDlg::OnTimer(UINT nIDEvent) 
{
	ULARGE_INTEGER availablesize;
	int num=m_disklist.GetItemCount();
	for(int i=0;i<num;i++)
	{
		CString str,temp;
		str=m_disklist.GetItemText(i,0);
		::GetDiskFreeSpaceEx(str,&freesize,&totalsize,&availablesize);
		temp.Format("%ldM",freesize.QuadPart/1048576);
		m_disklist.SetItemText(i,2,temp);
	}
	Invalidate();
	GetDlgItem(IDC_EDSPACE)->GetWindowText(strwarn);
	strfreespace=m_disklist.GetItemText(sel,2);
	if(atoi(strfreespace)<atoi(strwarn))
	{
		AfxMessageBox("磁盘空间已超出设置");
		KillTimer(1);
	}
	CDialog::OnTimer(nIDEvent);
}
