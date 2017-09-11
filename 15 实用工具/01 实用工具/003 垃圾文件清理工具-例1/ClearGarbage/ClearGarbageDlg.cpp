// ClearGarbageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ClearGarbage.h"
#include "ClearGarbageDlg.h"

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
// CClearGarbageDlg dialog

CClearGarbageDlg::CClearGarbageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClearGarbageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClearGarbageDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
	m_hThread = NULL;
	m_bFinding = FALSE;
}

void CClearGarbageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClearGarbageDlg)
	DDX_Control(pDX, IDC_DELETEINFO, m_DeleteLog);
	DDX_Control(pDX, IDC_FINDPROGRESS, m_FindProgress);
	DDX_Control(pDX, IDC_SCANEINFO, m_ScaneInfo);
	DDX_Control(pDX, IDC_DISK, m_Disk);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClearGarbageDlg, CDialog)
	//{{AFX_MSG_MAP(CClearGarbageDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SELECTALL, OnSelectall)
	ON_BN_CLICKED(IDC_CANCEL_SEL_ALL, OnCancelSelAll)
	ON_BN_CLICKED(IDC_BEGIN_SCANE, OnBeginScane)
	ON_BN_CLICKED(IDC_STOP_SCANE, OnStopScane)
	ON_BN_CLICKED(IDC_DELETE_ALL, OnDeleteAll)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClearGarbageDlg message handlers

BOOL CClearGarbageDlg::OnInitDialog()
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
	

	m_ScaneInfo.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_ScaneInfo.InsertColumn(0, "文件名称", LVCFMT_LEFT, 250);

	m_DeleteLog.SendMessage(LB_SETHORIZONTALEXTENT, 1000, 0);

	EnumDisks();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CClearGarbageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CClearGarbageDlg::OnPaint() 
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
HCURSOR CClearGarbageDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CClearGarbageDlg::OnOK() 
{

}

void CClearGarbageDlg::EnumDisks()
{
	m_Disk.ResetContent();
	//获取磁盘字符串的大小
	DWORD dwDiskLen = GetLogicalDriveStrings(0, NULL);
	HANDLE hProcess = GetProcessHeap();
	LPSTR lpDisk= (LPSTR) HeapAlloc(hProcess, HEAP_ZERO_MEMORY, dwDiskLen);
	GetLogicalDriveStrings(dwDiskLen, lpDisk);
	LPSTR lpTmp = lpDisk;
	while (*lpTmp != 0)
	{
		m_Disk.AddString(lpTmp);
		lpTmp += strlen(lpTmp) + 1;
	}
	HeapFree(hProcess, HEAP_NO_SERIALIZE, lpDisk);
	m_Disk.SetCurSel(0);
}


//全部选中临时文件类型的复选框
void CClearGarbageDlg::OnSelectall() 
{
	int nCheckID = IDC_TMP1;
	CButton* pBtn = NULL;
	for(int i= 0; i<20; i++, nCheckID ++)
	{	
		pBtn = (CButton*)GetDlgItem(nCheckID);
		if (pBtn != NULL)
		{
			pBtn->SetCheck(TRUE);
		}
	}
}

//取消选中复选框
void CClearGarbageDlg::OnCancelSelAll() 
{
	int nCheckID = IDC_TMP1;
	CButton* pBtn = NULL;
	for(int i= 0; i<20; i++, nCheckID ++)
	{	
		pBtn = (CButton*)GetDlgItem(nCheckID);
		if (pBtn != NULL)
		{
			pBtn->SetCheck(FALSE);
		}
	}	
}

//获取临时文件扩展名
void CClearGarbageDlg::GetTmpExtendedName()
{
	//移除所有内容
	m_FilterList.RemoveAll();
	int nCheckID = IDC_TMP1;
	CButton* pBtn = NULL;
	CString szText;
	int nState = 0;
	for(int i= 0; i<20; i++, nCheckID ++)
	{	
		pBtn = (CButton*)GetDlgItem(nCheckID);
		if (pBtn != NULL)
		{
			nState = pBtn->GetCheck();
			if (nState)
			{
				pBtn->GetWindowText(szText);
				m_FilterList.AddTail(szText);
			}
		}
	}		
}

DWORD __stdcall ThreadProc(LPVOID lpParameter)
{
	CClearGarbageDlg* pDlg = (CClearGarbageDlg*) lpParameter;
	pDlg->m_bFinding = TRUE;
	pDlg->ResearchFile(pDlg->m_szScaneDisk);
	pDlg->m_FindProgress.SetWindowText("查找结束!");
	pDlg->m_bFinding = FALSE;

	return 0;
}

void CClearGarbageDlg::OnBeginScane() 
{
	if (m_bFinding == FALSE)
	{
		m_ScaneInfo.DeleteAllItems();
		GetTmpExtendedName();
		m_bStopFind = FALSE;
		m_Disk.GetWindowText(m_szScaneDisk);
		m_FindProgress.SetWindowText("查找进行中...");
		m_hThread = CreateThread(NULL, 0, ThreadProc, this, 0, NULL);
	}
}

//查找文件
void CClearGarbageDlg::ResearchFile(CString szPath)
{
	CString strtemp;
	if(szPath.Right(1)!="\\")
	strtemp.Format("%s\\*.*",szPath);
	else
	strtemp.Format("%s*.*",szPath);
	CFileFind findfile;
	BOOL bfind=findfile.FindFile(strtemp);
	CString szRetName;
	while(bfind)
	{
		if (m_bStopFind)	//结束查找	
		{
			return;
		}
		bfind=findfile.FindNextFile();
		szRetName = findfile.GetFileName();
		if (IsTmpFile(szRetName))
		{
			CString szFullName = findfile.GetFilePath();
			int nCount = m_ScaneInfo.GetItemCount();
			int nIndex = m_ScaneInfo.InsertItem(nCount, "");
			m_ScaneInfo.SetItemText(nIndex, 0, szFullName);
		
		}
		if(findfile.IsDirectory()&&!findfile.IsDots())
		{
			ResearchFile(findfile.GetFilePath());
		}
	}

}

//判断是否为临时文件
BOOL CClearGarbageDlg::IsTmpFile(CString szFileName)
{

	for (POSITION pos = m_FilterList.GetHeadPosition(); pos != NULL;)
	{
		//获取临时文件
		CString szFilter = m_FilterList.GetNext(pos);
		//去除“*.”
		int nPos = szFilter.ReverseFind('.');
		
		CString szTmpExtended = szFilter.Right(szFilter.GetLength() - nPos - 1);

		int nFilterLen = szTmpExtended.GetLength();

		int nExtendedName = szFileName.ReverseFind('.');
		if (nExtendedName == -1)
		{
			return FALSE;
		}
		nExtendedName = szFileName.GetLength() - nExtendedName - 1;


		int nNameLen = szFileName.GetLength();
		if (nExtendedName == nFilterLen)
		{
			CString szName =  szFileName.Right(nFilterLen);
			if (szName.CompareNoCase(szTmpExtended) == 0)
		//	if (szName == szTmpExtended)
			{
				return TRUE;
			}
		}
	}
	return FALSE;
}

void CClearGarbageDlg::OnStopScane() 
{
	if (m_bFinding)
	{
		m_bStopFind = TRUE;
		m_bFinding = FALSE;

	}
}

void CClearGarbageDlg::OnDeleteAll() 
{
	if (m_bFinding)
	{
		MessageBox("查找进行中，不能删除文件!");
		return;
	}
	if (MessageBox("确实要删除所有文件吗?", "提示", MB_YESNO) == IDYES)
	{
		CString szFileName = "";
		int nFileCount = m_ScaneInfo.GetItemCount();
		m_DeleteLog.ResetContent();
		for (int i=0; i<nFileCount; i++)
		{
			szFileName = m_ScaneInfo.GetItemText(i, 0);
			if (!DeleteFile(szFileName))
			{
				m_DeleteLog.AddString(szFileName + "文件删除失败!");
			}
			
		}
	}
}

void CClearGarbageDlg::OnExit() 
{
	CDialog::OnCancel();	
}
