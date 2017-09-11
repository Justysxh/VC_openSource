// DiskCataDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DiskCata.h"
#include "DiskCataDlg.h"

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
// CDiskCataDlg dialog

CDiskCataDlg::CDiskCataDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDiskCataDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDiskCataDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDiskCataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDiskCataDlg)
	DDX_Control(pDX, IDC_TRDISKTREE, m_trdisktree);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDiskCataDlg, CDialog)
	//{{AFX_MSG_MAP(CDiskCataDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TVN_SELCHANGED, IDC_TRDISKTREE, OnSelchangedTrdisktree)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiskCataDlg message handlers

BOOL CDiskCataDlg::OnInitDialog()
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
	SetIcon(m_hIcon, FALSE);
	// Set small icon

	imlst.Create(16,16,ILC_COLOR32|ILC_MASK,0,0);
	m_trdisktree.SetImageList(&imlst,TVSIL_NORMAL);
	m_trdisktree.ModifyStyle(0L,TVS_HASLINES|TVS_LINESATROOT);
	size_t alldriver=::GetLogicalDriveStrings(0,NULL);
	_TCHAR *driverstr;
	driverstr=new _TCHAR[alldriver+sizeof(_T(""))];
	if(GetLogicalDriveStrings(alldriver,driverstr)!=alldriver-1)
		return FALSE;
	_TCHAR *pdriverstr=driverstr;
	size_t driversize=strlen(pdriverstr);
	
	HTREEITEM disktree;

	
	while(driversize>0)
	{
		SHGetFileInfo(pdriverstr,0,&fileinfo,sizeof(fileinfo),
			SHGFI_ICON);
		imindex=imlst.Add(fileinfo.hIcon);
		disktree=m_trdisktree.InsertItem(pdriverstr,imindex,imindex,TVI_ROOT,TVI_LAST);
		
		pdriverstr+=driversize+1;
		driversize=strlen(pdriverstr);
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDiskCataDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDiskCataDlg::OnPaint() 
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
HCURSOR CDiskCataDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDiskCataDlg::OnSelchangedTrdisktree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	CFileFind filefd;
	HTREEITEM parent;
	HTREEITEM rootitem=m_trdisktree.GetSelectedItem();
	if(m_trdisktree.GetChildItem(rootitem))return;
	parent=rootitem;
	CString rootstr=m_trdisktree.GetItemText(rootitem);
	CString temp;
	CString lstr;
	if(rootstr.Find("\\")==2)
	{
	lstr.Format("%s*.*",rootstr);
	}
	else
	{
		
		CString strparent;
		while(1)
		{
			parent=m_trdisktree.GetParentItem(parent);
			strparent=m_trdisktree.GetItemText(parent);
			if(strparent.Find("\\")==2)
				goto end;
			temp+=strparent;
			temp+="\\";
		}
end:
	CString root=m_trdisktree.GetItemText(parent);
	lstr.Format("%s%s%s\\*.*",root,temp,rootstr);
	}
	BOOL bfinded=filefd.FindFile(lstr);
	while(bfinded)
	{
		bfinded=filefd.FindNextFile();
		CString filepath;
		if(filefd.IsDirectory()&&!filefd.IsDots()){
		SHGetFileInfo(filefd.GetFilePath(),0,&fileinfo,sizeof(fileinfo),
		SHGFI_ICON);
		imindex=imlst.Add(fileinfo.hIcon);
		m_trdisktree.InsertItem(filefd.GetFileName(),imindex,imindex,rootitem);
		}
	}
	*pResult = 0;
}
