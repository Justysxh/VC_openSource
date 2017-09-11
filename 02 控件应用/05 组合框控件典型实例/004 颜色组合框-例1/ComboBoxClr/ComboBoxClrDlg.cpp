// ComboBoxClrDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ComboBoxClr.h"
#include "ComboBoxClrDlg.h"


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
// CComboBoxClrDlg dialog

CComboBoxClrDlg::CComboBoxClrDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CComboBoxClrDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CComboBoxClrDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_MAINICON);

	m_clrColor = RGB(255, 0, 255);
}

void CComboBoxClrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CComboBoxClrDlg)
	DDX_Control(pDX, IDC_DEMO, m_Demo);
	DDX_Control(pDX, IDC_COLORBOX, m_ColorBox);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CComboBoxClrDlg, CDialog)
	//{{AFX_MSG_MAP(CComboBoxClrDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COLORBOX, OnSelchangeColorbox)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComboBoxClrDlg message handlers

BOOL CComboBoxClrDlg::OnInitDialog()
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
	
	

	m_ColorBox.AddItem("红色", RGB(255, 0, 0));
	m_ColorBox.AddItem("蓝色", RGB(0, 0, 255));
	m_ColorBox.AddItem("绿色", RGB(0, 255, 0));
	m_ColorBox.AddItem("黄色", RGB(255, 255, 0));
	m_ColorBox.AddItem("粉色", RGB(255, 0, 255));	
	m_ColorBox.AddItem("棕色", RGB(255, 128, 64));



	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CComboBoxClrDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CComboBoxClrDlg::OnPaint() 
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

	CRect clientRC;
	m_Demo.GetClientRect(clientRC);
	CDC* pDC = m_Demo.GetDC();
	pDC->FillRect(clientRC, &CBrush(m_clrColor));
	m_Demo.ReleaseDC(pDC);
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CComboBoxClrDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CComboBoxClrDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
//	m_ColorBox.DrawItem(lpDrawItemStruct);	
	CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);
}

void CComboBoxClrDlg::OnOK() 
{
	m_ColorBox.AddItem("黄色", RGB(255, 255, 0));	
}

void CComboBoxClrDlg::OnSelchangeColorbox() 
{
	COLORREF clrColor = m_ColorBox.GetCurColor();
	if (clrColor != -1)
	{
		m_clrColor = clrColor;
		Invalidate();
	}
}
