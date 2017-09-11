// BitTreeCtl.cpp : implementation file
//

#include "stdafx.h"
#include "BitTree.h"
#include "BitTreeCtl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBitTreeCtl

CBitTreeCtl::CBitTreeCtl()
{
	m_Flags = 0;
}

CBitTreeCtl::~CBitTreeCtl()
{

}


BEGIN_MESSAGE_MAP(CBitTreeCtl, CTreeCtrl)
	//{{AFX_MSG_MAP(CBitTreeCtl)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBitTreeCtl message handlers

void CBitTreeCtl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	HTREEITEM hItemInfo =HitTest(point, &m_Flags);
	nFlags = m_Flags;
	//TVHT_ONITEMSTATEICON表示用户定义的视图项的图标状态
	if ( m_Flags &TVHT_ONITEMSTATEICON )
	{
		//State: 0无状态 1没有选择 2部分选择 3全部选择
		//12到15位表示视图项的图像状态索引
		UINT State = GetItemState( hItemInfo, TVIS_STATEIMAGEMASK ) >> 12;
		State=(State==3)?1:3;
		SetItemState( hItemInfo, INDEXTOSTATEIMAGEMASK(State), TVIS_STATEIMAGEMASK );
	}
	else
		CTreeCtrl::OnLButtonDown(nFlags, point);
}

BOOL CBitTreeCtl::SetItemState(HTREEITEM hItem, UINT State, UINT StateMask, BOOL IsSearch)
{
	BOOL ret=CTreeCtrl::SetItemState( hItem, State, StateMask );

	UINT nState =State >> 12;
	if(nState!=0)
	{
		if(IsSearch) 
			RansackChild(hItem, nState);
		RansackParentAndChild(hItem,nState);
	}
	return ret;
}

//遍历子节点
void CBitTreeCtl::RansackChild(HTREEITEM hItem, UINT State)
{
	HTREEITEM hChildItem,hBrotherItem;
	//查找子节点
	hChildItem=GetChildItem(hItem);
	if(hChildItem!=NULL)
	{
		//将所有子节点的状态设置与父节点相同
		CTreeCtrl::SetItemState( hChildItem, INDEXTOSTATEIMAGEMASK(State), TVIS_STATEIMAGEMASK );
		//再递归处理子节点的子节点
		RansackChild(hChildItem, State);
		
		//搜索子节点的兄弟节点
		hBrotherItem=GetNextSiblingItem(hChildItem);
		while (hBrotherItem)
		{
			//设置子节点的兄弟节点状态与当前节点的状态一致
			int nState = GetItemState( hBrotherItem, TVIS_STATEIMAGEMASK ) >> 12;
			if(nState!=0)
			{
				CTreeCtrl::SetItemState( hBrotherItem, INDEXTOSTATEIMAGEMASK(State), TVIS_STATEIMAGEMASK );
			}
			//再递归处理兄弟节点
			RansackChild(hBrotherItem, State);
			hBrotherItem=GetNextSiblingItem(hBrotherItem);
		}
	}
}

void CBitTreeCtl::RansackParentAndChild(HTREEITEM hItem, UINT State)
{
	HTREEITEM hNextItem,hPrevItem,hParentItem;
	
	//查找父节点，没有就结束
	hParentItem=GetParentItem(hItem);
	if(hParentItem!=NULL)
	{
		UINT nState1=State;//设初始值，防止没有兄弟节点时出错
		
		//查找当前节点的所有兄弟节点,如果所有兄弟节点状态都相同,
		//设置父节点的状态

		//查找当前节点下面的兄弟节点的状态
		hNextItem=GetNextSiblingItem(hItem);
		while(hNextItem!=NULL)
		{
			nState1 = GetItemState( hNextItem, TVIS_STATEIMAGEMASK ) >> 12;
			if(nState1!=State && nState1!=0) break;
			else hNextItem=GetNextSiblingItem(hNextItem);
		}
		
		if(nState1==State)
		{
			//查找当前节点上面的兄弟节点的状态
			hPrevItem=GetPrevSiblingItem(hItem);
			while(hPrevItem!=NULL)
			{
				nState1 = GetItemState( hPrevItem, TVIS_STATEIMAGEMASK ) >> 12;
				if(nState1!=State && nState1!=0) break;
				else hPrevItem=GetPrevSiblingItem
					(hPrevItem);
			}
		}	
		if(nState1==State || nState1==0)
		{
			nState1 = GetItemState( hParentItem, TVIS_STATEIMAGEMASK ) >> 12;
			if(nState1!=0)
			{
				//如果状态一致，则父节点的状态与当前节点的状态一致
				CTreeCtrl::SetItemState( hParentItem, INDEXTOSTATEIMAGEMASK(State), TVIS_STATEIMAGEMASK );
			}
			//再递归处理父节点的兄弟节点和其父节点
			RansackParentAndChild(hParentItem,State);
		}
		else
		{
			//状态不一致，则当前节点的父节点、父节点的父节点……状态均为第三态
			hParentItem=GetParentItem(hItem);
			while(hParentItem!=NULL)
			{
				nState1 = GetItemState( hParentItem, TVIS_STATEIMAGEMASK ) >> 12;
				if(nState1!=0)
				{
					CTreeCtrl::SetItemState( hParentItem, INDEXTOSTATEIMAGEMASK(2), TVIS_STATEIMAGEMASK );
				}
				hParentItem=GetParentItem(hParentItem);
			}
		}
	}
}
