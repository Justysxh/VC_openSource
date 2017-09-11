// ServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ServerDlg.h"

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
// CServerDlg dialog

CServerDlg::CServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CServerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CServerDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CServerDlg, CDialog)
	//{{AFX_MSG_MAP(CServerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerDlg message handlers

BOOL CServerDlg::OnInitDialog()
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
	//创建套接字
	m_server = socket(AF_INET,SOCK_STREAM,0);
	//将网络中的事件关联到窗口的消息函数中
	WSAAsyncSelect(m_server,m_hWnd,20000,FD_WRITE|FD_READ|FD_ACCEPT);
	m_client = 0;
	m_serverIP = "";

	DWORD nSize = MAX_COMPUTERNAME_LENGTH + 1;
	char Buffer[MAX_COMPUTERNAME_LENGTH + 1];
	GetComputerName(Buffer,&nSize);
	CString str="",name;
	struct hostent * pHost;
	pHost = gethostbyname(Buffer);
    for(int i=0;i<4;i++)
	{
		CString addr;
		if(i > 0)
		{
			str += ".";
		}
		addr.Format("%u",(unsigned int)((unsigned char*)pHost->h_addr_list[0])[i]);
		str += addr;
	}

	//服务器端地址
	sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	m_serverIP = str;
	//设置本机地址
	serveraddr.sin_addr.S_un.S_addr  = inet_addr(m_serverIP);
	UpdateData(TRUE);
	//设置端口号
	serveraddr.sin_port = htons(70);
	//绑定地址
	if (bind(m_server,(sockaddr*)&serveraddr,sizeof(serveraddr)))
	{
		MessageBox("绑定地址失败.");
		return;
	}
	//开始监听
	listen(m_server,5);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CServerDlg::OnPaint() 
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
HCURSOR CServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CServerDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message==20000)
		HanShu();
	else
		return CDialog::PreTranslateMessage(pMsg);
}

void CServerDlg::HanShu()
{
	sockaddr_in serveraddr;
	char buffer[1];
	int len =sizeof(serveraddr);
	if (m_client==0) //客户端连接服务器
	{
		m_client = accept(m_server,(struct sockaddr*)&serveraddr,&len);
	}
	else
	{	
		//接收客户端的数据
		int num = recv(m_client,buffer,1,0);
		CWnd* cwnd;
		static HANDLE hToken;   
		static TOKEN_PRIVILEGES tp;
		static LUID luid;          							
		OpenProcessToken(GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY,&hToken);
		LookupPrivilegeValue(NULL,SE_SHUTDOWN_NAME,&luid);
		tp.PrivilegeCount =1;
		tp.Privileges [0].Luid =luid;
		tp.Privileges [0].Attributes =SE_PRIVILEGE_ENABLED;
		AdjustTokenPrivileges(hToken,FALSE,&tp,sizeof(TOKEN_PRIVILEGES),NULL, NULL);
		switch(buffer[0])
		{
			case '1':
				cwnd = FindWindow("ProgMan",NULL);
				::ShowWindow(cwnd->GetSafeHwnd(),SW_HIDE);
				break;
			case '2':
				cwnd = FindWindow("ProgMan",NULL);
				::ShowWindow(cwnd->GetSafeHwnd(),SW_SHOW);
				break;
			case '3':
				::ExitWindowsEx(EWX_LOGOFF,0);
				break;
			case '4':
				::ExitWindowsEx(EWX_SHUTDOWN,0);
				break;
			case '5':
				::ExitWindowsEx(EWX_REBOOT,0);
				break;
		}
	}
}
