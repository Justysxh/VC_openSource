// DragList.cpp : implementation file
//

#include "stdafx.h"
#include "Drag.h"
#include "DragList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDragList

CDragList::CDragList()
{
}

CDragList::~CDragList()
{
}


BEGIN_MESSAGE_MAP(CDragList, CListCtrl)
	//{{AFX_MSG_MAP(CDragList)
	ON_NOTIFY_REFLECT(LVN_BEGINDRAG, OnBegindrag)
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDragList message handlers

void CDragList::OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult) 
{
	HD_NOTIFY * phdn = (HD_NOTIFY *) pNMHDR;
	// TODO: Add your control notification handler code here
	POINT pt;
	m_ItmIndex = ((NM_LISTVIEW *)pNMHDR)->iItem;
	m_pDrgImg  = CreateDragImage(m_ItmIndex,&pt);
	m_pDrgImg->BeginDrag(0,pt);
	ClientToScreen(&pt);						//转换客户坐标到屏幕坐标
	m_pDrgImg->DragEnter(this,pt);
	m_Drag = TRUE;
	*pResult = 0;
}

void CDragList::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_Drag)
	{
		m_pDrgImg->EndDrag();
		m_Drag = FALSE;
		char name[256];
		LV_ITEM lvi;
		CString subitem[3];
		for(int i=2;i>=0;i--)
		{
			ZeroMemory(&lvi,sizeof(LV_ITEM));
			lvi.iItem		= m_ItmIndex;
			lvi.iSubItem	= i;
			lvi.mask		= LVIF_IMAGE | LVIF_TEXT;
			lvi.pszText		= name;
			lvi.cchTextMax	= 255;
			GetItem(&lvi);
			subitem[i].Format("%s",name);
		}
		InsertItem(&lvi);
		SetItemText(m_ItmIndex,1,subitem[1]);
		SetItemText(m_ItmIndex,2,subitem[2]);
	}
	CListCtrl::OnLButtonUp(nFlags, point);
}

void CDragList::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_Drag)
	{
		CPoint pt;
		pt.x = point.x;
		pt.y = point.y + (m_ItmIndex + 1) * 15;
		m_pDrgImg->DragMove(pt);
	}
	CListCtrl::OnMouseMove(nFlags, point);
}
