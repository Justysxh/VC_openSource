// SoundCardCallDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SoundCardCall.h"
#include "SoundCardCallDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#include "tc08a32.h"
#pragma comment (lib,"Tc08a32")

#include "NewSig.h"
#pragma comment (lib,"NewSig.lib")

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
// CSoundCardCallDlg dialog

CSoundCardCallDlg::CSoundCardCallDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSoundCardCallDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSoundCardCallDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_Chanels = 0;
	m_CurChanel = -1;
}


void CSoundCardCallDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSoundCardCallDlg)
	DDX_Control(pDX, IDC_PHONE, m_Number);
	DDX_Control(pDX, IDC_COMCHANEL, m_Chanel);
	DDX_Control(pDX, IDC_CARDLIST, m_CardList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSoundCardCallDlg, CDialog)
	//{{AFX_MSG_MAP(CSoundCardCallDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSoundCardCallDlg message handlers


BOOL CSoundCardCallDlg::OnInitDialog()
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
	

	//设置列表扩展风格
	m_CardList.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT |LVS_EX_TWOCLICKACTIVATE);
	
	//添加列
	m_CardList.InsertColumn(1,"通道号",LVCFMT_LEFT,80);
	m_CardList.InsertColumn(2,"通道类型",LVCFMT_LEFT,80);
	m_CardList.InsertColumn(3,"流程状态",LVCFMT_LEFT,120);
	m_CardList.InsertColumn(4,"号码",LVCFMT_LEFT,150);


	//加载驱动程序
	long result  = LoadDRV(); //0成功,
	if (result!=0)
	{
		MessageBox("加载驱动程序错误");
	}
	//检查合法的通道
	m_Chanels =  CheckValidCh();
	m_pLines = new LINESTRUCT[m_Chanels];
	//设置忙音0.35秒
	SetBusyPara(350);

		
	//初始化电话卡的硬件,并为每个通道分配语音缓冲区
	EnableCard(m_Chanels,1024*16); 
	CString convert;
	for (int i = 0; i<m_Chanels; i++)
	{
		m_pLines[i].State = CH_FREE;
		convert.Format("%i",i);
		m_CardList.InsertItem(i,"");
		m_CardList.SetItemText(i,0,convert);
		WORD type = CheckChType(i);
		m_pLines[i].nType = type ;

		switch(type)
		{
		case 0: //内线
			{
				convert = "内线";
				break;
			}
		case 1: //外线
			{
				m_Chanel.AddString(convert);
				convert = "外线";
				
				break;
			}
		case 2: //悬空
			{
				convert = "悬空";
				break;
			}
		
		}
		m_CardList.SetItemText(i,1,convert);
	}
	//初始化信号音函数
	Sig_Init(0);
	SetTimer(1,600,NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSoundCardCallDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSoundCardCallDlg::OnPaint() 
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
HCURSOR CSoundCardCallDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSoundCardCallDlg::OnOK() 
{
	
//	CDialog::OnOK();
}

void CSoundCardCallDlg::OnCancel()
{
	delete m_pLines;
	FreeDRV();
	CDialog::OnCancel();
}

void CSoundCardCallDlg::OnButton1() 
{
	CString str,number;
	m_Chanel.GetWindowText(str);
	m_Number.GetWindowText(number);
	m_CurNumber = number;
	if (str.IsEmpty()||number.IsEmpty())
		return;
	//外线摘机
	m_CurChanel = atoi(str);
	OffHook(atoi(str));
	Sig_StartDial(atoi(str),number.GetBuffer(0),"",0);
	m_pLines[atoi(str)].State=CH_DIAL;
}

void CSoundCardCallDlg::OnTimer(UINT nIDEvent) 
{
	//维持断续振铃及信号音的函数
	PUSH_PLAY();
	FeedSigFunc();

	int result ;
	for (int i=0; i<m_Chanels;i++)
	{
		if (m_pLines[i].State==CH_FREE)
		{
			m_CardList.SetItemText(i,2,"空闲");
			m_CardList.SetItemText(i,3,"");
		}	
		switch(m_pLines[i].State)
		{
		case CH_DIAL:
			{
				m_CardList.SetItemText(i,2,"检测信号音");
				m_CardList.SetItemText(i,3,m_CurNumber);
				//检测某路DTMF发送是否结束,为1,以发送完毕,可以开始信号音检测
				if (CheckSendEnd(i)==1)
				{
					StartSigCheck(i);
					m_pLines[i].State=CH_CHECKSIG;
				}
				break;
			}
		case CH_CHECKSIG:
			{
				int tt = Sig_CheckDial(i);
				if(tt == S_BUSY)
				{
					m_pLines[i].State = CH_BUSY;
				}
				else if(tt == S_CONNECT)
				{
					m_pLines[i].State = CH_CONNECT;
				}
				else if(tt == S_NOSIGNAL)
				{
					m_pLines[i].State= CH_NOSIGNAL;
				}
				else if(tt == S_NOBODY)
				{
					m_pLines[i].State= CH_NOBODY;
				}
				else if(tt == S_NODIALTONE)
				{
					m_pLines[i].State= CH_NODIALTONE;
				}
				break;
			}
		case CH_NODIALTONE: //没有信号音
		case CH_NOSIGNAL:   //没有信号
		case CH_BUSY:       //对方占线(检测到忙音)
			{
				OnButton2();
				break;
			}
		}	
	}
	CDialog::OnTimer(nIDEvent);
}

void CSoundCardCallDlg::OnButton2() 
{
	HangUp(m_CurChanel);
	Sig_ResetCheck(m_CurChanel);
	StartSigCheck(m_CurChanel);
	m_pLines[m_CurChanel].State = CH_FREE;
}
