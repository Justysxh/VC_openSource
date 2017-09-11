// ScreensavealbumDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Screensavealbum.h"
#include "ScreensavealbumDlg.h"

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
// CScreensavealbumDlg dialog

CScreensavealbumDlg::CScreensavealbumDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScreensavealbumDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScreensavealbumDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CScreensavealbumDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScreensavealbumDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CScreensavealbumDlg, CDialog)
	//{{AFX_MSG_MAP(CScreensavealbumDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScreensavealbumDlg message handlers

BOOL CScreensavealbumDlg::OnInitDialog()
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
	
	ShowCursor(false);
	CRect rc(0,0,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));
	::GetCursorPos(&curpt);
	this->MoveWindow(rc);
	SetTimer(1,500,NULL);
	x=0;y=0;
	return TRUE;
}

void CScreensavealbumDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CScreensavealbumDlg::OnPaint() 
{/*
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
	}*/
	CPaintDC dc(this);
	CBrush brush(RGB(0,0,0));
	CRect rect;
	GetClientRect(rect);
	dc.FillRect(&rect,&brush);
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CScreensavealbumDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CScreensavealbumDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	int moveptx=point.x-curpt.x;
	int movepty=point.y-curpt.y;
	if(moveptx+movepty>3)
		PostMessage(WM_CLOSE); 
	CDialog::OnMouseMove(nFlags, point);
}

void CScreensavealbumDlg::PostNcDestroy() 
{
	KillTimer(1);
	CDialog::PostNcDestroy();
}

void CScreensavealbumDlg::OnTimer(UINT nIDEvent) 
{
	KillTimer(1);
	CClientDC dc(this);
	static nIndexBit=0;
	if(nIndexBit>3)
	nIndexBit=0;
	DrawBitmap(dc,nIndexBit++);
	SetTimer(1,500,NULL);
	CDialog::OnTimer(nIDEvent);
}

void CScreensavealbumDlg::DrawBitmap(CDC &dc, int nIndexBit)
{
	CDC dcmem;
	dcmem.CreateCompatibleDC(&dc);
	CBitmap m_Bitmap;
	m_Bitmap.LoadBitmap(IDB_BITMAP1+nIndexBit);
	dcmem.SelectObject(m_Bitmap);
	BITMAP bmp;
	GetObject(m_Bitmap,sizeof(bmp),&bmp);
	int iscreenx=GetSystemMetrics(SM_CXSCREEN);
	int iscreeny=GetSystemMetrics(SM_CYSCREEN);
	if(x>iscreenx)x=0;
	if(y>iscreeny)y=0;
	dc.BitBlt(x,y,bmp.bmWidth,bmp.bmHeight,&dcmem,0,0,SRCCOPY);
	Sleep(2000);
	dc.BitBlt(x,y,iscreenx,iscreeny,&dcmem,0,0,BLACKNESS);
	x+=80;
	y+=20;
	dcmem.DeleteDC();
}

void CScreensavealbumDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	PostMessage(WM_CLOSE);
}

void CScreensavealbumDlg::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	PostMessage(WM_CLOSE);
}

void CScreensavealbumDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	PostMessage(WM_CLOSE);
}

void CScreensavealbumDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	PostMessage(WM_CLOSE);
}

void CScreensavealbumDlg::OnRButtonDown(UINT nFlags, CPoint point) 
{
	PostMessage(WM_CLOSE);
}

void CScreensavealbumDlg::OnRButtonUp(UINT nFlags, CPoint point) 
{
	PostMessage(WM_CLOSE);
}
