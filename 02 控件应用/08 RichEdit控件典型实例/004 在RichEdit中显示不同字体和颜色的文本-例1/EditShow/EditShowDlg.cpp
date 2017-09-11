// EditShowDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EditShow.h"
#include "EditShowDlg.h"

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
// CEditShowDlg dialog

CEditShowDlg::CEditShowDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditShowDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditShowDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEditShowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditShowDlg)
	DDX_Control(pDX, IDC_RICHEDIT1, m_RichEdit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEditShowDlg, CDialog)
	//{{AFX_MSG_MAP(CEditShowDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTFONT, OnButfont)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditShowDlg message handlers

BOOL CEditShowDlg::OnInitDialog()
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

void CEditShowDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEditShowDlg::OnPaint() 
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
HCURSOR CEditShowDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEditShowDlg::OnButfont() 
{
	CFontDialog dlg;						//初始化字体信息
	if(dlg.DoModal()==IDOK)				//判断是否按下"确定"按钮
	{
		LOGFONT temp;					//声明LOGFONT结构指针
		dlg.GetCurrentFont(&temp);			//获取当前字体信息
		CHARFORMAT cf;				//声明CHARFORMAT变量
		memset(&cf, 0, sizeof(CHARFORMAT));	//分配内存
		m_RichEdit.GetDefaultCharFormat(cf);	//获得缺省的字符格式化属性
		cf.yHeight  = temp.lfWeight;		//设置字号
		cf.dwMask = CFM_COLOR | CFM_SIZE | CFM_FACE;	//设置标记属性
		cf.dwEffects = CFE_BOLD;			//设置标记属性有效
		cf.crTextColor = dlg.GetColor();		//设置颜色
		strcpy(cf.szFaceName,temp.lfFaceName);//设置字体
		m_RichEdit.SetWordCharFormat(cf);	//设置控件显示字体
		m_RichEdit.SetSel(-1,-1);			//选择最后一行
		m_RichEdit.ReplaceSel("\n");		//插入换行符
		m_RichEdit.SetSel(-1,-1);			//选择最后一行
	}
}

