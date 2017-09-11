// MyStatic.cpp : implementation file
//

#include "stdafx.h"
#include "RutineDemo.h"
#include "MyStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyStatic

CMyStatic::CMyStatic()
{
	m_titlefont.CreateFont(-20,-18,0,0,900,0,0,0,DEFAULT_CHARSET,OUT_DEVICE_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,FF_ROMAN,"»ªÎÄÖÐËÎ");
}

CMyStatic::~CMyStatic()
{

}


BEGIN_MESSAGE_MAP(CMyStatic, CStatic)
	//{{AFX_MSG_MAP(CMyStatic)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyStatic message handlers

void CMyStatic::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CDC* pDC = GetDC();
	CRect m_rect;
	GetClientRect(m_rect);

	pDC->SelectObject(&m_titlefont);
	CString str;
	GetWindowText(str);
	CPen pen(PS_SOLID,1,RGB(255,0,0));
	pDC->SetTextColor(RGB(255,0,0));
	pDC->TextOut(0,0, str);
}
