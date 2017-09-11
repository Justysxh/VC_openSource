// EditToolView.cpp : implementation of the CEditToolView class
//

#include "stdafx.h"
#include "EditTool.h"

#include "EditToolDoc.h"
#include "EditToolView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditToolView

IMPLEMENT_DYNCREATE(CEditToolView, CView)

BEGIN_MESSAGE_MAP(CEditToolView, CView)
	//{{AFX_MSG_MAP(CEditToolView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditToolView construction/destruction

CEditToolView::CEditToolView()
{
	// TODO: add construction code here

}

CEditToolView::~CEditToolView()
{
}

BOOL CEditToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEditToolView drawing

void CEditToolView::OnDraw(CDC* pDC)
{
	CEditToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEditToolView printing

BOOL CEditToolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEditToolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEditToolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEditToolView diagnostics

#ifdef _DEBUG
void CEditToolView::AssertValid() const
{
	CView::AssertValid();
}

void CEditToolView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEditToolDoc* CEditToolView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEditToolDoc)));
	return (CEditToolDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEditToolView message handlers
