// ManageImageDlg.cpp : implementation file
//
#include "user32.h"
#include "stdafx.h"
#include "ManageImage.h"
#include "ManageImageDlg.h"


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
// CManageImageDlg dialog

CManageImageDlg::CManageImageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CManageImageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CManageImageDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CManageImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CManageImageDlg)
	DDX_Control(pDX, IDC_TREE, m_tree);
	DDX_Control(pDX, IDC_DIR, m_dir);
	DDX_Control(pDX, IDC_DISK, m_disk);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CManageImageDlg, CDialog)
	//{{AFX_MSG_MAP(CManageImageDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_DISK, OnSelchangeDisk)
	ON_NOTIFY(NM_CLICK, IDC_TREE, OnClickTree)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE, OnDblclkTree)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManageImageDlg message handlers

BOOL CManageImageDlg::OnInitDialog()
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
	
	m_imagelist.Create(16,16,ILC_COLOR24|ILC_MASK,0,0);
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	// TODO: Add extra initialization here
	m_tree.SetImageList(&m_imagelist,TVSIL_NORMAL);

	//m_disk.Dir(DDL_DRIVES,"");
	EnumSysDisk();//列举系统盘符

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CManageImageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CManageImageDlg::OnPaint() 
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
HCURSOR CManageImageDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CManageImageDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
}

void CManageImageDlg::OnSelchangeDisk() 
{
	CString m_str ,c_disk;
	m_disk.GetWindowText(m_str);

	c_disk = m_str;
	m_str = m_str.Left(2);
	m_tree.DeleteAllItems();
	if (!m_str.IsEmpty())
	{
		hroot = m_tree.InsertItem(m_str,0,0);
		EnumDIR(m_str,hroot);
	}
}

void CManageImageDlg::EnumSysDisk()
{
	DWORD dirlen = GetLogicalDriveStrings(0,NULL); //获取所有盘符大小
	LPSTR pdir ,phead;
	pdir = new char [dirlen+1];


	GetLogicalDriveStrings(dirlen,pdir);
	phead = pdir;
	while (*pdir != 0 )
	{
		m_disk.AddString(pdir);
		pdir= _tcschr(pdir,0)+1;
	}
	
	delete[]phead;
}


void CManageImageDlg::EnumDIR(CString dirname,HTREEITEM hparentitem)
{
	WIN32_FIND_DATA m_fileinfo;

	HANDLE hfile;	
	
	HTREEITEM hnode;

	CString temp = dirname;
	CString tempfile;

	dirname+="\\*.*";

	hfile = FindFirstFile(dirname,&m_fileinfo);
	if (m_fileinfo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
	{
		tempfile = m_fileinfo.cFileName;
		tempfile.TrimLeft();
		tempfile.TrimRight();
		if ((tempfile!= ".") && (tempfile != "..") )
		{

			hnode = m_tree.InsertItem(m_fileinfo.cFileName,0,0,hparentitem);
		}

		if (m_fileinfo.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
			if ((tempfile!= ".") && (tempfile != "..") )
			{

				EnumDIR(temp+"\\"+m_fileinfo.cFileName+"\\",hnode);
			}
	}
	while (FindNextFile(hfile,&m_fileinfo))
	{
		if (m_fileinfo.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
		{
			tempfile = m_fileinfo.cFileName;
			tempfile.TrimLeft();
			tempfile.TrimRight();
			if ((tempfile!= ".") && (tempfile != "..") )
			{

				hnode = m_tree.InsertItem(tempfile,0,0,hparentitem);
							
			}
			if (m_fileinfo.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
				if ((tempfile!= ".") && (tempfile != "..") )
				{
					EnumDIR(temp+"\\"+m_fileinfo.cFileName,hnode);
				}
		}
	}
}

void CManageImageDlg::OnClickTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
		*pResult = 0;

	HTREEITEM htreeitem;

	CPoint m_point;
	GetCursorPos(&m_point);
	m_tree.ScreenToClient(&m_point);
	UINT state = 0;
	htreeitem = m_tree.HitTest(m_point,&state);

	if (htreeitem != NULL) //有节点被选中
	{
		CString str,path;
		str = m_tree.GetItemText(htreeitem);

		
		path = GetFullPath(htreeitem); //获取当前节点的完整目录
		path += "\\*.*";

		EnumFiles(path.GetBuffer(path.GetLength()));
	}	

}

CString CManageImageDlg::GetFullPath(HTREEITEM htreeitem)
{
	CString result = "";
	CString temp;
	HTREEITEM hparent;
	hparent = m_tree.GetParentItem(htreeitem);
	while (hparent != NULL)
	{
		temp = m_tree.GetItemText(hparent)+"\\";
		result.Insert(0,temp);
		hparent = m_tree.GetParentItem(hparent);

	}
	temp = m_tree.GetItemText(htreeitem);

	result+= temp;
	return result;

}

void CManageImageDlg::OnDblclkTree(NMHDR* pNMHDR, LRESULT* pResult) 
{

	*pResult = 0;
}

void CManageImageDlg::EnumFiles(LPSTR filepath)
{
	WIN32_FIND_DATA m_fileinfo;

	HANDLE hfile;	
	
	m_dir.ResetContent();

	CString tempfile;

	tempfile = filepath;
	tempfile = tempfile.Left(tempfile.GetLength()-3);


	CString c_temp,c_fileext;

	m_disk.GetWindowText(c_temp);


	hfile = FindFirstFile(filepath,&m_fileinfo);
	if ( !(m_fileinfo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
	{
		
		c_temp = m_fileinfo.cFileName;
		c_fileext = c_temp.Right(3);
		if (c_fileext=="bmp")
			m_dir.AddString( tempfile+m_fileinfo.cFileName);

	}

	while (FindNextFile(hfile,&m_fileinfo))
	{
		if (!( m_fileinfo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		c_temp = m_fileinfo.cFileName;
		c_fileext = c_temp.Right(3);
		if (c_fileext=="bmp")
			m_dir.AddString(tempfile+m_fileinfo.cFileName);
	}
}

void CManageImageDlg::OnSave() 
{
	int m_count = m_dir.GetCount();	
	if (m_count>0)
	{
		CFileDialog m_fdlg(FALSE,"bmp",NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,NULL,this);
		if (m_fdlg.DoModal()==IDOK)
		{
			CString m_savepath = m_fdlg.GetPathName();
			CString m_curfile;
			for (int i = 0;i <m_count;i++)
			{
				m_dir.GetText(i,m_curfile);
				CopyFile(m_curfile,ExtractFileName(m_savepath)+"\\"+ ExtractFilePath(m_curfile),FALSE);
			}
			MessageBox("保存成功");
		}
	}
}

//去除文件路径
CString CManageImageDlg::ExtractFilePath(CString m_path)
{
	int pos = m_path.ReverseFind('\\');
	
	return m_path.Right(m_path.GetLength()-pos);

}
//出除文件名,返回路径
CString CManageImageDlg::ExtractFileName(CString m_fullname)
{
	int pos = m_fullname.ReverseFind('\\');
	return m_fullname.Left(pos);
}
