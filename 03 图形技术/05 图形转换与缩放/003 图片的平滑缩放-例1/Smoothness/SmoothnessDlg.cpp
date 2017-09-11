// SmoothnessDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Smoothness.h"
#include "SmoothnessDlg.h"

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
// CSmoothnessDlg dialog

CSmoothnessDlg::CSmoothnessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSmoothnessDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSmoothnessDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSmoothnessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSmoothnessDlg)
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
	DDX_Control(pDX, IDC_PICTURE, m_picture);
	DDX_Control(pDX, IDC_FRAME, m_frame);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSmoothnessDlg, CDialog)
	//{{AFX_MSG_MAP(CSmoothnessDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTOPEN, OnButopen)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER1, OnReleasedcaptureSlider1)
	ON_BN_CLICKED(IDC_BUTDRAW, OnButdraw)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSmoothnessDlg message handlers

BOOL CSmoothnessDlg::OnInitDialog()
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
	dlg.Create(IDD_DIALOGFRAME);
	CRect rect;
	m_frame.GetClientRect(&rect);
	m_frame.MapWindowPoints(this,rect);
	dlg.MoveWindow(rect);
	dlg.ShowWindow(SW_SHOW);
	m_picture.SetParent(&dlg);
	CRect bmprect;
	m_picture.GetClientRect(&bmprect);
	m_picture.MoveWindow(0,0,bmprect.Width(),bmprect.Height());
	m_slider.SetRange(10,1000,true);
	m_slider.SetPos(100);
	m_edit.SetWindowText("100%");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSmoothnessDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSmoothnessDlg::OnPaint() 
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
HCURSOR CSmoothnessDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSmoothnessDlg::OnButopen() 
{
	// TODO: Add your control notification handler code here
	CFileDialog m_dialog (true,"bmp",NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"位图文件(*.bmp)|*.bmp",this);
	if (m_dialog.DoModal()==IDOK)
	{
		CString str;
		str = m_dialog.GetPathName();
		m_hBitmap=(HBITMAP)::LoadImage(AfxGetInstanceHandle(),str,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTCOLOR|LR_DEFAULTSIZE);
		if (m_hBitmap != NULL)
		{
			m_picture.SetBitmap(m_hBitmap);
		}	
		BITMAP bmp;
		GetObject(m_hBitmap,sizeof(bmp),&bmp);
		CRect rect;
		dlg.GetClientRect(rect);	
		int xpos = dlg.GetScrollPos(SB_HORZ);
		if (xpos != 0)
			dlg.ScrollWindow(xpos,0); //恢复窗口的水平滚动区域
		int ypos = dlg.GetScrollPos(SB_VERT);
		if (ypos != 0)
			dlg.ScrollWindow(0,ypos); //恢复窗口的垂直滚动区域
		
		SCROLLINFO vinfo;	
		vinfo.cbSize = sizeof(vinfo);
		vinfo.fMask = SIF_ALL;
		vinfo.nPage = bmp.bmHeight/10;
		vinfo.nMax= bmp.bmHeight-rect.Height()+bmp.bmHeight/10;
		vinfo.nMin = 0;
		vinfo.nTrackPos = 0;
		vinfo.nPos = 0;	
		//设置垂直滚动条信息
		dlg.SetScrollInfo(SB_VERT,&vinfo);

		vinfo.fMask = SIF_ALL;
		vinfo.nPage = bmp.bmWidth/10;
		vinfo.nMax= bmp.bmWidth-rect.Width()+bmp.bmWidth/10;
		vinfo.nMin = 0;
		vinfo.nPos  = 0;
		vinfo.nTrackPos = 0;
		vinfo.cbSize = sizeof(vinfo);
		//设置水平滚动条信息
		dlg.SetScrollInfo(SB_HORZ,&vinfo);
	}
}

void CSmoothnessDlg::OnReleasedcaptureSlider1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CString str;
	str.Format("%d%%",m_slider.GetPos());
	m_edit.SetWindowText(str);
	*pResult = 0;
}

void CSmoothnessDlg::OnButdraw() 
{
	// TODO: Add your control notification handler code here
	CRect rect;
	dlg.GetClientRect(rect);	
	int xpos = dlg.GetScrollPos(SB_HORZ);
	if (xpos != 0)
		dlg.ScrollWindow(xpos,0); //恢复窗口的水平滚动区域
	int ypos = dlg.GetScrollPos(SB_VERT);
	if (ypos != 0)
		dlg.ScrollWindow(0,ypos); //恢复窗口的垂直滚动区域

	CDC* pDC = m_picture.GetDC();
	//将位图选进设备场景中
	CDC memdc;	
	memdc.CreateCompatibleDC( pDC );
	memdc.SelectObject(m_hBitmap);
	BITMAP bmp;
	GetObject(m_hBitmap,sizeof(bmp),&bmp);
	int x,y;
	x = bmp.bmWidth*m_slider.GetPos()/100;
	y = bmp.bmHeight*m_slider.GetPos()/100;
	m_picture.MoveWindow(rect.left,rect.top,x,y,true);
	pDC->StretchBlt(rect.left,rect.top,x,y,&memdc,0,0,
			bmp.bmWidth,bmp.bmHeight,SRCCOPY);	
	memdc.DeleteDC();
	
	SCROLLINFO vinfo;	
	vinfo.cbSize = sizeof(vinfo);
	vinfo.fMask = SIF_ALL;
	vinfo.nPage = y/10;
	vinfo.nMax= y-rect.Height()+y/10;
	vinfo.nMin = 0;
	vinfo.nTrackPos = 0;
	vinfo.nPos = 0;	
	//设置垂直滚动条信息
	dlg.SetScrollInfo(SB_VERT,&vinfo);

	vinfo.fMask = SIF_ALL;
	vinfo.nPage = x/10;
	vinfo.nMax= x-rect.Width()+x/10;
	vinfo.nMin = 0;
	vinfo.nPos  = 0;
	vinfo.nTrackPos = 0;
	vinfo.cbSize = sizeof(vinfo);
	//设置水平滚动条信息
	dlg.SetScrollInfo(SB_HORZ,&vinfo);
}
