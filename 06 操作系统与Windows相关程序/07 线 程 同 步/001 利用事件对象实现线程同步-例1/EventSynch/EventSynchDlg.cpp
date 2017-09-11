// EventSynchDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EventSynch.h"
#include "EventSynchDlg.h"
#include <afxmt.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEventSynchDlg dialog

CEventSynchDlg::CEventSynchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEventSynchDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEventSynchDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEventSynchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEventSynchDlg)
	DDX_Control(pDX, IDC_RESULT, m_result);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEventSynchDlg, CDialog)
	//{{AFX_MSG_MAP(CEventSynchDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTSTARTONE, OnStartOne)
	ON_BN_CLICKED(IDC_BTSTARTTWO, OnStartTwo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEventSynchDlg message handlers

BOOL CEventSynchDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEventSynchDlg::OnPaint() 
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

HCURSOR CEventSynchDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
CEvent cEvent;
static UINT thread1(LPVOID pParam)
{
	CEdit *p=(CEdit*)pParam;
	char buf[MAX_PATH];
	for(int i=0;i<20;i++)
	{
		::SendMessage(p->GetSafeHwnd(),WM_GETTEXT,MAX_PATH,(LPARAM)buf);
		strcat(buf,"A");
		::SendMessage(p->GetSafeHwnd(),WM_SETTEXT,0,(LPARAM)buf);
		Sleep(200);
	}
	return 0;
}
static UINT thread2(LPVOID pParam)
{
	CEdit *p=(CEdit*)pParam;
	char buf[MAX_PATH];
	for(int i=0;i<20;i++)
	{
		::SendMessage(p->GetSafeHwnd(),WM_GETTEXT,MAX_PATH,(LPARAM)buf);
		strcat(buf,"B");
		::SendMessage(p->GetSafeHwnd(),WM_SETTEXT,0,(LPARAM)buf);
		Sleep(200);
	}
	return 0;
}
static UINT thread3(LPVOID pParam)
{
	CEdit *p=(CEdit*)pParam;
	char buf[MAX_PATH];
	for(int i=0;i<20;i++)
	{
		::SendMessage(p->GetSafeHwnd(),WM_GETTEXT,MAX_PATH,(LPARAM)buf);
		strcat(buf,"A");
		::SendMessage(p->GetSafeHwnd(),WM_SETTEXT,0,(LPARAM)buf);
		Sleep(200);
	}
	cEvent.SetEvent();
	return 0;
}
static UINT thread4(LPVOID pParam)
{
	CEdit *p=(CEdit*)pParam;
	char buf[MAX_PATH];
	cEvent.Lock();
	for(int i=0;i<20;i++)
	{
		::SendMessage(p->GetSafeHwnd(),WM_GETTEXT,MAX_PATH,(LPARAM)buf);
		strcat(buf,"B");
		::SendMessage(p->GetSafeHwnd(),WM_SETTEXT,0,(LPARAM)buf);
		Sleep(200);
	}
	cEvent.SetEvent();
	return 0;
}
void CEventSynchDlg::OnStartOne() 
{
	AfxBeginThread(thread1,&m_result);
	AfxBeginThread(thread2,&m_result);
}

void CEventSynchDlg::OnStartTwo() 
{
	AfxBeginThread(thread3,&m_result);
	AfxBeginThread(thread4,&m_result);
}
