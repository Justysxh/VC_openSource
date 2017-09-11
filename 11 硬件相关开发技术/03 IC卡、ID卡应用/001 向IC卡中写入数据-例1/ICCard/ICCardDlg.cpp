// ICCardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Mwic_32.h"
#include "ICCard.h"
#include "ICCardDlg.h"



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
// CICCardDlg dialog

CICCardDlg::CICCardDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CICCardDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CICCardDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	icdev = 0;
}

void CICCardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CICCardDlg)
	DDX_Control(pDX, IDC_HINT, m_Hint);
	DDX_Control(pDX, IDC_ICDATA, m_ICData);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CICCardDlg, CDialog)
	//{{AFX_MSG_MAP(CICCardDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CICCardDlg message handlers

BOOL CICCardDlg::OnInitDialog()
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
	

	//初始化端口 COM1 9600
	icdev= auto_init(0,9600);
	if (icdev<0)
		MessageBox("端口初始化失败,请检查接口线是否连接正确.");

	//设置密码模式,使设备密码无效,否则在设备加电时,必须核对密码才能进行后续操作
	setsc_md(icdev,1);
	__int16 rpass;
	//获取ID卡状态
	__int16 status = -1;
	
	__int16 result =get_status(icdev,&status);

	if (result<0)
	{
		MessageBox("获取IC卡状态错误");
	}
	else if ((result==0)&&(status==0))
		MessageBox("请插入ID卡");
	
	//西门子4442IC卡初试密码为ffffff
	unsigned char pass[3]={0xff,0xff,0xff};
	//验证密码
	rpass =csc_4442(icdev,3,pass);
	if (rpass<0)
	{
		MessageBox("IC卡密码核对错误,只能读取数据");
	}	
	return TRUE;  

}

void CICCardDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CICCardDlg::OnPaint() 
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
HCURSOR CICCardDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CICCardDlg::OnOK() 
{
	if (MessageBox("确实要写入数据吗?","提示",MB_YESNO)==IDYES)
	{
		CString str;
		m_ICData.GetWindowText(str);
		if (str.IsEmpty())
		{
			MessageBox("请输入数据");
			return;
		}
		if (str.GetLength()>224)
		{
			MessageBox("写入数据不能超过224个字符","提示",64);
			return;
		}

		__int16 result;
		
		//在IC卡的应用区中写入数据
		result =swr_4442(icdev,33,str.GetLength(),(unsigned char*)str.GetBuffer(0));
			
		if (result==0)
		{
			MessageBox("数据写入成功.","提示",64);
		}
		else
		{
			MessageBox("数据写入失败.","提示",64);
		}
	}
}

void CICCardDlg::OnCancel() 
{	
	ic_exit(icdev);
	CDialog::OnCancel();
}

HBRUSH CICCardDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
		CBrush brush(RGB(255,0,0));	
	if ((nCtlColor==CTLCOLOR_STATIC)&&(pWnd->m_hWnd==m_Hint.m_hWnd))
	{
		CBrush brush(RGB(255,0,0));
		pDC->SelectObject(&brush);
		pDC->SetTextColor(RGB(255,0,0));
		pDC->SetBkMode(TRANSPARENT);
		return brush;
	}
	return brush;
	// TODO: Return a different brush if the default is not desired
	//return hbr;
}
