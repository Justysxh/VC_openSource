// CustomScroll.cpp : implementation file
//

#include "stdafx.h"
#include "Skin.h"
#include "CustomScroll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustomScroll

CCustomScroll::CCustomScroll()
{
	m_ButtonDown = FALSE;
	m_IsLeft = FALSE;
	m_MinRange = 0;
	m_MaxRange = 200;
	m_CurPos = 0;
	m_IsLeftArrow = FALSE;
	m_IsRightArrow = FALSE;
	m_IsLeftRange = FALSE;
	m_IsRightRange = FALSE;
}

CCustomScroll::~CCustomScroll()
{
}


BEGIN_MESSAGE_MAP(CCustomScroll, CStatic)
	//{{AFX_MSG_MAP(CCustomScroll)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomScroll message handlers

BOOL CCustomScroll::CreateStatic(CWnd *pParent, DWORD dwStyle, UINT nIDStatic, UINT nID)
{
	m_pParent = pParent;
	ASSERT(m_pParent);
	
	//获取父窗口中的静态文本
	ASSERT(::IsWindow(pParent->GetDlgItem(nIDStatic)->m_hWnd));
	
	CRect recttemp;

	pParent->GetDlgItem(nIDStatic)->GetWindowRect(recttemp);

	pParent->ScreenToClient(&recttemp);

	m_ClientRect = recttemp;
	pParent->GetDlgItem(nIDStatic)->ShowWindow(SW_HIDE);


	BOOL ret = CStatic::Create("",dwStyle,m_ClientRect,pParent,nID);

	pParent->GetDlgItem(nIDStatic)->GetClientRect(m_ClientRect);

	if (ret)
	{
		CBitmap bmp;
		bmp.LoadBitmap(m_LeftArrow);
		BITMAP bInfo;
		bmp.GetBitmap(&bInfo);
		m_ThumbHeight = bInfo.bmHeight;
		m_ThumbWidth = bInfo.bmWidth;
		if (bmp.GetSafeHandle())
			bmp.DeleteObject();	

		bmp.LoadBitmap(IDB_THUMB);
		bmp.GetBitmap(&bInfo);

		m_ThumbRect.CopyRect(CRect(m_ThumbWidth,0,m_ThumbWidth+bInfo.bmWidth,bInfo.bmHeight));
		if (bmp.GetSafeHandle())
			bmp.DeleteObject();	

		SetScrollRange(m_MinRange,m_MaxRange);
	}
	ShowWindow(SW_SHOW);
	return ret;
}

void CCustomScroll::DrawControl()
{
	DrawHorScroll();
}

void CCustomScroll::DrawHorScroll()
{

	CClientDC dc(this);

	CMemDC memdc(&dc,m_ClientRect);
	CDC bmpdc;
	bmpdc.CreateCompatibleDC(&dc);

	CBitmap bmp;
	bmp.LoadBitmap(m_LeftArrow);
	
	CBitmap* pOldbmp =  bmpdc.SelectObject(&bmp);

	CRect LeftArrowRect (m_ClientRect.left,m_ClientRect.top,m_ClientRect.left+m_ThumbWidth,m_ClientRect.bottom);
	memdc.StretchBlt(m_ClientRect.left,m_ClientRect.top,m_ThumbWidth,m_ThumbHeight,&bmpdc,0,0,m_ThumbWidth,m_ThumbHeight,SRCCOPY);

	if (pOldbmp)
		bmpdc.SelectObject(pOldbmp);
	if (bmp.GetSafeHandle())
		bmp.DeleteObject();

	pOldbmp = NULL;
	//通道的开始位置和宽度
	int nChanelStart = m_ClientRect.left+m_ThumbWidth;
	int nChanelWidth = m_ClientRect.Width()- 2*m_ThumbWidth;


	//绘制通道
	bmp.LoadBitmap(m_ChanelBK);

	pOldbmp = bmpdc.SelectObject(&bmp);

	memdc.StretchBlt(nChanelStart,m_ClientRect.top,nChanelWidth,m_ClientRect.Height(),&bmpdc,0,0,1,10,SRCCOPY);
	if (pOldbmp)
		bmpdc.SelectObject(pOldbmp);
	if (bmp.GetSafeHandle())
		bmp.DeleteObject();

	//绘制右箭头
	bmp.LoadBitmap(m_RightArrow);
	pOldbmp =  bmpdc.SelectObject(&bmp);

	int nRArrowStart = m_ThumbWidth+nChanelWidth;
	memdc.StretchBlt(nRArrowStart,m_ClientRect.top,m_ThumbWidth,m_ClientRect.Height(),&bmpdc,0,0,m_ThumbWidth,m_ThumbHeight,SRCCOPY);
	//绘制滚动块
	if (bmp.GetSafeHandle())
		bmp.DeleteObject();

	bmp.LoadBitmap(m_ThumbBK);
	pOldbmp =  bmpdc.SelectObject(&bmp);
	memdc.StretchBlt(m_ThumbRect.left,m_ThumbRect.top,m_ThumbRect.Width()+1,m_ThumbRect.Height(),&bmpdc,0,0,m_ThumbRect.Width(),m_ThumbRect.Height(),SRCCOPY);

}


void CCustomScroll::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	DrawControl();
	
	// Do not call CStatic::OnPaint() for painting messages
}

void CCustomScroll::OnLButtonDown(UINT nFlags, CPoint point) 
{
	m_Startpt = point;
	
	//确定滚动区域
	CRect rcScroll = m_ClientRect;

	rcScroll.left += m_ThumbWidth;
	rcScroll.right-= m_ThumbWidth;

	DWORD  wparam;	
	
	SetCapture();
	if (m_ThumbRect.PtInRect(point))
	{
		m_ButtonDown = TRUE;
	}
	else if (rcScroll.PtInRect(point)) //单击滚动区域
	{
			
		CPoint centerPt = m_ThumbRect.CenterPoint();
		int offset = point.x-centerPt.x;
		
		
		
		if ((int)point.x<m_ThumbRect.left) //左滚动区域
			m_IsLeftRange = TRUE;
		if ((int)point.x>m_ThumbRect.right)
			m_IsRightRange= TRUE;

		m_ThumbRect.OffsetRect(offset,0);

		int left = m_ThumbRect.left; 
		int right = m_ThumbRect.right;
		


		if (left<(int)m_ThumbWidth) //判断当前滚动量是否超出了滚动范围
		{
			
			int width = m_ThumbRect.Width();
			m_ThumbRect.left = m_ThumbWidth;
			m_ThumbRect.right = m_ThumbRect.left+width; 
			m_CurPos = m_MinRange;

			wparam = MAKELONG(SB_PAGELEFT,m_CurPos)	;		
			::SendMessage(GetParent()->m_hWnd,WM_HSCROLL,wparam,(LPARAM)m_hWnd);

			DrawControl();
			return;
		}
		else if (right>(int)(m_ClientRect.Width()-m_ThumbWidth))
		{
			int width = m_ThumbRect.Width();
			m_ThumbRect.right = m_ClientRect.Width()-m_ThumbWidth; 
			m_ThumbRect.left = m_ThumbRect.right -width;
			m_CurPos = m_MaxRange;
			wparam = MAKELONG(SB_PAGERIGHT,m_CurPos);		
			::SendMessage(GetParent()->m_hWnd,WM_HSCROLL,wparam,(LPARAM)m_hWnd);
			DrawControl();
			return;					
		}
		
		int range =  m_ThumbRect.left-m_ThumbWidth;
			
		m_CurPos = m_Rate*(range);

		if (m_IsLeftRange)
		{
			
			wparam = MAKELONG(SB_PAGELEFT,m_CurPos)	;		
			::SendMessage(GetParent()->m_hWnd,WM_HSCROLL,wparam,(LPARAM)m_hWnd);	
			
		}
		else if (m_IsRightRange)
		{
			wparam = MAKELONG(SB_PAGERIGHT,m_CurPos);		
			::SendMessage(GetParent()->m_hWnd,WM_HSCROLL,wparam,(LPARAM)m_hWnd);
		}		
		DrawControl();
	}
	else  //单击箭头按钮
	{	

		if (point.x<=(int)m_ThumbWidth) //单击左箭头
		{
			if (m_CurPos>m_MinRange)
				wparam = MAKELONG(SB_LINELEFT ,1);
			else
				wparam = MAKELONG(SB_LINELEFT ,0);
			::SendMessage(GetParent()->m_hWnd,WM_HSCROLL,wparam,(LPARAM)m_hWnd);
			if (m_CurPos>m_MinRange)
				m_CurPos-=1;
			m_IsLeftArrow = TRUE;
		}
		else //单击右箭头
		{
			if (m_CurPos>=m_MaxRange)
				wparam = MAKELONG(SB_LINERIGHT ,0);
			else
				wparam = MAKELONG(SB_LINERIGHT ,1);	
			::SendMessage(GetParent()->m_hWnd,WM_HSCROLL,wparam,(LPARAM)m_hWnd);
			if (m_CurPos<m_MaxRange)
				m_CurPos+=1;
			m_IsRightArrow = TRUE;

		}
		int factpos = m_CurPos/m_Rate;		
		int width =  m_ThumbRect.Width();
		m_ThumbRect.left = m_ThumbWidth +factpos;
		m_ThumbRect.right = m_ThumbRect.left+width;

		DrawControl();
		SetTimer(1,100,NULL);
	}	
	CStatic::OnLButtonDown(nFlags, point);
}

void CCustomScroll::OnLButtonUp(UINT nFlags, CPoint point) 
{
	ReleaseCapture();
	m_ButtonDown = FALSE;
	m_IsLeftRange = FALSE;
	m_IsRightRange = FALSE;

	if (m_IsLeftArrow)
	{
		m_IsLeftArrow = FALSE;
		KillTimer(1);
	}
	if (m_IsRightArrow)
	{
		m_IsRightArrow = FALSE;
		KillTimer(1);
	}

	CStatic::OnLButtonUp(nFlags, point);
}

void CCustomScroll::OnMouseMove(UINT nFlags, CPoint point) 
{	
	if (m_ButtonDown)
	{
		int offset = point.x-m_Startpt.x;
		m_Startpt = point;	
		
		DWORD wparam;
		if (offset<=0) //向左拖动滚动块
		{
			if (m_ThumbRect.left<=(int)m_ThumbWidth)
				return;	
			else if (abs(offset)>(int)(m_ThumbRect.left-m_ThumbWidth)) //判断当前滚动量是否超出了滚动范围
			{
				int width = m_ThumbRect.Width();
				m_ThumbRect.left = m_ThumbWidth;
				m_ThumbRect.right = m_ThumbRect.left+width;
				
				m_CurPos = 0;
				wparam = MAKELONG(SB_THUMBPOSITION,m_CurPos);
				::SendMessage(GetParent()->m_hWnd,WM_HSCROLL,wparam,(LPARAM)m_hWnd);
				DrawControl();
				return;
			}
		}
		else if (offset>0) //向右拖动滚动块
		{
			if (m_ThumbRect.right>=m_ClientRect.Width()-m_ThumbWidth) //超出右箭头
			{
				return;
			}
			else if ( offset> m_ClientRect.Width()-m_ThumbWidth-m_ThumbRect.right) //判断当前滚动量是否超出了滚动范围
			{
				int width = m_ThumbRect.Width();
				m_ThumbRect.right = m_ClientRect.Width()-m_ThumbWidth; 
				m_ThumbRect.left = m_ThumbRect.right -width; 
				m_CurPos = m_MaxRange;
				wparam = MAKELONG(SB_THUMBPOSITION,m_CurPos);
				::SendMessage(GetParent()->m_hWnd,WM_HSCROLL,wparam,(LPARAM)m_hWnd);
				DrawControl();
				return;
			}			
		}
		

		m_ThumbRect.OffsetRect(offset,0);			
		int range =  m_ThumbRect.left-m_ThumbWidth;
		m_CurPos = m_Rate*(range);

		wparam = MAKELONG(SB_THUMBPOSITION,m_CurPos);
		::SendMessage(GetParent()->m_hWnd,WM_HSCROLL,wparam,(LPARAM)m_hWnd);

		DrawHorScroll();	
		
	}
	CStatic::OnMouseMove(nFlags, point);
}

void CCustomScroll::OnTimer(UINT nIDEvent) 
{
	DWORD wparam;
	if (m_IsLeftArrow)
	{
		if (m_CurPos>m_MinRange)
			wparam = MAKELONG(SB_LINELEFT ,1);
		else
			wparam = MAKELONG(SB_LINELEFT ,0);
		::SendMessage(GetParent()->m_hWnd,WM_HSCROLL,wparam,(LPARAM)m_hWnd);	
		if (m_CurPos>m_MinRange)
			m_CurPos-=1;
	}
	else if (m_IsRightArrow)
	{
		if (m_CurPos< m_MaxRange)
			wparam = MAKELONG(SB_LINERIGHT,1);
		else
			wparam = MAKELONG(SB_LINERIGHT ,0);
		::SendMessage(GetParent()->m_hWnd,WM_HSCROLL,wparam,(LPARAM)m_hWnd);
		if (m_CurPos<m_MaxRange)
			m_CurPos+=1;	
	}
	int factpos = m_CurPos/m_Rate;		
	int width =  m_ThumbRect.Width();
	m_ThumbRect.left = m_ThumbWidth +factpos;
	m_ThumbRect.right = m_ThumbRect.left+width;
	DrawControl();	

	CStatic::OnTimer(nIDEvent);
}

void CCustomScroll::SetScrollRange(int minRange, int maxRange)
{
	m_MinRange = minRange;
	m_MaxRange = maxRange;
	int ScrollRange = m_ClientRect.Width()-2*m_ThumbWidth-m_ThumbRect.Width();
	m_Rate = (m_MaxRange-m_MinRange)/(double)ScrollRange;

	Invalidate();
}
