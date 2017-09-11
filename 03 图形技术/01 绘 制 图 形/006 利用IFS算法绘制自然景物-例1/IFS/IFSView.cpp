// IFSView.cpp : implementation of the CIFSView class
//

#include "stdafx.h"
#include "IFS.h"

#include "IFSDoc.h"
#include "IFSView.h"
#include "math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define  MaxY  400
/////////////////////////////////////////////////////////////////////////////
// CIFSView

IMPLEMENT_DYNCREATE(CIFSView, CView)

BEGIN_MESSAGE_MAP(CIFSView, CView)
	//{{AFX_MSG_MAP(CIFSView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIFSView construction/destruction

CIFSView::CIFSView()
{
	// TODO: add construction code here
	m_pColor=RGB(0,255,0);
	m_N=4;
	stepx=3;
	stepy=3;
	totalsteps=32000;
}

CIFSView::~CIFSView()
{
}

BOOL CIFSView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CIFSView drawing

void CIFSView::OnDraw(CDC* pDC)
{
	CIFSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	for(i=1;i<m_N;i++)
	{
		p[i]=p[i]+p[i-1];
	}
	float xj,m;
	x=0;y=0;
	srand(unsigned(time(NULL)));
	for(i=0;i<totalsteps;i++)
	{	 
		m=float(rand());
	
		xj=float(m/RAND_MAX);
		if(xj<=p[0]) k=0;
		if((xj>p[0])&&(xj<=p[1])) k=1;
		if((xj>p[1])&&(xj<=p[2])) k=2;
		if((xj>p[2])&&(xj<=p[3])) k=3;
		if((xj>p[3])&&(xj<=p[4]))k=4;
		if((xj>p[4])&&(xj<=p[5])) k=5;
		if((xj>p[5])&&(xj<=p[6]))k=6;
		if((xj>p[6]) &&(xj<=p[7]))k=7; 

		x=a[k]*x+b[k]*y+e[k];
		y=c[k]*x+d[k]*y+f[k];
		if(i>10)
		pDC->SetPixel(int(MaxY*x/stepx+MaxY/2 ) , 
			MaxY-int(MaxY*y/stepy+30)-100 ,m_pColor);
	}
	
}

/////////////////////////////////////////////////////////////////////////////
// CIFSView printing

BOOL CIFSView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CIFSView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CIFSView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CIFSView diagnostics

#ifdef _DEBUG
void CIFSView::AssertValid() const
{
	CView::AssertValid();
}

void CIFSView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIFSDoc* CIFSView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIFSDoc)));
	return (CIFSDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CIFSView message handlers

void CIFSView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	CIFSDoc *pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	/*三叶草 xstep和ystep的值为15
	a[0]=0.0;a[1]=0.85;a[2]=0.2;a[3]=-0.15;
	b[0]=0;b[1]=0.04;b[2]=-0.26;b[3]=0.28;
	c[0]=0;c[1]=-0.04;c[2]=0.23;c[3]=0.26;
	d[0]=0.16;d[1]=0.85;d[2]=0.22;d[3]=0.24;
	e[0]=0;e[1]=0;e[2]=0;e[3]=0;
	f[0]=0;f[1]=1.6;f[2]=1.6;f[3]=0.44;
	p[0]=0.01;p[1]=0.85;p[2]=0.07;p[3]=0.07;
	*/
	/*山*************************************/
	a[0]=0.7;a[1]=0.5;a[2]=-0.4;a[3]=-0.5;
	b[0]=0.0;b[1]=0;b[2]=0;b[3]=0;
	c[0]=0;c[1]=0;c[2]=1;c[3]=0;
	d[0]=0.8;d[1]=0.5;d[2]=0.4;d[3]=0.5;
	e[0]=0;e[1]=2;e[2]=0;e[3]=2;
	f[0]=0;f[1]=0;f[2]=1;f[3]=1;
	p[0]=0.25;p[1]=0.25;p[2]=0.25;p[3]=0.25;
	/****************************************/
	/*皇冠*
	a[0]=0.25;a[1]=0.5;a[2]=-0.25;a[3]=0.5;a[4]=0.5;
	b[0]=0;b[1]=0;b[2]=0;b[3]=0;b[4]=0;
	c[0]=0;c[1]=0;c[2]=0;c[3]=0;c[4]=0;
	d[0]=0.5;d[1]=0.5;d[2]=-0.25;d[3]=0.5;d[4]=-0.25;
	e[0]=0;e[1]=-0.25;e[2]=0.25;e[3]=0;e[4]=0.5;
	f[0]=0;f[1]=0.5;f[2]=0;f[3]=0.75;f[4]=1.25;
	p[0]=0.154;p[1]=0.461;p[2]=0.539;p[3]=0.846;p[4]=1;
	**/
	/*树**
	a[0]=0;a[1]=0.42;a[2]=0.42;a[3]=0.1;
	b[0]=0;b[1]=-0.42;b[2]=0.42;b[3]=0;
	c[0]=0;c[1]=-0.42;c[2]=-0.42;c[3]=0;
	d[0]=0.5;d[1]=0.42;d[2]=0.42;d[3]=0.1;
	e[0]=0;e[1]=0;e[2]=0;e[3]=0;
	f[0]=0;f[1]=0.2;f[2]=0.2;f[3]=0.2;
	p[0]=0.05;p[1]=0.45;p[2]=0.85;p[3]=1;
	***/
}
