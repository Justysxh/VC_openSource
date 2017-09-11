// RutineDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RutineDemo.h"
#include "RutineDemoDlg.h"

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
// CRutineDemoDlg dialog

CRutineDemoDlg::CRutineDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRutineDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRutineDemoDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	iscreated = FALSE;
}

void CRutineDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRutineDemoDlg)
	DDX_Control(pDX, IDC_TITILE, m_title);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRutineDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CRutineDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRutineDemoDlg message handlers

BOOL CRutineDemoDlg::OnInitDialog()
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
	
	//Create Title Font
	DemoCircuitry();
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRutineDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRutineDemoDlg::OnPaint() 
{
//	if (iscreated)
	{
		CDC* m_dc = GetDC();

		CPen m_pen(PS_SOLID,3,RGB(0,0,255));
		m_dc->SelectObject(&m_pen);
		
		m_dc->MoveTo(80,130);
		m_dc->LineTo(180,210);

		m_dc->MoveTo(280,210);
		m_dc->LineTo(350,180);

		m_dc->MoveTo(450,180);
		m_dc->LineTo(520,220);

		m_dc->MoveTo(520,220);
		m_dc->LineTo(580,170);
	}


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
HCURSOR CRutineDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRutineDemoDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
}

void CRutineDemoDlg::DemoCircuitry()
{
	m_buses[0].Create("",WS_CHILD|SS_BITMAP,CRect(40,80,100,140),this);		
	m_buses[1].Create("",WS_CHILD|SS_BITMAP,CRect(180,180,240,240),this);		
	m_buses[2].Create("",WS_CHILD|SS_BITMAP,CRect(350,140,400,380),this);		
	m_buses[3].Create("",WS_CHILD|SS_BITMAP,CRect(460,220,500,400),this);		
	m_buses[4].Create("",WS_CHILD|SS_BITMAP|WS_EX_TRANSPARENT,CRect(580,140,650,160),this);		
	for (int i = 0;i<5;i++)
	{
		m_buses[i].SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP1)));
		m_buses[i].ShowWindow(SW_SHOW);		
	}
}

HBRUSH CRutineDemoDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if (nCtlColor==CTLCOLOR_STATIC) //判断是否为CStaitc控件
	{
		pDC->SetBkMode(TRANSPARENT);
	}
	else 
	{
		CBrush m_brush(RGB(255,255,255));
		CRect m_rect;
		GetClientRect(m_rect);
		pDC->SelectObject(&m_brush);
		pDC->FillRect(m_rect,&m_brush); //使对话框背景
		return m_brush;
	}
}
