// CreateIniMenuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CreateIniMenu.h"
#include "CreateIniMenuDlg.h"

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
// CCreateIniMenuDlg dialog

CCreateIniMenuDlg::CCreateIniMenuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCreateIniMenuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCreateIniMenuDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCreateIniMenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCreateIniMenuDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCreateIniMenuDlg, CDialog)
	//{{AFX_MSG_MAP(CCreateIniMenuDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCreateIniMenuDlg message handlers

BOOL CCreateIniMenuDlg::OnInitDialog()
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
	m_cMenu.CreateMenu();
	CreateMenuFromFile();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCreateIniMenuDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
void CCreateIniMenuDlg::LoadSubMenu(CMenu* m_menu,CString str)
{
	CMenu m_tempmenu;
	m_tempmenu.CreatePopupMenu();
	m_tempmenu.AppendMenu(MF_STRING,-1,str);
	_TCHAR buf[10240];
	CString strFilePath=".\\menu.ini";
	DWORD readlen=::GetPrivateProfileSection(str,buf,12040,strFilePath);
	_TCHAR *pbuf=buf;
	size_t size=strlen(pbuf);
	while(size)
	{
		CString strTmp(pbuf);
		CString strRight;
		int iRightPos=strTmp.Find("=");
		strRight=strTmp.Mid(iRightPos+1);
		m_tempmenu.AppendMenu(MF_STRING,-1,strRight);
			//if(IsHaveSubMenu(strRight))//¶þ¼¶Ä¿Â¼
				//LoadSubMenu(m_tempmenu,strRight);
		pbuf+=size+1;
		size=strlen(pbuf);
	}	
	m_cMenu.AppendMenu(MF_POPUP,(UINT)m_tempmenu.m_hMenu,str);
	m_tempmenu.Detach();
}
void CCreateIniMenuDlg::CreateMenuFromFile()
{
	CString strFilePath=".\\menu.ini";
	CString strSectionName="mainmenu";
	_TCHAR buf[10240];
	DWORD readlen=::GetPrivateProfileSection(strSectionName,buf,12040,strFilePath);
	_TCHAR *pbuf=buf;
	size_t size=strlen(pbuf);
	while(size)
	{
		CString strTmp(pbuf);
		CString strRight;
		int iRightPos=strTmp.Find("=");
		strRight=strTmp.Mid(iRightPos+1);
		LoadSubMenu(&m_cMenu,strRight);		
		pbuf+=size+1;
		size=strlen(pbuf);
	}	
	SetMenu(&m_cMenu);
}

BOOL CCreateIniMenuDlg::IsHaveSubMenu(CString strSubMenu)
{
	CString strFilePath=".\\menu.ini";
	CString tmp;
	_TCHAR buf[10240];
	::GetPrivateProfileSectionNames(buf,10240,strFilePath);
	_TCHAR *pbuf=buf;
	size_t size=strlen(pbuf);
	while(size)
	{
		CString strTmp(pbuf);
		if(strTmp==strSubMenu)
			return true;
		pbuf+=size+1;
		size=strlen(pbuf);
	}	
	return false;
}

void CCreateIniMenuDlg::OnPaint() 
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
HCURSOR CCreateIniMenuDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
