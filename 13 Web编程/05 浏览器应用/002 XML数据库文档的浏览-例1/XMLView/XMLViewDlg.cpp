// XMLViewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "XMLView.h"
#include "XMLViewDlg.h"

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
// CXMLViewDlg dialog

CXMLViewDlg::CXMLViewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CXMLViewDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CXMLViewDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CXMLViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CXMLViewDlg)
	DDX_Control(pDX, IDC_XMLLIST, m_xmllist);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CXMLViewDlg, CDialog)
	//{{AFX_MSG_MAP(CXMLViewDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_READ, OnRead)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXMLViewDlg message handlers

BOOL CXMLViewDlg::OnInitDialog()
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
	m_xmllist.SetExtendedStyle(LVS_EX_GRIDLINES);
	m_xmllist.InsertColumn(0,"name",LVCFMT_LEFT,70);
	m_xmllist.InsertColumn(1,"type",LVCFMT_LEFT,70);
	HRESULT hr=::CoInitialize(NULL);
	if(!SUCCEEDED(hr))
		return FALSE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CXMLViewDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CXMLViewDlg::OnPaint() 
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
HCURSOR CXMLViewDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CXMLViewDlg::OnRead() 
{
    unsigned short buff[128];
    memset(buff,0,128);   
	
	MSXML::IXMLDOMDocumentPtr xdoc;
	xdoc.CreateInstance(__uuidof(MSXML::DOMDocument));
	xdoc->load("test.xml");
	MSXML::IXMLDOMNodeListPtr nodelist=NULL;
	nodelist=xdoc->selectNodes("database/filed");
	MSXML::IXMLDOMNodePtr subnode;
	long nodecount;
	nodelist->get_length(&nodecount);
	for(long i=0;i<nodecount;i++)
	{
		subnode=nodelist->nextNode()->selectSingleNode((_bstr_t)"name");
		_bstr_t bstrname=subnode->Gettext();
		m_xmllist.InsertItem(i,"");
		m_xmllist.SetItemText(i,0,bstrname);
	}
	nodelist->reset();
	for(i=0;i<nodecount;i++)
	{
		subnode=nodelist->nextNode()->selectSingleNode((_bstr_t)"type");
		_bstr_t bstrname=subnode->Gettext();
		m_xmllist.SetItemText(i,1,bstrname);
	}	
}

void CXMLViewDlg::OnExit() 
{
	this->OnCancel();
}

BOOL CXMLViewDlg::DestroyWindow() 
{
	::CoUninitialize();
	return CDialog::DestroyWindow();
}
