// ChangeMFileAttriDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChangeMFileAttri.h"
#include "ChangeMFileAttriDlg.h"

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
// CChangeMFileAttriDlg dialog

CChangeMFileAttriDlg::CChangeMFileAttriDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChangeMFileAttriDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChangeMFileAttriDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChangeMFileAttriDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChangeMFileAttriDlg)
	DDX_Control(pDX, IDC_CHSYSTEM, m_chsystem);
	DDX_Control(pDX, IDC_CHREADONLY, m_chreadonly);
	DDX_Control(pDX, IDC_CHHIDE, m_chhide);
	DDX_Control(pDX, IDC_FILELIST, m_filelist);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChangeMFileAttriDlg, CDialog)
	//{{AFX_MSG_MAP(CChangeMFileAttriDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTADD, OnAddFile)
	ON_BN_CLICKED(IDC_BTSET, OnSetFile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChangeMFileAttriDlg message handlers

BOOL CChangeMFileAttriDlg::OnInitDialog()
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
	
	m_filelist.SetExtendedStyle(LVS_EX_GRIDLINES);
	m_filelist.InsertColumn(0,"文件",LVCFMT_LEFT,450);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CChangeMFileAttriDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChangeMFileAttriDlg::OnPaint() 
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
HCURSOR CChangeMFileAttriDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CChangeMFileAttriDlg::OnAddFile() 
{
	CFileDialog log(TRUE,"文件","*.*",OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT|
		OFN_ALLOWMULTISELECT,"FILE(*.*)|*.*|jpeg(*.jpg)|*.jpg|文本(*.txt)|*.txt||",NULL);
	if(log.DoModal()==IDOK)
	{
		POSITION pos = log.GetStartPosition();
        while(pos != NULL)
        {
        CString pathname=log.GetNextPathName(pos);
		m_filelist.InsertItem(m_filelist.GetItemCount(),pathname);
		}
	}	
}

void CChangeMFileAttriDlg::OnSetFile() 
{
	BYTE m_newattri;
	CFileStatus status;
	if(m_chreadonly.GetCheck())
		m_newattri|=0x01;
	if(m_chsystem.GetCheck())
		m_newattri|=0x04;
	if(m_chhide.GetCheck())
		m_newattri|=0x02;
	int count=m_filelist.GetItemCount();
	for(int i=0;i<count;i++)
	{
		CFile::GetStatus(m_filelist.GetItemText(i,0),status);
		status.m_attribute=m_newattri;
		CFile::SetStatus(m_filelist.GetItemText(i,0),status);
	}
}
