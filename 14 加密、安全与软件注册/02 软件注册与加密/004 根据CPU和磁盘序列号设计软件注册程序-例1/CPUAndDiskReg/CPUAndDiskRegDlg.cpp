// CPUAndDiskRegDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CPUAndDiskReg.h"
#include "CPUAndDiskRegDlg.h"

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
// CCPUAndDiskRegDlg dialog

CCPUAndDiskRegDlg::CCPUAndDiskRegDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCPUAndDiskRegDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCPUAndDiskRegDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCPUAndDiskRegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCPUAndDiskRegDlg)
	DDX_Control(pDX, IDC_MACHINE, m_machine);
	DDX_Control(pDX, IDC_CDISK, m_cdisk);
	DDX_Control(pDX, IDC_CPU, m_cpu);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCPUAndDiskRegDlg, CDialog)
	//{{AFX_MSG_MAP(CCPUAndDiskRegDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_REG, OnReg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCPUAndDiskRegDlg message handlers

BOOL CCPUAndDiskRegDlg::OnInitDialog()
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

	  
    unsigned long s1,s2;     
    char sel;   
    sel='1';   
    CString MyCpuID,CPUID1,CPUID2;   
	__asm{   
	mov eax,01h   
	xor edx,edx   
	cpuid   
	mov s1,edx   
	mov s2,eax   
	}   
	CPUID1.Format("%08X%08X",s1,s2);   
	__asm{   
	mov eax,03h   
	xor ecx,ecx   
	xor edx,edx   
	cpuid   
	mov s1,edx   
	mov s2,ecx   
	}   
	CPUID2.Format("%08X%08X",s1,s2);   
       
    MyCpuID=CPUID1+CPUID2;
    m_cpu.SetWindowText(MyCpuID);
	DWORD ser;
	char namebuf[128];
	char filebuf[128];
	::GetVolumeInformation("c:\\",namebuf,128,&ser,0,0,filebuf,128);
	CString strdisk;
	strdisk.Format("%d",ser);
	CString strmachine;
	strmachine=MyCpuID.Mid(13,5); //从MyCpuID的第13位开始取5个
	strmachine+=strdisk.Mid(3,5);//从strdisk的第3位开始取5个,合并生成机器码
	m_cdisk.SetWindowText(strdisk);
	m_machine.SetWindowText(strmachine);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCPUAndDiskRegDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCPUAndDiskRegDlg::OnPaint() 
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
HCURSOR CCPUAndDiskRegDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCPUAndDiskRegDlg::OnReg() 
{
	CString code[16]={"ad","eh","im","np","ru","vy","zc","gk",
	"pt","xb","fj","ox","wa","ei","nr","qu"};
	CString reg,stred;
	int num;
	m_machine.GetWindowText(stred);
	stred.MakeLower();
	for(int i=0;i<10;i++)
	{
		char p=stred.GetAt(i);
		if(p>='a'&&p<='f')
			num=p-'a'+10;
		else
			num=p-'0';
		CString tmp=code[num];
		reg+=tmp;
	}
	reg.MakeUpper();
	GetDlgItem(IDC_NUM1)->SetWindowText(reg.Mid(0,5));
	GetDlgItem(IDC_NUM2)->SetWindowText(reg.Mid(5,5));
	GetDlgItem(IDC_NUM3)->SetWindowText(reg.Mid(10,5));
	GetDlgItem(IDC_NUM4)->SetWindowText(reg.Mid(15,5));

}
