// WinResManagerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WinResManager.h"
#include "WinResManagerDlg.h"

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
// CWinResManagerDlg dialog

CWinResManagerDlg::CWinResManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWinResManagerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWinResManagerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_MAINICON);
}

void CWinResManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWinResManagerDlg)
	DDX_Control(pDX, IDC_FRAME, m_Frame);
	DDX_Control(pDX, IDC_LIST, m_FileList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWinResManagerDlg, CDialog)
	//{{AFX_MSG_MAP(CWinResManagerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_CBN_SELCHANGE(112, DiskItemChange)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinResManagerDlg message handlers

BOOL CWinResManagerDlg::OnInitDialog()
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

	m_FileList.SetExtendedStyle(LVS_EX_TWOCLICKACTIVATE|LVS_EX_FULLROWSELECT );
	m_FileList.SetColumns(_T("文件名,150;文件,80;文件日期,150"));

	CRect ComBoxRC;
	m_Frame.GetWindowRect(ComBoxRC);
	m_Frame.ScreenToClient(ComBoxRC);
	m_Frame.MapWindowPoints(this, ComBoxRC);
	ComBoxRC.bottom = ComBoxRC.top + 100;
	m_DiskList.Create(WS_CHILD|WS_VISIBLE|CBS_DROPDOWNLIST|CBS_SORT,
						ComBoxRC, this, 112);
	LoadSysDisk();
	return TRUE;  
}

void CWinResManagerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWinResManagerDlg::OnPaint() 
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
HCURSOR CWinResManagerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWinResManagerDlg::OnOK() 
{

}

void CWinResManagerDlg::LoadSysDisk()
{
	m_DiskList.SetImageList(&m_FileList.m_ImageList);
	m_DiskList.ResetContent();
	char  pchDrives[128] = {0};
	char* pchDrive;
	GetLogicalDriveStrings(sizeof(pchDrives), pchDrives) ;

	pchDrive = pchDrives;
	int nItem = 0;
	while(*pchDrive)
	{
		COMBOBOXEXITEM     cbi;
		CString            csText;
		cbi.mask = CBEIF_IMAGE|CBEIF_INDENT|CBEIF_OVERLAY|
					CBEIF_SELECTEDIMAGE|CBEIF_TEXT;

		SHFILEINFO shInfo;
		int nIcon;
		SHGetFileInfo(pchDrive, 0, &shInfo, sizeof(shInfo),
						SHGFI_ICON|SHGFI_SMALLICON);
		nIcon = shInfo.iIcon;

		cbi.iItem = nItem;
		cbi.pszText = pchDrive;
		cbi.cchTextMax = strlen(pchDrive);
		cbi.iImage = nIcon;
		cbi.iSelectedImage = nIcon;
		cbi.iOverlay = 0;
		cbi.iIndent = (0 & 0x03); 
		m_DiskList.InsertItem(&cbi);
		nItem++;
		pchDrive += strlen(pchDrive) + 1;
	}
}

void CWinResManagerDlg::DiskItemChange()
{
	COMBOBOXEXITEM cbi;
	memset(&cbi,0,sizeof(COMBOBOXEXITEM));

	int nCurItem = m_DiskList.GetCurSel();
	cbi.mask =  CBEIF_TEXT;
	char chName[128] = {0};
	cbi.pszText = chName;
	cbi.cchTextMax = 128;
	cbi.iItem = nCurItem;
	m_DiskList.GetItem(&cbi);
	m_FileList.m_BaseDir = chName;
	m_FileList.DisplayPath(chName);
}
