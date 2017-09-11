// FingerExerciseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FingerExercise.h"
#include "FingerExerciseDlg.h"

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
// CFingerExerciseDlg dialog

CFingerExerciseDlg::CFingerExerciseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFingerExerciseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFingerExerciseDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFingerExerciseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFingerExerciseDlg)
	DDX_Control(pDX, IDC_BUTCANCEL, m_Cancel);
	DDX_Control(pDX, IDC_BUTEXIT, m_Exit);
	DDX_Control(pDX, IDC_BUTSTART, m_Start);
	DDX_Control(pDX, IDC_ALTERNATION, m_Alternation);
	DDX_Control(pDX, IDC_TIMING, m_Timing);
	DDX_Control(pDX, IDC_SUMNUM, m_sNum);
	DDX_Control(pDX, IDC_VERACITY, m_Veracity);
	DDX_Control(pDX, IDC_TIME, m_uTime);
	DDX_Control(pDX, IDC_RATE, m_Rate);
	DDX_Control(pDX, IDC_LOSENUM, m_lNum);
	DDX_Control(pDX, IDC_ERRORNUM, m_eNum);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFingerExerciseDlg, CDialog)
	//{{AFX_MSG_MAP(CFingerExerciseDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTSTART, OnButstart)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTEXIT, OnButexit)
	ON_BN_CLICKED(IDC_BUTCANCEL, OnButcancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFingerExerciseDlg message handlers

BOOL CFingerExerciseDlg::OnInitDialog()
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
	Initialization();
	for(int i=0;i<10;i++)
	{
		m_Static[i].Create("",WS_CHILD|WS_CLIPSIBLINGS|
			WS_EX_TOOLWINDOW|SS_BITMAP,CRect(0,0,50,50),this,1230+i);
	}
	m_Start.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
	MAKEINTRESOURCE(IDB_START))); //设置位图
	m_Cancel.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
	MAKEINTRESOURCE(IDB_CANCEL))); //设置位图
	m_Exit.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
	MAKEINTRESOURCE(IDB_EXIT))); //设置位图

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFingerExerciseDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFingerExerciseDlg::OnPaint() 
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
HCURSOR CFingerExerciseDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFingerExerciseDlg::OnButstart() 
{
	// TODO: Add your control notification handler code here
	m_Error = 0;
	m_Sum = 0;
	m_Lose = 0;
	m_Time = 0;
	CString time;
	m_Timing.GetWindowText(time);
	m_iTime = atoi(time)*60;
	m_Alternation.GetWindowText(time);
	m_aTime = atoi(time);
	RandLetter();
	for(int i=0;i<10;i++)
	{
		SetBitmap(i);
	}
	m_IsStart = TRUE;
	SetTimer(1,m_aTime,NULL);
	SetTimer(2,1000,NULL);
}

void CFingerExerciseDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent == 1)
	{
		for(int i=0;i<10;i++)
		{
			CRect rect;
			m_Static[i].GetClientRect(rect);
			m_Static[i].MapWindowPoints(this,rect);
			if(rect.bottom == 495)
			{
				m_Lose++;
				srand(m_Num[i]*i+m_Num[i]+i);
				m_Num[i] = rand()%26+1;
				SetBitmap(i);
				rect.top = 21;
				rect.bottom = 45;
			}
			else
			{
				rect.top += 30;
				rect.bottom += 30;
			}
			m_Static[i].MoveWindow(rect);
		}
	}
	else if(nIDEvent == 2)
	{
		if(m_Time == m_iTime)
		{
			m_IsStart = FALSE;
			KillTimer(1);
			KillTimer(2);
			CString str;
			str.Format("╔═════════════════╗\r\n║ 时间：%02d分%02d秒 ║ 打字数： %03d个 ║\r\n║ 错误数： %03d个 ║ 漏打数： %03d个 ║\r\n║ 正确率： %0.0f%%  ║ 速度：%03d个/分 ║\r\n╚═════════════════╝"
				,m_Time/60,m_Time%60,m_Sum,m_Error,m_Lose,(m_Sum-m_Error)*1.0/m_Sum*100,m_Sum*60/m_Time);
			MessageBox(str);
			for(int i=0;i<10;i++)
				m_Static[i].ShowWindow(SW_HIDE);
		}
		else
		{
			m_Time++;
			CString str;
			str.Format("时间：%d分%d秒",m_Time/60,m_Time%60);
			m_uTime.SetWindowText(str);
			str.Format("打字数：%d个",m_Sum);
			m_sNum.SetWindowText(str);
			str.Format("错误数：%d个",m_Error);
			m_eNum.SetWindowText(str);
			str.Format("漏打数：%d个",m_Lose);
			m_lNum.SetWindowText(str);
			str.Format("正确率：%0.0f%%",(m_Sum-m_Error)*1.0/m_Sum*100);
			m_Veracity.SetWindowText(str);
			str.Format("速度：%d个/分",m_Sum*60/m_Time);
			m_Rate.SetWindowText(str);
		}
	}
	CDialog::OnTimer(nIDEvent);
}

void CFingerExerciseDlg::RandLetter()
{
	CTime time = CTime::GetCurrentTime();
	srand(time.GetHour()+time.GetMinute()+time.GetSecond());
	for(int i=0;i<10;i++)
	{
		m_Num[i] = rand()%26+1;
	}
}

BOOL CFingerExerciseDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_IsStart)
	{
		if(pMsg->message == WM_KEYDOWN)
		{
			BOOL IsNum=FALSE;
			for(int i=0;i<26;i++)
			{
				if(pMsg->wParam == 0x0041+i)
				{
					for(int j=0;j<10;j++)
					{
						if(m_Num[j] == i+1)
						{
							CRect rect;
							m_Static[j].GetClientRect(rect);
							m_Static[j].MapWindowPoints(this,rect);
							srand(m_Num[j]*j*i+m_Num[j]+j+i);
							m_Num[j] = rand()%26+1;
							SetBitmap(j);
							rect.top = 21;
							rect.bottom = 45;
							m_Static[j].MoveWindow(rect);
							IsNum = TRUE;
						}
					}
				}
			}
			if(!IsNum)
				m_Error++;
			m_Sum++;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

HBRUSH CFingerExerciseDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	CBitmap m_BK;
	m_BK.LoadBitmap(IDB_BITMAPBK);
	if (nCtlColor == CTLCOLOR_DLG)
	{
		//定义一个位图画刷
		CBrush m_Brush(&m_BK);
		CRect rect;
		GetClientRect(rect);
		//选中画刷
		pDC->SelectObject(&m_Brush);
		//填充客户区域
		pDC->FillRect(rect,&m_Brush);
		return m_Brush;
	}
	else
		hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if(nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetBkMode(TRANSPARENT);
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CFingerExerciseDlg::SetBitmap(int num)
{
	HBITMAP m_hBitmap;
	m_hBitmap = LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAPA+m_Num[num]-1));
	m_Static[num].SetBitmap(m_hBitmap);
	m_Static[num].MoveWindow(45+58*num,21,24,24);
	m_Static[num].ShowWindow(SW_SHOW);
}

void CFingerExerciseDlg::OnButexit() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

void CFingerExerciseDlg::OnButcancel() 
{
	// TODO: Add your control notification handler code here
	KillTimer(1);
	KillTimer(2);
	for(int i=0;i<10;i++)
		m_Static[i].ShowWindow(SW_HIDE);
	Initialization();
}

void CFingerExerciseDlg::Initialization()
{
	m_IsStart = FALSE;
	m_uTime.SetWindowText("时间：0分0秒");
	m_sNum.SetWindowText("打字数：0个");
	m_eNum.SetWindowText("错误数：0个");
	m_lNum.SetWindowText("漏打数：0个");
	m_Veracity.SetWindowText("正确率：0.0%");
	m_Rate.SetWindowText("速度：0个/分");
	m_Timing.SetWindowText("3");
	m_Alternation.SetWindowText("500");
}
