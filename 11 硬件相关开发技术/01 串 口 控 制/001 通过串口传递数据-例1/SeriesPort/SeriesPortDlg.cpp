// SeriesPortDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SeriesPort.h"
#include "SeriesPortDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//自定义一个消息
const CM_RECEIVE = WM_USER+100;

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
// CSeriesPortDlg dialog

CSeriesPortDlg::CSeriesPortDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSeriesPortDlg::IDD, pParent) 
{
	//{{AFX_DATA_INIT(CSeriesPortDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);

}

void CSeriesPortDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSeriesPortDlg)
	DDX_Control(pDX, IDC_EDIT1, m_info);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSeriesPortDlg, CDialog)
	//{{AFX_MSG_MAP(CSeriesPortDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_MESSAGE(CM_RECEIVE,OnRecieveData)
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSeriesPortDlg message handlers

BOOL CSeriesPortDlg::OnInitDialog()
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

void CSeriesPortDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSeriesPortDlg::OnPaint() 
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
OVERLAPPED tOverLaped=  {0};  //线程函数使用的OVERLAPPED结构
OVERLAPPED wOverLaped = {0};  //写操作使用的OVERLAPPED结构
OVERLAPPED rOverLaped = {0};  //读操作使用的OVERLAPPED结构
BOOL IsFun = TRUE;            //线程是否运行
BOOL IsStop = FALSE;          //数据是否发送完毕

HCURSOR CSeriesPortDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//线程函数
DWORD ThreadFunction(LPVOID pParam)
{
	DWORD  dwEvtMask ,dwResult;
	tOverLaped.hEvent = CreateEvent(NULL,TRUE,FALSE,NULL);//创建一个事件
	while (IsFun)
	{
		WaitCommEvent(((CSeriesPortDlg*)AfxGetMainWnd())->hCom,&dwEvtMask,&tOverLaped);//等待窗口事件
		dwResult = WaitForSingleObject(tOverLaped.hEvent,100); //如果事件没有信号,延时0.1秒

		switch (dwResult)
		{
		case WAIT_OBJECT_0: //事件对象有信号
			switch (dwEvtMask)
			{
			case EV_RXCHAR: //接收到数据
				{
					if (IsStop)//发送停止
					{
						IsStop = FALSE;
						//发送消息,由消息处理函数接收数据
						::PostMessage(AfxGetMainWnd()->m_hWnd, CM_RECEIVE,0,(LPARAM)EV_RXCHAR);
					}
					break;
				}			
			}
			break;		
		}
	}
	return 0;
}


void CSeriesPortDlg::OnOK() 
{
	hCom = CreateFile("COM1",       //打开串口1
		GENERIC_READ|GENERIC_WRITE, //允许读和写操作
		0,                          //独占方式
		NULL,
		OPEN_EXISTING,              //打开一个存在的串口
		FILE_ATTRIBUTE_NORMAL|FILE_FLAG_OVERLAPPED, //异步方式打开
		NULL
		);
	if (hCom==INVALID_HANDLE_VALUE)
	{
		MessageBox("端口打开失败.");
		return;
	}
}


void CSeriesPortDlg::OnButton1() 
{
	DWORD res;
	DWORD factdata = 0;

	m_info.GetWindowText(str);
	//创建一个事件对象
	wOverLaped.hEvent = CreateEvent(NULL,TRUE,FALSE,NULL); 
	IsStop = FALSE;
	//开始发送数据
	if (WriteFile(hCom,str,str.GetLength(),&factdata,&wOverLaped))
	{
		IsStop = TRUE;
		MessageBox("发送成功");
	}
	else
	{
		res = WaitForSingleObject(wOverLaped.hEvent,5000); //延时5秒,等待数据发送
		if (WAIT_OBJECT_0 == res) //如果事件处于有信号状态,表示发送完成
		{
			IsStop = TRUE;
		}
		else
			IsStop = FALSE;
		Sleep(1000); //延时1秒钟		
	}	
}

//自定义消息处理函数,用于接收数据		
void CSeriesPortDlg::OnRecieveData(WPARAM wParam, LPARAM lParam)
{

	DWORD res,factbyte;

	memset(DataBuffer,0,1024); //初始化数据缓冲区
	COMSTAT rst;

	ClearCommError(hCom,&res,&rst);//清空串口错误标志,记录当前通信状态

	rOverLaped.hEvent = CreateEvent(NULL,TRUE,FALSE,NULL); //创建一个事件对象
	if (ReadFile(hCom,DataBuffer,rst.cbInQue,&factbyte,&rOverLaped))  //读取数据到缓冲区中
	{
		DataBuffer[rst.cbInQue]= 0;
		IsStop = FALSE;
	}
	else
	{	
		res = WaitForSingleObject(rOverLaped.hEvent,5000);
	}
	IsStop = FALSE;
	MessageBox(DataBuffer);
}

//设置串口信息
void CSeriesPortDlg::OnButton2() 
{
	SetupComm(hCom,1024,1024); //设置发送和接收缓冲区大小
	//设置串口信息
	DCB dcb;
	GetCommState(hCom,&dcb);
	dcb.BaudRate = 9600;
	dcb.fBinary = TRUE;
	dcb.fParity = TRUE;
	dcb.ByteSize = 8;
	dcb.Parity = ODDPARITY;

	dcb.StopBits = ONESTOPBIT;

	if (!SetCommState(hCom,&dcb))
	{
		MessageBox("设置失败.","提示");
		return;		
	}

	if (!SetCommMask(hCom,EV_RXCHAR | EV_TXEMPTY))
	{
		MessageBox("掩码设置失败.","提示");
		return;
	}

	DWORD param;
	hThread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ThreadFunction,&param,0,&dwThreadID);
	if (hThread==INVALID_HANDLE_VALUE)
	{
		MessageBox("线程创建失败.","提示",64);
		return;
	}
	IsFun = TRUE;	
}
