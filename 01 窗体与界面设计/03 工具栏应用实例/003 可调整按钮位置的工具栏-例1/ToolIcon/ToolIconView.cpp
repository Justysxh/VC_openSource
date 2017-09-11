// ToolIconView.cpp : implementation of the CToolIconView class
//

#include "stdafx.h"
#include "ToolIcon.h"

#include "ToolIconDoc.h"
#include "ToolIconView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToolIconView

IMPLEMENT_DYNCREATE(CToolIconView, CView)

BEGIN_MESSAGE_MAP(CToolIconView, CView)
	//{{AFX_MSG_MAP(CToolIconView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToolIconView construction/destruction

CToolIconView::CToolIconView()
{
	// TODO: add construction code here

}

CToolIconView::~CToolIconView()
{
}

BOOL CToolIconView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CToolIconView drawing

void CToolIconView::OnDraw(CDC* pDC)
{
	CToolIconDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CToolIconView printing

BOOL CToolIconView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CToolIconView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CToolIconView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CToolIconView diagnostics

#ifdef _DEBUG
void CToolIconView::AssertValid() const
{
	CView::AssertValid();
}

void CToolIconView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CToolIconDoc* CToolIconView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CToolIconDoc)));
	return (CToolIconDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CToolIconView message handlers
