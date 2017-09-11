// delviewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "delview.h"
#include "delviewDlg.h"
#include "ADOConn.h"

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
// CDelviewDlg dialog

CDelviewDlg::CDelviewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDelviewDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDelviewDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDelviewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDelviewDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDelviewDlg, CDialog)
	//{{AFX_MSG_MAP(CDelviewDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDelviewDlg message handlers

BOOL CDelviewDlg::OnInitDialog()
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
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	_bstr_t vSQL;
	CString str;
	vSQL="select*from sysobjects where xtype='V'";
	_RecordsetPtr m_pRecordset;
    m_pRecordset=m_AdoConn.GetRecordSet(vSQL);
	while(m_pRecordset->adoEOF==0)
	{
		str=(char*)(_bstr_t)m_pRecordset->GetCollect("name");
		m_list.AddString(str);
		m_pRecordset->MoveNext();
	}

	m_AdoConn.ExitConnect();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDelviewDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDelviewDlg::OnPaint() 
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
HCURSOR CDelviewDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDelviewDlg::OnOK() 
{
	// TODO: Add extra validation here
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	_bstr_t sql;
	CString str;
	int i;
	i = m_list.GetCurSel();
	if(i<0)
	{
		MessageBox("请选择要删除的视图");
		return;
	}
	m_list.GetText(i,str);
	sql="drop view "+str+" ";
	m_AdoConn.ExecuteSQL(sql);
	m_list.ResetContent();
	_bstr_t vSQL;
	vSQL="select*from sysobjects where xtype='V'";
	_RecordsetPtr m_pRecordset;
    m_pRecordset=m_AdoConn.GetRecordSet(vSQL);
	while(m_pRecordset->adoEOF==0)
	{
		str=(char*)(_bstr_t)m_pRecordset->GetCollect("name");
		m_list.AddString(str);
		m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();
//	CDialog::OnOK();
}
