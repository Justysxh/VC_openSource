// NameAndIPDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NameAndIP.h"
#include "NameAndIPDlg.h"
#include "winnetwk.h"
#include "afxsock.h"
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
// CNameAndIPDlg dialog

CNameAndIPDlg::CNameAndIPDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNameAndIPDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNameAndIPDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNameAndIPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNameAndIPDlg)
	DDX_Control(pDX, IDC_LIST1, m_grid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNameAndIPDlg, CDialog)
	//{{AFX_MSG_MAP(CNameAndIPDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNameAndIPDlg message handlers

BOOL CNameAndIPDlg::OnInitDialog()
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
	WSADATA wsd;
	WSAStartup(MAKEWORD(2,2),&wsd);
	m_grid.SetExtendedStyle(LVS_EX_FLATSB
		|LVS_EX_FULLROWSELECT
		|LVS_EX_HEADERDRAGDROP
		|LVS_EX_ONECLICKACTIVATE
		|LVS_EX_GRIDLINES);
	m_grid.InsertColumn(0,"计算机名",LVCFMT_LEFT,200,0);
	m_grid.InsertColumn(1,"IP地址",LVCFMT_LEFT,200,0);
	DWORD Count=0xFFFFFFFF,Bufsize=4096,Res;

	NETRESOURCE* nRes; 
	NETRESOURCE* nRes1; 
	NETRESOURCE* nRes2; 
	HANDLE lphEnum;
	LPVOID Buf = new char[4096];
	LPVOID Buf1 = new char[4096];
	LPVOID Buf2 = new char[4096];
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
			DWORD Count2=0xFFFFFFFF;
			Res = WNetOpenEnum(RESOURCE_GLOBALNET, RESOURCETYPE_ANY, RESOURCEUSAGE_CONTAINER,nRes1,&lphEnum);
			Res=WNetEnumResource(lphEnum,&Count2,Buf2,&Bufsize);
			nRes2=(NETRESOURCE*)Buf2;
			for(DWORD j=0;j<Count2;j++,nRes2++)
			{
				m_grid.InsertItem(j,0);
				CString sName=nRes2->lpRemoteName;
				sName=sName.Right(sName.GetLength()-2);
				m_grid.SetItemText(j,0,sName);
				CString str="";
				struct hostent * pHost;
				pHost = gethostbyname(sName);
				if(pHost==NULL)
				{
					m_grid.SetItemText(j,1,"无法获得IP地址");
				}
				else
				{
					for(int n=0;n<4;n++)
					{
						CString addr;
						if(n > 0)
						{
							str += ".";
						}
						addr.Format("%u",(unsigned int)((unsigned char*)pHost->h_addr_list[0])[n]);
						str += addr;
					}
					m_grid.SetItemText(j,1,str);
				}
			}
		}
	}
	delete Buf;
	delete Buf1;
	delete Buf2;
	WNetCloseEnum(lphEnum);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNameAndIPDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CNameAndIPDlg::OnPaint() 
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
HCURSOR CNameAndIPDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
