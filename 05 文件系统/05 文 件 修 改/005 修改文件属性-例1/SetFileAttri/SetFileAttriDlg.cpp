// SetFileAttriDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SetFileAttri.h"
#include "SetFileAttriDlg.h"

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
// CSetFileAttriDlg dialog

CSetFileAttriDlg::CSetFileAttriDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetFileAttriDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetFileAttriDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSetFileAttriDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetFileAttriDlg)
	DDX_Control(pDX, IDC_CHVOL, m_vol);
	DDX_Control(pDX, IDC_CHSYSTEM, m_system);
	DDX_Control(pDX, IDC_CHREADONLY, m_readonly);
	DDX_Control(pDX, IDC_CHNORMAL, m_normal);
	DDX_Control(pDX, IDC_CHHIDE, m_hide);
	DDX_Control(pDX, IDC_CHDIR, m_dir);
	DDX_Control(pDX, IDC_CHAR, m_ar);
	DDX_Control(pDX, IDC_FILENAME, m_filename);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSetFileAttriDlg, CDialog)
	//{{AFX_MSG_MAP(CSetFileAttriDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTADD, OnAdd)
	ON_BN_CLICKED(IDC_BTSET, OnSet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetFileAttriDlg message handlers

BOOL CSetFileAttriDlg::OnInitDialog()
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

void CSetFileAttriDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSetFileAttriDlg::OnPaint() 
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
HCURSOR CSetFileAttriDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSetFileAttriDlg::OnAdd() 
{
	CFileDialog log(TRUE,"文件","*.*",OFN_HIDEREADONLY,"FILE(*.*)|*.*||",NULL);
	if(log.DoModal()==IDOK)
	{
        pathname=log.GetPathName();
		m_filename.SetWindowText(pathname);
		CFileStatus status;
		CFile::GetStatus(pathname,status);
		CString strsize;
		strsize.Format("%d",status.m_size);
		CTime createtime=status.m_ctime;
		CTime modifytime=status.m_mtime;
		CTime readtime=status.m_atime;
		GetDlgItem(IDC_EDFILESIZE)->SetWindowText(strsize);
		GetDlgItem(IDC_EDCREATETIME)->SetWindowText(createtime.Format("%Y年%m月%d日%H:%M:%S"));
		GetDlgItem(IDC_EDMODIFYTIME)->SetWindowText(modifytime.Format("%Y年%m月%d日%H:%M:%S"));
		GetDlgItem(IDC_EDREADTIME)->SetWindowText(readtime.Format("%Y年%m月%d日%H:%M:%S"));
		if(status.m_attribute&0x00)
			m_ar.SetCheck(1);
		if(status.m_attribute&0x10)
			m_dir.SetCheck(1);
		if(status.m_attribute&0x02)
			m_hide.SetCheck(1);
		if(status.m_attribute&0x20)
			m_normal.SetCheck(1);
		if(status.m_attribute&0x01)
			m_readonly.SetCheck(1);
		if(status.m_attribute&0x04)
			m_system.SetCheck(1);
		if(status.m_attribute&0x08)
			m_vol.SetCheck(1);
		
	}
}

void CSetFileAttriDlg::OnSet() 
{

	CFileStatus status;
	BYTE m_newattri;
	if(m_ar.GetCheck())
	{
	m_newattri=0x20;
	CFile::GetStatus(pathname,status);
	status.m_attribute=m_newattri;
	CFile::SetStatus(pathname,status);
	}
	if(m_dir.GetCheck())
	{
	m_newattri=0x10;
	CFile::GetStatus(pathname,status);
	status.m_attribute=m_newattri;
	CFile::SetStatus(pathname,status);
	}	
	if(m_hide.GetCheck())
	{
	m_newattri=0x02;
	CFile::GetStatus(pathname,status);
	status.m_attribute=m_newattri;
	CFile::SetStatus(pathname,status);
	}
	if(m_normal.GetCheck())
	{
	m_newattri=0x00;
	CFile::GetStatus(pathname,status);
	status.m_attribute=m_newattri;
	CFile::SetStatus(pathname,status);
	}
	if(m_readonly.GetCheck())
	{
	m_newattri=0x00;
	CFile::GetStatus(pathname,status);
	status.m_attribute=m_newattri;
	CFile::SetStatus(pathname,status);
	m_newattri=0x01;
	status.m_attribute=m_newattri;
	CFile::SetStatus(pathname,status);
	}
	if(m_system.GetCheck())
	{
	m_newattri=0x04;
	CFile::GetStatus(pathname,status);
	status.m_attribute=m_newattri;
	CFile::SetStatus(pathname,status);
	}	
	if(m_vol.GetCheck())
	{
	m_newattri=0x08;
	CFile::GetStatus(pathname,status);
	status.m_attribute=m_newattri;
	CFile::SetStatus(pathname,status);
	}
}
