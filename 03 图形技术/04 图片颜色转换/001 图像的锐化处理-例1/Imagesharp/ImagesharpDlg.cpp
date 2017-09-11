// ImagesharpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Imagesharp.h"
#include "ImagesharpDlg.h"

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
// CImagesharpDlg dialog

CImagesharpDlg::CImagesharpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImagesharpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CImagesharpDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CImagesharpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImagesharpDlg)
	DDX_Control(pDX, IDC_IMAGE1, m_image1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CImagesharpDlg, CDialog)
	//{{AFX_MSG_MAP(CImagesharpDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHARP, OnSharp)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImagesharpDlg message handlers

BOOL CImagesharpDlg::OnInitDialog()
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

void CImagesharpDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CImagesharpDlg::OnPaint() 
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
HCURSOR CImagesharpDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CImagesharpDlg::OnOK() 
{
	//CDialog::OnOK();
}

void CImagesharpDlg::OnSharp() 
{
	CDC * m_dc;
	CRect m_rect;
	
	m_image1.GetClientRect(m_rect);
	m_dc = m_image1.GetDC();
	
	int r1,g1,b1,r2,g2,b2;

	for (int i = 1;i<m_rect.right+1;i++)
		for (int j = 1; j< m_rect.bottom+1;j++)
		{
			COLORREF color = 	m_dc->GetPixel(i,j);
			COLORREF nextcolor = m_dc->GetPixel(i-1,j-1);

            r1 = (color & 0xFF);
            g1 = (int)(color & 62580) / 256;
            b1 = (int)(color & 0xFF0000) / 65536;

            r2 = (nextcolor & 0xFF);
            g2 = (int)(nextcolor & 62580) / 256;
            b2 = (int)(nextcolor & 0xFF0000) / 65536;

			r1+= (r1 - r2) /2;
            g1 +=  (g1 - g2) / 2;
            b1 +=  (b1 - b2) / 2;
			if ( r1 > 255)
				r1 = 255;
            if ( r1 < 0 )
				r1 = 0;
            if ( b1 > 255)
				b1 = 255;
            if (b1 < 0)
				b1 = 0;
            if( g1 > 255)
				g1 = 255;
            if ( g1 < 0 )
				g1 = 0;
			m_dc->SetPixel(i,j,RGB(r1,g1,b1));
		}
}

void CImagesharpDlg::OnCancel() 
{
	CDialog::OnCancel();	
}
