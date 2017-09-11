// PictureGameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PictureGame.h"
#include "PictureGameDlg.h"
#include "HelpDlg.h"
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
// CPictureGameDlg dialog

CPictureGameDlg::CPictureGameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPictureGameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPictureGameDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_Path = "";
}

void CPictureGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPictureGameDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPictureGameDlg, CDialog)
	//{{AFX_MSG_MAP(CPictureGameDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_MENUEASY, OnMenueasy)
	ON_COMMAND(ID_MENUMID, OnMenumid)
	ON_COMMAND(ID_MENUHARD, OnMenuhard)
	ON_COMMAND(ID_MENUCUSTOM, OnMenucustom)
	ON_COMMAND(ID_MENUHELP, OnMenuhelp)
	ON_COMMAND(ID_MENUSTART, OnMenustart)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	ON_COMMAND(ID_MENUBMP1, OnMenubmp1)
	ON_COMMAND(ID_MENUBMP2, OnMenubmp2)
	ON_COMMAND(ID_MENUBMP3, OnMenubmp3)
	ON_COMMAND(ID_MENUEXIT, OnMenuexit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPictureGameDlg message handlers

BOOL CPictureGameDlg::OnInitDialog()
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
	::GetCurrentDirectory(256,buf); //获取程序根目录路径
	m_bExpand = false;
	m_win = false;
	UINT array[5];
	for (int i=0;i<5;i++)
	{
		array[i] = 1001+i;
	}
	m_statusbar.Create(this); //创建状态栏窗口
	m_statusbar.SetIndicators(array,sizeof(array)/sizeof(UINT)); //添加面板
	for (int n = 0; n<4;n++)
	{
		m_statusbar.SetPaneInfo(n,array[n],0,155);//设置面板宽度
	}
	m_statusbar.SetPaneInfo(3,array[3],0,700);	
	CTime time;
	time=time.GetCurrentTime();
	CString stime;
	stime.Format("当前时间：%s",time.Format("%y-%m-%d %H:%M:%S"));
	m_statusbar.SetPaneText(0,stime);
	tm = 0;
	Gtime.Format("游戏时间：%d",tm);
	m_statusbar.SetPaneText(1,Gtime);
	m_statusbar.SetPaneText(2,"加油!");
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);

	CRect rcDlg, rcMarker;
	GetWindowRect(rcDlg);
	m_nExpandedWidth = rcDlg.Width();
	GetDlgItem(IDC_COMPART)->GetWindowRect(rcMarker);
	m_nNormalWidth = (rcMarker.left - rcDlg.left);
	Display();
	for(int j=0;j<64;j++)
	{
		Picture[j].Create("",WS_CHILD|WS_CLIPSIBLINGS|WS_EX_TOOLWINDOW|WS_BORDER,
			CRect(0,0,48,48),this,1200+i);
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPictureGameDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPictureGameDlg::OnPaint() 
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
	CDC* pDC = GetDC();
	if (m_Grade == "Easy")
	{
		for(int i=0;i<16;i++)
		{
			pDC->Rectangle(arrays[i].x,arrays[i].y,arrays[i+100].x,arrays[i+100].y);
			pDC->Rectangle(cpoint[i].x,cpoint[i].y,cpoint[i+100].x,cpoint[i+100].y);
		}
		ShowPicture(4,120);
	}
	else if(m_Grade == "Mid")
	{
		for(int i=0;i<36;i++)
		{
			pDC->Rectangle(arrays[i].x,arrays[i].y,arrays[i+100].x,arrays[i+100].y);
			pDC->Rectangle(cpoint[i].x,cpoint[i].y,cpoint[i+100].x,cpoint[i+100].y);
		}
		ShowPicture(6,80);
	}
	else if(m_Grade == "Hard")
	{
		for(int i=0;i<64;i++)
		{
			pDC->Rectangle(arrays[i].x,arrays[i].y,arrays[i+100].x,arrays[i+100].y);
			pDC->Rectangle(cpoint[i].x,cpoint[i].y,cpoint[i+100].x,cpoint[i+100].y);
		}
		ShowPicture(8,60);
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPictureGameDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPictureGameDlg::OnMenueasy() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
	tm = 0;
	Gtime.Format("游戏时间：%d",tm);
	m_statusbar.SetPaneText(1,Gtime);
	m_bExpand=false;
	Display();
	m_Grade = "Easy";
	SetGrade(m_Grade);
}

void CPictureGameDlg::OnMenumid() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
	tm = 0;
	Gtime.Format("游戏时间：%d",tm);
	m_statusbar.SetPaneText(1,Gtime);
	m_bExpand=false;
	Display();
	m_Grade = "Mid";
	SetGrade(m_Grade);
}

void CPictureGameDlg::OnMenuhard() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
	tm = 0;
	Gtime.Format("游戏时间：%d",tm);
	m_statusbar.SetPaneText(1,Gtime);
	m_bExpand=false;
	Display();
	m_Grade = "Hard";
	SetGrade(m_Grade);
}

void CPictureGameDlg::SetGrade(CString Grade)
{
	if(Grade == "Easy")
	{
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				CRect rect(0+j*120,0+i*120,120+j*120,120+i*120);
				Picture[j+i*4].MoveWindow(&rect);
				Picture[j+i*4].ShowWindow(SW_SHOW);
				arrays[j+i*4].x = 0+j*120;
				arrays[j+i*4].y = 0+i*120;
				arrays[100+j+i*4].x = 120+j*120;
				arrays[100+j+i*4].y = 120+i*120;
			}
		}
		ShowPicture(4,120);
		for(i=16;i<64;i++)
		{
			Picture[i].ShowWindow(SW_HIDE);
			Picture[i].EnableWindow(false);
		}
	}
	else if(Grade == "Mid")
	{
		for(int i=0;i<6;i++)
		{
			for(int j=0;j<6;j++)
			{
				CRect rect(0+j*80,0+i*80,80+j*80,80+i*80);
				Picture[j+i*6].MoveWindow(&rect);
				Picture[j+i*6].ShowWindow(SW_SHOW);
				arrays[j+i*6].x = 0+j*80;
				arrays[j+i*6].y = 0+i*80;
				arrays[100+j+i*6].x = 80+j*80;
				arrays[100+j+i*6].y = 80+i*80;
			}
		}
		ShowPicture(6,80);
		for(i=36;i<64;i++)
		{
			Picture[i].ShowWindow(SW_HIDE);
			Picture[i].EnableWindow(false);
		}
	}
	else if(Grade == "Hard")
	{
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				CRect rect(0+j*60,0+i*60,60+j*60,60+i*60);
				Picture[j+i*8].MoveWindow(&rect);
				Picture[j+i*8].ShowWindow(SW_SHOW);
				arrays[j+i*8].x = 0+j*60;
				arrays[j+i*8].y = 0+i*60;
				arrays[100+j+i*8].x = 60+j*60;
				arrays[100+j+i*8].y = 60+i*60;
			}
		}
		ShowPicture(8,60);
	}
}

void CPictureGameDlg::ShowPicture(int m,int n)
{
	HBITMAP m_hBitmap;
	m_hBitmap=(HBITMAP)::LoadImage(AfxGetInstanceHandle(),m_Path,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTCOLOR|LR_DEFAULTSIZE);	
	int x=0,y=0,i=0,j=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			CDC* pDC = Picture[j+i*m].GetDC();
			//将位图选进设备场景中
			CDC memdc;	
			memdc.CreateCompatibleDC( pDC );
			memdc.SelectObject(m_hBitmap);
			BITMAP bmp;
			GetObject(m_hBitmap,sizeof(bmp),&bmp);	
			x = bmp.bmWidth/m;
			y = bmp.bmHeight/m;
			pDC->StretchBlt(0,0,n,n,&memdc,x*j,y*i,x,y,SRCCOPY);
			pDC->Draw3dRect(0,0,n,n,RGB(0,0,0),RGB(0,0,0));
			memdc.DeleteDC();
			UpdateWindow();
		}
	}
	CDC* pDC = Picture[0].GetDC();
	//将位图选进设备场景中
	CDC memdc;	
	memdc.CreateCompatibleDC( pDC );
	memdc.SelectObject(m_hBitmap);
	pDC->StretchBlt(0,0,n,n,&memdc,0,0,x,y,SRCCOPY);
	pDC->Draw3dRect(0,0,n,n,RGB(0,0,0),RGB(0,0,0));
	memdc.DeleteDC();
	UpdateWindow();
}

void CPictureGameDlg::OnMenucustom() 
{
	// TODO: Add your command handler code here
	CFileDialog dlg (true,"bmp",NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"位图文件(*.bmp)|*.bmp",this);
	if (dlg.DoModal()==IDOK)
	{
		m_Path = dlg.GetPathName();
		m_Grade = "Easy";
		SetGrade(m_Grade);
	}
}

void CPictureGameDlg::OnMenuhelp() 
{
	// TODO: Add your command handler code here
	if(m_Path.IsEmpty())
	{
		MessageBox("请选择图片!");
		return;
	}
	CHelpDlg dlg;
	dlg.m_Path = m_Path;
	dlg.DoModal();
}

void CPictureGameDlg::RandPlace(int a,int b)
{
	
	int num[100];
	int n,m=0,k=1;
	num[0] = rand()%(a*a);
	while(k != (a*a))
	{
		n = rand()%(a*a);
		for(int i=0;i<k;i++)
		{
			if(num[i] == n)
			{
				m = 1;
			}
		}
		if(m == 0)	
		{
			k++;
			num[k-1] = n;
		}
		m = 0;
	}
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<a;j++)
		{
			cpoint[j+i*a].x = 490+j*b;
			cpoint[j+i*a].y = 0+i*b;
			cpoint[100+j+i*a].x = 490+b+j*b;
			cpoint[100+j+i*a].y = b+i*b;
		}
	}
	for(i=0;i<(a*a);i++)
	{
		int p;
		p = num[i];
		CRect rect;
		rect.left = cpoint[p].x;
		rect.top = cpoint[p].y;
		rect.right = cpoint[100+p].x;
		rect.bottom = cpoint[100+p].y;
		Picture[i].MoveWindow(&rect);
	}
}

void CPictureGameDlg::OnMenustart() 
{
	// TODO: Add your command handler code here
	if(m_Path.IsEmpty())
	{
		MessageBox("请选择图片!");
		return;
	}
	tm = 0;
	SetTimer(1,1000,NULL);
	m_bExpand = true;
	m_win = true;
	Display();
	CDC* pDC = GetDC();
	if (m_Grade == "Easy")
	{
		RandPlace(4,120);
		for(int i=0;i<16;i++)
		{
			pDC->Rectangle(arrays[i].x,arrays[i].y,arrays[i+100].x,arrays[i+100].y);
		}
	}
	else if(m_Grade == "Mid")
	{
		RandPlace(6,80);
		for(int i=0;i<36;i++)
		{
			pDC->Rectangle(arrays[i].x,arrays[i].y,arrays[i+100].x,arrays[i+100].y);
		}
	}
	else if(m_Grade == "Hard")
	{
		RandPlace(8,60);
		for(int i=0;i<64;i++)
		{
			pDC->Rectangle(arrays[i].x,arrays[i].y,arrays[i+100].x,arrays[i+100].y);
		}
	}
}

void CPictureGameDlg::Display()
{
	CRect rcDlg;
	GetWindowRect(rcDlg);
	if (m_bExpand)
	{
		rcDlg.SetRect( rcDlg.left, rcDlg.top, 
		rcDlg.left + m_nExpandedWidth,
		rcDlg.top + rcDlg.Height());
	}
	else
	{
		rcDlg.SetRect(rcDlg.left, rcDlg.top, 
		rcDlg.left + m_nNormalWidth,
		rcDlg.top + rcDlg.Height());
	}
	MoveWindow(rcDlg, true);
}

void CPictureGameDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rect;
	int num;
	if (m_Grade == "Easy")
		num = 16;
	else if(m_Grade == "Mid")
		num = 36;
	else if(m_Grade == "Hard")
		num = 64;
	for(int i=0;i<num;i++)
	{
		Picture[i].GetClientRect(&rect);
		Picture[i].MapWindowPoints(this,&rect);
		if (rect.PtInRect(point))
		{
			m_num = i;
		}
	}
	CDialog::OnLButtonDown(nFlags, point);
}

void CPictureGameDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_win)
	{	
		int num;
		if (m_Grade == "Easy")
			num = 16;
		else if(m_Grade == "Mid")
			num = 36;
		else if(m_Grade == "Hard")
			num = 64;
		for(int i=0;i<num;i++)
		{
			CRect rect;
			rect.left = arrays[i].x;
			rect.top = arrays[i].y;
			rect.right = arrays[i+100].x;
			rect.bottom = arrays[i+100].y;
			if(rect.PtInRect(point))
			{
				Picture[m_num].MoveWindow(&rect);
			}
			rect.left = cpoint[i].x;
			rect.top = cpoint[i].y;
			rect.right = cpoint[i+100].x;
			rect.bottom = cpoint[i+100].y;
			if(rect.PtInRect(point))
			{
				Picture[m_num].MoveWindow(&rect);
			}
		}

		CRect rect;
		int sum=0;
		for(i=0;i<num;i++)
		{
			Picture[i].GetClientRect(&rect);
			Picture[i].MapWindowPoints(this,&rect);
			if(rect.left == arrays[i].x+1 && rect.top == arrays[i].y+1)
				sum++;
		}
		if(num == sum)
		{
			KillTimer(1);
			m_bExpand=false;
			Display();
			CString win;
			win.Format("胜利!\n游戏时间：%d秒",tm);
			m_win = false;
			MessageBox(win);
			return;
		}
	}
	CDialog::OnLButtonUp(nFlags, point);
}

void CPictureGameDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	tm++;
	Gtime.Format("游戏时间：%d",tm);
	m_statusbar.SetPaneText(1,Gtime);
	CDialog::OnTimer(nIDEvent);
}

void CPictureGameDlg::OnMenubmp1() 
{
	// TODO: Add your command handler code here
	CString str;
	str = buf;
	str = str + "\\res\\01.bmp";
	m_Path = str;
	m_Grade = "Easy";
	SetGrade(m_Grade);
}

void CPictureGameDlg::OnMenubmp2() 
{
	// TODO: Add your command handler code here
	CString str;
	str = buf;
	str = str + "\\res\\02.bmp";
	m_Path = str;
	m_Grade = "Easy";
	SetGrade(m_Grade);
}

void CPictureGameDlg::OnMenubmp3() 
{
	// TODO: Add your command handler code here
	CString str;
	str = buf;
	str = str + "\\res\\03.bmp";
	m_Path = str;
	m_Grade = "Easy";
	SetGrade(m_Grade);
}

void CPictureGameDlg::OnMenuexit() 
{
	// TODO: Add your command handler code here
	CDialog::OnCancel();
}
