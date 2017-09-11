// PopManuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PopManu.h"
#include "PopManuDlg.h"
#include "windef.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

extern _ConnectionPtr m_pCon;
extern _RecordsetPtr m_pRecord;

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
// CPopManuDlg dialog

CPopManuDlg::CPopManuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPopManuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPopManuDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPopManuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPopManuDlg)
	DDX_Control(pDX, IDC_LIST3, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPopManuDlg, CDialog)
	//{{AFX_MSG_MAP(CPopManuDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_MENUITEMASC, OnMenuitemasc)
	ON_COMMAND(ID_MENUITEMDESC, OnMenuitemdesc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPopManuDlg message handlers

BOOL CPopManuDlg::OnInitDialog()
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
	
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FLATSB|LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0,"书籍名称",LVCFMT_LEFT,150);
	m_list.InsertColumn(1,"条形码",LVCFMT_LEFT,120);
	m_list.InsertColumn(2,"作者",LVCFMT_LEFT,80);
	m_list.InsertColumn(3,"出版社",LVCFMT_LEFT,80);
	m_list.InsertColumn(4,"价格",LVCFMT_LEFT,80);
	// TODO: Add extra initialization here
	LoadBookInfo();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPopManuDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPopManuDlg::OnPaint() 
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
HCURSOR CPopManuDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPopManuDlg::OnOK() 
{
	
	//CDialog::OnOK();
}

void CPopManuDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	CMenu m_popmenu;
	m_popmenu.LoadMenu(IDR_POPMENU);
	CMenu* m_submenu = m_popmenu.GetSubMenu(0);
	
	m_submenu->TrackPopupMenu(TPM_LEFTBUTTON |TPM_LEFTALIGN ,point.x,point.y,this);

	m_popmenu.DestroyMenu();
}

BOOL CPopManuDlg::PreTranslateMessage(MSG* pMsg) 
{

	return CDialog::PreTranslateMessage(pMsg);
}

void CPopManuDlg::LoadBookInfo(BOOL IsDesc)
{
	m_list.DeleteAllItems();
	CString sql;
	if (!IsDesc)
		sql = "Select * from tb_bookinfo ORDER BY PRICE ASC";
	else
		sql = "Select * from tb_bookinfo ORDER BY PRICE desc";
	CString fieldvalue;
	m_pRecord = m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	int i = 0;
	while (! m_pRecord->ADOEOF && !m_pRecord->BOF)
	{	
		m_list.InsertItem(100,"");

		fieldvalue = (TCHAR*)(_bstr_t)m_pRecord->GetFields()->GetItem("bookname")->Value;
		m_list.SetItemText(i,0,fieldvalue);

		fieldvalue = (TCHAR*)(_bstr_t)m_pRecord->GetFields()->GetItem("barcode")->Value;
		m_list.SetItemText(i,1,fieldvalue);

		fieldvalue =(TCHAR*) (_bstr_t)m_pRecord->GetFields()->GetItem("author")->Value;
		m_list.SetItemText(i,2,fieldvalue);

		fieldvalue = (TCHAR*)(_bstr_t)m_pRecord->GetFields()->GetItem("bookconcern")->Value;
		m_list.SetItemText(i,3,fieldvalue);

		fieldvalue =(TCHAR*) (_bstr_t)m_pRecord->GetFields()->GetItem("price")->Value;
		m_list.SetItemText(i,4,fieldvalue);

		i+=1;
		m_pRecord->MoveNext();
	}
}

void CPopManuDlg::OnMenuitemasc() 
{
	LoadBookInfo();
}

void CPopManuDlg::OnMenuitemdesc() 
{
	LoadBookInfo(TRUE);	
}
