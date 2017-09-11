// browsebmpsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "browsebmps.h"
#include "browsebmpsDlg.h"
#include <direct.h>
#include "io.h"

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
// CBrowsebmpsDlg dialog

CBrowsebmpsDlg::CBrowsebmpsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBrowsebmpsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBrowsebmpsDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBrowsebmpsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBrowsebmpsDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBrowsebmpsDlg, CDialog)
	//{{AFX_MSG_MAP(CBrowsebmpsDlg)
	ON_COMMAND(IDB_AHEAD, OnAhead)
	ON_COMMAND(IDB_NEXT, OnNext)
	ON_COMMAND(IDB_AHEADROW, OnAheadRow)
	ON_COMMAND(IDB_NEXTROW, OnNextRow)
	ON_COMMAND(IDB_OPEN, OnOpen)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBrowsebmpsDlg message handlers

BOOL CBrowsebmpsDlg::OnInitDialog()
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
	m_imagelist.Create(20,20,ILC_COLOR24|ILC_MASK,1,1);
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON3));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON4));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON5));

	m_toolbar.Create(this);
	m_toolbar.ModifyStyle(0, TBSTYLE_FLAT |CBRS_TOOLTIPS |CBRS_SIZE_DYNAMIC | TBSTYLE_TRANSPARENT|TBBS_CHECKBOX );	//改变工具栏属性
	m_toolbar.SetButtons(NULL,5);
	m_toolbar.SetButtonInfo(0, IDB_AHEAD, TBSTYLE_BUTTON, 0);
	m_toolbar.SetButtonText(0,"上一条");
	m_toolbar.SetButtonInfo(1, IDB_NEXT, TBSTYLE_BUTTON, 1);
	m_toolbar.SetButtonText(1,"下一条");
	m_toolbar.SetButtonInfo(2, IDB_AHEADROW, TBSTYLE_BUTTON, 3);
	m_toolbar.SetButtonText(2,"上一组");
	m_toolbar.SetButtonInfo(3, IDB_NEXTROW, TBSTYLE_BUTTON, 2);
	m_toolbar.SetButtonText(3,"下一组");
	m_toolbar.SetButtonInfo(4, IDB_OPEN, TBSTYLE_BUTTON, 4);
	m_toolbar.SetButtonText(4,"打开");
	//关联图像列表
	m_toolbar.GetToolBarCtrl().SetImageList(&m_imagelist);
	m_toolbar.SetSizes(CSize(50,40),CSize(20,20));
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);

	picture[0].Create("",SS_BITMAP,CRect(10,50,280,250),this);//WS_CHILD|
	picture[1].Create("",SS_BITMAP,CRect(300,50,570,250),this);//WS_CHILD|
	picture[2].Create("",SS_BITMAP,CRect(10,260,280,460),this);//WS_CHILD|
	picture[3].Create("",SS_BITMAP,CRect(300,260,570,460),this);//WS_CHILD|
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBrowsebmpsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBrowsebmpsDlg::OnPaint() 
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
HCURSOR CBrowsebmpsDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBrowsebmpsDlg::OnOpen()
{
	CFileDialog m_dialog (true,"bmp",NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"位图文件(*.bmp)|*.bmp",this);
	if (m_dialog.DoModal()==IDOK)
	{
		CString str;
		str = m_dialog.GetPathName();
		strName = m_dialog.GetFileName();
		strText = str;
		strText.Replace(strName,"");
		Loadpicture(str);	
	}
}

void CBrowsebmpsDlg::OnAhead()
{
	strFile[0]= strText + Search(strFile[0],false);
	if(strcmp(strFile[0],strText))
	{
		Loadpicture(strFile[0]);
	}
}
void CBrowsebmpsDlg::OnNext()
{
	strFile[3]= strText + Search(strFile[3],true);
	if(strcmp(strFile[3],strText))
	{
		Loadpicture(strFile[1]);
	}
}
void CBrowsebmpsDlg::OnAheadRow()
{
	for(int i=0;i<4;i++)
	{
		if(strcmp(strFile[0],strText))
		{
			strFile[0]= strText + Search(strFile[0],false);
		}
	}
	if(strcmp(strFile[0],strText))
	{
		Loadpicture(strFile[0]);
	}
}
void CBrowsebmpsDlg::OnNextRow()
{
	strFile[3]= strText + Search(strFile[3],true);
	if(strcmp(strFile[3],strText))
	{
		Loadpicture(strFile[3]);
	}
}

CString CBrowsebmpsDlg::Search(CString curstr,bool judge)
{
	long handle;
	if(curstr.IsEmpty())
		return "";
	if(_getcwd( buffer, 1000)==NULL)
	{
		AfxMessageBox("没有当前路径,请打开一个图像文件!");
		return "";
	}
	
	CString m_sbefore="";
	CString m_sPartname;
	int len = curstr.GetLength();
	int i;
	for(i = len-1;curstr[i] != '\\';i--)
		m_sPartname.Insert(0,curstr[i]);
	i++;
	while(i--<0)
		buffer[i]=curstr[i];
	if (_chdir(buffer) != 0)
		return "";
	
	bool b_notfinde=false;
	struct _finddata_t filestruct;
	// 开始查找工作, 找到当前目录下的第一个实体(文件或子目录)， 
	// ″*″表示查找任何的文件或子目录, filestruct为查找结果 
	handle = _findfirst("*", &filestruct);
	do{
		if((handle ==-1)) // 当handle为－1, 表示当前目录为空, 则结束查找而返回
			break; 
		// 检查找到的第一个实体是否是一个目录 
		if( ::GetFileAttributes(filestruct.name) & FILE_ATTRIBUTE_DIRECTORY )
		{
			continue ;
		}
		CString Filename=filestruct.name;
		{
			CString tailstr;
			tailstr = Filename.Mid(Filename.GetLength()-3);
			tailstr.MakeUpper();
			Filename.MakeUpper();
			m_sPartname.MakeUpper();
			if(tailstr=="BMP")
			{
				if(judge)
				{
					if(b_notfinde==false)
					{
						if(m_sPartname==Filename)
							b_notfinde=true;
					}
					else
					{
						_findclose(handle);
						return Filename;
					}
				}
				else
				{
					if(m_sPartname==Filename)
					{
						_findclose(handle);
						if(m_sbefore=="")
						{
							AfxMessageBox("已经到达第一个图像文件!");
						}
						return m_sbefore;
					}
					b_notfinde=true;
					m_sbefore = Filename;					
				}				
			}			
		}		
	} while(_findnext(handle, &filestruct)==0);
	_findclose(handle);
	if(judge)
	{
		AfxMessageBox("已经到达最后一个图像文件!");
	}
	else
	{
		AfxMessageBox("已经到达第一个图像文件!");
	}
	return "";
}

char szFilter[] = "BMP Files(*.BMP)|*.BMP";

void CBrowsebmpsDlg::Loadpicture(CString str)
{
	
		for(int i=0;i<4;i++)
		{
			if(i != 0)
			{
				str = strText+Search(str,true);
			}
			strFile[i]=str;
			HBITMAP m_hBitmap;
			m_hBitmap=(HBITMAP)::LoadImage(AfxGetInstanceHandle(),str,IMAGE_BITMAP,0,0,
				LR_LOADFROMFILE|LR_DEFAULTCOLOR|LR_DEFAULTSIZE);
			if (m_hBitmap != NULL)
			{
				picture[i].SetImage(m_hBitmap);
				picture[i].ShowWindow(SW_SHOW);
			}
		}
	
}
