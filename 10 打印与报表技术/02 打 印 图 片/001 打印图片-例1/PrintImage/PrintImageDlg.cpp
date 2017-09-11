// PrintImageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PrintImage.h"
#include "PrintImageDlg.h"

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
// CPrintImageDlg dialog

CPrintImageDlg::CPrintImageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrintImageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrintImageDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPrintImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrintImageDlg)
	DDX_Control(pDX, IDC_IMAGE, m_image);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPrintImageDlg, CDialog)
	//{{AFX_MSG_MAP(CPrintImageDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONPRINT, OnButtonprint)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintImageDlg message handlers

BOOL CPrintImageDlg::OnInitDialog()
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

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPrintImageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPrintImageDlg::OnPaint() 
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

HCURSOR CPrintImageDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPrintImageDlg::OnOK() 
{

}

void CPrintImageDlg::OnButtonprint() 
{
	CDC* imagedc = m_image.GetDC();
	CRect m_rect;
	//获取图像的大小
	m_image.GetClientRect(m_rect);

	int formx,formy;
	formx = imagedc->GetDeviceCaps(LOGPIXELSX);
	formy = imagedc->GetDeviceCaps(LOGPIXELSY);

	CPrintDialog m_printdlg (FALSE);
	if (m_printdlg.DoModal()==IDOK)
	{
		CDC dc;
		
		dc.Attach(m_printdlg.GetPrinterDC());
		
		//获取打印机与屏幕的分辨率比率
		int printerx,printery;
		printerx = dc.GetDeviceCaps(LOGPIXELSX);
		printery = dc.GetDeviceCaps(LOGPIXELSY);

		double ratex,ratey;
		ratex = (double)printerx/formx;
		ratey = (double)printery/formy;

		//打印图像
		dc.StartDoc("print");
		dc.StretchBlt(30,40,(int)(m_rect.Width()*ratex),(int)(m_rect.Height()*ratey),imagedc,0,0,m_rect.Width(),m_rect.Height(),SRCCOPY);
		dc.EndDoc();
	}
}
