// BackUpAccessDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BackUpAccess.h"
#include "BackUpAccessDlg.h"

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
// CBackUpAccessDlg dialog

CBackUpAccessDlg::CBackUpAccessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBackUpAccessDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBackUpAccessDlg)
	m_Edit1 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBackUpAccessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBackUpAccessDlg)
	DDX_Control(pDX, IDC_BUTTON2, m_But2);
	DDX_Control(pDX, IDC_BUTTON1, m_But1);
	DDX_Text(pDX, IDC_EDIT1, m_Edit1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBackUpAccessDlg, CDialog)
	//{{AFX_MSG_MAP(CBackUpAccessDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBackUpAccessDlg message handlers

BOOL CBackUpAccessDlg::OnInitDialog()
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
	CButton* tempbutton = (CButton*)GetDlgItem(IDC_RADIO1);
		tempbutton->SetCheck(1);
	char buf[256];
	::GetCurrentDirectory(256,buf);
	strcat(buf,"\\shujuku.mdb");
	StrPath = buf;
	m_But1.SetWindowText("保存文件路径");
	m_But2.SetWindowText("备份");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBackUpAccessDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBackUpAccessDlg::OnPaint() 
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
HCURSOR CBackUpAccessDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBackUpAccessDlg::OnRadio1() 
{
	UpdateData(true);
	radio = true;
	m_But1.SetWindowText("保存文件路径");
	m_But2.SetWindowText("备份");
}

void CBackUpAccessDlg::OnRadio2() 
{
	UpdateData(true);
	radio = false;
	m_But1.SetWindowText("选择备份文件");
	m_But2.SetWindowText("还原");
}

void CBackUpAccessDlg::OnButton1() 
{
	if(radio)
	{
		CString ReturnPach;
		TCHAR szPath[_MAX_PATH];
		BROWSEINFO bi;
		bi.hwndOwner=NULL;
		bi.pidlRoot=NULL;
		bi.lpszTitle=_T("请选择备份文件夹");
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
		m_Edit1 = ReturnPach;
		m_Edit1 = m_Edit1 + "shujuku.mdb";
	}
	else
	{
		CFileDialog file(true,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"All Files(*.*)|*.*| |",AfxGetMainWnd());
		if(file.DoModal()==IDOK)
		{
			m_Edit1 = file.GetPathName();
		}
	}
	UpdateData(false);
}

void CBackUpAccessDlg::OnButton2() 
{
	
	if(radio)
	{	
		CopyFile(StrPath,m_Edit1,false);
		MessageBox("备份完成！","系统提示",MB_OK|MB_ICONEXCLAMATION);
	}
	else
	{
		CopyFile(m_Edit1,StrPath,false);
		MessageBox("还原完成！","系统提示",MB_OK|MB_ICONEXCLAMATION);
	}
}
