// GetAirReportDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GetAirReport.h"
#include "GetAirReportDlg.h"
#include "afxinet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CString city[]={"哈尔滨","长春","沈阳","北京",
			"天津","石家庄","乌鲁木齐","呼和浩特",
	"济南","太原","银川","西宁",
	"合肥","郑州","西安","兰州",
	"上海","南京","武汉","成都",
	"拉萨","杭州","重庆","南昌",
	"长沙","贵阳","福州",
	"昆明","广州","南宁"
	,"海口"};
CString city2[31][2]={"哈尔滨","50953",
	"长春","54161",
	"沈阳","54342",
	"北京","54511",
	"天津","54527",
	"石家庄","53698",
	"乌鲁木齐","51463",
	"呼和浩特","53463",
	"济南","54823",
	"太原","53772",
	"银川","53614",
	"西宁","52866",
	"合肥","58321",
	"郑州","57083",
	"西安","57036",
	"兰州","52889",
	"上海","58362",
	"南京","58238",
	"武汉","57494",
	"成都","56294",
	"拉萨","55591",
	"杭州","58457",
	"重庆","57516",
	"南昌","58606",
	"长沙","57687",
	"贵阳","57816",
	
	"福州","58847",
	"昆明","56778",
	"广州","59287",
	"南宁","59431",
	
	
	"海口","59758"};
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
// CGetAirReportDlg dialog

CGetAirReportDlg::CGetAirReportDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGetAirReportDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGetAirReportDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGetAirReportDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGetAirReportDlg)
	DDX_Control(pDX, IDC_REPORTLIST, m_reportlist);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGetAirReportDlg, CDialog)
	//{{AFX_MSG_MAP(CGetAirReportDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTGET, OnGet)
	ON_BN_CLICKED(IDC_BTEXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGetAirReportDlg message handlers

BOOL CGetAirReportDlg::OnInitDialog()
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
	addressfront="http://www.nmc.gov.cn/weatherdetail";
	m_reportlist.SetExtendedStyle(LVS_EX_GRIDLINES);
	m_reportlist.InsertColumn(0,"城市",LVCFMT_LEFT,70);
	m_reportlist.InsertColumn(1,"天气",LVCFMT_LEFT,90);
	m_reportlist.InsertColumn(2,"气温",LVCFMT_LEFT,120);
	m_reportlist.InsertColumn(3,"风力",LVCFMT_LEFT,70);
	//通过字符串数组向列表控件中添加数据
	for(int i=0;i<31;i++)
	{
		m_reportlist.InsertItem(i,city[i],0);
	}

	return TRUE;
}

void CGetAirReportDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGetAirReportDlg::OnPaint() 
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
HCURSOR CGetAirReportDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
/*
void CGetAirReportDlg::OnGet()
{
	//如果在网页中找到城市名称，设为真
	BOOL bTable=FALSE;
	//分别是获得天气，气温，风力所在行后，设为真
	BOOL bGet1=TRUE,bGet2=TRUE,bGet3=TRUE;
	//如果<TD class>和</TD>处在源码的两行中
	BOOL bNext1=FALSE,bNext2=FALSE,bNext3=FALSE;
	int line=0;    //在源代码中的位置
	int leftpos;   //取某行源码“</TD>”的位置
	int rightpos;  //取某行源码“>”的位置
	//address="http://192.168.1.165/default.htm";
	int isel=m_reportlist.GetSelectionMark();
	if(isel<0)
	{
		AfxMessageBox("请选择城市");
		return;
	}
	//CString tmp;
	strtmp1=city2[isel][0];
	//strtmp1="北京";
	address.Format("%s/%s.html",addressfront,city2[isel][1]);

		//tmp.Format("%s/%s_full.htm",addressfront,city2[i][1]);
	CString strsource;
	CInternetSession mySession(NULL,0);
	CHttpFile* myHttpFile=NULL;
	myHttpFile=(CHttpFile*)mySession.OpenURL(address);
	while(myHttpFile->ReadString(strsource))
	{
		//如果某行源码中有提取的字符，开始进行处理
		if(strsource.Find(strtmp1)>0)
			bTable=TRUE;
		if(bTable)
		{
			if(strsource.Find("TD class")>0)
				line++;
		}
		//得到天气的位置
		if(line==6&&bGet1)
		{
			leftpos=strsource.Find("</TD>");
			if(leftpos>0)
			{
				strtmp2=strsource.Left(leftpos);
				rightpos=strtmp2.Find(">");
				strweather=strtmp2.Right(strtmp2.GetLength()-rightpos-1);
				bGet1=FALSE;
			}
			else
			{
				bNext1=TRUE;
				strtmp3=strsource;
				goto end;
			}
		}
		if(bNext1)
		{
			//将上一行和下一行进行合并，然后进行合并
			strtmp3+=strsource;
			strtmp3.Replace(" ","");
			leftpos=strsource.Find("</TD>");
			strtmp2=strsource.Left(leftpos);
			rightpos=strtmp2.Find(">");
			strweather=strtmp2.Right(strtmp2.GetLength()-rightpos-1);
			bGet1=FALSE;
			bNext1=FALSE;
		}
		//得到气温的位置
		if(line==12&&bGet2)
		{
			leftpos=strsource.Find("</TD>");
			if(leftpos>0)
			{
				
				strtmp2=strsource.Left(leftpos);
				rightpos=strtmp2.Find(">");
				strtemperature=strtmp2.Right(strtmp2.GetLength()-rightpos-1);
				bGet2=FALSE;
			}
			else
			{
				bNext2=TRUE;
				strtmp3=strsource;
				goto end;
			}
		}
		if(bNext2)
		{
			strtmp3+=strsource;
			strtmp3.Replace(" ","");
			leftpos=strsource.Find("</TD>");
			strtmp2=strsource.Left(leftpos);
			rightpos=strtmp2.Find(">");
			strtemperature=strtmp2.Right(strtmp2.GetLength()-rightpos)-1;
			bGet2=FALSE;
			bNext2=FALSE;
		}
		//得到风力的位置
		if(line==16&&bGet3)
		{
			leftpos=strsource.Find("</TD>");
			if(leftpos>0)
			{
				
				strtmp2=strsource.Left(leftpos);
				rightpos=strtmp2.Find(">");
				strwind=strtmp2.Right(strtmp2.GetLength()-rightpos-1);
				goto stop;
			
			}
			else
			{
				bNext3=TRUE;
				strtmp3=strsource;
				goto end;
			}
		}
		if(bNext3)
		{
			strtmp3+=strsource;
			strtmp3.Replace(" ","");
			leftpos=strsource.Find("</TD>");
			strtmp2=strsource.Left(leftpos);
			rightpos=strtmp2.Find(">");
			strwind=strtmp2.Right(strtmp2.GetLength()-rightpos-1);
			bGet3=FALSE;
			bNext3=FALSE;
			goto stop;
		}
		
end:
		{}
	}
stop:
	myHttpFile->Close();
	mySession.Close();	
	m_reportlist.SetItemText(isel,1,strweather);
	m_reportlist.SetItemText(isel,2,strtemperature);
	m_reportlist.SetItemText(isel,3,strwind);
}
*/
void CGetAirReportDlg::OnExit()
{
	this->OnCancel();	
}

void CGetAirReportDlg::OnGet()
{
	BOOL bNext1=FALSE,bNext2=FALSE,bNext3=FALSE;
	int leftpos=0;   //取某行源码“</TD>”的位置
	int rightpos=0;  //取某行源码“>”的位置
	int isel=m_reportlist.GetSelectionMark();
	if(isel<0)
	{
		AfxMessageBox("请选择城市");
		return;
	}
	address.Format("%s/%s.html",addressfront,city2[isel][1]);
	strtmp1.Format("city\" >%s",city2[isel][0]);
	CString strsource;
	CInternetSession mySession(NULL,0);
	CHttpFile* myHttpFile=NULL;
	myHttpFile=(CHttpFile*)mySession.OpenURL(address);
	while(myHttpFile->ReadString(strsource))
	{
		//如果某行源码中有提取的字符，开始进行处理
		if(strsource.Find(strtmp1)>0)
			bNext1=TRUE;
		if(bNext1)
		{
			int leftpos=strsource.Find("map-layer-weaher");
	
			if(leftpos>0)
			{
				strtmp2=strsource.Right(strsource.GetLength()-strlen("map-layer-weaher")-leftpos-2);
				rightpos=strtmp2.Find("</div>");
				strtmp2=strtmp2.Left(rightpos);
				strweather=strtmp2;
				bNext1=FALSE;
				bNext2=TRUE;
			}
		}
		if(bNext2)
		{
			int leftpos=strsource.Find("map-layer-temp");
			if(leftpos>0)
			{
				strtmp2=strsource.Right(strsource.GetLength()-strlen("map-layer-temp")-leftpos-2);
				rightpos=strtmp2.Find("</div>");
				strtmp2=strtmp2.Left(rightpos);
				strtemperature=strtmp2;
				bNext2=FALSE;
				bNext3=TRUE;
			}
		}
		if(bNext3)
		{
			int leftpos=strsource.Find("map-layer-wind");
			if(leftpos>0)
			{
				strtmp2=strsource.Right(strsource.GetLength()-strlen("map-layer-wind")-leftpos-2);
				rightpos=strtmp2.Find("</div>");
				strtmp2=strtmp2.Left(rightpos);
				strwind=strtmp2;
				bNext3=FALSE;
			goto end;
			}
		}
		
	}
end:
	myHttpFile->Close();
	mySession.Close();	
	m_reportlist.SetItemText(isel,1,strweather);
	m_reportlist.SetItemText(isel,2,strtemperature);
	m_reportlist.SetItemText(isel,3,strwind);
}
