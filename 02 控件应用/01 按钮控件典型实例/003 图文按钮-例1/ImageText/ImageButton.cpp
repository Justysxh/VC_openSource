// ImageButton.cpp : implementation file
//

#include "stdafx.h"
#include "ImageText.h"
#include "ImageButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ImageButton

ImageButton::ImageButton()
{
	IsPressed = FALSE;
}

ImageButton::~ImageButton()
{
}


BEGIN_MESSAGE_MAP(ImageButton, CButton)
	//{{AFX_MSG_MAP(ImageButton)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ImageButton message handlers

void ImageButton::SetImageIndex(UINT index)
{
	m_ImageIndex = index;
}

void ImageButton::SetImageList(CImageList *pImage)
{
	m_pImagelist = pImage;
}

void ImageButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CDC dc ;
	dc.Attach(lpDrawItemStruct->hDC);	
	if (m_pImagelist)
	{
		UINT state = lpDrawItemStruct->itemState; //获取状态
		UINT action = lpDrawItemStruct->itemAction;
		//获取图像列中图像大小
		IMAGEINFO imageinfo;
		m_pImagelist->GetImageInfo(m_ImageIndex,&imageinfo);
		CSize imagesize;
		imagesize.cx = imageinfo.rcImage.right-imageinfo.rcImage.left;
		imagesize.cy = imageinfo.rcImage.bottom - imageinfo.rcImage.top;
		//在按钮垂直方向居中显示位图
		CRect rect;
		GetClientRect(rect);
		CPoint point;
		point.x = 5;
		point.y = (rect.Height() - imagesize.cy)/2;
		m_pImagelist->Draw(&dc,m_ImageIndex,point,ILD_NORMAL|ILD_TRANSPARENT);
		//按钮被选中或者获得焦点时
		if ((state&ODS_SELECTED)||(state&ODS_FOCUS))
		{		
			CRect focusRect (rect); //焦点矩形
			focusRect.DeflateRect(4,4,4,4);
			CPen pen(PS_DASHDOTDOT,1,RGB(0,0,0));
			CBrush brush;
			brush.CreateStockObject(NULL_BRUSH);
			dc.SelectObject(&brush);
			dc.SelectObject(&pen);
			//绘制焦点矩形
			dc.DrawFocusRect(focusRect);
			//绘制立体效果
			dc.DrawEdge(rect,BDR_RAISEDINNER|BDR_RAISEDOUTER,BF_BOTTOMLEFT|BF_TOPRIGHT);			
			//获得焦点时绘制黑色边框
			dc.Draw3dRect(rect,RGB(51,51,51),RGB(0,0,0));
		}
		else  //默认情况下
		{	
			CRect focusRect (rect);
			focusRect.DeflateRect(4,4,4,4);		
			CPen pen(PS_DOT,1,RGB(192,192,192));
			CBrush brush;
			brush.CreateStockObject(NULL_BRUSH);
			dc.SelectObject(&brush);
			dc.SelectObject(&pen);
			dc.Rectangle(focusRect);			
			dc.DrawEdge(rect,BDR_RAISEDINNER|BDR_RAISEDOUTER,BF_BOTTOMLEFT|BF_TOPRIGHT);	
		}
		if (IsPressed) //在按钮被按下时绘制按下效果
		{

			CRect focusRect1(rect);
			focusRect1.DeflateRect(4,4,4,4);
			dc.DrawFocusRect(focusRect1);			
			dc.DrawEdge(rect,BDR_SUNKENINNER |BDR_SUNKENOUTER ,BF_BOTTOMLEFT|BF_TOPRIGHT);

			dc.Draw3dRect(rect,RGB(51,51,51),RGB(0,0,0));	
			//dc.DrawFocusRect(focusRect1);
		}
		//绘制按钮文本
		CString text;
		GetWindowText(text);
		rect.DeflateRect(point.x+imagesize.cx+2,0,0,0);
		dc.SetBkMode(TRANSPARENT);
		dc.DrawText(text,rect,DT_LEFT|DT_SINGLELINE|DT_VCENTER);
	}
}

void ImageButton::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CButton::PreSubclassWindow();
	ModifyStyle(0,BS_OWNERDRAW);
}

void ImageButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
/*	CRect rect;
	GetClientRect(rect);

	if (!rect.PtInRect(point)) //判断当前鼠标点是否在按钮区域内
	{
		if (IsPressed) //如果鼠标不在按钮的区域内,并且按钮处于按下状态,将按钮设置为正常状态
			IsPressed = FALSE;
	}*/
	CButton::OnMouseMove(nFlags, point);
}

void ImageButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	IsPressed = TRUE; //按钮被按下
	CButton::OnLButtonDown(nFlags, point);
}

void ImageButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	IsPressed = FALSE;	//释放鼠标按钮
	CButton::OnLButtonUp(nFlags, point);
}
