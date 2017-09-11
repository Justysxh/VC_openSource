// TVandLVView.cpp : implementation of the CTVandLVView class
//

#include "stdafx.h"
#include "TVandLV.h"

#include "TVandLVDoc.h"
#include "TVandLVView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTVandLVView

IMPLEMENT_DYNCREATE(CTVandLVView, CView)

BEGIN_MESSAGE_MAP(CTVandLVView, CView)
	//{{AFX_MSG_MAP(CTVandLVView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTVandLVView construction/destruction

CTVandLVView::CTVandLVView()
{
	// TODO: add construction code here

}

CTVandLVView::~CTVandLVView()
{
}

BOOL CTVandLVView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTVandLVView drawing

void CTVandLVView::OnDraw(CDC* pDC)
{
	CTVandLVDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTVandLVView printing

BOOL CTVandLVView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTVandLVView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTVandLVView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTVandLVView diagnostics

#ifdef _DEBUG
void CTVandLVView::AssertValid() const
{
	CView::AssertValid();
}

void CTVandLVView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTVandLVDoc* CTVandLVView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTVandLVDoc)));
	return (CTVandLVDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTVandLVView message handlers
