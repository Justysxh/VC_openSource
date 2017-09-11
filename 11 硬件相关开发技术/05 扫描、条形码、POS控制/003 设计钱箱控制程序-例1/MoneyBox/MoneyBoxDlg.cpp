// MoneyBoxDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MoneyBox.h"
#include "MoneyBoxDlg.h"

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
// CMoneyBoxDlg dialog

CMoneyBoxDlg::CMoneyBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMoneyBoxDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMoneyBoxDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMoneyBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMoneyBoxDlg)
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_TITLE, m_Title);
	DDX_Control(pDX, IDC_MSCOMM1, m_Com);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMoneyBoxDlg, CDialog)
	//{{AFX_MSG_MAP(CMoneyBoxDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK2, OnOk2)
	ON_BN_CLICKED(IDC_COM1, OnCom1)
	ON_BN_CLICKED(IDC_COM2, OnCom2)
	ON_BN_CLICKED(IDC_COM3, OnCom3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMoneyBoxDlg message handlers

BOOL CMoneyBoxDlg::OnInitDialog()
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

	SetIcon(m_hIcon, TRUE);		
	SetIcon(m_hIcon, FALSE);
	
	m_List.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_TWOCLICKACTIVATE);
	m_List.InsertColumn(1,"商品名称",LVCFMT_CENTER,100);
	m_List.InsertColumn(2,"条形码",LVCFMT_CENTER,100);
	m_List.InsertColumn(3,"单价",LVCFMT_CENTER,80);
	m_List.InsertColumn(4,"数量",LVCFMT_CENTER,80);
	m_List.InsertColumn(5,"金额",LVCFMT_CENTER,80);

	m_List.InsertItem(0,"");
	m_List.SetItemText(0,0,"华龙方便面");
	m_List.SetItemText(0,1,"4542156854754");
	m_List.SetItemText(0,2,"0.8");
	m_List.SetItemText(0,3,"10");
	m_List.SetItemText(0,4,"8");


	m_List.InsertItem(1,"");
	m_List.SetItemText(1,0,"中华牙膏");
	m_List.SetItemText(1,1,"4542564854754");
	m_List.SetItemText(1,2,"2.4");
	m_List.SetItemText(1,3,"10");
	m_List.SetItemText(1,4,"24");

	m_List.InsertItem(2,"");
	m_List.SetItemText(2,0,"舒肤佳香皂");
	m_List.SetItemText(2,1,"4542564854111");
	m_List.SetItemText(2,2,"3.5");
	m_List.SetItemText(2,3,"20");
	m_List.SetItemText(2,4,"70");


	CWnd* pCtrl = GetDlgItem(IDC_COM1 );
	m_Com.SetCommPort(1);
	m_Com.SetPortOpen(TRUE);	
	((CButton*)pCtrl)->SetCheck(1);
	return TRUE;  
}

void CMoneyBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMoneyBoxDlg::OnPaint() 
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
HCURSOR CMoneyBoxDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMoneyBoxDlg::OnOK() 
{
	//Chr$(27);Chr$(112);Chr$(0);Chr$(5);Chr$(255)   '钱箱控制
	char ctrl[5]= {27,112,0,5,255};
	m_Com.SetOutput((COleVariant)ctrl);
}

void CMoneyBoxDlg::OnOk2() 
{
	CDialog::OnCancel();	
}

void CMoneyBoxDlg::OnCom1() 
{	
	CButton* pCtrl = (CButton*)GetDlgItem(IDC_COM1 );
	if (pCtrl->GetCheck())
	{
		m_Com.SetPortOpen(FALSE);
		m_Com.SetCommPort(1);
		m_Com.SetPortOpen(TRUE);
	}
}

void CMoneyBoxDlg::OnCom2() 
{
	CButton* pCtrl = (CButton*)GetDlgItem(IDC_COM2);
	if (pCtrl->GetCheck())
	{
		m_Com.SetPortOpen(FALSE);
		m_Com.SetCommPort(1);
		m_Com.SetPortOpen(TRUE);
	}
}

void CMoneyBoxDlg::OnCom3() 
{
	CButton* pCtrl = (CButton*)GetDlgItem(IDC_COM3 );
	if (pCtrl->GetCheck())
	{
		m_Com.SetPortOpen(FALSE);
		m_Com.SetCommPort(1);
		m_Com.SetPortOpen(TRUE);
	}	
}
