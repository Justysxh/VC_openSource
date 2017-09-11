// FetchPageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FetchPage.h"
#include "FetchPageDlg.h"

#include <atlbase.h>
#include <Mshtml.h>
#include "comdef.h"

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
// CFetchPageDlg dialog

CFetchPageDlg::CFetchPageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFetchPageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFetchPageDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pSHWnd = NULL;
	m_Num = 0;
}

void CFetchPageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFetchPageDlg)
	DDX_Control(pDX, IDC_LIST1, m_List);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFetchPageDlg, CDialog)
	//{{AFX_MSG_MAP(CFetchPageDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOOKUP, OnLookup)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFetchPageDlg message handlers

BOOL CFetchPageDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	//初始化COM
	CoInitialize(NULL);
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
	
	m_List.SetExtendedStyle(LVS_EX_CHECKBOXES|LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_List.InsertColumn(0, "链接地址", LVCFMT_LEFT, 350);
	m_List.InsertColumn(1, "主机名称", LVCFMT_LEFT, 130);

	if (m_pSHWnd == NULL){
		if (m_pSHWnd.CreateInstance(__uuidof(SHDocVw::ShellWindows)) != S_OK)
		{
			MessageBox("创建外壳窗口失败");
			OnCancel();
		}	
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFetchPageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFetchPageDlg::OnPaint() 
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
HCURSOR CFetchPageDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFetchPageDlg::OnOK() 
{
	
}

void CFetchPageDlg::OnLookup() 
{
	TCHAR host[MAX_COMPUTER];

	CComPtr<IDispatch> spDispatch;
	CComQIPtr<IHTMLDocument2, &IID_IHTMLDocument2> pDoc2;
	CComPtr<IHTMLElementCollection> pElementCol;
	CComPtr<IHTMLAnchorElement> pLoct;

	int rowcount = m_List.GetItemCount();

	for (int i = 0; i < rowcount; i ++)
	{
		IWebBrowser2 *pBrowser = (IWebBrowser2 *)m_List.GetItemData(i);
		if (pBrowser)
		{
			pBrowser->Release();
		}
	}

	m_List.DeleteAllItems();
	m_Num = 0;

	if (m_pSHWnd)
	{
		int n = m_pSHWnd->GetCount();
		for (int i = 0; i < n; i++)
		{
			_variant_t v = (long)i;
			IDispatchPtr spDisp = m_pSHWnd->Item(v);


			SHDocVw::IWebBrowser2Ptr spBrowser(spDisp); 
			if (spBrowser){

				if (SUCCEEDED(spBrowser->get_Document( &spDispatch)))
					pDoc2 = spDispatch;
				if(pDoc2!=NULL)
				{
					if (SUCCEEDED(pDoc2->get_links(&pElementCol)))
					{
						DWORD len=0;
						if(SUCCEEDED(pElementCol->get_length((long*)&len)))
							if(len!=0)
							{   
								m_Num = m_Num+len;
								UpdateData(FALSE);

								for(long i=0;i<=(len-1);i++)
								{

									CComBSTR String;
									_variant_t index = i;
									if(SUCCEEDED(pElementCol->item( index, index, &spDispatch)))
									if(SUCCEEDED(spDispatch->QueryInterface( IID_IHTMLAnchorElement,(void **) &pLoct)))

									pLoct->get_href(&String);
									
									memset(host,0,MAX_COMPUTER);
									lstrcpy(host,_bstr_t(String)); 
									//添加到列表
									m_List.InsertItem(i,host);
									m_List.SetCheck(i,TRUE);
                                   
									pLoct->get_hostname(&String);
                                    
									memset(host,0,MAX_COMPUTER);

									strcpy(host,_bstr_t(String)); 
									if(strlen(host))
									{
										m_List.SetItemText(i,1,host);
									}
								}
							}
					}

				}

			}
		}
	}
}

void CFetchPageDlg::OnCancel()
{

	CDialog::OnCancel();
}


