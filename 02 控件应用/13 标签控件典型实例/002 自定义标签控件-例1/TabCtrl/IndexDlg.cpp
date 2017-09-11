// IndexDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TabCtrl.h"
#include "IndexDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIndexDlg dialog


CIndexDlg::CIndexDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIndexDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIndexDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CIndexDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIndexDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CIndexDlg, CDialog)
	//{{AFX_MSG_MAP(CIndexDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIndexDlg message handlers
