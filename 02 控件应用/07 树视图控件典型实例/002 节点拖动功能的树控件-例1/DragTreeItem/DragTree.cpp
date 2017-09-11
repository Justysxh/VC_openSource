// DragTree.cpp : implementation file
//

#include "stdafx.h"
#include "DragTreeItem.h"
#include "DragTree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDragTree

CDragTree::CDragTree()
{
	m_pDragImages = NULL;
	m_bDrag = FALSE;
	m_hBeginDrag = NULL;
}

CDragTree::~CDragTree()
{
}


BEGIN_MESSAGE_MAP(CDragTree, CTreeCtrl)
	//{{AFX_MSG_MAP(CDragTree)
	ON_NOTIFY_REFLECT(TVN_BEGINDRAG, OnBegindrag)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDragTree message handlers

void CDragTree::OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	HTREEITEM hItem = pNMTreeView->itemNew.hItem;		//获取开始拖动的节点
	if (hItem==GetRootItem())							//不允许拖动根节点
	{
		*pResult = 0;
		return;
	}
	m_hBeginDrag = hItem;								//记录开始拖动的项目
	m_pDragImages = CreateDragImage(hItem);				//创建拖动的图像列表

	CPoint dragPT;										//记录起始点
	dragPT.x = pNMTreeView->ptDrag.x;
	dragPT.y = pNMTreeView->ptDrag.y;
	if (m_pDragImages != NULL)
	{
		m_pDragImages->BeginDrag(0, CPoint(8, 8));		//开始拖动图像
		ClientToScreen(&dragPT);						//转换客户坐标到屏幕坐标
		m_pDragImages->DragEnter(this, dragPT);			//锁定窗口更新，在拖动的过程中显示拖动的图像
		SetCapture();									//开始鼠标捕捉
		m_bDrag = TRUE;
	}
	*pResult = 0;
}

void CDragTree::OnMouseMove(UINT nFlags, CPoint point) 
{
	if (m_bDrag)										//处于拖动状态
	{
		HTREEITEM	hItem;
		UINT		nHitFlags;
		CRect		clientRC;
		GetClientRect(&clientRC);						//获取客户区域
		m_pDragImages->DragMove(point);					//设置拖动的图像位置
		//鼠标经过时高亮显示
		if( (hItem = HitTest(point, &nHitFlags)) != NULL )
		{
			CImageList::DragShowNolock(FALSE);			//隐藏拖动的图像
			SelectDropTarget(hItem);					//设置选中的项目
			CImageList::DragShowNolock(TRUE);			//显示拖动的图像
		}
	}
	else
		CTreeCtrl::OnMouseMove(nFlags, point);
}

void CDragTree::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if (m_bDrag)										//处于拖动状态
	{
		m_bDrag = FALSE;
		CImageList::DragLeave(this);					//
		CImageList::EndDrag();							//结束图像拖动
		ReleaseCapture();								//释放鼠标捕捉
		delete m_pDragImages;							//释放图像列表
		m_pDragImages = NULL;
		CRect winRC;
		GetWindowRect(&winRC);							//获取窗口区域
		HTREEITEM hItem;
		if((hItem = HitTest(point, &nFlags)) != NULL)
		{
			//进行拖动处理
			//如果目标项目与开始拖动的项目相同或者目标项目仍是开始项目的父节点，不进行处理
			if (m_hBeginDrag != hItem && hItem != GetParentItem(m_hBeginDrag))
			{
				CopyNodes(hItem, m_hBeginDrag);			//进行节点的复制
				DeleteItem(m_hBeginDrag);				//删除源节点
			}
			Invalidate();
			SelectDropTarget(NULL);
			m_hBeginDrag = NULL;
		}
	}
}

//复制节点，将hSrcItem及其子项目复制到下hDesItem节点下
void CDragTree::CopyNodes(HTREEITEM hDesItem, HTREEITEM hSrcItem)
{

	if (hDesItem==NULL || hSrcItem==NULL)				//验证参数
	{
		return;
	}
	TVITEM tvItem;										//定义项目信息
	tvItem.mask = TVIF_TEXT|TVIF_IMAGE;					//设置返回标记
	tvItem.hItem = hSrcItem;
	char chText[MAX_PATH] = {0};
	tvItem.pszText = chText;
	tvItem.cchTextMax = MAX_PATH;
	GetItem(&tvItem);									//获取项目信息
	TVINSERTSTRUCT tvInsert;							//定义插入操作的数据结构
	tvInsert.hParent = hDesItem;
	tvInsert.item = tvItem;
	HTREEITEM hInsert = InsertItem(&tvInsert);			//插入项目
	HTREEITEM hChild = GetChildItem(hSrcItem);			//获取子节点
	while (hChild != NULL)								//遍历子节点
	{
		tvItem.mask = TVIF_TEXT|TVIF_IMAGE;
		tvItem.hItem = hChild;
		tvItem.pszText = chText;
		tvItem.cchTextMax = MAX_PATH;
		GetItem(&tvItem);
		tvInsert.hParent = hInsert;
		tvInsert.item = tvItem;
		CopyNodes(hInsert, hChild);						//递归调用
		hChild = GetNextSiblingItem(hChild);			//查找下一个兄弟节点	
	}
}



