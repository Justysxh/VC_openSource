// TimeBackUpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TimeBackUp.h"
#include "TimeBackUpDlg.h"

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
// CTimeBackUpDlg dialog

CTimeBackUpDlg::CTimeBackUpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTimeBackUpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTimeBackUpDlg)
	m_edit1 = _T("");
	m_edit2 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTimeBackUpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTimeBackUpDlg)
	DDX_Control(pDX, IDC_EDIT2, m_min);
	DDX_Control(pDX, IDC_EDIT1, m_hour);
	DDX_Text(pDX, IDC_EDIT3, m_edit1);
	DDX_Text(pDX, IDC_EDIT4, m_edit2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTimeBackUpDlg, CDialog)
	//{{AFX_MSG_MAP(CTimeBackUpDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTLIULAN, OnButliulan)
	ON_BN_CLICKED(IDC_BUTSAVE, OnButsave)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimeBackUpDlg message handlers

BOOL CTimeBackUpDlg::OnInitDialog()
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
	SetTimer(1,60000,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTimeBackUpDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTimeBackUpDlg::OnPaint() 
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
HCURSOR CTimeBackUpDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTimeBackUpDlg::OnButliulan() 
{
	// TODO: Add your control notification handler code here
	CFileDialog file(true,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"All Files(*.*)|*.*| |",AfxGetMainWnd());
		if(file.DoModal()==IDOK)
		{
			strName = file.GetFileName();
			m_edit1 = file.GetPathName();
		}
	UpdateData(false);
}

void CTimeBackUpDlg::OnButsave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString ReturnPach;
	TCHAR szPath[_MAX_PATH];
	BROWSEINFO bi;
	bi.hwndOwner=NULL;
	bi.pidlRoot=NULL;
	bi.lpszTitle=_T("ÇëÑ¡ÔñÎÄ¼þ¼Ð");
	bi.pszDisplayName=szPath;
	bi.ulFlags=BIF_RETURNONLYFSDIRS;
	bi.lpfn=NULL;
	bi.lParam=NULL;
	LPITEMIDLIST pItemIDList=SHBrowseForFolder(&bi);
	if(pItemIDList)
	{
		if(SHGetPathFromIDList(pItemIDList,szPath))
			ReturnPach=szPath;	
	}
	else
		ReturnPach="";
	m_edit2 = ReturnPach;
	if(m_edit2.Right(1)!="\\")
		m_edit2 += "\\";
	CString name,mhour,mmin,stime;
	int length;
	CTime time;
	time=time.GetCurrentTime();
	m_hour.GetWindowText(mhour);
	stime.Format("%s",time.Format("%y-%m-%d-"));
	m_min.GetWindowText(mmin);
	m_edit2 = m_edit2 + strName;
	length = m_edit2.GetLength();
	name = m_edit2.Right(4);
	m_edit2 = m_edit2.Left(length-4) + stime + mhour + "-" + mmin + name;
	UpdateData(false);
}

void CTimeBackUpDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CTime time;
	time=time.GetCurrentTime();
	hour = time.GetHour();
	min = time.GetMinute();
	CString mhour,mmin;
	m_hour.GetWindowText(mhour);
	m_min.GetWindowText(mmin);
	if(hour == atoi(mhour) && min == atoi(mmin))
	{
		CopyFile(m_edit1,m_edit2,false);
	}
	CDialog::OnTimer(nIDEvent);
}
