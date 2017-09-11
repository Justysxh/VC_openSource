// EncryptLockDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EncryptLock.h"
#include "EncryptLockDlg.h"
#include "elet2.h"
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
// CEncryptLockDlg dialog

CEncryptLockDlg::CEncryptLockDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEncryptLockDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEncryptLockDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEncryptLockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEncryptLockDlg)
	DDX_Control(pDX, IDC_BUTLOGIN, m_Login);
	DDX_Control(pDX, IDC_EDIT1, m_Data);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEncryptLockDlg, CDialog)
	//{{AFX_MSG_MAP(CEncryptLockDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTLOGIN, OnButlogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEncryptLockDlg message handlers

BOOL CEncryptLockDlg::OnInitDialog()
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
	m_Login.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP2))); //设置位图
	char* pcPassword="0000000000000000";
	char* buf="123456";
    unsigned short usWrittenLen;
 	long ret = EleT2Write(0,pcPassword,(unsigned char *)buf,
		6,&usWrittenLen);						//写入数据
	switch(ret)										//判断是否成功
	{
	case ELE_T2_SUCCESS:
		MessageBox("函数执行成功");
		break;
    case ELE_T2_NO_MORE_DEVICE :           
		MessageBox("没有找到相应的模板设备");
		break;
    case ELE_T2_INVALID_PASSWORD :         
		MessageBox("无效的密码");
		break;
    case ELE_T2_INSUFFICIENT_BUFFER:      
		MessageBox("缓冲区不足");
		break;
    case ELE_T2_BEYOND_DATA_SIZE:          
		MessageBox("读写数据区越界"); 
		break;
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEncryptLockDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEncryptLockDlg::OnPaint() 
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
HCURSOR CEncryptLockDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEncryptLockDlg::OnButlogin() 
{
	// TODO: Add your control notification handler code here
	unsigned short usReadLen;
	CString strtext,Data;
	char buf[6];
	long ret = EleT2Read(0,(unsigned char *)buf,6,&usReadLen);
	switch(ret)
	{
    case ELE_T2_NO_MORE_DEVICE :           
		MessageBox("没有找到相应的模板设备");
		break;
    case ELE_T2_INVALID_PASSWORD :         
		MessageBox("无效的密码");
		break;
    case ELE_T2_INSUFFICIENT_BUFFER:      
		MessageBox("缓冲区不足");
		break;
    case ELE_T2_BEYOND_DATA_SIZE:          
		MessageBox("读写数据区越界"); 
		break;
	}
	buf[6]='\0';
	strtext = buf;
	m_Data.GetWindowText(Data);
	if(ret != ELE_T2_SUCCESS || strtext != Data)
	{
		MessageBox("请插入指定的加密锁");
		CDialog::OnCancel();
	}
	else
	{
		MessageBox("注册成功");
	}
}
