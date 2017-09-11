// PrintBearingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PrintBearing.h"
#include "PrintBearingDlg.h"

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
// CPrintBearingDlg dialog

CPrintBearingDlg::CPrintBearingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrintBearingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrintBearingDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPrintBearingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrintBearingDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPrintBearingDlg, CDialog)
	//{{AFX_MSG_MAP(CPrintBearingDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTPRINT, OnButprint)
	ON_BN_CLICKED(IDC_BUTEXIT, OnButexit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintBearingDlg message handlers

BOOL CPrintBearingDlg::OnInitDialog()
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
	merchandise[0][0]= "商品编号";
	merchandise[1][0]= "商品名称";
	merchandise[2][0]= "数量";
	merchandise[3][0]= "单价";

	merchandise[0][1]= "S001";
	merchandise[0][2]= "S002";
	merchandise[0][3]= "S003";
	merchandise[0][4]= "S004";

	merchandise[1][1]= "手机";
	merchandise[1][2]= "电视";
	merchandise[1][3]= "空调";
	merchandise[1][4]= "电脑";

	merchandise[2][1]= "200";
	merchandise[2][2]= "300";
	merchandise[2][3]= "400";
	merchandise[2][4]= "500";

	merchandise[3][1]= "1200";
	merchandise[3][2]= "2500";
	merchandise[3][3]= "3200";
	merchandise[3][4]= "5000";
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPrintBearingDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPrintBearingDlg::OnPaint() 
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
	CRect rect;
	GetClientRect(rect);	
	CDC* pDC = GetDC();
	screenx = pDC->GetDeviceCaps(LOGPIXELSX);
	screeny = pDC->GetDeviceCaps(LOGPIXELSY);
	titlefont.CreatePointFont(200,"宋体",pDC);
	bodyfont.CreatePointFont(120,"宋体",pDC);
	rect.DeflateRect(0,15,0,0);	
	pDC->SelectObject(&titlefont);	
	pDC->DrawText("商品销售排行",rect,DT_CENTER);			
	pDC->SelectObject(&bodyfont);
	CRect m_rect(rect);
	CRect temprect(m_rect.left+80,m_rect.top+60,40+(m_rect.Width())/4,m_rect.bottom+100);
	CRect itemrect;
	int width = temprect.Width();
	for (int i = 0;i<4;i++)
	{
		pDC->DrawText(merchandise[i][0],temprect,DT_LEFT);
		itemrect.CopyRect(temprect);
		for (int y = 1; y< 5;y++)
		{
			itemrect.DeflateRect(0,50);
			pDC->DrawText(merchandise[i][y],itemrect,DT_LEFT);						
		}
		temprect.DeflateRect(width,0,0,0);
		temprect.InflateRect(0,0,width,0);	
	}	
	titlefont.DeleteObject();
	bodyfont.DeleteObject();
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPrintBearingDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

HBRUSH CPrintBearingDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	CBrush m_brush (RGB(255,255,255));	
	CRect m_rect;
	GetClientRect(m_rect);
	pDC->FillRect(m_rect,&m_brush);
	// TODO: Return a different brush if the default is not desired
	return m_brush;
}

void CPrintBearingDlg::OnButprint() 
{
	// TODO: Add your control notification handler code here
	DWORD dwflags=PD_ALLPAGES | PD_NOPAGENUMS | PD_USEDEVMODECOPIES
		| PD_SELECTION | PD_HIDEPRINTTOFILE; 
	CPrintDialog dlg(false,dwflags,NULL);
	if(dlg.DoModal() == IDOK)
	{
		LPDEVMODE dev = dlg.GetDevMode();
		dev->dmFields = DM_PAPERSIZE | DM_PAPERWIDTH 
					| DM_PAPERLENGTH | dev->dmFields;
		dev->dmFields = dev->dmFields | DMBIN_MANUAL;
		dev->dmDefaultSource = DMBIN_MANUAL;
		dev->dmOrientation = DMORIENT_LANDSCAPE;
		char aa[32] = "自定义";		
		strcpy((char*)dev->dmFormName,aa);

		CDC dc;
		dc.Attach(dlg.CreatePrinterDC());
		CDC* pDC = &dc;
		int leftmargin;
		leftmargin = dc.GetDeviceCaps(PHYSICALOFFSETX);
		CRect rect(-leftmargin,0,dc.GetDeviceCaps(PHYSICALWIDTH)-leftmargin,dc.GetDeviceCaps(PHYSICALHEIGHT)) ;		
		titlefont.CreatePointFont(200,"宋体",pDC);
		bodyfont.CreatePointFont(120,"宋体",pDC);	
		int printx,printy;
		printx = pDC->GetDeviceCaps(LOGPIXELSX);
		printy = pDC->GetDeviceCaps(LOGPIXELSY);

		double ratex = (double)(printx)/screenx;
		double ratey = (double)(printy)/screeny;
		rect.DeflateRect(0,(int)(ratey*15),0,0);		
		pDC->SelectObject(&titlefont);		
		pDC->StartDoc("print");
		pDC->DrawText("商品销售排行",rect,DT_CENTER);		
		pDC->SelectObject(&bodyfont);
		CRect m_rect(rect);
		CRect temprect(m_rect.left+(int)(80*ratex),m_rect.top+(int)(60*ratey),
			(int)(ratey*40)+(m_rect.Width())/4,m_rect.bottom+(int)(ratey*100));
		CRect itemrect;
		int width = temprect.Width();

		for (int i = 0;i<4;i++)
		{
			pDC->DrawText(merchandise[i][0],temprect,DT_LEFT);
			itemrect.CopyRect(temprect);
			for (int y = 1; y< 5;y++)
			{
				itemrect.DeflateRect(0,(int)(ratey*50));
				pDC->DrawText(merchandise[i][y],itemrect,DT_LEFT);						
			}			
			temprect.DeflateRect(width,0,0,0);
			temprect.InflateRect(0,0,width,0);		
		}
		titlefont.DeleteObject();
		bodyfont.DeleteObject();
	}
}

void CPrintBearingDlg::OnButexit() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}
