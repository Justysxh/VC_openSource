// ShutterView.cpp : implementation of the CShutterView class
//

#include "stdafx.h"
#include "Shutter.h"

#include "ShutterDoc.h"
#include "ShutterView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
BITMAP bm;
/////////////////////////////////////////////////////////////////////////////
// CShutterView

IMPLEMENT_DYNCREATE(CShutterView, CView)

BEGIN_MESSAGE_MAP(CShutterView, CView)
	//{{AFX_MSG_MAP(CShutterView)
	ON_COMMAND(ID_VIEW, OnView)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShutterView construction/destruction

CShutterView::CShutterView()
{
	bstart=FALSE;
	m_hDrawDib=NULL;
	m_hDrawDib=DrawDibOpen();
	HBITMAP hBmp=(HBITMAP)LoadImage(NULL,"bitmap.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	HDC hMemDC=CreateCompatibleDC(NULL);
	if(hMemDC)
	{
		GetObject(hBmp,sizeof(bm),&bm);
		m_size=CSize(bm.bmWidth,bm.bmHeight);
		BITMAPINFOHEADER RGB32BITSBITMAPINFO=
		{sizeof(BITMAPINFOHEADER),bm.bmWidth,bm.bmHeight,1,32,BI_RGB,0,0,0,0,0};
		m_bmpSrc=CreateDIBSection(hMemDC,(BITMAPINFO*)&RGB32BITSBITMAPINFO,
			DIB_RGB_COLORS,(VOID**)&m_clrSrc,NULL,0);
		if(m_bmpSrc)
		{
			HBITMAP hOldBmp=(HBITMAP)SelectObject(hMemDC,m_bmpSrc);
			HDC hDC=CreateCompatibleDC(hMemDC);
			if(hDC)
			{
				HBITMAP hOldBmp2=(HBITMAP)SelectObject(hDC,hBmp);
				BitBlt(hMemDC,0,0,bm.bmWidth,bm.bmHeight,hDC,0,0,SRCCOPY);
				SelectObject(hDC,hOldBmp2);
				DeleteDC(hDC);
			}
			SelectObject(hMemDC,hOldBmp);
		}
		DeleteDC(hMemDC);
		
	}

}


CShutterView::~CShutterView()
{
	if(m_hDrawDib!=NULL)
	{
		DrawDibClose(m_hDrawDib);
		m_hDrawDib=NULL;
	}
	if(m_bmpSrc!=NULL)
	{
		DeleteObject(m_bmpSrc);
	}
}

BOOL CShutterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CShutterView drawing

void CShutterView::OnDraw(CDC* pDC)
{
	CShutterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(bstart)
	{
	if(m_bmpSrc==NULL||m_hDrawDib==NULL)return;
	Invalidate();
	
	BOOL bDone=FALSE;
	int i=0,j;
	BITMAPINFOHEADER REG32BITSBITMAPINFO=
		{sizeof(BITMAPINFOHEADER),bm.bmWidth,bm.bmHeight,1,32,BI_RGB,0,0,0,0,0};
	
	DrawDibRealize(m_hDrawDib,pDC->GetSafeHdc(),true);
	for(i=0;i<20;i++)
	{
		for(j=i;j<m_size.cy;j+=20)
			DrawDibDraw(m_hDrawDib,pDC->GetSafeHdc(),j,0,1,
			m_size.cy,&REG32BITSBITMAPINFO,(LPVOID)m_clrSrc,
			j,0,1,m_size.cy,DDF_BACKGROUNDPAL);
		Sleep(200);
	}
	bstart=FALSE;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CShutterView printing

BOOL CShutterView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CShutterView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CShutterView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CShutterView diagnostics

#ifdef _DEBUG
void CShutterView::AssertValid() const
{
	CView::AssertValid();
}

void CShutterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CShutterDoc* CShutterView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShutterDoc)));
	return (CShutterDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShutterView message handlers

void CShutterView::OnView() 
{
	bstart=TRUE;
	this->Invalidate();
}
