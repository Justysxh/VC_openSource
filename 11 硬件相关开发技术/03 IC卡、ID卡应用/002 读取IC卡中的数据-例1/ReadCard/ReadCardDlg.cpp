// ReadCardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ReadCard.h"
#include "ReadCardDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "Mwic_32.h"
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
#pragma comment (lib,"Mwic_32.lib")

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
// CReadCardDlg dialog

CReadCardDlg::CReadCardDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReadCardDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReadCardDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReadCardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReadCardDlg)
	DDX_Control(pDX, IDC_DATA, m_Data);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CReadCardDlg, CDialog)
	//{{AFX_MSG_MAP(CReadCardDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	ON_BN_CLICKED(IDC_READ, OnRead)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReadCardDlg message handlers

BOOL CReadCardDlg::OnInitDialog()
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
	//获取ID卡状态
	__int16 status = -1;
	
	__int16 result =get_status(icdev,&status);

	if (result<0)
	{
		MessageBox("获取IC卡状态错误");
	}
	else if ((result==0)&&(status==0))
		MessageBox("请插入ID卡");
	
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CReadCardDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CReadCardDlg::OnPaint() 
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
HCURSOR CReadCardDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CReadCardDlg::OnCancel() 
{
	ic_exit(icdev);
	CDialog::OnCancel();
}

void CReadCardDlg::OnRead() 
{
	__int16 result;
	unsigned char data[224];
	result = srd_4442(icdev,33,223,data);
	//蜂鸣
	dv_beep(icdev,20);
	if (result<0)
		MessageBox("数据读取失败");
	else
	{
		int i =0;
		for (i= 0; i<224;i++)
		{
			if (data[i]==255)
				break;
		}
		unsigned char* pArray = new unsigned char[i+1];
		memset(pArray,0,i+1);
		memcpy(pArray,data,i);
		pArray[i]= 0;
		m_Data.SetWindowText((char*)pArray);
		delete pArray;
	}
}
