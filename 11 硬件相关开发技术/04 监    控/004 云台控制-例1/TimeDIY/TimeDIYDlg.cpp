// TimeDIYDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TimeDIY.h"
#include "TimeDIYDlg.h"
#include "CtrlFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
void CALLBACK CapCallBack(DWORD dwCard, BYTE *pbuff,DWORD dwSize)
{

//	BOOL ret = MTAWriteVideo(dwCard,pbuff,dwSize,TRUE);

//	AfxMessageBox("www",0,0);
	//设备的YUY2数据处理(注意：之前要注册回调函数)
//	g_pDev[dwCard].dwRealFrameRate++;
	
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
// CTimeDIYDlg dialog

CTimeDIYDlg::CTimeDIYDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTimeDIYDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTimeDIYDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CTimeDIYDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTimeDIYDlg)
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_Time);
	DDX_Control(pDX, IDC_PANEL, m_Panel);
	DDX_Control(pDX, IDC_MSCOMM, m_Com);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTimeDIYDlg, CDialog)
	//{{AFX_MSG_MAP(CTimeDIYDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_WINDOWPOSCHANGED()
	ON_BN_CLICKED(IDC_STARTTAIL, OnStartTail)
	ON_BN_CLICKED(IDC_STOPTAIL, OnStopTail)
	ON_BN_CLICKED(IDC_CloudMsg, OnCloudMsg)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_QUIT, OnQuit)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_BN_CLICKED(IDC_DOWN, OnDown)
	ON_BN_CLICKED(IDC_LEFT, OnLeft)
	ON_BN_CLICKED(IDC_RIGHT, OnRight)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimeDIYDlg message handlers

BOOL CTimeDIYDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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

	SetIcon(m_hIcon, TRUE);		
	SetIcon(m_hIcon, FALSE);	

	CTime time = CTime::GetCurrentTime();
	m_Time.SetTime(&time);

	m_Len = GetPrivateProfileInt("使用字节数","字节数",8,"./stage.ini");
	m_ActoinCount = GetPrivateProfileInt("控制项","控制数",13,"./stage.ini");
	m_pData = new  unsigned char[m_ActoinCount][100];

	m_Port = GetPrivateProfileInt("端口设置","端口号",1,"./stage.ini");

	GetPrivateProfileString("端口设置","环境设置","9600,n,8,1",m_Setting.GetBuffer(0),MAX_PATH,"./stage.ini");

	int data;
	char buff[20] = {0};
	char var[20] = {0};


	for (int i = 0 ; i<m_ActoinCount ; i++)
		for (int j = 0 ; j <m_Len; j++)
	{
		char section[20] = "字节";
		itoa(i+1,var,10);
		itoa(j+1,buff,10);
		strcat(section,buff);
		data = GetPrivateProfileInt(var,section,0,"./stage.ini");
		m_pData[i][j] = data;
	}

	//设置端口信息,并打开端口
	m_Com.SetSettings(m_Setting);
	m_Com.SetOutBufferSize(512);
	m_Com.SetCommPort(m_Port);
	m_Com.SetSThreshold(0);
	m_Com.SetPortOpen(TRUE);
	
	if (VCAInitSdk(m_hWnd))
	{
	
		VCARegVidCapCallBack(0,CapCallBack);
		VCAOpenDevice(0,m_Panel.m_hWnd);
		VCAStartVideoPreview(0);	

	}	
	m_Tail = FALSE;
	
	SetTimer(1,300,NULL);
	return TRUE;  
}

void CTimeDIYDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTimeDIYDlg::OnPaint() 
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

	CRect rc;
	m_Panel.GetClientRect(rc);
	CBrush brush (RGB(255,0,255));
	CDC* pDC = m_Panel.GetDC();
	pDC->FillRect(rc,&brush);

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTimeDIYDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTimeDIYDlg::OnOK() 
{

}

void CTimeDIYDlg::OnCancel() 
{
	delete [] m_pData;
	VCACloseDevice(0);
	VCAUnInitSdk();	
	OnStopTail(); 
	CDialog::OnCancel();
}

void CTimeDIYDlg::OnWindowPosChanged(WINDOWPOS FAR* lpwndpos) 
{
	CDialog::OnWindowPosChanged(lpwndpos);
	
	VCAUpdateOverlayWnd(m_Panel.m_hWnd);
	VCAUpdateVideoPreview(0,m_Panel.m_hWnd);	
}

DWORD WINAPI ThreadProc(LPVOID lpParameter )
{
	CTimeDIYDlg* pDlg = (CTimeDIYDlg*)lpParameter;
	while (true) 
	{
		//进行云台控制
		VARIANT vt;
		SAFEARRAY* pSafe;
		SAFEARRAYBOUND band;
		band.cElements =pDlg->m_Len;
		band.lLbound = 0;
		pSafe = SafeArrayCreate(VT_UI1,1,&band);

		//向上
		for (long i = 0; i<pDlg->m_Len; i++)
		{
			SafeArrayPutElement(pSafe,&i,(void*)&pDlg->m_pData[0][i]);
		}
		vt.vt= VT_ARRAY |VT_UI1;
		vt.parray = pSafe;
		pDlg->m_Com.SetOutput((COleVariant)vt);

		Sleep(15000);

		//向左
		vt.vt= VT_ARRAY |VT_UI1;
		vt.parray = pSafe;
		for ( i = 0; i<pDlg->m_Len; i++)
		{
			SafeArrayPutElement(pSafe,&i,(void*)&pDlg->m_pData[2][i]);
		}
		pDlg->m_Com.SetOutput((COleVariant)vt);

		vt.vt= VT_ARRAY |VT_UI1;
		vt.parray = pSafe;
		for ( i = 0; i<pDlg->m_Len; i++)
		{
			SafeArrayPutElement(pSafe,&i,(void*)&pDlg->m_pData[1][i]);
		}
		Sleep(15000);
		//向下
		pDlg->m_Com.SetOutput((COleVariant)vt);

		//向右
		Sleep(15000);
		vt.vt= VT_ARRAY |VT_UI1;
		vt.parray = pSafe;
		for ( i = 0; i<pDlg->m_Len; i++)
		{
			SafeArrayPutElement(pSafe,&i,(void*)&pDlg->m_pData[3][i]);
		}
		pDlg->m_Com.SetOutput((COleVariant)vt);
		Sleep(15000);
	}
	return 0;
}

void CTimeDIYDlg::OnStartTail() 
{
	m_Tail = TRUE;
	//开始监控
	VCAStartVideoCapture(0,CAP_MPEG4_STREAM,MPEG4_AVIFILE_ONLY ,"C:\\WW.avi");

	DWORD threadID;
	m_hThread = ::CreateThread(NULL,0,ThreadProc,(LPVOID)this,0,&threadID);
}

void CTimeDIYDlg::OnStopTail() 
{
	if (m_Tail==TRUE)
	{
		//停止运动
		VARIANT vt;
		SAFEARRAY* pSafe;
		SAFEARRAYBOUND band;
		band.cElements =m_Len;
		band.lLbound = 0;
		pSafe = SafeArrayCreate(VT_UI1,1,&band);

		for (long i = 0; i<m_Len; i++)
		{
			SafeArrayPutElement(pSafe,&i,(void*)&m_pData[12][i]);
		}
		vt.vt= VT_ARRAY |VT_UI1;
		vt.parray = pSafe;
		m_Com.SetOutput((COleVariant)vt);


		::TerminateThread(m_hThread,0);
		//停止监控
		VCAStopVideoCapture(0);
		m_Tail = FALSE;
	}
}

void CTimeDIYDlg::OnCloudMsg() 
{
	CCtrlFrm ctrFrm;
	ctrFrm.DoModal();
}

void CTimeDIYDlg::OnTimer(UINT nIDEvent) 
{
	CTime time= CTime::GetCurrentTime();
	
	CTime strtime;
	m_Time.GetTime(strtime);

	if (time==strtime)
	{
		OnStartTail() ;
		KillTimer(1);
	}

	CDialog::OnTimer(nIDEvent);
}

void CTimeDIYDlg::OnQuit() 
{
	OnCancel() ;	
}

void CTimeDIYDlg::OnUp() 
{
	//进行云台控制
	VARIANT vt;
	SAFEARRAY* pSafe;
	SAFEARRAYBOUND band;
	band.cElements =m_Len;
	band.lLbound = 0;
	pSafe = SafeArrayCreate(VT_UI1,1,&band);

	//向上
	for (long i = 0; i<m_Len; i++)
	{
		SafeArrayPutElement(pSafe,&i,(void*)&m_pData[0][i]);
	}
	vt.vt= VT_ARRAY |VT_UI1;
	vt.parray = pSafe;
	m_Com.SetOutput((COleVariant)vt);

	Sleep(300);
	//停止
	for ( i = 0; i<m_Len; i++)
	{
		SafeArrayPutElement(pSafe,&i,(void*)&m_pData[12][i]);
	}
	vt.vt= VT_ARRAY |VT_UI1;
	vt.parray = pSafe;
	m_Com.SetOutput((COleVariant)vt);
			
}

void CTimeDIYDlg::OnDown() 
{
	//进行云台控制
	VARIANT vt;
	SAFEARRAY* pSafe;
	SAFEARRAYBOUND band;
	band.cElements =m_Len;
	band.lLbound = 0;
	pSafe = SafeArrayCreate(VT_UI1,1,&band);

	//向下
	for (long i = 0; i<m_Len; i++)
	{
		SafeArrayPutElement(pSafe,&i,(void*)&m_pData[1][i]);
	}
	vt.vt= VT_ARRAY |VT_UI1;
	vt.parray = pSafe;
	m_Com.SetOutput((COleVariant)vt);

	Sleep(300);

	//停止
	for (i = 0; i<m_Len; i++)
	{
		SafeArrayPutElement(pSafe,&i,(void*)&m_pData[12][i]);
	}
	vt.vt= VT_ARRAY |VT_UI1;
	vt.parray = pSafe;
	m_Com.SetOutput((COleVariant)vt)	;
}

void CTimeDIYDlg::OnLeft() 
{
	//进行云台控制
	VARIANT vt;
	SAFEARRAY* pSafe;
	SAFEARRAYBOUND band;
	band.cElements =m_Len;
	band.lLbound = 0;
	pSafe = SafeArrayCreate(VT_UI1,1,&band);

	//向左
	for (long i = 0; i<m_Len; i++)
	{
		SafeArrayPutElement(pSafe,&i,(void*)&m_pData[2][i]);
	}
	vt.vt= VT_ARRAY |VT_UI1;
	vt.parray = pSafe;
	m_Com.SetOutput((COleVariant)vt);

	Sleep(300);	
	//停止
	for (i = 0; i<m_Len; i++)
	{
		SafeArrayPutElement(pSafe,&i,(void*)&m_pData[12][i]);
	}
	vt.vt= VT_ARRAY |VT_UI1;
	vt.parray = pSafe;
	m_Com.SetOutput((COleVariant)vt);	
}

void CTimeDIYDlg::OnRight() 
{
	//进行云台控制
	VARIANT vt;
	SAFEARRAY* pSafe;
	SAFEARRAYBOUND band;
	band.cElements =m_Len;
	band.lLbound = 0;
	pSafe = SafeArrayCreate(VT_UI1,1,&band);

	//向右
	for (long i = 0; i<m_Len; i++)
	{
		SafeArrayPutElement(pSafe,&i,(void*)&m_pData[3][i]);
	}
	vt.vt= VT_ARRAY |VT_UI1;
	vt.parray = pSafe;
	m_Com.SetOutput((COleVariant)vt);

	Sleep(300);
	//停止
	for (i = 0; i<m_Len; i++)
	{
		SafeArrayPutElement(pSafe,&i,(void*)&m_pData[12][i]);
	}
	vt.vt= VT_ARRAY |VT_UI1;
	vt.parray = pSafe;
	m_Com.SetOutput((COleVariant)vt);	
}
