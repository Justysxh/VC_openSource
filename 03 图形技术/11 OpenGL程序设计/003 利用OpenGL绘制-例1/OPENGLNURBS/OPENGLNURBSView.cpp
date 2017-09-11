// OPENGLNURBSView.cpp : implementation of the COPENGLNURBSView class
//

#include "stdafx.h"
#include "OPENGLNURBS.h"

#include "OPENGLNURBSDoc.h"
#include "OPENGLNURBSView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COPENGLNURBSView

IMPLEMENT_DYNCREATE(COPENGLNURBSView, CView)

BEGIN_MESSAGE_MAP(COPENGLNURBSView, CView)
	//{{AFX_MSG_MAP(COPENGLNURBSView)
	ON_WM_SIZE()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COPENGLNURBSView construction/destruction

COPENGLNURBSView::COPENGLNURBSView()
{
	// TODO: add construction code here

}

COPENGLNURBSView::~COPENGLNURBSView()
{
}

BOOL COPENGLNURBSView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// COPENGLNURBSView drawing

void COPENGLNURBSView::OnDraw(CDC* pDC)
{
	COPENGLNURBSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	GLfloat diffuse[]={0.88,0.66,0.22,1.0};
	GLfloat specular[]={0.92,0.9,0.0,1.0};
	GLfloat shininess[]={80.0};
 
	glClearColor(0.0,0.0,0.0,1.0);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,shininess); 

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
 
	int u, v;
	for (u=0;u<4;u++)
	{
		for(v=0;v<4;v++)
		{
			point[u][v][0]=2.0*((GLfloat)u-1.5);
			point[u][v][1]=2.0*((GLfloat)v-1.5);
 
			if((u==1||u==2)&&(v==1||v==2))
			point[u][v][2]=3.0;
			else
			point[u][v][2]=-3.0;
		}
	}
 
	nurb=gluNewNurbsRenderer();
	gluNurbsProperty(nurb,GLU_SAMPLING_TOLERANCE,25.0);
	gluNurbsProperty(nurb,GLU_DISPLAY_MODE,GLU_FILL);

	GLfloat knots[8]={0.0,0.0,0.0,0.0,1.0,1.0,1.0,1.0};
 
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 
	glPushMatrix();
	glRotatef(330.0,1.0,0.0,0.0);
	glScalef(0.5,0.5,0.5);
 
	gluBeginSurface(nurb);
	gluNurbsSurface(nurb,
    8,
    knots,
    8,
    knots,
    4*3,
    3,
    &point[0][0][0],
    4,4,
    GL_MAP2_VERTEX_3);
	gluEndSurface(nurb);
 
	glPopMatrix();
	glFlush();

	if(FALSE==::SwapBuffers(m_pContextDC->GetSafeHdc()))
		AfxMessageBox("½»»»»º³åÇøÊ§°Ü");
}

/////////////////////////////////////////////////////////////////////////////
// COPENGLNURBSView printing

BOOL COPENGLNURBSView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COPENGLNURBSView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COPENGLNURBSView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// COPENGLNURBSView diagnostics

#ifdef _DEBUG
void COPENGLNURBSView::AssertValid() const
{
	CView::AssertValid();
}

void COPENGLNURBSView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COPENGLNURBSDoc* COPENGLNURBSView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COPENGLNURBSDoc)));
	return (COPENGLNURBSDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COPENGLNURBSView message handlers

void COPENGLNURBSView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType,cx,cy);
	if(0>=cx||0>=cy)
	{
		return;
	}
	::glViewport(0,0,cx,cy);
	::glMatrixMode(GL_PROJECTION);
    ::glLoadIdentity();
	GLdouble dblaspect=(GLdouble)cx/(GLdouble)cy;
	::gluPerspective(45.0f,dblaspect,3.0f, 8.0f);
	::glMatrixMode(GL_MODELVIEW);
    ::glLoadIdentity();
	::glTranslatef(0.0f,1.0f,-5.0f);

}


int COPENGLNURBSView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_pContextDC=new CClientDC(this);
	ASSERT(m_pContextDC);
	static PIXELFORMATDESCRIPTOR pfd = 
	{
        sizeof(PIXELFORMATDESCRIPTOR),  // 
        1,                              // 
        PFD_DRAW_TO_WINDOW|             // 
        PFD_SUPPORT_OPENGL|             // 
        PFD_DOUBLEBUFFER,               //
        PFD_TYPE_RGBA,                  // 
        24,                             // 
        0, 0, 0, 0, 0, 0,               // 
        0,                              // 
        0,                              // 
        0,                              // 
        0, 0, 0, 0,                     // 
		16,	                            // 
        0,                              // 
        0,                              // 
        PFD_MAIN_PLANE,                 // 
        0,                              // 
        0, 0, 0                         // 
    };
	int pixelformat=::ChoosePixelFormat(m_pContextDC->GetSafeHdc(),&pfd);
	if(pixelformat==0)
	{
		AfxMessageBox("³õÊ¼»¯Ê§°Ü");
		return -1;
	}
	SetPixelFormat(m_pContextDC->GetSafeHdc(),pixelformat,&pfd);
	m_hOpenglRC=wglCreateContext(m_pContextDC->GetSafeHdc());
	wglMakeCurrent(m_pContextDC->GetSafeHdc(),m_hOpenglRC);
	return 0;
}

BOOL COPENGLNURBSView::DestroyWindow() 
{
	wglDeleteContext(m_hOpenglRC);
	delete m_pContextDC;
	return CView::DestroyWindow();
}
