// SuperLabel.cpp : implementation file
//

#include "stdafx.h"
#include "SuperConnect.h"
#include "SuperLabel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSuperLabel

CSuperLabel::CSuperLabel()
{
//	m_Font.CreateFont(18,18,0,0,400,0,1,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DRAFT_QUALITY,DEFAULT_PITCH,"¿¬Ìå32");

}

CSuperLabel::~CSuperLabel()
{
}


BEGIN_MESSAGE_MAP(CSuperLabel, CStatic)
	//{{AFX_MSG_MAP(CSuperLabel)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSuperLabel message handlers

void CSuperLabel::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CDC* pDC = GetDC();

	CString text;
	GetWindowText(text);
	
	if (m_ConnectStr.IsEmpty())
		m_ConnectStr = text;

	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(RGB(0,0,255));


	pDC->SelectObject(&m_Font);
	pDC->TextOut(0,0,text);

	// Do not call CStatic::OnPaint() for painting messages
}

void CSuperLabel::OnLButtonDown(UINT nFlags, CPoint point) 
{

	ShellExecute(m_hWnd,NULL,m_ConnectStr,NULL,NULL,SW_SHOW);		
	CStatic::OnLButtonDown(nFlags, point);
}

void CSuperLabel::PreSubclassWindow() 
{	
	GetWindowText(m_ConnectStr);
	CFont* pFont = GetFont();

	pFont->GetLogFont(&lfont);
	lfont.lfUnderline =TRUE;
	m_Font.CreateFontIndirect(&lfont);
	CStatic::PreSubclassWindow();
}

void CSuperLabel::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
	CStatic::OnMouseMove(nFlags, point);
}
