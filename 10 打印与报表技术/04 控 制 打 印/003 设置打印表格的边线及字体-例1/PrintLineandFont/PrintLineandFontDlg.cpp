// PrintLineandFontDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PrintLineandFont.h"
#include "PrintLineandFontDlg.h"

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
// CPrintLineandFontDlg dialog

CPrintLineandFontDlg::CPrintLineandFontDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrintLineandFontDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrintLineandFontDlg)
	m_edit = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPrintLineandFontDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrintLineandFontDlg)
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	DDX_Text(pDX, IDC_EDIT1, m_edit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPrintLineandFontDlg, CDialog)
	//{{AFX_MSG_MAP(CPrintLineandFontDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnPreview)
	ON_BN_CLICKED(IDC_BUTTON2, OnSelectFont)
	ON_BN_CLICKED(IDC_BUTTON3, OnPrint)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintLineandFontDlg message handlers

BOOL CPrintLineandFontDlg::OnInitDialog()
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
	
	m_Grid.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_Grid.InsertColumn(0,"姓名",LVCFMT_LEFT,100);
	m_Grid.InsertColumn(1,"性别",LVCFMT_LEFT,100);
	m_Grid.InsertColumn(2,"年龄",LVCFMT_LEFT,100);
	m_Grid.InsertColumn(3,"地址",LVCFMT_LEFT,100);
	
	m_Grid.InsertItem(0,"张三");
	m_Grid.SetItemText(0,1,"男");
	m_Grid.SetItemText(0,2,"18");
	m_Grid.SetItemText(0,3,"吉林");

	m_Grid.InsertItem(1,"李四");
	m_Grid.SetItemText(1,1,"男");
	m_Grid.SetItemText(1,2,"25");
	m_Grid.SetItemText(1,3,"长沙");

	m_Grid.InsertItem(2,"王五");
	m_Grid.SetItemText(2,1,"男");
	m_Grid.SetItemText(2,2,"30");
	m_Grid.SetItemText(2,3,"上海");
	
	dlg.PrintGrid = &m_Grid;
	dlg.isfont = false;
	m_edit = "1";
	UpdateData(false);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPrintLineandFontDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPrintLineandFontDlg::OnPaint() 
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
HCURSOR CPrintLineandFontDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPrintLineandFontDlg::OnPreview() 
{
	UpdateData();
	dlg.LineWidth = atoi(m_edit);
	dlg.DoModal();		
}

void CPrintLineandFontDlg::OnSelectFont() 
{
	CFontDialog fontdlg;
	if (fontdlg.DoModal() == IDOK)
	{
		fontdlg.GetCurrentFont(&dlg.logfont);
		dlg.isfont = true;
	}
}

void CPrintLineandFontDlg::OnPrint() 
{
	CPrintDialog pdlg(false);	
	pdlg.GetDefaults();
	CDC dc;
	dc.Attach(pdlg.GetPrinterDC());
	dc.StartDoc("PrintGrid");
	dlg.PreviewGrid(&dc,true);
	dc.EndDoc();
}
