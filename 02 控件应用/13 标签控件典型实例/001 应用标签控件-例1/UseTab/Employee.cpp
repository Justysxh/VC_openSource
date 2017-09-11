// Employee.cpp : implementation file
//

#include "stdafx.h"
#include "UseTab.h"
#include "Employee.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEmployee dialog


CEmployee::CEmployee(CWnd* pParent /*=NULL*/)
	: CDialog(CEmployee::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEmployee)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEmployee::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEmployee)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEmployee, CDialog)
	//{{AFX_MSG_MAP(CEmployee)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmployee message handlers
