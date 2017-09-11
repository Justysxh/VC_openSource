// uuuuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "uuuu.h"
#include "uuuuDlg.h"

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
// CUuuuDlg dialog

CUuuuDlg::CUuuuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUuuuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUuuuDlg)
	m_Port = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_IsStop = TRUE;
	m_IsRead = FALSE;
	m_IsReceived = FALSE;
}

void CUuuuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUuuuDlg)
	DDX_Control(pDX, IDC_STATIC1, m_picture);
	DDX_Text(pDX, IDC_EDIT1, m_Port);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CUuuuDlg, CDialog)
	//{{AFX_MSG_MAP(CUuuuDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUuuuDlg message handlers

BOOL CUuuuDlg::OnInitDialog()
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
	
	m_pClientSock = new CClientSocket(this);
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CUuuuDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CUuuuDlg::OnPaint() 
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
HCURSOR CUuuuDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CUuuuDlg::OnOK() 
{
	SetTimer(1,200,NULL);
}

void CUuuuDlg::OnTimer(UINT nIDEvent) 
{
	CString str;
	CFileFind fFind;
	if (m_IsReceived==TRUE)
	{
		if  (fFind.FindFile("c:\\b.bmp"))
		{
			HANDLE hBmp = LoadImage(NULL,"c:\\b.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);

			if (hBmp!=NULL)
			{
				m_picture.SetBitmap((HBITMAP)hBmp);
			}
		}
	}
	CDialog::OnTimer(nIDEvent);
}

void CUuuuDlg::AcceptConnect()
{
	//接受客户框的连接
	m_pServerSock->Accept(*m_pClientSock);
}

void CUuuuDlg::OnButton1() 
{
	UpdateData();
	m_pServerSock = new CServerSocket(this);
	if (!m_pServerSock->Create(m_Port))
	{
		MessageBox("套接字创建失败");
		delete m_pServerSock;
		m_pServerSock = NULL;
		return;
	}
	if (!m_pServerSock->Listen())
		MessageBox("监听失败");	
}

void CUuuuDlg::ReceiveData(CClientSocket *sock)
{	
		
	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE,999999);
	void* lpBuf = GlobalLock(hGlobal);

	DWORD size= sock->Receive(lpBuf,999999);
	if (m_IsStop)
	{
		m_file.Open("c:\\b.bmp",CFile::modeCreate|CFile::modeWrite);
		m_file.WriteHuge(lpBuf,size);
		m_IsStop = FALSE;
		m_IsReceived = FALSE;

		GlobalUnlock(hGlobal);
		GlobalFree(hGlobal);
		return;
	}
	char* temp = (char*)lpBuf;
	if ((temp[size-1]=='^'))
	{
		m_file.Close();
		m_IsStop = TRUE;
		m_IsReceived =TRUE;
		char temp[1]={'a'};
		sock->Send(temp,1);
	}
	else 
	{
		m_file.WriteHuge(lpBuf,size);

		GlobalUnlock(hGlobal);
		GlobalFree(hGlobal);
	}
}

void CUuuuDlg::OnButton2() 
{
	
}
