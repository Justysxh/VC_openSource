// EnumSysFontDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EnumSysFont.h"
#include "EnumSysFontDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
CString fontname;
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

CStringList fontlist;
int CALLBACK EnumFontList (const ENUMLOGFONTEX *lpelfe, const NEWTEXTMETRICEX *lpntme, unsigned long FontType, LPARAM lParam) 
{
	POSITION pos = fontlist.Find(lpelfe->elfLogFont.lfFaceName);
	if (pos == NULL)
		fontlist.AddTail(lpelfe->elfLogFont.lfFaceName);
	return 1 ;
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
// CEnumSysFontDlg dialog

CEnumSysFontDlg::CEnumSysFontDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEnumSysFontDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEnumSysFontDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEnumSysFontDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnumSysFontDlg)
	DDX_Control(pDX, IDC_DEMO, m_demo);
	DDX_Control(pDX, IDC_FONTLIST, m_FontList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEnumSysFontDlg, CDialog)
	//{{AFX_MSG_MAP(CEnumSysFontDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_FONTLIST, OnSelchangeFontlist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnumSysFontDlg message handlers

BOOL CEnumSysFontDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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
	OnOK();	
	// TODO: Add extra initialization here	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEnumSysFontDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEnumSysFontDlg::OnPaint() 
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
	OnSelchangeFontlist() ;
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEnumSysFontDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEnumSysFontDlg::OnOK() 
{
	CDC* dc = GetDC();
	CString str;
	fontlist.RemoveAll();
	m_FontList.ResetContent();
	LOGFONT m_logfont;
	memset(&m_logfont,0,sizeof(m_logfont));
	m_logfont.lfCharSet = DEFAULT_CHARSET;

	m_logfont.lfFaceName[0] =NULL;

	EnumFontFamiliesEx(dc->m_hDC,&m_logfont,(FONTENUMPROC)EnumFontList,100,0);

	POSITION pos;
	for ( pos =fontlist.GetHeadPosition() ;pos != NULL;)
	{
		str = fontlist.GetNext(pos);
		m_FontList.AddString(str);
	}
}


void CEnumSysFontDlg::OnSelchangeFontlist() 
{
	CString str;
	m_FontList.GetWindowText(str);
	if (!str.IsEmpty())
	{
		CFont m_font;
		m_font.CreateFont(-14,-10,0,0,600,0,0,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,FF_ROMAN,str);
		
		CRect m_rect;
		m_demo.GetClientRect(m_rect);
		m_rect.DeflateRect(1,1,1,1);

		CDC* pDC = m_demo.GetDC();
		
		pDC->FillRect(m_rect,NULL);	

		pDC->SelectObject(&m_font);
		pDC->SetBkMode(TRANSPARENT);
		pDC->TextOut(0,8,"明日科技");
		
		m_font.Detach();
	
	}
}
