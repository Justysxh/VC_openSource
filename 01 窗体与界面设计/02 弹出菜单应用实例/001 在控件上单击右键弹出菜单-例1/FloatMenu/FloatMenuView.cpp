// FloatMenuView.cpp : implementation of the CFloatMenuView class
//

#include "stdafx.h"
#include "FloatMenu.h"

#include "FloatMenuDoc.h"
#include "FloatMenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFloatMenuView

IMPLEMENT_DYNCREATE(CFloatMenuView, CView)

BEGIN_MESSAGE_MAP(CFloatMenuView, CView)
	//{{AFX_MSG_MAP(CFloatMenuView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFloatMenuView construction/destruction

CFloatMenuView::CFloatMenuView()
{
	// TODO: add construction code here

}

CFloatMenuView::~CFloatMenuView()
{
}

BOOL CFloatMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFloatMenuView drawing

void CFloatMenuView::OnDraw(CDC* pDC)
{
	CFloatMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CFloatMenuView printing

BOOL CFloatMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFloatMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFloatMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFloatMenuView diagnostics

#ifdef _DEBUG
void CFloatMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CFloatMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFloatMenuDoc* CFloatMenuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFloatMenuDoc)));
	return (CFloatMenuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFloatMenuView message handlers
