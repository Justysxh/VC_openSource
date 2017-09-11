// RemoteCloseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RemoteClose.h"
#include "RemoteCloseDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "winnetwk.h"
#pragma comment (lib,"mpr.lib")

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
// CRemoteCloseDlg dialog

CRemoteCloseDlg::CRemoteCloseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRemoteCloseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRemoteCloseDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_IsSucc = FALSE;
	m_IsSend = FALSE;
}

void CRemoteCloseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRemoteCloseDlg)
	DDX_Control(pDX, IDC_Pass, m_Pass);
	DDX_Control(pDX, IDC_IP, m_IP);
	DDX_Control(pDX, IDC_DELAY, m_Delay);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRemoteCloseDlg, CDialog)
	//{{AFX_MSG_MAP(CRemoteCloseDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRemoteCloseDlg message handlers

BOOL CRemoteCloseDlg::OnInitDialog()
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
	WSADATA data;
	WSAStartup(2.1,&data);
	
	hostent* info;
	info=  gethostbyname("mrvc");

	CString str;
	str.Format("%d.%d.%d.%d",(byte)info->h_addr[0],(byte)info->h_addr[1],(byte)info->h_addr[2],(byte)info->h_addr[3]);
	
	m_IP.SetWindowText(str);

	m_Delay.SetWindowText("3000");

	WSACleanup();

	if (GSMModemInitNew("COM1","9600",
		NULL,NULL,FALSE,"YIWU-IJDD-CDQW-JDWG")==FALSE)
	{
		MessageBox((char*)GSMModemGetErrorMsg());
		return TRUE;
	}

	SetTimer(1,500,NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRemoteCloseDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRemoteCloseDlg::OnPaint() 
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
HCURSOR CRemoteCloseDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRemoteCloseDlg::OnOK() 
{
	CString c_ip,c_name,c_pass,c_delay,temp;
	
	m_IP.GetWindowText(c_ip);
	temp.Format("\\\\%s",c_ip);
	c_ip = temp;
	m_Pass.GetWindowText(c_pass);
	m_Delay.GetWindowText(c_delay);
	DWORD delay = atol(c_delay);
	m_IsSucc = RemoteCloseWindows(c_ip.GetBuffer(0),"administrator",c_pass.GetBuffer(0),"系统出现异常,将要关机!",delay);
}

BOOL CRemoteCloseDlg::RemoteCloseWindows(LPCSTR remotename ,LPCSTR nameuser,LPCSTR pass,LPCSTR info, DWORD timeout)
{
	NETRESOURCE netresource;
	
	HANDLE token;

	TOKEN_PRIVILEGES privilege;

	DWORD result;

	memset(&netresource,0,sizeof(netresource));

	netresource.dwType = RESOURCETYPE_ANY;
	netresource.lpLocalName = "";
	netresource.lpProvider = "";
	netresource.lpRemoteName = (char*)remotename;

	if (WNetAddConnection2(&netresource,pass,nameuser,0)==0)
	{
		if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY,(PHANDLE)&token))
		{
			if (LookupPrivilegeValue(remotename,"SeRemoteShutdownPrivilege",&privilege.Privileges[0].Luid))
			{
				privilege.PrivilegeCount = 1;
				privilege.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
				
				if (AdjustTokenPrivileges(token,FALSE,&privilege,0,NULL,&result))
				{
					if (InitiateSystemShutdown((char*)remotename,(char*)info,timeout,TRUE,FALSE))
						return TRUE;
				}
			}	
		}
	}
	return FALSE;
}

void CRemoteCloseDlg::OnButton1() 
{
	CString c_ip,temp;
	m_IP.GetWindowText(c_ip);
	temp.Format("\\\\%s",c_ip);
	c_ip = temp;
	if (AbortSystemShutdown(c_ip.GetBuffer(0))==TRUE)
		MessageBox("成功");
}

void CRemoteCloseDlg::OnCancel()
{
	GSMModemRelease();
	CDialog::OnCancel();
}

void CRemoteCloseDlg::OnButton2() 
{
	char* reData;
	//获取接收的所有数据
	reData = (char*)GSMModemSMSReadAll(0);
	if (reData != NULL)
	{
		//获取所有短信内容的总长度
		int allDataLen = strlen(reData);
		
		int num = 0,content = 0;

		char number[30],msgContent[512]; //电话号码,短信内容
		memset(number,0,30);
		memset(msgContent,0,512);

		int once = 0 ; //接收完一个电话号码和一条短信

		for (int i = 0;i< allDataLen;i++)
		{
			if (reData[i]=='|')
			{
				once+=1;
				if (once==3 && reData[i-1]=='|')
				{ 
					CString str = msgContent;

					if (str=="关机")
					{
						KillTimer(1);
						m_Phone = number;
						OnOK();
						if (m_IsSucc) //已成功关机
						{
							GSMModemSMSsend(NULL,8,"已经成功关机",12,(char*)(LPCTSTR)m_Phone,FALSE);
							return;
						}
						else
						{
							GSMModemSMSsend(NULL,8,"关机失败,请重新关机",20,(char*)(LPCTSTR)m_Phone,FALSE);
							SetTimer(1,500,NULL);
						}
					}
					memset(number,0,30);
					memset(msgContent,0,512);
					num = 0;
					content = 0;
					once = 0;
					continue;
				}
			}
			if (once==0)
				number[num++]=reData[i];
			else if (once==1)
				if (reData[i]!='|')
				msgContent[content++]= reData[i];
		}
	}
}

void CRemoteCloseDlg::OnTimer(UINT nIDEvent) 
{	
	OnButton2();
	CDialog::OnTimer(nIDEvent);
}
