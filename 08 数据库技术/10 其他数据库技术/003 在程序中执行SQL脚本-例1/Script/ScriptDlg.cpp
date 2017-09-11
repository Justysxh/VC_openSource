// ScriptDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Script.h"
#include "ScriptDlg.h"

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
// CScriptDlg dialog

CScriptDlg::CScriptDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScriptDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScriptDlg)
	m_Server = _T("");
	m_Database = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CScriptDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScriptDlg)
	DDX_Control(pDX, IDC_STATICTEXT, m_Path);
	DDX_Control(pDX, IDC_RICHEDIT1, m_RichEdit);
	DDX_Text(pDX, IDC_EDIT1, m_Server);
	DDX_Text(pDX, IDC_EDIT2, m_Database);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CScriptDlg, CDialog)
	//{{AFX_MSG_MAP(CScriptDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTEXECUTE, OnButexecute)
	ON_BN_CLICKED(IDC_BUTSELECT, OnButselect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScriptDlg message handlers

BOOL CScriptDlg::OnInitDialog()
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

void CScriptDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CScriptDlg::OnPaint() 
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
HCURSOR CScriptDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CScriptDlg::OnButexecute() 
{
	UpdateData(true);
	char buf[256];
	::GetCurrentDirectory(256,buf); //获取程序根目录路径
	strcat(buf,"\\sql.txt");
	CString StrPath,sqltxt;
	sqltxt = buf;
	StrPath.Format("isqlw -S %s -d %s -E -i %s -o %s",m_Server,m_Database,strText,sqltxt);
	WinExec(StrPath,4);
	Sleep(1000);
	CString str="";
	char sread[10000];
	CFile mfile(_T(sqltxt),CFile::modeRead);
	mfile.Read(sread,10000);
	for(int i=0;i<mfile.GetLength();i++)
	{
		str += sread[i];
	}
	m_RichEdit.SetWindowText(str);
}

void CScriptDlg::OnButselect() 
{
	CFileDialog file(true,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		"All Files(*.sql)|*.sql| |",AfxGetMainWnd());
	if(file.DoModal()==IDOK)
	{
		strText=file.GetPathName();
		m_Path.SetWindowText(strText);
	}	
}
