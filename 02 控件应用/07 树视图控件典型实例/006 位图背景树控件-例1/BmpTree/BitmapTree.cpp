// BitmapTree.cpp : implementation file
//

#include "stdafx.h"
#include "BmpTree.h"
#include "BitmapTree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBitmapTree

CBitmapTree::CBitmapTree()
{
}

CBitmapTree::~CBitmapTree()
{
}


BEGIN_MESSAGE_MAP(CBitmapTree, CTreeCtrl)
	//{{AFX_MSG_MAP(CBitmapTree)
	ON_WM_PAINT()
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDING, OnItemexpanding)
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDED, OnItemexpanded)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBitmapTree message handlers

void CBitmapTree::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	m_hBmp = LoadImage(NULL,m_Path,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	CRect rect;
	GetClientRect(&rect);
	m_Bitmap.Attach(m_hBmp);
	CDC memdc;
	memdc.CreateCompatibleDC(&dc);	
	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	memdc.SelectObject( &bitmap );
	//获取原始画布
	CWnd::DefWindowProc(WM_PAINT, (WPARAM)memdc.m_hDC , 0);

	//绘制背景图片
	CMemDC tempDC( &dc,rect);
	CBrush brush;
	brush.CreatePatternBrush(&m_Bitmap);
	tempDC.FillRect(rect, &brush);	
	
	//将原始图片与背景进行组合
	tempDC.BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), 
           &memdc, rect.left, rect.top,SRCAND);
	brush.DeleteObject();
	m_Bitmap.Detach();
	// Do not call CTreeCtrl::OnPaint() for painting messages
}

void CBitmapTree::OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	SetRedraw(FALSE);
	*pResult = 0;
}

void CBitmapTree::OnItemexpanded(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	SetRedraw();
	*pResult = 0;
}

BOOL CBitmapTree::SetTreeBK(CString path)
{
	m_Path = path;
	Invalidate();
	return true;
}
