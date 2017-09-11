// ThreadSynchDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ThreadSynch.h"
#include "ThreadSynchDlg.h"

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
// CThreadSynchDlg dialog

CThreadSynchDlg::CThreadSynchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CThreadSynchDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CThreadSynchDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CThreadSynchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CThreadSynchDlg)
	DDX_Control(pDX, IDC_POSG, m_posg);
	DDX_Control(pDX, IDC_POSF, m_posf);
	DDX_Control(pDX, IDC_POSE, m_pose);
	DDX_Control(pDX, IDC_POSD, m_posd);
	DDX_Control(pDX, IDC_POSC, m_posc);
	DDX_Control(pDX, IDC_POSB, m_posb);
	DDX_Control(pDX, IDC_POSA, m_posa);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CThreadSynchDlg, CDialog)
	//{{AFX_MSG_MAP(CThreadSynchDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTWRITEA, OnWriteA)
	ON_BN_CLICKED(IDC_BTWRITEB, OnWriteB)
	ON_BN_CLICKED(IDC_BTWRITEC, OnWriteC)
	ON_BN_CLICKED(IDC_BTWRITED, OnWriteD)
	ON_BN_CLICKED(IDC_BTWRITEE, OnWriteE)
	ON_BN_CLICKED(IDC_BTWRITEF, OnWriteF)
	ON_BN_CLICKED(IDC_BTWRITEG, OnWriteG)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThreadSynchDlg message handlers

BOOL CThreadSynchDlg::OnInitDialog()
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

void CThreadSynchDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CThreadSynchDlg::OnPaint() 
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
HCURSOR CThreadSynchDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
DWORD WINAPI thread(LPVOID pParam)
{
	CThreadSynchDlg* pdlg=(CThreadSynchDlg*)pParam;
	CString strtmp=pdlg->str;
	CString path=pdlg->path;
	FILE* pf;
	pf=fopen(path.GetBuffer(0),"a");
	
	CProgressCtrl*p;
	if(strtmp=="A")p=(CProgressCtrl*)(&pdlg->m_posa);
	if(strtmp=="B")p=(CProgressCtrl*)(&pdlg->m_posb);
	if(strtmp=="C")p=(CProgressCtrl*)(&pdlg->m_posc);
	if(strtmp=="D")p=(CProgressCtrl*)(&pdlg->m_posd);
	if(strtmp=="E")p=(CProgressCtrl*)(&pdlg->m_pose);
	if(strtmp=="F")p=(CProgressCtrl*)(&pdlg->m_posf);
	if(strtmp=="G")p=(CProgressCtrl*)(&pdlg->m_posg);
	

	for(int i=0;i<100;i++)
	{
		fprintf(pf,"%s",strtmp);
		p->SetPos(i);
		Sleep(20);
	}
	fclose(pf);
		return 0;
}
void CThreadSynchDlg::OnWriteA() 
{
	char buf[256];
	::GetCurrentDirectory(256,buf);
	strcat(buf,"\\a.txt");
	HANDLE hfile=::CreateFile(buf,GENERIC_WRITE|GENERIC_WRITE,0,0,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);
	CloseHandle(hfile);
	str="A";
	path.Format("%s",buf);
	DWORD nThreadId;
	HANDLE handle=CreateThread(NULL,0,thread,(LPVOID)this,CREATE_SUSPENDED,&nThreadId );
	//设置优先级为高于正常
	SetThreadPriority(handle,THREAD_PRIORITY_ABOVE_NORMAL);
	ResumeThread(handle);
}

void CThreadSynchDlg::OnWriteB() 
{
	char buf[256];
	::GetCurrentDirectory(256,buf);
	strcat(buf,"\\b.txt");
	HANDLE hfile=::CreateFile(buf,GENERIC_WRITE|GENERIC_WRITE,0,0,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);
	CloseHandle(hfile);
	str="B";
	path.Format("%s",buf);
	DWORD nThreadId;
	HANDLE handle=CreateThread(NULL,0,thread,(LPVOID)this,CREATE_SUSPENDED,&nThreadId );
	//设置优先级为低于正常
	SetThreadPriority(handle,THREAD_PRIORITY_BELOW_NORMAL);
	ResumeThread(handle);
}

void CThreadSynchDlg::OnWriteC() 
{
	char buf[256];
	::GetCurrentDirectory(256,buf);
	strcat(buf,"\\c.txt");
	HANDLE hfile=::CreateFile(buf,GENERIC_WRITE|GENERIC_WRITE,0,0,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);
	CloseHandle(hfile);
	str="C";
	path.Format("%s",buf);
	DWORD nThreadId;
	HANDLE handle=CreateThread(NULL,0,thread,(LPVOID)this,CREATE_SUSPENDED,&nThreadId );
	//设置优先级为最高
	SetThreadPriority(handle,THREAD_PRIORITY_HIGHEST);
	ResumeThread(handle);
}

void CThreadSynchDlg::OnWriteD() 
{
	char buf[256];
	::GetCurrentDirectory(256,buf);
	strcat(buf,"\\d.txt");
	HANDLE hfile=::CreateFile(buf,GENERIC_WRITE|GENERIC_WRITE,0,0,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);
	CloseHandle(hfile);
	str="D";
	path.Format("%s",buf);
	DWORD nThreadId;
	HANDLE handle=CreateThread(NULL,0,thread,(LPVOID)this,CREATE_SUSPENDED,&nThreadId );
	//设置优先级为空闲
	SetThreadPriority(handle,THREAD_PRIORITY_IDLE);
	ResumeThread(handle);
}

void CThreadSynchDlg::OnWriteE() 
{
	char buf[256];
	::GetCurrentDirectory(256,buf);
	strcat(buf,"\\e.txt");
	HANDLE hfile=::CreateFile(buf,GENERIC_WRITE|GENERIC_WRITE,0,0,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);
	CloseHandle(hfile);
	str="E";
	path.Format("%s",buf);
	DWORD nThreadId;
	HANDLE handle=CreateThread(NULL,0,thread,(LPVOID)this,CREATE_SUSPENDED,&nThreadId );
	SetThreadPriority(handle,THREAD_PRIORITY_LOWEST);
	//设置优先级为最低
	ResumeThread(handle);
}

void CThreadSynchDlg::OnWriteF() 
{
	char buf[256];
	::GetCurrentDirectory(256,buf);
	strcat(buf,"\\f.txt");
	HANDLE hfile=::CreateFile(buf,GENERIC_WRITE|GENERIC_WRITE,0,0,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);
	CloseHandle(hfile);
	str="F";
	path.Format("%s",buf);
	DWORD nThreadId;
	HANDLE handle=CreateThread(NULL,0,thread,(LPVOID)this,CREATE_SUSPENDED,&nThreadId );
	//设置优先级为正常
	SetThreadPriority(handle,THREAD_PRIORITY_NORMAL);
	ResumeThread(handle);
}

void CThreadSynchDlg::OnWriteG() 
{
	char buf[256];
	::GetCurrentDirectory(256,buf);
	strcat(buf,"\\g.txt");
	HANDLE hfile=::CreateFile(buf,GENERIC_WRITE|GENERIC_WRITE,0,0,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);
	CloseHandle(hfile);
	str="G";
	path.Format("%s",buf);
	DWORD nThreadId;
	HANDLE handle=CreateThread(NULL,0,thread,(LPVOID)this,CREATE_SUSPENDED,&nThreadId );
	//设置优先级为关键
	SetThreadPriority(handle,THREAD_PRIORITY_TIME_CRITICAL);
	ResumeThread(handle);
}
