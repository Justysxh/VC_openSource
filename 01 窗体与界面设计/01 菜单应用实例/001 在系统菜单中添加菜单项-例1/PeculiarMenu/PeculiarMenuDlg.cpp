// PeculiarMenuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PeculiarMenu.h"
#include "PeculiarMenuDlg.h"

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


	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPeculiarMenuDlg dialog

CPeculiarMenuDlg::CPeculiarMenuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPeculiarMenuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPeculiarMenuDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_MAINMENU);
}

void CPeculiarMenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPeculiarMenuDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPeculiarMenuDlg, CDialog)
	//{{AFX_MSG_MAP(CPeculiarMenuDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton1)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPeculiarMenuDlg message handlers

BOOL CPeculiarMenuDlg::OnInitDialog()
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

	m_pMenu = GetSystemMenu(FALSE);
	m_pMenu->AppendMenu(MF_STRING,IDI_PECULIARMENU,"系统菜单");
	
	return TRUE;  
}

void CPeculiarMenuDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID ) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else if (nID == IDI_PECULIARMENU)
	{
			MessageBox("系统菜单","提示",MB_OK|MB_ICONINFORMATION);
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPeculiarMenuDlg::OnPaint() 
{
	CDC* m_dc = this->GetDC();
	CDC m_memdc;
	m_memdc.CreateCompatibleDC(m_dc);
	CBitmap m_bitmap;
	m_bitmap.LoadBitmap(IDB_MAIN);
	m_memdc.SelectObject(&m_bitmap);
	CRect m_rect;
//	GetClientRect(m_rect);
	m_dc->BitBlt(0,0,800,700,&m_memdc,0,0,SRCCOPY);
	
	m_bitmap.DeleteObject();
//	m_memdc.DeleteDC();

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
HCURSOR CPeculiarMenuDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPeculiarMenuDlg::OnOK() 
{	
	//m_memdc.DeleteDC();

}

void CPeculiarMenuDlg::OnButton1() 
{
	m_pMenu = GetSystemMenu(FALSE);
	m_pMenu->EnableMenuItem(1,MF_BYPOSITION |MF_DISABLED);
}
