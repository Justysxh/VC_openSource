// Providedlg.cpp : implementation file
//

#include "stdafx.h"
#include "UseTab.h"
#include "Providedlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProvidedlg dialog


CProvidedlg::CProvidedlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProvidedlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProvidedlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CProvidedlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProvidedlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProvidedlg, CDialog)
	//{{AFX_MSG_MAP(CProvidedlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProvidedlg message handlers
