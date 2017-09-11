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
	m_Port = 789;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon      = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_IsStop     = TRUE;
	m_IsRead     = FALSE;
	m_IsReceived = FALSE;
	m_AudioStop  = TRUE;
	m_Index      = 0;
	m_TransType  = ttText;
}

void CUuuuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUuuuDlg)
	DDX_Text(pDX, IDC_EDIT1, m_Port);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CUuuuDlg, CDialog)
	//{{AFX_MSG_MAP(CUuuuDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
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
	
	InitAudio();

	for (int i = 0; i<MAXNUM;i++)
	{
		if (i==0)
			m_pClientSock[i] = new CClientSocket(this,tpVideo);
		else
			m_pClientSock[i] = new CClientSocket(this,tpAudio);
	}
	m_pServerSock  = NULL;
	m_pServerAudio = NULL;

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



void CUuuuDlg::AcceptConnect()
{
	//接受客户框的连接
	m_pServerSock->Accept(*m_pClientSock[0]);
}

void CUuuuDlg::OnButton1() 
{
	UpdateData();
	m_pServerAudio = new CServerSocket(this,tpAudio);
	
	if (!m_pServerAudio->Create(m_Port))
	{
		MessageBox("套接字创建失败");

		delete m_pServerAudio;
		m_pServerAudio = NULL;
		return;
	}
	if (!m_pServerAudio->Listen())
		MessageBox("监听失败");	
}


void CUuuuDlg::OnCancel()
{
	if (m_pServerSock!= NULL)
		delete m_pServerSock;
	if (m_pServerAudio != NULL)
		delete m_pServerAudio;
	if (m_pClientSock[1] != NULL)
		delete m_pClientSock[1];
	if (m_pClientSock[0] != NULL)
		delete m_pClientSock[0];

	CDialog::OnCancel();
}

void CUuuuDlg::InitAudio()
{
	waveform.wFormatTag      = WAVE_FORMAT_PCM;  // 采样方式,PCM(脉冲编码调制)
    waveform.nChannels       = 2;                // 双声道
    waveform.nSamplesPerSec  = 11025;            // 采样率11.025KHz
    waveform.nAvgBytesPerSec = 11025;            // 数据率11.025KB/s
    waveform.nBlockAlign     = 1;                // 最小块单元，wBitsPerSample×nChannels/8
    waveform.wBitsPerSample  = 8;                // 样本大小为8bit
    waveform.cbSize          = 0;       

	lpInWaveHdr[0].dwBufferLength  = 4096;
	lpInWaveHdr[0].lpData          = lpInbuf;
	lpInWaveHdr[0].dwBytesRecorded = 4096;
	lpInWaveHdr[0].dwFlags         = 0;//WHDR_BEGINLOOP|WHDR_ENDLOOP;
	lpInWaveHdr[0].dwLoops         = 0;
	lpInWaveHdr[0].dwUser          = 0;
	lpInWaveHdr[0].lpNext          = NULL;
	lpInWaveHdr[0].reserved        = 0;

	lpOutWaveHdr[0].dwBufferLength  = 4096;
	lpOutWaveHdr[0].lpData          = lpOutbuf;
	lpOutWaveHdr[0].dwBytesRecorded = 4096;
	lpOutWaveHdr[0].dwFlags         = 0;//WHDR_BEGINLOOP|WHDR_ENDLOOP;
	lpOutWaveHdr[0].dwLoops         = 0;
	lpOutWaveHdr[0].dwUser          = 0;
	lpOutWaveHdr[0].lpNext          = NULL;
	lpOutWaveHdr[0].reserved        = 0;
	//打开放音设备
	waveOutOpen(&m_hWaveOut,WAVE_MAPPER,&waveform,(DWORD)m_hWnd,0,CALLBACK_WINDOW);
	waveOutPrepareHeader(m_hWaveOut,lpOutWaveHdr,4096);
	//设置音量大小
	waveOutSetVolume(m_hWaveOut,32765);
}

void CUuuuDlg::PlayAudio()
{
	waveOutWrite(m_hWaveOut,lpOutWaveHdr,sizeof(WAVEHDR));
}

void CUuuuDlg::AcceptAudioConnection()
{
	//接收客户端的连接
	m_pServerAudio->Accept(*m_pClientSock[1]);
}

//接收音频数据
void CUuuuDlg::OnReveiveAudioData(CClientSocket *sock)
{
	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE,9999);
	char* lpBuf = (char*)GlobalLock(hGlobal);

	memset(lpBuf,0,9999);
	int size= sock->Receive(lpBuf,9999);

	memset(lpOutbuf,0,4096);
	if (size<=4096)
	{
		memcpy(lpOutbuf,lpBuf,size);
		PlayAudio();
	}
	GlobalUnlock(hGlobal);
	GlobalFree(hGlobal);
}
