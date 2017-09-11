// FileFindThreadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FileFindThread.h"
#include "FileFindThreadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define WMFINDFILE (WM_USER + 10)
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
// CFileFindThreadDlg dialog

CFileFindThreadDlg::CFileFindThreadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileFindThreadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileFindThreadDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileFindThreadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileFindThreadDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFileFindThreadDlg, CDialog)
	//{{AFX_MSG_MAP(CFileFindThreadDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_MESSAGE(WMFINDFILE,OnFindFile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileFindThreadDlg message handlers

BOOL CFileFindThreadDlg::OnInitDialog()
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
	
	m_Splitter.CreateStatic(this,1,2);
	m_Splitter.CreateView(0,0,RUNTIME_CLASS(CTreeFrame),CSize(150,0),NULL);
	m_Splitter.CreateView(0,1,RUNTIME_CLASS(CChildFrame),CSize(0,0),NULL);

	CalcSplitterSize();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFileFindThreadDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFileFindThreadDlg::OnPaint() 
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
HCURSOR CFileFindThreadDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFileFindThreadDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	CalcSplitterSize();

}

void CFileFindThreadDlg::CalcSplitterSize()
{
	if (IsWindow(m_Splitter.GetSafeHwnd()))
	{
		CRect rect;
		GetClientRect(&rect);
		m_Splitter.MoveWindow(&rect,false);
	}
}

UINT FindFileThreadFunc( LPVOID lParam )
{
	THREADPARAM threadParam = *( THREADPARAM* ) lParam;
	int count = threadParam.dlg->m_strArrPath.GetSize();
	
	for (int i = 0 ; i < count ; i++)
	{
		threadParam.dlg->FindFiles(threadParam.dlg->m_strArrPath.GetAt(i),
			threadParam.FileName,threadParam.listCtrl);
	}
	AfxMessageBox("²éÕÒÍê³É");
	return 0;
}

LRESULT CFileFindThreadDlg::OnFindFile(WPARAM wParam, LPARAM lParam)
{
	CTreeCtrl &treeCtrl = ((CTreeFrame *)m_Splitter.GetPane(0,0))->GetTreeCtrl();
	m_strArrPath.RemoveAll();
	GetSearchingPath(treeCtrl.GetRootItem(),&treeCtrl);

	THREADPARAM threadParam;
	
	CEdit *edit = (CEdit *)(wParam);
	edit->GetWindowText(threadParam.FileName,255);

	CListCtrl *listCtrl = (CListCtrl*)lParam;

	threadParam.dlg = this;
	threadParam.listCtrl = listCtrl;
	
	CWinThread* pThread = AfxBeginThread( 
				FindFileThreadFunc, 
				& threadParam, 
				THREAD_PRIORITY_NORMAL, 
				0, 
				CREATE_SUSPENDED );
	ASSERT_VALID( pThread );
	pThread->ResumeThread();

	return (LRESULT)0;
}

void CFileFindThreadDlg::FindFiles( CString strPath, CString strFileName ,CListCtrl *listCtrl)
{
	if ( strPath.Right( 1 ) != _T( "\\" ) )
		strPath += _T( "\\" );

	strPath += _T( "*.*" );

	CFileFind file;

	BOOL bContinue = file.FindFile( strPath );
	while ( bContinue )
	{
		bContinue = file.FindNextFile();
		if ( file.IsDirectory() && ! file.IsDots() )
		{
			FindFiles( file.GetFilePath(), strFileName ,listCtrl);
		}
		else if ( ! file.IsDots() && ! file.IsDirectory())
		{
			if ( file.GetFileName().Find( strFileName ) != -1 )
			{
				int index = listCtrl->GetItemCount();
				listCtrl->InsertItem(index,file.GetFileName());
				listCtrl->SetItemText(index,1,file.GetFilePath());
			}
		} 
	} 
}


void CFileFindThreadDlg::GetSearchingPath( HTREEITEM hItem ,CTreeCtrl *treeCtrl )
{
	ASSERT( hItem );
	HTREEITEM hChildItem = treeCtrl->GetChildItem( hItem );

	while ( hChildItem )
	{
		if ( treeCtrl->GetCheck( hChildItem ) )
		{
			if ( GetFullPath( hChildItem ,treeCtrl) != _T( "" ) )
			{
				TRACE1( "The selected path is: %s\n", GetFullPath( hChildItem ,treeCtrl) );
				m_strArrPath.Add( GetFullPath( hChildItem ,treeCtrl) );
			}
		}
		else
		{
			GetSearchingPath( hChildItem ,treeCtrl);
		}

		hChildItem = treeCtrl->GetNextItem( hChildItem, TVGN_NEXT );
	}
}

CString CFileFindThreadDlg::GetFullPath( HTREEITEM hItem , CTreeCtrl *treeCtrl)
{
	ASSERT( hItem );

	CString strTmp	= _T( "" );
	CString strPath	= _T( "" );
	
	while ( hItem != treeCtrl->GetRootItem() )
	{
		strTmp = treeCtrl->GetItemText( hItem );
		if ( strTmp.Right( 1 ) != _T( "\\" ) )
			strTmp += _T( "\\" );
		strPath = strTmp + strPath;

		hItem = treeCtrl->GetParentItem( hItem );
	}

	return strPath;
}