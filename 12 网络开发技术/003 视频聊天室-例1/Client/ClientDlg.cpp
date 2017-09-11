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
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
	m_hGlobal = NULL;
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClientDlg)
	DDX_Control(pDX, IDC_IMAGE, m_Image);
	DDX_Control(pDX, IDC_INFOLIST, m_InfoList);
	DDX_Control(pDX, IDC_SENDCONTENT, m_SendContent);
	DDX_Control(pDX, IDC_SERVERIP, m_ServerIP);
	DDX_Control(pDX, IDC_PORT, m_Port);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClientDlg, CDialog)
	//{{AFX_MSG_MAP(CClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_BN_CLICKED(IDC_SEND, OnSend)
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
	m_ClientSock.SetDialog(this);

	BOOL bRet = InitSocket();
	if (!bRet)
	{
		MessageBox("初始化套接字失败!");
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
// the minimized window.
HCURSOR CClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CClientDlg::OnOK() 
{
	
}

void CClientDlg::ReceiveData()
{
	static int nMaxLen = 1024*10;
	HGLOBAL hGlobal = GlobalAlloc(GHND, nMaxLen);
	BYTE* pBuffer = (BYTE*)GlobalLock(hGlobal);
	int nFact = m_ClientSock.Receive(pBuffer, nMaxLen);
	static BOOL bCompleted = TRUE;	//数据包是否完整
	static BOOL bFirstRec = TRUE;	//首次接收数据

	int nPackage = sizeof(CPackage);	//计算数据包大小
rec:
	if(bFirstRec)	//首次接收数据,认为数据包中一定包含完整的数据包结构信息，数据不一定完整
	{
		CPackage* pPackage = (CPackage*)pBuffer;
		if (nFact - nPackage == pPackage->m_dwContent)	//正好是一个数据包的大小
		{
			bCompleted = TRUE;
			HandleRecData(pPackage);
			
			bFirstRec = TRUE;	
		
		}
		else	//数据包不完整，可能大于一个数据包也可能小于一个数据包
		{
			bCompleted = FALSE;
			if (nFact - nPackage < pPackage->m_dwContent)	//数据包中没有包含完整的数据,产生了分包
			{
				if (m_hGlobal != NULL)						//在m_hGlobal中存储数据
				{
					GlobalFree(m_hGlobal);
				}
				m_hGlobal = GlobalAlloc(GHND, nFact);
				BYTE* pData = (BYTE*)GlobalLock(m_hGlobal);
				//复制部分数据
				memcpy(pData, pBuffer, nFact);
				GlobalUnlock(m_hGlobal);
				bFirstRec = FALSE;
			}
			else											//数据包中包含不止一个数据包，产生了粘包
			{
				HandleRecData(pPackage);
				//计算剩余的数据
				int nLeaving = nFact - nPackage - pPackage->m_dwContent;
				BYTE* pTmp = pBuffer + nPackage + pPackage->m_dwContent;
				while (nLeaving > 0)
				{
					bCompleted = FALSE;
					if (nLeaving > nPackage)	//数据包含有完整的数据包结构
					{
						CPackage* pPackage = (CPackage*) pTmp;
						//数据中包含一个或一个以上的数据包
						if (nLeaving >= pPackage->m_dwContent + nPackage)
						{
							HandleRecData(pPackage);
							nLeaving -= pPackage->m_dwContent + nPackage;
							if (nLeaving == 0)
								bFirstRec = TRUE;
							pTmp += pPackage->m_dwContent + nPackage;
						}
						else	//数据中包含的一个数据包数据不完整
						{
							if (m_hGlobal != NULL)						//在m_hGlobal中存储数据
							{
								GlobalFree(m_hGlobal);
							}
							m_hGlobal = GlobalAlloc(GHND, nLeaving);
							BYTE* pData = (BYTE*)GlobalLock(m_hGlobal);
							memcpy(pData, pTmp, nLeaving);
							GlobalUnlock(m_hGlobal);
							nLeaving = 0;
							bCompleted = FALSE;
							GlobalUnlock(m_hGlobal);
							break;

						}
					}
					else		//数据包含有不完整的数据包结构	
					{
						if (m_hGlobal != NULL)						//在m_hGlobal中存储数据
						{
							GlobalFree(m_hGlobal);
						}
						m_hGlobal = GlobalAlloc(GHND, nLeaving);
						BYTE* pData = (BYTE*)GlobalLock(m_hGlobal);
						memcpy(pData, pTmp, nLeaving);
						nLeaving = 0;
						bCompleted = FALSE;
						GlobalUnlock(m_hGlobal);
						break;						
					}
				
				}
			}

		}
	}
	else							//bFirstRec==FALSE 不是首次接收数据
	{
		if (bCompleted)				//之前接收的数据包是完整的
		{
			bFirstRec = TRUE;
			goto rec;
		}
		if (bCompleted == FALSE)	//之前的数据包产生了分包或粘包，继续接收数据	
		{
			//获取之前接收的数据大小
			DWORD dwSize = GlobalSize(m_hGlobal);
			BYTE* pGlobal = (BYTE*)GlobalLock(m_hGlobal);
			BYTE* pBuf = new BYTE[dwSize];
			//将数据复制到pBuf中
			memcpy(pBuf, pGlobal, dwSize);
			GlobalUnlock(m_hGlobal);
			GlobalFree(m_hGlobal);
			m_hGlobal = NULL;
			//如果数据包结构不完整，先接收数据包的结构
			if (dwSize < nPackage)
			{
				if(dwSize + nFact < nPackage)	//将当前的数据添加到堆中仍不能描述完整的数据包结构
				{
					m_hGlobal = GlobalAlloc(GHND, dwSize + nFact);
					BYTE* pData = (BYTE*)GlobalLock(m_hGlobal);
					memcpy(pData, pBuf, dwSize);
					pData += dwSize;
					memcpy(pData, pBuffer, nFact);
					delete [] pBuf;
					bFirstRec = FALSE;
					bCompleted = FALSE;
					return;
				}
				else						//将当前的数据添加到堆中能够描述完整的数据包结构	
				{
					//先填充数据包结构
					int nNeedPackage = nPackage - dwSize;
					BYTE* pPack = new BYTE[nPackage];
					memcpy(pPack, pBuf, dwSize);
					BYTE* pTmp = pPack;
					pTmp += dwSize;
					memcpy(pTmp, pBuffer, nNeedPackage);
					CPackage* pPackage = (CPackage*)pPack;
					//获取数据的长度
					int nDataLen = pPackage->m_dwContent;
					delete [] pPack;

					//接收数据包数据
					if (nFact - nNeedPackage < nDataLen)	//pBuffer中包含的数据不是一个完整的数据包数据
					{
						m_hGlobal = GlobalAlloc(GHND, dwSize + nFact);
						BYTE* pData = (BYTE*)GlobalLock(m_hGlobal);
						memcpy(pData, pBuf, dwSize);
						pTmp = pData;
						pTmp += dwSize;
						memcpy(pTmp, pBuffer, nFact);
						GlobalUnlock(m_hGlobal);
						bCompleted = FALSE;
					}
					else	//pBuffer中包含了完整的数据包数据，并且可能包含多个数据包
					{
						//先构建一个完整的数据包进行处理
						m_hGlobal = GlobalAlloc(GHND, nPackage + nDataLen);
						BYTE* pData = (BYTE*)GlobalLock(m_hGlobal);
						memcpy(pData, pBuf, dwSize);
						pTmp = pData;
						pTmp += dwSize;
						memcpy(pTmp, pBuffer, nDataLen);

						pPackage = (CPackage*)pData;

						HandleRecData(pPackage);
			
						GlobalUnlock(m_hGlobal);
						GlobalFree(m_hGlobal);
						m_hGlobal = NULL;
						bCompleted = TRUE;

						//接收其他数据包数据
						//计算剩余数据的大小
						int nLeaving = nFact - nNeedPackage - nDataLen;
						//定位到pBuffer中的余下数据部分
						pTmp = pBuffer + nNeedPackage + nDataLen;
						if (nLeaving == 0)
						{
							bCompleted = TRUE;
							bFirstRec = TRUE;							
						}
						while (nLeaving > 0)
						{
							bCompleted = FALSE;
							if (nLeaving > nPackage)	//数据包含有完整的数据包结构
							{
								CPackage* pPackage = (CPackage*) pTmp;
								//数据中包含一个或一个以上的数据包
								if (nLeaving >= pPackage->m_dwContent + nPackage)
								{
									//进行数据包处理
									HandleRecData(pPackage);

									nLeaving -= pPackage->m_dwContent + nPackage;
									if (nLeaving == 0)
									{
										bCompleted = TRUE;
										bFirstRec = TRUE;
									}
									pTmp += pPackage->m_dwContent + nPackage;
								}
								else	//数据中包含的一个数据包数据不完整
								{
									if (m_hGlobal != NULL)						//在m_hGlobal中存储数据
									{
										GlobalFree(m_hGlobal);
										m_hGlobal = NULL;

									}
									m_hGlobal = GlobalAlloc(GHND, nLeaving);
									void* pData = GlobalLock(m_hGlobal);
									memcpy(pData, pTmp, nLeaving);
									GlobalUnlock(m_hGlobal);
									nLeaving = 0;
									bCompleted = FALSE;
									GlobalUnlock(m_hGlobal);
									break;

								}
							}
							else		//数据包含有不完整的数据包结构	
							{
								if (m_hGlobal != NULL)	
								{
									GlobalFree(m_hGlobal);
									m_hGlobal = NULL;
								}
								m_hGlobal = GlobalAlloc(GHND, nLeaving);
								void* pData = GlobalLock(m_hGlobal);
								memcpy(pData, pTmp, nLeaving);
								nLeaving = 0;
								bCompleted = FALSE;
								GlobalUnlock(m_hGlobal);
								break;						
							}
						
						}
					
					}
				}
			}
			else	//(dwSize >= nPackage) 数据包结构完整，接收数据
			{
				//读取数据包的大小，包含数据包结构大小和数据大小
				CPackage* pPackage = (CPackage*)pBuf;
				int nPackageSize = pPackage->m_dwContent + sizeof(CPackage);

				if (dwSize + nFact >= nPackageSize)	//之前接收的数据与现在接收的数据能够构成至少一个完整的数据包
				{
					//先组合一个完整的数据包进行处理
					m_hGlobal = GlobalAlloc(GHND, nPackageSize);
					BYTE* pData = (BYTE*)GlobalLock(m_hGlobal);
					memcpy(pData, pBuf, dwSize);
					BYTE* pTmp = pData;
					pTmp += dwSize;
					int nNeed = nPackageSize - dwSize;
					memcpy(pTmp, pBuffer, nNeed);
					pPackage = (CPackage*)pData;
					//进行数据包处理
					HandleRecData(pPackage);
					if (m_hGlobal != NULL)						//在m_hGlobal中存储数据
					{
						GlobalFree(m_hGlobal);
						m_hGlobal = NULL;
					}					

					bCompleted = TRUE;
					//计算剩余的数据
					int nLeaving = nFact - nNeed;
					pTmp = pBuffer + nNeed;
				
					while (nLeaving > 0)
					{
						bCompleted = FALSE;
						if (nLeaving > nPackage)	//数据包含有完整的数据包结构
						{
							CPackage* pPackage = (CPackage*) pTmp;
							//数据中包含一个或一个以上的数据包
							if (nLeaving >= pPackage->m_dwContent + nPackage)
							{
								HandleRecData(pPackage);
	
								nLeaving -= pPackage->m_dwContent + nPackage;
								if (nLeaving == 0)	
								{
									bCompleted = TRUE;
								}
								pTmp += pPackage->m_dwContent + nPackage;
							}
							else	//数据中包含的一个数据包数据不完整
							{
								if (m_hGlobal != NULL)						//在m_hGlobal中存储数据
								{
									GlobalFree(m_hGlobal);
									m_hGlobal = NULL;
								}
								m_hGlobal = GlobalAlloc(GHND, nLeaving);
								void* pData = GlobalLock(m_hGlobal);
								memcpy(pData, pTmp, nLeaving);
								GlobalUnlock(m_hGlobal);
								nLeaving = 0;
								bCompleted = FALSE;
								GlobalUnlock(m_hGlobal);
								break;

							}
						}
						else		//数据包含有不完整的数据包结构	
						{
							if (m_hGlobal != NULL)						//在m_hGlobal中存储数据
							{
								GlobalFree(m_hGlobal);
								m_hGlobal = NULL;
							}
							m_hGlobal = GlobalAlloc(GHND, nLeaving);
							void* pData = GlobalLock(m_hGlobal);
							memcpy(pData, pTmp, nLeaving);
							nLeaving = 0;
							bCompleted = FALSE;
							GlobalUnlock(m_hGlobal);
							break;						
						}
					}
				}
				else	//之前接收的数据与现在接收的数据不能构成一个完整的数据包，还需要继续接收数据
				{
					if (m_hGlobal != NULL)						//在m_hGlobal中存储数据
					{
						GlobalFree(m_hGlobal);
					}
					m_hGlobal = GlobalAlloc(GHND, dwSize + nFact);
					BYTE* pData = (BYTE*)GlobalLock(m_hGlobal);
					memcpy(pData, pBuf, dwSize);
					BYTE* pTmp = pData;
					pTmp += dwSize;
					memcpy(pTmp, pBuffer, nFact);
					bCompleted = FALSE;
					GlobalUnlock(m_hGlobal);					
				
				}
	
			}
			delete [] pBuf;
		}
	}
//	bFirstRec = FALSE;
	GlobalUnlock(hGlobal);
	GlobalFree(hGlobal);
}

//连接服务器
void CClientDlg::OnConnect() 
{
	CString szIP, szPort;
	m_ServerIP.GetWindowText(szIP);
	m_Port.GetWindowText(szPort);
	if (szIP.IsEmpty() || szPort.IsEmpty())
	{
		MessageBox("请设置服务器IP和端口号");
		return;
	}
	int nPort = atoi(szPort.GetBuffer(0));
	szPort.ReleaseBuffer();
	
	BOOL bRet = m_ClientSock.Connect(szIP, nPort);
	if (!bRet)
	{
		MessageBox("连接服务器失败!");
	}
}

BOOL CClientDlg::InitSocket()
{
	return m_ClientSock.Create();
}

//处理接收的数据
void CClientDlg::HandleRecData(CPackage *pPackage)
{
	if (pPackage != NULL)
	{
		if (pPackage->m_Type==ptText)	//文本数据
		{
			char* szData = (char* )pPackage->m_Data;
			m_InfoList.SetSel(-1, 0);
			m_InfoList.ReplaceSel("服务器say: \n");
			m_InfoList.SetSel(-1, 0);
			m_InfoList.ReplaceSel(szData);
			m_InfoList.SetSel(-1, 0);
			m_InfoList.ReplaceSel("\n");	//添加换行符
		}
		else if (pPackage->m_Type==ptImage)	//图像数据
		{
			BITMAPINFOHEADER bmpHeader;
			BITMAPINFO bmpInfo;
			bmpInfo.bmiHeader = bmpHeader;
			memcpy(&bmpHeader, pPackage->m_Data, sizeof(bmpHeader));
			BYTE* pBmpData = pPackage->m_Data;
			pBmpData += sizeof(bmpHeader);
			CDC* pDC = GetDC();
			HBITMAP hBmp = CreateDIBitmap(pDC->m_hDC, &bmpHeader, CBM_INIT, pBmpData, (BITMAPINFO*)&bmpHeader, DIB_RGB_COLORS);
			HBITMAP hOldBmp = m_Image.SetBitmap(hBmp);
			if (hOldBmp != NULL)
			{
				DeleteObject(hOldBmp);
			}
			//显示图像
			//...
			ReleaseDC(pDC);
		}		
	
	}
}

void CClientDlg::OnSend() 
{
	CString szSendInfo;
	m_SendContent.GetWindowText(szSendInfo);
	if (!szSendInfo.IsEmpty())
	{
		//填充数据包
		int nLen = szSendInfo.GetLength();
		HGLOBAL hGlobal = GlobalAlloc(GHND, sizeof(CPackage) + nLen);
		BYTE* pData = (BYTE*)GlobalLock(hGlobal);
		CPackage *pPackage = (CPackage*) pData;
		pPackage->m_Type = ptText;
		pPackage->m_dwContent = nLen;
		pPackage->m_dwSize = sizeof(CPackage);
		pPackage->m_dwData = nLen;
		BYTE* pTmp = pData;
		pTmp += sizeof(CPackage);
		memcpy(pTmp, szSendInfo, nLen);
		m_ClientSock.Send(pData, sizeof(CPackage) + nLen);

		GlobalUnlock(hGlobal);
		GlobalFree(hGlobal);
		m_SendContent.SetWindowText("");
		m_InfoList.SetSel(-1, 0);
		m_InfoList.ReplaceSel("客户端say: \n");
		m_InfoList.SetSel(-1, 0);
		m_InfoList.ReplaceSel(szSendInfo);
		m_InfoList.SetSel(-1, 0);
		m_InfoList.ReplaceSel("\n");
	}		
}
