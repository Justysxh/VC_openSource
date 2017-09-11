// PosManageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PosManage.h"
#include "PosManageDlg.h"

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
// CPosManageDlg dialog

CPosManageDlg::CPosManageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPosManageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPosManageDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPosManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPosManageDlg)
	DDX_Control(pDX, IDC_SENDDATA, m_Send);
	DDX_Control(pDX, IDC_RECEIVEDATA, m_Receive);
	DDX_Control(pDX, IDC_MSCOMM1, m_Com);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPosManageDlg, CDialog)
	//{{AFX_MSG_MAP(CPosManageDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_COM1, OnCom1)
	ON_BN_CLICKED(IDC_COM2, OnCom2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPosManageDlg message handlers

BOOL CPosManageDlg::OnInitDialog()
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
	
	CButton* pButton = (CButton*)GetDlgItem(IDC_COM1);
	pButton->SetCheck(1);
	m_Com.SetCommPort(1);
	m_Com.SetPortOpen(TRUE);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPosManageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPosManageDlg::OnPaint() 
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
HCURSOR CPosManageDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPosManageDlg::OnOK() 
{

}

void CPosManageDlg::OnButton5() 
{
	OnCancel();	
}

void CPosManageDlg::OnCom1() 
{
	CButton* pButton = (CButton*)GetDlgItem(IDC_COM1);
	if (pButton->GetCheck())
	{
		m_Com.SetPortOpen(FALSE);
		m_Com.SetCommPort(1);	
		m_Com.SetPortOpen(TRUE);
	}
}

void CPosManageDlg::OnCom2() 
{
	CButton* pButton = (CButton*)GetDlgItem(IDC_COM2);
	if (pButton->GetCheck())
	{
		m_Com.SetPortOpen(FALSE);
		m_Com.SetCommPort(2);	
		m_Com.SetPortOpen(TRUE);
	}	
}

//≤‚ ‘¥Ú”°
void CPosManageDlg::OnButton1() 
{
	m_Com.SetOutput((COleVariant)(CString)(27+'@'));
	m_Com.SetOutput((COleVariant)(CString)(27+'z'+1));
	m_Com.SetOutput((COleVariant)(CString)(27+'d'+4));
	CString str;
	m_Send.GetWindowText(str);
	m_Com.SetOutput((COleVariant)(str));
	(COleVariant)str = m_Com.GetInput();
	m_Receive.SetWindowText(str);
}

void CPosManageDlg::OnButton2() 
{
	m_Com.SetOutput((COleVariant)(CString)(13+10));	
}

void CPosManageDlg::OnButton3() 
{
	m_Com.SetOutput((COleVariant)(CString)(27+'@'));
	m_Com.SetOutput((COleVariant)(CString)(27+'z'+1));
	m_Com.SetOutput((COleVariant)(CString)(27+'d'+4));
	m_Com.SetOutput((COleVariant)(CString)(""+13+10));
}

void CPosManageDlg::OnButton4() 
{
	m_Com.SetOutput((COleVariant)(CString)(27+'@'));
	m_Com.SetOutput((COleVariant)(CString)(27+'z'+1));
	m_Com.SetOutput((COleVariant)(CString)(27+'d'+4));
	m_Com.SetOutput((COleVariant)(CString)(""+29+79+75));	
}
