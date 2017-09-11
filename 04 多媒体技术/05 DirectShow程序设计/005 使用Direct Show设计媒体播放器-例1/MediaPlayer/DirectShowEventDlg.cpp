// DirectShowEventDlg.cpp : implementation file
//
#include "stdafx.h"
#include "MediaPlayer.h"
#include "DirectShowEventDlg.h"
#include "VideoSet.h"
#include <dshow.h>
#include "Mpconfig.h"

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
// CDirectShowEventDlg dialog
DWORD WINAPI ThreadProc(LPVOID lpParameter )
{
	CDirectShowEventDlg* pWnd = (CDirectShowEventDlg*)lpParameter;
	HANDLE  hEvent;
	pWnd->pEvent->GetEventHandle( (OAEVENT*) &hEvent);
	
	long code,p1,p2;
	BOOL  done = FALSE;
	while (!done)
	{
		pWnd->SendMessage(CM_POSCHANGE);
		
		if (WaitForSingleObject(hEvent,80)==WAIT_OBJECT_0)
		{
			while (SUCCEEDED( pWnd->pEvent->GetEvent(&code,&p1,&p2,0)))
			{
				pWnd->pEvent->FreeEventParams(code,p1,p2);
				if (code==EC_COMPLETE)
				{
					pWnd->m_Completed = TRUE;
					pWnd->SendMessage(CM_COMPLETE);
					done=true;
				}
			}
		}
	}
	return 0 ;
}

CDirectShowEventDlg::CDirectShowEventDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDirectShowEventDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDirectShowEventDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);

	m_bFullScreen = FALSE;
	pViewWnd = NULL;
	pBaseVideo = NULL;
	pBase = NULL;


	m_lVolumn = 0;
	m_bMute = FALSE;
	m_bSpeed = FALSE;
	m_bBack= FALSE;
	m_bGrayImage = FALSE;
	m_fSaturation = m_fBright = m_fContrast = m_fHue = 1;
	pRender = NULL;
	pMediaControl = NULL;
	m_bStop = m_bPause = FALSE;
	pGraph = NULL;
	m_hThread = NULL;
	m_bViewPlay = FALSE;
	m_bInvalidFile = FALSE;
	m_Completed = TRUE;
	pEvent = NULL;

}

void CDirectShowEventDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDirectShowEventDlg)
	DDX_Control(pDX, IDC_CTLLIST, m_CtlList);
	DDX_Control(pDX, IDC_GROUPPOS, m_GroupPos);
	DDX_Control(pDX, IDC_CURPOS, m_CurPos);
	DDX_Control(pDX, IDC_PROCESS, m_Progress);
	DDX_Control(pDX, IDC_TB_STOP, m_Stop);
	DDX_Control(pDX, IDC_TB_PAUSE, m_Pause);
	DDX_Control(pDX, IDC_GRAY, m_GrayBtn);
	DDX_Control(pDX, IDC_PROCESSCTRL, m_ProgressCtrl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDirectShowEventDlg, CDialog)
	//{{AFX_MSG_MAP(CDirectShowEventDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SETFILE, OnSetFile)
	ON_BN_CLICKED(IDC_SNAP, OnSnap)
	ON_BN_CLICKED(IDC_FULLSCREEN, OnFullScreen)
	ON_BN_CLICKED(IDC_MUTE, OnMute)
	ON_BN_CLICKED(IDC_VOLUMNMAX, OnVolumnmax)
	ON_BN_CLICKED(IDC_VOLUMNMIN, OnVolumnmin)
	ON_BN_CLICKED(IDC_ADDSPEED, OnAddSpeed)
	ON_BN_CLICKED(IDC_ADDBACK, OnAddBack)
	ON_BN_CLICKED(IDC_GRAY, OnGray)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_VIDEOSET, OnVideoset)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_TB_PAUSE, OnTbPause)
	ON_BN_CLICKED(IDC_TB_STOP, OnTbStop)
	ON_BN_CLICKED(IDC_SHOWWND, OnShowwnd)
	ON_MESSAGE(CM_COMPLETE,Done)

	//}}AFX_MSG_MAP
	ON_MESSAGE(CM_POSCHANGE,OnPosChange)

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDirectShowEventDlg message handlers
DWORD WINAPI PlayVideoFile(LPVOID lpParameter )
{
	CDirectShowEventDlg* pWnd = (CDirectShowEventDlg*)lpParameter;
	CString strFile= pWnd->m_FileName;
	HRESULT hRet = pWnd->pGraph->RenderFile(strFile.AllocSysString(),NULL);	
	if(hRet!=S_OK)
	{
		pWnd->m_bInvalidFile = TRUE;	//非法的文件
		return 1;
	}
	//获取VideoRender filter
	pWnd->pBase == NULL;
	IBaseFilter *pRenderFiler = NULL;
	pWnd->pGraph->FindFilterByName(L"Video Renderer",(IBaseFilter**)&pRenderFiler);
	if (pRenderFiler!=NULL)	//包含视频信息
	{	

		pWnd->m_bViewPlay = TRUE;
		IPin* pVideoIn = NULL;
		pVideoIn  = pWnd->FindPin(pRenderFiler,PINDIR_INPUT);
		if (pVideoIn)
		{
			pVideoIn->Disconnect();
		}
		
		pWnd->pGraph->RemoveFilter(pRenderFiler);
		pWnd->pGraph->AddFilter(pWnd->pRender,L"Render");
		//获取视频解码器
		pWnd->pGraph->FindFilterByName(L"MPEG Video Decoder",(IBaseFilter**)&pWnd->pBase);
	
		if (pWnd->pBase)
		{
			IPin* pOutPin = NULL;
			//获取视频解码的输出引脚
			pOutPin = pWnd->FindPin(pWnd->pBase,PINDIR_OUTPUT);
			if (pOutPin != NULL)
			{

				IPin* pColorIn = NULL;
				IPin* pColorOut = NULL;
					
				//获取输入和输出引脚
				IPin *pTextIn = NULL;
				IPin *pTextOut = NULL;

				IPin *pRenderIn = NULL;
				pRenderIn = pWnd->FindPin(pWnd->pRender,PINDIR_INPUT);

					HRESULT hRet = 0;
					hRet = pOutPin->Disconnect();
				
					hRet = pWnd->pGraph->ConnectDirect(pOutPin,pRenderIn,NULL);
			}
		}
	}
	else
	{
		pWnd->m_bViewPlay = FALSE;	//没有视频信息
	}
	pWnd->m_ThreadStop = TRUE;
	return 0 ;
}


BOOL CDirectShowEventDlg::OnInitDialog()
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
	
	m_Completed = FALSE;
	m_Previewed = FALSE;
	m_hThread   = NULL;

	m_DisplayWnd.Create(IDD_DISPLAYWND_DIALOG);
	m_DisplayWnd.GetWindowRect(m_OriginRC);

	SetTimer(1,100,NULL);
	return TRUE; 
}


void CDirectShowEventDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDirectShowEventDlg::OnPaint() 
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
HCURSOR CDirectShowEventDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDirectShowEventDlg::OnOK() 
{

}



void CDirectShowEventDlg::OnSetFile() 
{
	CFileDialog fDlg(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"avi文件|*.avi;*.dat;*.mp3;*.wav;*.mpeg|所有文件|*.*||",this);
	if (fDlg.DoModal()==IDOK)
	{
		m_FileName = fDlg.GetPathName();
		m_Stop.SendMessage(WM_LBUTTONDOWN,0,0);
		PlayFile(m_FileName);
	}
}

void CDirectShowEventDlg::OnCancel()
{
	OnTbStop() ;
	m_DisplayWnd.DestroyWindow();
	CDialog::OnCancel();

}

void CDirectShowEventDlg::Done(WPARAM wParam, LPARAM lParam)
{
	if (m_hThread)
	{
		TerminateThread(m_hThread,0);
		m_hThread = NULL;
	}

	if (pMediaControl != NULL)
	{
		pMediaControl->Stop();
		m_bStop = TRUE;
		if (pViewWnd != NULL)
		{
			pViewWnd->put_Visible(FALSE);
		}
	}
	if (pMediaControl)
	{
		pMediaControl->Release();
			pMediaControl = NULL;
	}
	if (pGraph)
	{
		pGraph->Release();
		pGraph = NULL;
	}
	if (pEvent)
	{
		pEvent->Release();
		pEvent = NULL;
	}
	m_bFullScreen = FALSE;
	pViewWnd = NULL;
	pBaseVideo = NULL;
	pBase = NULL;
	m_bViewPlay = FALSE;
	m_lVolumn = 0;
	m_bMute = FALSE;
	m_bSpeed = FALSE;
	m_bBack= FALSE;
	m_bGrayImage = FALSE;
	m_fSaturation = m_fBright = m_fContrast = m_fHue = 1;
	pRender = NULL;

	m_bStop = m_bPause = FALSE;
	m_hThread = NULL;
	m_Stop.SetWindowText("停止");
	m_GrayBtn.SetWindowText("黑白图像");
	m_Pause.SetWindowText("暂停");	
	m_Progress.SetText("00:00:00");
	m_CurPos.SetText("00:00:00");
	m_ProgressCtrl.SetPos(0);

	//播放完成
	m_Previewed = FALSE;
	m_Completed = TRUE;
	m_DisplayWnd.ModifyStyle(WS_SIZEBOX,0);
	m_DisplayWnd.m_Panel.ModifyStyle(SS_BLACKRECT,SS_BITMAP);
	m_DisplayWnd.m_Panel.SetBitmap(m_DisplayWnd.bmp);
	m_DisplayWnd.SetWindowPos(NULL,0,0,m_OriginRC.Width(),m_OriginRC.Height(),SWP_NOMOVE);
}

void CDirectShowEventDlg::OnSnap() 
{
	CFileDialog flDlg(FALSE,"","Snap.bmp");
	if (pGraph != NULL)
	{
		IBasicVideo * pBasicVideo = NULL;
		pGraph->QueryInterface(IID_IBasicVideo, (void **)&pBasicVideo);
		if (pBasicVideo != NULL)
		{
			pMediaControl->Pause();
			if ( flDlg.DoModal()==IDOK)
			{
				CString csSaveName = flDlg.GetPathName();
				//获取图像大小，包含位图信息头
				long lBmpSize ;
				if (SUCCEEDED(pBasicVideo->GetCurrentImage(&lBmpSize, 0)))
				{
					//定义图像数据缓冲区，获取图像数据
					BYTE* pData = new BYTE[lBmpSize];
					if (SUCCEEDED(pBasicVideo->GetCurrentImage(&lBmpSize, (long*)pData)))
					{
						BITMAPFILEHEADER bFile;
						bFile.bfReserved1 = bFile.bfReserved2 = 0;
						bFile.bfSize = sizeof(BITMAPFILEHEADER);
						bFile.bfType = 0x4d42;
						bFile.bfOffBits = sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);
						CFile file;
						file.Open(csSaveName,CFile::modeCreate|CFile::modeReadWrite);
						file.Write(&bFile,sizeof(BITMAPFILEHEADER));
						file.WriteHuge(pData,lBmpSize);
						file.Close();
					}
					delete [] pData;
					pBasicVideo->Release();
				}
			}
			pMediaControl->Run();
		}
	}
}

void CDirectShowEventDlg::OnFullScreen() 
{
	if (pViewWnd!= NULL && m_bStop==FALSE)
	{
		pViewWnd->put_FullScreenMode(-1);
		m_bFullScreen = TRUE;
	}
}

BOOL CDirectShowEventDlg::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_ESCAPE)
		{
			if (pViewWnd!= NULL)
			{
				pMsg->wParam == 0;
				pViewWnd->put_FullScreenMode(0);
				m_bFullScreen = FALSE;
				return TRUE;
			}		
		}
	}	
	return CDialog::PreTranslateMessage(pMsg);
}

//查找引脚
IPin* CDirectShowEventDlg::FindPin(IBaseFilter *pFilter, PIN_DIRECTION dir)
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
}



void CDirectShowEventDlg::OnMute() 
{
	IBasicAudio* pAudio = NULL;
	if (pGraph != NULL)
	{
		pGraph->QueryInterface(IID_IBasicAudio,(void**)&pAudio);
		if (pAudio != NULL && m_bMute==FALSE)
		{
			pAudio->get_Volume(&m_lVolumn);
			pAudio->put_Volume(VOLUMN_CLIENCE);
			m_bMute=TRUE;
		}
		else if (pAudio != NULL && m_bMute==TRUE)
		{
			pAudio->put_Volume(m_lVolumn);
			m_bMute = FALSE;		
		}
	}
}

void CDirectShowEventDlg::OnVolumnmax() 
{
	IBasicAudio* pAudio = NULL;
	if (pGraph != NULL)
	{
		pGraph->QueryInterface(IID_IBasicAudio,(void**)&pAudio);
		if (pAudio != NULL)
		{
			pAudio->get_Volume(&m_lVolumn);
			if (m_lVolumn <0)
			{
				m_lVolumn += 200;
				pAudio->put_Volume(m_lVolumn);
			}
			else
			{
				m_lVolumn = 0;
			}
		}
	}
}

void CDirectShowEventDlg::OnVolumnmin() 
{
	IBasicAudio* pAudio = NULL;
	if (pGraph != NULL)
	{
		pGraph->QueryInterface(IID_IBasicAudio,(void**)&pAudio);
		if (pGraph != NULL)
		{
			if (pAudio != NULL)
			{
				pAudio->get_Volume(&m_lVolumn);
				if (m_lVolumn > VOLUMN_CLIENCE )
				{
					m_lVolumn -= 200;
					pAudio->put_Volume(m_lVolumn);
				}
				else
				{
					m_lVolumn = VOLUMN_CLIENCE;
				}
			}
		}
	}
}

//快进
void CDirectShowEventDlg::OnAddSpeed() 
{
	IMediaPosition* pPosition = NULL;
	if (pGraph != NULL)
	{
		pGraph->QueryInterface(IID_IMediaPosition,(void**)&pPosition);
		if (pPosition != NULL)
		{
			REFTIME curTime,endTime;
			pPosition->get_StopTime(&endTime);
				pPosition->get_CurrentPosition(&curTime);
			curTime += 5;
			if (curTime <=endTime)
			{
				pPosition->put_CurrentPosition(curTime);
			}
			else
			{
				pPosition->put_CurrentPosition(endTime);
			}
		}
	}
}

//快退
void CDirectShowEventDlg::OnAddBack() 
{
	IMediaPosition* pPosition = NULL;
	if (pGraph != NULL)
	{
		pGraph->QueryInterface(IID_IMediaPosition,(void**)&pPosition);
		if (pPosition != NULL )
		{
			REFTIME curTime;
			pPosition->get_CurrentPosition(&curTime);
			curTime -= 5;
			if (curTime >= 0)
			{
				pPosition->put_CurrentPosition(curTime);
			}
			else
			{
				pPosition->put_CurrentPosition(0);
			}
		}
	}
}

void CDirectShowEventDlg::OnGray() 
{
	IVMRMixerControl9 * pControl = NULL;
	if (pRender != NULL)
	{
		pRender->QueryInterface( IID_IVMRMixerControl9,(void**)&pControl);
		if (pControl != NULL )
		{
			VMR9ProcAmpControl vmrParam;
			memset(&vmrParam,0,sizeof(VMR9ProcAmpControl));
			vmrParam.dwSize = sizeof(VMR9ProcAmpControl);
			vmrParam.dwFlags = ProcAmpControl9_Saturation;

			//获取饱和度的最小值
			VMR9ProcAmpControlRange range;
			range.dwSize = sizeof(VMR9ProcAmpControlRange);
			range.dwProperty = ProcAmpControl9_Saturation;

			pControl->GetProcAmpControlRange(0, &range);
			//设置饱和度为最小值
			if (m_bGrayImage==FALSE)
			{
				VMR9ProcAmpControl getParam;
				memset(&getParam,0,sizeof(VMR9ProcAmpControl));
				getParam.dwSize = sizeof(VMR9ProcAmpControl);
				getParam.dwFlags = ProcAmpControl9_Saturation;
				pControl->GetProcAmpControl(0,&getParam);
				m_fSaturation = range.MinValue;
				vmrParam.Saturation = m_fSaturation;
				m_bGrayImage = TRUE;
				m_GrayBtn.SetWindowText("彩色图像");
			}
			else
			{
				m_fSaturation = 1;
				m_GrayBtn.SetWindowText("黑白图像");
				vmrParam.Saturation = m_fSaturation;
				m_bGrayImage = FALSE;
			}
			HRESULT hRet = pControl->SetProcAmpControl(0,&vmrParam);
		}
	}
}

void CDirectShowEventDlg::OnTimer(UINT nIDEvent) 
{
	CDialog::OnTimer(nIDEvent);
}



void CDirectShowEventDlg::OnVideoset() 
{
	IVMRMixerControl9 * pControl = NULL;
	if (pRender != NULL)
	{
		//pRender->QueryInterface( IID_IVMRMixerControl9,(void**)&pControl);
		pRender->QueryInterface( IID_IVMRMixerControl9,(void**)&pControl);
		if (pControl != NULL )
		{
			//获取饱和度的范围
			m_SatRange.dwSize = sizeof(VMR9ProcAmpControlRange);
			m_SatRange.dwProperty = ProcAmpControl9_Saturation;
			pControl->GetProcAmpControlRange(0, &m_SatRange);

			//获取亮度范围
			m_BrightRange.dwSize = sizeof(VMR9ProcAmpControlRange);
			m_BrightRange.dwProperty = ProcAmpControl9_Brightness;
			pControl->GetProcAmpControlRange(0, &m_BrightRange);
			
			//获取色调范围
			m_HueRange.dwSize = sizeof(VMR9ProcAmpControlRange);
			m_HueRange.dwProperty = ProcAmpControl9_Hue;
			pControl->GetProcAmpControlRange(0, &m_HueRange);

			//获取对比度范围
			m_ConRange.dwSize = sizeof(VMR9ProcAmpControlRange);
			m_ConRange.dwProperty = ProcAmpControl9_Contrast;
			pControl->GetProcAmpControlRange(0, &m_ConRange);

			CVideoSet VideoDlg;
			VideoDlg.DoModal();
		}
	}
}

void CDirectShowEventDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	if (pScrollBar != NULL)
	{
		pScrollBar->SendMessage(WM_PAINT,0,0);	
		if (pScrollBar->m_hWnd==m_ProgressCtrl.m_hWnd && pGraph != NULL)
		{
			IMediaPosition* pPosition = NULL;
			
			pGraph->QueryInterface(IID_IMediaPosition,(void**)&pPosition);
			if (pPosition != NULL)
			{
				int nCurPos = m_ProgressCtrl.GetPos();
				pPosition->put_CurrentPosition(nCurPos);
			}		
		}
		else
		{
			m_ProgressCtrl.SetPos(0);
		}
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

//设置颜色信息
void CDirectShowEventDlg::SetViewInfo(int nFlag, float fValue)
{
	IVMRMixerControl9 * pControl = NULL;
	if (pRender != NULL)
	{
		pRender->QueryInterface( IID_IVMRMixerControl9,(void**)&pControl);
		if (pControl != NULL)
		{
			VMR9ProcAmpControl vmrParam;
			memset(&vmrParam,0,sizeof(VMR9ProcAmpControl));
			vmrParam.dwSize = sizeof(VMR9ProcAmpControl);
			vmrParam.dwFlags = nFlag;
			vmrParam.Brightness = fValue;
			vmrParam.Contrast = fValue;
			vmrParam.Hue = fValue;
			vmrParam.Saturation = fValue;
 			pControl->SetProcAmpControl(0,&vmrParam);
		}
	}
}

void CDirectShowEventDlg::OnTbPause() 
{
	if (pMediaControl != NULL)
	{
		if (m_bPause==FALSE)
		{
			pMediaControl->Pause();
			m_Pause.SetWindowText("继续");
		}
		else
		{
			pMediaControl->Run();
			m_Pause.SetWindowText("暂停");
		}
		m_bPause = !m_bPause;
	}
}

void CDirectShowEventDlg::OnTbStop() 
{
	if (pMediaControl != NULL)
	{			
		m_ProgressCtrl.SetPos(0);
		WPARAM wParam;
		MAKEWPARAM(SB_THUMBPOSITION,0);
		SendMessage(WM_HSCROLL,wParam,(LPARAM)m_ProgressCtrl.m_hWnd);
		pMediaControl->Stop();
		SendMessage(CM_COMPLETE);
		m_Previewed = FALSE;
		m_Progress.SetText("00:00:00");
		m_CurPos.SetText("00:00:00");
		m_bStop = TRUE;
		Invalidate();
	}
}

void CDirectShowEventDlg::OnPosChange()
{
	if (pGraph != NULL)
	{
		IMediaPosition* pPosition = NULL;
		pGraph->QueryInterface(IID_IMediaPosition,(void**)&pPosition);
		if (pPosition != NULL)
		{
			REFTIME endTime;
			pPosition->get_CurrentPosition(&endTime);
			m_ProgressCtrl.SetPos(endTime);

			//将秒转换为小时:分:秒的形式
			int nHour = endTime / 3600;
			int nMinute = (endTime - nHour*3600)/60;
			int nSecond = (int)endTime % 60;
			
			CString csTime,csSpace;
			csSpace = "";
			if (nHour<10)
				csSpace += "0%d:";
			else
				csSpace += "%d:";
			if (nMinute<10)
				csSpace += "0%d:";
			else
				csSpace += "%d:";
			if (nSecond<10)
				csSpace += "0%d";
			else
				csSpace += "%d";
		
			csTime.Format(csSpace,nHour,nMinute,nSecond);
		
			m_CurPos.SetText(csTime);

		}		
	}
}

void CDirectShowEventDlg::OnShowwnd() 
{
	m_DisplayWnd.ShowWindow(SW_SHOW);	
}



void CDirectShowEventDlg::PlayFile(LPCTSTR lpFileName)
{
	if (pGraph != NULL)	//之前已经播放文件或者正在播放文件
	{
		Done(0,0);	//停止播放
	}
	m_bStop = FALSE;

	pBuilder = NULL;
	pGraph = NULL;
	pMediaControl = NULL;
	m_FileName = lpFileName;
	CoCreateInstance(CLSID_CaptureGraphBuilder2,0,CLSCTX_INPROC_SERVER,IID_ICaptureGraphBuilder2,(void**)&pBuilder);		
	CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, 
						IID_IFilterGraph2, (void **)&pGraph);

	pBuilder->SetFiltergraph(pGraph);

	m_bInvalidFile = FALSE;
	pRender = NULL;
	CoCreateInstance(CLSID_VideoMixingRenderer9, NULL, CLSCTX_ALL, 
		IID_IBaseFilter, (void **)&pRender);

	m_ThreadStop = FALSE;
	HANDLE hHandle = CreateThread(NULL,0,PlayVideoFile,(void*)this,0,NULL);

	while (!m_ThreadStop)
	{
		MSG msg;
		::GetMessage(&msg,NULL,0,WM_USER);
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}

	if (m_bInvalidFile)	//文件非法
	{
		Done(0,0);	//停止播放
		return;
	}
	//获取预览窗口
	pViewWnd= NULL;  
	pGraph->QueryInterface(IID_IVideoWindow,(void**)&pViewWnd);


	if (pViewWnd)
	{
		//设置预览窗口的拥有者
		pViewWnd->put_Owner((long)m_DisplayWnd.m_Panel.m_hWnd);
		pViewWnd->put_Left(0);
		pViewWnd->put_Top(0);

		//获取预览窗口风格
		long style;
		pViewWnd->get_WindowStyle(&style);
		style = style & ~WS_CAPTION;
		style = style & ~WS_DLGFRAME;
		style = style & WS_CHILD;
		pViewWnd->put_WindowStyle(style);
		
		//设置预览窗口宽度和高度
		CRect rc;
		m_DisplayWnd.m_Panel.GetClientRect(rc);
		pViewWnd->put_Height(rc.Height());
		pViewWnd->put_Width(rc.Width());
		pViewWnd->put_MessageDrain((OAHWND)m_DisplayWnd.m_Panel. m_hWnd );
	}

	if (m_bViewPlay)
	{
		m_DisplayWnd.ShowWindow(SW_SHOW);
		m_DisplayWnd.ModifyStyle(0,WS_SIZEBOX);
	}
	else
	{
		m_DisplayWnd.ShowWindow(SW_HIDE);
		m_DisplayWnd.ModifyStyle(WS_SIZEBOX,0);		
	}

	m_hThread = NULL;
	pGraph->QueryInterface(IID_IMediaControl,(void**)&pMediaControl);		
	pMediaControl->Run();

	IMediaPosition* pPosition = NULL;
	pGraph->QueryInterface(IID_IMediaPosition,(void**)&pPosition);
	if (pPosition != NULL)
	{
		REFTIME curTime,endTime;
		pPosition->get_StopTime(&endTime);
		pPosition->get_CurrentPosition(&curTime);
		m_ProgressCtrl.SetRange(curTime,endTime);
		
		//将秒转换为小时:分:秒的形式
		int nHour = endTime / 3600;
		int nMinute = (endTime - nHour*3600)/60;
		int nSecond = (int)endTime % 60;
		
		CString csTime,csSpace;
		csSpace = "";
		if (nHour<10)
			csSpace += "0%d:";
		else
			csSpace += "%d:";
		if (nMinute<10)
			csSpace += "0%d:";
		else
			csSpace += "%d:";
		if (nSecond<10)
			csSpace += "0%d";
		else
			csSpace += "%d";
	
		csTime.Format(csSpace,nHour,nMinute,nSecond);
	
		m_Progress.SetText(csTime);

	}

	pEvent = NULL;

	pGraph->QueryInterface(IID_IMediaEventEx, (void **)&pEvent);
	m_Completed = FALSE;
	DWORD threadID;
	m_hThread =  CreateThread(NULL,0,ThreadProc,(void*)this,0,&threadID);
	m_Previewed = TRUE;
}

