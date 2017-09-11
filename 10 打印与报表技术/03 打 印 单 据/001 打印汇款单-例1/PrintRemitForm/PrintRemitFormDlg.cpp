// PrintRemitFormDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PrintRemitForm.h"
#include "PrintRemitFormDlg.h"

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
// CPrintRemitFormDlg dialog

CPrintRemitFormDlg::CPrintRemitFormDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrintRemitFormDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrintRemitFormDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPrintRemitFormDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrintRemitFormDlg)
	DDX_Control(pDX, IDC_FRAME20, m_frame20);
	DDX_Control(pDX, IDC_FRAME19, m_frame19);
	DDX_Control(pDX, IDC_RENAME3, m_rename3);
	DDX_Control(pDX, IDC_SENDPEOPLE, m_sendpeople);
	DDX_Control(pDX, IDC_FRAME18, m_frame18);
	DDX_Control(pDX, IDC_FRAME17, m_frame17);
	DDX_Control(pDX, IDC_ADDRESS2, m_addr2);
	DDX_Control(pDX, IDC_FRAME16, m_frame16);
	DDX_Control(pDX, IDC_SENDPERSON, m_sendperson);
	DDX_Control(pDX, IDC_FRAME15, m_frame15);
	DDX_Control(pDX, IDC_FRAME14, m_frame14);
	DDX_Control(pDX, IDC_FRAME13, m_frame13);
	DDX_Control(pDX, IDC_RENAME, m_rename);
	DDX_Control(pDX, IDC_REPERSON, m_reperson);
	DDX_Control(pDX, IDC_FRAME12, m_frame12);
	DDX_Control(pDX, IDC_FRAME11, m_frame11);
	DDX_Control(pDX, IDC_ADDRESS, m_addr);
	DDX_Control(pDX, IDC_RECEIVE, m_receive);
	DDX_Control(pDX, IDC_FRAME10, m_frame10);
	DDX_Control(pDX, IDC_MONEY, m_money);
	DDX_Control(pDX, IDC_TEXT10, m_text10);
	DDX_Control(pDX, IDC_TEXT9, m_text9);
	DDX_Control(pDX, IDC_FRAME4, m_frame4);
	DDX_Control(pDX, IDC_FRAME3, m_frame3);
	DDX_Control(pDX, IDC_FRAME8, m_frame8);
	DDX_Control(pDX, IDC_FRAME7, m_frame7);
	DDX_Control(pDX, IDC_FRAME6, m_frame6);
	DDX_Control(pDX, IDC_TEXT6, m_text6);
	DDX_Control(pDX, IDC_LINE2, m_line2);
	DDX_Control(pDX, IDC_FRAME2, m_frame2);
	DDX_Control(pDX, IDC_FRAME1, m_frame1);
	DDX_Control(pDX, IDC_TITLE, m_title);
	DDX_Control(pDX, IDC_NUM6, m_num6);
	DDX_Control(pDX, IDC_NUM5, m_num5);
	DDX_Control(pDX, IDC_NUM4, m_num4);
	DDX_Control(pDX, IDC_NUM3, m_num3);
	DDX_Control(pDX, IDC_NUM2, m_num2);
	DDX_Control(pDX, IDC_NUM1, m_num1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPrintRemitFormDlg, CDialog)
	//{{AFX_MSG_MAP(CPrintRemitFormDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_PRINT, OnPrint)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintRemitFormDlg message handlers

BOOL CPrintRemitFormDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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

	SetIcon(m_hIcon, TRUE);	// Set big icon
	SetIcon(m_hIcon, FALSE);// Set small icon
	
	// TODO: Add extra initialization here
	m_font.CreateFont(-12,-10,0,0,0,0,0,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,DEFAULT_PITCH,DEFAULT_QUALITY,FF_ROMAN ,"宋体");
	
	m_title.SetFont(&m_font);
	
	m_title.isframed = false;
	m_title.islined = true;
	m_title.align = DT_LEFT;
	m_title.m_color = RGB(0,255,0);
	m_frame1.m_framecolor = RGB(0,255,0);
	m_frame2.m_framecolor = RGB(0,255,0);	

	m_frame2.isBottom = false;
	m_frame2.isRight = false;

	m_line2.islined = true;
	m_line2.m_color = RGB(0,255,0);
	m_line2.isframed = false;

	m_text6.m_framecolor = RGB(0,255,0);


	m_frame4.m_lindwidth = 2;
	//m_frame6.isframed = false;
	m_frame6.m_framecolor = RGB(0,255,0);



	m_frame7.m_framecolor = RGB(0,255,0);
	m_frame8.m_framecolor = RGB(0,255,0);
	
	m_frame3.m_framecolor = RGB(0,255,0);
	m_frame3.isframed = false;

	m_text9.m_color = m_text9.m_framecolor =  RGB(0,255,0);

	m_text9.isTop = FALSE;
	m_text9.isBottom = FALSE;

	m_text10.isTop = FALSE;
	m_text10.isBottom = FALSE;

	m_text10.m_framecolor =  RGB(0,255,0);

	m_money.SetFont(&m_font);
	

	m_frame10.m_framecolor = RGB(0,255,0);
	m_frame10.isBottom = false;

	m_receive.isframed = false;
	m_receive.m_color = RGB(0,255,0);
	
	m_addr.isframed = false;
	m_addr.m_color = RGB(0,255,0);

	m_addr2.isframed = false;
	m_addr2.m_color = RGB(0,255,0);

	m_frame11.m_framecolor = RGB(0,255,0);
	m_frame11.isLeft = false;

	m_frame12.m_framecolor = RGB(0,255,0);
	m_frame12.isRight = false;

	m_reperson.m_color = RGB(0,255,0);
	m_reperson.isframed = false;

	m_rename.m_color = RGB(0,255,0);
	m_rename.isframed = false;

	m_sendperson.m_color = RGB(0,255,0);
	m_sendperson.isframed = false;

	m_frame13.m_framecolor = m_frame14.m_framecolor= m_frame15.m_framecolor = RGB(0,255,0);

	m_frame13.isRight = false;
	m_frame14.isRight = false;
	m_frame15.isRight = false;

	m_frame16.m_framecolor = RGB(0,255,0);

	m_frame16.isTop = false;
	m_frame16.isRight = false;

	m_frame17.m_framecolor = RGB(0,255,0);
	m_frame18.m_framecolor = RGB(0,255,0);

	m_frame17.isTop = false;

	m_frame18.isBottom = FALSE;

	m_sendpeople.m_color = RGB(0,255,0);
	m_sendpeople.isframed = false;

	m_rename3.m_color = RGB(0,255,0);
	m_rename3.isframed = false;

	m_frame19.m_framecolor = RGB(0,255,0);


	m_frame20.isLeft = false;
	m_frame20.isRight = false;
	m_frame20.m_framecolor = RGB(0,255,0);

	//m_frame19.isframed = false;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPrintRemitFormDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPrintRemitFormDlg::OnPaint() 
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
HCURSOR CPrintRemitFormDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPrintRemitFormDlg::OnOK() 
{
	
	//CDialog::OnOK();
}

HBRUSH CPrintRemitFormDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	CBrush m_brush(RGB(255,255,255));
	
	CRect rect;
	GetClientRect(rect);
	pDC->FillRect(rect,&m_brush);
	
	if (nCtlColor==CTLCOLOR_STATIC)
		pDC->SetBkMode(TRANSPARENT);

	return m_brush;
}

void CPrintRemitFormDlg::OnPrint() 
{	
	CWnd* m_btn = GetDlgItem(IDC_PRINT);
	m_btn->ShowWindow(SW_HIDE);

	CBitmap bitmap;
	CClientDC dc(this);
	CDC memDC;
	CRect rect;
	memDC.CreateCompatibleDC(&dc);
	this->GetClientRect(rect);

	bitmap.CreateCompatibleBitmap(&dc,rect.Width(),rect.Height());
	CBitmap * oldbitmap = memDC.SelectObject(&bitmap);

	memDC.BitBlt(0,0,rect.Width(),rect.Height(),&dc,0,0,SRCCOPY);

	//获取打印机DC
	CPrintDialog m_printdlg(FALSE);
	if(	m_printdlg.DoModal()==IDOK)
	{
		CDC dc1;
		dc1.Attach(m_printdlg.GetPrinterDC());

		int screenx,screeny;
		int printx,printy;
		double ratex,ratey;

		//确定打印机与屏幕的像素比率
		screenx =  dc.GetDeviceCaps(LOGPIXELSX);
		screeny =  dc.GetDeviceCaps(LOGPIXELSY);

		printx =  dc1.GetDeviceCaps(LOGPIXELSX);
		printy =  dc1.GetDeviceCaps(LOGPIXELSY);

		ratex = (double)(printx)/screenx;
		ratey = (double)(printy)/screeny;

		//开始打印
		dc1.StartDoc("FirstDoc");
		dc1.StretchBlt(0,0,(int)(rect.Width()*ratex),(int)(rect.Height()*ratey),&memDC,0,0,rect.Width(),rect.Height(),SRCCOPY);
		dc1.EndDoc();

		memDC.SelectObject(oldbitmap);
		bitmap.Detach();
	}
	m_btn->ShowWindow(SW_SHOW);
}
