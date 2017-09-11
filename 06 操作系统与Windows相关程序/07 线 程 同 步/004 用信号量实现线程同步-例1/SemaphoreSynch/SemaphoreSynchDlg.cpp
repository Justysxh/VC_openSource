// SemaphoreSynchDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SemaphoreSynch.h"
#include "SemaphoreSynchDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "afxmt.h"
HANDLE hSema;

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
// CSemaphoreSynchDlg dialog

CSemaphoreSynchDlg::CSemaphoreSynchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSemaphoreSynchDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSemaphoreSynchDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSemaphoreSynchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSemaphoreSynchDlg)
	DDX_Control(pDX, IDC_POS, m_pos);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSemaphoreSynchDlg, CDialog)
	//{{AFX_MSG_MAP(CSemaphoreSynchDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTSOURCE, OnAddSource)
	ON_BN_CLICKED(IDC_BTDES, OnAddDes)
	ON_BN_CLICKED(IDC_BTCOPY, OnCopy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSemaphoreSynchDlg message handlers

BOOL CSemaphoreSynchDlg::OnInitDialog()
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
	
	hSema=CreateSemaphore(NULL,1,1,NULL);
	m_pos.SetRange(0,100);
	m_pos.SetPos(0);
	poslen=0;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSemaphoreSynchDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSemaphoreSynchDlg::OnPaint() 
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
HCURSOR CSemaphoreSynchDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

static UINT thread1(LPVOID pParam)
{
	WaitForSingleObject(hSema,INFINITE);
	CSemaphoreSynchDlg *pdlg=(CSemaphoreSynchDlg*)pParam;
	CString tmp;tmp=pdlg->sourcename;
	CFile* readfile;
	readfile=new CFile(tmp,CFile::modeRead);
	readfile->Seek(pdlg->poslen,CFile::begin);
	pdlg->readlen=readfile->Read(pdlg->pvData,512);
	pdlg->poslen+=pdlg->readlen;
	readfile->Close();
	delete readfile;
	ReleaseSemaphore(hSema,1,NULL);
	return 0;
}
static UINT thread2(LPVOID pParam)
{
	WaitForSingleObject(hSema,INFINITE);
	CSemaphoreSynchDlg *pdlg=(CSemaphoreSynchDlg*)pParam;
	CFile* writefile;
	writefile=new CFile(pdlg->desname,CFile::modeWrite);
	writefile->SeekToEnd();
	writefile->Write(pdlg->pvData,pdlg->readlen);
	writefile->Close();
	delete writefile;
	ReleaseSemaphore(hSema,1,NULL);
	return 0;
}




void CSemaphoreSynchDlg::OnAddSource() 
{
	CFileDialog log(TRUE,"文件","*.*",OFN_HIDEREADONLY,"FILE(*.*)|*.*||",NULL);
	if(log.DoModal()==IDOK)
	{
		sourcename=log.GetPathName();
		filename=log.GetFileName();
		GetDlgItem(IDC_EDSOURCE)->SetWindowText(sourcename);
	}
}

void CSemaphoreSynchDlg::OnAddDes() 
{
	if(sourcename.IsEmpty())
		return;
	BROWSEINFO bi;   
	char buffer[MAX_PATH];   
	ZeroMemory(buffer,MAX_PATH);   
	bi.hwndOwner=GetSafeHwnd();   
	bi.pidlRoot=NULL;   
	bi.pszDisplayName=buffer;   
	bi.lpszTitle="选择一个文件夹";   
	bi.ulFlags=BIF_EDITBOX;   
	bi.lpfn=NULL;   
	bi.lParam=0;   
	bi.iImage=0; 
	LPITEMIDLIST pList=NULL;   
	if((pList=SHBrowseForFolder(&bi))!=NULL)   
	{   
		char path[MAX_PATH];
		ZeroMemory(path,MAX_PATH);
		SHGetPathFromIDList(pList,path);
		desname=path;
		if(desname.Right(1)!="\\")
		desname.Format("%s\\%s",path,filename);
		else
		desname.Format("%s%s",path,filename);
		GetDlgItem(IDC_EDDES)->SetWindowText(desname);
	}
}

void CSemaphoreSynchDlg::OnCopy() 
{
	HANDLE hfile=::CreateFile(desname,GENERIC_WRITE|GENERIC_WRITE,0,0,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);
	CloseHandle(hfile);
	CFileStatus status;
	CFile::GetStatus(sourcename,status);
	filelen=status.m_size;
	//计算文件的百分之一大小
	ldiv_t r;
	r=ldiv(filelen,100);
	long pos=r.quot;
	//保存递增的百分比大小
	long ipos;
	ipos=pos;
	int i=0;
	hGlobal = GlobalAlloc(GMEM_MOVEABLE,512);
	pvData = GlobalLock(hGlobal);
	
	while(1)
	{
		AfxBeginThread(thread1,this);
		AfxBeginThread(thread2,this);
		if(poslen>ipos)
		{
			ipos+=pos;
			i++;
		}
		m_pos.SetPos(i);
		if(poslen==filelen)
				break;
	}
	GlobalUnlock(hGlobal);
	AfxMessageBox("复制完成");
}
