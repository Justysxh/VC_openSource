// IconMenuView.cpp : implementation of the CIconMenuView class
//

#include "stdafx.h"
#include "IconMenu.h"

#include "IconMenuDoc.h"
#include "IconMenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIconMenuView

IMPLEMENT_DYNCREATE(CIconMenuView, CView)

BEGIN_MESSAGE_MAP(CIconMenuView, CView)
	//{{AFX_MSG_MAP(CIconMenuView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIconMenuView construction/destruction

CIconMenuView::CIconMenuView()
{
	// TODO: add construction code here

}

CIconMenuView::~CIconMenuView()
{
}

BOOL CIconMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CIconMenuView drawing

void CIconMenuView::OnDraw(CDC* pDC)
{
	this->SetWindowText("sss");
	CIconMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CIconMenuView printing

BOOL CIconMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CIconMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CIconMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CIconMenuView diagnostics

#ifdef _DEBUG
void CIconMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CIconMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIconMenuDoc* CIconMenuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIconMenuDoc)));
	return (CIconMenuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CIconMenuView message handlers
