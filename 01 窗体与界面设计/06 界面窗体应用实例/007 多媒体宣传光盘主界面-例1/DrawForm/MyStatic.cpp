// MyStatic.cpp : implementation file
//

#include "stdafx.h"
#include "DrawForm.h"
#include "MyStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyStatic

CMyStatic::CMyStatic()
{
}

CMyStatic::~CMyStatic()
{

}


BEGIN_MESSAGE_MAP(CMyStatic, CStatic)
	//{{AFX_MSG_MAP(CMyStatic)
	ON_WM_CTLCOLOR_REFLECT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyStatic message handlers



BOOL CMyStatic::PreCreateWindow(CREATESTRUCT& cs) 
{
//	cs.dwExStyle=cs.dwExStyle| 	WS_EX_TRANSPARENT ;
	return CStatic::PreCreateWindow(cs);
}

HBRUSH CMyStatic::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	pDC->SetBkMode(TRANSPARENT);	
	// TODO: Return a non-NULL brush if the parent's handler should not be called
	return NULL;
}
