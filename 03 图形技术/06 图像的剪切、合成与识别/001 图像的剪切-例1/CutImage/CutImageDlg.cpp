// CutImageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CutImage.h"
#include "CutImageDlg.h"

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
// CCutImageDlg dialog

CCutImageDlg::CCutImageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCutImageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCutImageDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCutImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCutImageDlg)
	DDX_Control(pDX, IDC_SOURCEIMAGE, m_sourceimage);
	DDX_Control(pDX, IDC_CUTIMAGE, m_cutimage);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCutImageDlg, CDialog)
	//{{AFX_MSG_MAP(CCutImageDlg)

	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCutImageDlg message handlers

BOOL CCutImageDlg::OnInitDialog()
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

void CCutImageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCutImageDlg::OnPaint() 
{
	OnOK() ;
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
HCURSOR CCutImageDlg::OnQueryDragIcon()
{
	OnOK();
	return (HCURSOR) m_hIcon;
}

void CCutImageDlg::OnOK() 
{

	CBitmap m_bitmap;
	HBITMAP m_hbitmap = m_sourceimage.GetBitmap();
	
	//附加位图句柄
	m_bitmap.Attach(m_hbitmap);

	CDC* m_dc = m_cutimage.GetDC();
	CRgn m_rgn;
	BITMAP m_bitinfo;
	m_bitmap.GetBitmap(&m_bitinfo);
	//创建一个剪切区域
	m_rgn.CreateEllipticRgn(150,1,m_bitinfo.bmWidth-1,m_bitinfo.bmHeight-1);
	
	CDC* m_sourcedc = m_sourceimage.GetDC();
	//选中剪切区域
	m_dc->SelectClipRgn(&m_rgn,RGN_COPY );
	m_dc->BitBlt(0,0,m_bitinfo.bmWidth,m_bitinfo.bmHeight,m_sourcedc,0,0,SRCCOPY);

	m_sourcedc->SelectClipRgn(&m_rgn,RGN_COPY );
	m_sourcedc->BitBlt(0,0,m_bitinfo.bmWidth,m_bitinfo.bmHeight,m_dc,0,0,WHITENESS);

	m_bitmap.Detach();
}


BOOL CCutImageDlg::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message==0x0000000f)
		OnOK();	
	return CDialog::PreTranslateMessage(pMsg);
}
