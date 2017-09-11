// FilmMoveViewView.cpp : implementation of the CFilmMoveViewView class
//

#include "stdafx.h"
#include "FilmMoveView.h"

#include "FilmMoveViewDoc.h"
#include "FilmMoveViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFilmMoveViewView

IMPLEMENT_DYNCREATE(CFilmMoveViewView, CView)

BEGIN_MESSAGE_MAP(CFilmMoveViewView, CView)
	//{{AFX_MSG_MAP(CFilmMoveViewView)
	ON_COMMAND(ID_VIEW, OnView)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFilmMoveViewView construction/destruction

CFilmMoveViewView::CFilmMoveViewView()
{
	// TODO: add construction code here
	m_hDrawDib=NULL;
	m_hDrawDib=DrawDibOpen();
	HBITMAP hBmp=(HBITMAP)LoadImage(NULL,"bitmap.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	HDC hMemDC=CreateCompatibleDC(NULL);
	if(hMemDC)
	{
		GetObject(hBmp,sizeof(bm),&bm);
		m_size=CSize(bm.bmWidth,bm.bmHeight);
		BITMAPINFOHEADER RGB32BITSBITMAPINFO=
		{sizeof(BITMAPINFOHEADER),bm.bmWidth,bm.bmHeight,
		1,32,BI_RGB,0,0,0,0};
		m_bmpSrc=CreateDIBSection(hMemDC,(BITMAPINFO*)&RGB32BITSBITMAPINFO,
			DIB_RGB_COLORS,(VOID**)&m_clrSrc,NULL,0);
		if(m_bmpSrc)
		{
			HBITMAP hOldBmp=(HBITMAP)SelectObject(hMemDC,m_bmpSrc);
			HDC hDC=CreateCompatibleDC(hMemDC);
			if(hDC)
			{
				HBITMAP hOldBmp2=(HBITMAP)SelectObject(hDC,hBmp);
				BitBlt(hMemDC,0,0,bm.bmWidth,bm.bmHeight,hDC,
					0,0,SRCCOPY);
				SelectObject(hDC,hOldBmp2);
				DeleteDC(hDC);
			}
			SelectObject(hMemDC,hOldBmp);
		}
		DeleteDC(hMemDC);
	}
}

CFilmMoveViewView::~CFilmMoveViewView()
{
		if(m_hDrawDib!=NULL)
	{
		DrawDibClose(m_hDrawDib);
		m_hDrawDib=NULL;
	}
	if(m_bmpSrc!=NULL)
		DeleteObject(m_bmpSrc);
}

BOOL CFilmMoveViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFilmMoveViewView drawing

void CFilmMoveViewView::OnDraw(CDC* pDC)
{
	CFilmMoveViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CFilmMoveViewView printing

BOOL CFilmMoveViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFilmMoveViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFilmMoveViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFilmMoveViewView diagnostics

#ifdef _DEBUG
void CFilmMoveViewView::AssertValid() const
{
	CView::AssertValid();
}

void CFilmMoveViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFilmMoveViewDoc* CFilmMoveViewView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFilmMoveViewDoc)));
	return (CFilmMoveViewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFilmMoveViewView message handlers

void CFilmMoveViewView::OnView() 
{
	// TODO: Add your command handler code here
	if(m_bmpSrc==NULL||m_hDrawDib==NULL)return;
	Invalidate();
	BOOL bDone=false;
	int i=0;
	BITMAPINFOHEADER RGB32BITSBITMAPINFO=
	{sizeof(BITMAPINFOHEADER),m_size.cx,m_size.cy,1,32,BI_RGB,0,0,0,0,0};
	CPaintDC dc(this);
	while(!bDone)
	{
		if(i>m_size.cx)
		{
			i=m_size.cx;
			bDone=true;
		}
		DrawDibRealize(m_hDrawDib,dc.GetSafeHdc(),true);
		DrawDibDraw(m_hDrawDib,dc.GetSafeHdc(),10+m_size.cx-i,10,i,
			m_size.cy,&RGB32BITSBITMAPINFO,(LPVOID)m_clrSrc,
			0,0,i,m_size.cy,DDF_BACKGROUNDPAL);
		i+=10;
		Sleep(50);
	}
}
