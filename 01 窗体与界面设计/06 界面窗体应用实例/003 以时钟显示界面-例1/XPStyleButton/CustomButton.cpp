// CustomButton.cpp : implementation file
//

#include "stdafx.h"
#include "XPStyleButton.h"
#include "CustomButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustomButton

CCustomButton::CCustomButton()
{
	m_State   = bsNormal;
}

CCustomButton::~CCustomButton()
{
	m_State   = bsNormal;
}


BEGIN_MESSAGE_MAP(CCustomButton, CButton)
	//{{AFX_MSG_MAP(CCustomButton)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomButton message handlers


void CCustomButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	m_State = bsDown;					//设置按钮按下状态
	InvalidateRect(NULL,TRUE);		//更新按钮
}

void CCustomButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	HRGN hRgn = CreateRectRgn(0, 0, 0, 0);
	GetWindowRgn(hRgn);
	BOOL ret = PtInRegion(hRgn, point.x, point.y);//鼠标是否在按钮上
	if(ret)							//在按钮上
	{
		if(m_State == bsDown) 		//判断按钮是否为按下状态
			return ;
		if(m_State != bsHot) 			//判断按钮是否不是热点状态
		{
			m_State = bsHot;			//设置为热点状态
			InvalidateRect(NULL,TRUE);	//更新按钮
			SetCapture();				//捕获鼠标
		}
	} 
	else								//不在按钮上
	{
		m_State = bsNormal;				//设置按钮状态
		InvalidateRect(NULL,TRUE);		//更新按钮
		ReleaseCapture();				//释放鼠标
	}	
	DeleteObject( hRgn );	

	CButton::OnMouseMove(nFlags, point);
}

void CCustomButton::OnPaint() 
{
	CPaintDC dc(this); 					//获取按钮的设备上下文
	CString		Text;					//定义一个字符串变量
	CRect		RC;						//定义一个区域对象
	CFont		Font;					//定义一个字体对象
	CFont		*pOldFont;				//定义一个字体对象指针，用于存储之前的字体
	CBrush		Brush;					//定义一个画刷对象
	CBrush		*pOldBrush;				//定义一个画刷对象指针，用于存储之前的画刷对象
	CPoint		PT(2,2);					//定义一个点对象
	dc.SetBkMode(TRANSPARENT);		//将设备上下文背景模式设置为透明
	Font.CreateFont(12, 0, 0, 0, FW_HEAVY, 0, 0, 0, ANSI_CHARSET, 
		OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		VARIABLE_PITCH | FF_SWISS, "宋体");		//创建字体
	pOldFont = dc.SelectObject(&Font);						//选中新的字体
	if(m_State == bsNormal)				//判断按钮是否为正常状态
	{
		Brush.CreateSolidBrush( RGB(230, 230, 230)); 	//创建指定颜色的画刷
		dc.SetTextColor(RGB(0, 0, 0));		//设置文本颜色
	}
	else if(m_State == bsDown)			//判断按钮是否为按下状态
	{
		Brush.CreateSolidBrush(RGB(100, 100, 180));	//创建指定颜色的画刷
		dc.SetTextColor(RGB(250, 250, 0));		//设置文本颜色
	}
	else if(m_State == bsHot)			//判断按钮是否为热点状态
	{
		Brush.CreateSolidBrush(RGB(230, 230, 130));	//创建指定颜色的画刷
		dc.SetTextColor(RGB(50, 50, 250));		//设置文本颜色
	}
	pOldBrush = dc.SelectObject(&Brush);					//选中画刷
	GetClientRect(&RC);							//获取按钮的客户区域
	dc.RoundRect(&RC, PT);								//利用当前选中的画刷和画笔绘制按钮区域
	HRGN hRgn = CreateRectRgn(RC.left, RC.top, RC.right, RC.bottom);		//创建一个选区
	SetWindowRgn(hRgn, TRUE);								//设置按钮窗口区域
	DeleteObject(hRgn);												//删除选区
	GetWindowText(Text);										//获取按钮文本
	dc.DrawText(Text, &RC, DT_CENTER | DT_VCENTER | DT_SINGLELINE);	//绘制按钮文本
	Font.DeleteObject();												//删除字体对象
	Brush.DeleteObject();												//删除画刷对象
	dc.SelectObject(pOldFont);											//恢复原来选中的字体
	dc.SelectObject(pOldBrush);										//恢复原来选中的画刷
}

void CCustomButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if(m_State != bsNormal)			//判断按钮状态
	{
		m_State = bsNormal;			//设置按钮状态
		ReleaseCapture();				//释放鼠标捕捉
		InvalidateRect(NULL,TRUE);	//更新按钮
	}	
	//向父窗口发送命令消息
	::SendMessage(GetParent()->m_hWnd,WM_COMMAND, GetDlgCtrlID(), (LPARAM) m_hWnd);
}
