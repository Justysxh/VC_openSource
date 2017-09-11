// SongManageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SongManage.h"
#include "SongManageDlg.h"

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
// CSongManageDlg dialog

CSongManageDlg::CSongManageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSongManageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSongManageDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSongManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSongManageDlg)
	DDX_Control(pDX, IDC_WHISHT, m_Whisht);
	DDX_Control(pDX, IDC_SETVOLUMN, m_SetVolumn);
	DDX_Control(pDX, IDC_SONGLIST, m_SongList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSongManageDlg, CDialog)
	//{{AFX_MSG_MAP(CSongManageDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_SPEED, OnSpeed)
	ON_BN_CLICKED(IDC_BACK, OnBack)
	ON_BN_CLICKED(IDC_PAUSE, OnPause)
	ON_BN_CLICKED(IDC_TERMINAL, OnTerminal)
	ON_BN_CLICKED(IDC_QUIT, OnQuit)
	ON_BN_CLICKED(IDC_LEFTWAV, OnLeftwav)
	ON_BN_CLICKED(IDC_RIGHTWAVE, OnRightwave)
	ON_BN_CLICKED(IDC_SOLIDWAVE, OnSolidwave)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SETVOLUMN, OnReleasedcaptureSetvolumn)
	ON_BN_CLICKED(IDC_WHISHT, OnWhisht)
	ON_BN_CLICKED(IDC_TV, OnTv)
	ON_BN_CLICKED(IDC_VGA, OnVga)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSongManageDlg message handlers

BOOL CSongManageDlg::OnInitDialog()
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
	//
	m_Play.SetAutoCloseDriver(FALSE);
	m_Play.SetSerialString("0F7CFC6CF7FE");
	m_Play.SetVolume(21);
	if (m_Play.OpenDriver()==FALSE)
	{
		MessageBox("连接驱动程序错误","提示",64);
	}

	m_SetVolumn.SetRangeMax(100);
	m_SetVolumn.SetRangeMin(0);

	
	//设置列表扩展风格
	m_SongList.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_TWOCLICKACTIVATE);
	
	//向列表中添加数据
	m_SongList.InsertColumn(1,"歌曲名称",LVCFMT_CENTER,120);
	m_SongList.InsertColumn(2,"原唱",LVCFMT_CENTER,80);
	m_SongList.InsertColumn(3,"类型",LVCFMT_CENTER,80);
	m_SongList.SetTextColor(RGB(255,0,0));

	m_SongList.InsertItem(0,"");
	m_SongList.SetItemText(0,0,"蝶儿蝶儿满天飞");
	m_SongList.SetItemText(0,1,"高胜美");
	m_SongList.SetItemText(0,2,"DAT");

	m_SongList.InsertItem(1,"");
	m_SongList.SetItemText(1,0,"别来无恙");
	m_SongList.SetItemText(1,1,"张宇");
	m_SongList.SetItemText(1,2,"DAT");

	m_SongList.InsertItem(2,"");
	m_SongList.SetItemText(2,0,"好男人");
	m_SongList.SetItemText(2,1,"张镐哲");
	m_SongList.SetItemText(2,2,"DAT");

	m_SongList.InsertItem(3,"");
	m_SongList.SetItemText(3,0,"爱你的宿命");
	m_SongList.SetItemText(3,1,"迪克牛仔");
	m_SongList.SetItemText(3,2,"DAT");

	m_SongList.InsertItem(4,"");
	m_SongList.SetItemText(4,0,"不再伤痛");
	m_SongList.SetItemText(4,1,"小刚");
	m_SongList.SetItemText(4,2,"DAT");

	m_SongList.InsertItem(5,"");
	m_SongList.SetItemText(5,0,"明明知道相思苦");
	m_SongList.SetItemText(5,1,"黄安");
	m_SongList.SetItemText(5,2,"DAT");

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSongManageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSongManageDlg::OnPaint() 
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
HCURSOR CSongManageDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSongManageDlg::OnOK() 
{
	
}

//	播放
void CSongManageDlg::OnPlay() 
{
	CString str;
	int currow = m_SongList.GetSelectionMark();
	if (currow != -1)
	{
		m_Play.Stop();
		str = m_SongList.GetItemText(currow,0);
		str+=".dat";
		m_Play.SetFilename(str);
		m_Play.Play();
	}
}

//快进
void CSongManageDlg::OnSpeed() 
{
	m_Play.SetCurrentFrame(m_Play.GetCurrentFrame()+125);	
}
//快退
void CSongManageDlg::OnBack() 
{
	m_Play.SetCurrentFrame(m_Play.GetCurrentFrame()-125);	
}
//暂停
void CSongManageDlg::OnPause() 
{
	m_Play.Pause();
}
//停止
void CSongManageDlg::OnTerminal() 
{
	m_Play.Stop();	
}

void CSongManageDlg::OnQuit() 
{
	OnCancel();	
}
//左声道
void CSongManageDlg::OnLeftwav() 
{
	m_Play.SetAudioChannel(0);
}
//右声道
void CSongManageDlg::OnRightwave() 
{
	m_Play.SetAudioChannel(1);	
}
//立体声
void CSongManageDlg::OnSolidwave() 
{
	m_Play.SetAudioChannel(2);	
}

void CSongManageDlg::OnReleasedcaptureSetvolumn(NMHDR* pNMHDR, LRESULT* pResult) 
{
	m_Play.SetVolume(m_SetVolumn.GetPos());	
	*pResult = 0;
}

void CSongManageDlg::OnWhisht() 
{
	m_Play.SetMute(m_Whisht.GetCheck());	
}

void CSongManageDlg::OnTv() 
{
	m_Play.SetDisplayDevice(0);
}

void CSongManageDlg::OnVga() 
{
	m_Play.SetDisplayDevice(1);	
}
