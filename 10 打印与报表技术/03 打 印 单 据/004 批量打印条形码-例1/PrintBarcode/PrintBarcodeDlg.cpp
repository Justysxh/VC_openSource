// PrintBarcodeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PrintBarcode.h"
#include "PrintBarcodeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

extern _ConnectionPtr pCon;
extern _RecordsetPtr pRecord;

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
// CPrintBarcodeDlg dialog

CPrintBarcodeDlg::CPrintBarcodeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrintBarcodeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrintBarcodeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CPrintBarcodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrintBarcodeDlg)
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_BARCODE, m_Barcode);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPrintBarcodeDlg, CDialog)
	//{{AFX_MSG_MAP(CPrintBarcodeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PRINT, OnPrint)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintBarcodeDlg message handlers

BOOL CPrintBarcodeDlg::OnInitDialog()
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
	

	m_List.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_TWOCLICKACTIVATE);
	m_List.InsertColumn(100,"条形码",LVCFMT_CENTER,100);
	m_List.InsertColumn(100,"商品名称",LVCFMT_CENTER,100);
	m_List.InsertColumn(100,"价格",LVCFMT_CENTER,80);
	m_List.InsertColumn(100,"规格",LVCFMT_CENTER,80);
	m_List.InsertColumn(100,"厂家",LVCFMT_CENTER,100);
	
	CString sql= "Select * from MerchandiseInfo";
	pRecord = pCon->Execute((_bstr_t)sql,NULL,0);
	int row = 0;
	CString data;
	if (pRecord->GetState()==adStateOpen) //有数据返回
	{
		while (! pRecord->ADOEOF)
		{
			m_List.InsertItem(row,"");
			for (int col = 0; col < pRecord->GetFields()->Count; col++)
			{
				data = (char*)(bstr_t)pRecord->GetFields()->GetItem((long)col)->Value;
				m_List.SetItemText(row,col,data);
			}
			row+=1;
			pRecord->MoveNext();
		}
	}
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPrintBarcodeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPrintBarcodeDlg::OnPaint() 
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
HCURSOR CPrintBarcodeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPrintBarcodeDlg::OnPrint() 
{
	CString str;
	//构造打印对话框
	CPrintDialog m_print(false,PD_ALLPAGES | PD_USEDEVMODECOPIES |PD_RETURNDEFAULT| PD_NOPAGENUMS | PD_HIDEPRINTTOFILE | PD_NOSELECTION,this);
	m_Barcode.SetBackColor(RGB(255,255,255));
	if (m_print.DoModal()==IDOK)
	{
		CDC dc1 ;
		dc1.Attach(m_print.GetPrinterDC()); //将dc1关联到打印机句柄
		dc1.StartDoc("print");

		int screenx,screeny;
		int printx,printy;
		float ratex,ratey;
		//确定打印机与屏幕的像素比率
		screenx =  m_Barcode.GetDC()->GetDeviceCaps(LOGPIXELSX);
		screeny =  m_Barcode.GetDC()->GetDeviceCaps(LOGPIXELSY);
		printx =  dc1.GetDeviceCaps(LOGPIXELSX);
		printy =  dc1.GetDeviceCaps(LOGPIXELSY);
		ratex = (float)(printx)/screenx;
		ratey = (float)(printy)/screeny;

		for (int row = 0; row< m_List.GetItemCount();row++)
		{
			str = m_List.GetItemText(row,0);
			m_Barcode.SetValue((COleVariant)str);
			m_Barcode.UpdateWindow();			
			CDC* pBar = m_Barcode.GetDC();
			pBar->SetBkMode(TRANSPARENT);		
			CDC memdc;
			memdc.CreateCompatibleDC(pBar);
			CRect rect;
			m_Barcode.GetClientRect(rect); //获取条形码的客户区域
			CBitmap bitmap;
			bitmap.CreateCompatibleBitmap(pBar,rect.Width(),rect.Height());
			memdc.SelectObject(&bitmap);
			memdc.BitBlt(0,0,rect.Width(),rect.Height(),pBar,0,0,SRCCOPY);
			
			BITMAP bmp ;
			bitmap.GetBitmap(&bmp);
			int panelsize =0; //调色版大小		
			if (bmp.bmBitsPixel<16)
				panelsize =  pow(2,bmp.bmBitsPixel)*sizeof(RGBQUAD);		
			BITMAPINFO* bInfo = (BITMAPINFO*)LocalAlloc(LPTR,sizeof(BITMAPINFO)+panelsize);		
			bInfo->bmiHeader.biBitCount = bmp.bmBitsPixel;
			bInfo->bmiHeader.biClrImportant = 0;
			bInfo->bmiHeader.biClrUsed = 0;
			bInfo->bmiHeader.biCompression = 0;
			bInfo->bmiHeader.biHeight = bmp.bmHeight;
			bInfo->bmiHeader.biPlanes = bmp.bmPlanes;
			bInfo->bmiHeader.biSize = sizeof(BITMAPINFO);
			bInfo->bmiHeader.biSizeImage = bmp.bmWidthBytes*bmp.bmHeight;
			bInfo->bmiHeader.biWidth = bmp.bmWidth;
			bInfo->bmiHeader.biXPelsPerMeter = 0;
			bInfo->bmiHeader.biYPelsPerMeter = 0;

			char* pdata = new char[bmp.bmWidthBytes*bmp.bmHeight];
			GetDIBits(memdc.m_hDC,bitmap,0,bmp.bmHeight,pdata,bInfo,DIB_RGB_COLORS);			

			CDC* pDC = GetDC();
			//开始打印
			int x = bInfo->bmiHeader.biWidth;
			int y = bInfo->bmiHeader.biHeight;
			StretchDIBits(dc1.m_hDC,80,row* (int)(200*ratex),int(x*ratex),int(y*ratey),1,1,x,y,pdata,bInfo,DIB_RGB_COLORS, SRCCOPY);
			delete pdata;
			LocalFree(bInfo );
		}		
		dc1.EndDoc();
	}
}

void CPrintBarcodeDlg::OnCancel() 
{
	CDialog::OnCancel();	
}
