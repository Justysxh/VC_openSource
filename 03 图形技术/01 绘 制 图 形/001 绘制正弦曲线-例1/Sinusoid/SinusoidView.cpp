// SinusoidView.cpp : implementation of the CSinusoidView class
//

#include "stdafx.h"
#include "Sinusoid.h"
#include "math.h"
#include "SinusoidDoc.h"
#include "SinusoidView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define PI 3.1415926
/////////////////////////////////////////////////////////////////////////////
// CSinusoidView

IMPLEMENT_DYNCREATE(CSinusoidView, CView)

BEGIN_MESSAGE_MAP(CSinusoidView, CView)
	//{{AFX_MSG_MAP(CSinusoidView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSinusoidView construction/destruction

CSinusoidView::CSinusoidView()
{
	// TODO: add construction code here

}

CSinusoidView::~CSinusoidView()
{
}

BOOL CSinusoidView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSinusoidView drawing

void CSinusoidView::OnDraw(CDC* pDC)
{
	CSinusoidDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	//建立画笔
	CPen cpen,pen;
	pen.CreatePen(PS_SOLID,4,RGB(0,0,0));
	cpen.CreatePen(PS_SOLID,2,RGB(0,0,255));
	pDC->SelectObject(&cpen);
	//指定原点
	pDC->SetViewportOrg(100,245);	
	pDC->SetTextColor(RGB(255,0,0));
	//绘制横坐标
	CString sPIText[]={"-1/2π","","1/2π","π","3/2π","2π","5/2π","3π","7/2π","4π","9/2π","5π"};
	for(int n=-1,nTmp=0;nTmp<=660;n++,nTmp+=60)
	{
		pDC->LineTo(60*n,0);
		pDC->LineTo(60*n,-5);
		pDC->MoveTo(60*n,0);
		pDC->TextOut(60*n-sPIText[n+1].GetLength()*3,16,sPIText[n+1]);
	}
	pDC->MoveTo(0,0);
	CString sTmp;
	//绘制纵坐标
	for(n=-4,nTmp=0;nTmp<=180;n++,nTmp=60*n)
	{
		pDC->LineTo(0,60*n);
		pDC->LineTo(5,60*n);
		pDC->MoveTo(0,60*n);
		sTmp.Format("%d",-n);
		pDC->TextOut(10,60*n,sTmp);
	}	
	double y,radian;	
	pDC->SelectObject(&pen);
	for(int x=-60;x<600;x++)
	{
		//弧度=X坐标/曲线宽度*角系数*π
		//Y坐标=振幅*曲线宽度*sin(弧度)
		radian =x/((double)60*2)*PI;
		y=sin(radian)*2*60;
		pDC->MoveTo((int)x,(int)y);
		pDC->LineTo((int)x,(int)y);
	}
	cpen.DeleteObject();
	pen.DeleteObject();
}

/////////////////////////////////////////////////////////////////////////////
// CSinusoidView printing

BOOL CSinusoidView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSinusoidView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSinusoidView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSinusoidView diagnostics

#ifdef _DEBUG
void CSinusoidView::AssertValid() const
{
	CView::AssertValid();
}

void CSinusoidView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSinusoidDoc* CSinusoidView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSinusoidDoc)));
	return (CSinusoidDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSinusoidView message handlers
