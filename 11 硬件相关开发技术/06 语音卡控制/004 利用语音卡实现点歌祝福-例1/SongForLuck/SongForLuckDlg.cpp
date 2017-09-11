// SongForLuckDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SongForLuck.h"
#include "SongForLuckDlg.h"
#include "Tc08a32.h"
#include "NewSig.h"

#pragma comment(lib,"tc08a32")
#pragma comment(lib,"newsig")

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
// CSongForLuckDlg dialog

CSongForLuckDlg::CSongForLuckDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSongForLuckDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSongForLuckDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_ChanelCount = 0;
	m_Received    = FALSE;
	m_PressCh =  "";
	m_IsSong  = FALSE;
}

void CSongForLuckDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSongForLuckDlg)
	DDX_Control(pDX, IDC_LIST1, m_CardList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSongForLuckDlg, CDialog)
	//{{AFX_MSG_MAP(CSongForLuckDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSongForLuckDlg message handlers

BOOL CSongForLuckDlg::OnInitDialog()
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
	

	//加载驱动程序
	if (LoadDRV()!=0)
		MessageBox("加载驱动程序错误");
	
	//检查可用的通道数量
	m_ChanelCount = CheckValidCh();
	
	m_pChanel = new LINESTRUCT[m_ChanelCount];
	SetBusyPara(350);

	EnableCard(m_ChanelCount,1024*59);
	
	//设置列表扩展风格
	m_CardList.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT |LVS_EX_TWOCLICKACTIVATE);
	
	//添加列
	m_CardList.InsertColumn(1,"通道号",LVCFMT_LEFT,80);
	m_CardList.InsertColumn(2,"通道类型",LVCFMT_LEFT,80);
	m_CardList.InsertColumn(3,"状态",LVCFMT_LEFT,120);
	m_CardList.InsertColumn(4,"信息",LVCFMT_LEFT,180);

	CString convert;
	for (int i = 0; i<m_ChanelCount; i++)
	{
		convert.Format("%i",i);
		m_CardList.InsertItem(i,"");
		m_CardList.SetItemText(i,0,convert);
		WORD type = CheckChType(i);
		m_pChanel[i].RING = FALSE;
		m_pChanel[i].IsSong = FALSE;
		m_pChanel[i].Inited = FALSE;
		switch(type)
		{
		case 0: //内线
			{
				convert = "内线";
				break;
			}
		case 1: //外线
			{
				//m_Chanel.AddString(convert);
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
	SetDialPara(1000,2000,350,7);

	SetTimer(1,1,NULL);	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSongForLuckDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSongForLuckDlg::OnPaint() 
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
HCURSOR CSongForLuckDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSongForLuckDlg::OnCancel() 
{
	delete [] m_pChanel;	
	DisableCard();
	FreeDRV();

	CDialog::OnCancel();
}

char CSongForLuckDlg::ConvertToASCII(short ch)
{
	char c;

	switch(ch)
    {
		case 10:
			c = '0';
			break;
		case 11:
			c = '*';
			break;
		case 12:
			c = '#';
			break;
        case 13:
        case 14:
        case 15:
            c=ch-13+'a';
            break;
        case 0:
            c='d';
            break;
		default:
			c = ch + '0';
	}
	return c;
}

void CSongForLuckDlg::OnTimer(UINT nIDEvent) 
{
	PUSH_PLAY();
	FeedSigFunc();
	int result ;
	short code;
	for (int i=0; i< m_ChanelCount; i++)
	{
		StartSigCheck(i);

		//外线响铃
		if (RingDetect(i)&& CheckChType(i)==1)
		{
			m_pChanel[i].RING = TRUE;
		}

		if (m_pChanel[i].RING == TRUE)
		{
			if (m_pChanel[i].Inited==FALSE)
			{	
				OffHook(i);
				InitDtmfBuf(i);

				m_pChanel[i].Inited = TRUE;
				code = GetDtmfCode(i);
				return;
			}
		
			while((code = GetDtmfCode(i))!= -1)
			{
				m_PressCh.Insert(m_PressCh.GetLength(),ConvertToASCII(code));
				m_CardList.SetItemText(i,3,m_PressCh);
			}

			if ( m_pChanel[i].IsSong ==FALSE&& m_PressCh=="136")
			{
				m_pChanel[i].IsSong = TRUE;			
				StartPlayFile(i,"Welcomeold",0L);
			}
			
			if (m_IsSong ==TRUE  &&  CheckPlayEnd(i))
			{
				m_PressCh = "";
				m_pChanel[i].IsSong = FALSE;
				m_pChanel[i].RING = FALSE;
				m_pChanel[i].Inited = FALSE;
				m_CardList.SetItemText(i,3,m_PressCh);
				StopPlayFile(i);
			}
		}	
	}
	CDialog::OnTimer(nIDEvent);
}
