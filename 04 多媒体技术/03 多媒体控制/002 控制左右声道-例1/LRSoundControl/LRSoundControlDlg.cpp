// LRSoundControlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LRSoundControl.h"
#include "LRSoundControlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLRSoundControlDlg dialog

CLRSoundControlDlg::CLRSoundControlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLRSoundControlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLRSoundControlDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLRSoundControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLRSoundControlDlg)
	DDX_Control(pDX, IDC_RIGHT, m_right);
	DDX_Control(pDX, IDC_LEFT, m_left);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLRSoundControlDlg, CDialog)
	//{{AFX_MSG_MAP(CLRSoundControlDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLRSoundControlDlg message handlers

BOOL CLRSoundControlDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);
	
	m_left.SetRange(0,200);
	m_right.SetRange(0,200);
	return TRUE; 
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLRSoundControlDlg::OnPaint() 
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

HCURSOR CLRSoundControlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLRSoundControlDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	DWORD pos;
	int scrollpos;
	if(pScrollBar->m_hWnd==m_left.m_hWnd)
	{
		scrollpos=m_left.GetPos();
		::waveOutGetVolume(0,&pos);
		pos=pos&0x0000ffff|(scrollpos<<8);
		::waveOutSetVolume(0,pos);
	}

	if(pScrollBar->m_hWnd==m_right.m_hWnd)
	{
		scrollpos=m_right.GetPos();
		::waveOutGetVolume(0,&pos);
		pos=pos&0xffff0000|(scrollpos<<24);
		::waveOutSetVolume(0,pos);
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
