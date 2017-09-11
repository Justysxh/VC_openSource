// ClipboardViewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ClipboardView.h"
#include "ClipboardViewDlg.h"

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
// CClipboardViewDlg dialog

CClipboardViewDlg::CClipboardViewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClipboardViewDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClipboardViewDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClipboardViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClipboardViewDlg)
	DDX_Control(pDX, IDC_LISTTYPE, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClipboardViewDlg, CDialog)
	//{{AFX_MSG_MAP(CClipboardViewDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTVIEW, OnView)
	ON_LBN_SELCHANGE(IDC_LISTTYPE, OnSelchangeListtype)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClipboardViewDlg message handlers

BOOL CClipboardViewDlg::OnInitDialog()
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
	view=SetClipboardViewer();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CClipboardViewDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CClipboardViewDlg::OnPaint() 
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
HCURSOR CClipboardViewDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CClipboardViewDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	ChangeClipboardChain(view);
}

void CClipboardViewDlg::OnView() 
{
	m_list.ResetContent();
	if(OpenClipboard())
	{
		UINT i=0;
		while(i=EnumClipboardFormats(i))
		{
			CString str;
			str=GetName(i);
			m_list.AddString(str);
		}
	}
}

void CClipboardViewDlg::OnSelchangeListtype() 
{
	//m_list.GetText(m_list.GetCurSel(),s);
	if(IsClipboardFormatAvailable(CF_TEXT))
	{
		HANDLE handle=GetClipboardData(CF_TEXT);
		char*data=(char*)GlobalLock(handle);
		CString str=data;
		GetDlgItem(IDC_EDBODY)->SetWindowText(str);
	}
}
CString CClipboardViewDlg::GetName(int value)
{
	CString fmtstr;
	switch(value)
	{
	case 1:
		fmtstr="CF_TEXT";
		return fmtstr;
	case 2:
		fmtstr="CF_BITMAP";
		return fmtstr;
	case 3:
		fmtstr="CF_METAFILEPICT";
		return fmtstr;
	case 4:
		fmtstr="CF_SYLK";
		return fmtstr;
	case 5:
		fmtstr="CF_DIF";
		return fmtstr;
	case 6:
		fmtstr="CF_TIFF";
		return fmtstr;
	case 7:
		fmtstr="CF_OEMTEXT";
		return fmtstr;
	case 8:
		fmtstr="CF_DIB";
		return fmtstr;
	case 9:
		fmtstr="CF_PALETTE";
		return fmtstr;
	case 10:
		fmtstr="CF_PENDATA";
		return fmtstr;
	case 11:
		fmtstr="CF_RIFF";
		return fmtstr;
	case 12:
		fmtstr="CF_WAVE";
		return fmtstr;
	case 13:
		fmtstr="CF_UNICODETEXT";
		return fmtstr;
	case 14:
		fmtstr="CF_ENHMETAFILE";
		return fmtstr;
	case 15:
		fmtstr="CF_HDROP";
		return fmtstr;
	case 16:
		fmtstr="CF_LOCALE";
		return fmtstr;
	case 17:
		fmtstr="CF_MAX";
		return fmtstr;
	case 0x0080:
		fmtstr="CF_OWNERDISPLAY";
		return fmtstr;
	case 0x0081:
		fmtstr="CF_DSPTEXT";
		return fmtstr;
	case 0x0082:
		fmtstr="CF_DSPBITMAP";
		return fmtstr;
	case 0x0083:
		fmtstr="CF_DSPMETAFILEPICT";
		return fmtstr;
	case 0x008E:
		fmtstr="CF_DSPENHMETAFILE";
		return fmtstr;
	case 0x0200:
		fmtstr="CF_PRIVATEFIRST";
		return fmtstr;
	case 0x02FF:
		fmtstr="CF_PRIVATELAST";
		return fmtstr;
	case 0x0300:
		fmtstr="CF_GDIOBJFIRST";
		return fmtstr;
	case 0x03FF:
		fmtstr="CF_GDIOBJLAST";
		return fmtstr;
	default:
		fmtstr.Format("%d",value);
		return fmtstr;
	}
	fmtstr="";
	return fmtstr;
}