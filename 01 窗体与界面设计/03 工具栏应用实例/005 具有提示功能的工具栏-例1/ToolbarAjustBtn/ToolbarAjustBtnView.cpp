// ToolbarAjustBtnView.cpp : implementation of the CToolbarAjustBtnView class
//

#include "stdafx.h"
#include "ToolbarAjustBtn.h"

#include "ToolbarAjustBtnDoc.h"
#include "ToolbarAjustBtnView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToolbarAjustBtnView

IMPLEMENT_DYNCREATE(CToolbarAjustBtnView, CView)

BEGIN_MESSAGE_MAP(CToolbarAjustBtnView, CView)
	//{{AFX_MSG_MAP(CToolbarAjustBtnView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToolbarAjustBtnView construction/destruction

CToolbarAjustBtnView::CToolbarAjustBtnView()
{
	// TODO: add construction code here

}

CToolbarAjustBtnView::~CToolbarAjustBtnView()
{
}

BOOL CToolbarAjustBtnView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CToolbarAjustBtnView drawing

void CToolbarAjustBtnView::OnDraw(CDC* pDC)
{
	CToolbarAjustBtnDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CToolbarAjustBtnView printing

BOOL CToolbarAjustBtnView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CToolbarAjustBtnView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CToolbarAjustBtnView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CToolbarAjustBtnView diagnostics

#ifdef _DEBUG
void CToolbarAjustBtnView::AssertValid() const
{
	CView::AssertValid();
}

void CToolbarAjustBtnView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CToolbarAjustBtnDoc* CToolbarAjustBtnView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CToolbarAjustBtnDoc)));
	return (CToolbarAjustBtnDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CToolbarAjustBtnView message handlers
