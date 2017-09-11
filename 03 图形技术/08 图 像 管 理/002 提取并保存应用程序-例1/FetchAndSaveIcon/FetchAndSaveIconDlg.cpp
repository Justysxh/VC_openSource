// FetchAndSaveIconDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FetchAndSaveIcon.h"
#include "FetchAndSaveIconDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

extern LPSTR m_iconname;

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
// CFetchAndSaveIconDlg dialog


CFetchAndSaveIconDlg::CFetchAndSaveIconDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFetchAndSaveIconDlg::IDD, pParent)
{

	m_lpdir= NULL;
	m_lpdirentry= NULL;
//	m_lpicondata= NULL;
	//{{AFX_DATA_INIT(CFetchAndSaveIconDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
;

}

void CFetchAndSaveIconDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFetchAndSaveIconDlg)
	DDX_Control(pDX, IDC_DEMOSTATE, m_demoicon);
	DDX_Control(pDX, IDC_FILENAME, m_filename);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFetchAndSaveIconDlg, CDialog)
	//{{AFX_MSG_MAP(CFetchAndSaveIconDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BROWN, OnBrown)
	ON_BN_CLICKED(IDC_FETCH, OnFetch)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFetchAndSaveIconDlg message handlers

BOOL CFetchAndSaveIconDlg::OnInitDialog()
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

void CFetchAndSaveIconDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFetchAndSaveIconDlg::OnPaint() 
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
HCURSOR CFetchAndSaveIconDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFetchAndSaveIconDlg::OnOK() 
{
	// TODO: Add extra validation here
	//CDialog::OnOK();
}

void CFetchAndSaveIconDlg::OnBrown() 
{
	CFileDialog m_fdlg(TRUE,"exe",NULL,NULL,"可执行文件(.exe)|*.exe",this);
	if (m_fdlg.DoModal()==IDOK)
	{
		m_filename.SetWindowText(m_fdlg.GetPathName());
	}
}

//提取应用程序图标
void CFetchAndSaveIconDlg::OnFetch() 
{
	CString str;
	m_filename.GetWindowText(str);
	if (!str.IsEmpty())
	{
		HICON m_hicon;
		m_hicon = ::ExtractIcon(AfxGetInstanceHandle(),str,0);
		if (m_hicon != NULL)
		{
			m_demoicon.SetIcon(m_hicon);
		}
	}
}

BOOL CALLBACK EnumResNameProc( HANDLE hModule,  LPCTSTR lpszType,  LPTSTR lpszName, LONG lParam )
{	
	//如果高字节为零,低字节表示图标ID
	if (HIWORD(lpszName)==0)
	{
		m_iconname = MAKEINTRESOURCE(LOWORD(lpszName));
	}
	else //如果高字节不为零,整个lpszName为图标name
	{
		//m_iconname = lpszName;
		m_iconname = strdup(lpszName);
		//strcpy(m_iconname,lpszName);	
	}
	return true;
}

void CFetchAndSaveIconDlg::OnSave() 
{
	CFileDialog m_savedlg (FALSE,"ico",NULL,NULL,"图标(.ico)|*.ico",this);
	
	if (m_savedlg.DoModal()==IDOK)
	{
		CString str = m_savedlg.GetPathName();
		if(!str.IsEmpty())
		{						
		
			CFile m_file (str,CFile::modeCreate|CFile::typeBinary|CFile::modeWrite);
			
			HICON hicon;
			
			CString name;
			m_filename.GetWindowText(name);
			HMODULE hmodule = LoadLibraryEx(name, NULL, LOAD_LIBRARY_AS_DATAFILE);
			
			EnumResourceNames(hmodule,RT_GROUP_ICON,( ENUMRESNAMEPROC)EnumResNameProc,LONG(GetSafeHwnd()));

			hicon  = (HICON)FindResource(hmodule,m_iconname,RT_GROUP_ICON);
		
			HGLOBAL global=LoadResource(hmodule,(HRSRC)hicon );
			
			if (global!= NULL)
			{
				m_lpMemDir = (LPMEMICONDIR)LockResource(global);			
			}
			
			lpicondir temp = (lpicondir)m_lpMemDir;
			m_lpdir = (lpicondir)m_lpMemDir;

			DWORD factsize;
			
			//写入文件头
			WORD a = m_lpdir->idreserved;
			m_file.Write(&a,sizeof(WORD));

			a = m_lpdir->idtype;
			m_file.Write(&a,sizeof(WORD));
	
			a = m_lpdir->idcount;
			m_file.Write(&a,sizeof(WORD));

			m_lpdir = NULL;

			//写入索引目录
			icondirentry entry;

			for (int i = 0; i<temp->idcount;i++)
			{
				DWORD size;
				DWORD imagesize= GetImageOffset(hmodule,i,size);
				free(m_lpData);
				entry.bheight = m_lpMemDir->idEntries[i].bHeight;
				entry.bwidth = m_lpMemDir->idEntries[i].bWidth;
				entry.breserved = 0;
				entry.bcolorcount = m_lpMemDir->idEntries[i].bColorCount;
				entry.dwbytesinres =m_lpMemDir->idEntries[i].dwBytesInRes;

				entry.dwimageoffset = imagesize;
				entry.wbitcount = m_lpMemDir->idEntries[i].wBitCount;
				entry.wplanes = m_lpMemDir->idEntries[i].wPlanes;	
				
				m_file.Write(&entry,sizeof(entry));
			}			
			//写入图像数据
			for (int j = 0; j<temp->idcount;j++)
			{
				LPBYTE pInfo;
				DWORD size;
				DWORD imagesize= GetImageOffset(hmodule,j,size,pInfo);		
				m_file.Write((LPBYTE)m_lpData,size);
				
				free(m_lpData);
			}

			UnlockResource(global);	
			FreeLibrary(hmodule);

			m_file.Close();	
		}	
	}
}

DWORD CFetchAndSaveIconDlg::GetImageOffset(HMODULE hmodule ,UINT index,DWORD& cursize ,LPBYTE pbitinfo )
{
	DWORD imagesize=0; 
	HRSRC himage;

	HGLOBAL gimage;
	imagesize = sizeof(WORD)*3+sizeof(icondirentry)*m_lpMemDir->idCount;

	//计算图像数据的偏移量
	for (int j=0; j<index;j++)
	{
		himage= FindResource(hmodule,MAKEINTRESOURCE(m_lpMemDir->idEntries[j].nID),RT_ICON);
		if (himage ==NULL)
			return 0;
		gimage= LockResource(himage);
		imagesize+= SizeofResource(hmodule,himage);
		UnlockResource(gimage);
	}	
	himage= FindResource(hmodule,MAKEINTRESOURCE(m_lpMemDir->idEntries[index].nID),RT_ICON);
	gimage= LoadResource(hmodule,himage);
	DWORD  size= SizeofResource(hmodule,himage);

	m_lpData =  (LPBYTE)malloc(size);

	if (cursize != NULL)
		cursize = size;
	memcpy(m_lpData ,LockResource(gimage),size);	
	UnlockResource(gimage);

	return imagesize;
}
