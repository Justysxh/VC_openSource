// CloseTimerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CloseTimer.h"
#include "CloseTimerDlg.h"
#include <atlbase.h>
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
// CCloseTimerDlg dialog

CCloseTimerDlg::CCloseTimerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCloseTimerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCloseTimerDlg)
	m_Time = COleDateTime::GetCurrentTime();
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCloseTimerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCloseTimerDlg)
	DDX_Control(pDX, IDC_CHECK1, m_Check);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_Time);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCloseTimerDlg, CDialog)
	//{{AFX_MSG_MAP(CCloseTimerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONSET, OnButtonset)
	ON_WM_TIMER()
	ON_MESSAGE(WM_ONTRAY,OnTray)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCloseTimerDlg message handlers

BOOL CCloseTimerDlg::OnInitDialog()
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
	m_Icon = AfxGetApp()->LoadIcon(IDI_ICON1);
	HANDLE hToken;
	//打开进程标识
	OpenProcessToken(GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY,&hToken);	
	TOKEN_PRIVILEGES Privilege;
	//查找权限
	LookupPrivilegeValue(NULL,"Seshutdownprivilege",&Privilege.Privileges[0].Luid);
	Privilege.PrivilegeCount = 1;
	Privilege.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	DWORD dwLen;
	//更改权限
	AdjustTokenPrivileges(hToken,false,&Privilege,sizeof(TOKEN_PRIVILEGES),NULL,&dwLen);

	m_Skey="Software\\Microsoft\\Windows\\CurrentVersion\\Run";
	ModifyStyleEx(WS_EX_APPWINDOW,WS_EX_TOOLWINDOW);

	//添加系统托盘
	char lpszTip[256];
	strcpy(lpszTip,"屏幕录像");							//托盘提示字符
	NOTIFYICONDATA data;
	data.cbSize = sizeof(NOTIFYICONDATA); 				//结构的大小
	data.hWnd   = m_hWnd; 								//接收消息窗口句柄
	lstrcpyn(data.szTip,lpszTip,sizeof(lpszTip)); 		//提示信息
	data.uCallbackMessage = WM_ONTRAY; 					//消息响应函数
	data.uFlags           = NIF_MESSAGE | NIF_ICON | NIF_TIP; //设置结构成员有效
	data.uID              = IDR_MAINFRAME;				//图标标识
	data.hIcon = m_Icon;						//图标句柄
	Shell_NotifyIcon(NIM_ADD,&data);			//添加系统托盘

	CString str;
	char buf[2];
	GetPrivateProfileString("设置", "开机运行", "", buf,2,"./Setting.ini");
	str = buf;
	m_Check.SetCheck(atoi(str));
	GetPrivateProfileString("设置", "是否关机", "", buf,2,"./Setting.ini");
	str = buf;
	if(str == "1")
	{
		SetTimer(1,1000,NULL);
		char time[8];
		GetPrivateProfileString("设置", "时间设置", "", time,8,"./Setting.ini");
		str = time;
		m_Time.SetTime(atoi(str.Left(2)),atoi(str.Mid(2,2)),atoi(str.Right(2)));
		UpdateData(FALSE);
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCloseTimerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCloseTimerDlg::OnPaint() 
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
HCURSOR CCloseTimerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCloseTimerDlg::OnButtonset() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(m_Check.GetCheck())
	{
		WritePrivateProfileString("设置","开机运行","1","./Setting.ini");
		char path[256];
		::GetCurrentDirectory(256,path);
		CString strname;
		strname.Format("%s\\Debug\\CloseTimer.exe",path);
		CRegKey	writevalue;
		writevalue.Create(HKEY_CURRENT_USER,m_Skey); 
		writevalue.SetValue(strname,"TimerRun");
		writevalue.Close();
	}
	else
	{
		WritePrivateProfileString("设置","开机运行","0","./Setting.ini");
		CRegKey	delkey;
		if(!delkey.Open(HKEY_CURRENT_USER,m_Skey))
		{
			delkey.DeleteValue("TimerRun");
			delkey.Close();
		}
	}
	WritePrivateProfileString("设置","是否关机","1","./Setting.ini");
	WritePrivateProfileString("设置","时间设置",m_Time.Format("%H%M%S"),"./Setting.ini");
	KillTimer(1);
	SetTimer(1,1000,NULL);
}

void CCloseTimerDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	UpdateData();
	CTime time = CTime::GetCurrentTime();
	if(m_Time.Format("%H%M%S") == time.Format("%H%M%S"))
	{
		ExitWindowsEx(EWX_SHUTDOWN | EWX_POWEROFF,0);
	}
	CDialog::OnTimer(nIDEvent);
}

void CCloseTimerDlg::OnTray(WPARAM wParam, LPARAM lParam)
{
	if(lParam == WM_LBUTTONDBLCLK)						//双击鼠标
	{
		ShowWindow(SW_RESTORE);							//恢复窗口的显示
	}
	if(lParam == WM_RBUTTONDOWN)						//双击鼠标
	{
		if(MessageBox("确定要退出程序吗？","系统提示",MB_OKCANCEL|MB_ICONQUESTION)==IDOK)
		{
			//删除系统托盘
			NOTIFYICONDATA data;
			data.cbSize = sizeof(NOTIFYICONDATA);
			data.hWnd   = m_hWnd;
			data.hIcon  = m_Icon;
			Shell_NotifyIcon(NIM_DELETE,&data);
			CDialog::OnCancel();
		}
	}
}

void CCloseTimerDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	ShowWindow(SW_HIDE);
	//CDialog::OnClose();
}
