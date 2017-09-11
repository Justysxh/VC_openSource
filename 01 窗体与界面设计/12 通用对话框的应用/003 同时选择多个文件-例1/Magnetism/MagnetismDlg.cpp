// MagnetismDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Magnetism.h"
#include "MagnetismDlg.h"

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
// CMagnetismDlg dialog

CMagnetismDlg::CMagnetismDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMagnetismDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMagnetismDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_IsCreate = FALSE;
	m_Berth = FALSE;
}

void CMagnetismDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMagnetismDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMagnetismDlg, CDialog)
	//{{AFX_MSG_MAP(CMagnetismDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_WM_MOVE()
	ON_WM_NCLBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMagnetismDlg message handlers

BOOL CMagnetismDlg::OnInitDialog()
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
	m_Dlg = new CChildDlg;
	m_Dlg->Create(IDD_CHILD_DIALOG,this);
	CRect pRect,cRect;
	GetWindowRect(pRect);
	MapWindowPoints(this,pRect);
	m_Dlg->GetWindowRect(cRect);
	m_Dlg->ShowWindow(SW_SHOW);
	m_Width = pRect.Width();
	m_Height = pRect.Height();
	m_Point.x = pRect.left;
	m_Point.y = pRect.top;
	m_IsCreate = TRUE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMagnetismDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMagnetismDlg::OnPaint() 
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
HCURSOR CMagnetismDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMagnetismDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	m_Dlg->DestroyWindow();
	CDialog::OnClose();
}

void CMagnetismDlg::OnMove(int x, int y) 
{
	CDialog::OnMove(x, y);
	
	// TODO: Add your message handler code here
	if(m_IsCreate == TRUE)
	{
		CRect pRect,cRect;
		GetWindowRect(pRect);
		MapWindowPoints(this,pRect);
		m_Dlg->GetWindowRect(cRect);
		if(pRect.left-cRect.right<20 && pRect.left-cRect.right>0 && (
			pRect.top>cRect.top-m_Height && pRect.bottom<cRect.bottom+m_Height))
			pRect.left = cRect.right;
		else if(cRect.left-pRect.right<20 && cRect.left-pRect.right>0 && (
			pRect.top>cRect.top-m_Height && pRect.bottom<cRect.bottom+m_Height))
			pRect.left = cRect.left - m_Width;
		else if(cRect.top-pRect.bottom<20 && cRect.top-pRect.bottom>0 && (
			pRect.left>cRect.left-m_Width && pRect.right<cRect.right+m_Width))
			pRect.top = cRect.top - m_Height;
		else if(pRect.top-cRect.bottom<20 && pRect.top-cRect.bottom>0 && (
			pRect.left>cRect.left-m_Width && pRect.right<cRect.right+m_Width))
			pRect.top = cRect.bottom;
		MoveWindow(pRect.left,pRect.top,m_Width,m_Height);
		if(m_Berth)
		{
			m_Dlg->MoveWindow(cRect.left+(pRect.left-m_Point.x),
				cRect.top+(pRect.top-m_Point.y),cRect.Width(),cRect.Height());
		}
		m_Point.x = pRect.left;
		m_Point.y = pRect.top;
	}
}

void CMagnetismDlg::OnNcLButtonDown(UINT nHitTest, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CRect pRect,cRect;
	GetWindowRect(pRect);
	MapWindowPoints(this,pRect);
	m_Dlg->GetWindowRect(cRect);
	if(pRect.left-cRect.right == 0)
	{
		m_Berth = TRUE;
	}
	else if(cRect.left-pRect.right == 0)
	{
		m_Berth = TRUE;
	}
	else if(cRect.top-pRect.bottom == 0)
	{
		m_Berth = TRUE;
	}
	else if(pRect.top-cRect.bottom == 0)
	{
		m_Berth = TRUE;
	}
	else
		m_Berth = FALSE;
	CDialog::OnNcLButtonDown(nHitTest, point);
}
