// SnailView.cpp : implementation of the CSnailView class
//

#include "stdafx.h"
#include "Snail.h"

#include "SnailDoc.h"
#include "SnailView.h"
#include "math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSnailView

IMPLEMENT_DYNCREATE(CSnailView, CView)

BEGIN_MESSAGE_MAP(CSnailView, CView)
	//{{AFX_MSG_MAP(CSnailView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnailView construction/destruction

CSnailView::CSnailView()
{
	pi=3.1415;
}

CSnailView::~CSnailView()
{
}

BOOL CSnailView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSnailView drawing

void CSnailView::OnDraw(CDC* pDC)
{
	CSnailDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDC->SetWindowOrg(-100,-100);
	for(double i=0;i<40;i+=pi/600)
	{
		if(i==0)
			pDC->SetPixel(0,0,RGB(0,128,128));
		else
			pDC->SetPixel((20*sin(i)/i*cos(i))*10,(20*sin(i)/i*sin(i))*10,RGB(128,128,128));
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSnailView printing

BOOL CSnailView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSnailView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSnailView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSnailView diagnostics

#ifdef _DEBUG
void CSnailView::AssertValid() const
{
	CView::AssertValid();
}

void CSnailView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSnailDoc* CSnailView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSnailDoc)));
	return (CSnailDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSnailView message handlers
