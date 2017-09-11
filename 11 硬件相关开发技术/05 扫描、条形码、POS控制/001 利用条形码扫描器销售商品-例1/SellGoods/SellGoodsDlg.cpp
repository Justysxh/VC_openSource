// SellGoodsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SellGoods.h"
#include "SellGoodsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

extern _ConnectionPtr m_pCon;
extern _RecordsetPtr  m_pRecord;

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
// CSellGoodsDlg dialog

CSellGoodsDlg::CSellGoodsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSellGoodsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSellGoodsDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSellGoodsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSellGoodsDlg)
	DDX_Control(pDX, IDC_SAVE, m_Save);
	DDX_Control(pDX, IDC_LISTINFO, m_ListInfo);
	DDX_Control(pDX, IDC_BARCODE, m_Barcode);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSellGoodsDlg, CDialog)
	//{{AFX_MSG_MAP(CSellGoodsDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSellGoodsDlg message handlers

BOOL CSellGoodsDlg::OnInitDialog()
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
	
	m_ListInfo.SetTextColor(RGB(255,0,0));
	//设置列表扩展风格
	m_ListInfo.SetExtendedStyle(LVS_EX_FLATSB |LVS_EX_TWOCLICKACTIVATE |LVS_EX_FULLROWSELECT |LVS_EX_GRIDLINES|LVS_EX_UNDERLINEHOT);
	//添加列
	m_ListInfo.InsertColumn(1,"条形码",LVCFMT_CENTER,120);
	m_ListInfo.InsertColumn(2,"商品名称",LVCFMT_CENTER,120);
	m_ListInfo.InsertColumn(3,"价格",LVCFMT_CENTER,60);
	m_ListInfo.InsertColumn(4,"数量",LVCFMT_CENTER,60);
	m_ListInfo.InsertColumn(5,"总计",LVCFMT_CENTER,80);

	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSellGoodsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSellGoodsDlg::OnPaint() 
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
HCURSOR CSellGoodsDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSellGoodsDlg::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

BOOL CSellGoodsDlg::PreTranslateMessage(MSG* pMsg) 
{
	//截获编辑框的WM_KEYDOWN消息
	if ((pMsg->hwnd==m_Barcode.m_hWnd)&&(pMsg->message==WM_KEYDOWN))
		if (pMsg->wParam==13)
			OnEditEnter();
	return CDialog::PreTranslateMessage(pMsg);
}

void CSellGoodsDlg::OnEditEnter()
{
	CString str;
	m_Barcode.GetWindowText(str);
	if (str.IsEmpty())
		return;
	
	CString sql;
	sql.Format("select * from MerchandiseInfo where Barcode = '%s'",str);

	m_pRecord->raw_Close();
	m_pRecord->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	
	CString c_barcode,c_name,c_price;
	
	int row = 0;
	CString temp;
	
	int   num; 
	float price;

	while (m_pRecord->ADOEOF==FALSE)
	{
		c_barcode =(char*)(_bstr_t) m_pRecord->GetFields()->GetItem("Barcode")->Value;
		c_name = (char*)(_bstr_t) m_pRecord->GetFields()->GetItem("MerchandiseName")->Value;
		c_price =  (char*)(_bstr_t) m_pRecord->GetFields()->GetItem("Price")->Value;
		
		int currow = IsExistInList(c_barcode);
		if (currow==-1) //添加新行
		{
			m_ListInfo.InsertItem(row,"");
			m_ListInfo.SetItemText(row,0,c_barcode);
			m_ListInfo.SetItemText(row,1,c_name);
			m_ListInfo.SetItemText(row,2,c_price);
			m_ListInfo.SetItemText(row,3,"1");
			m_ListInfo.SetItemText(row,4,c_price);
		}
		else  //修改现有行
		{
			temp = m_ListInfo.GetItemText(currow,3); //获取数量
			num = atoi(temp);
			num+=1;
			temp.Format("%d",num);
			m_ListInfo.SetItemText(currow,3,temp);
			
			temp = m_ListInfo.GetItemText(currow,4);  //获取总计
			price = atof(temp)+ atof(c_price);
			temp.Format("%8.2f",price);
			m_ListInfo.SetItemText(currow,4,temp);
		}
		m_pRecord->MoveNext();
	}
	m_Barcode.SetWindowText("");
}

int  CSellGoodsDlg::IsExistInList(CString barcode)
{
	CString str;
	for (int row = 0; row<m_ListInfo.GetItemCount();row++)
	{
		str = m_ListInfo.GetItemText(row,0);
		if (str==barcode)
			return row;
	}
	return -1;
}

void CSellGoodsDlg::OnSave() 
{
	if (m_ListInfo.GetItemCount()<1)
	{
		MessageBox("销售信息不能为空.","提示",64);
		return;
	}
	
	CString sql;
	CString c_barcode,c_num,c_total;
	try
	{
		for (int i = 0; i<m_ListInfo.GetItemCount();i++)
		{
			c_barcode = m_ListInfo.GetItemText(i,0);
			c_num   = m_ListInfo.GetItemText(i,3);
			c_total = m_ListInfo.GetItemText(i,4);
			sql.Format("insert into SellDetail values ('%s',%i,%f)",c_barcode,atoi(c_num),atof(c_total));
			m_pRecord->raw_Close();
			
			m_pRecord->Open((_variant_t)sql,m_pCon.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
		}
		MessageBox("操作成功");
		m_ListInfo.DeleteAllItems();
	}
	catch(...)
	{
		MessageBox("操作失败");
	}
}
