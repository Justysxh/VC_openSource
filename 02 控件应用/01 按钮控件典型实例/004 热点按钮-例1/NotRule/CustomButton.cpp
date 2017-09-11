// CustomButton.cpp : implementation file
//

#include "stdafx.h"
#include "NotRule.h"
#include "CustomButton.h"
#include <cmath>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define PI 2.0*asin(1.0)
/////////////////////////////////////////////////////////////////////////////
// CCustomButton

CCustomButton::CCustomButton()
{
	IsPressed = false; 
}

CCustomButton::~CCustomButton()
{
}


BEGIN_MESSAGE_MAP(CCustomButton, CButton)
//{{AFX_MSG_MAP(CCustomButton)
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomButton message handlers
void CCustomButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{ 
	CRect rect;
	GetClientRect(rect);								//获得按钮客户区域
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);					//获得设备上下文
	int x,y,r;
	x = rect.Width()/2;
	y = rect.top;
	r = rect.Height()/2;
	double lpi=0;
	arrays[0] = CPoint(x,y);							//设置多边形第一个顶点坐标
	if(m_result)
	{
		for(int i=1;i<m_num;i++)						//根据多边形顶点数循环
		{
			lpi+=(2*PI/m_num);							//获得每个顶点的相对角度
			if(lpi<=2*PI/4)								//小于等于90度时
			{
				arrays[i] = CPoint(x+r*sin(2*i*PI/m_num),r-r*cos(2*i*PI/m_num));
			}
			if(lpi>2*PI/4 && lpi<=2*PI/2)					//大于90度小于等于180读
			{
				arrays[i] = CPoint(x+r*sin(PI-2*i*PI/m_num),r+r*cos(PI-2*i*PI/m_num));
			}
			if(lpi>2*PI/2 && lpi<=2*PI*3/4)					//大于180度小于等于270度
			{
				arrays[i] = CPoint(x-r*sin(2*i*PI/m_num-2*PI/2),r+r*cos(2*i*PI/m_num-2*PI/2));
			}
			if(lpi>2*PI*3/4 && lpi<=2*PI)					//大于270度小于等于360度
			{
				arrays[i] = CPoint(x-r*sin(2*PI-2*i*PI/m_num),r-r*cos(2*PI-2*i*PI/m_num));
			}
		}
	}
	dc.SetBkMode(TRANSPARENT);  					//设置背景透明
	CBrush brush(m_color);  							//创建一个位图画刷
	dc.SelectObject(&brush);
	CPen pen(PS_NULL,1,m_color);					//创建画笔
	dc.SelectObject(&pen);
	if(m_result)
		dc.Polygon(arrays,m_num);							//绘制多边形
	else
		dc.Ellipse(0,0,rect.Width(),rect.Height());					//绘制圆形
	if(IsPressed) 										//判断鼠标是否按下
	{
		CPen pen(PS_DASHDOTDOT,2,RGB(0,0,0));				//创建画笔
		dc.SelectObject(&pen);
		if(m_result)
		{
			dc.MoveTo(arrays[0]);							//设置起点
			for(int i=1;i<m_num;i++)
			{
				dc.LineTo(arrays[i]);							//画线
			}
			dc.LineTo(arrays[0]);
		}
		else
			dc.Ellipse(0,0,rect.Width(),rect.Height());				//绘制圆形
	}
	else
	{
		CPen pen(PS_DASHDOTDOT,2,m_color);				//设置画笔
		dc.SelectObject(&pen);
		if(m_result)
		{
			dc.MoveTo(arrays[0]);							//设置顶点
			for(int i=1;i<m_num;i++)
			{
				dc.LineTo(arrays[i]);							//画多边形边线
			}
			dc.LineTo(arrays[0]);
		}
		else
			dc.Ellipse(0,0,rect.Width(),rect.Height());				//绘制圆形
	}
	
	CString str;
	GetWindowText(str);									//获得按钮文本
	dc.SetTextColor(RGB(0,0,0));							//设置文本颜色
	dc.DrawText(str,CRect(0,0,rect.right,rect.bottom),DT_CENTER|DT_VCENTER|DT_SINGLELINE);	//绘制按钮文本
}


void CCustomButton::SetPolygon(int num)
{
	m_num = num;
}

void CCustomButton::SetResult(BOOL result,COLORREF color)
{
	m_result = result;
	m_color = color;   
}

void CCustomButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	IsPressed = true; 
	CButton::OnLButtonDown(nFlags, point);
}

void CCustomButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	IsPressed = false; 
	CButton::OnLButtonUp(nFlags, point);
}
