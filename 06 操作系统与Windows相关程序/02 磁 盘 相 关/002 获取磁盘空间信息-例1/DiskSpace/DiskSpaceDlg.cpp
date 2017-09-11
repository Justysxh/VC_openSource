// DiskSpaceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DiskSpace.h"
#include "DiskSpaceDlg.h"

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
// CDiskSpaceDlg dialog

CDiskSpaceDlg::CDiskSpaceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDiskSpaceDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDiskSpaceDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDiskSpaceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDiskSpaceDlg)
	DDX_Control(pDX, IDC_DISKLIST, m_disklist);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDiskSpaceDlg, CDialog)
	//{{AFX_MSG_MAP(CDiskSpaceDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiskSpaceDlg message handlers

BOOL CDiskSpaceDlg::OnInitDialog()
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
	
	m_disklist.SetExtendedStyle(LVS_EX_GRIDLINES);
	m_disklist.InsertColumn(0,"´ÅÅÌÇý¶¯Æ÷",LVCFMT_LEFT,150);
	m_disklist.InsertColumn(1,"Çý¶¯Æ÷´óÐ¡",LVCFMT_LEFT,150);
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
		while(*lp!=0)
		{
			m_disklist.InsertItem(0,lp,0);
			lp=_tcschr(lp,0)+1;
		}
	}
	ULARGE_INTEGER totalsize;
	ULARGE_INTEGER freesize;
	ULARGE_INTEGER availablesize;
	int num=m_disklist.GetItemCount();
	for(int i=0;i<num;i++)
	{
		CString str,temp;
		str=m_disklist.GetItemText(i,0);
		::GetDiskFreeSpaceEx(str,&totalsize,&freesize,&availablesize);
		temp.Format("%ldÇ§×Ö½Ú",totalsize.QuadPart/1024);
		m_disklist.SetItemText(i,1,temp);
	}
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDiskSpaceDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDiskSpaceDlg::OnPaint() 
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
HCURSOR CDiskSpaceDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
