// PhoneRecordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PhoneRecord.h"
#include "PhoneRecordDlg.h"

#include "Tc08a32.h"
#include "Newsig.h"

#pragma comment (lib,"Tc08a32.lib")
#pragma comment (lib,"NewSig.lib")

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
// CPhoneRecordDlg dialog

CPhoneRecordDlg::CPhoneRecordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPhoneRecordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPhoneRecordDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_IsOffHook = TRUE;
	m_Num =0;
}

void CPhoneRecordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPhoneRecordDlg)
	DDX_Control(pDX, IDC_LIST1, m_CardList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPhoneRecordDlg, CDialog)
	//{{AFX_MSG_MAP(CPhoneRecordDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPhoneRecordDlg message handlers

BOOL CPhoneRecordDlg::OnInitDialog()
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
	
	SetPackRate(PACK_32KBPS);
	//初始化信号音函数
	Sig_Init(0);
	//SetDialPara(1000,2000,350,7);


	SetTimer(1,1,NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPhoneRecordDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPhoneRecordDlg::OnPaint() 
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
HCURSOR CPhoneRecordDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPhoneRecordDlg::OnOK() 
{

}

void CPhoneRecordDlg::OnCancel()
{
	DisableCard();
	FreeDRV();
	CDialog::OnCancel();
}

void CPhoneRecordDlg::OnTimer(UINT nIDEvent) 
{
	PUSH_PLAY();
	FeedSigFunc();	
	CString sfile;
	switch(nIDEvent)
	{
	case 1:
		for (int i = 0; i< m_ChanelCount; i++)
		{
			if (RingDetect(i)&&CheckChType(i)==1) //外线
			{
				m_CardList.SetItemText(i,2,"来电话了");					
				//摘机,开始录音
				OffHook(i);
				StartSigCheck(i);
				//对方没有挂机
				if (ReadCheckResult(i,RECORD_CHECK)!= R_BUSY)
				{
					if (m_IsOffHook==TRUE)
					{	
						m_IsOffHook = FALSE;
						sfile.Format("c:\\%i.vol",i);
						m_CardList.SetItemText(i,3,sfile);
						StartRecordFile(i,sfile.GetBuffer(0),600*1024);
					}
				}
				else
				{
					StopRecordFile(i);
					m_IsOffHook = TRUE;
					Sig_ResetCheck(i);
				}
				if(CheckRecordEnd(i))
				{
					StopRecordFile(i);
					m_IsOffHook = TRUE;
				}			
			}	
		}
		break;
	}
	CDialog::OnTimer(nIDEvent);
}
