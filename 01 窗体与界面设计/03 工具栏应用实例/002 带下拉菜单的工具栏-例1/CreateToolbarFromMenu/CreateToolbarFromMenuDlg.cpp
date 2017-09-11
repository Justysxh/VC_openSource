// CreateToolbarFromMenuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CreateToolbarFromMenu.h"
#include "CreateToolbarFromMenuDlg.h"

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
// CCreateToolbarFromMenuDlg dialog

CCreateToolbarFromMenuDlg::CCreateToolbarFromMenuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCreateToolbarFromMenuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCreateToolbarFromMenuDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCreateToolbarFromMenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCreateToolbarFromMenuDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCreateToolbarFromMenuDlg, CDialog)
	//{{AFX_MSG_MAP(CCreateToolbarFromMenuDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_COMMAND_RANGE(ID_CGTH,ID_CGTH+9,OnMenuClick)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCreateToolbarFromMenuDlg message handlers

BOOL CCreateToolbarFromMenuDlg::OnInitDialog()
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

	m_imagelist.Create(32,32,ILC_COLOR32|ILC_MASK,0,0);
	CString strpath;
	HICON hicon;
	int j;
	for(j=1;j<10;j++)
	{
		strpath.Format(".\\res\\toolbar\\%02d.ico",j);
		hicon = (HICON)::LoadImage(NULL,strpath,IMAGE_ICON,32,32,LR_LOADFROMFILE);
		m_imagelist.Add(hicon);
	}
	m_toolbar.Create(WS_CHILD|WS_VISIBLE,CRect(0,0,0,0),this,154230);//154230是一个资源值
	m_toolbar.EnableAutomation();
	m_toolbar.SetImageList(&m_imagelist);
	TBBUTTON button[11];
	int i;
	for(i=0;i<11;i++)
	{
		button[i].dwData=0;
		button[i].fsState=TBSTATE_ENABLED;
		button[i].fsStyle=TBSTYLE_BUTTON;
	}

	int iMenuButtonCount=0;
	MENUITEMINFO info;
	CString strMenuName;

	CMenu menDlgMenu;
	CMenu *menDlgSubmenu;
	menDlgMenu.LoadMenu(IDR_MYMENU);
	int iMenuCount=menDlgMenu.GetMenuItemCount();//父菜单数量
	for(j=0;j<iMenuCount;j++)
	{
		
		menDlgSubmenu=menDlgMenu.GetSubMenu(j);//MF_BYPOSITION//MF_BYCOMMAND
		int iSubMenuCount=menDlgSubmenu->GetMenuItemCount();
		for(i=0;i<iSubMenuCount;i++)
		{
			menDlgSubmenu->GetMenuString(i,strMenuName,MF_BYPOSITION);
			button[iMenuButtonCount].idCommand=menDlgSubmenu->GetMenuItemID(i);
			button[iMenuButtonCount].iBitmap=iMenuButtonCount%9;
			button[iMenuButtonCount].iString =m_toolbar.AddStrings(strMenuName);
			iMenuButtonCount++;
			if(iMenuButtonCount>10)
				break;
		}
		//menDlgSubmenu->//释放
		if(iMenuButtonCount>10)
				break;
	}
	
	
	this->SetMenu(&menDlgMenu);
	
	m_toolbar.AddButtons(iMenuButtonCount,button);
	m_toolbar.AutoSize();
	m_toolbar.SetStyle(TBSTYLE_FLAT|CCS_TOP);

	return TRUE;
}

void CCreateToolbarFromMenuDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCreateToolbarFromMenuDlg::OnPaint() 
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
HCURSOR CCreateToolbarFromMenuDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CCreateToolbarFromMenuDlg::OnMenuClick(UINT nID) 
{
	MessageBox("执行命令");
}

void CCreateToolbarFromMenuDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	
}
