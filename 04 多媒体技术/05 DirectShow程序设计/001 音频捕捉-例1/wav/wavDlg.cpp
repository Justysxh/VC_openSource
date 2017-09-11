// wavDlg.cpp : implementation file
//

#include "stdafx.h"
#include "wav.h"
#include "wavDlg.h"
#include <atlbase.h>
#include <windows.h>
#include <dshow.h>
#include "objbase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
static const GUID CLSID_WavDest =
{ 0x3c78b8e2, 0x6c4d, 0x11d1, { 0xad, 0xe2, 0x0, 0x0, 0xf8, 0x75, 0x4b, 0x99 } };

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
// CWavDlg dialog

CWavDlg::CWavDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWavDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWavDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_IsRecorded = FALSE;
	m_IsPause = FALSE;
}

void CWavDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWavDlg)
	DDX_Control(pDX, IDOK2, m_Pause);
	DDX_Control(pDX, IDC_EDIT1, m_WavFile);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWavDlg, CDialog)
	//{{AFX_MSG_MAP(CWavDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTBROWN, OnButbrown)
	ON_BN_CLICKED(IDOK2, OnOk2)
	ON_BN_CLICKED(IDOK3, OnOk3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWavDlg message handlers

BOOL CWavDlg::OnInitDialog()
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

void CWavDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWavDlg::OnPaint() 
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
HCURSOR CWavDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWavDlg::OnOK() 
{
	CString str ;
	m_WavFile.GetWindowText(str);
	if (str.IsEmpty())
	{
		MessageBox("请选择或输入文件");
		return;
	}

	ICaptureGraphBuilder2 * pBuilder = NULL;

	pGraph = NULL;

	pMediaControl = NULL;

	CoCreateInstance(CLSID_CaptureGraphBuilder2,0,CLSCTX_INPROC_SERVER,IID_ICaptureGraphBuilder2,(void**)&pBuilder);

	CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, 
                        IID_IGraphBuilder, (void **)&pGraph);

	pBuilder->SetFiltergraph(pGraph);



	pGraph->QueryInterface(IID_IMediaControl,(void**)&pMediaControl);

	ICreateDevEnum *pDevEnum = NULL;
	CoCreateInstance(CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC, 
		IID_ICreateDevEnum, (void **)&pDevEnum);


	IEnumMoniker *pClassEnum = NULL;
	pDevEnum->CreateClassEnumerator(CLSID_AudioInputDeviceCategory, &pClassEnum, 0);
	ULONG cFetched;
	if (pClassEnum->Next(1, &pMoniker, &cFetched) == S_OK)     
	{
		pMoniker->BindToObject(0, 0, IID_IBaseFilter, (void**)&pSrc);
		pMoniker->Release();      
	}
	pClassEnum->Release();

	
	CoCreateInstance(CLSID_WavDest, NULL, CLSCTX_ALL, 
                        IID_IBaseFilter, (void **)&pWaveDest);

	CoCreateInstance(CLSID_FileWriter, NULL, CLSCTX_ALL, 
                        IID_IBaseFilter, (void **)&pWriter);


	pGraph->AddFilter(pSrc,L"Wav");

	pGraph->AddFilter(pWaveDest,L"WavDest");

	

	pGraph->AddFilter(pWriter,L"FileWriter");

	pWriter->QueryInterface(IID_IFileSinkFilter2,(void**)&pSink);



	pSink->SetFileName(str.AllocSysString(),NULL);

	IPin* pOutpin = FindPin(pSrc,PINDIR_OUTPUT);

	IPin* pInpin,*pOut;	
	
	pOut= FindPin(pWaveDest,PINDIR_OUTPUT);


	AM_MEDIA_TYPE type;
	type.majortype = MEDIATYPE_Stream;
	type.subtype =MEDIASUBTYPE_WAVE;
	type.formattype = FORMAT_None;
	type.bFixedSizeSamples = FALSE;
	type.bTemporalCompression = FALSE;
	type.pUnk = NULL;


	pInpin = FindPin(pWaveDest,PINDIR_INPUT);

	IPin* pInpin1= FindPin(pWriter,PINDIR_INPUT);	

		HRESULT result ;
	result = pGraph->ConnectDirect(pOutpin,pInpin,NULL);

	result = pGraph->ConnectDirect(pOut,pInpin1,NULL);


	pMediaControl->Run();
	m_IsRecorded = TRUE;
}

IPin* CWavDlg::FindPin(IBaseFilter *pFilter, PIN_DIRECTION dir)
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

void CWavDlg::OnCancel() 
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

//选择Wav文件
void CWavDlg::OnButbrown() 
{
	CFileDialog FileDlg(TRUE,"WAV",NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"声音文件|*.wav|",this);
	if (FileDlg.DoModal()==IDOK)
	{
		CString str;
		str = FileDlg.GetPathName();
		m_WavFile.SetWindowText(str);
	}
}

void CWavDlg::OnOk2() 
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

void CWavDlg::OnOk3() 
{
	if (m_IsRecorded)
	{
		pMediaControl->Stop();
	}
}
