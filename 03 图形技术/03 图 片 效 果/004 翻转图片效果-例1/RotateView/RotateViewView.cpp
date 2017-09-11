// RotateViewView.cpp : implementation of the CRotateViewView class
//

#include "stdafx.h"
#include "RotateView.h"

#include "RotateViewDoc.h"
#include "RotateViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRotateViewView

IMPLEMENT_DYNCREATE(CRotateViewView, CView)

BEGIN_MESSAGE_MAP(CRotateViewView, CView)
	//{{AFX_MSG_MAP(CRotateViewView)
	ON_COMMAND(ID_VIEW, OnView)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRotateViewView construction/destruction

CRotateViewView::CRotateViewView()
{
	// TODO: add construction code here
	m_bmpSrc=NULL;
	m_bmpDst=NULL;
	m_nType=0;
	m_hDrawDib=DrawDibOpen();
	HBITMAP hBmp=(HBITMAP)LoadImage(NULL,"bitmap.bmp",IMAGE_BITMAP,0,0,
		LR_LOADFROMFILE);
	HDC hMemDC=CreateCompatibleDC(NULL);
	if(hMemDC)
	{
		GetObject(hBmp,sizeof(bm),&bm);
		m_sizeSrc=m_sizeDst=CSize(bm.bmWidth,bm.bmHeight);
		BITMAPINFOHEADER RGB32BITSBITMAPINFO=
		{sizeof(BITMAPINFOHEADER),bm.bmWidth,bm.bmHeight,1,32,
		BI_RGB,0,0,0,0,0};
		m_bmpSrc=CreateDIBSection(hMemDC,(BITMAPINFO*)&RGB32BITSBITMAPINFO,
			DIB_RGB_COLORS,(VOID**)&m_clrSrc,NULL,0);
		m_bmpDst=CreateDIBSection(hMemDC,(BITMAPINFO*)&RGB32BITSBITMAPINFO,
			DIB_RGB_COLORS,(VOID**)&m_clrDst,NULL,0);
		if(m_bmpSrc&&m_bmpDst)
		{
			HBITMAP hOldBmp=(HBITMAP)SelectObject(hMemDC,m_bmpSrc);
			HDC hDC=CreateCompatibleDC(hMemDC);
			if(hDC)
			{
				HBITMAP hOldBmp2=(HBITMAP)SelectObject(hDC,hBmp);
				BitBlt(hMemDC,0,0,bm.bmWidth,bm.bmHeight,hDC,0,0,
					SRCCOPY);
				SelectObject(hMemDC,m_bmpDst);
				BitBlt(hMemDC,0,0,bm.bmWidth,bm.bmHeight,hDC,0,0,
					SRCCOPY);
				SelectObject(hMemDC,hOldBmp2);
				DeleteObject(hDC);

			}
			SelectObject(hMemDC,hOldBmp);
		}
		DeleteObject(hMemDC);
		DeleteObject(hBmp);
	}
}

CRotateViewView::~CRotateViewView()
{
	if(m_hDrawDib!=NULL)
	{
		DrawDibClose(m_hDrawDib);
		m_hDrawDib=NULL;

	}
	if(m_bmpDst!=NULL)
	DeleteObject(m_bmpDst);
	if(m_bmpSrc!=NULL)
		DeleteObject(m_bmpSrc);
}

BOOL CRotateViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRotateViewView drawing

void CRotateViewView::OnDraw(CDC* pDC)
{
	CRotateViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(m_hDrawDib!=NULL&&m_bmpSrc!=NULL&&m_bmpDst!=NULL)
	{
		BITMAPINFOHEADER RGB32BITSBITMAPINFO=
		{sizeof(BITMAPINFOHEADER),m_sizeDst.cx,m_sizeDst.cy,
		1,32,BI_RGB,0,0,0,0,0};
		DrawDibRealize(m_hDrawDib,pDC->GetSafeHdc(),TRUE);
		DrawDibDraw(m_hDrawDib,pDC->GetSafeHdc(),0,0,m_sizeDst.cx,
			m_sizeDst.cy,&RGB32BITSBITMAPINFO,(LPVOID)m_clrDst,0,0,
			m_sizeDst.cx,m_sizeDst.cy,DDF_BACKGROUNDPAL);
	}
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CRotateViewView printing

BOOL CRotateViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRotateViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRotateViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRotateViewView diagnostics

#ifdef _DEBUG
void CRotateViewView::AssertValid() const
{
	CView::AssertValid();
}

void CRotateViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRotateViewDoc* CRotateViewView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRotateViewDoc)));
	return (CRotateViewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRotateViewView message handlers

void CRotateViewView::OnView() 
{
	// TODO: Add your command handler code here
	if(m_nType==1)return;
	if(m_bmpSrc!=NULL&&m_bmpDst!=NULL)
	{
		m_sizeDst.cx=m_sizeSrc.cy;
		m_sizeDst.cy=m_sizeSrc.cx;
		LONG x,y;
		for(y=0;y<m_sizeSrc.cy;y++)
		{
			for(x=0;x<m_sizeSrc.cx;x++)
			{
				m_clrDst[y+(m_sizeDst.cy-x-1)*m_sizeDst.cx]=
					m_clrSrc[x+y*m_sizeSrc.cx];
			}
		}
		m_nType=1;
		Invalidate();
	}
}
