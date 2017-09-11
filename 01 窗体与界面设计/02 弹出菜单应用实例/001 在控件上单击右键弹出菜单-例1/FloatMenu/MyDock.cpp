// MyDock.cpp : implementation file
//

#include "stdafx.h"
#include "FloatMenu.h"
#include "MyDock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyDock

CMyDock::CMyDock()
{
}

CMyDock::~CMyDock()
{
}


BEGIN_MESSAGE_MAP(CMyDock, CDialogBar)
	//{{AFX_MSG_MAP(CMyDock)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDock message handlers

void CMyDock::SetMenu()
{
	CDialogBar::SetMenu(m_pMenu);
}
