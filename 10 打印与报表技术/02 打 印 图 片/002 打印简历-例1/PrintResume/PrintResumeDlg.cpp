// PrintResumeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PrintResume.h"
#include "PrintResumeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern _ConnectionPtr m_pCon;
extern _RecordsetPtr m_pRecord;

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
// CPrintResumeDlg dialog

CPrintResumeDlg::CPrintResumeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrintResumeDlg::IDD, pParent)
{
	isInited = FALSE;
	hbitmap = 0;
	//{{AFX_DATA_INIT(CPrintResumeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPrintResumeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrintResumeDlg)

	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPrintResumeDlg, CDialog)
	//{{AFX_MSG_MAP(CPrintResumeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONPRINT, OnButtonprint)
	ON_COMMAND(ID_MENUITEM32771, OnMenuitem32771)
	ON_COMMAND(IDB_PRIOR, OnMovePrior)
	ON_COMMAND(IDB_NEXT, OnMoveNext)
	ON_COMMAND(IDB_PRINT, OnPrint)
	ON_COMMAND(IDB_QUIT, OnQuit)
	ON_WM_CTLCOLOR()
	ON_WM_SIZE()
	ON_WM_GETMINMAXINFO()
	ON_WM_SIZING()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintResumeDlg message handlers

BOOL CPrintResumeDlg::OnInitDialog()
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
	
	m_imagelist.Create(22,22,ILC_COLOR24|ILC_MASK,2,2);


	//添加图标
	for(int i = 0;i<7;i++)
	{
		m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON1+i));
	}

	m_rebar.Create(this,RBS_BANDBORDERS|RBS_AUTOSIZE);

	m_toolbar.CreateEx(&m_rebar);
	
	m_toolbar.GetToolBarCtrl().SetImageList(&m_imagelist);


	m_toolbar.ModifyStyle(0, TBSTYLE_FLAT |CBRS_TOOLTIPS |CBRS_SIZE_DYNAMIC | TBSTYLE_TRANSPARENT|TBBS_CHECKBOX );	//改变工具栏属性
	m_toolbar.SetButtons(NULL,4);


	m_toolbar.SetButtonInfo(0, IDB_PRIOR, TBSTYLE_BUTTON, 1);
	m_toolbar.SetButtonText(0,"上一条");

	m_toolbar.SetButtonInfo(1, IDB_NEXT, TBSTYLE_BUTTON, 2);
	m_toolbar.SetButtonText(1,"下一条");

	m_toolbar.SetButtonInfo(2, IDB_PRINT, TBSTYLE_BUTTON,3);
	m_toolbar.SetButtonText(2,"打印");

	m_toolbar.SetButtonInfo(3, IDB_QUIT, TBSTYLE_BUTTON,4);
	m_toolbar.SetButtonText(3,"关闭");

	m_toolbar.SetSizes(CSize(50,40),CSize(20,20));

	m_rebar.AddBar(&m_toolbar);
	//m_rebar.ModifyStyle(0,);



//	m_toolbar.ShowWindow(SW_SHOW);
	
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,1);

	CString sql = "select * from resume";
	
	m_pRecord->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenKeyset,adLockOptimistic,adCmdText);
	
	isInited = TRUE;
	hbitmap = GetBitmapFromField();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPrintResumeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPrintResumeDlg::OnPaint() 
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

	if (isInited)
	{
		CDC* pDC = GetDC();
		CRect m_rect;
		GetClientRect(m_rect);
		DrawReport(pDC,m_rect,false);
		RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,1);	
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPrintResumeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPrintResumeDlg::OnOK() 
{
	
	//CDialog::OnOK();
}

void CPrintResumeDlg::OnButtonprint() 
{
 
}

void CPrintResumeDlg::OnMenuitem32771() 
{
	
}

void CPrintResumeDlg::OnMovePrior()
{
	if (! m_pRecord->BOF)
	{
		m_pRecord->MovePrevious();
		if(m_pRecord->BOF)
			m_pRecord->MoveFirst();
		hbitmap = GetBitmapFromField();
		OnPaint();
	}
}

void CPrintResumeDlg::OnPrint()
{
	if (isInited)
	{
		CDC  m_PrinterDC ;
		CPrintDialog m_pdlg(FALSE);

		if (m_pdlg.DoModal()==IDOK)
		{


			m_PrinterDC.Attach(m_pdlg.GetPrinterDC());
			tempDC = GetDC();
			CRect m_rect;
			GetClientRect(m_rect);
			
			OnPaint();
			DrawReport(&m_PrinterDC,m_rect,TRUE);
		}
		RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,1);	
	}
}

void CPrintResumeDlg::OnMoveNext()
{
	if ( m_pRecord->ADOEOF==FALSE)
	{
		m_pRecord->MoveNext();
		if (m_pRecord->ADOEOF)
			m_pRecord->MoveLast();
		hbitmap = GetBitmapFromField();
		OnPaint();
	}
}

void CPrintResumeDlg::OnQuit()
{
	PostQuitMessage(0);

}

HBRUSH CPrintResumeDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	CBrush brush (RGB(255,255,255));
	CRect m_rect ;
	GetClientRect(m_rect);
	pDC->FillRect(m_rect,&brush);

	return brush;
}

void CPrintResumeDlg::OnSize(UINT nType, int cx, int cy) 
{

	OnPaint();
}


void CPrintResumeDlg::DrawReport(CDC* pDC,CRect m_rect,BOOL isPrinted)
{
	CString c_name,c_sex,c_age,c_knowledge,c_degree,c_phone,c_workground,c_suit,c_other;

	if ((! m_pRecord->ADOEOF)&&(! m_pRecord->BOF))
	{
		c_name = (TCHAR*)(_bstr_t)m_pRecord->GetFields()->GetItem((long)1)->Value;
		c_sex = (TCHAR*)(_bstr_t)m_pRecord->GetFields()->GetItem((long)2)->Value;
		c_age = (TCHAR*)(_bstr_t)m_pRecord->GetFields()->GetItem((long)3)->Value;
		c_knowledge = (TCHAR*)(_bstr_t)m_pRecord->GetFields()->GetItem((long)4)->Value;
		c_degree = (TCHAR*)(_bstr_t)m_pRecord->GetFields()->GetItem((long)5)->Value;
		c_phone = (TCHAR*)(_bstr_t)m_pRecord->GetFields()->GetItem((long)6)->Value;
		c_workground = (TCHAR*)(_bstr_t)m_pRecord->GetFields()->GetItem((long)7)->Value;
		c_suit = (TCHAR*)(_bstr_t)m_pRecord->GetFields()->GetItem((long)8)->Value;
		c_other = (TCHAR*)(_bstr_t)m_pRecord->GetFields()->GetItem((long)10)->Value;
	}

	if (! isPrinted)
	{
		screenx = pDC->GetDeviceCaps(LOGPIXELSX);
		screeny = pDC->GetDeviceCaps(LOGPIXELSY);


		m_rect.DeflateRect(0,60,0,0);
		pDC->FillRect(&m_rect,NULL);
		pDC->DrawText("个人简历",m_rect,DT_CENTER);

		m_rect.DeflateRect(0,20);
		//绘制边框

		CRect m_framerect (m_rect);
		m_framerect.DeflateRect(10,10,10,10);
		CBrush m_brush;

		m_brush.CreateStockObject(BLACK_BRUSH);
		pDC->FrameRect(&m_framerect,&m_brush);

		//绘制横向区域

		CRect rect(10,90,410,120);
		pDC->FrameRect(&rect,&m_brush);

	
		rect.InflateRect(0,-29,0,30);
		pDC->FrameRect(&rect,&m_brush);

		rect.InflateRect(0,-30,0,30);
		pDC->FrameRect(&rect,&m_brush);

		rect.InflateRect(0,-30,m_rect.Width()-420,30); 
		pDC->FrameRect(&rect,&m_brush);

		rect.InflateRect(0,0,0,80);
		pDC->FrameRect(&rect,&m_brush);

		rect.InflateRect(0,-30,0,30);
		pDC->FrameRect(&rect,&m_brush);


		rect.InflateRect(0,0,0,80);
		pDC->FrameRect(&rect,&m_brush);

		rect.InflateRect(0,0,0,30);  
		pDC->FrameRect(&rect,&m_brush);

		//绘制纵向区域
		CRect verrect(10,90,80,180);
		pDC->FrameRect(&verrect,&m_brush);

		verrect.InflateRect(-69,0,130,0);
		pDC->FrameRect(&verrect,&m_brush);

		verrect.InflateRect(-130,0,70,0);
		pDC->FrameRect(&verrect,&m_brush);

		//绘制文本
		/**************************************************************/
		CRect textrect(10,90,80,120);
		pDC->DrawText("姓名",&textrect,DT_VCENTER|DT_SINGLELINE|DT_CENTER);

		textrect.InflateRect(-70,0,130,0);
		pDC->DrawText(c_name,&textrect,DT_VCENTER|DT_SINGLELINE|DT_LEFT);
	

		textrect.InflateRect(-130,0,70,0);
		pDC->DrawText("学历",&textrect,DT_VCENTER|DT_SINGLELINE|DT_CENTER);

		textrect.InflateRect(-70,0,130,0);
		pDC->DrawText(c_knowledge,&textrect,DT_VCENTER|DT_SINGLELINE|DT_LEFT);

		/**************************************************************/
		CRect rect2(10,120,80,150);
		pDC->DrawText("性别",&rect2,DT_VCENTER|DT_SINGLELINE|DT_CENTER);

		rect2.InflateRect(-70,0,130,0);
		pDC->DrawText(c_sex,&rect2,DT_VCENTER|DT_SINGLELINE|DT_LEFT);
		

		rect2.InflateRect(-130,0,70,0);
		pDC->DrawText("电话",&rect2,DT_VCENTER|DT_SINGLELINE|DT_CENTER);

		rect2.InflateRect(-70,0,130,0);
		pDC->DrawText(c_phone,&rect2,DT_VCENTER|DT_SINGLELINE|DT_LEFT);

		/**************************************************************/
		CRect rect3(10,150,80,180);
		pDC->DrawText("年龄",&rect3,DT_VCENTER|DT_SINGLELINE|DT_CENTER);

		rect3.InflateRect(-70,0,130,0);
		pDC->DrawText(c_age,&rect3,DT_VCENTER|DT_SINGLELINE|DT_LEFT);
		

		rect3.InflateRect(-130,0,70,0);
		pDC->DrawText("政治面貌",&rect3,DT_VCENTER|DT_SINGLELINE|DT_CENTER);

		rect3.InflateRect(-70,0,130,0);
		pDC->DrawText(c_degree,&rect3,DT_VCENTER|DT_SINGLELINE|DT_LEFT);	
		
		/**************************************************************/
		
		CRect rect4(10+10,180,90,210);
		pDC->DrawText("工作经验",&rect4,DT_VCENTER|DT_SINGLELINE|DT_LEFT);

		rect4.InflateRect(-20,-30,m_rect.Width()-90+20,80);
		pDC->DrawText(c_workground,&rect4,DT_LEFT);

		/**************************************************************/
	
		CRect rect5(10+10,290,90,320);
		pDC->DrawText("特长",&rect5,DT_VCENTER|DT_SINGLELINE|DT_LEFT);

		rect5.InflateRect(-20,-30,m_rect.Width()-90+20,80);
		pDC->DrawText(c_suit,&rect5,DT_LEFT);

		/**************************************************************/
			
		CRect rect6(10+10,400,90,430);
		pDC->DrawText("其他",&rect6,DT_VCENTER|DT_SINGLELINE|DT_LEFT);

		rect6.InflateRect(-20,-30,m_rect.Width()-90+20,80);
		pDC->DrawText(c_other,&rect6,DT_LEFT);

		/**************************************************************/
		m_bitmap.Attach(hbitmap);

		CDC memdc;
		memdc.CreateCompatibleDC(pDC);
		memdc.SelectObject(&m_bitmap);

		pDC->StretchBlt(410,92,100,98,&memdc,0,0,100,100,SRCCOPY);
		m_bitmap.Detach();

	}
	else
	{
			printerx = pDC->GetDeviceCaps(LOGPIXELSX);
			printery = pDC->GetDeviceCaps(LOGPIXELSY);

			ratex = (double)printerx/screenx;
			ratey = (double)printery/screeny;

			m_rect.DeflateRect(10,60,0,-60);
	
			CClientDC dc(this);
			CDC memdc;
			CRect rect;
			memdc.CreateCompatibleDC(&dc);

			GetClientRect(rect);
			
			rect.DeflateRect(10,60,0,-60);


			bitmap.CreateCompatibleBitmap(&dc,rect.Width(),rect.Height());

			CBitmap* oldbitmap = memdc.SelectObject(&bitmap);

			memdc.BitBlt(0,0,rect.Width(),rect.Height(),&dc,0,0,SRCCOPY);

			rect.InflateRect(10,60,0,0);

			pDC->StartDoc("firstdoc");
			pDC->StretchBlt(0,0,(int)(ratex*(rect.Width()-10)),(int)(ratey*(rect.Height()-60)),&memdc,10,60,rect.Width()-10,rect.Height()-60,SRCCOPY);
			pDC->EndDoc();

			bitmap.DeleteObject();		
	}
}

void CPrintResumeDlg::OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI) 
{

	CDialog::OnGetMinMaxInfo(lpMMI);
}

void CPrintResumeDlg::OnSizing(UINT fwSide, LPRECT pRect) 
{
	CDialog::OnSizing(fwSide, pRect);	
}

HBITMAP CPrintResumeDlg::GetBitmapFromField()
{
	if ((! m_pRecord->ADOEOF)&&(!m_pRecord->BOF))
	{
		_variant_t m_bitdata;
		static char* m_bitbuffer;
		char* m_buffer = NULL;
		char* temp = NULL;
		long m_factsize =  m_pRecord->GetFields()->GetItem("照片")->ActualSize;
		
		//获取位图所有数据
		m_bitdata = m_pRecord->GetFields()->GetItem((long)9)->GetChunk(m_factsize);
		HBITMAP m_hmap ;

		if (m_bitdata.vt==VT_ARRAY |VT_UI1)
		{
			//定义一个数据缓冲区	
			m_bitbuffer = new char[m_factsize];
			//将m_buffer指向m_bitdata
			SafeArrayAccessData(m_bitdata.parray,(void**)&m_buffer);
			//复制位图数据到m_bitbuffer;
			memcpy(m_bitbuffer,m_buffer,m_factsize);

			SafeArrayUnaccessData(m_bitdata.parray);

			void* m_factbitdata ; //实际的位图数据

			//temp指向位图信息头
			temp = m_bitbuffer+sizeof(BITMAPFILEHEADER);

			BITMAPINFOHEADER * m_bitheader = (BITMAPINFOHEADER*)temp;

			//获取位图信息,它包括位图信息头和调色板
			BITMAPINFO* m_bitinfo = (BITMAPINFO*)temp;

			//获取位图的实际数据
			m_factbitdata = (void*)(m_buffer+((LPBITMAPFILEHEADER)m_bitbuffer)->bfOffBits);
			
			CClientDC m_dc(this);
			//创建位图
			hbitmap = CreateDIBitmap(m_dc.m_hDC,m_bitheader,CBM_INIT,m_factbitdata,m_bitinfo,DIB_RGB_COLORS);
			delete [] m_bitbuffer;			
		}
	}
	return hbitmap;
}
