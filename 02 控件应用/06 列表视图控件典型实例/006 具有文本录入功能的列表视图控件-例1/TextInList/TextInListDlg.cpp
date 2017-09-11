// TextInListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TextInList.h"
#include "TextInListDlg.h"
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
// CTextInListDlg dialog

CTextInListDlg::CTextInListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTextInListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTextInListDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTextInListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTextInListDlg)
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTextInListDlg, CDialog)
	//{{AFX_MSG_MAP(CTextInListDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTSAVE, OnButsave)
	ON_BN_CLICKED(IDC_BUTEXIT, OnButexit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextInListDlg message handlers

BOOL CTextInListDlg::OnInitDialog()
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
	m_Grid.InsertColumn(0,"职业编号",LVCFMT_LEFT,100,0);
	m_Grid.InsertColumn(1,"职业名称",LVCFMT_LEFT,100,1);
	m_Grid.InsertColumn(2,"负责人",LVCFMT_LEFT,100,2);
	m_Grid.InsertItem(0,0);
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select * from bumenbiao order by 职业编号 desc");
	_RecordsetPtr m_pRecordset;
	m_pRecordset=m_AdoConn.GetRecordSet((_bstr_t)sql);
	while(!m_pRecordset->adoEOF)
	{
		m_Grid.InsertItem(0,0);
		m_Grid.SetItemText(0,0,(char*)(_bstr_t)m_pRecordset->GetCollect("职业编号"));
		m_Grid.SetItemText(0,1,(char*)(_bstr_t)m_pRecordset->GetCollect("职业名称"));
		m_Grid.SetItemText(0,2,(char*)(_bstr_t)m_pRecordset->GetCollect("负责人"));
		m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTextInListDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTextInListDlg::OnPaint() 
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
HCURSOR CTextInListDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CTextInListDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if((pMsg->message == WM_KEYUP)&&(pMsg->hwnd == m_Grid.edit.m_hWnd))
	{
		CString str;
		m_Grid.edit.GetWindowText(str);
		m_Grid.SetItemText(m_Grid.row,m_Grid.col,str);
		if(m_Grid.col==2 && m_Grid.GetItemCount() == m_Grid.row+1)
		{
			m_Grid.InsertItem(m_Grid.row+1,0);
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CTextInListDlg::OnButsave() 
{
	// TODO: Add your control notification handler code here
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql,str,str1,str2;
	sql.Format("delete from bumenbiao");
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	int m=0;
	for(int i=0;i<m_Grid.GetItemCount();i++)
	{
		str=m_Grid.GetItemText(i,m);
		str1=m_Grid.GetItemText(i,m+1);
		str2=m_Grid.GetItemText(i,m+2);
		if(!str.IsEmpty() || !str1.IsEmpty() || !str2.IsEmpty())
		{
			sql.Format("insert into bumenbiao (职业编号,职业名称,负责人) values ('%s','%s','%s')",str,str1,str2);
			m_AdoConn.ExecuteSQL((_bstr_t)sql);
		}
	}
	m_AdoConn.ExitConnect();
	MessageBox("保存完毕");
}

void CTextInListDlg::OnButexit() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}
