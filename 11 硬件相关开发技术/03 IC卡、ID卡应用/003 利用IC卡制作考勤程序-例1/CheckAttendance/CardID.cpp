// CardID.cpp : implementation file
//

#include "stdafx.h"
#include "CheckAttendance.h"
#include "CardID.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCardID

CCardID::CCardID()
{
	m_Font.CreateFont(24,24,0,0,900,0,0,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH,"ËÎÌו");
}

CCardID::~CCardID()
{
}


BEGIN_MESSAGE_MAP(CCardID, CStatic)
	//{{AFX_MSG_MAP(CCardID)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCardID message handlers

void CCardID::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CRect rect;
	GetClientRect(rect);
	CBrush brush(RGB(0,0,0));
	dc.FillRect(rect,&brush);
	CString str;
	GetWindowText(str);
	dc.SelectObject(m_Font);
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor( RGB(255,255,0));
	dc.TextOut(0,0,str);
	// Do not call CStatic::OnPaint() for painting messages
}

HBRUSH CCardID::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CStatic::OnCtlColor(pDC, pWnd, nCtlColor);
	
	OnPaint();
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

LRESULT CCardID::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	LRESULT result = CStatic::WindowProc(message, wParam, lParam);
	if (message==WM_SETTEXT)
		Invalidate();
	return result;
}
