// TreeNaviView.cpp : implementation of the CTreeNaviView class
//

#include "stdafx.h"
#include "TreeNavi.h"

#include "TreeNaviDoc.h"
#include "TreeNaviView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreeNaviView

IMPLEMENT_DYNCREATE(CTreeNaviView, CView)

BEGIN_MESSAGE_MAP(CTreeNaviView, CView)
	//{{AFX_MSG_MAP(CTreeNaviView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreeNaviView construction/destruction

CTreeNaviView::CTreeNaviView()
{
	// TODO: add construction code here

}

CTreeNaviView::~CTreeNaviView()
{
}

BOOL CTreeNaviView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTreeNaviView drawing

void CTreeNaviView::OnDraw(CDC* pDC)
{
	CTreeNaviDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTreeNaviView diagnostics

#ifdef _DEBUG
void CTreeNaviView::AssertValid() const
{
	CView::AssertValid();
}

void CTreeNaviView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTreeNaviDoc* CTreeNaviView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTreeNaviDoc)));
	return (CTreeNaviDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTreeNaviView message handlers
