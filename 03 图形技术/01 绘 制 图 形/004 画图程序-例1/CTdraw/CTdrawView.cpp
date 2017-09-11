// CTdrawView.cpp : implementation of the CCTdrawView class
//

#include "stdafx.h"
#include "CTdraw.h"

#include "CTdrawDoc.h"
#include "CTdrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCTdrawView

IMPLEMENT_DYNCREATE(CCTdrawView, CView)

BEGIN_MESSAGE_MAP(CCTdrawView, CView)
	//{{AFX_MSG_MAP(CCTdrawView)
	ON_COMMAND(ID_MENUDRAW, OnMenudraw)
	ON_UPDATE_COMMAND_UI(ID_MENUDRAW, OnUpdateMenudraw)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_MENUJUXING, OnMenujuxing)
	ON_COMMAND(ID_MENUYUAN, OnMenuyuan)
	ON_UPDATE_COMMAND_UI(ID_MENUJUXING, OnUpdateMenujuxing)
	ON_UPDATE_COMMAND_UI(ID_MENUYUAN, OnUpdateMenuyuan)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCTdrawView construction/destruction

CCTdrawView::CCTdrawView()
{
	// TODO: add construction code here
	m_draw = true;
	m_juxing = false;
	m_yuan = false;
}

CCTdrawView::~CCTdrawView()
{
}

BOOL CCTdrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCTdrawView drawing

void CCTdrawView::OnDraw(CDC* pDC)
{
	CCTdrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CCTdrawView printing

BOOL CCTdrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCTdrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCTdrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCTdrawView diagnostics

#ifdef _DEBUG
void CCTdrawView::AssertValid() const
{
	CView::AssertValid();
}

void CCTdrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCTdrawDoc* CCTdrawView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCTdrawDoc)));
	return (CCTdrawDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCTdrawView message handlers

void CCTdrawView::OnMenudraw() 
{
	// TODO: Add your command handler code here
	ResetAllFlags();
	m_draw = true;
}

void CCTdrawView::ResetAllFlags()
{
	m_draw = false;
	m_juxing = false;
	m_yuan = false;
}

void CCTdrawView::OnUpdateMenudraw(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_draw);
}

void CCTdrawView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_draw)
	{
		m_start = point;
	}
	if(m_juxing||m_yuan)
	{
		m_start = point;
		m_end = point;
		SetCapture();
	}
	CView::OnLButtonDown(nFlags, point);
}

void CCTdrawView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}

void CCTdrawView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	if(m_draw&&(nFlags&&MK_LBUTTON))
	{
		dc.MoveTo(m_start);
		dc.LineTo(point);
		m_start = point;
	}
	if(m_juxing&&(nFlags&&MK_LBUTTON))
	{
		CGdiObject*object = dc.SelectStockObject(NULL_BRUSH);
		int mdoe = dc.GetROP2();
		dc.SetROP2(R2_NOTCOPYPEN);
		dc.Rectangle(m_end.x,m_end.y,m_start.x,m_start.y);
		dc.SetROP2(mdoe);
		dc.Rectangle(m_start.x,m_start.y,point.x,point.y);
		dc.SelectObject(object);
		m_end = point;
	}
	if(m_yuan&&(nFlags&&MK_LBUTTON))
	{
		CGdiObject*object = dc.SelectStockObject(NULL_BRUSH);
		int mdoe = dc.GetROP2();
		dc.SetROP2(R2_NOTCOPYPEN);
		dc.Ellipse(m_end.x,m_end.y,m_start.x,m_start.y);
		dc.SetROP2(mdoe);
		dc.Ellipse(m_start.x,m_start.y,point.x,point.y);
		dc.SelectObject(object);
		m_end = point;
	}
	CView::OnMouseMove(nFlags, point);
}

void CCTdrawView::OnMenujuxing() 
{
	// TODO: Add your command handler code here
	ResetAllFlags();
	m_juxing = true;
}

void CCTdrawView::OnMenuyuan() 
{
	// TODO: Add your command handler code here
	ResetAllFlags();
	m_yuan = true;
}

void CCTdrawView::OnUpdateMenujuxing(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_juxing);
}

void CCTdrawView::OnUpdateMenuyuan(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_yuan);
}
