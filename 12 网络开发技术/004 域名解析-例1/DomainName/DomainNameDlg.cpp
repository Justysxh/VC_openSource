// DomainNameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DomainName.h"
#include "DomainNameDlg.h"
#include <nspapi.h>
#include <svcguid.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDomainNameDlg dialog

CDomainNameDlg::CDomainNameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDomainNameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDomainNameDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDomainNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDomainNameDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDomainNameDlg, CDialog)
	//{{AFX_MSG_MAP(CDomainNameDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTGET, OnGet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDomainNameDlg message handlers

BOOL CDomainNameDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	AfxSocketInit();
	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDomainNameDlg::OnPaint() 
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

HCURSOR CDomainNameDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDomainNameDlg::OnGet() 
{
	HOSTENT* hst=NULL;
	CString strname,strip,tmp;
	GetDlgItem(IDC_EDNAME)->GetWindowText(strname);
	struct in_addr ia;
	hst=gethostbyname((LPCTSTR)strname);

    for(int i=0;hst->h_addr_list[i];i++){
        memcpy(&ia.s_addr,hst->h_addr_list[i],sizeof(ia.s_addr));
        tmp.Format("%s\n",inet_ntoa(ia));
		strip+=tmp;
    }
	GetDlgItem(IDC_EDIP)->SetWindowText(strip);
}
