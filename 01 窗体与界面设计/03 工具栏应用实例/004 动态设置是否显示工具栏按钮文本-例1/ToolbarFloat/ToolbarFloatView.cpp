// ToolbarFloatView.cpp : implementation of the CToolbarFloatView class
//

#include "stdafx.h"
#include "ToolbarFloat.h"

#include "ToolbarFloatDoc.h"
#include "ToolbarFloatView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToolbarFloatView

IMPLEMENT_DYNCREATE(CToolbarFloatView, CView)

BEGIN_MESSAGE_MAP(CToolbarFloatView, CView)
	//{{AFX_MSG_MAP(CToolbarFloatView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToolbarFloatView construction/destruction

CToolbarFloatView::CToolbarFloatView()
{
	// TODO: add construction code here

}

CToolbarFloatView::~CToolbarFloatView()
{
}

BOOL CToolbarFloatView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CToolbarFloatView drawing

void CToolbarFloatView::OnDraw(CDC* pDC)
{
	CToolbarFloatDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CToolbarFloatView printing

BOOL CToolbarFloatView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CToolbarFloatView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CToolbarFloatView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CToolbarFloatView diagnostics

#ifdef _DEBUG
void CToolbarFloatView::AssertValid() const
{
	CView::AssertValid();
}

void CToolbarFloatView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CToolbarFloatDoc* CToolbarFloatView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CToolbarFloatDoc)));
	return (CToolbarFloatDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CToolbarFloatView message handlers
