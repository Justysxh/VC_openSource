// ResShareDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ResShare.h"
#include "ResShareDlg.h"
//#include "winnetwk.h"
//#include "afxsock.h"
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
// CResShareDlg dialog

CResShareDlg::CResShareDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CResShareDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CResShareDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CResShareDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CResShareDlg)
	DDX_Control(pDX, IDC_TREE1, m_Tree);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CResShareDlg, CDialog)
	//{{AFX_MSG_MAP(CResShareDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResShareDlg message handlers

BOOL CResShareDlg::OnInitDialog()
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
//	WSADATA wsd;
//	WSAStartup(MAKEWORD(2,2),&wsd);
	
	m_imagelist.Create(16,16,ILC_COLOR24|ILC_MASK,0,0);
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON3));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON4));
	HICON hIcon=::LoadIcon(AfxGetResourceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));
	m_Tree.SetImageList(&m_imagelist,LVSIL_NORMAL);
	m_Root=m_Tree.InsertItem("Õû¸öÍøÂç",0,0);
	m_Tree.Expand(m_Root,TVE_EXPAND);

	DWORD Count=0xFFFFFFFF,Bufsize=4096,Res;
	
	NETRESOURCE* nRes; 
	NETRESOURCE* nRes1; 
	NETRESOURCE* nRes2; 
	NETRESOURCE* nRes3; 
	HANDLE lphEnum;
	LPVOID Buf = new char[4096];
	LPVOID Buf1 = new char[4096];
	LPVOID Buf2 = new char[4096];
	LPVOID Buf3 = new char[4096];
	Res = WNetOpenEnum(RESOURCE_GLOBALNET, RESOURCETYPE_ANY, RESOURCEUSAGE_CONTAINER,NULL,&lphEnum);
	Res=WNetEnumResource(lphEnum,&Count,Buf,&Bufsize);
	nRes=(NETRESOURCE*)Buf;

	for(DWORD n=0;n<Count;n++,nRes++)
	{
		DWORD Count1=0xFFFFFFFF;
	Res = WNetOpenEnum(RESOURCE_GLOBALNET, RESOURCETYPE_ANY, RESOURCEUSAGE_CONTAINER,nRes,&lphEnum);
	Res=WNetEnumResource(lphEnum,&Count1,Buf1,&Bufsize);
	nRes1=(NETRESOURCE*)Buf1;

	for(DWORD i=0;i<Count1;i++,nRes1++)
	{
		m_Group = m_Tree.InsertItem(nRes1->lpRemoteName,1,1,m_Root);
		DWORD Count2=0xFFFFFFFF;
		Res = WNetOpenEnum(RESOURCE_GLOBALNET, RESOURCETYPE_ANY, RESOURCEUSAGE_CONTAINER,nRes1,&lphEnum);
		Res=WNetEnumResource(lphEnum,&Count2,Buf2,&Bufsize);
		nRes2=(NETRESOURCE*)Buf2;
		for(DWORD j=0;j<Count2;j++,nRes2++)
		{
			CString sName = nRes2->lpRemoteName;
			sName = sName.Right(sName.GetLength()-2);
			m_Name = m_Tree.InsertItem(sName,2,2,m_Group);
			DWORD Count3=0xFFFFFFFF;
			Res = WNetOpenEnum(RESOURCE_GLOBALNET, RESOURCETYPE_ANY, RESOURCEUSAGE_CONNECTABLE,nRes2,&lphEnum);
			Res=WNetEnumResource(lphEnum,&Count3,Buf3,&Bufsize);
			nRes3=(NETRESOURCE*)Buf3;
			for(DWORD k=0;k<Count3;k++,nRes3++)
			{
				CString sShare = nRes3->lpRemoteName;
				sShare = sShare.Right(sShare.GetLength()-3-sName.GetLength());
				m_Tree.InsertItem(sShare,3,3,m_Name);
			}
		}
	}
	}
	delete Buf;
	delete Buf1;
	delete Buf2;
	delete Buf3;
	WNetCloseEnum(lphEnum);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CResShareDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CResShareDlg::OnPaint() 
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
HCURSOR CResShareDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
