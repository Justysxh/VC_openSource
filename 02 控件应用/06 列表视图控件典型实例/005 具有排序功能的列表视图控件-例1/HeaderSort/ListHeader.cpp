// ListHeader.cpp : implementation file
//

#include "stdafx.h"
#include "HeaderSort.h"
#include "ListHeader.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListHeader

CListHeader::CListHeader()
{
	m_nSortColumn = -1;
	m_bAscend = TRUE;
}

CListHeader::~CListHeader()
{
}


BEGIN_MESSAGE_MAP(CListHeader, CHeaderCtrl)
	//{{AFX_MSG_MAP(CListHeader)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListHeader message handlers

void CListHeader::SetSortColomn(int nColumn, BOOL bAscend)
{
	m_nSortColumn = nColumn;							//记录排序列
	m_bAscend = bAscend;							//记录排序方式，升序(TRUE)还是降序(FALSE)
	HD_ITEM hItem;
	hItem.mask = HDI_FORMAT;
	GetItem( nColumn, &hItem ) ;						//获取列信息
	hItem.fmt |= HDF_OWNERDRAW;					//设置自绘风格
	SetItem( nColumn, &hItem );							//设置列信息
	Invalidate();									//更新表头
}

void CListHeader::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CDC dc;			//定义设备上下文
	dc.Attach( lpDrawItemStruct->hDC );		//附加设备上下文句柄
	const int nSavedIndex = dc.SaveDC();	//保存设备上下文
	CRect rc( lpDrawItemStruct->rcItem );	//获取当前列区域
	CBrush brush( GetSysColor( COLOR_3DFACE ) );	//定义背景画刷
	dc.FillRect( rc, &brush );				//填充画刷
	TCHAR szText[ 256 ];					
	HD_ITEM hditem;
	hditem.mask = HDI_TEXT | HDI_FORMAT;
	hditem.pszText = szText;
	hditem.cchTextMax = 255;
	GetItem( lpDrawItemStruct->itemID, &hditem );	//获取当前的项目信息
	//设置绘制的文本格式
	UINT uFormat = DT_SINGLELINE | DT_NOPREFIX | DT_NOCLIP | DT_VCENTER | DT_END_ELLIPSIS ;
	if( hditem.fmt & HDF_CENTER)
		uFormat |= DT_CENTER;
	else if( hditem.fmt & HDF_RIGHT)
		uFormat |= DT_RIGHT;
	else
		uFormat |= DT_LEFT;
	if( lpDrawItemStruct->itemState == ODS_SELECTED )
	{
		rc.left++;
		rc.top += 2;
		rc.right++;
	}
	CRect rcIcon( lpDrawItemStruct->rcItem );
	const int iOffset = ( rcIcon.bottom - rcIcon.top ) / 4;
	if( lpDrawItemStruct->itemID == (UINT) m_nSortColumn )
		rc.right -= 3 * iOffset;
	rc.left += iOffset;
	rc.right -= iOffset;
	//绘制列文本
	if( rc.left < rc.right )
		dc.DrawText( szText, -1, rc, uFormat );
	//绘制箭头
	if( lpDrawItemStruct->itemID == (UINT) m_nSortColumn )
	{
		//定义画笔
		CPen penLight( PS_SOLID, 1, GetSysColor( COLOR_3DHILIGHT ) );
		CPen penShadow( PS_SOLID, 1, GetSysColor( COLOR_3DSHADOW ) );
		CPen* pOldPen = dc.SelectObject( &penLight );	//选中画笔
		if( m_bAscend )
		{
			//绘制向上的箭头
			dc.MoveTo( rcIcon.right - 2 * iOffset, iOffset);
			dc.LineTo( rcIcon.right - iOffset, rcIcon.bottom - iOffset - 1 );
			dc.LineTo( rcIcon.right - 3 * iOffset - 2, rcIcon.bottom - iOffset - 1 );
			dc.SelectObject( &penShadow );
			dc.MoveTo( rcIcon.right - 3 * iOffset - 1, rcIcon.bottom - iOffset - 1 );
			dc.LineTo( rcIcon.right - 2 * iOffset, iOffset - 1);		
		}
		else
		{
			//绘制向下的箭头
			dc.MoveTo( rcIcon.right - iOffset - 1, iOffset );
			dc.LineTo( rcIcon.right - 2 * iOffset - 1, rcIcon.bottom - iOffset );
			dc.SelectObject( &penShadow );
			dc.MoveTo( rcIcon.right - 2 * iOffset - 2, rcIcon.bottom - iOffset );
			dc.LineTo( rcIcon.right - 3 * iOffset - 1, iOffset );
			dc.LineTo( rcIcon.right - iOffset - 1, iOffset );		
		}
		dc.SelectObject( pOldPen );		//恢复原来选择的画笔
	}
	dc.RestoreDC( nSavedIndex );		//恢复之前的设备上下文
	dc.Detach();//从设备上下文中分离设备上下文句柄
}
