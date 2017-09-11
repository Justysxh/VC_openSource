// ProtocolDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Protocol.h"
#include "ProtocolDlg.h"
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
// CProtocolDlg dialog

CProtocolDlg::CProtocolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProtocolDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProtocolDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProtocolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProtocolDlg)
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CProtocolDlg, CDialog)
	//{{AFX_MSG_MAP(CProtocolDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTENUMERATE, OnButenumerate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProtocolDlg message handlers

BOOL CProtocolDlg::OnInitDialog()
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
	WSADATA wsa;
	WSAStartup(MAKEWORD(2,2),&wsa);
	m_Grid.SetExtendedStyle(LVS_EX_FLATSB
		|LVS_EX_FULLROWSELECT
		|LVS_EX_HEADERDRAGDROP
		|LVS_EX_ONECLICKACTIVATE
		|LVS_EX_GRIDLINES);
	m_Grid.InsertColumn(0,"系统中安装的协议",LVCFMT_LEFT,550,0);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CProtocolDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CProtocolDlg::OnPaint() 
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
HCURSOR CProtocolDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CProtocolDlg::OnButenumerate() 
{
	LPBYTE pBuf; //保存网络协议信息的缓冲区
	DWORD dwLen; //缓冲区的长度
	LPWSAPROTOCOL_INFO pInfo;
	//通过调用WSAEnumProtocols以获得所需缓冲区的大小
	int nRet = WSAEnumProtocols(NULL,NULL,&dwLen);
	if(nRet == SOCKET_ERROR)
	{
		if(WSAGetLastError() != WSAENOBUFS)
		{   
			MessageBox("调用失败");
			return;
		}
	}
	//检查缓冲区的大小是否可以容纳信息
	if(dwLen < sizeof(WSAPROTOCOL_INFO))
	{
		MessageBox("缓冲区出现错误");
		return;
	}
	dwLen++;
	pBuf = (LPBYTE)malloc(dwLen); //申请所需的内存
	if(pBuf == NULL)
	{
		MessageBox("内存分配失败");
		return;
	}
    //进行枚举，nRet是返回的协议个数
	nRet = WSAEnumProtocols(NULL,(LPWSAPROTOCOL_INFO)pBuf,&dwLen);
	if(nRet == SOCKET_ERROR)
	{   
        free(pBuf);
		MessageBox("枚举失败");
		return;		
	}
	//遍历各协议的信息
	pInfo = (LPWSAPROTOCOL_INFO)pBuf;
	for(int nCount=0;nCount<nRet;nCount++)
	{
		//将协议信息添加到列表中
		int i = m_Grid.GetCountPerPage();
		m_Grid.InsertItem(i,pInfo->szProtocol);
		pInfo++;
	}
	//释放内存
	free(pBuf);
}
