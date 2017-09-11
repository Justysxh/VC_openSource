// KinescodeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Kinescode.h"
#include "KinescodeDlg.h"
#include <math.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
	BOOL            m_IsSending = false;
	BOOL            m_IsSave    = false;
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
// CKinescodeDlg dialog

CKinescodeDlg::CKinescodeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKinescodeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CKinescodeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hVideoWnd =  0;
	m_pThread   =   NULL;
	m_IsKindscode = FALSE;
	m_pSock = NULL;
	m_IsSend  = FALSE;
	m_IsSending = FALSE;
	m_IsReceived  = TRUE;
}

void CKinescodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKinescodeDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CKinescodeDlg, CDialog)
	//{{AFX_MSG_MAP(CKinescodeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_KINESCODE, OnKinescode)
	ON_BN_CLICKED(IDC_STOPKINESCODE, OnStopkinescode)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_LINKSERVER, OnLinkserver)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

HWND hTemp ;


/////////////////////////////////////////////////////////////////////////////
// CKinescodeDlg message handlers

BOOL CKinescodeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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


	m_pThread = AfxBeginThread(ThreadFun,(LPVOID)this);
	m_Event.ResetEvent();
	::WaitForSingleObject(m_Event,INFINITE);
	if (m_hVideoWnd)
	{
		if (capDriverConnect(m_hVideoWnd,0)==FALSE)
		{
			MessageBox("连接驱动程序出错");
 			return 0;
		}
		

		::SetParent(m_hVideoWnd,*this);
		::SetWindowLong(m_hVideoWnd,GWL_STYLE,WS_CHILD);
		::SetWindowPos(m_hVideoWnd,0,10,10,300,300,SWP_NOREDRAW);
		::ShowWindow(m_hVideoWnd,SW_SHOW);
		capPreviewRate(m_hVideoWnd,10);
		capPreview(m_hVideoWnd,TRUE);
		capOverlay(m_hVideoWnd,TRUE);
	}

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
		
	return TRUE;  // return TRUE  unless you set the focus to a control
}

//线程执行函数
UINT CKinescodeDlg::ThreadFun( LPVOID wParam )
{
	CKinescodeDlg* temp = (CKinescodeDlg*)wParam;
	temp->m_hVideoWnd = capCreateCaptureWindow("Capture",WS_POPUP,5,5,20,20,*temp,0);
	hTemp = temp->m_hVideoWnd;

	if (temp->m_hVideoWnd )
	{	
		temp->m_Event.SetEvent();
		MSG msg;
		while (GetMessage(&msg,temp->m_hVideoWnd,0,0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return msg.wParam;
	}
	return 0;
}


void CKinescodeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CKinescodeDlg::OnPaint() 
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

HCURSOR CKinescodeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CKinescodeDlg::OnExit() 
{
	OnCancel();
}

void CKinescodeDlg::OnKinescode() 
{
	CString filename;
	CFileDialog FileDlg(FALSE,"mpg");
	if (FileDlg.DoModal()==IDOK)
	{
		filename = FileDlg.GetPathName();
		filename.GetBufferSetLength(filename.GetLength()+2);
		filename.Insert(filename.GetLength(),'0');
		filename.Insert(filename.GetLength()+1,'0');
		
		capFileSetCaptureFile(m_hVideoWnd,filename.GetBuffer(0));
		capCaptureSequence(m_hVideoWnd);
		m_IsKindscode = TRUE;
	}
}

void CKinescodeDlg::OnCancel()
{
	capCaptureSingleFrameClose(m_hVideoWnd);
	capDriverDisconnect(m_hVideoWnd);
	if (m_pSock)
		delete m_pSock;
	if (m_pThread != NULL)
		delete m_pThread;
	CDialog::OnCancel();
}

void CaptureFun(LPVOID pParam)
{
	if (m_IsSending==FALSE)
	{
		m_IsSave=FALSE;
		capFileSaveDIB(hTemp,"c:\\a.bmp");
		m_IsSave = TRUE;
	}
}

void CKinescodeDlg::OnStopkinescode() 
{
	capSetCallbackOnFrame(m_hVideoWnd,CaptureFun);
	m_IsSend = TRUE;
	SetTimer(1,200,NULL);
}

void CKinescodeDlg::OnTimer(UINT nIDEvent) 
{
	if (m_IsSend)
	{
		if (m_IsSending==FALSE)
			if (m_IsSave)
				((CKinescodeDlg*)AfxGetMainWnd())->SendData();
	}
	CDialog::OnTimer(nIDEvent);
}

void CKinescodeDlg::OnLinkserver() 
{

	LABEL1: CLogin login;
	if (login.DoModal()==IDOK)
	{
		m_pSock = new CClientSocket(this);

		CString port = login.m_Port;
		CString serveraddr = login.m_ServerAddr;

		if (!m_pSock->Create())
		{
			delete m_pSock;
			MessageBox("操作失败");
			return ;
		}
		UINT i_port = atoi(port);
		if (m_pSock->Connect(serveraddr,i_port)==FALSE)
		{
			if (MessageBox("连接服务器失败,是否尝试重新连接?","提示",MB_YESNO)==IDYES)
			{
				delete m_pSock;
				goto LABEL1;   //重新连接
			}
			else
				return;
		}
		m_IsSend = TRUE;
	}
}

void CKinescodeDlg::SendData()
{	
	//只有在服务器端接收完成才开始发送数据
	if (m_IsReceived)
	{
		m_IsReceived = FALSE;
		m_IsSending = TRUE;

		CFile file("c:\\a.bmp",CFile::modeRead);
		DWORD size = file.GetLength();
		
		HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE,size);
		void* lpBuf = GlobalLock(hGlobal);
		file.ReadHuge(lpBuf,size);
		m_pSock->Send(lpBuf,size);
		char a[1]={'^'};          //结束符
		m_pSock->Send(a,1);    
		GlobalUnlock(hGlobal);
		GlobalFree(hGlobal);
		m_IsSending = FALSE;
	}
}

void CKinescodeDlg::ReceiveData(CClientSocket *sock)
{
	char a[1];
	sock->Receive(a,1);
	m_IsReceived = TRUE;
}
