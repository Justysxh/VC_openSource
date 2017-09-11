// ListButton.cpp : implementation file
//

#include "stdafx.h"
#include "aaaaa.h"
#include "ListButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListButton

CListButton::CListButton()
{
}

CListButton::~CListButton()
{
}


BEGIN_MESSAGE_MAP(CListButton, CButton)
	//{{AFX_MSG_MAP(CListButton)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListButton message handlers

void CListButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your code to draw the specified item
	CRect rect;												//声明区域对象
	GetClientRect(rect);											//获得按钮的客户区域
	CDC dc;													//声明设备上下文
	dc.Attach(lpDrawItemStruct->hDC);								//设置设备上下文
	dc.SetBkMode(TRANSPARENT);								//设置背景透明
	CBrush m_Brush(RGB(100,140,200));						//创建画刷
	dc.SelectObject(&m_Brush);									//将画刷选入设备上下文
	dc.DrawEdge(rect,BDR_RAISEDINNER|BDR_RAISEDOUTER
		,BF_BOTTOMLEFT|BF_TOPRIGHT);						//绘制立体效果
	dc.Draw3dRect(rect,RGB(51,51,51),RGB(0,0,0));			//获得焦点时绘制黑色边框
	CRect rc(rect);
	rc.DeflateRect(2,2,2,2);
	dc.FillRect(rc,&m_Brush);							//用画刷填充按钮
	CString str;
	GetWindowText(str);								//获得按钮文本
	dc.SetTextColor(RGB(255,255,255));					//设置按钮颜色
	dc.DrawText(str,CRect(0,0,rect.right,rect.bottom),
		DT_CENTER|DT_VCENTER|DT_SINGLELINE);		//绘制按钮文本
}
