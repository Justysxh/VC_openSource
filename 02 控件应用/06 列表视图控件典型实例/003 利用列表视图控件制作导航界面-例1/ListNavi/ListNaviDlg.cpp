// ListNaviDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ListNavi.h"
#include "ListNaviDlg.h"

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
// CListNaviDlg dialog

CListNaviDlg::CListNaviDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListNaviDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CListNaviDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListNaviDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CListNaviDlg)
	DDX_Control(pDX, IDC_IMAGELST, m_mylist);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CListNaviDlg, CDialog)
	//{{AFX_MSG_MAP(CListNaviDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_DBLCLK, IDC_IMAGELST, OnDblclkImagelst)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListNaviDlg message handlers

BOOL CListNaviDlg::OnInitDialog()
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

	m_imglst.Create(32,32,ILC_COLOR32|ILC_MASK,0,0);
	m_imglst.Add(::AfxGetApp()->LoadIcon(IDI_CK));
	m_imglst.Add(::AfxGetApp()->LoadIcon(IDI_CP));
	m_imglst.Add(::AfxGetApp()->LoadIcon(IDI_DB));
	m_imglst.Add(::AfxGetApp()->LoadIcon(IDI_DY));
	m_imglst.Add(::AfxGetApp()->LoadIcon(IDI_KC));
	m_imglst.Add(::AfxGetApp()->LoadIcon(IDI_PD));
	m_imglst.Add(::AfxGetApp()->LoadIcon(IDI_RK));
	m_mylist.SetImageList(&m_imglst,TVSIL_NORMAL);
	m_mylist.InsertItem(0,"项目1",0);
	m_mylist.InsertItem(1,"项目2",1);
	m_mylist.InsertItem(2,"项目3",2);
	m_mylist.InsertItem(3,"项目4",3);
	m_mylist.InsertItem(4,"项目5",4);
	m_mylist.InsertItem(5,"项目6",5);
	m_mylist.InsertItem(6,"项目7",6);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CListNaviDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CListNaviDlg::OnPaint() 
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
HCURSOR CListNaviDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



void CListNaviDlg::OnDblclkImagelst(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int cursel=m_mylist.GetSelectionMark();
	if(cursel==-1)return;
	switch(cursel)
	{
	case 0:
		{
		CButton *p=(CButton*)GetDlgItem(IDC_ADD);
		p->SetCheck(1);
		break;
		}
	case 1:
		{
		CButton *p=(CButton*)GetDlgItem(IDC_RELATINFO);
		p->SetCheck(1);
		break;
		}
	case 2:
		{
		CButton *p=(CButton*)GetDlgItem(IDC_UPDATE);
		p->SetCheck(1);
		break;
		}
	case 3:
		{
		CButton *p=(CButton*)GetDlgItem(IDC_CHECKOUT);
		p->SetCheck(1);
		break;
		}
	case 4:
		{
		CButton *p=(CButton*)GetDlgItem(IDC_TYPEINFO);
		p->SetCheck(1);
		break;
		}
	case 5:
		{
		CButton *p=(CButton*)GetDlgItem(IDC_BACKUP);
		p->SetCheck(1);
		break;
		}
	case 6:
		{
		CButton *p=(CButton*)GetDlgItem(IDC_INPUT);
		p->SetCheck(1);
		break;
		}
	case 7:
		{
		CButton *p=(CButton*)GetDlgItem(IDC_BASEINFO);
		p->SetCheck(1);
		break;
		}
	}
	*pResult = 0;
}
