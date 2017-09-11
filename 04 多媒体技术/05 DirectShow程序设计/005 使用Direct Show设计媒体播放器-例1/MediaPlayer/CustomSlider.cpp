// CustomSlider.cpp : implementation file
//

#include "stdafx.h"
#include "MediaPlayer.h"
#include "CustomSlider.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustomSlider


CCustomSlider::CCustomSlider()
{
	m_bDown = FALSE;
}

CCustomSlider::~CCustomSlider()
{
}


BEGIN_MESSAGE_MAP(CCustomSlider, CSliderCtrl)
	//{{AFX_MSG_MAP(CCustomSlider)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomSlider message handlers

void CCustomSlider::OnPaint() 
{
	CPaintDC dc(this);
	
	int nPos = GetPos();
	SetPos(nPos);
	CRect ThumbRC;
	GetThumbRect(ThumbRC);

	//获取滑块的宽度和高度
	CBitmap bmp;
	bmp.LoadBitmap(IDB_THUMB);
	BITMAP bmpInfo;
	bmp.GetBitmap(&bmpInfo);
	//获取位图高度和宽度
	int bmpWidth = bmpInfo.bmWidth;
	int bmpHeight = bmpInfo.bmHeight;

	CRect ClientRC,ChanelRC;
	GetClientRect(ClientRC);
	GetChannelRect(ChanelRC);

	//绘制背景
	CBitmap bmpBK;
	BITMAP BKInfo;
	bmpBK.LoadBitmap(IDB_BK);
	bmpBK.GetBitmap(&BKInfo);
	int nBKWidth = BKInfo.bmWidth;
	int nBKHeight = BKInfo.bmHeight;

	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	memDC.SelectObject(&bmpBK);

	int nRightMargin = ClientRC.Width()-ChanelRC.left-ChanelRC.Width();
	ClientRC.right = ChanelRC.left +ChanelRC.Width()+nRightMargin;

	ClientRC.left = ChanelRC.left;
	CMemDC bkMemDC(&dc,ClientRC);

	bkMemDC.StretchBlt(ChanelRC.left,0,ChanelRC.Width()+ChanelRC.left,ClientRC.Height(),
						&memDC,0,0,nBKWidth,nBKHeight,SRCCOPY);

	bmpBK.DeleteObject();
	memDC.DeleteDC();

	memDC.CreateCompatibleDC(&dc);
	memDC.SelectObject(&bmp);
	bkMemDC.StretchBlt(ThumbRC.left,ThumbRC.top, ThumbRC.Width(),ClientRC.Height(),&memDC,0,0,bmpWidth,bmpHeight,SRCCOPY);
	bmp.DeleteObject();
	memDC.DeleteDC();
}

void CCustomSlider::OnMouseMove(UINT nFlags, CPoint point) 
{
	if (m_bDown)
	{
	//	CRect ThumbRC;
	//	GetThumbRect(ThumbRC);
	//	Invalidate;
	//	InvalidateRect(ThumbRC);
	}
	CSliderCtrl::OnMouseMove(nFlags, point);
}

void CCustomSlider::OnLButtonDown(UINT nFlags, CPoint point) 
{
	SetCapture();
	m_bDown = TRUE;
	CSliderCtrl::OnLButtonDown(nFlags, point);
}

void CCustomSlider::OnLButtonUp(UINT nFlags, CPoint point) 
{
	ReleaseCapture();
	m_bDown = FALSE;
	CSliderCtrl::OnLButtonUp(nFlags, point);
}


void CCustomSlider::PreSubclassWindow() 
{
	CSliderCtrl::PreSubclassWindow();
}
