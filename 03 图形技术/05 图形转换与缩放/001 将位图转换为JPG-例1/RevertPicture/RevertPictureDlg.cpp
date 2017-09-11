// RevertPictureDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RevertPicture.h"
#include "RevertPictureDlg.h"
#include "olectl.h"

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
// CRevertPictureDlg dialog

CRevertPictureDlg::CRevertPictureDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRevertPictureDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRevertPictureDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRevertPictureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRevertPictureDlg)
	DDX_Control(pDX, IDC_IMAGE, m_image);
	DDX_Control(pDX, IDC_FILEDIR, m_dir);
	DDX_Control(pDX, IDC_JPG1, m_JPG);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRevertPictureDlg, CDialog)
	//{{AFX_MSG_MAP(CRevertPictureDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BROWN, OnBrown)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRevertPictureDlg message handlers

BOOL CRevertPictureDlg::OnInitDialog()
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

void CRevertPictureDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRevertPictureDlg::OnPaint() 
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
HCURSOR CRevertPictureDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRevertPictureDlg::OnOK() 
{
	m_JPG.SetBmpFile(m_filename);
	m_JPG.SetQuality((long)90);
	CFileDialog m_dlg(FALSE,"JPG",NULL,NULL,"JPGÍ¼Ïñ(JPG)|*.JPG",this);
	if (m_dlg.DoModal()==IDOK)
	{
		m_JPG.BmpToJPG(m_dlg.GetPathName());
	}
}

void CRevertPictureDlg::OnBrown() 
{
	CFileDialog m_dlg(TRUE,"bmp",NULL,NULL,"Î»Í¼(bmp)|*.bmp",this);
	if (m_dlg.DoModal()==IDOK)
	{
		 m_filename = m_dlg.GetPathName();
		m_dir.SetWindowText(m_filename);
		HANDLE m_handle;
		m_handle = ::LoadImage(GetModuleHandle(NULL),m_filename,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		m_image.SetBitmap((HBITMAP)m_handle);	
	}
}
