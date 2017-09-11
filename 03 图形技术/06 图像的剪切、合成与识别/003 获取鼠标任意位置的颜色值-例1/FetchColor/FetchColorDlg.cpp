// FetchColorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FetchColor.h"
#include "FetchColorDlg.h"

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
// CFetchColorDlg dialog

CFetchColorDlg::CFetchColorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFetchColorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFetchColorDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFetchColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFetchColorDlg)
	DDX_Control(pDX, IDC_TEST, m_test);
	DDX_Control(pDX, IDC_STATIC1, m_image);
	DDX_Control(pDX, IDC_EDITRED, m_red);
	DDX_Control(pDX, IDC_EDITGREEN, m_green);
	DDX_Control(pDX, IDC_EDITBLUE, m_blue);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFetchColorDlg, CDialog)
	//{{AFX_MSG_MAP(CFetchColorDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFetchColorDlg message handlers

BOOL CFetchColorDlg::OnInitDialog()
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

void CFetchColorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFetchColorDlg::OnPaint() 
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
HCURSOR CFetchColorDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFetchColorDlg::OnOK() 
{
	//CDialog::OnOK();
}

void CFetchColorDlg::OnMouseMove(UINT nFlags, CPoint point) 
{	
	CDialog::OnMouseMove(nFlags, point);
	CWnd* temp = ChildWindowFromPoint(point);
	if (temp)
	{				
		CDC* m_dc = temp->GetDC();
		COLORREF m_color;

		this->MapWindowPoints(temp,&point,1);
		
		//获取颜色值
		m_color = m_dc->GetPixel(point);
		
		int r,g,b;
		r = GetRValue(m_color);
		g = GetGValue(m_color);
		b = GetBValue(m_color);
		CString str;
		
		str.Format("%i",r);
		m_red.SetWindowText(str);

		str.Format("%i",g);
		m_green.SetWindowText(str);

		str.Format("%i",b);
		m_blue.SetWindowText(str);
		
		CRect m_rect;
		m_test.GetClientRect(m_rect);
		CDC* dc = m_test.GetDC();
		CBrush m_brush(RGB(r,g,b));
		dc->FillRect(m_rect,&m_brush);
	}
}

BOOL CFetchColorDlg::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message==WM_MOUSEMOVE)
	{
	//	if (pMsg->hwnd == m_image.m_hWnd )
	//	FetchColor(pMsg->hwnd,pMsg->lParam);
	
	
	
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CFetchColorDlg::FetchColor(HWND m_handle, WORD lparam)
{
	int x = LOWORD(lparam);
	int y = HIWORD(lparam);


}
