// ReadWriteXMLDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ReadWriteXML.h"
#include "ReadWriteXMLDlg.h"

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
// CReadWriteXMLDlg dialog

CReadWriteXMLDlg::CReadWriteXMLDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReadWriteXMLDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReadWriteXMLDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReadWriteXMLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReadWriteXMLDlg)
	DDX_Control(pDX, IDC_EDIT3, m_age);
	DDX_Control(pDX, IDC_EDIT2, m_name);
	DDX_Control(pDX, IDC_EDIT1, m_code);
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CReadWriteXMLDlg, CDialog)
	//{{AFX_MSG_MAP(CReadWriteXMLDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON4, OnClose)
	ON_BN_CLICKED(IDC_BUTTON1, OnAddRow)
	ON_BN_CLICKED(IDC_BUTTON5, OnSave)
	ON_BN_CLICKED(IDC_BUTTON2, OnEdit)
	ON_BN_CLICKED(IDC_BUTTON3, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReadWriteXMLDlg message handlers

BOOL CReadWriteXMLDlg::OnInitDialog()
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
	
	m_list.InsertColumn(0,"±àºÅ");
	m_list.SetColumnWidth(0,50);
	m_list.InsertColumn(1,"ÐÕÃû");
	m_list.SetColumnWidth(1,100);
	m_list.InsertColumn(2,"ÄêÁä");
	m_list.SetColumnWidth(2,100);

	m_list.SetExtendedStyle(LVS_EX_FLATSB | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	

	
	
	XMLFilePath = GetAppPath() + "Text.XML";
//	UpdateXMLData();
	if (FileExists(XMLFilePath))
		ReadXMLData();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CReadWriteXMLDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CReadWriteXMLDlg::OnPaint() 
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
HCURSOR CReadWriteXMLDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CReadWriteXMLDlg::OnClose() 
{
	CDialog::OnCancel();	
}

void CReadWriteXMLDlg::OnAddRow() 
{
	CString name,code,age;
	m_code.GetWindowText(code);
	m_name.GetWindowText(name);
	m_age.GetWindowText(age);
	int index = m_list.InsertItem(m_list.GetItemCount(),code);	
	m_list.SetItemText(index,1,name);
	m_list.SetItemText(index,2,age);
}

CString CReadWriteXMLDlg::GetAppPath()
{
	char str[255];
	char mm[255];
	char *m = mm;
	::GetModuleFileName(0,str,255);
	m = strrchr(str,'\\');
	int l = m - str + 1;
	strncpy(mm,str,l);
	mm[l] = '\0';
	return mm;
}

BOOL CReadWriteXMLDlg::FileExists(CString FilePath)
{
	WIN32_FIND_DATA data;
	HANDLE handle = FindFirstFile(FilePath,&data);
	if (handle != INVALID_HANDLE_VALUE)
		return true;
	return false;
}

void CReadWriteXMLDlg::UpdateXMLData()
{
	MSXML::IXMLDOMDocumentPtr xdoc;
	xdoc.CreateInstance(__uuidof(MSXML::DOMDocument));
	MSXML::IXMLDOMElementPtr Root = xdoc->createElement("XMLList");
	MSXML::IXMLDOMElementPtr Row;
	MSXML::IXMLDOMElementPtr Col;
	xdoc->appendChild(Root);
	for (int i = 0 ; i < m_list.GetItemCount()  ; i++)
	{
		Row = xdoc->createElement("Row");
		Root->appendChild(Row);
		for (int j = 0 ; j < m_list.GetHeaderCtrl()->GetItemCount() ;j++)
		{
			LVCOLUMN column;
			column.mask = LVCF_TEXT;
			column.cchTextMax = 255;
			char str[255];
			column.pszText = str;
			m_list.GetColumn(j,&column);

			Col = xdoc->createElement(column.pszText);
			Row->appendChild(Col);
			CString values;
			values = m_list.GetItemText(i,j);
			Col->appendChild(xdoc->createTextNode((_bstr_t)values));
		}
	}
	xdoc->save((_bstr_t)XMLFilePath);

}

void CReadWriteXMLDlg::ReadXMLData()
{
	MSXML::IXMLDOMDocumentPtr xdoc;
	xdoc.CreateInstance(__uuidof(MSXML::DOMDocument));
	xdoc->load((_bstr_t)XMLFilePath);
	IXMLDOMNodeListPtr nodelist=NULL;
	IXMLDOMNodeListPtr rows=NULL;
	IXMLDOMNodeListPtr cols=NULL;
	nodelist=xdoc->selectNodes("XMLList");
	
	MSXML::IXMLDOMNodePtr Root;
	MSXML::IXMLDOMNodePtr Row;
	MSXML::IXMLDOMNodePtr Col;
	Root = nodelist->nextNode();
	_bstr_t bstrname=Root->nodeName;
	rows = Root->childNodes;
	m_list.DeleteAllItems();
	for (int i = 0 ; i < rows->length ; i++)
	{
		Row = rows->nextNode();
		cols = Row->childNodes;
		_bstr_t rowname = Row->nodeName;
		m_list.InsertItem(m_list.GetItemCount(),"");
		for (int j = 0 ; j < cols->length ; j++)
		{
			Col = cols->nextNode();
			IXMLDOMNodePtr node = Col->firstChild;
			_bstr_t value =  node->nodeValue;
			m_list.SetItemText(i,j,value);
		}
	}
}

void CReadWriteXMLDlg::OnSave() 
{
	UpdateXMLData();	
}

void CReadWriteXMLDlg::OnEdit() 
{
	CString name,code,age;
	m_code.GetWindowText(code);
	m_name.GetWindowText(name);
	m_age.GetWindowText(age);
	int index = m_list.GetSelectionMark();
	if (index >=0)
	{
		m_list.SetItemText(index,0,code);
		m_list.SetItemText(index,1,name);
		m_list.SetItemText(index,2,age);
	}
}

void CReadWriteXMLDlg::OnDelete() 
{
	int index = m_list.GetSelectionMark();
	if (index >=0)
		m_list.DeleteItem(index);
}
