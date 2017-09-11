// SendEMailDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SendEMail.h"
#include "SendEMailDlg.h"
#include "MAPI.H"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About


//定义mapi32.dll动态库中的函数原型
ULONG (PASCAL *lpfnMAPISendMail) (LHANDLE lhSession, 
ULONG ulUIParam, lpMapiMessage lpMessage, 
FLAGS flFlags, ULONG ulReserved); 


ULONG (FAR PASCAL *lpfnMAPILogon)(ULONG ulUIParam, 
LPSTR lpszProfileName, LPSTR lpszPassword, 
FLAGS flFlags, ULONG ulReserved, 
LPLHANDLE lplhSession); 

ULONG (FAR PASCAL *lpfnMAPILogoff)(LHANDLE lhSession, 
ULONG ulUIParam, FLAGS flFlags, 
ULONG ulReserved); 

ULONG (FAR PASCAL *lpfnMAPIFreeBuffer)(LPVOID lpBuffer); 

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
// CSendEMailDlg dialog

CSendEMailDlg::CSendEMailDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSendEMailDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSendEMailDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CSendEMailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSendEMailDlg)
	DDX_Control(pDX, IDC_Subject, m_subject);
	DDX_Control(pDX, IDC_ReceiverAddr, m_ReceiverAddr);
	DDX_Control(pDX, IDC_Content, m_content);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSendEMailDlg, CDialog)
	//{{AFX_MSG_MAP(CSendEMailDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSendEMailDlg message handlers

BOOL CSendEMailDlg::OnInitDialog()
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

void CSendEMailDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSendEMailDlg::OnPaint() 
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
HCURSOR CSendEMailDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSendEMailDlg::OnOK() 
{
	result = LoadLibrary("mapi32.dll"); //加载mapi动态库
	//获取函数指针
	(FARPROC&)lpfnMAPILogon      = GetProcAddress(result,"MAPILogon");
	(FARPROC&)lpfnMAPISendMail   = GetProcAddress(result,"MAPISendMail");
	(FARPROC&)lpfnMAPIFreeBuffer = GetProcAddress(result,"MAPIFreeBuffer");
	(FARPROC&)lpfnMAPILogoff     = GetProcAddress(result,"MAPILogoff");

	unsigned long a;
	lpfnMAPILogon(0,NULL,NULL,0,0,&a); //开始一个会话

	char* pcontext; //记录邮件正文
	CString str;
	m_content.GetWindowText(str);
	pcontext = str.GetBuffer(0);

	ULONG lresult ;

	MapiMessage* m_messageInfo; //定义一个信息结构指针
	m_messageInfo = new MapiMessage;
	memset(m_messageInfo,0,sizeof(MapiMessage));//初始化m_messageInfo

	CTime time = CTime::GetCurrentTime();//获取当前时间
	CString ctime = time.Format("%y//%m//%d//%H");
	char date[50];
	strcpy(date,ctime);

	CString subject ;
	m_subject.GetWindowText(subject); //获取主题


	CString receiver,temp;
	m_ReceiverAddr.GetWindowText(temp);//获取收件人信息

	receiver = temp.Left(temp.Find('@'));//获取用户账户

	char addr1[100]; //记录用户账户
	char addr2[100]; //记录SMTP服务器
	strcpy(addr1,receiver);

	receiver = "SMTP:"+temp;
	strcpy(addr2,receiver);
	
	MapiRecipDesc m_receiver = {0,MAPI_TO,addr1 ,addr2,0,NULL}; //定义接收者信息

	m_messageInfo->lpszNoteText = pcontext;            //设置邮件正文
	m_messageInfo->ulReserved = 0;                     //保留，必须为0
	m_messageInfo->lpszSubject = subject.GetBuffer(0); //设置主题
	m_messageInfo->lpszDateReceived = date;            //设置邮件发送时间
	m_messageInfo->lpszConversationID = NULL;          //邮件所属线程一个字符串指针
	m_messageInfo->flFlags = MAPI_SENT;                //邮件状态标记
	m_messageInfo->lpOriginator = NULL;                //发送者信息
	m_messageInfo->nRecipCount = 1;                    //接收者人数
	m_messageInfo->nFileCount = 0;                     //附件数
	m_messageInfo->lpRecips = &m_receiver;             //设置接收者信息
	m_messageInfo->lpszMessageType = NULL;	           //邮件类型

	lresult =  lpfnMAPISendMail(a,0,m_messageInfo,MAPI_DIALOG ,0); //发送邮件
	if (lresult != SUCCESS_SUCCESS)
	{
		MessageBox("操作失败.","提示",64);
	}
	else
	{
		MessageBox("邮件发送成功.","提示",64);
	
		m_content.Clear();
	}
	delete m_messageInfo;
	lpfnMAPIFreeBuffer(m_messageInfo);
	lpfnMAPILogoff(a,0,0,0);
	FreeLibrary(result);
}

void CSendEMailDlg::OnCancel() 
{
	CDialog::OnCancel();
}
