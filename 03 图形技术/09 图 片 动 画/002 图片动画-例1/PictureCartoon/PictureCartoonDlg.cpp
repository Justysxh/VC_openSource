// PictureCartoonDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PictureCartoon.h"
#include "PictureCartoonDlg.h"
#include "cmath"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define PI 2.0*asin(1.0)
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
// CPictureCartoonDlg dialog

CPictureCartoonDlg::CPictureCartoonDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPictureCartoonDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPictureCartoonDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPictureCartoonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPictureCartoonDlg)
	DDX_Control(pDX, IDC_PICTURE, m_picture);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPictureCartoonDlg, CDialog)
	//{{AFX_MSG_MAP(CPictureCartoonDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPictureCartoonDlg message handlers

BOOL CPictureCartoonDlg::OnInitDialog()
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
	lpi=0;
	arrays[0] = CPoint(148,0);
	n=40;
	for(int i=1;i<n;i++)
	{
		lpi+=(2*PI/n);
		if(lpi<=2*PI/4)
		{
			arrays[i] = CPoint(148+148*sin(2*i*PI/n),148-148*cos(2*i*PI/n));
		}
		if(lpi>2*PI/4 && lpi<=2*PI/2)
		{
			arrays[i] = CPoint(148+148*sin(PI-2*i*PI/n),148+148*cos(PI-2*i*PI/n));
		}
		if(lpi>2*PI/2 && lpi<=2*PI*3/4)
		{
			arrays[i] = CPoint(148-148*sin(2*i*PI/n-2*PI/2),148+148*cos(2*i*PI/n-2*PI/2));
		}
		if(lpi>2*PI*3/4 && lpi<=2*PI)
		{
			arrays[i] = CPoint(148-148*sin(2*PI-2*i*PI/n),148-148*cos(2*PI-2*i*PI/n));
		}
	}
	result = true;
	SetTimer(1,300,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPictureCartoonDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPictureCartoonDlg::OnPaint() 
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
HCURSOR CPictureCartoonDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPictureCartoonDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rc;
	m_picture.GetClientRect(&rc);
	CDC* pDC = m_picture.GetDC();
	pDC->FillRect(&rc,NULL);
	CPen pen;
	pen.CreatePen(PS_SOLID,1,RGB(0,0,255));
	pDC->SelectObject(&pen);
	if(result)
	{
		for(int j=0;j<n;j=j+2)
		{	
			for(int k=0;k<=j;k=k+2)
			{
				pDC->MoveTo(arrays[j]);
				pDC->LineTo(arrays[k]);
			}
		}
	}
	else
	{
		for(int j=1;j<=n;j=j+2)
		{	
			for(int k=1;k<=j;k=k+2)
			{
				pDC->MoveTo(arrays[j]);
				pDC->LineTo(arrays[k]);
			}
		}
	}
	result = !result;
	CDialog::OnTimer(nIDEvent);
}
