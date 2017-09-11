// RichTextCharDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RichTextChar.h"
#include "RichTextCharDlg.h"

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
// CRichTextCharDlg dialog

CRichTextCharDlg::CRichTextCharDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRichTextCharDlg::IDD, pParent)
{
	::AfxInitRichEdit();

	//{{AFX_DATA_INIT(CRichTextCharDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRichTextCharDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRichTextCharDlg)
	DDX_Control(pDX, IDC_EDFIND, m_edfind);
	DDX_Control(pDX, IDC_BTNFIND, m_btnFind);
	DDX_Control(pDX, IDC_RICHEDIT1, m_richedit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRichTextCharDlg, CDialog)
	//{{AFX_MSG_MAP(CRichTextCharDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_BTNFIND, OnFind)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRichTextCharDlg message handlers

BOOL CRichTextCharDlg::OnInitDialog()
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
	CStdioFile file;
	file.Open("test.txt",CFile::modeRead);

	while(1)
	{
	DWORD i=file.ReadString(str);
	if(i==0)goto end;
	tmp+=str;
	tmp+="\n";
	}
	end:m_richedit.SetWindowText(tmp);
	lineindex=0;
	istartpos=0;
	movepos=0;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRichTextCharDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRichTextCharDlg::OnPaint() 
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
HCURSOR CRichTextCharDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRichTextCharDlg::OnFind() 
{
	m_richedit.LineScroll(-lineindex);
	CString strfind;
	GetDlgItem(IDC_EDFIND)->GetWindowText(strfind);
	int ret=tmp.Find(strfind,istartpos);
	int strlen=strfind.GetLength();
	m_richedit.SetSel(ret,ret+strlen);
	istartpos=ret+strlen;
	lineindex=m_richedit.LineFromChar(ret);
	int linepos=m_richedit.LineIndex(lineindex);
	m_richedit.LineScroll(lineindex);
	m_richedit.SetFocus();
	
}
