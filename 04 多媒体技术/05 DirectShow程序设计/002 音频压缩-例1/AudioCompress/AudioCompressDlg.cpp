// AudioCompressDlg.cpp : implementation file
//

#include "stdafx.h"

#include "AudioCompress.h"
#include "AudioCompressDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "wave.h"

/////////////////////////////////////////////////////////////////////////////

//定义Wave文件格式中数据块结构
typedef struct _rifflist 
{ 
	FOURCC fcc;
	DWORD cb;
	FOURCC fccListType;
} RIFFLIST, * LPRIFFLIST;

typedef struct _riffchunk
{ 
	FOURCC fcc;
	DWORD cb;
} RIFFCHUNK, * LPRIFFCHUNK;

typedef struct 
{
	HACMDRIVERID hadid;  //指向HACMDRIVERID的句柄
	WORD wFormatTag;     //32位无符号整型 格式标签
} FIND_DRIVER_INFO;      //结构FIND_DRIVER_INFO包含2个元素:HACMDRIVERID hadid 和WORD wFormatTag


WAVEFORMATEX  dstPCM;     //目标音频格式
DWORD         dstSamples; //目标采样数量
HACMDRIVERID  hAcm;       //ACM驱动程序句柄
DWORD         dstBytes;   //压缩后的音频数据大小

//选择目标音频压缩格式
BOOL CALLBACK FormatEnumProc(HACMDRIVERID   hadid,  LPACMFORMATDETAILS   pafd, 
							 DWORD   dwInstance,   DWORD   fdwSupport)   
{   
	if(pafd->dwFormatTag==WAVE_FORMAT_PCM)   
	{   
		DWORD   sample=pafd->pwfx->nAvgBytesPerSec;   
		if((sample==44100))   
		{   
			dstPCM =*(WAVEFORMATEX*)pafd->pwfx;   
			hAcm=hadid;   
			return   FALSE;   
		}   
	}   
	return   TRUE;   
}   

BOOL CALLBACK CodecsEnum(HACMDRIVERID hAdid, DWORD dwInstance,DWORD dwSupport)     
{   
	DWORD   dwSize   =   0;   
    
	ACMDRIVERDETAILS   acm;   
	acm.cbStruct   =   sizeof(acm);   
	MMRESULT   mmr   =   acmDriverDetails(hAdid,   &acm,   0);   
    
	HACMDRIVER   had   =   NULL;   
	mmr   =   acmDriverOpen(&had,hAdid,0);   //打开驱动程序   
	if   (mmr)   
	{
		return FALSE;
	}   
	else 
	{   
		mmr   =   acmMetrics((HACMOBJ)had,   ACM_METRIC_MAX_SIZE_FORMAT, &dwSize);   
		if   (dwSize   <   sizeof(WAVEFORMATEX))   dwSize   =   sizeof(WAVEFORMATEX);   
		WAVEFORMATEX*   pWaveForm   =   (WAVEFORMATEX*)   malloc(dwSize);   
		
		memset(pWaveForm,0,dwSize);   
		pWaveForm->cbSize = LOWORD(dwSize)- sizeof(WAVEFORMATEX);   
		pWaveForm->wFormatTag =  WAVE_FORMAT_UNKNOWN;   
		ACMFORMATDETAILS   AcmForm;   
		memset(&AcmForm,   0,   sizeof(AcmForm));   
		AcmForm.cbStruct   =    sizeof(AcmForm);     
		AcmForm.pwfx   =   pWaveForm;   
		AcmForm.cbwfx   =   dwSize;   
		AcmForm.dwFormatTag   =   WAVE_FORMAT_UNKNOWN;   
		mmr   =   acmFormatEnum(had,   &AcmForm,  FormatEnumProc,   0,   0);     
		if   (mmr||hAcm)   
		{   
			return   FALSE;   
		}   
		free(pWaveForm);   
		acmDriverClose(had,   0);   
	}   
	return   TRUE;     
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
// CAudioCompressDlg dialog

CAudioCompressDlg::CAudioCompressDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAudioCompressDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAudioCompressDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CAudioCompressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAudioCompressDlg)
	DDX_Control(pDX, IDC_SRCFILE, m_SrcFile);
	DDX_Control(pDX, IDC_DSTFILE, m_DstFile);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAudioCompressDlg, CDialog)
	//{{AFX_MSG_MAP(CAudioCompressDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SRCBROWN, OnSrcBrown)
	ON_BN_CLICKED(IDC_DSTBRWON, OnDstBrown)
	ON_BN_CLICKED(IDC_COMPRESS, OnCompress)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAudioCompressDlg message handlers

BOOL CAudioCompressDlg::OnInitDialog()
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

void CAudioCompressDlg::OnSysCommand(UINT nID, LPARAM lParam)
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


void CAudioCompressDlg::OnPaint() 
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
HCURSOR CAudioCompressDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAudioCompressDlg::OnOK() 
{

}


void CAudioCompressDlg::OnSrcBrown() 
{
	CFileDialog fDlg(TRUE,"","",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"波形文件| *.wav");
	if (fDlg.DoModal()==IDOK)
	{
		CString strFile;
		strFile = fDlg.GetPathName();
		m_SrcFile.SetWindowText(strFile);
	}	
}

void CAudioCompressDlg::OnDstBrown() 
{
	CFileDialog fDlg(FALSE,"wav","one",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"波形文件|*.wav");
	if (fDlg.DoModal()==IDOK)
	{
		CString strFile;
		strFile = fDlg.GetPathName();
		DeleteFile(strFile);
		m_DstFile.SetWindowText(strFile);
	}	
}


void CAudioCompressDlg::OnCompress() 
{
    CString srcFile;
	m_SrcFile.GetWindowText(srcFile);
	CString dstFile;
	m_DstFile.GetWindowText(dstFile);
	//列举驱动器
	acmDriverEnum(CodecsEnum,0,0);
   
	CFile   fp;   
	fp.Open(srcFile ,CFile::modeRead);   
	DWORD   dwDstBytes=fp.GetLength();   
 
	RIFFLIST riff;

	fp.Read(&riff,sizeof(RIFFLIST));
	RIFFCHUNK  riffchuck;
	fp.Read(&riffchuck,sizeof(RIFFCHUNK));

	fp.Read(&m_wfSrc,sizeof(WAVEFORMATEX1));

	RIFFCHUNK riffData;
	fp.Read(&riffData,sizeof(RIFFLIST));

	BYTE* pSrcData=new   byte [riffData.cb] ;
	fp.Read(pSrcData, riffData.cb);  

	fp.Close();

	HMMIO hmmio;
	MMCKINFO  pck,riffinfo;
	
	UINT factsize;

	MMIOINFO  mmio;

	BYTE* pDstData =  OnConvert(pSrcData,riffData.cb);

	WaveSaveFile(dstFile.GetBuffer(0),dstBytes, dstSamples,(WAVEFORMATEX*)&dstPCM,pDstData );
	delete   []   pSrcData ;   
	delete   []   pDstData;   
}


BYTE*  CAudioCompressDlg::OnConvert(BYTE*   pSrcData,DWORD datasize)   
{   
	//数据块的调整数
	m_wfSrc.nBlockAlign   =   m_wfSrc.nChannels   *m_wfSrc.wBitsPerSample   / 8;   

	MMRESULT   mmr;   
	HACMSTREAM   hstr   =   NULL;   
	mmr   =   acmStreamOpen(&hstr,   
		NULL,	 
		(WAVEFORMATEX*)&m_wfSrc,  
		(WAVEFORMATEX*)&dstPCM,    
		NULL,  
		NULL,
		0,	   
		ACM_STREAMOPENF_NONREALTIME); 
    
	if   (mmr)   {   
		AfxMessageBox("转换失败!");   
		return NULL;   
	}   
	ACMSTREAMHEADER   strhdr;   
	memset(&strhdr,   0,   sizeof(strhdr));   
	strhdr.cbStruct   =   sizeof(strhdr);   
	strhdr.pbSrc      =   pSrcData;     
	strhdr.cbSrcLength   =   datasize;    
	//采样数量
	dstSamples =  datasize / (m_wfSrc.nChannels* m_wfSrc.wBitsPerSample/8) ;

	dstBytes =datasize ;

	BYTE* pDstData = new BYTE[dstBytes];
	strhdr.cbDstLength   =   dstBytes;   
	strhdr.pbDst   =   pDstData;   	   
	mmr   =   acmStreamPrepareHeader(hstr, &strhdr, 0);     
	mmr   =   acmStreamConvert(hstr,   &strhdr,   0);   
	dstBytes  = strhdr.cbDstLengthUsed;    
	if (mmr)
	{   
		AfxMessageBox("转换失败!");   
		return NULL ;   
	}   

	acmStreamClose(hstr,   0);   
	return pDstData;
}   
