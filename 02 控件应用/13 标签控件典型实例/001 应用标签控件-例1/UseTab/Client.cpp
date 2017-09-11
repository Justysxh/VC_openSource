// Client.cpp : implementation file
//

#include "stdafx.h"
#include "UseTab.h"
#include "Client.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClient dialog


CClient::CClient(CWnd* pParent /*=NULL*/)
	: CDialog(CClient::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClient)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CClient::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClient)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CClient, CDialog)
	//{{AFX_MSG_MAP(CClient)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClient message handlers
