// ServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

LRESULT WINAPI EncodeCallback(HWND hWnd, LPVIDEOHDR lpVHdr)
{
	if (lpVHdr->dwFlags&VHDR_DONE)
	{
		static BOOL bSend = TRUE;
		CServerDlg* pDlg = (CServerDlg*)AfxGetMainWnd();
		int nState = pDlg->m_Video.GetCheck();
		if (nState == 1)
		{
			if (pDlg->m_bSendImage==FALSE)
			{
				//获取图象数据
				BITMAPINFO bmpInfo;
				capGetVideoFormat(pDlg->m_hWndVideo, &bmpInfo, sizeof(BITMAPINFO));
				//确定图象数据大小
				int nSize = bmpInfo.bmiHeader.biSizeImage;
				bSend = FALSE;
				HGLOBAL hGlobal = GlobalAlloc(GHND, nSize + sizeof(BITMAPINFOHEADER));
				BYTE* pData = (BYTE*)GlobalLock(hGlobal);
				memcpy(pData, &bmpInfo.bmiHeader, sizeof(BITMAPINFOHEADER));

				BYTE* pTmp = pData;
				pTmp += sizeof(BITMAPINFOHEADER);
				memcpy(pTmp, lpVHdr->lpData, nSize);

				int nPackSize = sizeof(CPackage) + nSize + sizeof(BITMAPINFOHEADER);
				
				if (pDlg->m_hGlobal != NULL)
				{
					GlobalFree(pDlg->m_hGlobal);
					pDlg->m_hGlobal = NULL;
				}

				pDlg->m_hGlobal = GlobalAlloc(GHND, nPackSize);

				BYTE* pSendData = (BYTE*)GlobalLock(pDlg->m_hGlobal);
				CPackage* pPackage = (CPackage*)pSendData;
				pPackage->m_Type = ptImage;
				pPackage->m_dwContent = nSize + sizeof(BITMAPINFOHEADER);
				pPackage->m_dwData = nSize + sizeof(BITMAPINFOHEADER);
				pPackage->m_dwSize = sizeof(CPackage);
				pTmp = pSendData;
				pTmp += sizeof(CPackage);
				memcpy(pTmp, pData, nSize + sizeof(BITMAPINFOHEADER));

				GlobalUnlock(hGlobal);
				GlobalFree(hGlobal);
				GlobalUnlock(pDlg->m_hGlobal);
			
				pDlg->m_bSendImage = TRUE;
			}
		}
	}
 	return 1;
}


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
// CServerDlg dialog

CServerDlg::CServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CServerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
	m_hGlobal = NULL;
}

void CServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CServerDlg)
	DDX_Control(pDX, IDC_INFOLIST, m_InfoList);
	DDX_Control(pDX, IDC_PANEL, m_Panel);
	DDX_Control(pDX, IDC_VIDEO, m_Video);
	DDX_Control(pDX, IDC_SENDCONTENT, m_SendInfo);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CServerDlg, CDialog)
	//{{AFX_MSG_MAP(CServerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SEND, OnSend)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerDlg message handlers

BOOL CServerDlg::OnInitDialog()
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
	
	m_ServerSock.SetDlg(this);
	m_ClientSock.SetDlg(this);
	// TODO: Add extra initialization here
	
	m_ServerSock.Create(845);
	m_ServerSock.Listen();



	m_hWndVideo = capCreateCaptureWindow(NULL,WS_POPUP, 1, 1, 10, 10, m_hWnd, 0);
	if (capDriverConnect(m_hWndVideo, 0))
	{
		::SetParent(m_hWndVideo,*this);
		::SetWindowLong(m_hWndVideo,GWL_STYLE,WS_CHILD);

		CRect wndRC;
		m_Panel.GetClientRect(wndRC);
		m_Panel.MapWindowPoints(this,wndRC);
		wndRC.DeflateRect(1,1,1,1);

		::SetWindowPos(m_hWndVideo,NULL,wndRC.left,wndRC.top,wndRC.Width(),wndRC.Height(),SWP_NOZORDER);
		::ShowWindow(m_hWndVideo,SW_SHOW);

		CAPDRIVERCAPS caps;
		capDriverGetCaps(m_hWndVideo,sizeof(caps),&caps);

		if (caps.fHasOverlay)
			capOverlay(m_hWndVideo,TRUE);

		CAPTUREPARMS params;
		capCaptureGetSetup(m_hWndVideo,&params,sizeof(params));

		params.fYield           = TRUE;
		params.fAbortLeftMouse  = FALSE;
		params.fAbortRightMouse = FALSE;
		params.fLimitEnabled    = FALSE;
		params.vKeyAbort        = FALSE;
		params.fCaptureAudio    = FALSE;
		
		capCaptureSetSetup(m_hWndVideo,&params, sizeof(params));
		capSetCallbackOnVideoStream(m_hWndVideo, EncodeCallback);

		capPreviewRate(m_hWndVideo,30);
		capPreview(m_hWndVideo, TRUE);
		capCaptureSequenceNoFile(m_hWndVideo);
	
		m_bSendImage = FALSE;
	}
	SetTimer(1, 200, NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CServerDlg::OnPaint() 
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
HCURSOR CServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CServerDlg::OnOK() 
{


}

void CServerDlg::AcceptConnect()
{
	m_ClientSock.ShutDown();
	m_ClientSock.Close();
	m_ServerSock.Accept(m_ClientSock);
}

void CServerDlg::OnSend() 
{
	CString szSendInfo;
	m_SendInfo.GetWindowText(szSendInfo);
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
		m_SendInfo.SetWindowText("");
		m_InfoList.SetSel(-1, 0);
		m_InfoList.ReplaceSel("服务器say: \n");
		m_InfoList.SetSel(-1, 0);
		m_InfoList.ReplaceSel(szSendInfo);
		m_InfoList.SetSel(-1, 0);
		m_InfoList.ReplaceSel("\n");


	}
}

void CServerDlg::OnCancel()
{
	//终止回调函数
	capSetCallbackOnVideoStream(m_hWndVideo,NULL);
	//停止捕捉
	capCaptureStop(m_hWndVideo);
	//断开驱动程序连接
	capDriverDisconnect(m_hWndVideo);
	if (m_hGlobal != NULL)
	{
		GlobalFree(m_hGlobal);
		m_hGlobal = NULL;
	}
	CDialog::OnCancel();
}

void CServerDlg::OnTimer(UINT nIDEvent) 
{
	if (m_bSendImage)
	{
		if (m_hGlobal != NULL)
		{
			int nSize = GlobalSize(m_hGlobal);
			BYTE* pData = (BYTE*)GlobalLock(m_hGlobal);
			m_ClientSock.Send(pData, nSize);	
			m_bSendImage = FALSE;
			GlobalUnlock(m_hGlobal);
		}
	}
	CDialog::OnTimer(nIDEvent);
}

//接收数据
void CServerDlg::ReceiveData()
{
	static int nSize = sizeof(CPackage) + 1024;
	HGLOBAL hGlobal = GlobalAlloc(GHND, nSize);
	BYTE* pBuffer = (BYTE*)GlobalLock(hGlobal);

	int nFact = m_ClientSock.Receive(pBuffer, nSize);
	if (nFact > 0)
	{
		CPackage* pPackage = (CPackage*)pBuffer;
		int nDataLen = pPackage->m_dwContent;
		if (pPackage->m_Type==ptText)
		{
			char* pszData = (char*)pBuffer;
			pszData += sizeof(CPackage);
			m_InfoList.SetSel(-1, 0);
			m_InfoList.ReplaceSel("客户端say: \n");
			m_InfoList.SetSel(-1, 0);
			m_InfoList.ReplaceSel(pszData);	
			m_InfoList.SetSel(-1, 0);
			m_InfoList.ReplaceSel("\n");				
		}	
	}
	GlobalUnlock(hGlobal);
	GlobalFree(hGlobal);
}
