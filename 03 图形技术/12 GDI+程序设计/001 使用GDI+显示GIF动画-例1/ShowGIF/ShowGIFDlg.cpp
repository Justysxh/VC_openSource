// ShowGIFDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ShowGIF.h"
#include "ShowGIFDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CMemDC : public CDC 
{
private:
	CBitmap*	m_bmp;
	CBitmap*	m_oldbmp;
	CDC*		m_pDC;
	CRect		m_Rect;
public:
	CMemDC(CDC* pDC, const CRect& rect) : CDC()
	{
		CreateCompatibleDC(pDC);
		m_bmp = new CBitmap;
		m_bmp->CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
		m_oldbmp = SelectObject(m_bmp);
		m_pDC = pDC;
		m_Rect = rect;
		BitBlt(m_Rect.left, m_Rect.top, m_Rect.Width(), m_Rect.Height(), 
				pDC, m_Rect.left, m_Rect.top, WHITENESS);
	}
	~CMemDC() 
	{
		m_pDC->BitBlt(m_Rect.left, m_Rect.top, m_Rect.Width(), m_Rect.Height(), 
				this, m_Rect.left, m_Rect.top, SRCCOPY);
		SelectObject(m_oldbmp);
		if (m_bmp != NULL) 
			delete m_bmp;
	}
};


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
// CShowGIFDlg dialog

CShowGIFDlg::CShowGIFDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShowGIFDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShowGIFDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
	m_pBmp = NULL;
	m_nFrameIndex = 0;
	m_bLoaded = FALSE;
}

void CShowGIFDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShowGIFDlg)
	DDX_Control(pDX, IDC_DEMOAREA, m_DemoArea);
	DDX_Control(pDX, IDC_GIFNAME, m_GifName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CShowGIFDlg, CDialog)
	//{{AFX_MSG_MAP(CShowGIFDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BROWN, OnBrown)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowGIFDlg message handlers

BOOL CShowGIFDlg::OnInitDialog()
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
	
	SetTimer(1, 200, NULL);	//开始一个计时器
	GdiplusStartup(&m_pGdiToken,&m_Gdiplus,NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShowGIFDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CShowGIFDlg::OnPaint() 
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
HCURSOR CShowGIFDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CShowGIFDlg::OnBrown() 
{
	CFileDialog flDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
						"Gif图片|*.gif||");
	if (flDlg.DoModal()==IDOK)
	{
		CString szFileName = flDlg.GetPathName();
		m_GifName.SetWindowText(szFileName);
		//显示Gif图像
		m_pBmp = Bitmap::FromFile(szFileName.AllocSysString());
		if (m_pBmp != NULL)
		{
			m_bLoaded = TRUE;
			m_nFrameIndex = 0;
		}
	}
}

void CShowGIFDlg::OnTimer(UINT nIDEvent) 
{
	if (m_bLoaded)
	{
		//获取帧维数
		int nDimCount = m_pBmp->GetFrameDimensionsCount();
		//获取标识Dimension的GUID
		GUID *pGuids = new GUID[nDimCount];
		m_pBmp->GetFrameDimensionsList(pGuids, nDimCount);
		//获取第一个Dimension中的图像帧数
		int  m_FrameCount = m_pBmp->GetFrameCount(pGuids);
		UINT nSize = 0;
		UINT nDelay = PropertyTagFrameDelay;
		//先计算属性相关数据的大小
		m_pBmp->GetPropertySize(&nSize, &nDelay);
		
		PropertyItem *pItem = NULL;
		pItem = (PropertyItem*)malloc(nSize);
		m_pBmp->GetAllPropertyItems(nSize, nDelay, pItem);

		//获取每一帧的时间间隔
		nDelay = ((long*)pItem->value)[m_nFrameIndex];
		free(pItem);
		delete [] pGuids;	

		CMemDC dc(m_DemoArea.GetDC(), CRect(0, 0, 
					m_pBmp->GetWidth(), m_pBmp->GetHeight()));

		//显示图像帧
		Graphics graphic(dc.m_hDC);
		graphic.DrawImage(m_pBmp, 0, 0, m_pBmp->GetWidth(), m_pBmp->GetHeight());
		if (m_nFrameIndex >= m_FrameCount - 1)
		{
			m_nFrameIndex = 0;
		}
		GUID Guid = FrameDimensionTime;
		m_pBmp->SelectActiveFrame(&Guid, m_nFrameIndex++);	
	}
	CDialog::OnTimer(nIDEvent);
}
