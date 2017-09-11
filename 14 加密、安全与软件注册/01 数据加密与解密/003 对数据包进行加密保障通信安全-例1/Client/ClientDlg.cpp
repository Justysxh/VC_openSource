// ClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "ClientDlg.h"

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
// CClientDlg dialog

CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClientDlg)
	m_name = _T("");
	m_servername = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClientDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_EDIT2, m_info);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_servername);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClientDlg, CDialog)
	//{{AFX_MSG_MAP(CClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONSEND, OnButtonsend)
	ON_BN_CLICKED(IDC_BUTTONJOIN, OnButtonjoin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClientDlg message handlers

BOOL CClientDlg::OnInitDialog()
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
	pMysocket = new CMysocket(this); //创建套接字对象
	if (!pMysocket->Create()) //创建套接字
	{
		delete pMysocket;
		MessageBox("套接字创建失败.");
		return false;
	}
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CClientDlg::OnPaint() 
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
HCURSOR CClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CClientDlg::OnButtonsend() 
{
	// TODO: Add your control notification handler code here
	CString str,temp;
	m_info.GetWindowText(str);
	if (str.IsEmpty()|m_name.IsEmpty())
		return;
	temp.Format("%s说: %s",m_name,str);
	temp = Enjcrypt(temp,123456);
	int num = pMysocket->Send(temp.GetBuffer(temp.GetLength()),temp.GetLength());
	m_info.SetWindowText("");
	m_info.SetFocus();
}

void CClientDlg::ReceiveData()
{
	char buffer[200];
	//接收传来的数据
	int factdata =  pMysocket->Receive(buffer,200);
	
	buffer[factdata] = '\0';
	CString str;
	str.Format("%s",buffer);
	str = Decrypt(str,123456);
	int i = m_list.GetCount();
	//将数据添加到列表框中
	m_list.InsertString(m_list.GetCount(),str);
}

void CClientDlg::OnButtonjoin() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString servername = m_servername; //读取服务器名称
	int port;
	port = 70; //获取端口
	
	if  (! pMysocket->Connect(servername,port)) //连接服务器
	{
		MessageBox("连接服务器失败!");
		return;
	}
	CString str;
	str.Format("%s----->%s",m_name,"进入聊天室");
	str = Enjcrypt(str,123456);
	int num = pMysocket->Send(str.GetBuffer(0),str.GetLength());
}

CString CClientDlg::Enjcrypt(CString s,WORD k)
{
	CString Str,Str1,Result;
	int i,j;
	Str = s;
	for(i=0;i<s.GetLength();i++)
	{
		Str.SetAt(i,s.GetAt(i)+k);
	}
	s = Str;
	for(i=0;i<s.GetLength();i++)
	{
		j = (BYTE)s.GetAt(i);
		Str1 = "01";
		Str1.SetAt(0,65+j/26);
		Str1.SetAt(1,65+j%26);
		Result += Str1;
	}
	return Result;
}

CString CClientDlg::Decrypt(CString s,WORD k)
{
	CString Result,Str;
	int i,j;
	for(i=0;i<s.GetLength()/2;i++)
	{
		j=((BYTE)s.GetAt(2*i)-65)*26;
		j+=(BYTE)s.GetAt(2*i+1)-65;
		Str = "0";
		Str.SetAt(0,j);
		Result += Str;
	}
	s = Result;
	for(i=0;i<s.GetLength();i++)
	{
		Result.SetAt(i,(BYTE)s.GetAt(i)-k);
	}
	return Result;
}