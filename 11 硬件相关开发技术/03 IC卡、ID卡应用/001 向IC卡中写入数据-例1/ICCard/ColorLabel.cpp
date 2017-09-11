// ColorLabel.cpp : implementation file
//

#include "stdafx.h"
#include "ICCard.h"
#include "ColorLabel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorLabel

CColorLabel::CColorLabel()
:m_TextColor(RGB(255,0,0))
{
}

CColorLabel::~CColorLabel()
{
}


BEGIN_MESSAGE_MAP(CColorLabel, CStatic)
	//{{AFX_MSG_MAP(CColorLabel)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorLabel message handlers

void CColorLabel::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	dc.SetTextColor(m_TextColor);
	CString str;
	GetWindowText(str);
	dc.SetBkMode(TRANSPARENT);
	dc.SelectObject(GetFont());
	dc.TextOut(0,0,str);

}

COLORREF CColorLabel::GetTextColor()
{
	return m_TextColor;
}

void CColorLabel::SetTextColor(COLORREF Color)
{
	if (m_TextColor!=Color)
		m_TextColor = Color;
	Invalidate();
}
