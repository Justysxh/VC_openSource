// CustomGroup.cpp : implementation file
//

#include "stdafx.h"
#include "MediaPlayer.h"
#include "CustomGroup.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustomGroup

CCustomGroup::CCustomGroup()
{
	m_LeftMargin = 10;
	m_FrameColor = RGB(0,0,159);
	m_clText = RGB(255,0,0);
}

CCustomGroup::~CCustomGroup()
{
}


BEGIN_MESSAGE_MAP(CCustomGroup, CStatic)
	//{{AFX_MSG_MAP(CCustomGroup)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomGroup message handlers

void CCustomGroup::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CString text;
	GetWindowText(text);

	CRect rect;
	GetClientRect(rect);
	CFont* pOldFont =  dc.SelectObject(GetFont());
	CSize size =  dc.GetTextExtent(text);
	CRect textRC(m_LeftMargin,0,rect.Width(),size.cy);
	
	rect.DeflateRect(0,size.cy/2,0,-size.cy/2);

	CPen pen(PS_SOLID,1,m_FrameColor);
	dc.SelectObject(&pen);

	dc.MoveTo(0,rect.top);
	dc.LineTo(0,rect.Height());
	dc.MoveTo(0,rect.Height());
	dc.LineTo(rect.Width(),rect.Height());
	
	dc.MoveTo(rect.Width(),rect.top);
	dc.LineTo(rect.Width(),rect.Height());

	dc.MoveTo(0,rect.top);
	dc.LineTo(m_LeftMargin,rect.top);

	dc.MoveTo(m_LeftMargin+size.cx,rect.top);
	dc.LineTo(rect.Width(),rect.top);

	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(m_clText);
	dc.DrawText(text,textRC,DT_LEFT|DT_SINGLELINE|DT_VCENTER);
	dc.SelectObject(pOldFont);
	
	// Do not call CStatic::OnPaint() for painting messages
}
