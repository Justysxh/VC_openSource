// TextNewMenuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TextNewMenu.h"
#include "TextNewMenuDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextNewMenuDlg dialog

CTextNewMenuDlg::CTextNewMenuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTextNewMenuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTextNewMenuDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTextNewMenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTextNewMenuDlg)
	DDX_Control(pDX, IDC_EDTEXT, m_mytext);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTextNewMenuDlg, CDialog)
	//{{AFX_MSG_MAP(CTextNewMenuDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_VIEW1, OnView1)
	ON_COMMAND(ID_VIEW2, OnView2)
	ON_COMMAND(ID_VIEW3, OnView3)
	ON_COMMAND(ID_VIEW4, OnView4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextNewMenuDlg message handlers

BOOL CTextNewMenuDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	menu.LoadMenu(IDR_TEXTMENU);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTextNewMenuDlg::OnPaint() 
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
HCURSOR CTextNewMenuDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CTextNewMenuDlg::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message==WM_RBUTTONUP && pMsg->hwnd==m_mytext.m_hWnd)
	{
		CMenu* pPopup =menu.GetSubMenu(0);
		CRect rc;
		CPoint point=pMsg->pt;
		rc.top=point.x;
		rc.left=point.y;
		pPopup->TrackPopupMenu(TPM_LEFTALIGN|TPM_LEFTBUTTON|TPM_VERTICAL,rc.top
					   ,rc.left,this,&rc);
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CTextNewMenuDlg::OnView1() 
{
	AfxMessageBox("获取字符");
	
}

void CTextNewMenuDlg::OnView2() 
{
	AfxMessageBox("去除空字符");
}

void CTextNewMenuDlg::OnView3() 
{
	AfxMessageBox("去除非英文字符");
}

void CTextNewMenuDlg::OnView4() 
{
	AfxMessageBox("去除非数字字符");
}
