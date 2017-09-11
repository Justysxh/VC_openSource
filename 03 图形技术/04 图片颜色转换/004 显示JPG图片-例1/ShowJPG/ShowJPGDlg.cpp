// ShowJPGDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ShowJPG.h"
#include "ShowJPGDlg.h"
#include "objidl.h"

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
// CShowJPGDlg dialog

CShowJPGDlg::CShowJPGDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShowJPGDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShowJPGDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_IsShow = FALSE;
}

void CShowJPGDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShowJPGDlg)
	DDX_Control(pDX, IDC_DIR, m_dir);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CShowJPGDlg, CDialog)
	//{{AFX_MSG_MAP(CShowJPGDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_VSCROLL()
	ON_WM_SIZE()
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowJPGDlg message handlers

BOOL CShowJPGDlg::OnInitDialog()
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
	//this->SetTimer(1,500,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShowJPGDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CShowJPGDlg::OnPaint() 
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
	if (m_IsShow==TRUE)
	{
		CDC * dc= GetDC();
		int vpos = GetScrollPos(SB_VERT);
		int hpos = GetScrollPos(SB_HORZ);
		//dc->SetWindowOrg(0,pos);
		m_picture->Render(*dc,1-hpos,50-vpos,(int)(m_width/26.45),(int)(m_height/26.45)
			,0,m_height,m_width,-m_height,NULL);
	
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShowJPGDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CShowJPGDlg::OnOK() 
{
	CFileDialog m_dlg(TRUE,"JPG",NULL,NULL,"JPG(*.jpg)|*.JPG|gif|*.gif",this);
	if (m_dlg.DoModal()==IDOK)
	{
		CString m_filename =m_dlg.GetPathName();
		
		m_dir.SetWindowText(m_filename);

		CFile m_file(m_filename,CFile::modeRead );
		
		//获取文件长度
		DWORD m_filelen = m_file.GetLength(); 
		
		//在堆上分配空间
		HGLOBAL m_hglobal = GlobalAlloc(GMEM_MOVEABLE,m_filelen);

		LPVOID pvdata = NULL;
		//锁定堆空间,获取指向堆空间的指针
		pvdata = GlobalLock(m_hglobal);

		//将文件数据读区到堆中
		m_file.ReadHuge(pvdata,m_filelen);

		IStream*  m_stream;

		GlobalUnlock(m_hglobal);

		//在堆中创建流对象
		CreateStreamOnHGlobal(m_hglobal,TRUE,&m_stream);

		//利用流加载图像
		OleLoadPicture(m_stream,m_filelen,TRUE,IID_IPicture,(LPVOID*)&m_picture);
	
		m_picture->get_Width(&m_width);
		m_picture->get_Height(&m_height);	

		CDC* dc = GetDC();
		
		m_IsShow = TRUE;
		CRect rect;
		GetClientRect(rect);
		SetScrollRange(SB_VERT,0,(int)(m_height/26.45)-rect.Height());
		SetScrollRange(SB_HORZ,0,(int)(m_width/26.45)-rect.Width());

		m_picture->Render(*dc,1,50,(int)(m_width/26.45),(int)(m_height/26.45),0,m_height,m_width,-m_height,NULL);
		
	}
}

void CShowJPGDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
//	OnOK();
	CDialog::OnTimer(nIDEvent);
}

BOOL CShowJPGDlg::PreTranslateMessage(MSG* pMsg) 
{
	return CDialog::PreTranslateMessage(pMsg);
}

void CShowJPGDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	switch (nSBCode)
	{
		case SB_THUMBTRACK:
		int pos =GetScrollPos(SB_VERT);
		CDC* pDC = GetDC();
		//pDC->SetViewportOrg(0,pos);
		SetScrollPos(SB_VERT,nPos);
		Invalidate();

		//ScrollWindow(0,nPos-pos);
		break;
	}
	
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CShowJPGDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	if (m_IsShow)
	{
		CRect rect;
		GetClientRect(rect);
		
		if ((int)(m_height/26.45)-rect.Height()<0)
			ShowScrollBar(SB_VERT,FALSE);
		else
			ShowScrollBar(SB_VERT);

		if ((int)(m_width/26.45)-rect.Width()<0)
			ShowScrollBar(SB_HORZ,FALSE);
		else
			ShowScrollBar(SB_HORZ);

		SetScrollRange(SB_VERT,0,(int)(m_height/26.45)-rect.Height());
		SetScrollRange(SB_HORZ,0,(int)(m_width/26.45)-rect.Width());
	}
}

void CShowJPGDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	switch (nSBCode)
	{
		case SB_THUMBTRACK:
		int pos =GetScrollPos(SB_HORZ);
		CDC* pDC = GetDC();
		//pDC->SetViewportOrg(pos,0);
		SetScrollPos(SB_HORZ,nPos);
		Invalidate();
		break;
	}	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
