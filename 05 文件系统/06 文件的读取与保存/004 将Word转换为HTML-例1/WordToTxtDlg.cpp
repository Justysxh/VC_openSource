// WordToTxtDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WordToTxt.h"
#include "WordToTxtDlg.h"
#include "msword9.h"
#include "COMDEF.H"

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
// CWordToTxtDlg dialog

CWordToTxtDlg::CWordToTxtDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWordToTxtDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWordToTxtDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWordToTxtDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWordToTxtDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWordToTxtDlg, CDialog)
	//{{AFX_MSG_MAP(CWordToTxtDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTCONVERT, OnConvert)
	ON_BN_CLICKED(IDC_BTEXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWordToTxtDlg message handlers

BOOL CWordToTxtDlg::OnInitDialog()
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
	
	AfxOleInit();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWordToTxtDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWordToTxtDlg::OnPaint() 
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
HCURSOR CWordToTxtDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWordToTxtDlg::OnConvert() 
{
	COleVariant covOptional((long)DISP_E_PARAMNOTFOUND,VT_ERROR);
	CString strfile;
	CString strtxt,strext;
	GetDlgItem(IDC_EDFILE)->GetWindowText(strfile);
	_Application app;	
	Documents docs;
	_Document doc;
	COleVariant tmplt(strfile);
	COleVariant newtmp(short(false));
	COleVariant type(short(0));
	COleVariant vble(short(true));
	COleVariant format(short(8));
	app.CreateDispatch("word.Application");
	docs.AttachDispatch(app.GetDocuments());
	doc=docs.Add(&tmplt,&newtmp,&type,&vble);
	
	strext=GetFileExt(strfile);
	strtxt=strfile.Left(strfile.GetLength()-strext.GetLength());
	if(strtxt.Right(1)==".")
	strtxt+="html";
	COleVariant file(strtxt);

	doc.SaveAs(file,format,covOptional,covOptional,covOptional,covOptional,
		covOptional,covOptional,covOptional,covOptional,covOptional);
	app.Quit(&COleVariant(short(false)),&COleVariant(short(0)),&COleVariant(short(false)));
	docs.ReleaseDispatch();
	doc.ReleaseDispatch();
	app.ReleaseDispatch();
}

void CWordToTxtDlg::OnExit() 
{
	OnCancel();	
}

CString CWordToTxtDlg::GetFileExt(CString filepath)
{
	CString tmp;
	CString pathname,strname,strext,strtitle,strpath;
	strname=filepath;
	int namelen=strname.GetLength();
	int pos=strname.Find(".");
	if(pos<0)
	{
		//无扩展名情况
		strext="";
	}
	else
	{
		//获取.后面的字符串，如果是单扩展名，该字符串就是扩展名
		tmp=strname.Right(namelen-pos-1);
		pos=tmp.Find(".");
		if(pos<0)
			strext=tmp;
		else
		{
			//非单扩展名，tmp为第二个扩展名
			tmp=tmp.Right(tmp.GetLength()-pos-1);
			while(pos>0)
			{
				pos=tmp.Find(".");
				if(pos<0)//没有下一个扩展名
					strext=tmp;
				else
					tmp=tmp.Right(tmp.GetLength()-pos-1);
			}
			strext=tmp;
		}		
	}
	return strext;
}
