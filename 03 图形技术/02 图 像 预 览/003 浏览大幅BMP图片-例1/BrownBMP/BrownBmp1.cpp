// BrownBmp1.cpp : implementation file
//

#include "stdafx.h"
#include "BrownBMP.h"
#include "BrownBmp1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBrownBmp

CBrownBmp::CBrownBmp()
{
}

CBrownBmp::~CBrownBmp()
{
}


BEGIN_MESSAGE_MAP(CBrownBmp, CStatic)
	//{{AFX_MSG_MAP(CBrownBmp)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBrownBmp message handlers

void CBrownBmp::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	
	CStatic::OnHScroll(nSBCode, nPos, pScrollBar);
}
