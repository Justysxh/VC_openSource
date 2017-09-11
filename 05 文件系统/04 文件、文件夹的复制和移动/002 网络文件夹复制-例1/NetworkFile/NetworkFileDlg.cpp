// NetworkFileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetworkFile.h"
#include "NetworkFileDlg.h"

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
// CNetworkFileDlg dialog

CNetworkFileDlg::CNetworkFileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNetworkFileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNetworkFileDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNetworkFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNetworkFileDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNetworkFileDlg, CDialog)
	//{{AFX_MSG_MAP(CNetworkFileDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTCOPY, OnCopy)
	ON_BN_CLICKED(IDC_BTEXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetworkFileDlg message handlers

BOOL CNetworkFileDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNetworkFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CNetworkFileDlg::OnPaint() 
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
HCURSOR CNetworkFileDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CNetworkFileDlg::OnCopy() 
{
	CString strnetwork,strlocal;
	GetDlgItem(IDC_EDNETWORK)->GetWindowText(strnetwork);
	GetDlgItem(IDC_EDLOCAL)->GetWindowText(strlocal);
	if(strnetwork.IsEmpty())
	{
		AfxMessageBox("请输入网络文件夹路径");
		return;
	}
	if(strlocal.IsEmpty())
	{
		AfxMessageBox("请输入本地文件夹路径");
		return;
	}
	if(strnetwork.Left(2)!="\\\\")
	{
		AfxMessageBox("路径首部应是\\\\");
		return;
	}
	char fromname[80]="\0";
	char toname[80]="\0";

	strcpy(fromname,strnetwork);
	strcpy(toname,strlocal);
	strcat(fromname,"\0");
	strcat(toname,"\0");
	SHFILEOPSTRUCT lpFilestru;
	lpFilestru.hwnd=GetSafeHwnd();
	lpFilestru.wFunc=FO_COPY;
	lpFilestru.pFrom=fromname;
	lpFilestru.pTo=toname;
	lpFilestru.fFlags=FOF_ALLOWUNDO;
	lpFilestru.fAnyOperationsAborted=FALSE;
	BOOL bcopy=SHFileOperation(&lpFilestru);
	if(bcopy==0)
	{
		
		if(lpFilestru.fAnyOperationsAborted==TRUE)
			AfxMessageBox("复制被取消");
		else
			AfxMessageBox("复制成功");
	}
	else
	{
		AfxMessageBox("复制失败");
	}
		
}

void CNetworkFileDlg::OnExit() 
{
	this->OnCancel();	
}
