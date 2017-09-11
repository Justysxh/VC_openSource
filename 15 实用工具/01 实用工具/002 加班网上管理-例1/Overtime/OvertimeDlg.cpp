// OvertimeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Overtime.h"
#include "OvertimeDlg.h"
#include "winnetwk.h"
#include "afxsock.h"
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
// COvertimeDlg dialog

COvertimeDlg::COvertimeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COvertimeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COvertimeDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COvertimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COvertimeDlg)
	DDX_Control(pDX, IDC_BUTCLOSE, m_close);
	DDX_Control(pDX, IDC_BUTTONOK, m_ok);
	DDX_Control(pDX, IDC_STATICTIME, m_Time);
	DDX_Control(pDX, IDC_LIST2, m_Jbyg);
	DDX_Control(pDX, IDC_LIST1, m_Gsyg);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COvertimeDlg, CDialog)
	//{{AFX_MSG_MAP(COvertimeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	ON_COMMAND(ID_MENUCLEAR, OnMenuclear)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, OnDblclkList2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COvertimeDlg message handlers

BOOL COvertimeDlg::OnInitDialog()
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
	WSADATA wsd;
	WSAStartup(MAKEWORD(2,2),&wsd);

	CTime time;
	time=time.GetCurrentTime();
	CString stime;
	stime.Format("%s",time.Format("%Y-%m-%d        %H:%M:%S"));
	m_Time.SetWindowText(stime);
	SetTimer(1,1000,NULL);
	
	m_ImageList.Create(32,32,ILC_COLOR32|ILC_MASK,0,0);
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON3));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON4));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON5));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON6));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON7));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON8));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON9));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON10));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON11));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON12));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON13));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON14));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON15));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON16));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON17));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON18));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON19));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON20));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON21));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON22));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON23));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON24));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON25));

	m_Gsyg.SetImageList(&m_ImageList,LVSIL_NORMAL);
	m_Jbyg.SetImageList(&m_ImageList,LVSIL_NORMAL);

	char buf[128];
	CString str;
	int i=0;
	DWORD N;
	while(N!=7)
	{
		str.Format("%d",i+1);
		N = GetPrivateProfileString("公司员工",str,"default",buf,128,"\\\\明日公共文件夹\\公共程序\\VC开发部\\刘锐宁\\employee.ini");
		if(N!=7)
		{
			m_Gsyg.InsertItem(i,buf,i);
			i++;
		}
	}
	CString nstr;
	nstr.Format("吉林省明日科技有限公司员工总人数：%d",i);
	m_ToolTip.Create(this);
	m_ToolTip.SetDelayTime(1000);
	m_ToolTip.SetMaxTipWidth(300);
	m_ToolTip.AddTool(GetDlgItem(IDC_LIST1),nstr);
	i = 0;
	N = 0;
	while(N!=7)
	{
		str.Format("%d",i+1);
		N = GetPrivateProfileString("加班员工",str,"default",buf,128,"\\\\明日公共文件夹\\公共程序\\VC开发部\\刘锐宁\\overtime.ini");
		if(N!=7)
		{
			m_Jbyg.InsertItem(i,buf,i);
			i++;
		}
	}

	Menu.LoadMenu(IDR_MENU1);

	STR.Format("加班人数：%d",i);
	m_ToolTip.AddTool(GetDlgItem(IDC_LIST2),STR);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COvertimeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COvertimeDlg::OnPaint() 
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
HCURSOR COvertimeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void COvertimeDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CTime time;
	time=time.GetCurrentTime();
	CString stime;
	stime.Format("%s",time.Format("%Y-%m-%d        %H:%M:%S"));
	m_Time.SetWindowText(stime);
	CDialog::OnTimer(nIDEvent);
}

HBRUSH COvertimeDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if(nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetBkColor(RGB(255,255,255));
		pDC->SetTextColor(RGB(0,0,255));
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

BOOL COvertimeDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_ToolTip.RelayEvent(pMsg);
	if(pMsg->message==WM_RBUTTONUP)	
	{
		CMenu* pPopup =Menu.GetSubMenu(0);
		CRect rc;
		CPoint point;
		GetCursorPos(&point);
		rc.top=point.x;
		rc.left=point.y;
		pPopup->TrackPopupMenu(TPM_LEFTALIGN|TPM_LEFTBUTTON|TPM_VERTICAL,rc.top
								,rc.left,this,&rc);
	}
	if(pMsg->message==WM_LBUTTONDOWN)
	{
		CRect rect,rc;
		m_ok.GetWindowRect(&rect);
		m_close.GetWindowRect(&rc);
		CPoint point;
		GetCursorPos(&point);
		if(rect.PtInRect(point))
		{
			CString str,name;
			char buf[128];
			int i=0,j;
			DWORD N;
			j = m_Gsyg.GetSelectionMark();	
			name = m_Gsyg.GetItemText(j,0);
			while(N!=7)
			{
				str.Format("%d",i+1);
				N = GetPrivateProfileString("加班员工",str,"default",buf,128,"\\\\明日公共文件夹\\公共程序\\VC开发部\\刘锐宁\\overtime.ini");
				if(buf == name)
				{
					MessageBox("你已经填写过加班信息！");
					return false;
				}
				if(N!=7)
				{
					i++;
				}
			}
			if(MessageBox(name+"：请确定你是否加班！","加班信使服务软件",MB_YESNO)==IDYES)
			{
				str.Format("%d",i+1);
				WritePrivateProfileString(_T("加班员工"),_T(str),_T(name),_T("\\\\明日公共文件夹\\公共程序\\VC开发部\\刘锐宁\\overtime.ini"));
				m_Jbyg.InsertItem(i,name,i);
			}
			STR.Format("加班人数：%d",i+1);
			m_ToolTip.UpdateTipText(STR,GetDlgItem(IDC_LIST2));
		}
		else if(rc.PtInRect(point))
		{
			CDialog::OnCancel();
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void COvertimeDlg::OnMenuclear() 
{
	// TODO: Add your command handler code here
	if(MessageBox("请确定是否清空加班名单！","加班信使服务软件",MB_YESNO)==IDYES)
	{
		DWORD nSize = MAX_COMPUTERNAME_LENGTH + 1;
		char Buffer[MAX_COMPUTERNAME_LENGTH + 1];
		GetComputerName(Buffer,&nSize);
		CString Name;
		Name = Buffer;
		if(Name == "MRLRN")
		{
			CFile file;
			file.Open("\\\\明日公共文件夹\\公共程序\\VC开发部\\刘锐宁\\overtime.ini",CFile::modeCreate|CFile::modeWrite);
			CString str;
			str = "[加班员工]";
			file.Write(str,str.GetLength());
			file.Close();
			m_Jbyg.DeleteAllItems();
		}
		else
		{
			MessageBox("对不起，你没有足够权限清除加班信息！", "注意");
			return;
		}
		STR.Format("加班人数：%d",0);
		m_ToolTip.UpdateTipText(STR,GetDlgItem(IDC_LIST2));
	}
}


void COvertimeDlg::OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CString str,name;
	int i,j;
	j = m_Jbyg.GetSelectionMark();	
	name = m_Jbyg.GetItemText(j,0);
	if(MessageBox(name+"：请确定是否取消加班！","加班信使服务软件",MB_YESNO)==IDYES)
	{
		m_Jbyg.DeleteItem(j);
		CFile file;
		file.Open("\\\\明日公共文件夹\\公共程序\\VC开发部\\刘锐宁\\overtime.ini",CFile::modeCreate|CFile::modeWrite);
		CString str;
		str = "[加班员工]";
		file.Write(str,str.GetLength());
		file.Close();
		for(i=0;i<m_Jbyg.GetItemCount();i++)
		{
			str.Format("%d",i+1);
			name = m_Jbyg.GetItemText(i,0);
			WritePrivateProfileString(_T("加班员工"),_T(str),_T(name),_T("\\\\明日公共文件夹\\公共程序\\VC开发部\\刘锐宁\\overtime.ini"));
		}
	}
	STR.Format("加班人数：%d",i);
	m_ToolTip.UpdateTipText(STR,GetDlgItem(IDC_LIST2));
	*pResult = 0;
}

