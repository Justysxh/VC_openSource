// DrawcudeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Drawcude.h"
#include "DrawcudeDlg.h"
#include "math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define PI 3.1415926
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
// CDrawcudeDlg dialog

CDrawcudeDlg::CDrawcudeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDrawcudeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDrawcudeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDrawcudeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDrawcudeDlg)
	DDX_Control(pDX, IDC_PALETTE, m_palette);
	DDX_Control(pDX, IDC_EDIT4, m_angle);
	DDX_Control(pDX, IDC_EDIT3, m_height);
	DDX_Control(pDX, IDC_EDIT2, m_width);
	DDX_Control(pDX, IDC_EDIT1, m_length);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDrawcudeDlg, CDialog)
	//{{AFX_MSG_MAP(CDrawcudeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTDRAW, OnButdraw)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawcudeDlg message handlers

BOOL CDrawcudeDlg::OnInitDialog()
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

void CDrawcudeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDrawcudeDlg::OnPaint() 
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
HCURSOR CDrawcudeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDrawcudeDlg::OnButdraw() 
{
	// TODO: Add your control notification handler code here
	CDC* pDC;
	pDC = m_palette.GetDC();	
	CRect rc,rect;
	m_palette.GetClientRect(rect);
	m_palette.GetWindowRect(rc);
	pDC->FillRect(rect,NULL);
	//取出中心点
	CPoint center;    
	center.x=rc.Width()/2;
	center.y=rc.Height()/2;
	pDC->SetViewportOrg(center);
	CString slength,swidth,sheight,sangle;
	m_length.GetWindowText(slength);
	m_width.GetWindowText(swidth);
	m_height.GetWindowText(sheight);
	m_angle.GetWindowText(sangle);
	int nlength,nwidth,nheight,nangle;
	nlength=atoi(slength);
	nwidth=atoi(swidth);
	nheight=atoi(sheight);
	nangle=atoi(sangle);
	CPoint LTop,LBottom,RTop,RBottom;
	LTop.x=1-nlength/2;
	LTop.y=1-nheight/2;
	RTop.x=nlength/2;
	RTop.y=1-nheight/2;
	LBottom.x=1-nlength/2;
	LBottom.y=nheight/2;
	RBottom.x=nlength/2;
	RBottom.y=nheight/2;
	CPen pen(PS_SOLID,1,RGB(0,0,0));
	CPen DOTPen; //虚线
	DOTPen.CreatePen(PS_DOT,1,RGB(0,0,0));
	pDC->SelectObject(&pen);
	//画正面矩形
	pDC->Rectangle(LTop.x,LTop.y,RBottom.x,RBottom.y);
	CPoint LeftTop,RightTop;
	LeftTop.x=(long)(LTop.x+(cos(nangle*PI/180)*nwidth));
	LeftTop.y=(long)(LTop.y-(sin(nangle*PI/180)*nwidth));
	RightTop.x=LeftTop.x+nlength;
	RightTop.y=LeftTop.y;
	pDC->MoveTo(LTop);
	pDC->LineTo(LeftTop);
	pDC->LineTo(RightTop);
	pDC->LineTo(RTop);
	CPoint Other,DotPoint;
	DotPoint.x=LeftTop.x ;
	DotPoint.y=LeftTop.y+nheight;
	pDC->MoveTo(RightTop);
	if(nangle<89)
	{
		pDC->SelectObject(&pen);
		Other.x=RightTop.x;
		Other.y=RightTop.y+nheight;
		pDC->LineTo(Other);
		pDC->LineTo(RBottom);
		pDC->SelectObject(&DOTPen);
		pDC->MoveTo(LeftTop);
		pDC->LineTo(DotPoint);
		pDC->LineTo(LBottom);
	}
	else
	{	
		pDC->SelectObject(&DOTPen);
		Other.x=RightTop.x;
		Other.y=RightTop.y+nheight;
		pDC->LineTo(Other);
		pDC->LineTo(RBottom);
		pDC->SelectObject(&pen);
		pDC->MoveTo(LeftTop);
		pDC->LineTo(DotPoint);
		pDC->LineTo(LBottom);
	}
	pDC->SelectObject(&DOTPen);
	pDC->MoveTo(DotPoint);
	pDC->LineTo(Other);
	
}
