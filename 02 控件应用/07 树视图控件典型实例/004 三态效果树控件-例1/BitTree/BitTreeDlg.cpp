// BitTreeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BitTree.h"
#include "BitTreeDlg.h"

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
// CBitTreeDlg dialog

CBitTreeDlg::CBitTreeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBitTreeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBitTreeDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CBitTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBitTreeDlg)
	DDX_Control(pDX, IDC_TREE, m_Tree);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBitTreeDlg, CDialog)
	//{{AFX_MSG_MAP(CBitTreeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBitTreeDlg message handlers

BOOL CBitTreeDlg::OnInitDialog()
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
	
	m_ImageList.Create(IDB_BITMAP1,16,1,RGB(255,255,255));
	m_StateList.Create(IDB_BITMAP2,12,1,RGB(255,255,255));

	m_Tree.SetImageList(&m_ImageList,TVSIL_NORMAL);
	m_Tree.SetImageList(&m_StateList,TVSIL_STATE);

	// TODO: Add extra initialization here
	OnOK();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBitTreeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
void CBitTreeDlg::OnPaint() 
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
HCURSOR CBitTreeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBitTreeDlg::OnOK() 
{
	TV_INSERTSTRUCT hInsert;
	hInsert.hParent=NULL;
	hInsert.hInsertAfter=TVI_LAST;
	hInsert.item.mask=TVIF_IMAGE|TVIF_SELECTEDIMAGE|TVIF_TEXT|TVIF_STATE;
	hInsert.item.hItem=NULL;
	hInsert.item.state=INDEXTOSTATEIMAGEMASK( 1 );
	hInsert.item.stateMask=TVIS_STATEIMAGEMASK;
	hInsert.item.cchTextMax=6;
	hInsert.item.iSelectedImage=1;
	hInsert.item.cChildren=0;
	hInsert.item.lParam=0;
	
	hInsert.item.pszText="吉林省";
	hInsert.item.iImage=0;
	HTREEITEM hRoot=m_Tree.InsertItem(&hInsert);
	
	m_Tree.SetItemState( hRoot, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK );


	hInsert.hParent=hRoot;
	hInsert.item.iImage=0;
	hInsert.item.pszText="长春市";
	m_Tree.InsertItem(&hInsert);
	
	hInsert.hParent=hRoot;
	hInsert.item.pszText="辽源市";
	HTREEITEM h1=m_Tree.InsertItem(&hInsert);
	
	hInsert.hParent=hRoot;
	hInsert.item.pszText="吉林市";
	m_Tree.InsertItem(&hInsert);
	
	hInsert.hParent=hRoot;
	hInsert.item.pszText="四平市";
	m_Tree.InsertItem(&hInsert);
	
	hInsert.hParent=hRoot;
	hInsert.item.pszText="公主岭市";
	m_Tree.InsertItem(&hInsert);	
	
	hInsert.hParent=hRoot;
	hInsert.item.pszText="松原市";
	HTREEITEM h2=m_Tree.InsertItem(&hInsert);
	
	hInsert.hParent=h2;
	hInsert.item.pszText="扶余县";
	m_Tree.InsertItem(&hInsert);
	
    hInsert.hParent=h2;
	hInsert.item.pszText="长岭县";
	m_Tree.InsertItem(&hInsert);
	
    hInsert.hParent=h2;
	hInsert.item.pszText="前郭县";
	m_Tree.InsertItem(&hInsert);
	
    hInsert.hParent=h2;
	hInsert.item.pszText="宁江区";
	m_Tree.InsertItem(&hInsert);
	
}


