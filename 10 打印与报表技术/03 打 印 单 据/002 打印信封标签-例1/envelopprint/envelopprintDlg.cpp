// envelopprintDlg.cpp : implementation file
//

#include "stdafx.h"
#include "envelopprint.h"
#include "envelopprintDlg.h"
#include "ADOConn.h"
#include "Preview.h"

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
// CEnvelopprintDlg dialog

CEnvelopprintDlg::CEnvelopprintDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEnvelopprintDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEnvelopprintDlg)
	m_edit = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEnvelopprintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnvelopprintDlg)
	DDX_Control(pDX, IDC_LIST1, m_grid);
	DDX_Text(pDX, IDC_EDIT1, m_edit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEnvelopprintDlg, CDialog)
	//{{AFX_MSG_MAP(CEnvelopprintDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTPREVIEW, OnButpreview)
	ON_BN_CLICKED(IDC_BUTPRINT, OnButprint)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnvelopprintDlg message handlers

BOOL CEnvelopprintDlg::OnInitDialog()
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
	UpdateData(true);
	m_grid.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_grid.InsertColumn(0,"收信人",LVCFMT_LEFT,100,0);
	m_grid.InsertColumn(1,"地址",LVCFMT_LEFT,100,1);
	m_grid.InsertColumn(2,"邮编",LVCFMT_LEFT,100,2);
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select* from xinjianbiao order by 收信人 desc");
	m_AdoConn.GetRecordSet((_bstr_t)sql);
	while(m_AdoConn.m_pRecordset->adoEOF==0)
	{
		m_grid.InsertItem(0,"");
		m_grid.SetItemText(0,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("收信人"));
		m_grid.SetItemText(0,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("地址"));
		m_grid.SetItemText(0,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("邮编"));
		m_AdoConn.m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEnvelopprintDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEnvelopprintDlg::OnPaint() 
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
HCURSOR CEnvelopprintDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEnvelopprintDlg::OnButpreview() 
{
	// TODO: Add your control notification handler code here
	CPreview dlg;
	dlg.m_sxr = sxr;
	dlg.m_dz = dz;
	dlg.m_yb = yb;
	dlg.edit = m_edit;
	dlg.hanshu();
	dlg.DoModal();
}

void CEnvelopprintDlg::OnButprint() 
{
	// TODO: Add your control notification handler code here
	CPreview dlg;
	dlg.m_sxr = sxr;
	dlg.m_dz = dz;
	dlg.m_yb = yb;
	dlg.edit = m_edit;
	dlg.hanshu();
	CPrintDialog m_printdlg(false);
	if (m_printdlg.DoModal()==IDOK)
	{
		CDC dc1;		
		dc1.Attach(m_printdlg.GetPrinterDC());			
		int leftmargin;
		leftmargin = dc1.GetDeviceCaps(PHYSICALOFFSETX);
		CRect m_rect(-leftmargin,0,dc1.GetDeviceCaps(PHYSICALWIDTH)-leftmargin,dc1.GetDeviceCaps(PHYSICALHEIGHT)) ;		
		dlg.DrawReport(m_rect,&dc1,true);
	}
}

void CEnvelopprintDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CPreview dlg;
	int pos;
	pos=m_grid.GetSelectionMark();
	sxr=m_grid.GetItemText(pos,0);
	dz=m_grid.GetItemText(pos,1);
	yb=m_grid.GetItemText(pos,2);
	*pResult = 0;
}
