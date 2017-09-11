// ReceiveMailDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ReceiveMail.h"
#include "ReceiveMailDlg.h"

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
// CReceiveMailDlg dialog

CReceiveMailDlg::CReceiveMailDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReceiveMailDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReceiveMailDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReceiveMailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReceiveMailDlg)
	DDX_Control(pDX, IDC_RECELST, m_recelst);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CReceiveMailDlg, CDialog)
	//{{AFX_MSG_MAP(CReceiveMailDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTRECE, OnRece)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReceiveMailDlg message handlers

BOOL CReceiveMailDlg::OnInitDialog()
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
	m_recelst.SetExtendedStyle(LVS_EX_GRIDLINES);
	m_recelst.InsertColumn(0,"主题",LVCFMT_LEFT,50);
	m_recelst.InsertColumn(1,"内容",LVCFMT_LEFT,300);
	m_recelst.InsertColumn(2,"时间",LVCFMT_LEFT,50);
	HRESULT hr=::CoInitialize(NULL);
	if(!SUCCEEDED(hr))
		return FALSE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CReceiveMailDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CReceiveMailDlg::OnPaint() 
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
HCURSOR CReceiveMailDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CReceiveMailDlg::OnRece() 
{
	m_recelst.DeleteAllItems();
	CString strpop;
	CString strusr;
	CString strpwd;
	GetDlgItem(IDC_EDPOP)->GetWindowText(strpop);
	GetDlgItem(IDC_EDUSER)->GetWindowText(strusr);
	GetDlgItem(IDC_EDPWD)->GetWindowText(strpwd);


	jmail::IMessagesPtr jmsg;
	jmail::IPOP3Ptr jpop;
	jpop.CreateInstance(__uuidof(jmail::POP3));
	jmsg.CreateInstance(__uuidof(jmail::Message));
	try{
	jpop->Timeout=120;
	jpop->Connect((_bstr_t)strusr,(_bstr_t)strpwd,(_bstr_t)strpop,110);
	long mailcount=jpop->Messages->Count-1;
	for(long i=1;i<=mailcount;i++)
	{
		_bstr_t bssubject=jpop->Messages->Item[i]->Subject;
		_bstr_t bsbody=jpop->Messages->Item[i]->Body;
		COleDateTime time=jpop->Messages->Item[i]->Date;
		int count=m_recelst.InsertItem(i,"");
		m_recelst.SetItemText(count,0,(const char *)bssubject);
		m_recelst.SetItemText(count,1,(const char *)bsbody);
		m_recelst.SetItemText(count,2,(const char *)time.Format("%Y-%m-%d"));
	}
	}
	catch(_com_error e)
	{
		CString strerr;
		strerr.Format("错误信息：%s\r\n错误描述：%s", (LPCTSTR)e.ErrorMessage(), (LPCTSTR)e.Description());
		AfxMessageBox(strerr);
		return;
	}
	//jmsg->Release();
	//jpop->Disconnect();
	//jpop->Release();
	AfxMessageBox("接收完成");	
}

BOOL CReceiveMailDlg::DestroyWindow() 
{
	::CoUninitialize();
	return CDialog::DestroyWindow();
}
