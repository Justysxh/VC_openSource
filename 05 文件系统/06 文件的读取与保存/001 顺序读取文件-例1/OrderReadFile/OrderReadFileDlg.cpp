// OrderReadFileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OrderReadFile.h"
#include "OrderReadFileDlg.h"

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
// COrderReadFileDlg dialog

COrderReadFileDlg::COrderReadFileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COrderReadFileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COrderReadFileDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COrderReadFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COrderReadFileDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COrderReadFileDlg, CDialog)
	//{{AFX_MSG_MAP(COrderReadFileDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTREAD, OnRead)
	ON_BN_CLICKED(IDC_BTOPEN, OnOpen)
	ON_BN_CLICKED(IDC_BTEXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COrderReadFileDlg message handlers

BOOL COrderReadFileDlg::OnInitDialog()
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
	
	GetDlgItem(IDC_BTREAD)->EnableWindow(FALSE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COrderReadFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COrderReadFileDlg::OnPaint() 
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
HCURSOR COrderReadFileDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void COrderReadFileDlg::OnRead() 
{
	CString strserver,strdatabase,strusr,strpwd,readstring;
	if(file)
	{
	readlen=file.ReadString(readstring);
	if(!readlen)
		{
			GetDlgItem(IDC_BTREAD)->EnableWindow(FALSE);
			return;
		}
	int pos=readstring.Find(" ");
	strserver=readstring.Left(pos);
	readstring=readstring.Right(readstring.GetLength()-pos-1);

	pos=readstring.Find(" ");
	strdatabase=readstring.Left(pos);
	readstring=readstring.Right(readstring.GetLength()-pos-1);

	pos=readstring.Find(" ");
	strusr=readstring.Left(pos);
	readstring=readstring.Right(readstring.GetLength()-pos-1);

	pos=readstring.Find(" ");
	strpwd=readstring.Left(pos);
	readstring=readstring.Right(readstring.GetLength()-pos-1);
	
	GetDlgItem(IDC_EDSERVER)->SetWindowText(strserver);
	GetDlgItem(IDC_EDDATABASE)->SetWindowText(strdatabase);
	GetDlgItem(IDC_EDUSR)->SetWindowText(strusr);
	GetDlgItem(IDC_EDPWD)->SetWindowText(strpwd);
	}

}

void COrderReadFileDlg::OnOpen() 
{
	try{
	file.Open("test.txt",CFile::modeRead);
	GetDlgItem(IDC_BTOPEN)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTREAD)->EnableWindow(TRUE);
	AfxMessageBox("文件已打开");
	}catch(CFileException *e)
	{
		TCHAR szBuf[256]; 
		e->GetErrorMessage(szBuf,256,NULL);
		MessageBox(szBuf,_T("Warning"));
		e->Delete();
	}
	
}

void COrderReadFileDlg::OnExit() 
{
	file.Close();
	this->OnCancel();	
}
