// AviCompressDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AviCompress.h"
#include "AviCompressDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "vfw.h"
#pragma comment (lib,"vfw32")

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
// CAviCompressDlg dialog

CAviCompressDlg::CAviCompressDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAviCompressDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAviCompressDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CAviCompressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAviCompressDlg)
	DDX_Control(pDX, IDC_SRCFile, m_SrcFile);
	DDX_Control(pDX, IDC_DSTFILE, m_DstFile);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAviCompressDlg, CDialog)
	//{{AFX_MSG_MAP(CAviCompressDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SRCBROWN, OnSrcBrown)
	ON_BN_CLICKED(IDC_DSTBROWN, OnDstBrown)
	ON_BN_CLICKED(IDC_COMPRESS, OnCompress)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAviCompressDlg message handlers

BOOL CAviCompressDlg::OnInitDialog()
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

void CAviCompressDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAviCompressDlg::OnPaint() 
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
HCURSOR CAviCompressDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAviCompressDlg::CompressAvi(LPCSTR lpstrOldFile,LPCSTR lpstrNewFile)
{
	HIC hIC;
	ICINFO icInfo;
	icInfo.fccType    = 1667524982;   //编码解码器类型值
	icInfo.fccHandler = 859066445;    //编码解码器句柄值
	
	BITMAPINFOHEADER InHeader ;
	BITMAPINFOHEADER OutHeader;
	
	//初始化avi文件
	AVIFileInit();

	PAVIFILE pOldFile,pNewFile;
	
	HRESULT hRet;
	//打开源文件
	hRet =  AVIFileOpen(&pOldFile,lpstrOldFile,OF_READ, NULL);
	
	if (hRet != 0)
	{
		MessageBox("打开源文件错误","提示");
		return;
	}
	//打开新文件
	hRet =  AVIFileOpen(&pNewFile,lpstrNewFile,OF_WRITE |OF_CREATE ,NULL);
	if (hRet != 0 )
	{
		MessageBox("打开目标文件错误","提示");
		return;
	}
	
	//定义文件流
	PAVISTREAM pOldStream,pNewStream;

	AVIFileGetStream(pOldFile, &pOldStream, streamtypeVIDEO, 0 );
	//获取流的起始帧
	long StartFrame=AVIStreamStart(pOldStream);
	//获取流的帧长度
	long FrameNum= AVIStreamLength(pOldStream);
	
	AVISTREAMINFO OldStreamInfo,NewStreamInfo;
	//获取流信息
	AVIStreamInfo(pOldStream,&OldStreamInfo,sizeof(AVISTREAMINFO));

	long size = sizeof(BITMAPINFOHEADER);

	AVIStreamReadFormat(pOldStream,StartFrame,&InHeader,&size);
	OutHeader=InHeader;

	PGETFRAME pFrame;
	//在流中打开帧
	pFrame=AVIStreamGetFrameOpen(pOldStream, NULL);

	void * lpOutData;
	lpOutData=VirtualAlloc(NULL,OutHeader.biSizeImage,MEM_COMMIT,
		PAGE_READWRITE);

	//打开压缩管理器
	hIC=ICOpen(icInfo.fccType,icInfo.fccHandler,ICMODE_COMPRESS); 
	ICCompressGetFormat(hIC,&InHeader,&OutHeader);

	memset(&NewStreamInfo,0,sizeof(NewStreamInfo));
	NewStreamInfo.fccType=streamtypeVIDEO;
	NewStreamInfo.fccHandler=mmioFOURCC('M', 'S', 'V', 'C');
	NewStreamInfo.dwScale=1;
	NewStreamInfo.dwRate=25;
	NewStreamInfo.dwSuggestedBufferSize=OutHeader.biSizeImage;
	SetRect(&NewStreamInfo.rcFrame,0,0,OutHeader.biWidth,OutHeader.biHeight);

	if(ICCompressQuery(hIC,&InHeader,&OutHeader)==ICERR_OK)
	{
		ICCompressBegin(hIC,(BITMAPINFO*)&InHeader,(BITMAPINFO*)&OutHeader);
	}

	AVIFileCreateStream(pNewFile,&pNewStream,&NewStreamInfo);
	AVIStreamSetFormat(pNewStream,0,&OutHeader,sizeof(OutHeader));

	for (int index=StartFrame; index<FrameNum; index++)
	{
		long num = sizeof(InHeader);
		AVIStreamReadFormat(pOldStream,index,&OutHeader,&num);

		BYTE* pDIB = (BYTE*) AVIStreamGetFrame(pFrame, index);
		BYTE* pData=pDIB+sizeof(BITMAPINFOHEADER);
		
		DWORD dwCkID;
		DWORD dwCompFlags;
		DWORD dwQuality=100;
		if(ICCompress(hIC,ICCOMPRESS_KEYFRAME,&OutHeader,lpOutData,
			&InHeader,pData,&dwCkID,&dwCompFlags,index,0,dwQuality,
			NULL,NULL)==ICERR_OK)
		{
			AVIStreamSetFormat(pNewStream,index,&OutHeader,sizeof(OutHeader));
			AVIStreamWrite(pNewStream,index,1,(LPBYTE)lpOutData,
				OutHeader.biSizeImage,AVIIF_KEYFRAME,NULL,NULL);	
		} 
	}
	if(hIC!=NULL)
	{
		ICCompressEnd(hIC);
		ICClose (hIC);
	}	
	AVIStreamGetFrameClose(pFrame);
	AVIStreamRelease(pNewStream);
	AVIStreamRelease(pOldStream);

	AVIFileRelease(pOldFile);
	AVIFileRelease(pNewFile); 
	VirtualFree(lpOutData,OutHeader.biSizeImage,MEM_DECOMMIT);	
	AVIFileExit();
}

void CAviCompressDlg::OnOK() 
{

}

void CAviCompressDlg::OnSrcBrown() 
{
	CFileDialog fDlg(TRUE,"","",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"AVI文件|*.avi");
	if (fDlg.DoModal()==IDOK)
	{
		CString strFile = fDlg.GetPathName();
		m_SrcFile.SetWindowText(strFile);
	}
}

void CAviCompressDlg::OnDstBrown() 
{
	CFileDialog fDlg(FALSE,"avi","One",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"AVI文件|*.avi");
	if (fDlg.DoModal()==IDOK)
	{
		CString strFile = fDlg.GetPathName();
		DeleteFile(strFile);
		m_DstFile.SetWindowText(strFile);
	}	
}

//对AVI文件进行再次压缩
void CAviCompressDlg::OnCompress() 
{
	CString strSrc,strDst;
	m_SrcFile.GetWindowText(strSrc);
	m_DstFile.GetWindowText(strDst);
	if (strSrc.IsEmpty()|| strDst.IsEmpty())
	{
		MessageBox("源文件或目标文件不能为空!","提示");
		return ;
	}
	CompressAvi(strSrc,strDst);
	MessageBox("压缩完成!");
}



