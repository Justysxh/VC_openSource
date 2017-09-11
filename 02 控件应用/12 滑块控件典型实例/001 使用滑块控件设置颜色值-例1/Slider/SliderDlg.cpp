// SliderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Slider.h"
#include "SliderDlg.h"

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
// CSliderDlg dialog

CSliderDlg::CSliderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSliderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSliderDlg)
	m_bEdit = 0;
	m_gEdit = 0;
	m_rEdit = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSliderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSliderDlg)
	DDX_Control(pDX, IDC_COLOR, m_Color);
	DDX_Control(pDX, IDC_SLIDER3, m_Blue);
	DDX_Control(pDX, IDC_SLIDER2, m_Green);
	DDX_Control(pDX, IDC_SLIDER1, m_Red);
	DDX_Text(pDX, IDC_EDIT3, m_bEdit);
	DDX_Text(pDX, IDC_EDIT2, m_gEdit);
	DDX_Text(pDX, IDC_EDIT1, m_rEdit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSliderDlg, CDialog)
	//{{AFX_MSG_MAP(CSliderDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER1, OnReleasedcaptureSlider1)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER2, OnReleasedcaptureSlider2)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER3, OnReleasedcaptureSlider3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSliderDlg message handlers

BOOL CSliderDlg::OnInitDialog()
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
	m_Red.SetRange(0,255,TRUE);
	m_Green.SetRange(0,255,TRUE);
	m_Blue.SetRange(0,255,TRUE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSliderDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSliderDlg::OnPaint() 
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
	DrawColor();
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSliderDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSliderDlg::DrawColor()
{
	CDC* pDC = m_Color.GetDC();
	CRect rect;
	m_Color.GetClientRect(rect);
	CBrush brush(RGB(m_Red.GetPos(),m_Green.GetPos(),m_Blue.GetPos()));
	pDC->FillRect(rect,&brush);
}

void CSliderDlg::OnReleasedcaptureSlider1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_rEdit = m_Red.GetPos();
	DrawColor();
	UpdateData(FALSE);
	*pResult = 0;
}

void CSliderDlg::OnReleasedcaptureSlider2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_gEdit = m_Green.GetPos();
	DrawColor();
	UpdateData(FALSE);
	*pResult = 0;
}

void CSliderDlg::OnReleasedcaptureSlider3(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_bEdit = m_Blue.GetPos();
	DrawColor();
	UpdateData(FALSE);
	*pResult = 0;
}
