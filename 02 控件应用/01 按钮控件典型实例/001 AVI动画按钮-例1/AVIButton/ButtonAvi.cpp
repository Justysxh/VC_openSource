// ButtonAvi.cpp : implementation file
//

#include "stdafx.h"
#include "AVIButton.h"
#include "ButtonAvi.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CButtonAvi

CButtonAvi::CButtonAvi()
{
	m_play = false;
}

CButtonAvi::~CButtonAvi()
{
}


BEGIN_MESSAGE_MAP(CButtonAvi, CButton)
	//{{AFX_MSG_MAP(CButtonAvi)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CButtonAvi message handlers

void CButtonAvi::LoadAVI(UINT nID)
{
	m_id =nID;
}

void CButtonAvi::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CRect rect;
	GetClientRect(rect);
	if (!::IsWindow(m_Animate))
	{
		m_Animate.Create(WS_CHILD | WS_VISIBLE,rect,this,0);
		m_Animate.Open(m_id);
		m_Animate.GetClientRect(rect);
		VERIFY(SetWindowPos(NULL,0,0, rect.Width()+2, rect.Height()+2,SWP_NOMOVE));
		m_Animate.MoveWindow(rect); 
	}

	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	UINT State = lpDrawItemStruct->itemState;
	DrawButton(pDC,State,rect);
}

void CButtonAvi::DrawButton(CDC *pDC,UINT nState,CRect rect)
{
	COLORREF UpCol,DownCol;
	if ((nState & ODS_SELECTED) == ODS_SELECTED)
	{
		UpCol=RGB(0,0,0);
		DownCol=RGB(0,0,0);
		m_play = false;
	}
	else if ((nState & ODS_DISABLED) != ODS_DISABLED)
	{
		UpCol=RGB(255,255,255);
		DownCol=RGB(128,128,128);
	}
	//画按钮的左边和上边
	CPen pen1,pen2;
	pen1.CreatePen(PS_SOLID,3,UpCol);
	pDC->SelectObject(&pen1);
	pDC->MoveTo(0,rect.Height()-1);
	pDC->LineTo(0,0);                                                             
	pDC->LineTo(rect.Width()-1,0);
	//画按钮的右边和下边
	pen2.CreatePen(PS_SOLID,2,DownCol);
	pDC->SelectObject(&pen2);
	pDC->MoveTo(rect.Width()-1,0);
	pDC->LineTo(rect.Width()-1,rect.Height()-1);
	pDC->LineTo(0,rect.Height()-1);

	pen1.DeleteObject();
	pen2.DeleteObject();
}

void CButtonAvi::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	ClientToScreen(&point);
	CRect rc;
	GetWindowRect(rc);
	if(rc.PtInRect(point))
	{
        if (::IsWindow(m_Animate) && !m_play)
		{
			m_Animate.Play(0,-1,1);
			m_play = true;
			SetCapture();
		}
	}
	else
	{
		m_play = false;
		ReleaseCapture();
	}
	CButton::OnMouseMove(nFlags, point);
}
