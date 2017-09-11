// SendMailWithAddDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SendMailWithAdd.h"
#include "SendMailWithAddDlg.h"
#include <afxsock.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include <afxtempl.h>
#include <afxpriv.h>
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
// CSendMailWithAddDlg dialog

CSendMailWithAddDlg::CSendMailWithAddDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSendMailWithAddDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSendMailWithAddDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSendMailWithAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSendMailWithAddDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSendMailWithAddDlg, CDialog)
	//{{AFX_MSG_MAP(CSendMailWithAddDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTADD, OnAdd)
	ON_BN_CLICKED(IDC_BTSEND, OnBtsend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSendMailWithAddDlg message handlers

BOOL CSendMailWithAddDlg::OnInitDialog()
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
	
	HRESULT hr=::CoInitialize(NULL);
	if(!SUCCEEDED(hr))
		return FALSE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSendMailWithAddDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSendMailWithAddDlg::OnPaint() 
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
HCURSOR CSendMailWithAddDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}




void CSendMailWithAddDlg::OnAdd() 
{
	
	CFileDialog file(true,"file",NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"所有文件|*.*||",this);
	if(file.DoModal()==IDOK)
	{
		CString str;
		str=file.GetPathName();
		GetDlgItem(IDC_EDATT)->SetWindowText(str);
	}
}

void CSendMailWithAddDlg::OnBtsend() 
{
	CString strserver;
	CString strrece;
	CString strsubject;
	CString strbody;
	CString stratt;
	CString strfrom;
	GetDlgItem(IDC_EDRECE)->GetWindowText(strrece);
	GetDlgItem(IDC_EDSUBJECT)->GetWindowText(strsubject);
	GetDlgItem(IDC_EDBODY)->GetWindowText(strbody);
	GetDlgItem(IDC_EDATT)->GetWindowText(stratt);
	GetDlgItem(IDC_SMTP)->GetWindowText(strserver);
	GetDlgItem(IDC_EDFROM)->GetWindowText(strfrom);
	if(strfrom.IsEmpty())
	{
		AfxMessageBox("请填写发信人地址");
		return;
	}
	if(strrece.IsEmpty())
	{
		AfxMessageBox("请填写收信人地址");
		return;
	}
	
	jmail::IMessagePtr jmsg;
	jmsg.CreateInstance(__uuidof(jmail::Message));
	jmsg->AddRecipient((LPCTSTR)strrece,"","");
	jmsg->Subject=(LPCTSTR)strsubject;
	jmsg->Body=(LPCTSTR)strbody;
	jmsg->From=(LPCTSTR)strfrom;
	jmsg->AddCustomAttachment((_bstr_t)stratt,(_bstr_t)"jmail",VARIANT_FALSE);
	try{
	jmsg->Send((LPCTSTR)strserver,VARIANT_FALSE);
	}
	catch(_com_error e)
	{
		CString strerr;
		strerr.Format("%s\r\n错误描述是%s", (LPCTSTR)e.ErrorMessage(), (LPCTSTR)e.Description());
		AfxMessageBox(strerr);
	}
	AfxMessageBox("发送成功");
}

BOOL CSendMailWithAddDlg::DestroyWindow() 
{
	::CoUninitialize();
	return CDialog::DestroyWindow();
}
