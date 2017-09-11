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
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
	m_bSending = FALSE;
	m_hGlobal = NULL;
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClientDlg)
	DDX_Control(pDX, IDC_SERVERIP, m_ServerIP);
	DDX_Control(pDX, IDC_PORT, m_Port);
	DDX_Control(pDX, IDC_FILERECPROGRESS, m_Progress);
	DDX_Control(pDX, IDC_CANCELREC, m_Cancel);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClientDlg, CDialog)
	//{{AFX_MSG_MAP(CClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_CANCELREC, OnCancelRec)
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
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
	m_ClientSock.SetDlg(this);
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

void CClientDlg::OnOK() 
{
	
}

//接收数据
void CClientDlg::ReceiveData()
{
	static int nMaxLen = 1024*100;//定义接收最大长度
	HGLOBAL hGlobal = GlobalAlloc(GHND, nMaxLen);//定义接收全局缓冲区
	BYTE* pBuffer = (BYTE*)GlobalLock(hGlobal);//获取指定全局缓冲区指针
	int nFact = m_ClientSock.Receive(pBuffer, nMaxLen);//接收数据
	int nPackage = sizeof(CPackage);	//计算数据包大小
	int SunSize = 0;//本次处理数据总大小
	BYTE *Ptemp = NULL;//处理缓冲区数据指针
	BYTE * temp = NULL;//全局缓冲区指针
	if (m_hGlobal != NULL)//当全局缓冲区中存在数据
	{
		BYTE* pData = (BYTE*)GlobalLock(m_hGlobal);
		int GSize = GlobalSize(m_hGlobal);//获取数据大小
		SunSize = GSize + nFact;//全局缓冲区数据与接收数据大小
		temp = new BYTE[SunSize];//定义本次处理的临时缓冲区
		Ptemp = temp;
		memcpy(temp,pData,GSize);//复制全局缓冲区中数据
		memcpy(temp + GSize,pBuffer,nFact);//复制本次接收的数据
		GlobalUnlock(m_hGlobal);
		GlobalFree(m_hGlobal);
		m_hGlobal = NULL;
	}
	else
	{
		SunSize = nFact;
		Ptemp = pBuffer;
	}

	CPackage* pPackage = (CPackage*)Ptemp;//获取需要处理的第一个包
	while ((SunSize >= nPackage) && (SunSize >= pPackage->m_dwData))	
	{
		HandleRecData(pPackage);//处理包
		SunSize -= nPackage + pPackage->m_dwData;//总大小减去已处理包大小
		Ptemp += nPackage + pPackage->m_dwData;//将指针指向下一个包的地址
		pPackage = (CPackage*)Ptemp;//获取本次处理的包
	}
	if (SunSize > 0)//将剩余数据写入全局缓冲区
	{
		m_hGlobal = GlobalAlloc(GHND, SunSize);
		BYTE* pData = (BYTE*)GlobalLock(m_hGlobal);
		memcpy(pData,Ptemp,SunSize);
		GlobalUnlock(m_hGlobal);
	}
	else
	{
		GlobalUnlock(m_hGlobal);
		GlobalFree(m_hGlobal);
		m_hGlobal = NULL;
	}

	if (temp != NULL)
		delete temp;

	GlobalUnlock(hGlobal);
	GlobalFree(hGlobal);
}

void CClientDlg::HandleRecData(CPackage *pPackage)
{
	if (pPackage != NULL)
	{
		if (pPackage->m_Type==PTFILE)				//只处理文件数据
		{
			static CFile file;			
			
			if (pPackage->m_Flag==SFBEGIN)			//开始发送
			{
				//读取文件名
				char szFileName[128] = {0};
				memcpy(szFileName, pPackage->m_Data, 128);				
				CFileDialog flDlg(FALSE, "", szFileName);				
				if (flDlg.DoModal()==IDOK) 
				{
					if (m_bSending)						//当前文件发送没有结束，又发送一个文件
					{
						file.Close();
					}

					m_Progress.SetPos(0);
					//确定真个文件大小
					DWORD dwFileSize = pPackage->m_dwFileSize;
					//设置进度条的表示范围
					m_Progress.SetRange32(0, dwFileSize);
					
					CString szFile = flDlg.GetPathName();
					file.Open(szFile, CFile::modeCreate|CFile::modeReadWrite);
					//计算数据报中文件数据的大小
					int nFileLen = pPackage->m_dwData - 128;
					
					if (nFileLen >= dwFileSize)	//文件比较小，只发送一次数据包就完成了文件发送
					{
						m_bSending = FALSE;					//设置结束标记
						file.Close();
						m_Progress.SetPos(0);
						m_Cancel.EnableWindow(FALSE);
						return;
					}

					//读取数据报中的文件数据
					BYTE* pTmp = pPackage->m_Data;
					pTmp += 128;	//掠过文件名数据，定位到文件数据
					file.WriteHuge(pTmp, nFileLen);
					m_Progress.SetPos(nFileLen);
					//发送接收标记
					CPackage package;
					package.m_Type = PTFILE;
					package.m_Flag = SFACCEPT;
					package.m_dwSize = sizeof(CPackage);
					package.m_dwData = 0;
					package.m_dwFileSize = 0;
					m_ClientSock.Send(&package, sizeof(CPackage));	

					m_bSending = TRUE;
					m_Cancel.EnableWindow();
				}
				else
				{
					//取消文件发送
					CPackage package;
					package.m_Type = PTFILE;
					package.m_Flag = SFDENY;
					package.m_dwSize = sizeof(CPackage);
					package.m_dwData = 0;
					package.m_dwFileSize = 0;
					m_ClientSock.Send(&package, sizeof(CPackage));
					m_Cancel.EnableWindow();

				}
			}
			else if (pPackage->m_Flag==SFSENDING)	//文件发送中
			{
				file.WriteHuge(pPackage->m_Data, pPackage->m_dwData);
				int nPos = m_Progress.GetPos();
				nPos += pPackage->m_dwData;
				m_Progress.SetPos(nPos);
			}
			else if (pPackage->m_Flag==SFEND)		//文件发送结束
			{
				file.WriteHuge(pPackage->m_Data, pPackage->m_dwData);
				m_bSending = FALSE;					//设置结束标记
				m_Cancel.EnableWindow(FALSE);
				file.Close();
				m_Progress.SetPos(0);
			}
			else if (pPackage->m_Flag==SFCANCEL)	//对方取消了文件发送
			{
				m_bSending = FALSE;					//设置结束标记
				file.Close();
				m_Cancel.EnableWindow(FALSE);
				m_Progress.SetPos(0);
				MessageBox("对方取消了文件发送!");
			}
		}
	}
}

void CClientDlg::OnExit() 
{
	CDialog::OnCancel();	
}

//取消接收文件
void CClientDlg::OnCancelRec() 
{
	if (m_bSending)
	{
		CPackage package;
		package.m_Type = PTFILE;
		package.m_Flag = SFCANCEL;	//取消接收文件
		package.m_dwSize = sizeof(CPackage);
		package.m_dwData = 0;
		package.m_dwFileSize = 0;
		m_ClientSock.Send(&package, sizeof(CPackage));		
	}
}

//与服务器建立连接
void CClientDlg::OnConnect() 
{
	CString szServerIP, szPort;
	m_ServerIP.GetWindowText(szServerIP);
	m_Port.GetWindowText(szPort);
	int nPort = atoi(szPort.GetBuffer(0));
	szPort.ReleaseBuffer(0);
	if (!m_bSending)		//当前没有进行文件传输
	{
		m_ClientSock.ShutDown();
		m_ClientSock.Close();
		m_ClientSock.Create();
		BOOL bRet = m_ClientSock.Connect(szServerIP, nPort);	
		if (!bRet)
		{
			MessageBox("连接失败!");
		}
	}
}
