// NetTabCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "TabCtrl.h"
#include "NetTabCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNetTabCtrl

CNetTabCtrl::CNetTabCtrl()
{
}

CNetTabCtrl::~CNetTabCtrl()
{
}



BEGIN_MESSAGE_MAP(CNetTabCtrl, CTabCtrl)
	//{{AFX_MSG_MAP(CNetTabCtrl)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetTabCtrl message handlers

void CNetTabCtrl::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	ASSERT(lpDrawItemStruct->CtlType == ODT_TAB);
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);
	CRect itemRC(lpDrawItemStruct->rcItem);			//获取项目区域
	int nIndex = lpDrawItemStruct->itemID;			//获取项目索引
	int nState = lpDrawItemStruct->itemState;		//获取项目状态
	static COLORREF clrBK = RGB(229, 229, 215);		//定义默认背景颜色
	static COLORREF clrSelBK = RGB(252, 252, 254);	//定义选中的背景颜色 
	COLORREF clrText = RGB(113, 111, 100);
	if (nState & ODS_SELECTED)						//处于选中状态
	{
		dc.FillSolidRect((CRect)lpDrawItemStruct->rcItem, clrSelBK);
		clrText = RGB(0, 0, 0);
	}
	else											//非选中状态
	{
		if (nIndex == 0)
		{
			CRect itemRC = lpDrawItemStruct->rcItem;
			itemRC.OffsetRect(-1, 0);
			dc.FillSolidRect(itemRC, clrBK);
		}
		else
		{
			dc.FillSolidRect((CRect)lpDrawItemStruct->rcItem, clrBK);
		}
	}
	//绘制项目文本和图像
	char szText[MAX_PATH] = {0};
	TC_ITEM tcItem;
	tcItem.mask        = TCIF_TEXT | TCIF_IMAGE;
	tcItem.pszText     = szText;
	tcItem.cchTextMax  = MAX_PATH;
	GetItem(nIndex, &tcItem);
	CImageList* pImages = GetImageList();			//获取控件关联的图像列表
	if (pImages != NULL)
	{
		CPoint iconPT;
		iconPT.x = itemRC.left;
		iconPT.y = itemRC.top;
		pImages->Draw(&dc, tcItem.iImage, iconPT, ILD_NORMAL);
	}
	//输出文本
	itemRC.left += 40;
	//设置文本颜色
	dc.SetTextColor(clrText);
	dc.SetBkMode(TRANSPARENT);
	CFont* pFont = GetFont();
	dc.SelectObject(pFont);
	dc.DrawText(szText, strlen(szText), itemRC, DT_LEFT|DT_VCENTER|DT_SINGLELINE);
	dc.Detach();
}


void CNetTabCtrl::OnPaint() 
{
	CPaintDC dc(this); 
	DRAWITEMSTRUCT drawItem;
	drawItem.CtlType = ODT_TAB;
	drawItem.CtlID = GetDlgCtrlID();
	drawItem.hwndItem = GetSafeHwnd();
	drawItem.hDC = dc.GetSafeHdc();
	drawItem.itemAction = ODA_DRAWENTIRE;
	GetClientRect(&drawItem.rcItem);
	CRect clientRC;
	CRect pageRC;
	pageRC = drawItem.rcItem;
	AdjustRect(FALSE, pageRC);
	drawItem.rcItem.top = pageRC.top - 2;
	//绘制标签页的边框
	DrawTabBorder(&dc, (CRect)drawItem.rcItem);
	int nItemCount = GetItemCount();
	int nCurSel = GetCurSel();
	if (nItemCount < 1)
		return;
	for(int i=0; i<nItemCount; i++)
	{
		drawItem.itemID = i;
		if (i == nCurSel)
			drawItem.itemState = ODS_SELECTED;
		else
			drawItem.itemState = 0;
		GetItemRect(i, &drawItem.rcItem);
		DrawItem(&drawItem);
		//绘制项目边框
		DrawItemFrame(&drawItem);
	}
}



//绘制标签控件的边框
void CNetTabCtrl::DrawTabBorder(CDC *pDC, CRect &TabRC)
{	
	pDC->Draw3dRect(&TabRC, RGB(255, 255, 255), RGB(177, 174, 162));
}

//绘制项目边框
void CNetTabCtrl::DrawItemFrame(DRAWITEMSTRUCT *lpDrawItem)
{
	int nCurSel = GetCurSel();
	int nIndex = lpDrawItem->itemID;
	BOOL bSelected = (nCurSel==nIndex);
	CDC dc;
	CRect itemRC = lpDrawItem->rcItem;
	dc.Attach(lpDrawItem->hDC);
	if (bSelected)	//项目处于选中状态
	{
		itemRC.OffsetRect(-1, 0);
		dc.FrameRect(&itemRC, &CBrush(RGB(172, 168, 153)));
	}
	else			//项目处于非选中状态
	{
		//绘制左右两端的分隔线
		if (nIndex == 0)
			dc.FillSolidRect(itemRC.left, itemRC.top + 2, 1, itemRC.Height() - 4, RGB(172, 168, 153));
		dc.FillSolidRect(itemRC.right - 1, itemRC.top + 2, 1, itemRC.Height() - 4, RGB(172, 168, 153));
	}
	dc.Detach();
}

BOOL CNetTabCtrl::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}

void CNetTabCtrl::PreSubclassWindow() 
{
	SetMinTabWidth(100);			//设置最小选项卡的宽度
	SetItemSize(CSize(120, 32));	//设置选项卡的宽度和高度	
	CTabCtrl::PreSubclassWindow();
}
