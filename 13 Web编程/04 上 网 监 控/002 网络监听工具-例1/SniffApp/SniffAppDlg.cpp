// SniffAppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SniffApp.h"
#include "SniffAppDlg.h"

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
// CSniffAppDlg dialog
PROTONAME protos[11] = {
	{IPPROTO_IP ,"IP"},
	{IPPROTO_ICMP,"ICMP"},
	{IPPROTO_IGMP,"IGMP"},
	{IPPROTO_GGP,"GGP"},
	{IPPROTO_TCP,"TCP"},
	{IPPROTO_PUP,"PUP"},
	{IPPROTO_UDP,"UDP"},
	{IPPROTO_IDP,"IDP"},
	{IPPROTO_ND,"ND"},
	{IPPROTO_RAW,"RAW"},
	{IPPROTO_MAX,"MAX"}
};

char* get_protoname(int protoID)
{
	for (int i= 0; i<11; i++)
		if (protoID == protos[i].value)
		{
			return protos[i].protoname;
		}
	return "";
}


CSniffAppDlg::CSniffAppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSniffAppDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSniffAppDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pThread = NULL;
}

void CSniffAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSniffAppDlg)
	DDX_Control(pDX, IDC_LIST1, m_List);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSniffAppDlg, CDialog)
	//{{AFX_MSG_MAP(CSniffAppDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BEGINLISTEN, OnBeginlisten)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSniffAppDlg message handlers

BOOL CSniffAppDlg::OnInitDialog()
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
	



	m_List.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_GRIDLINES|LVS_EX_TWOCLICKACTIVATE);

	m_List.InsertColumn(0,"协议",LVCFMT_LEFT,80);
	m_List.InsertColumn(1,"源IP地址",LVCFMT_LEFT,120);
	m_List.InsertColumn(2,"目的IP地址",LVCFMT_LEFT,120);
	m_List.InsertColumn(3,"通信端口",LVCFMT_LEFT,80);
	m_List.InsertColumn(4,"大小",LVCFMT_LEFT,100);
	m_List.InsertColumn(5,"数据",LVCFMT_LEFT,120);


	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSniffAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSniffAppDlg::OnPaint() 
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
HCURSOR CSniffAppDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSniffAppDlg::OnOK() 
{

}

//线程函数
UINT ThreadFun( LPVOID pParam )
{
	CSniffAppDlg* pDlg = static_cast<CSniffAppDlg*>(pParam);
	
	MSG msg;
	char buffer[1000],sourceip[32] ,*tempbuf;
	char *ptemp;

	BYTE* pData = NULL; //实际数据报中的数据
	

	UINT  sourceport ;

	CString str;

	HEADIP*    pHeadIP;
	HEADICMP*  pHeadICMP;
	HEADUDP*   pHeadUDP;
	HEADTCP*   pHeadTCP;
	
	in_addr addr;
	
	int ret;
	while (TRUE)
	{
		pData = NULL;
		if (PeekMessage(&msg,pDlg->m_hWnd,WM_CLOSE,WM_CLOSE,PM_NOREMOVE ))
		{
			closesocket(pDlg->m_Sock);
			break;		
		}
		memset(buffer,0,1000);


		ret = recv(pDlg->m_Sock,buffer,1000,0);
		
		if (ret == SOCKET_ERROR)
		{
			continue;
		}
		else //接收到数据
		{
			tempbuf = buffer;
			
			pHeadIP = (HEADIP*)tempbuf;
			
			//获取数据报总长度
			WORD len = ntohs(pHeadIP->totallen);
			
			//获取源IP
			pDlg->m_List.InsertItem(pDlg->m_List.GetItemCount(),"");
			addr.S_un.S_addr = pHeadIP->sourceIP;
			ptemp = inet_ntoa(addr);
			
			pDlg->m_List.SetItemText(pDlg->m_List.GetItemCount()-1,1,ptemp);
		
			//获取目的IP
			addr.S_un.S_addr = pHeadIP->destIP;
			ptemp = inet_ntoa(addr);
			pDlg->m_List.SetItemText(pDlg->m_List.GetItemCount()-1,2,ptemp);
			
			//获取协议名称
			ptemp = get_protoname(pHeadIP->proto);
			strcpy(sourceip,ptemp);
			pDlg->m_List.SetItemText(pDlg->m_List.GetItemCount()-1,0,sourceip);
			
			
			//获取IP数据报总长度
			WORD ipSumLen  =  ntohs(pHeadIP->totallen);
			
			//IP数据报头总长度
			int ipHeadLen = 20;

			//获得去除IP层数据的长度
			WORD  netlen = ipSumLen - ipHeadLen;
			
			//根据不同大协议获得不同协议的数据
			switch (pHeadIP->proto)
			{
			case IPPROTO_ICMP:
				{
					pHeadICMP = (HEADICMP*)(tempbuf+20); 
					
					pData = (BYTE*)(pHeadICMP)+4; //ICMP数据报头共4个字节					
					//获取数据的长度
					netlen -= 4;

					break;
				}
			case IPPROTO_UDP:
				{
					pHeadUDP = (HEADUDP*)(tempbuf+20); 
					
					

					pData = (BYTE*)pHeadUDP+8; //UDP数据报头共8个字节
					
					sourceport = ntohs(pHeadUDP->SourcePort);
					
					str.Format("%d",sourceport);
					//设置源端口
					pDlg->m_List.SetItemText(pDlg->m_List.GetItemCount()-1,3,str);	
					
					str.Empty();

					netlen -= 8;				
					break;
				}
			case IPPROTO_TCP:
				{
					pHeadTCP = (HEADTCP*)(tempbuf+20);
					sourceport = ntohs(pHeadTCP->SourcePort);					

					pData = (BYTE*)pHeadTCP+20; //TCP数据报头共20个字节
									 
					str.Format("%d",sourceport);
					//设置源端口
					pDlg->m_List.SetItemText(pDlg->m_List.GetItemCount()-1,3,str);	
					str.Empty();
					netlen-= 20;				
					break;
				}									
			}
			//设置数据大小
			str.Format("%d",netlen);
			pDlg->m_List.SetItemText(pDlg->m_List.GetItemCount()-1,4,str);
			str.Empty();
			//设置数据
			if (pData != NULL)
			{
				str.Format(" %s",pData);
				pDlg->m_List.SetItemText(pDlg->m_List.GetItemCount()-1,5,str);
			}
			str.Empty();
		}
	}
	return 0;
}


void CSniffAppDlg::OnBeginlisten() 
{
	//创建套接字
	m_Sock = socket(AF_INET,SOCK_RAW, IPPROTO_IP );
	
	char name[128];
	memset(name,0,128);
	
	hostent* phostent;

	phostent =  gethostbyname(name);
	
	DWORD ip;
	
	ip = inet_addr(inet_ntoa(*(in_addr*)phostent->h_addr_list[0]));


	int timeout = 4000; //超时4秒

	//设置接收数据的超时时间
	setsockopt(m_Sock,SOL_SOCKET,SO_RCVTIMEO,(const char*)&timeout,sizeof(timeout));

	sockaddr_in skaddr;
	skaddr.sin_family = AF_INET;
	skaddr.sin_port = htons(700);
	skaddr.sin_addr.S_un.S_addr  = ip;
	//绑定地址
	if ( bind(m_Sock,(sockaddr*)&skaddr,sizeof(skaddr))==SOCKET_ERROR)
	{
		MessageBox("地址绑定错误");
		return;
	}
	
	DWORD inBuffer=1;
	DWORD outBuffer[10];
	DWORD reValue = 0;

	if (WSAIoctl(m_Sock,SIO_RCVALL,&inBuffer,sizeof(inBuffer),&outBuffer,sizeof(outBuffer),&reValue,NULL,NULL)==SOCKET_ERROR)
	{
		MessageBox("设置缓冲区错误.");
		closesocket(m_Sock);
		return;
	}
	else
		m_pThread = AfxBeginThread(ThreadFun,(void*)this);
}

void CSniffAppDlg::OnCancel()
{
	if (m_pThread)
	{
		//m_pThread->ExitInstance();
		delete m_pThread;
	}
	closesocket( m_Sock) ;
	CDialog::OnCancel();
}

