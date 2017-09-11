// SendMsgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SendMsg.h"
#include "SendMsgDlg.h"

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
// CSendMsgDlg dialog

CSendMsgDlg::CSendMsgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSendMsgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSendMsgDlg)
	m_Baud = _T("");
	m_MerID = _T("");
	m_Accredit = _T("");
	m_Port = _T("");
	m_ReceiverID = _T("");
	m_Content = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSendMsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSendMsgDlg)
	DDX_Text(pDX, IDC_BAUD, m_Baud);
	DDX_Text(pDX, IDC_MERCHANEID, m_MerID);
	DDX_Text(pDX, IDC_ACCREDIT, m_Accredit);
	DDX_Text(pDX, IDC_PORT, m_Port);
	DDX_Text(pDX, IDC_RECEIVERID, m_ReceiverID);
	DDX_Text(pDX, IDC_CONTENT, m_Content);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSendMsgDlg, CDialog)
	//{{AFX_MSG_MAP(CSendMsgDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GETINFO, OnGetinfo)
	ON_BN_CLICKED(IDC_SENDINFO, OnSendinfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSendMsgDlg message handlers

BOOL CSendMsgDlg::OnInitDialog()
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

void CSendMsgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSendMsgDlg::OnPaint() 
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
HCURSOR CSendMsgDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSendMsgDlg::OnOK() 
{

}

void CSendMsgDlg::OnGetinfo() 
{
	m_MerID.Format("%s",GSMModemGetSnInfoNew(NULL,NULL)) ;
	
	m_Baud.Format("%s",GSMModemGetBaudrate());

	m_Port.Format("%s",GSMModemGetDevice());
	
	UpdateData(FALSE);	
}

void CSendMsgDlg::OnSendinfo() 
{
	UpdateData(TRUE);	

	if (GSMModemInitNew((char*)(LPCTSTR)m_Port,(char*)(LPCTSTR)m_Baud,
		NULL,NULL,FALSE,(char*)(LPCTSTR)m_Accredit)==FALSE)
	{
		MessageBox((char*)GSMModemGetErrorMsg());
		return;
	}

	if(GSMModemSMSsend(NULL,8,(char*)(LPCTSTR)m_Content,m_Content.GetLength(),(char*)(LPCTSTR)m_ReceiverID,FALSE)==FALSE)
	{
		MessageBox("发送失败");
	}
	else
	{
		MessageBox("发送成功");
	}
}

void CSendMsgDlg::OnCancel()
{
	GSMModemRelease();
	CDialog::OnCancel();
}
