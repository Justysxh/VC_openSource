// ColorEdit.cpp : implementation file
//

#include "stdafx.h"
#include "TextColor.h"
#include "ColorEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorEdit

CColorEdit::CColorEdit()
{
}

CColorEdit::~CColorEdit()
{
}


BEGIN_MESSAGE_MAP(CColorEdit, CEdit)
	//{{AFX_MSG_MAP(CColorEdit)
	ON_WM_CTLCOLOR_REFLECT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorEdit message handlers

void CColorEdit::SetColor(COLORREF color)
{
	m_Color = color;
}


HBRUSH CColorEdit::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	// TODO: Change any attributes of the DC here
	CBrush m_Brush;
	m_Brush.CreateStockObject(WHITE_BRUSH);
	pDC->SetTextColor(m_Color);
	// TODO: Return a non-NULL brush if the parent's handler should not be called
	return m_Brush;
}

