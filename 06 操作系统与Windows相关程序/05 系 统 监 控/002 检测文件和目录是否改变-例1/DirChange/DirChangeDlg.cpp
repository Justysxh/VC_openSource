// DirChangeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DirChange.h"
#include "DirChangeDlg.h"

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
// CDirChangeDlg dialog

CDirChangeDlg::CDirChangeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDirChangeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDirChangeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDirChangeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDirChangeDlg)
	DDX_Control(pDX, IDC_EDIT1, m_path);
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDirChangeDlg, CDialog)
	//{{AFX_MSG_MAP(CDirChangeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, OnStrart)
	ON_BN_CLICKED(IDC_BUTTON3, OnClose)
	ON_BN_CLICKED(IDC_BUTTON1, OnSelectDir)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDirChangeDlg message handlers

BOOL CDirChangeDlg::OnInitDialog()
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
	
	m_list.ModifyStyle(LVS_TYPEMASK,LVS_REPORT);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_FLATSB|LVS_EX_TWOCLICKACTIVATE |LVS_EX_GRIDLINES);
	m_list.InsertColumn(0,"数量",LVCFMT_LEFT,40);
	m_list.InsertColumn(1,"时间",LVCFMT_LEFT,80);
	m_list.InsertColumn(2,"类型",LVCFMT_LEFT,100);
	m_list.InsertColumn(3,"变化的内容",LVCFMT_LEFT,500);

	m_i=0;
	m_szi=new char[MAX_PATH];
	itoa(m_i,m_szi,10);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDirChangeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDirChangeDlg::OnPaint() 
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
HCURSOR CDirChangeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

DWORD WINAPI CDirChangeDlg::ThreadProc( LPVOID lParam )
{
	CDirChangeDlg* obj = (CDirChangeDlg*)lParam;  //参数转化
	
	obj->hDir = CreateFile(            //打开目录，得到目录的句柄
		obj->m_strWatchedDir,
		GENERIC_READ|GENERIC_WRITE,
		FILE_SHARE_READ|FILE_SHARE_WRITE|FILE_SHARE_DELETE,
		NULL,
		OPEN_EXISTING,
		FILE_FLAG_BACKUP_SEMANTICS,
		NULL
        ); 
	if(obj->hDir ==INVALID_HANDLE_VALUE  ) 
		return false;
	
	char buf[(sizeof(FILE_NOTIFY_INFORMATION)+MAX_PATH)*2];
	FILE_NOTIFY_INFORMATION* pNotify=(FILE_NOTIFY_INFORMATION*)buf;
	DWORD dwBytesReturned;        
	while(true)
	{
		if(::ReadDirectoryChangesW( obj->hDir,
			pNotify,
			sizeof(buf),
			true,
			FILE_NOTIFY_CHANGE_FILE_NAME|
			FILE_NOTIFY_CHANGE_DIR_NAME|
			FILE_NOTIFY_CHANGE_ATTRIBUTES|
			FILE_NOTIFY_CHANGE_SIZE|
			FILE_NOTIFY_CHANGE_LAST_WRITE|
			FILE_NOTIFY_CHANGE_LAST_ACCESS|
			FILE_NOTIFY_CHANGE_CREATION|
			FILE_NOTIFY_CHANGE_SECURITY,
			&dwBytesReturned,
			NULL,
			NULL ) )
		{
			char tmp[MAX_PATH], str1[MAX_PATH], str2[MAX_PATH];
			memset( tmp, 0, sizeof(tmp) ); 
			WideCharToMultiByte( CP_ACP,0,pNotify->FileName,pNotify->FileNameLength/2,tmp,99,NULL,NULL );
			strcpy( str1, tmp );
	
			if(pNotify->NextEntryOffset !=0 )
			{
				PFILE_NOTIFY_INFORMATION p = (PFILE_NOTIFY_INFORMATION)((char*)pNotify+pNotify->NextEntryOffset);
				memset( tmp, 0, sizeof(tmp) );
				WideCharToMultiByte( CP_ACP,0,p->FileName,p->FileNameLength/2,tmp,99,NULL,NULL );
				strcpy( str2, tmp );
			}
			switch(pNotify->Action)
			{				
				case FILE_ACTION_ADDED:
					{
						CTime tt=CTime::GetCurrentTime();	
						CString strTT;
						strTT.Format("%d:%d:%d",tt.GetHour(),tt.GetMinute(),tt.GetSecond());
						obj->m_list.InsertItem(0,obj->m_szi);
						obj->m_list.SetItemText(0,2,"添加了新文件");
						obj->m_list.SetItemText(0,3,str1);
						obj->m_list.SetItemText(0,1,strTT);
					}
					break;
			
				case FILE_ACTION_REMOVED:
					{
						CTime tt=CTime::GetCurrentTime();	
						CString strTT;
						strTT.Format("%d:%d:%d",tt.GetHour(),tt.GetMinute(),tt.GetSecond());
						obj->m_list.InsertItem(0,obj->m_szi);
						obj->m_list.SetItemText(0,2,"删除了文件");
						obj->m_list.SetItemText(0,3,str1);
						obj->m_list.SetItemText(0,1,strTT);
					}
					break;

				case FILE_ACTION_RENAMED_NEW_NAME:
					{
						CTime tt=CTime::GetCurrentTime();	
						CString strTT;
						strTT.Format("%d:%d:%d",tt.GetHour(),tt.GetMinute(),tt.GetSecond());
						obj->m_list.InsertItem(0,obj->m_szi);
						obj->m_list.SetItemText(0,2,"重命名了文件");
						strcat(str1,"->");
						obj->m_list.SetItemText(0,3,strcat(str1,str2));
						obj->m_list.SetItemText(0,1,strTT);
					}
					break;
		
				case FILE_ACTION_RENAMED_OLD_NAME:
					{
						CTime tt=CTime::GetCurrentTime();	
						CString strTT;
						strTT.Format("%d:%d:%d",tt.GetHour(),tt.GetMinute(),tt.GetSecond());
						obj->m_list.InsertItem(0,obj->m_szi);
						obj->m_list.SetItemText(0,2,"重命名了文件");
						strcat(str1," 改名为 ");
						obj->m_list.SetItemText(0,3,strcat(str1,str2));
						obj->m_list.SetItemText(0,1,strTT);
					}
					break;

				case FILE_ACTION_MODIFIED:
					{
						CTime tt=CTime::GetCurrentTime();	
						CString strTT;
						strTT.Format("%d:%d:%d",tt.GetHour(),tt.GetMinute(),tt.GetSecond());
						obj->m_list.InsertItem(0,obj->m_szi);
						obj->m_list.SetItemText(0,2,"修改了文件");
						obj->m_list.SetItemText(0,3,str1);
						obj->m_list.SetItemText(0,1,strTT);
					}
					break;  
					
				default:
					{
						CTime tt=CTime::GetCurrentTime();	
						CString strTT;
						strTT.Format("%d:%d:%d",tt.GetHour(),tt.GetMinute(),tt.GetSecond());
						obj->m_list.InsertItem(0,obj->m_szi);
						obj->m_list.SetItemText(0,2,"未知变化");
						obj->m_list.SetItemText(0,3,"");
						obj->m_list.SetItemText(0,1,strTT);
					}
					break;  
			}	
			obj->m_i++;		
			itoa(obj->m_i,obj->m_szi,10);
		
		}
		else           
			break;           
	}
	return 0;
}

void CDirChangeDlg::OnStrart() 
{
	StartThread();		
}

void CDirChangeDlg::OnClose() 
{
	EndThread();
	CDialog::OnCancel();
}

bool CDirChangeDlg::StartThread()
{
	m_path.GetWindowText(m_strWatchedDir);
	if (m_strWatchedDir.IsEmpty())
		m_strWatchedDir = "c:\\";
	
	DWORD ThreadId;  //创建一个新线程用于监视
	m_hThread=::CreateThread(NULL,0,ThreadProc,this,0,&ThreadId );
	
	return NULL!=m_hThread;
}

bool CDirChangeDlg::EndThread()
{
	if(m_hThread !=NULL)
	{
		::TerminateThread(m_hThread, 0 );
		m_hThread = NULL;
	}
	if(hDir !=INVALID_HANDLE_VALUE)
	{
		CloseHandle( hDir );
		hDir = INVALID_HANDLE_VALUE;
	}
	return true;
}

bool CDirChangeDlg::OpenDir(char *pStartPath)
{
	LPMALLOC pMalloc;
	if(SHGetMalloc(&pMalloc)!=NOERROR)
		return false;
	/*if(pStartPath && IsValuePath(pStartPath))
	{
		char *pStr=m_pDirPath;
		while(*pStr++=*pStartPath++);
	}*/
	BROWSEINFO bInfo={this->m_hWnd,NULL,0,"请选择文件夹:",0,NULL,NULL,0};
	ITEMIDLIST *pItemList=SHBrowseForFolder(&bInfo);
	if(pItemList)
	{
		SHGetPathFromIDList(pItemList,pStartPath);
		pMalloc->Free(pItemList);
		pMalloc->Release();
		return TRUE;
	}
	pMalloc->Free(pItemList);
	pMalloc->Release();
	return false;
}

void CDirChangeDlg::OnSelectDir() 
{
	CString dir;
	OpenDir(dir.GetBuffer(0));
	if ("" != dir)
		m_path.SetWindowText(dir);
}
