// FtpDownDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FtpDown.h"
#include "FtpDownDlg.h"

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
// CFtpDownDlg dialog

CFtpDownDlg::CFtpDownDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFtpDownDlg::IDD, pParent),m_ThreadCount(4)
{
	//{{AFX_DATA_INIT(CFtpDownDlg)
	m_Dir = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_pHthread = new HANDLE[m_ThreadCount];
	m_pData = new void*[m_ThreadCount];
	m_pEvent = new CEvent[m_ThreadCount];
}

void CFtpDownDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFtpDownDlg)
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Text(pDX, IDC_DIR, m_Dir);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFtpDownDlg, CDialog)
	//{{AFX_MSG_MAP(CFtpDownDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DOWNLOAD, OnDownload)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFtpDownDlg message handlers

BOOL CFtpDownDlg::OnInitDialog()
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
	
	m_List.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES |LVS_EX_TWOCLICKACTIVATE);

	m_List.InsertColumn(0,"文件名称",LVCFMT_LEFT,100);
	m_List.InsertColumn(1,"开始时间",LVCFMT_LEFT,150);
	m_List.InsertColumn(2,"目标文件",LVCFMT_LEFT,150);
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFtpDownDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFtpDownDlg::OnPaint() 
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
HCURSOR CFtpDownDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFtpDownDlg::OnOK() 
{

}

//线程函数
DWORD WINAPI ThreadProc(LPVOID lpParameter )
{
	int index = *(int*)lpParameter;
	delete lpParameter;
	CInternetSession * pSession = new CInternetSession;
	CHttpConnection * pFtpCon = pSession->GetHttpConnection("127.0.0.1");

	CFtpDownDlg* pDlg = (CFtpDownDlg*)AfxGetMainWnd();

	CInternetFile* pFile = (CInternetFile*)pSession->OpenURL(pDlg->m_Dir);

	DWORD readsize;
	if (index < pDlg->m_ThreadCount-1)
		readsize = pDlg->m_PerFileSize;
	else
		readsize = pDlg->m_EndFileSize;	
	
	
	pFile->Seek(index*pDlg->m_PerFileSize,FILE_BEGIN);

	pDlg->m_pData[index] = LocalAlloc(LMEM_FIXED,readsize);

	pFile->Read(pDlg->m_pData[index],readsize);
		
	delete pFile;
	delete pFtpCon;
	delete pSession;
	
	pDlg->m_pEvent[index].SetEvent();

	return 0;
}


void CFtpDownDlg::OnDownload() 
{
	UpdateData(TRUE);
	
	if (m_Dir.IsEmpty())
	{
		MessageBox("请输入下载路径");
		return;
	}

	CInternetSession * pSession = new CInternetSession;
	CHttpConnection * pFtpCon = pSession->GetHttpConnection("127.0.0.1");

	CInternetFile* pFile = (CInternetFile*)pSession->OpenURL(m_Dir,1,INTERNET_FLAG_TRANSFER_BINARY|INTERNET_FLAG_RELOAD);

	DWORD len = pFile->SeekToEnd();
	//确定划分几个线程下载
	
	//每个线程应下载的文件大小
	m_PerFileSize=  len / m_ThreadCount;	
	m_EndFileSize = m_PerFileSize+ len % m_ThreadCount;

	delete pFile;
	delete pFtpCon;
	delete pSession;
	int pos = m_Dir.ReverseFind('/');
	
	CString filename =  m_Dir.Right(m_Dir.GetLength()-pos-1);
	
	m_List.InsertItem(m_List.GetItemCount(),"");
	m_List.SetItemText(m_List.GetItemCount()-1,0,filename);

	CString time = CTime::GetCurrentTime().Format("%H:%M:%S");
	m_List.SetItemText(m_List.GetItemCount()-1,1,time);	

	m_List.SetItemText(m_List.GetItemCount()-1,2,"C:\\"+filename);	


	for (int i = 0; i<m_ThreadCount; i++)
	{
		int* temp =  new int ;
		*temp = i;

		m_pEvent[i].ResetEvent();
		m_pHthread[i] = CreateThread(NULL,0,ThreadProc,temp,0,NULL);
	
	}
	for (int n = 0 ; n< m_ThreadCount; n++)
	{
		WaitForSingleObject(m_pEvent[n],INFINITE);
	}
	
	CFile file ("c:\\"+filename,CFile::modeCreate|CFile::modeWrite);
	
	DWORD readsize;
	
	for (int m = 0; m<m_ThreadCount; m++)
	{
		if (m < m_ThreadCount-1)
			readsize = m_PerFileSize;
		else
			readsize = m_EndFileSize;
		file.Write(m_pData[m],readsize);
	}
	delete[] m_pData;
	m_pData = new void*[m_ThreadCount];	
}

void CFtpDownDlg::OnCancel()
{
	delete[] m_pData;
	delete[] m_pHthread;
	delete[] m_pEvent;
	CDialog::OnCancel();
}
