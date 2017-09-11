// dataencryptDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dataencrypt.h"
#include "dataencryptDlg.h"

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
// CDataencryptDlg dialog

CDataencryptDlg::CDataencryptDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDataencryptDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDataencryptDlg)
	m_edit2 = _T("");
	m_edit3 = _T("");
	m_edit1 = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDataencryptDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDataencryptDlg)
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDataencryptDlg, CDialog)
	//{{AFX_MSG_MAP(CDataencryptDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataencryptDlg message handlers

BOOL CDataencryptDlg::OnInitDialog()
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

void CDataencryptDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDataencryptDlg::OnPaint() 
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
HCURSOR CDataencryptDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDataencryptDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
	m_edit3 = Encrypt(m_edit2,m_edit1);
	UpdateData(false);
	//CDialog::OnOK();
}

CString CDataencryptDlg::Encrypt(CString S, WORD K)
{
	CString Str,Str1,Result;
	int i,j;
	Str = S;
	for(i=0;i<S.GetLength();i++)
	{
		Str.SetAt(i,S.GetAt(i)+K);
	}
	S = Str;
	for(i=0;i<S.GetLength();i++)
	{
		j = (BYTE)S.GetAt(i);
		Str1 = "01";
		Str1.SetAt(0,65+j/26);
		Str1.SetAt(1,65+j%26);
		Result += Str1;
	}
	return Result;
}

CString CDataencryptDlg::Decrypt(CString S, WORD K)
{
	CString Result,Str;
	int i,j;
	for(i=0;i<S.GetLength()/2;i++)
	{
		j=((BYTE)S.GetAt(2*i)-65)*26;
		j+=(BYTE)S.GetAt(2*i+1)-65;
		Str = "0";
		Str.SetAt(0,j);
		Result += Str;
	}
	S = Result;
	for(i=0;i<S.GetLength();i++)
	{
		Result.SetAt(i,(BYTE)S.GetAt(i)-K);
	}
	return Result;
}

void CDataencryptDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_edit3 = Decrypt(m_edit3,m_edit1);
	UpdateData(false);
}
