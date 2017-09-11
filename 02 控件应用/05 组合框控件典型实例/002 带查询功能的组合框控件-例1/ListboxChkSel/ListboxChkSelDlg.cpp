// ListboxChkSelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ListboxChkSel.h"
#include "ListboxChkSelDlg.h"

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
// CListboxChkSelDlg dialog

CListboxChkSelDlg::CListboxChkSelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListboxChkSelDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CListboxChkSelDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListboxChkSelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CListboxChkSelDlg)
	DDX_Control(pDX, IDC_CHKLIST, m_chklist);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CListboxChkSelDlg, CDialog)
	//{{AFX_MSG_MAP(CListboxChkSelDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPER, OnOper)
	ON_LBN_DBLCLK(IDC_CHKLIST, OnDblclkChklist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListboxChkSelDlg message handlers

BOOL CListboxChkSelDlg::OnInitDialog()
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
	m_chklist.SetCheckStyle(BS_CHECKBOX);
	m_chklist.AddString("浏览文件");
	m_chklist.AddString("操作数据库");
	m_chklist.AddString("前台操作");
	m_chklist.AddString("后台管理");
	GetDlgItem(IDC_VIEW)->EnableWindow(FALSE);
	GetDlgItem(IDC_DATABASE)->EnableWindow(FALSE);
	GetDlgItem(IDC_FRONT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BACK)->EnableWindow(FALSE);

	return TRUE;
}

void CListboxChkSelDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CListboxChkSelDlg::OnPaint() 
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
HCURSOR CListboxChkSelDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CListboxChkSelDlg::OnOper() 
{
	if(m_chklist.GetCheck(0))
		GetDlgItem(IDC_VIEW)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_VIEW)->EnableWindow(FALSE);
	if(m_chklist.GetCheck(1))
		GetDlgItem(IDC_DATABASE)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_DATABASE)->EnableWindow(FALSE);
	if(m_chklist.GetCheck(2))
		GetDlgItem(IDC_FRONT)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_FRONT)->EnableWindow(FALSE);
	if(m_chklist.GetCheck(3))
		GetDlgItem(IDC_BACK)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_BACK)->EnableWindow(FALSE);
}

void CListboxChkSelDlg::OnDblclkChklist() 
{
	int i=m_chklist.GetCurSel();
	if(i<0)return;
	if(m_chklist.GetCheck(i)<1)
	m_chklist.SetCheck(i,1);
	else
	m_chklist.SetCheck(i,0);
}
