// PrintFormDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PrintForm.h"
#include "PrintFormDlg.h"
#include "_recordset.h"

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
// CPrintFormDlg dialog

CPrintFormDlg::CPrintFormDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrintFormDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrintFormDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	x = 10;
}

void CPrintFormDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrintFormDlg)

	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPrintFormDlg, CDialog)
	//{{AFX_MSG_MAP(CPrintFormDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintFormDlg message handlers

BOOL CPrintFormDlg::OnInitDialog()
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

void CPrintFormDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPrintFormDlg::OnPaint() 
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
HCURSOR CPrintFormDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPrintFormDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
}

void CPrintFormDlg::OnButton1() 
{
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
	CPrintDialog m_printdlg( FALSE);
	if (m_printdlg.DoModal()==IDOK)
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
	}
	memDC.SelectObject(oldbitmap);
	bitmap.Detach();
}
