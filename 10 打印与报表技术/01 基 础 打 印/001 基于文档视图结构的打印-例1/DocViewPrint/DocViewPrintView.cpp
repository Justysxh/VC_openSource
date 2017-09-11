// DocViewPrintView.cpp : implementation of the CDocViewPrintView class
//

#include "stdafx.h"
#include "DocViewPrint.h"

#include "DocViewPrintDoc.h"
#include "DocViewPrintView.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDocViewPrintView

IMPLEMENT_DYNCREATE(CDocViewPrintView, CView)

BEGIN_MESSAGE_MAP(CDocViewPrintView, CView)
	//{{AFX_MSG_MAP(CDocViewPrintView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDocViewPrintView construction/destruction

CDocViewPrintView::CDocViewPrintView()
{
	isPreview = FALSE;	// TODO: add construction code here

}

CDocViewPrintView::~CDocViewPrintView()
{
}

BOOL CDocViewPrintView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	
	//m_titlefont.CreateFont(-24,-16,0,0,600,0,0,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,FF_SCRIPT ,"宋体");
	//  the CREATESTRUCT cs
//	m_bodyfont.CreateFont(-12,-10,0,0,600,0,0,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,FF_SCRIPT ,"宋体");
	
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDocViewPrintView drawing

void CDocViewPrintView::OnDraw(CDC* pDC)
{
	
	m_titlefont.CreatePointFont(200,"宋体",pDC);

	m_bodyfont.CreatePointFont(100,"宋体",pDC);

	screenx =pDC->GetDeviceCaps(LOGPIXELSX);
	screeny =pDC->GetDeviceCaps(LOGPIXELSY);
	
	CDocViewPrintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	pDC->SelectObject(&m_titlefont);
	CRect m_rect;

	this->GetClientRect(m_rect);
	m_rect.DeflateRect(0,20,0,0);

	//绘制标题
	pDC->DrawText("学生成绩单",m_rect,DT_CENTER);

	//绘制报表数据

	CMainDlg* pmaindlg = ((CDocViewPrintApp*)(AfxGetApp()))->tempdlg;


	pDC->SelectObject(&m_bodyfont);

	char* pchar = new char[100];
	LVCOLUMN column;
	column.mask = LVCF_TEXT;
	column.pszText = pchar;
	column.cchTextMax = 100;


	CString str;

	CRect m_temprect (m_rect.left+60,m_rect.top+60,60+(m_rect.Width())/6,m_rect.bottom);
	
	CRect m_itemrect;

	m_rect.DeflateRect(60,40);


	int width = m_temprect.Width();
	for (int i = 0;i< 6;i++)
	{

		if (pmaindlg->m_list.GetColumn(i,&column))
			str =  column.pszText;

		pDC->DrawText(str,m_temprect,DT_LEFT);

		m_itemrect.CopyRect(m_temprect);

		for (int row = 0;row <10;row++)
		{
			m_itemrect.DeflateRect(0,30);
			str = pmaindlg->m_list.GetItemText(row,i);

			pDC->DrawText(str,m_itemrect,DT_LEFT);
		
		}

		m_temprect.DeflateRect(width,0,0,0);

		m_temprect.InflateRect(0,0,width,0);

	}
	delete []pchar;
	m_titlefont.DeleteObject();
	m_bodyfont.DeleteObject();
}

/////////////////////////////////////////////////////////////////////////////
// CDocViewPrintView printing

BOOL CDocViewPrintView::OnPreparePrinting(CPrintInfo* pInfo)
{

	//pInfo->
	return DoPreparePrinting(pInfo);
}

void CDocViewPrintView::OnBeginPrinting(CDC* pDC, CPrintInfo* /*pInfo*/)
{

	printx =pDC->GetDeviceCaps(LOGPIXELSX);
	printy =pDC->GetDeviceCaps(LOGPIXELSY);	

	xrate = (double)printx /screenx; //确定打印机与屏幕的比率
	yrate = (double)printy /screeny;

	pageheight =pDC->GetDeviceCaps(VERTRES);
	pagewidth =pDC->GetDeviceCaps(HORZRES);
	//获取打印机的左右边距
	
	leftmargin = pDC->GetDeviceCaps(PHYSICALOFFSETX);//获取左边距
	
	int phywidth= pDC->GetDeviceCaps(PHYSICALWIDTH);

	rightmargin = phywidth-pagewidth-leftmargin;
}

void CDocViewPrintView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	
}

/////////////////////////////////////////////////////////////////////////////
// CDocViewPrintView diagnostics

#ifdef _DEBUG
void CDocViewPrintView::AssertValid() const
{
	CView::AssertValid();
}

void CDocViewPrintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDocViewPrintDoc* CDocViewPrintView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDocViewPrintDoc)));
	return (CDocViewPrintDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDocViewPrintView message handlers

void CDocViewPrintView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	isPreview = TRUE;
	m_titlefont.CreatePointFont((int)xrate*200,"宋体",pDC);

	m_bodyfont.CreatePointFont((int)xrate*100,"宋体",pDC);

	pDC->SelectObject(&m_titlefont);

	CRect m_rect(-leftmargin,0,pagewidth+rightmargin,pageheight);

	m_rect.DeflateRect(0,(int)20*yrate,0,0);

	//绘制标题
	pDC->DrawText("学生成绩单",m_rect,DT_CENTER|DT_SINGLELINE);

	//绘制报表数据
	CMainDlg* pmaindlg = ((CDocViewPrintApp*)(AfxGetApp()))->tempdlg;

	m_rect.DeflateRect(0,(int)20*yrate,0,0);
	pDC->SelectObject(&m_bodyfont);

	char* pchar = new char[100];
	LVCOLUMN column;
	column.mask = LVCF_TEXT;
	column.pszText = pchar;
	column.cchTextMax = 100;

	CString str;
	CRect m_temprect ((int)(xrate*60),m_rect.top+(int)(xrate*60),(int)(xrate*60)+(m_rect.Width()-(int)(xrate*60)*2)/6,m_rect.bottom);
	CRect m_itemrect;

	int width = m_temprect.Width();
	for (int i = 0;i< 6;i++)
	{

		if (pmaindlg->m_list.GetColumn(i,&column))
			str =  column.pszText;

		pDC->DrawText(str,m_temprect,DT_LEFT);

		m_itemrect.CopyRect(m_temprect);

		for (int row = 0;row <10;row++)
		{
			m_itemrect.DeflateRect(0,(int)(xrate*30));
			str = pmaindlg->m_list.GetItemText(row,i);

			pDC->DrawText(str,m_itemrect,DT_LEFT);
		
		}

		m_temprect.DeflateRect(width+1,0,0,0);

		m_temprect.InflateRect(0,0,width+1,0);

	}
	m_titlefont.DeleteObject();
	m_bodyfont.DeleteObject();	
	delete []pchar;
//	CView::OnPrint(pDC, pInfo);
}

void CDocViewPrintView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	CView::OnPrepareDC(pDC, pInfo);	
}

void CDocViewPrintView::OnEndPrintPreview(CDC* pDC, CPrintInfo* pInfo, POINT point, CPreviewView* pView) 
{
	isPreview = FALSE;
	CView::OnEndPrintPreview(pDC, pInfo, point, pView);
}
