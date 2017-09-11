// NetMACRegDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetMACReg.h"
#include "NetMACRegDlg.h"
#include "nb30.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
char base[64]={'d','c','a','b','h','g','e','f','l','k',
				'i','j','p','o','m','n','t','s','q','r',
				'x','w','u','v','b','a','y','z','f','e',
				'c','d','j','i','g','h','n','m','k','l',
				'r','q','o','p','v','u','s','t','z','y',
				'j','t','o','v','w','m','q','x','p','f',
				'w','x','d','c'};
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
// CNetMACRegDlg dialog

CNetMACRegDlg::CNetMACRegDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNetMACRegDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNetMACRegDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNetMACRegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNetMACRegDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNetMACRegDlg, CDialog)
	//{{AFX_MSG_MAP(CNetMACRegDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTREG, OnReg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetMACRegDlg message handlers

BOOL CNetMACRegDlg::OnInitDialog()
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
	NCB ncb;
	LANA_ENUM lenum;
	ADAPTER_STATUS state;
	UCHAR ucReturnCode;
	ncb.ncb_command=NCBENUM;
	ncb.ncb_buffer=(UCHAR*)&lenum;
	ncb.ncb_length=sizeof(lenum);
	ucReturnCode=Netbios(&ncb);
	if(lenum.length>=0)
	{
		int num=lenum.lana[0];
		UCHAR buf[128];
		memset(&ncb,0,sizeof(ncb));
		ncb.ncb_command=NCBRESET;
		ncb.ncb_lana_num=num;
		ucReturnCode=Netbios(&ncb);
		memset(&ncb,0,sizeof(ncb));
		ncb.ncb_command=NCBASTAT;
		ncb.ncb_lana_num=num;
		ncb.ncb_buffer=(unsigned char *)&state;
		ncb.ncb_length=sizeof(state);
		strcpy( (char *)ncb.ncb_callname,"*" );
		ucReturnCode=Netbios(&ncb);
		CString strMac;
		strMac.Format("%02X%02X-%02X%02X-%02X%02X\n",
			state.adapter_address[0],
			state.adapter_address[1],
			state.adapter_address[2],
			state.adapter_address[3],
			state.adapter_address[4],
			state.adapter_address[5]);
		GetDlgItem(IDC_MACADDR)->EnableWindow(false);
		GetDlgItem(IDC_MACADDR)->SetWindowText(strMac);
	}
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNetMACRegDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CNetMACRegDlg::OnPaint() 
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
HCURSOR CNetMACRegDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CNetMACRegDlg::OnReg() 
{
	CString code;
	CString regcode,tmp;
	GetDlgItem(IDC_MACADDR)->GetWindowText(code);
	code.MakeLower();
	CString seg1,seg2,seg3;
	int num;
	seg1=code.Mid(0,4);
	seg2=code.Mid(5,4);
	seg3=code.Mid(10,4);
	char *cpseg1=new char[4];
	char *cpseg2=new char[4];
	char *cpseg3=new char[4];
	cpseg1=seg1.GetBuffer(0);
	cpseg2=seg2.GetBuffer(0);
	cpseg3=seg3.GetBuffer(0);
	char temp;
	int i;
	for(i=0;i<4;i++)
	{
		temp=cpseg1[i];
		if(temp>='a'&&temp<='f')
			num=temp-'a'+10;
		else
			num=temp-'0';
		tmp.Format("%c",base[num*4+i]);
		regcode+=tmp;
	}
	
	for(i=0;i<4;i++)
	{
		temp=cpseg2[i];
		if(temp>='a'&&temp<='f')
			num=temp-'a'+10;
		else
			num=temp-'0';
		tmp.Format("%c",base[num*4+i]);
		regcode+=tmp;
	}
	for(i=0;i<4;i++)
	{
		temp=cpseg3[i];
		if(temp>='a'&&temp<='f')
			num=temp-'a'+10;
		else
			num=temp-'0';
		tmp.Format("%c",base[num*4+i]);
		regcode+=tmp;
	}
	regcode.MakeUpper();
	GetDlgItem(IDC_EDREGCODE)->SetWindowText(regcode);
}
