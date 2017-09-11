// SZxscxjmView.cpp : implementation of the CSZxscxjmView class
//

#include "stdafx.h"
#include "SZxscxjm.h"

#include "SZxscxjmDoc.h"
#include "SZxscxjmView.h"

#include <cmath>
#define pi 2.0*asin(1.0)

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSZxscxjmView

IMPLEMENT_DYNCREATE(CSZxscxjmView, CView)

BEGIN_MESSAGE_MAP(CSZxscxjmView, CView)
	//{{AFX_MSG_MAP(CSZxscxjmView)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSZxscxjmView construction/destruction

CSZxscxjmView::CSZxscxjmView()
{
	// TODO: add construction code here
	
}

CSZxscxjmView::~CSZxscxjmView()
{
}

BOOL CSZxscxjmView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSZxscxjmView drawing

void CSZxscxjmView::OnDraw(CDC* pDC)
{
	CSZxscxjmDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	time = CTime::GetCurrentTime();
	if(hour>12)
	{
		hour=hour-12;
	}
	sec = time.GetSecond();
	min = time.GetMinute();
	hour = time.GetHour();
	CDC dc;
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP1);	//IDB_BITMAP1是待显示位图的资源ID
	BITMAP bm;
	bmp.GetBitmap(&bm);
	int nWidth = bm.bmWidth;
	int nHeight = bm.bmHeight;
	dc.CreateCompatibleDC(pDC);
	dc.SelectObject(&bmp);
	pDC->BitBlt(18, 0, nWidth, nHeight, &dc, 0, 0, SRCCOPY);
	SetTimer(1,1,NULL);
}

/////////////////////////////////////////////////////////////////////////////
// CSZxscxjmView printing

BOOL CSZxscxjmView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSZxscxjmView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSZxscxjmView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSZxscxjmView diagnostics

#ifdef _DEBUG
void CSZxscxjmView::AssertValid() const
{
	CView::AssertValid();
}

void CSZxscxjmView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSZxscxjmDoc* CSZxscxjmView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSZxscxjmDoc)));
	return (CSZxscxjmDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSZxscxjmView message handlers

void CSZxscxjmView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	KillTimer(1);
	CDC *pDC=this->GetDC();
	CRect m_rect;
	this->GetClientRect(m_rect);	
	CRgn rgn;
	HRGN m_hrgn;
	m_hrgn = ::CreateEllipticRgn(64,40,186,165);
	rgn.Attach(m_hrgn);	
	CBrush m_brush (1,RGB(255,255,255));
	pDC->SelectClipRgn(&rgn,0);
	pDC->FillRgn(&rgn,&m_brush);
	int x=120;
    int y=100;
	CPen pen;					//声明画笔
	pen.CreatePen(PS_SOLID,1,RGB(255,0,0));//创建实线画笔
	pDC->SelectObject(&pen);		//将画笔选入设备上下文
	pDC->MoveTo (x,y);
    pDC->LineTo (x+(long)55*cos(pi/2-2*pi*sec/60.0),y-(long)55*sin(pi/2-2*pi*sec/60.0));
	CPen pen1;					//声明画笔
	pen1.CreatePen(PS_SOLID,2,RGB(0,0,0));//创建实线画笔
	pDC->SelectObject(&pen1);		//将画笔选入设备上下文
	pDC->MoveTo (x,y);
    pDC->LineTo (x+(long)45*cos(pi/2-2*pi*min/60.0),y-(long)45*sin(pi/2-2*pi*min/60.0));
	pDC->MoveTo (x,y);
    pDC->LineTo (x+(long)35*cos(pi/2-5*2*pi*hour/60.0),y-(long)35*sin(pi/2-5*2*pi*hour/60.0));
	sec = sec+1;
	if(sec==60)
	{
		sec=0;
		min=min+1;
		if(min==60)
		{
			min=0;
			hour=hour+1;
		}
	}
	SetTimer(1,1000,NULL);
	CView::OnTimer(nIDEvent);
	pen.DeleteObject();
	pen1.DeleteObject();
}


