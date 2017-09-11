// FetchVisualDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FetchVisual.h"
#include "FetchVisualDlg.h"
//#include <atlbase.h>
#include <windows.h>
#include <dshow.h>
#include "objbase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// e436ebb1-524f-11ce-9f53-0020af0ba770            Reference clock
//OUR_GUID_ENTRY(CLSID_SystemClock,
//0xe436ebb1, 0x524f, 0x11ce, 0x9f, 0x53, 0x00, 0x20, 0xaf, 0x0b, 0xa7, 0x70)
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
static const GUID CLSID_AviMux =
{ 0xe2510970, 0xf137, 0x11ce, { 0x8b, 0x67,0x00, 0xaa, 0x00, 0xa3, 0xf1,0xa6 } };


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
// CFetchVisualDlg dialog

CFetchVisualDlg::CFetchVisualDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFetchVisualDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFetchVisualDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_IsRecorded = FALSE;
	m_IsPause = FALSE;
}

void CFetchVisualDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFetchVisualDlg)
	DDX_Control(pDX, IDC_BUTTON3, m_Pause);
	DDX_Control(pDX, IDC_EDIT1, m_File);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFetchVisualDlg, CDialog)
	//{{AFX_MSG_MAP(CFetchVisualDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFetchVisualDlg message handlers

BOOL CFetchVisualDlg::OnInitDialog()
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

void CFetchVisualDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFetchVisualDlg::OnPaint() 
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
HCURSOR CFetchVisualDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFetchVisualDlg::OnOK() 
{
	CString str;
	m_File.GetWindowText(str);
	if (str.IsEmpty())
	{
		MessageBox("请选择或输入文件");
		return;
	}

	ICaptureGraphBuilder2 * pBuilder = NULL;

	pGraph = NULL;

	pMediaControl = NULL;

	/***********************列举视频设备**************************/
	ICreateDevEnum *pDevEnum = NULL;

	CoCreateInstance(CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC, 
		IID_ICreateDevEnum, (void **)&pDevEnum);

	IEnumMoniker *pClassEnum = NULL;

	pDevEnum->CreateClassEnumerator(CLSID_VideoInputDeviceCategory, &pClassEnum, 0);
	ULONG cFetched;
	if (pClassEnum->Next(1, &pMoniker, &cFetched) == S_OK)     
	{
		// Bind the first moniker to a filter object.
		pMoniker->BindToObject(0, 0, IID_IBaseFilter, (void**)&pSrc);
		pMoniker->Release();      
	}
	pClassEnum->Release();
	/***********************列举视频设备**************************/

	
	/**************************创建过滤器*************************/

	CoCreateInstance(CLSID_CaptureGraphBuilder2,0,CLSCTX_INPROC_SERVER,IID_ICaptureGraphBuilder2,(void**)&pBuilder);

	CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, 
                        IID_IGraphBuilder, (void **)&pGraph);

	pBuilder->SetFiltergraph(pGraph);

	pGraph->QueryInterface(IID_IMediaControl,(void**)&pMediaControl);

	pGraph->AddFilter(pSrc,L"avi");



	CoCreateInstance(CLSID_AviDest,NULL, CLSCTX_ALL, 
                       IID_IBaseFilter,(void**)&pMux);
	pGraph->AddFilter(pMux,L"Mux");
	

	CoCreateInstance(CLSID_FileWriter, NULL, CLSCTX_ALL, 
                        IID_IBaseFilter, (void **)&pWriter);
	pGraph->AddFilter(pWriter,L"Writer");


	pWriter->QueryInterface(IID_IFileSinkFilter2,(void**)&pSink);
	
	pSink->SetFileName(str.AllocSysString(),NULL);

	/**************************创建过滤器*************************/

	/**************************连接端子***************************/

	IPin* pOutpin = FindPin(pSrc,PINDIR_OUTPUT); //pSrc的输出端子
		
	IPin* pInpin,*pOut;	//pMux的输入\输出端子

	pInpin = FindPin(pMux,PINDIR_INPUT);
	
	pOut= FindPin(pMux,PINDIR_OUTPUT);

	IPin* pInpin1= FindPin(pWriter,PINDIR_INPUT);//pWriter的输入端子	

	//连接端子
	HRESULT result ;
	result = pGraph->ConnectDirect(pOutpin,pInpin,NULL);
	result = pGraph->ConnectDirect(pOut,pInpin1,NULL);

	pMediaControl->Run();
	m_IsRecorded = TRUE;
	/**************************连接端子***************************/
}

IPin* CFetchVisualDlg::FindPin(IBaseFilter *pFilter, PIN_DIRECTION dir)
{
	IEnumPins* pEnumPins;
	IPin* pOutpin;
	PIN_DIRECTION pDir;
	pFilter->EnumPins(&pEnumPins);

	while (pEnumPins->Next(1,&pOutpin,NULL)==S_OK)
	{
		pOutpin->QueryDirection(&pDir);
		if (pDir==dir)
		{
			return pOutpin;
		}
	}
	return 0;
}

void CFetchVisualDlg::OnButton1() 
{
	if (m_IsRecorded)
	{
		pMediaControl->Stop();
	}
}

void CFetchVisualDlg::OnButton2() 
{
	CFileDialog FileDlg(TRUE,"WAV",NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"视频文件|*.avi|",this);
	if (FileDlg.DoModal()==IDOK)
	{
		CString str;
		str = FileDlg.GetPathName();
		m_File.SetWindowText(str);
	}	
}

void CFetchVisualDlg::OnButton3() 
{
	if (m_IsRecorded)
	{
		if (!m_IsPause)
		{
			pMediaControl->Pause();
			m_Pause.SetWindowText("继续");
			m_IsPause = TRUE;
		}
		else
		{
			pMediaControl->Run();
			m_Pause.SetWindowText("暂停");
			m_IsPause = FALSE;
		}
	}	
}

void CFetchVisualDlg::OnButton4() 
{
	if (m_IsRecorded)
	{
		pMediaControl->Stop();
		pMediaControl->Release();
		pGraph->Release();
		CoUninitialize();
	}
	CDialog::OnCancel();		
}
