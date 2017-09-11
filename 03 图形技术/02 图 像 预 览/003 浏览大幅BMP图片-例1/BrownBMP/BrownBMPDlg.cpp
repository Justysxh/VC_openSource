// BrownBMPDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BrownBMP.h"
#include "BrownBMPDlg.h"

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
// CBrownBMPDlg dialog

CBrownBMPDlg::CBrownBMPDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBrownBMPDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBrownBMPDlg)
	m_Path = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBrownBMPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBrownBMPDlg)
	DDX_Control(pDX, IDC_FRAME, m_Frame);
	DDX_Control(pDX, IDC_BMP, m_Bmp);
	DDX_Text(pDX, IDC_PATH, m_Path);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBrownBMPDlg, CDialog)
	//{{AFX_MSG_MAP(CBrownBMPDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BROWN, OnBrown)
	ON_WM_HSCROLL()
	ON_WM_MOUSEWHEEL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBrownBMPDlg message handlers

BOOL CBrownBMPDlg::OnInitDialog()
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

	//创建子对话框
	m_BrownDlg.Create(IDD_BMPDLG_DIALOG,this);
	
	CRect rect,framerect;
	m_BrownDlg.GetClientRect(rect);
	
	m_Frame.GetClientRect(framerect);
	m_Frame.MapWindowPoints(this,framerect);
	m_BrownDlg.MoveWindow(framerect);
	m_BrownDlg.ShowWindow(SW_SHOW);

	
	m_Bmp.SetParent(&m_BrownDlg);
	CRect bmprect;
	m_Bmp.GetClientRect(bmprect);
	m_Bmp.MoveWindow(0,0,bmprect.Width(),bmprect.Height());
	
	//m_Horz.SetParent(&m_Parent);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBrownBMPDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBrownBMPDlg::OnPaint() 
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
HCURSOR CBrownBMPDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBrownBMPDlg::OnOK() 
{

}

void CBrownBMPDlg::OnBrown() 
{
	CFileDialog dlg(TRUE,"","",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"位图文件(BMP)|*.bmp",this);
	if (dlg.DoModal()==IDOK)
	{
		CString filename = dlg.GetPathName();
		m_Path = filename;
		UpdateData(FALSE);
		HANDLE handle =  LoadImage(NULL,filename,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);

		m_Bmp.SetBitmap((HBITMAP)handle);
		
		CRect bmprect,dlgrect;
		
		m_Bmp.GetClientRect(bmprect);
		m_BrownDlg.GetClientRect(dlgrect);
		
		int xpos = m_BrownDlg.GetScrollPos(SB_HORZ);
		if (xpos !=0)
			m_BrownDlg.ScrollWindow(xpos,0); //恢复窗口的水平滚动区域

		int ypos = m_BrownDlg.GetScrollPos(SB_VERT);
		if (ypos !=0)
			m_BrownDlg.ScrollWindow(0,ypos); //恢复窗口的垂直滚动区域

		
		SCROLLINFO vinfo;
		
		vinfo.cbSize = sizeof(vinfo);
		vinfo.fMask = SIF_ALL;
		vinfo.nPage = 100;
		vinfo.nMax= bmprect.Height()-dlgrect.Height()+100;
		vinfo.nMin = 0;
		vinfo.nTrackPos = 0;
		vinfo.nPos = 0;
		
		//设置垂直滚动条信息
		m_BrownDlg.SetScrollInfo(SB_VERT,&vinfo);

		vinfo.fMask = SIF_ALL;
		vinfo.nPage = 100;
		vinfo.nMax= bmprect.Width()-dlgrect.Width()+100;
		vinfo.nMin = 0;
		vinfo.nPos  = 0;
		vinfo.nTrackPos = 0;
		vinfo.cbSize = sizeof(vinfo);

		//设置水平滚动条信息
		m_BrownDlg.SetScrollInfo(SB_HORZ,&vinfo);

	}
}

void CBrownBMPDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
		
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

BOOL CBrownBMPDlg::PreTranslateMessage(MSG* pMsg) 
{
	return CDialog::PreTranslateMessage(pMsg);
}

BOOL CBrownBMPDlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	m_BrownDlg.OnMouseWheel(nFlags,zDelta,pt);
	return CDialog::OnMouseWheel(nFlags, zDelta, pt);
}
