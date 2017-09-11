// BuildAviDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BuildAvi.h"
#include "BuildAviDlg.h"
#include "Vfw.h"
#include "mmsystem.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#pragma comment (lib,"winmm.lib")
#pragma comment (lib,"Vfw32.lib")				//链接库文件

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
// CBuildAviDlg dialog

CBuildAviDlg::CBuildAviDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBuildAviDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBuildAviDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBuildAviDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBuildAviDlg)
	DDX_Control(pDX, IDC_EDIT1, m_BmpDir);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBuildAviDlg, CDialog)
	//{{AFX_MSG_MAP(CBuildAviDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBuildAviDlg message handlers

BOOL CBuildAviDlg::OnInitDialog()
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

void CBuildAviDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBuildAviDlg::OnPaint() 
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
HCURSOR CBuildAviDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBuildAviDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	char folder[MAX_PATH] = {0};				//定义一个字符数组
	BROWSEINFO binfo;					//定义浏览信息
	memset(&binfo,0,sizeof(BROWSEINFO));		//初始化binfo
	ITEMIDLIST* ilist;						//定义一个ITEMIDLIST指针
	binfo.hwndOwner      = 0;					//设置对话框拥有者
	binfo.pidlRoot       = NULL;					//设置根目录
	binfo.pszDisplayName = folder;				//设置显示名称
	binfo.lpszTitle      = "浏览文件";				//设置标题
	binfo.ulFlags        = BIF_VALIDATE;			//设置标记
	binfo.lpfn           = NULL;			//设置回调函数
	binfo.lParam         = 0;						//设置回调函数的参数
	ilist                = SHBrowseForFolder(&binfo);			//显示浏览文件夹对话框
	SHGetPathFromIDList(ilist,folder);			//获取选择的文件夹名称
	m_BmpDir.SetWindowText(folder);			//设置编辑框文本
}

void CBuildAviDlg::OnOK() 
{
	// TODO: Add extra validation here
	CFileDialog flDlg(FALSE,"avi","demo",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT
		,"AVI文件|*.avi||",this);	//定义文件保存对话框
	if(flDlg.DoModal()==IDOK)				//判断用户是否按OK按钮
	{
		CString flname = flDlg.GetPathName();	//获取文件名称
		CString folder;
		m_BmpDir.GetWindowText(folder);	
		BmpsToAvi(flname,folder);
	}

	//CDialog::OnOK();
}

void CBuildAviDlg::BmpsToAvi(LPCSTR szFileName, LPCSTR szDir)
{
	CString BmpDir = szDir;					//定义一个字符串
	BmpDir += _T("\\*.*"); 					//修改字符串
	AVIFileInit(); 							//初始化AVIFile函数库
	AVISTREAMINFO strhdr;					//定义AVI文件流信息
	PAVIFILE pFile;						//定义AVI文件指针
	PAVISTREAM ps; 						//定义AVI流对象
	PAVISTREAM pComStream;									//压缩视频数据流
	AVICOMPRESSOPTIONS pCompressOption; 						//压缩模式
	AVICOMPRESSOPTIONS FAR * opts[1] = {&pCompressOption};  
	int nFrames =0; 						//定义整型变量，表示帧数
	CFileFind flFind;						//定义文件查找对象
	BOOL bret = flFind.FindFile(BmpDir);		//查找文件
	while(bret)							//是否发现文件
	{
		bret = flFind.FindNextFile();			//查找下一个文件
		if(!flFind.IsDots() && !flFind.IsDirectory())	//判断文件属性
		{
			CString flname = flFind.GetFilePath();//获取文件名称
			FILE *pf = fopen(flname,"rb");		//打开文件
			BITMAPFILEHEADER bmpFileHdr;	//定义位图文件头
			BITMAPINFOHEADER bmpInfoHdr;	//定义位图信息头
			fseek(pf,0,SEEK_SET);							//搜索文件
			fread(&bmpFileHdr,sizeof(BITMAPFILEHEADER),1, pf);	//读取位图文件头
			fread(&bmpInfoHdr,sizeof(BITMAPINFOHEADER),1, pf);	//读取位图信息头
			if(nFrames == 0)								//是否为第一帧
			{
				//创建并打开avi文件
				AVIFileOpen(&pFile,szFileName,OF_WRITE | OF_CREATE,NULL);
				memset(&strhdr, 0, sizeof(strhdr));				//初始化文件流信息
				strhdr.fccType    = streamtypeVIDEO;				//设置流类型
				strhdr.fccHandler = 0;						//设置处理者
				strhdr.dwScale    = 1;							//设置时间刻度
				strhdr.dwRate     = 3; 							//设置速度
				//设置图像代码
				strhdr.dwSuggestedBufferSize = bmpInfoHdr.biSizeImage ;	
				//设置显示区域
				SetRect(&strhdr.rcFrame, 0, 0, bmpInfoHdr.biWidth, bmpInfoHdr.biHeight);
				AVIFileCreateStream(pFile,&ps,&strhdr); 			//创建数据流
				opts[0]->fccType = streamtypeVIDEO;					//视频模式
				opts[0]->fccHandler = mmioStringToFOURCC("MSVC", 0);	//压缩编码
				opts[0]->dwQuality = 7500;
				opts[0]->dwBytesPerSecond = 0;
				opts[0]->dwFlags = AVICOMPRESSF_VALID || AVICOMPRESSF_KEYFRAMES;
				opts[0]->lpFormat = 0;
				opts[0]->cbFormat = 0;
				opts[0]->dwInterleaveEvery = 0;
				AVIMakeCompressedStream(&pComStream,ps,&pCompressOption,NULL); //创建压缩数据流
				AVIStreamSetFormat(pComStream,0,&bmpInfoHdr,sizeof(BITMAPINFOHEADER));//设置流格式
			}
			//定义一个缓冲区
			BYTE *buffer = new BYTE[bmpInfoHdr.biWidth * bmpInfoHdr.biHeight * 3];
			//读取图像信息到缓冲区
			fread(buffer, 1, bmpInfoHdr.biWidth * bmpInfoHdr.biHeight * 3, pf);
			//向流中写入数据
			AVIStreamWrite(pComStream, nFrames,1,(LPBYTE)buffer,bmpInfoHdr.biSizeImage, 
				AVIIF_KEYFRAME, NULL,NULL);
			nFrames ++; 									//写下一帧
			fclose(pf);										//关闭文件
			delete []buffer;									//释放缓冲区
		}
	}
	AVIStreamClose(ps);									//关闭流文件
	AVIStreamClose(pComStream);									//关闭流文件
	if(pFile != NULL)
		AVIFileRelease(pFile);								//释放AVI文件接口
	AVIFileExit();											//退出AVI函数库
}
