// MyLabel.cpp : implementation file
//

#include "stdafx.h"
#include "MoneyBox.h"
#include "MyLabel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyLabel

CMyLabel::CMyLabel()
{
	m_Font.CreateFont(24,20,0,0,900,0,0,0,DEFAULT_CHARSET,OUT_DEVICE_PRECIS,CLIP_LH_ANGLES,DRAFT_QUALITY ,FF_SWISS ,"¡• È");
}

CMyLabel::~CMyLabel()
{

}

BEGIN_MESSAGE_MAP(CMyLabel, CStatic)
	//{{AFX_MSG_MAP(CMyLabel)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CMyLabel::OnPaint() 
{
	CPaintDC dc(this); 
	
	dc.SelectObject(&m_Font);
	CString str;
	dc.SetBkMode(TRANSPARENT);
	GetWindowText(str);
	dc.TextOut(0,0,str);
}
