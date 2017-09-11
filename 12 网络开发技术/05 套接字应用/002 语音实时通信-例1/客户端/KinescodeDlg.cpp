// KinescodeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Kinescode.h"
#include "KinescodeDlg.h"
#include <math.h>
//#include "ClientSocket.h"

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

	m_hVideoWnd   =  0;
	m_pThread     =  NULL;
	m_IsKindscode = FALSE;
	m_pSock       = NULL;
	m_pAudioSock  = NULL;
	m_IsSend      = FALSE;
	m_IsSending   = FALSE;
	m_IsReceived  = TRUE;
	m_Played      = TRUE;
	m_Change      = TRUE;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
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
	ON_MESSAGE(MM_WIM_DATA,EndRecord)
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



	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	m_pSock = NULL;
	
	return TRUE;  // return TRUE  unless you set the focus to a control
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
	m_Played !=m_Played;
	OnCancel();
}

void CKinescodeDlg::OnKinescode() 
{

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



void CKinescodeDlg::OnStopkinescode() 
{
	InitAudio();
}

void CKinescodeDlg::OnLinkserver() 
{
	LABEL1: CLogin login;
	if (login.DoModal()==IDOK)
	{

		if (m_pAudioSock != NULL)
			delete m_pAudioSock;
		m_pAudioSock = new CClientSocket(this,tpAudio);

		CString port = login.m_Port;
		CString serveraddr = login.m_ServerAddr;

		if ( !m_pAudioSock->Create())
		{
			delete m_pAudioSock;
			m_pAudioSock = NULL;
			MessageBox("操作失败");
			return ;
		}
		UINT i_port = atoi(port);
		if ((m_pAudioSock->Connect(serveraddr,i_port)==FALSE))
		{
			if (MessageBox("连接服务器失败,是否尝试重新连接?","提示",MB_YESNO)==IDYES)
			{
				delete m_pAudioSock;
				m_pAudioSock = NULL;
				goto LABEL1;   //重新连接
			}
			else
				return;
		}

		m_IsSend = TRUE;
	}

}


void CKinescodeDlg::InitAudio()
{
	waveform.wFormatTag      = WAVE_FORMAT_PCM ;  // 采样方式,PCM(脉冲编码调制)
    waveform.nChannels       = 2 ;                // 双声道
    waveform.nSamplesPerSec  = 11025 ;            // 采样率11.025KHz
    waveform.nAvgBytesPerSec = 11025;             // 数据率11.025KB/s
    waveform.nBlockAlign     = 1 ;                // 最小块单元，wBitsPerSample×nChannels/8
    waveform.wBitsPerSample  = 8 ;                // 样本大小为8bit
    waveform.cbSize          = 0 ;       

	lpInWaveHdr[0].dwBufferLength  = 4096;
	lpInWaveHdr[0].lpData          = lpInbuf;
	lpInWaveHdr[0].dwBytesRecorded = 0;
	lpInWaveHdr[0].dwFlags         = 0;
	lpInWaveHdr[0].dwLoops         = 0;
	lpInWaveHdr[0].dwUser          = 0;
	lpInWaveHdr[0].lpNext          = NULL;
	lpInWaveHdr[0].reserved        = 0;

	lpInWaveHdr[1].dwBufferLength  = 4096;
	lpInWaveHdr[1].lpData          = lpInbuf1;
	lpInWaveHdr[1].dwBytesRecorded = 0;
	lpInWaveHdr[1].dwFlags         = 0;
	lpInWaveHdr[1].dwLoops         = 0;
	lpInWaveHdr[1].dwUser          = 0;
	lpInWaveHdr[1].lpNext          = NULL;
	lpInWaveHdr[1].reserved        = 0;

	lpOutWaveHdr[0].dwBufferLength  = 4096;
	lpOutWaveHdr[0].lpData          = lpOutbuf;
	lpOutWaveHdr[0].dwBytesRecorded = 4096;
	lpOutWaveHdr[0].dwFlags         = 0;
	lpOutWaveHdr[0].dwLoops         = 0;
	lpOutWaveHdr[0].dwUser          = 0;
	lpOutWaveHdr[0].lpNext          = NULL;
	lpOutWaveHdr[0].reserved        = 0;

	//打开录音设备和放音设备
	MMRESULT result = 	waveInOpen(&m_hWaveIn,WAVE_MAPPER ,&waveform,(DWORD)m_hWnd,0,CALLBACK_WINDOW);
	waveInPrepareHeader(m_hWaveIn,lpInWaveHdr,4096);
	StartRecord();
	m_pAudioSock->SetSockOpt(SO_SNDBUF,lpOutWaveHdr->lpData,4096);
}

//开始录音
void CKinescodeDlg::StartRecord()
{
	if (m_Played)
	{
		if (m_Change)
			waveInAddBuffer(m_hWaveIn,&lpInWaveHdr[0],sizeof(WAVEHDR));
		else
			waveInAddBuffer(m_hWaveIn,&lpInWaveHdr[1],sizeof(WAVEHDR));
		waveInStart(m_hWaveIn);
	}
}

void CKinescodeDlg::EndRecord()
{
	m_pAudioSock->SetSockOpt(SO_SNDBUF,lpOutWaveHdr->lpData,4096);
	if (m_Change)
		m_pAudioSock->Send(lpInWaveHdr[0].lpData,4096);
	else
		m_pAudioSock->Send(lpInWaveHdr[1].lpData,4096);
	m_Change !=m_Change;
	StartRecord();
}
