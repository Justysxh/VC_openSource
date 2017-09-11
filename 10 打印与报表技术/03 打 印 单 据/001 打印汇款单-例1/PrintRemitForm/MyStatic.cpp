// MyStatic.cpp : implementation file
//

#include "stdafx.h"
#include "PrintRemitForm.h"
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
	islined = false;
	isframed = true;
	
	isTop = TRUE;
	isLeft = TRUE;
	isRight = TRUE;
	isBottom = TRUE;

	m_color = RGB(0,0,0);
	m_lindwidth = 1;
	align = DT_CENTER|DT_VCENTER|DT_SINGLELINE;
	m_framecolor = RGB(255,0,0);
}

CMyStatic::~CMyStatic()
{

}


BEGIN_MESSAGE_MAP(CMyStatic, CStatic)
	//{{AFX_MSG_MAP(CMyStatic)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR_REFLECT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyStatic message handlers

void CMyStatic::OnPaint() 
{
	CPaintDC dc1(this); 
	
	CDC dc;
	dc.Attach(GetDC()->m_hDC);

	CRect rect;
	GetClientRect(rect);
	dc.SetBkMode(TRANSPARENT);

	CPen pen(PS_SOLID,m_lindwidth,m_framecolor);

	CPen* oldpen;
	oldpen = dc.SelectObject(&pen);

	if (isframed)
	{

		if (isTop)
		{
			dc.MoveTo(rect.left,rect.top);  //上边线
			dc.LineTo(rect.right,rect.top);
		}

		if (isBottom)
		{
			dc.MoveTo(rect.left,rect.bottom); //下边线
			dc.LineTo(rect.right,rect.bottom);
		}

		if (isLeft)
		{
			dc.MoveTo(rect.left,rect.top);   //左边线
			dc.LineTo(rect.left,rect.bottom);
		}

		if (isRight)
		{
			dc.MoveTo(rect.right,rect.top);   //右边线
			dc.LineTo(rect.right,rect.bottom);
		}

	}
	if (islined)
	{
		
		CPen linepen(PS_SOLID,m_lindwidth,m_color);
		oldpen = dc.SelectObject(&linepen);

		dc.MoveTo(rect.left,rect.bottom-1);
		dc.LineTo(rect.right,rect.bottom-1);
	}

	dc.SelectObject(oldpen);
	CString str ;
	GetWindowText(str);
	dc.SetTextColor(m_color);
	dc.DrawText(str,rect,align);

}

HBRUSH CMyStatic::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	CBrush m_brush(RGB(255,255,255));
	

	//CRect rect;
	//GetClientRect(rect);
	//pDC->FillRect(rect,&m_brush);
	return m_brush;
}

