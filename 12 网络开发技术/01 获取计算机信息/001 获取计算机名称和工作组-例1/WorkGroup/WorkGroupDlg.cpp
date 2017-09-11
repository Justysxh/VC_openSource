// WorkGroupDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WorkGroup.h"
#include "WorkGroupDlg.h"
#include "winnetwk.h"
#include "winsock2.h"
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
// CWorkGroupDlg dialog

CWorkGroupDlg::CWorkGroupDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWorkGroupDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWorkGroupDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWorkGroupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWorkGroupDlg)
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_LIST1, m_grid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWorkGroupDlg, CDialog)
	//{{AFX_MSG_MAP(CWorkGroupDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWorkGroupDlg message handlers

BOOL CWorkGroupDlg::OnInitDialog()
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
	m_grid.SetExtendedStyle(LVS_EX_FLATSB
		|LVS_EX_FULLROWSELECT
		|LVS_EX_HEADERDRAGDROP
		|LVS_EX_ONECLICKACTIVATE
		|LVS_EX_GRIDLINES);
	m_grid.InsertColumn(0,"局域网内工作组",LVCFMT_LEFT,220,0);
	DWORD nSize = MAX_COMPUTERNAME_LENGTH + 1;
	char Buffer[MAX_COMPUTERNAME_LENGTH + 1];
	GetComputerName(Buffer,&nSize);
	m_edit.SetWindowText(Buffer);
	DWORD Count=0xFFFFFFFF,Bufsize=4096,Res;
	NETRESOURCE* nRes; 
	NETRESOURCE* nRes1;
	HANDLE lphEnum;
	LPVOID Buf = new char[4096];
	LPVOID Bufwg = new char[4096];
	
	Res = WNetOpenEnum(RESOURCE_GLOBALNET, RESOURCETYPE_ANY, RESOURCEUSAGE_CONTAINER,NULL,&lphEnum);	
	Res=WNetEnumResource(lphEnum,&Count,Buf,&Bufsize);
	nRes=(NETRESOURCE*)Buf;
	for(DWORD n=0;n<Count;n++,nRes++)
	{
		DWORD NUM= 0xFFFFFFFF;
		Res = WNetOpenEnum(RESOURCE_GLOBALNET, RESOURCETYPE_ANY, 0,nRes,&lphEnum);
		Res=WNetEnumResource(lphEnum,&NUM,Bufwg,&Bufsize);
		int num= Bufsize/sizeof(NETRESOURCE);
		nRes1=(NETRESOURCE*)Bufwg;
		for(DWORD i=0;i<NUM;i++,nRes1++)
		{	
			m_grid.InsertItem(i,0);
			m_grid.SetItemText(i,0,nRes1->lpRemoteName);
		}
	}
	delete Buf;
	delete Bufwg;
	WNetCloseEnum(lphEnum);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWorkGroupDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWorkGroupDlg::OnPaint() 
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
HCURSOR CWorkGroupDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
