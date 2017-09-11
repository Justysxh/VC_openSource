// NumLabel.cpp : implementation file
//

#include "stdafx.h"
#include "MediaPlayer.h"
#include "NumLabel.h"
#include "CustomSlider.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNumLabel

CNumLabel::CNumLabel()
{

	m_Text = "00:00:00";
	font.CreateFont(16,0,0,0,600,0,0,0,GB2312_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH,"宋体");

	//font.CreateFont(16,12,0,0,600,0,0,0,GB2312_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH,"宋体");
}

CNumLabel::~CNumLabel()
{
}


BEGIN_MESSAGE_MAP(CNumLabel, CStatic)
	//{{AFX_MSG_MAP(CNumLabel)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNumLabel message handlers

void CNumLabel::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CRect ClientRC;
	GetClientRect(ClientRC);
	
	CMemDC memDC(&dc,ClientRC);
	memDC.SetBkMode(TRANSPARENT);
	memDC.SetTextColor(RGB(0,255,0));
	memDC.SelectObject(&font);
	memDC.DrawText(m_Text,ClientRC,DT_SINGLELINE|DT_VCENTER|DT_LEFT);	
	//绘制红色边框
	CBrush brush(RGB(255,0,0));
	memDC.FrameRect(ClientRC,&brush);
	brush.DeleteObject();

}

void CNumLabel::SetText(CString csText)
{
	m_Text = csText;
	CDC* pDC = GetDC();
	CSize szWnd = pDC->GetTextExtent(m_Text);
//	SetWindowPos(NULL,0,0,szWnd.cx,szWnd.cy,SWP_NOMOVE|SWP_SHOWWINDOW);
	//	CRect ClientRC;
//	GetClientRect(ClientRC);
	//InvalidateRect(ClientRC);
	RedrawWindow();
}
