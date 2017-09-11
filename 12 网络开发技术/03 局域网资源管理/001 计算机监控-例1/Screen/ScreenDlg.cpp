// ScreenDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Screen.h"
#include "ScreenDlg.h"

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
// CScreenDlg dialog

CScreenDlg::CScreenDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScreenDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScreenDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CScreenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScreenDlg)
	DDX_Control(pDX, IDC_DRAWSCREEN, m_drawscreen);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CScreenDlg, CDialog)
	//{{AFX_MSG_MAP(CScreenDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnStart)
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, OnStop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScreenDlg message handlers

BOOL CScreenDlg::OnInitDialog()
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CScreenDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CScreenDlg::OnPaint() 
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
HCURSOR CScreenDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CScreenDlg::OnStart() 
{
	clientsocket.Create();
	run = false;
	bool ret = clientsocket.Connect("127.0.0.1",1033);
	if (!ret)
		return;
	this->SetTimer(0,1000,NULL);

}


void CScreenDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	if (!IsWindow(m_drawscreen.GetSafeHwnd()))
		return;
	CRect rect;
	m_drawscreen.GetClientRect(&rect);
	rect.top = 50;
	rect.left = 10;
	rect.right = cx -10;
	rect.bottom = cy - 10;
	m_drawscreen.MoveWindow(&rect);
}

void CScreenDlg::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent != 0)
		return;
	if (run)
		return;
	run = true;
	GetScreen();
	run = false;
	CDialog::OnTimer(nIDEvent);
}

void CScreenDlg::GetScreen()
{
	char *buffer = "M";
	clientsocket.Send(buffer,strlen(buffer));
	clientsocket.Receive(&bitmap,sizeof(BITMAP));
	size = bitmap.bmWidthBytes * bitmap.bmHeight;
	bmpdata = new char[size];
	char * data = bmpdata;
	int len,receivelen;
	len = receivelen = 0;
	buffer = "D";
	clientsocket.Send(buffer,strlen(buffer));
	do
	{
		receivelen = clientsocket.Receive(data,size);
		len += receivelen;
		data += receivelen;
	}while(len<size);
	DrawScreen();
	delete bmpdata;
	bmpdata = NULL;
	size = 0;
}

void CScreenDlg::DrawScreen()
{
	CDC *dc = m_drawscreen.GetDC();
	BITMAPINFOHEADER bih;
	bih.biBitCount=bitmap.bmBitsPixel;
	bih.biClrImportant=0;
	bih.biClrUsed=0;
	bih.biCompression=0;
	bih.biHeight=bitmap.bmHeight;
	bih.biPlanes=1;
	bih.biSize=sizeof(BITMAPINFOHEADER);
	bih.biSizeImage=size;
	bih.biWidth=bitmap.bmWidth;
	bih.biXPelsPerMeter=0;
	bih.biYPelsPerMeter=0;

	CBitmap bm;
	bm.CreateBitmapIndirect(&bitmap);
	CDC bmpdc;
	bmpdc.CreateCompatibleDC(dc);
	SetDIBits(bmpdc.m_hDC,bm,0,bitmap.bmHeight,bmpdata,(BITMAPINFO*)&bih,DIB_RGB_COLORS);
	bmpdc.SelectObject(&bm);
	CRect rect;
	m_drawscreen.GetClientRect(&rect);
	dc->StretchBlt(0,0,rect.Width(),rect.Height(),&bmpdc,0,0,bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);
}

void CScreenDlg::OnStop() 
{
	this->KillTimer(0);
	clientsocket.ShutDown(2);
	clientsocket.Close();
}
