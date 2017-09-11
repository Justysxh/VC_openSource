// MosaicViewView.cpp : implementation of the CMosaicViewView class
//

#include "stdafx.h"
#include "MosaicView.h"

#include "MosaicViewDoc.h"
#include "MosaicViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMosaicViewView

IMPLEMENT_DYNCREATE(CMosaicViewView, CView)

BEGIN_MESSAGE_MAP(CMosaicViewView, CView)
	//{{AFX_MSG_MAP(CMosaicViewView)
	ON_COMMAND(ID_VIEW, OnView)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMosaicViewView construction/destruction

CMosaicViewView::CMosaicViewView()
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

CMosaicViewView::~CMosaicViewView()
{
	if(m_hDrawDib!=NULL)
	{
		DrawDibClose(m_hDrawDib);
		m_hDrawDib=NULL;
	}
	if(m_bmpSrc!=NULL)
		DeleteObject(m_bmpSrc);
}

BOOL CMosaicViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMosaicViewView drawing

void CMosaicViewView::OnDraw(CDC* pDC)
{
	CMosaicViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMosaicViewView printing

BOOL CMosaicViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMosaicViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMosaicViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMosaicViewView diagnostics

#ifdef _DEBUG
void CMosaicViewView::AssertValid() const
{
	CView::AssertValid();
}

void CMosaicViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMosaicViewDoc* CMosaicViewView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMosaicViewDoc)));
	return (CMosaicViewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMosaicViewView message handlers

void CMosaicViewView::OnView() 
{
	// TODO: Add your command handler code here
	if(m_bmpSrc==NULL||m_hDrawDib==NULL)return;
	Invalidate();
	int nTileSize=10;
	int nTileNum=((m_size.cx+nTileSize-1)/nTileSize)*((m_size.cy+nTileSize-1)/nTileSize);
	POINT *pt=new POINT[nTileNum];
	int x=0;
	int y=0;
	int i;
	for(i=0;i<nTileNum;i++)
	{
		pt[i].x=x;
		pt[i].y=y;
		x=x+nTileSize;
		if(x>m_size.cx)
		{
			x=0;
			y=y+nTileSize;
		}
	}
	BITMAPINFOHEADER RGB32BITSBITMAPINFO=
	{sizeof(BITMAPINFOHEADER),m_size.cx,m_size.cy,
	1,32,BI_RGB,0,0,0,0,0};
	CPaintDC dc(this);
	DrawDibRealize(m_hDrawDib,dc.GetSafeHdc(),TRUE);
	double fMax=RAND_MAX;
	for(i=nTileNum-1;i>=0;i--)
	{
		int n=(int)((double)nTileNum*rand()/fMax);
		x=pt[n].x;
		y=pt[n].y;
		DrawDibDraw(m_hDrawDib,dc.GetSafeHdc(),10+x,10+y,nTileSize,nTileSize,
			&RGB32BITSBITMAPINFO,(LPVOID)m_clrSrc,
			x,y,nTileSize,nTileSize,DDF_BACKGROUNDPAL);
		pt[n].x=pt[i].x;
		pt[n].y=pt[i].y	;
		Sleep(20);
}
	delete[] pt;
	DrawDibDraw(m_hDrawDib,dc.GetSafeHdc(),10,10,m_size.cx,m_size.cy,
		&RGB32BITSBITMAPINFO,(LPVOID)m_clrSrc,
		0,0,m_size.cx,m_size.cy,DDF_BACKGROUNDPAL);
}
