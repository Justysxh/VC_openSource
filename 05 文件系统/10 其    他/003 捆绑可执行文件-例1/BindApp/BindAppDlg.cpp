// BindAppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BindApp.h"
#include "BindAppDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

#define FINDFLAG 0x12345678

//定义一个结构,fileFlag为全局变量，用于记录可执行文件的长度
struct FILE_FLAG
{
	UINT	nFindFlag;		//查找标识
	UINT	nFileLen;		//文件长度
} fileFlag = {FINDFLAG, 0};


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
// CBindAppDlg dialog

CBindAppDlg::CBindAppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBindAppDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBindAppDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_MAINICON);
}

void CBindAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBindAppDlg)
	DDX_Control(pDX, IDC_FILE3, m_File3);
	DDX_Control(pDX, IDC_FILE2, m_File2);
	DDX_Control(pDX, IDC_FILE1, m_File1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBindAppDlg, CDialog)
	//{{AFX_MSG_MAP(CBindAppDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUILD, OnBuild)
	ON_BN_CLICKED(IDC_BROWSE1, OnBrowse1)
	ON_BN_CLICKED(IDC_BROWSE2, OnBrowse2)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	ON_BN_CLICKED(IDC_BROWSE3, OnBrowse3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBindAppDlg message handlers

BOOL CBindAppDlg::OnInitDialog()
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
	
	memset(m_szSelfName, 0, MAX_PATH);
	//获取可执行文件的名称
	GetModuleFileName(NULL, m_szSelfName, MAX_PATH);

	struct _stat fileState;
	_stat(m_szSelfName, &fileState);
	
	//当前文件已被捆绑
	if (fileFlag.nFileLen !=0)
	{
		RunBindExe();
		exit(0);
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBindAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBindAppDlg::OnPaint() 
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
HCURSOR CBindAppDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBindAppDlg::OnOK() 
{
	
}

void CBindAppDlg::OnCancel() 
{
	CDialog::OnCancel();	
}

//生成可执行文件
void CBindAppDlg::OnBuild() 
{
	//读取文件1
	CString szFile1, szFile2, szFile3;
	m_File1.GetWindowText(szFile1);
	m_File2.GetWindowText(szFile2);
	m_File3.GetWindowText(szFile3);

	if (!szFile1.IsEmpty() && !szFile2.IsEmpty() && !szFile3.IsEmpty())
	{
		FILE* pflSelf	= NULL;	//可执行文件自身
		FILE* pflFinal	= NULL;	//最终生成的可执行文件
		FILE* pflFirst	= NULL;	//第一个捆绑的文件
		FILE* pflSecond	= NULL;	//第二个捆绑的文件
		struct _stat fileState;
		//获取自身的可执行文件信息
		_stat(m_szSelfName, &fileState);
		//获取文件长度
		DWORD dwFileLen = fileState.st_size;
		fileFlag.nFileLen = dwFileLen;
		//为文件分配缓冲区
		BYTE* pFileBuffer = (BYTE*)	malloc(dwFileLen);
		//打开当前文件
		pflSelf = fopen(m_szSelfName, "rb");
		if (pflSelf == NULL)
		{
			MessageBox("打开自身文件失败!", "提示");
			return;
		}
		//读取文件
		DWORD dwRead = fread(pFileBuffer, sizeof(char), dwFileLen, pflSelf);
		fclose(pflSelf);
		if (dwRead != dwFileLen)
		{
			MessageBox("读取自身文件发生错误!", "提示");
			return;
		}
		
		//写入文件的长度
		UINT nFlag  = FINDFLAG;
		//在可执行文件中查找FINDFLAG常量值，目的是定位到全局变量fileFlag的数据存储位置
		for(int i=0; i<dwFileLen-sizeof(UINT); i+=sizeof(UINT))
		{
			//在可执行文件中查找FINDFLAG即0x12345678，因为全局变量fileFlag中包含有0x12345678
			for(int j=0; j<sizeof(UINT); j++)
			{
				if (pFileBuffer[i+j] != ((BYTE*)&nFlag)[j])
					break;
			}
			if (j == sizeof(UINT))	//在可执行文件中发现了0x12345678数据
			{
				//修改可执行文件中fileFlag的数据存储位置上的数据
				memcpy(pFileBuffer+i, &fileFlag, sizeof(FILE_FLAG));
				break;
			}
		}
		if (i >= dwFileLen-sizeof(UINT))	//在可执行文件中没有发现0x12345678数据
		{
			free(pFileBuffer);
			MessageBox("定义可执行文件错误!", "提示");
			return;
		}
		
		//写入第一个可执行文件
		if (_stat(szFile1.GetBuffer(0), &fileState) != 0 || fileState.st_size ==0)
		{
			free(pFileBuffer);
			MessageBox("读取第一个绑定的文件失败!", "提示");			
			return;
		}
		szFile1.ReleaseBuffer();
		//创建最终的可执行文件
		pflFinal = fopen(szFile3.GetBuffer(0), "wb");
		if (pflFinal == NULL)
		{
			free(pFileBuffer);
			MessageBox("创建可执行文件失败!", "提示");			
			return;
		}
		szFile3.ReleaseBuffer();
		//首先写入自身文件到最终的可执行文件中
		fwrite(pFileBuffer, sizeof(char), dwFileLen, pflFinal);
		//打开第一个可执行文件
		pflFirst = fopen(szFile1.GetBuffer(0), "rb");
		if (pflFirst == NULL)
		{
			fclose(pflFinal);
			//删除生成的文件
			//...
			free(pFileBuffer);
			MessageBox("打开第一个绑定的文件失败!", "提示");
			return;
		}
		szFile1.ReleaseBuffer();
		//写入第一个要捆绑的文件长度
		fwrite(&fileState.st_size, sizeof(char), sizeof(fileState.st_size), pflFinal);
		//将第一个文件写入到最终的可执行文件中
		free(pFileBuffer);
		pFileBuffer = (BYTE*)malloc(fileState.st_size);
		fread(pFileBuffer, sizeof(char), fileState.st_size, pflFirst);
		fwrite(pFileBuffer, sizeof(char), fileState.st_size, pflFinal);
		fclose(pflFirst);
		free(pFileBuffer);
		//写入第二个要捆绑的文件
		if (_stat(szFile2.GetBuffer(0), &fileState) != 0 || fileState.st_size ==0)
		{
			MessageBox("读取第二个绑定的文件失败!", "提示");			
			return;
		}
		szFile2.ReleaseBuffer();	
		pflSecond = fopen(szFile2.GetBuffer(0), "rb");
		if (pflSecond == NULL)
		{
			MessageBox("打开第二个绑定的文件失败!", "提示");
			return;
		}
		szFile2.ReleaseBuffer();
		pFileBuffer = (BYTE*)malloc(fileState.st_size);
		fread(pFileBuffer, sizeof(char), fileState.st_size, pflFirst);
		fwrite(pFileBuffer, sizeof(char), fileState.st_size, pflFinal);
		fclose(pflSecond);
		free(pFileBuffer);
		MessageBox("绑定完成!", "提示");

	}
}

void CBindAppDlg::OnBrowse1() 
{
	CFileDialog flDlg(TRUE, "", "", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
						"可执行文件|*.exe||");
	if (flDlg.DoModal()==IDOK)
	{
		CString szFileName = flDlg.GetPathName();
		m_File1.SetWindowText(szFileName);
	}
}

void CBindAppDlg::OnBrowse2() 
{
	CFileDialog flDlg(TRUE, "", "", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
						"可执行文件|*.exe||");
	if (flDlg.DoModal()==IDOK)
	{
		CString szFileName = flDlg.GetPathName();
		m_File2.SetWindowText(szFileName);
	}	
}

void CBindAppDlg::OnBrowse3() 
{
	CFileDialog flDlg(TRUE, "", "", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
						"可执行文件|*.exe||");
	if (flDlg.DoModal()==IDOK)
	{
		CString szFileName = flDlg.GetPathName();
		m_File3.SetWindowText(szFileName);
	}	
}

//运行绑定的Exe文件
void CBindAppDlg::RunBindExe()
{
	FILE* pflSelf	= NULL;		//当前文件自身
	FILE* pflFirst	= NULL;		//捆绑的第一个文件
	FILE* pflSecond = NULL;		//捆绑的第二个文件
	char  pszFirstFile[]  = "First.exe";
	char  pszSecondFile[] = "Second.exe";
	
	pflSelf = fopen(m_szSelfName, "rb");

	if (pflSelf == NULL)
	{
		return;
	}
	pflFirst = fopen(pszFirstFile, "wb");
	if (pflFirst == NULL)
	{
		fclose(pflSelf);
		return;
	}
	//定位到第一个文件的结尾
	fseek(pflSelf, fileFlag.nFileLen, SEEK_SET);
	//读取第一个绑定的文件长度
	
	UINT nFileLen = 0;
	if (fread(&nFileLen, sizeof(char), sizeof(UINT), pflSelf)==0)
	{
		fclose(pflSelf);
		fclose(pflFirst);
		return;
	}
	//向绑定的第一个文件中写入数据
	BYTE* pBuffer = (BYTE*) malloc(nFileLen);
	fread(pBuffer, sizeof(char), nFileLen, pflSelf);
	fwrite(pBuffer, sizeof(char), nFileLen, pflFirst);
	fclose(pflFirst);

	//向绑定的第二个文件中写入数据
	pflSecond = fopen(pszSecondFile, "wb");
	if (pflSecond == NULL)
	{
		fclose(pflSelf);
		free(pBuffer);
		return;
	}	
	int nReadSize = 0;
	while(nReadSize = fread(pBuffer, sizeof(char), nFileLen, pflSelf))
	{
		fwrite(pBuffer, sizeof(char), nReadSize, pflSecond);
	}
	fclose(pflSecond);
	free(pBuffer);
	fclose(pflSelf);

	RunExeFile(pszFirstFile);
	RunExeFile(pszSecondFile);

}

void CBindAppDlg::RunExeFile(LPCTSTR lpExeFile)
{
     HANDLE hProc;
     PROCESS_INFORMATION procInfo;
     STARTUPINFO startInfo;
     memset(&startInfo, 0, sizeof(STARTUPINFO));
     startInfo.cb = sizeof(STARTUPINFO);
	 CreateProcess(lpExeFile, NULL, NULL, NULL, FALSE,
					NORMAL_PRIORITY_CLASS, NULL, NULL, &startInfo, &procInfo);	 
	 hProc = procInfo.hProcess;       
     WaitForSingleObject(hProc, INFINITE);
     unlink(lpExeFile);
}

