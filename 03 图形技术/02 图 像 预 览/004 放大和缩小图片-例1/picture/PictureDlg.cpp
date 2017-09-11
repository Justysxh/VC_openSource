// PictureDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Picture.h"
#include "PictureDlg.h"

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
// CPictureDlg dialog

CPictureDlg::CPictureDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPictureDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPictureDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPictureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPictureDlg)
	DDX_Control(pDX, IDC_PICTURE, m_picture);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPictureDlg, CDialog)
	//{{AFX_MSG_MAP(CPictureDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUT50, OnBut50)
	ON_BN_CLICKED(IDC_BUT75, OnBut75)
	ON_BN_CLICKED(IDC_BUT100, OnBut100)
	ON_BN_CLICKED(IDC_BUT150, OnBut150)
	ON_BN_CLICKED(IDC_BUTCHM, OnButchm)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPictureDlg message handlers

BOOL CPictureDlg::OnInitDialog()
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

void CPictureDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPictureDlg::OnPaint() 
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
	//开始缩放
	switch(num)
	{
	case 0://50%显示
		DrawPicture(num);
		break;
	case 1://75%显示
		DrawPicture(num);
		break;
	case 2://100%显示
		DrawPicture(num);
		break;
	case 3://150%显示
		DrawPicture(num);
		break;
	case 4://充满窗口
		DrawPicture(num);
		break;
	}
	m_picture.UpdateWindow();
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPictureDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPictureDlg::OnBut50() 
{
	// TODO: Add your control notification handler code here
	num = 0;
	DrawPicture(0);
}

void CPictureDlg::OnBut75() 
{
	// TODO: Add your control notification handler code here
	num = 1;
	DrawPicture(1);
}

void CPictureDlg::OnBut100() 
{
	// TODO: Add your control notification handler code here
	num = 2;
	DrawPicture(2);
}

void CPictureDlg::OnBut150() 
{
	// TODO: Add your control notification handler code here
	num = 3;
	DrawPicture(3);
}

void CPictureDlg::OnButchm() 
{
	// TODO: Add your control notification handler code here
	num = 4;
	DrawPicture(4);
}

void CPictureDlg::DrawPicture(int num)
{
	//获得窗口大小
	CRect r;
	m_picture.GetClientRect(&r);
	CDC* pDC = m_picture.GetDC();	
	//填充背景
	pDC->FillRect(&r,NULL);
	//将位图选进设备场景中
	CBitmap cbmp;
	cbmp.LoadBitmap(IDB_BITMAP1);
	CDC memdc;
	memdc.CreateCompatibleDC(pDC);
	memdc.SelectObject(&cbmp);
	
	//获得位图参数
	long width,height;
	cbmp.GetBitmap(&bmp);
	width = bmp.bmWidth;
	height = bmp.bmHeight;
	//开始缩放
	switch(num)
	{
	case 0://50%显示
		pDC->StretchBlt(r.left,r.top,(int)(width*0.5),(int)(height*0.5),&memdc,0,0,
			bmp.bmWidth,bmp.bmHeight,SRCCOPY);
		break;
	case 1://75%显示
		pDC->StretchBlt(r.left,r.top,(int)(width*0.75),(int)(height*0.75),&memdc,0,0,
			bmp.bmWidth,bmp.bmHeight,SRCCOPY);
		break;
	case 2://100%显示
		pDC->BitBlt(r.left,r.top,r.Width(),r.Height(),&memdc,0,0,SRCCOPY);
		break;
	case 3://150%显示
		pDC->StretchBlt(r.left,r.top,(int)(width*1.5),(int)(height*1.5),&memdc,0,0,
			bmp.bmWidth,bmp.bmHeight,SRCCOPY);
		break;
	case 4://充满窗口
		pDC->StretchBlt(r.left,r.top,r.Width(),r.Height(),&memdc,0,0,
			bmp.bmWidth,bmp.bmHeight,SRCCOPY);
		break;
	}
	m_picture.UpdateWindow();
}
