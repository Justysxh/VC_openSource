// TAPITELDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TAPITEL.h"
#include "TAPITELDlg.h"

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
// CTAPITELDlg dialog

CTAPITELDlg::CTAPITELDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTAPITELDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTAPITELDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTAPITELDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTAPITELDlg)
	DDX_Control(pDX, IDC_LINELIST, m_linelist);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTAPITELDlg, CDialog)
	//{{AFX_MSG_MAP(CTAPITELDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_DBLCLK(IDC_LINELIST, OnDblclkLinelist)
	ON_BN_CLICKED(IDC_BTDIAL, OnDial)
	ON_BN_CLICKED(IDC_BTDROP, OnDrop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTAPITELDlg message handlers

BOOL CTAPITELDlg::OnInitDialog()
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


	LONG lResult;
	LINEINITIALIZEEXPARAMS exparams;
	LPLINEAGENTCAPS pLAC;
	//LPLINEDEVCAPS pLDC;
	DWORD dwDeviceID,dwNumDevs,dwAPIVersion, dwThreadID;

	exparams.dwTotalSize=sizeof(LINEINITIALIZEEXPARAMS);
	exparams.dwOptions=LINEINITIALIZEEXOPTION_USECOMPLETIONPORT;
	exparams.Handles.hCompletionPort=ghCompletionPort;

	lResult=lineInitializeEx(&ghLineApp,::AfxGetApp()->m_hInstance,NULL,"mrtapi",
		&dwNumDevs,&dwAPIVersion,&exparams);

	if (dwNumDevs==0)     
	{lineShutdown(ghLineApp);
	return FALSE;}

	for(DWORD i=0;i<dwNumDevs;i++)
	{
		//pLAC=LineGetAgentCaps(ghLineApp,i,0);
		//pLDC=LineGetDevCaps(ghLineApp,i);
		LINEDEVCAPS *pLineDevCaps;
		static DWORD dwMaxNeededSize=sizeof(LINEDEVCAPS);

		pLineDevCaps=(LINEDEVCAPS*)GlobalAlloc(GPTR,dwMaxNeededSize);
		pLineDevCaps->dwTotalSize=dwMaxNeededSize;
		lineGetDevCaps(ghLineApp,i,TAPI_CURRENT_VERSION,0,pLineDevCaps);
		
		dwMaxNeededSize=pLineDevCaps->dwNeededSize;
		pLineDevCaps=(LINEDEVCAPS*)GlobalReAlloc((HLOCAL)pLineDevCaps,dwMaxNeededSize,GMEM_MOVEABLE);
		//if(pLineDevCaps->dwBearerModes==LINEBEARERMODE_VOICE)
		//if(pLineDevCaps->dwMediaModes==LINEMEDIAMODE_INTERACTIVEVOICE)
		m_linelist.AddString(((LPTSTR)((LPBYTE)pLineDevCaps+pLineDevCaps->dwLineNameOffset)));
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTAPITELDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTAPITELDlg::OnPaint() 
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
HCURSOR CTAPITELDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTAPITELDlg::OnDblclkLinelist() 
{
	int i=m_linelist.GetCurSel();
	lineOpen(ghLineApp,i,&ghLine,TAPI_CURRENT_VERSION,
	0,0,LINECALLPRIVILEGE_OWNER,LINEMEDIAMODE_INTERACTIVEVOICE,NULL);
	::lineConfigDialog(i,this->GetSafeHwnd(),NULL);
	lineShutdown(ghLineApp);
}

void CTAPITELDlg::OnDial() 
{
	CString number;
	
	GetDlgItem(IDC_EDTELNUM)->GetWindowText(number);
	int i=m_linelist.GetCurSel();
	lineOpen(ghLineApp,i,&ghLine,TAPI_CURRENT_VERSION,
	0,0,LINECALLPRIVILEGE_OWNER,LINEMEDIAMODE_INTERACTIVEVOICE,NULL);
	::lineMakeCall(ghLine,&call,number,0,0);
}

void CTAPITELDlg::OnDrop() 
{
	lineDrop(call,NULL,0);
}
