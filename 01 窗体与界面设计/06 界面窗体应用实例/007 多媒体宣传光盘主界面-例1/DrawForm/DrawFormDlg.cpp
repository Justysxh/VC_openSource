// DrawFormDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DrawForm.h"
#include "DrawFormDlg.h"

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
// CDrawFormDlg dialog

CDrawFormDlg::CDrawFormDlg(CWnd* pParent /*=NULL*/)
	: m_IsDrawForm (FALSE),m_ButtonState(bsNone), CDialog(CDrawFormDlg::IDD, pParent)
{
	m_FirstShow = FALSE;
	m_IsMax = TRUE;
	m_CapitonColor =RGB(0,0,255);
	m_Caption = "系统登录";
	//{{AFX_DATA_INIT(CDrawFormDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDrawFormDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDrawFormDlg)
	DDX_Control(pDX, IDC_STATIC2, m_label2);
	DDX_Control(pDX, IDC_STATIC1, m_label1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDrawFormDlg, CDialog)
	//{{AFX_MSG_MAP(CDrawFormDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_NCACTIVATE()
	ON_WM_ACTIVATE()
	ON_WM_NCMOUSEMOVE()
	ON_WM_NCPAINT()
	ON_WM_NCLBUTTONDOWN()
	ON_WM_CREATE()
	ON_WM_SHOWWINDOW()
	ON_WM_CTLCOLOR()
	ON_WM_NCLBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_WM_WINDOWPOSCHANGED()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawFormDlg message handlers

BOOL CDrawFormDlg::OnInitDialog()
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

	m_BorderHeight = GetSystemMetrics(SM_CYBORDER);
	m_BorderWidth = GetSystemMetrics(SM_CXBORDER);
	m_CaptionHeight = GetSystemMetrics(SM_CYCAPTION);	

	//获取按钮位图大小
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP6);
	BITMAPINFO bInfo;
	bitmap.GetObject(sizeof(bInfo),&bInfo);
	m_ButtonWidth = bInfo.bmiHeader.biWidth;
	m_ButtonHeight = bInfo.bmiHeader.biHeight;
	bitmap.DeleteObject();

	CRect rect;
	GetClientRect(rect);

	m_IniRect.CopyRect(CRect(8,(m_CaptionHeight+3*m_BorderHeight -m_ButtonHeight)/2,m_ButtonWidth,m_ButtonHeight));
	m_MinRect.CopyRect(CRect(rect.Width()-45,(m_CaptionHeight+2*m_BorderHeight -m_ButtonHeight)/2,m_ButtonWidth,m_ButtonHeight));
	m_MaxRect.CopyRect(CRect(rect.Width()-32,(m_CaptionHeight+2*m_BorderHeight -m_ButtonHeight)/2,m_ButtonWidth,m_ButtonHeight));
	m_CloseRect.CopyRect(CRect(rect.Width()-19,(m_CaptionHeight+2*m_BorderHeight -m_ButtonHeight)/2,m_ButtonWidth,m_ButtonHeight));

	m_CaptionFont.CreateFont(14,10,0,0,600,0,0,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,FF_ROMAN,"宋体");
	
	DrawForm();

	m_label1.ModifyStyleEx(0,WS_EX_TRANSPARENT);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDrawFormDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDrawFormDlg::OnPaint() 
{
		CRect rect;
		GetClientRect(&rect);
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);

		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
	DrawForm();
	m_IsDrawForm = TRUE;



}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDrawFormDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDrawFormDlg::OnOK() 
{
	
//CDialog::OnOK();
}

void CDrawFormDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);

	CRect rect;
	GetClientRect(rect);

	m_IniRect.CopyRect(CRect(8,(m_CaptionHeight+3*m_BorderHeight -m_ButtonHeight)/2,m_ButtonWidth,m_ButtonHeight));
	m_MinRect.CopyRect(CRect(rect.Width()-45,(m_CaptionHeight+2*m_BorderHeight -m_ButtonHeight)/2,m_ButtonWidth,m_ButtonHeight));
	m_MaxRect.CopyRect(CRect(rect.Width()-32,(m_CaptionHeight+2*m_BorderHeight -m_ButtonHeight)/2,m_ButtonWidth,m_ButtonHeight));
	m_CloseRect.CopyRect(CRect(rect.Width()-19,(m_CaptionHeight+2*m_BorderHeight -m_ButtonHeight)/2,m_ButtonWidth,m_ButtonHeight));
	
	Invalidate();
	//Update();

}

BOOL CDrawFormDlg::OnNcActivate(BOOL bActive) 
{
	OnPaint() ;
	return CDialog::OnNcActivate(bActive);
}

void CDrawFormDlg::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) 
{
	CDialog::OnActivate(nState, pWndOther, bMinimized);
	OnPaint() ;	
}

void CDrawFormDlg::OnNcMouseMove(UINT nHitTest, CPoint point) 
{
	CDialog::OnNcMouseMove(nHitTest, point);
	CRect tempIni,tempMin,tempMax,tempClose,ClientRect;
	
	CDC* pWindowDC = GetWindowDC();
	CDC memDC;
	memDC.CreateCompatibleDC(pWindowDC);

	BITMAPINFO bInfo;
	CBitmap LeftLine;
	int x,y;

	GetWindowRect(ClientRect);
	//GetClientRect();
	tempIni.CopyRect(CRect(m_IniRect.left+ ClientRect.left,ClientRect.top+m_IniRect.top,m_IniRect.right+m_IniRect.left+ ClientRect.left,m_IniRect.bottom+m_IniRect.top+ClientRect.top));
	tempMin.CopyRect(CRect(m_MinRect.left+ ClientRect.left,ClientRect.top+m_MinRect.top,m_MinRect.right+m_MinRect.left+ ClientRect.left,m_MinRect.bottom+m_MinRect.top+ClientRect.top));
	tempMax.CopyRect(CRect(m_MaxRect.left+ ClientRect.left,ClientRect.top+m_MaxRect.top,m_MaxRect.right+m_MaxRect.left+ ClientRect.left,m_MaxRect.bottom+m_MaxRect.top+ClientRect.top));
	tempClose.CopyRect(CRect(m_CloseRect.left+ ClientRect.left,ClientRect.top+m_CloseRect.top,m_CloseRect.right+m_CloseRect.left+ ClientRect.left,m_CloseRect.bottom+m_CloseRect.top+ClientRect.top));
	
	if (tempIni.PtInRect(point)) //鼠标在初始化按钮上移动时,更改按钮显示的位图
	{

		LeftLine.LoadBitmap(IDB_BITMAP7);
		LeftLine.GetObject(sizeof(bInfo),&bInfo);
		
		x = bInfo.bmiHeader.biWidth;
		y = bInfo.bmiHeader.biHeight;
		memDC.SelectObject(&LeftLine);
		pWindowDC->StretchBlt(m_IniRect.left,m_IniRect.top,m_IniRect.right,m_IniRect.bottom,&memDC,0,0,x,y,SRCCOPY);
		m_IsDrawForm = FALSE;
		m_ButtonState = bsIni;
		LeftLine.DeleteObject();
	}
	else if(tempMin.PtInRect(point))//鼠标在最小化按钮上移动时,更改按钮显示的位图
	{
		LeftLine.LoadBitmap(IDB_BITMAP7);
		LeftLine.GetObject(sizeof(bInfo),&bInfo);
		
		x = bInfo.bmiHeader.biWidth;
		y = bInfo.bmiHeader.biHeight;
		memDC.SelectObject(&LeftLine);
		pWindowDC->StretchBlt(m_MinRect.left,m_MinRect.top,m_MinRect.right,m_MinRect.bottom,&memDC,0,0,x,y,SRCCOPY);
		m_IsDrawForm = FALSE;
		m_ButtonState = bsMin;
		LeftLine.DeleteObject();		
	}
	else if (tempMax.PtInRect(point))
	{
		LeftLine.LoadBitmap(IDB_BITMAP7);
		LeftLine.GetObject(sizeof(bInfo),&bInfo);
		
		x = bInfo.bmiHeader.biWidth;
		y = bInfo.bmiHeader.biHeight;
		memDC.SelectObject(&LeftLine);
		pWindowDC->StretchBlt(m_MaxRect.left,m_MaxRect.top,m_MaxRect.right,m_MaxRect.bottom,&memDC,0,0,x,y,SRCCOPY);
		m_IsDrawForm = FALSE;
		if (m_IsMax)
		{
			m_ButtonState = bsMax;
		}
		else
		{
			m_ButtonState = bsRes;
		}
		
		LeftLine.DeleteObject();		
	}
	else if (tempClose.PtInRect(point))
	{
		LeftLine.LoadBitmap(IDB_BITMAP7);
		LeftLine.GetObject(sizeof(bInfo),&bInfo);
		
		x = bInfo.bmiHeader.biWidth;
		y = bInfo.bmiHeader.biHeight;
		memDC.SelectObject(&LeftLine);
		pWindowDC->StretchBlt(m_CloseRect.left,m_CloseRect.top,m_CloseRect.right,m_CloseRect.bottom,&memDC,0,0,x,y,SRCCOPY);
		m_IsDrawForm = FALSE;
		m_ButtonState = bsClose;
		LeftLine.DeleteObject();			
	}
	else
	{
		m_ButtonState = bsNone;
		if (m_IsDrawForm==FALSE)
			DrawForm();
	//	m_IsDrawForm = TRUE;
	}
	ReleaseDC(&memDC);
}

void CDrawFormDlg::DrawForm()
{

	//获取窗口设备上下文
	CDC* pWindowDC = GetWindowDC();
	CBitmap LeftLine;
	BITMAPINFO bitinfo;
	
	CDC memDC;
	memDC.CreateCompatibleDC(pWindowDC);

	CRect Clientrect;
	GetClientRect(Clientrect);

	int leftwidth=0; //左标题的宽度
	int rightwidth = 0; //右标题的宽度
	int leftlinewidth = 0; //左边线宽度
	LeftLine.LoadBitmap(IDB_BITMAP3); //加载右标题
	LeftLine.GetObject(sizeof(bitinfo),&bitinfo);
	rightwidth = bitinfo.bmiHeader.biWidth;
	LeftLine.DeleteObject();

	int x,y;
	//绘制左边线

	//获取位图大小
	LeftLine.LoadBitmap(IDB_BITMAP4);

	LeftLine.GetObject(sizeof(bitinfo),&bitinfo);
	leftlinewidth = x = bitinfo.bmiHeader.biWidth;
	y = bitinfo.bmiHeader.biHeight;

	memDC.SelectObject(&LeftLine);
	pWindowDC->StretchBlt(1-m_BorderWidth,m_CaptionHeight+1,x+1,Clientrect.Height()+2*m_BorderHeight+5,&memDC,0,0,x,y,SRCCOPY);
	LeftLine.DeleteObject();
	
	/*****************************绘制左标题**************************************/
	LeftLine.LoadBitmap(IDB_BITMAP2);
	//获取位图大小
	LeftLine.GetObject(sizeof(bitinfo),&bitinfo);
	memDC.SelectObject(&LeftLine);
	leftwidth = x = bitinfo.bmiHeader.biWidth;
	y = bitinfo.bmiHeader.biHeight;
	pWindowDC->StretchBlt(-m_BorderWidth,0,x,m_CaptionHeight+4,&memDC,0,0,x,y,SRCCOPY);
	LeftLine.DeleteObject();
	/*****************************绘制左标题**************************************/

	/*****************************绘制中间标题**************************************/
	LeftLine.LoadBitmap(IDB_BITMAP1);
	//获取位图大小
	LeftLine.GetObject(sizeof(bitinfo),&bitinfo);
	memDC.SelectObject(&LeftLine);
	x = bitinfo.bmiHeader.biWidth;
	y = bitinfo.bmiHeader.biHeight;
	pWindowDC->StretchBlt(leftwidth-1,0,Clientrect.Width()-leftwidth-rightwidth ,m_CaptionHeight+4,&memDC,0,0,x,y,SRCCOPY);
	LeftLine.DeleteObject();
	/*****************************绘制中间标题***************************************/

	/*****************************绘制右标题**************************************/
	LeftLine.LoadBitmap(IDB_BITMAP3);
	//获取位图大小
	LeftLine.GetObject(sizeof(bitinfo),&bitinfo);
	memDC.SelectObject(&LeftLine);
	x = bitinfo.bmiHeader.biWidth;
	y = bitinfo.bmiHeader.biHeight;

	pWindowDC->StretchBlt(Clientrect.Width()-x-1,0,x+m_BorderWidth+9,m_CaptionHeight+4,&memDC,0,0,x,y,SRCCOPY);
	LeftLine.DeleteObject();
	/*****************************绘制右标题***************************************/

	/*****************************绘制右边框**************************************/
	LeftLine.LoadBitmap(IDB_BITMAP4);
	//获取位图大小
	LeftLine.GetObject(sizeof(bitinfo),&bitinfo);
	memDC.SelectObject(&LeftLine);
	x = bitinfo.bmiHeader.biWidth;
	y = bitinfo.bmiHeader.biHeight;
	pWindowDC->StretchBlt(Clientrect.Width()+m_BorderWidth+2,m_CaptionHeight+1,x+m_BorderWidth,Clientrect.Height()+2*m_BorderHeight+5,&memDC,0,0,x,y,SRCCOPY);
	LeftLine.DeleteObject();
	/*****************************绘制右边框***************************************/

	/*****************************绘制底边框**************************************/
	LeftLine.LoadBitmap(IDB_BITMAP5);
	//获取位图大小
	LeftLine.GetObject(sizeof(bitinfo),&bitinfo);
	memDC.SelectObject(&LeftLine);
	x = bitinfo.bmiHeader.biWidth;
	y = bitinfo.bmiHeader.biHeight;
	pWindowDC->StretchBlt(leftlinewidth-m_BorderWidth,Clientrect.Height()+m_CaptionHeight+2,Clientrect.Width()+m_BorderWidth,y+2,&memDC,0,0,x,y,SRCCOPY);
	LeftLine.DeleteObject();
	/*****************************绘制底边框***************************************/

	/*****************************绘制初始化按钮**************************************/
	LeftLine.LoadBitmap(IDB_BITMAP6);
	//获取位图大小
	LeftLine.GetObject(sizeof(bitinfo),&bitinfo);
	memDC.SelectObject(&LeftLine);
	x = bitinfo.bmiHeader.biWidth;
	y = bitinfo.bmiHeader.biHeight;
	pWindowDC->StretchBlt(m_IniRect.left,m_IniRect.top,m_IniRect.right,m_IniRect.bottom,&memDC,0,0,x,y,SRCCOPY);
	LeftLine.DeleteObject();
	/*****************************绘制初始化按钮***************************************/

	/*****************************绘制最小化按钮**************************************/
	LeftLine.LoadBitmap(IDB_BITMAP6);
	//获取位图大小
	LeftLine.GetObject(sizeof(bitinfo),&bitinfo);
	memDC.SelectObject(&LeftLine);
	x = bitinfo.bmiHeader.biWidth;
	y = bitinfo.bmiHeader.biHeight;
	pWindowDC->StretchBlt(m_MinRect.left,m_MinRect.top,m_MinRect.right,m_MinRect.bottom,&memDC,0,0,x,y,SRCCOPY);
	LeftLine.DeleteObject();
	/*****************************绘制最小化按钮***************************************/

	/*****************************绘制最大化按钮**************************************/
	LeftLine.LoadBitmap(IDB_BITMAP6);
	//获取位图大小
	LeftLine.GetObject(sizeof(bitinfo),&bitinfo);
	memDC.SelectObject(&LeftLine);
	x = bitinfo.bmiHeader.biWidth;
	y = bitinfo.bmiHeader.biHeight;
	pWindowDC->StretchBlt(m_MaxRect.left,m_MaxRect.top,m_MaxRect.right,m_MaxRect.bottom,&memDC,0,0,x,y,SRCCOPY);
	LeftLine.DeleteObject();
	/*****************************绘制最大化按钮***************************************/

	/*****************************绘制关闭按钮**************************************/
	LeftLine.LoadBitmap(IDB_BITMAP6);
	//获取位图大小
	LeftLine.GetObject(sizeof(bitinfo),&bitinfo);
	memDC.SelectObject(&LeftLine);
	x = bitinfo.bmiHeader.biWidth;
	y = bitinfo.bmiHeader.biHeight;
	pWindowDC->StretchBlt(m_CloseRect.left,m_CloseRect.top,m_CloseRect.right,m_CloseRect.bottom,&memDC,0,0,x,y,SRCCOPY);
	LeftLine.DeleteObject();
	m_IsDrawForm = TRUE;
	/*****************************绘制关闭按钮***************************************/
	ReleaseDC(&memDC);
	DrawFormCaption();

}

void CDrawFormDlg::OnNcPaint() 
{
	DrawForm();
	m_IsDrawForm = TRUE;
}

void CDrawFormDlg::OnNcLButtonDown(UINT nHitTest, CPoint point) 
{
	CDialog::OnNcLButtonDown(nHitTest, point);

	switch (m_ButtonState)
	{
	case bsClose: //关闭窗口
		{
			DestroyWindow();
		}
		break;
	case bsIni: //还原窗口到初始大小和位置
		{
			m_IsMax = TRUE;
			MoveWindow(m_OrigonRect.left,m_OrigonRect.top,m_OrigonRect.Width(),m_OrigonRect.Height());
		}
		break;
	case bsMin: //
		{
			CWnd* pDesk = GetDesktopWindow();
			CRect rect;
			pDesk->GetClientRect(rect);
			SetWindowPos(0 ,(rect.Width()-m_OrigonRect.Width())/2,2,m_OrigonRect.Width(),0,SWP_SHOWWINDOW);
		}
		break;
	case bsMax:
		{
			m_ButtonState = bsMax;
			ShowWindow(SW_SHOWMAXIMIZED);
			m_IsMax = FALSE;
		}
		break;
	case bsRes:
		{			
			ShowWindow(SW_RESTORE);
			m_IsMax = TRUE;
		}
		break;
	}
}

int CDrawFormDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
	{
		return -1;
	}	
	return 0;
}

void CDrawFormDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{	
	CDialog::OnShowWindow(bShow, nStatus);
	if (m_FirstShow==FALSE)
	{
		m_FirstShow = TRUE;
		GetWindowRect(m_OrigonRect);
	}
}

HBRUSH CDrawFormDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{	
	//绘制背景
	if (nCtlColor==CTLCOLOR_DLG)
	{
		CBitmap bitmap;
		bitmap.LoadBitmap(IDB_CLIENTBITMAP);

		CBrush brush(&bitmap);
		CRect rect;
		GetClientRect(rect);
		pDC->SelectObject(&brush);
		bitmap.DeleteObject();
		pDC->FillRect(rect,&brush);
		return brush;
	}
	else if (nCtlColor ==CTLCOLOR_STATIC)
	{
		pDC->SetBkMode(TRANSPARENT);
	}
	else
		return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}

void CDrawFormDlg::DrawFormCaption()
{
	if (! m_Caption.IsEmpty())
	{
		CDC* pDC = GetWindowDC();
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(m_CapitonColor);
		pDC->SetTextAlign(TA_CENTER);
		CRect rect;
		GetClientRect(rect);
		pDC->SelectObject(&m_CaptionFont);
		pDC->TextOut(rect.Width()/2, m_CaptionHeight/3 ,m_Caption);	
	}
}

//阻止用户双击标题栏
void CDrawFormDlg::OnNcLButtonDblClk(UINT nHitTest, CPoint point) 
{	
	//CDialog::OnNcLButtonDblClk(nHitTest, point);
}

void CDrawFormDlg::OnButton2() 
{
	DestroyWindow();	
}

void CDrawFormDlg::OnWindowPosChanged(WINDOWPOS FAR* lpwndpos) 
{
	CDialog::OnWindowPosChanged(lpwndpos);
	
}
