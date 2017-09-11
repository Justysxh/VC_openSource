// ColourTextDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ColourText.h"
#include "ColourTextDlg.h"

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
// CColourTextDlg dialog

CColourTextDlg::CColourTextDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CColourTextDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CColourTextDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CColourTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CColourTextDlg)
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CColourTextDlg, CDialog)
	//{{AFX_MSG_MAP(CColourTextDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_RED, OnRed)
	ON_BN_CLICKED(IDC_BLUE, OnBlue)
	ON_BN_CLICKED(IDC_GREEN, OnGreen)
	ON_BN_CLICKED(IDC_YELLOW, OnYellow)
	ON_BN_CLICKED(IDC_AMETHYST, OnAmethyst)
	ON_BN_CLICKED(IDC_CYAN, OnCyan)
	ON_BN_CLICKED(IDC_BLACK, OnBlack)
	ON_BN_CLICKED(IDC_GRAY, OnGray)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColourTextDlg message handlers

BOOL CColourTextDlg::OnInitDialog()
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
	colour = RGB(0,0,0);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CColourTextDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CColourTextDlg::OnPaint() 
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
HCURSOR CColourTextDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



HBRUSH CColourTextDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if(nCtlColor == CTLCOLOR_EDIT)
		pDC->SetTextColor(colour);
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CColourTextDlg::OnRed() 
{
	// TODO: Add your control notification handler code here
	colour = RGB(255,0,0);
	m_edit.SetFocus();
}

void CColourTextDlg::OnBlue() 
{
	// TODO: Add your control notification handler code here
	colour = RGB(0,0,255);
	m_edit.SetFocus();
}

void CColourTextDlg::OnGreen() 
{
	// TODO: Add your control notification handler code here
	colour = RGB(0,255,0);
	m_edit.SetFocus();
}

void CColourTextDlg::OnYellow() 
{
	// TODO: Add your control notification handler code here
	colour = RGB(255,255,0);
	m_edit.SetFocus();
}

void CColourTextDlg::OnAmethyst() 
{
	// TODO: Add your control notification handler code here
	colour = RGB(255,0,255);
	m_edit.SetFocus();
}

void CColourTextDlg::OnCyan() 
{
	// TODO: Add your control notification handler code here
	colour = RGB(0,255,255);
	m_edit.SetFocus();
}

void CColourTextDlg::OnBlack() 
{
	// TODO: Add your control notification handler code here
	colour = RGB(0,0,0);
	m_edit.SetFocus();
}

void CColourTextDlg::OnGray() 
{
	// TODO: Add your control notification handler code here
	colour = RGB(128,128,128);
	m_edit.SetFocus();
}

