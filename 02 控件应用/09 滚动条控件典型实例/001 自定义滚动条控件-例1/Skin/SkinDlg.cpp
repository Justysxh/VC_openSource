// SkinDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Skin.h"
#include "SkinDlg.h"

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
// CSkinDlg dialog

CSkinDlg::CSkinDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSkinDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSkinDlg)
	m_Rtext = _T("");
	m_Gtext = _T("");
	m_Btext = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pScroll = NULL;
}

void CSkinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSkinDlg)
	DDX_Control(pDX, IDC_COLOR, m_Color);
	DDX_Text(pDX, IDC_STATIC1, m_Rtext);
	DDX_Text(pDX, IDC_STATIC2, m_Gtext);
	DDX_Text(pDX, IDC_STATIC3, m_Btext);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSkinDlg, CDialog)
	//{{AFX_MSG_MAP(CSkinDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_HSCROLL()
	ON_WM_CTLCOLOR()
	ON_WM_SIZE()
	ON_WM_SIZING()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSkinDlg message handlers

BOOL CSkinDlg::OnInitDialog()
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

	

	m_Red.m_LeftArrow = IDB_REDLEFT;
	m_Red.m_RightArrow = IDB_REDRIGHT;
	m_Red.m_ChanelBK = IDB_REDBK;
	m_Red.m_ThumbBK = IDB_REDTHUMB;

	m_Red.CreateStatic(this,SBS_HORZ|WS_CHILD|SS_LEFT|SS_NOTIFY|WS_VISIBLE,IDC_RED,465);
	m_Red.SetScrollRange(0,255);

	m_Green.m_LeftArrow = IDB_GLEFTARROW;
	m_Green.m_RightArrow = IDB_GRIGHTARROW;
	m_Green.m_ChanelBK = IDB_GCHANELBK;
	m_Green.m_ThumbBK = IDB_GTHUMB;

	m_Green.CreateStatic(this,SBS_HORZ|WS_CHILD|SS_LEFT|SS_NOTIFY|WS_VISIBLE,IDC_GREEN,466);
	m_Green.SetScrollRange(0,255);


	m_Blue.m_LeftArrow = IDB_BLEFTARROW;
	m_Blue.m_RightArrow = IDB_BRIGHTARROW;
	m_Blue.m_ChanelBK = IDB_BCHANELBK;
	m_Blue.m_ThumbBK = IDB_BTHUMB;

	m_Blue.CreateStatic(this,SBS_HORZ|WS_CHILD|SS_LEFT|SS_NOTIFY|WS_VISIBLE,IDC_BLUE,467);
	m_Blue.SetScrollRange(0,255);

	m_Rvalue = 0;
	m_Bvalue = 0;
	m_Gvalue = 0;
	
	m_Rtext.Format("%i",m_Rvalue);
	m_Gtext.Format("%i",m_Gvalue);
	m_Btext.Format("%i",m_Bvalue);

	UpdateData(FALSE);
	



	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSkinDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSkinDlg::OnPaint() 
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

	//CScrollBar* pScroll = GetScrollBarCtrl(SB_HORZ);	
//	if (m_pScroll != NULL)
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSkinDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSkinDlg::OnOK() 
{

}

void CSkinDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	CString str;
	

	CCustomScroll* temp = (CCustomScroll*)(CWnd*)pScrollBar; 	
	int pos ;
	if (temp == NULL)
		return;
	if (nSBCode==SB_LINELEFT )
	{
		pos =  temp->m_CurPos-nPos;
	
	}
	else if (nSBCode==SB_LINERIGHT)
	{
		pos =  temp->m_CurPos+nPos;
	}
	else
	{
		pos = nPos;
	}

	if (temp->m_hWnd==m_Red.m_hWnd)
		m_Rvalue = pos;
	else if (temp->m_hWnd==m_Green.m_hWnd)
		m_Gvalue = pos;
	else if (temp->m_hWnd==m_Blue.m_hWnd)
		m_Bvalue = pos;
	
	m_Rtext.Format("%i",m_Rvalue);
	m_Gtext.Format("%i",m_Gvalue);
	m_Btext.Format("%i",m_Bvalue);
	
	UpdateData(FALSE);

	DrawColor();
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

HBRUSH CSkinDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}



void CSkinDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	CRect rect;
	//GetWindowRect(rect);
	
	//rect.DeflateRect(0,0,0,20);

	//HRGN hrgn =  CreateRectRgn(rect.left,rect.top,rect.right,rect.bottom);
	//OffsetRgn(hrgn,0,20);
	//SetWindowRgn(hrgn,TRUE);	
}

void CSkinDlg::OnSizing(UINT fwSide, LPRECT pRect) 
{
	CDialog::OnSizing(fwSide, pRect);	
}

void CSkinDlg::OnButton1() 
{

}

void CSkinDlg::DrawColor()
{
	CDC* pDC = m_Color.GetDC();
	CRect rect;
	m_Color.GetClientRect(rect);

	CBrush brush(RGB(m_Rvalue,m_Gvalue,m_Bvalue));
	
	pDC->FillRect(rect,&brush);

}
