// ChangeDisktopDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChangeDisktop.h"
#include "ChangeDisktopDlg.h"

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
// CChangeDisktopDlg dialog

CChangeDisktopDlg::CChangeDisktopDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChangeDisktopDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChangeDisktopDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChangeDisktopDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChangeDisktopDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChangeDisktopDlg, CDialog)
	//{{AFX_MSG_MAP(CChangeDisktopDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnLoad)
	ON_BN_CLICKED(IDOK2, Onrand)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChangeDisktopDlg message handlers

BOOL CChangeDisktopDlg::OnInitDialog()
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

void CChangeDisktopDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChangeDisktopDlg::OnPaint() 
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
HCURSOR CChangeDisktopDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CChangeDisktopDlg::OnOK() 
{
	CString path;
	if (m_list.GetCurSel() > 0)
	{
		m_list.GetText(m_list.GetCurSel(),path);
		SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, path.GetBuffer(0),
							  SPIF_UPDATEINIFILE);
	}

}

void CChangeDisktopDlg::OnLoad() 
{
	CString strFilter = "*.bmp|*.bmp||";
	CFileDialog filedialog(TRUE, NULL, NULL,
			OFN_FILEMUSTEXIST |
			OFN_HIDEREADONLY |
			OFN_PATHMUSTEXIST|
			OFN_ALLOWMULTISELECT,
			strFilter);


	if (filedialog.DoModal() == IDOK)
	{
		POSITION pos = filedialog.GetStartPosition();
		CString path,exname;
		while (NULL != pos)
		{
			path = filedialog.GetNextPathName(pos);
			exname = path.Right(4);
			exname.MakeUpper();
			if (exname == ".BMP") 
			m_list.AddString(path);
		}
		path.MakeReverse();
		int p = path.FindOneOf("\\");
		path.MakeReverse();

		m_edit.SetWindowText(path.Left(path.GetLength()-p));
		
	}
	
}

void CChangeDisktopDlg::Onrand() 
{
	int n = m_list.GetCount();
	int i = rand() % n;
	CString path;
	if (i > 0)
	{
		m_list.GetText(i,path);
		SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, path.GetBuffer(0),
							  SPIF_UPDATEINIFILE);
		m_list.SetCurSel(i);
	}
}
