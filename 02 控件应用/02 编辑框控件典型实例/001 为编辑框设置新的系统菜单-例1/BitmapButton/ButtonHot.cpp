// ButtonHot.cpp : implementation file
//

#include "stdafx.h"
#include "BitmapButton.h"
#include "ButtonHot.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CButtonHot

CButtonHot::CButtonHot()
{
	m_DownPic   = IDB_BUTTONDOWN;		//鼠标按下时显示的图片
	m_NomalPic  = IDB_BUTTONUP;			//正常情况下显示的图片
	m_EnablePic = IDB_BUTTONENABLE;		//按钮失效时显示的图片
	m_MovePic   = IDB_BUTTONMOVE;		//鼠标经过按钮时显示的图片
	m_IsInRect  = FALSE;
}

CButtonHot::~CButtonHot()
{
}


BEGIN_MESSAGE_MAP(CButtonHot, CButton)
	//{{AFX_MSG_MAP(CButtonHot)
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CButtonHot message handlers

void CButtonHot::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your code to draw the specified item
	CDC dc;														//声明设备上下文
	dc.Attach(lpDrawItemStruct->hDC);									//获得绘制按钮设备上下文
	UINT state = lpDrawItemStruct->itemState; 							//获取状态
	CRect rect;													//声明区域对象
	GetClientRect(rect);										//获得编辑框客户区域
	CString text;
	GetWindowText(text);
	
	if(state & ODS_DISABLED)
	{
		DrawBK(&dc,m_EnablePic);
		dc.SetTextColor(RGB(0,0,0));
	}
	else if(state&ODS_SELECTED)
	{
		DrawBK(&dc,m_DownPic);
		dc.SetTextColor(RGB(0,0,255));
	}
	else if(m_IsInRect==TRUE)
	{
		DrawBK(&dc,m_MovePic);
		dc.SetTextColor(RGB(255,0,0));
	}
	else 													//默认情况下
	{
		DrawBK(&dc,m_NomalPic);
		dc.SetTextColor(RGB(0,0,0));
	}
	if(state&ODS_FOCUS)
	{
		CRect FocTect(rect);
		FocTect.DeflateRect(2,2,2,2);
		dc.DrawFocusRect(&FocTect);
		lpDrawItemStruct->itemAction = ODA_FOCUS ;
	}
	dc.SetBkMode(TRANSPARENT);
	dc.DrawText(text,&rect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
}

void CButtonHot::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CPoint point;						//声明Cpoint变量
	GetCursorPos(&point); 				//获得鼠标位置
	CRect rcWnd;						//声明区域对象
	GetWindowRect(&rcWnd); 			//获得按钮区域
	if(rcWnd.PtInRect(point)) 				//判断鼠标是否在按钮上
	{
		if(m_IsInRect == TRUE) 			//判断鼠标是否一直在按钮上
			goto END;					//跳转到标记
		else							//鼠标移动到按钮上
		{
			m_IsInRect = TRUE;			//设置m_IsInRect变量值
			Invalidate(); 				//重绘按钮
		}
	}
	else															//不在按钮区域内
	{
		if(m_IsInRect == FALSE)										//判断鼠标一直在按钮外
			goto END;												//跳转到标记
		else														//鼠标移动到按钮外
		{
			Invalidate(); 											//重绘按钮
			m_IsInRect = FALSE;										//设置m_IsInRect变量值
		}
	}
END:	CButton::OnTimer(nIDEvent);									//设置标记，调用基类方法
}

void CButtonHot::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	SetTimer(1,10,NULL); 				//设置定时器
	CButton::PreSubclassWindow();
}

BOOL CButtonHot::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return true;//CButton::OnEraseBkgnd(pDC);
}

void CButtonHot::DrawBK(CDC *pDC, UINT ResID)
{
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CRect rect;													//声明区域对象
	GetClientRect(rect);										//获得编辑框客户区域
	CBitmap bitmap;
	BITMAP bitStruct;
	bitmap.LoadBitmap(ResID);
	bitmap.GetBitmap(&bitStruct);
	memDC.SelectObject(&bitmap);
	pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&memDC,0,0,bitStruct.bmWidth
		,bitStruct.bmHeight,SRCCOPY);
	memDC.DeleteDC();
	bitmap.DeleteObject();
}

BOOL CButtonHot::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->hwnd==this->GetSafeHwnd()&&pMsg->message==WM_KEYDOWN && pMsg->wParam==13)
	{
		pMsg->lParam  = 0;
		pMsg->message = WM_LBUTTONDOWN;
	}
	if(pMsg->hwnd==this->GetSafeHwnd()&&pMsg->message==WM_KEYUP && pMsg->wParam==13)
	{
		pMsg->lParam  = 0;
		pMsg->message = WM_LBUTTONUP;
	}
	return CButton::PreTranslateMessage(pMsg);
}