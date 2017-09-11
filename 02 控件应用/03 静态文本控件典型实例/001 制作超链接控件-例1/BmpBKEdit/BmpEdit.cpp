// BmpEdit.cpp : implementation file
//

#include "stdafx.h"
#include "BmpBKEdit.h"
#include "BmpEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBmpEdit

CBmpEdit::CBmpEdit()
{
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
}

CBmpEdit::~CBmpEdit()
{
}


BEGIN_MESSAGE_MAP(CBmpEdit, CEdit)
	//{{AFX_MSG_MAP(CBmpEdit)
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_ERASEBKGND()
	ON_CONTROL_REFLECT(EN_CHANGE, OnChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBmpEdit message handlers

HBRUSH CBmpEdit::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	// TODO: Change any attributes of the DC here
	pDC->SetBkMode(TRANSPARENT);
	// TODO: Return a non-NULL brush if the parent's handler should not be called
	return NULL;
}

BOOL CBmpEdit::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	memDC.SelectObject(&m_Bitmap);
	BITMAP m_Bmp;
	m_Bitmap.GetBitmap(&m_Bmp);
	int x = m_Bmp.bmWidth;
	int y = m_Bmp.bmHeight;
	CRect rect;
	GetClientRect(rect);
	pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&memDC,0,0,x,y,SRCCOPY);
	memDC.DeleteDC();
	return TRUE;
//	return CEdit::OnEraseBkgnd(pDC);
}

void CBmpEdit::OnChange() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CEdit::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	Invalidate();
}
