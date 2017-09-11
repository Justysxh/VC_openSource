// TextScreenSaveDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TextScreenSave.h"
#include "TextScreenSaveDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
static UINT thread(LPVOID pParam);
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
// CTextScreenSaveDlg dialog

CTextScreenSaveDlg::CTextScreenSaveDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTextScreenSaveDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTextScreenSaveDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTextScreenSaveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTextScreenSaveDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTextScreenSaveDlg, CDialog)
	//{{AFX_MSG_MAP(CTextScreenSaveDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextScreenSaveDlg message handlers

BOOL CTextScreenSaveDlg::OnInitDialog()
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
	iscreenx=GetSystemMetrics(SM_CXSCREEN);
	iscreeny=GetSystemMetrics(SM_CYSCREEN);
	CRect rc(0,0,iscreenx,iscreeny);
	::GetCursorPos(&curpt);
	this->MoveWindow(rc);
	x=0;y=0;
	AfxBeginThread(thread,this);
	return TRUE;
}

void CTextScreenSaveDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTextScreenSaveDlg::OnPaint() 
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
	CPaintDC dc(this);
	CBrush brush(RGB(0,0,0));
	CRect rect;
	GetClientRect(rect);
	dc.FillRect(&rect,&brush);
	CFont font;
	font.CreateFont(30,20,10,10,FW_NORMAL,FALSE,FALSE,0,
			ANSI_CHARSET,OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY,DEFAULT_PITCH|FF_SWISS,"");
	dc.SelectObject(font);
	dc.SetTextColor(RGB(0,255,255));
	dc.SetBkMode(TRANSPARENT);
	TEXTMETRIC tm;
	::GetTextMetrics(dc.GetSafeHdc(),&tm);
	rect.SetRect(x,y,tm.tmMaxCharWidth*10,tm.tmHeight+y);
	dc.DrawText("mingrisoft",&rect,DT_LEFT);
		CDialog::OnPaint();
	}
	
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTextScreenSaveDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
static UINT thread(LPVOID pParam)
{
	CTextScreenSaveDlg *p=(CTextScreenSaveDlg*)pParam;
	
	CDC *pDC=p->GetDC();
	while(1)
	{	
		p->x+=10;
		if(p->x>p->iscreenx)
		{
			p->x=0;
			p->y+=20;
		}
		if(p->y>p->iscreeny)p->y=0;
		Sleep(10);
		p->Invalidate(FALSE);
	}
	return 0;
}

void CTextScreenSaveDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	int moveptx=point.x-curpt.x;
	int movepty=point.y-curpt.y;
	if(abs(moveptx)+abs(movepty)>3)
		PostMessage(WM_CLOSE);
	CDialog::OnMouseMove(nFlags, point);
}

BOOL CTextScreenSaveDlg::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message==WM_KEYDOWN)
	PostMessage(WM_CLOSE);
	if(pMsg->message==WM_LBUTTONDOWN)
	PostMessage(WM_CLOSE);
	if(pMsg->message==WM_RBUTTONDOWN)
	PostMessage(WM_CLOSE);
	return CDialog::PreTranslateMessage(pMsg);
}
