// OPENGLCubeView.cpp : implementation of the COPENGLCubeView class
//

#include "stdafx.h"
#include "OPENGLCube.h"

#include "OPENGLCubeDoc.h"
#include "OPENGLCubeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// COPENGLCubeView

static GLfloat p1[]={0.5,-0.5,-0.5};
static GLfloat p2[]={0.5,0.5,-0.5};
static GLfloat p3[]={0.5,0.5,0.5};
static GLfloat p4[]={0.5,-0.5,0.5};
static GLfloat p5[]={-0.5,-0.5,0.5};
static GLfloat p6[]={-0.5,0.5,0.5};
static GLfloat p7[]={-0.5,0.5,-0.5};
static GLfloat p8[]={-0.5,-0.5,-0.5};

static GLfloat m1[]={1.0,0.0,0.0};
static GLfloat m2[]={-1.0,0.0,0.0};
static GLfloat m3[]={0.0,1.0,0.0};
static GLfloat m4[]={0.0,-1.0,0.0};
static GLfloat m5[]={0.0,0.0,1.0};
static GLfloat m6[]={0.0,0.0,-1.0};

static GLfloat c1[]={0.0,0.0,1.0};
static GLfloat c2[]={0.0,1.0,1.0};
static GLfloat c3[]={1.0,1.0,1.0};
static GLfloat c4[]={1.0,0.0,1.0};
static GLfloat c5[]={1.0,0.0,0.0};
static GLfloat c6[]={1.0,1.0,0.0};
static GLfloat c7[]={0.0,1.0,0.0};
static GLfloat c8[]={1.0,1.0,1.0};
 
IMPLEMENT_DYNCREATE(COPENGLCubeView, CView)

BEGIN_MESSAGE_MAP(COPENGLCubeView, CView)
	//{{AFX_MSG_MAP(COPENGLCubeView)
	ON_WM_SIZE()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COPENGLCubeView construction/destruction

COPENGLCubeView::COPENGLCubeView()
{
	// TODO: add construction code here

}

COPENGLCubeView::~COPENGLCubeView()
{
}

BOOL COPENGLCubeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// COPENGLCubeView drawing

void COPENGLCubeView::OnDraw(CDC* pDC)
{
	COPENGLCubeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
/////////////////////////////////
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
	glPushMatrix();
	glRotatef(45,0.0,1.0,0.0);
	glRotatef(315,0.0,0.0,1.0);
///////////////////////////////////////////////
	GLfloat light_ambient[]={0.3,0.2,0.5};
  GLfloat light_diffuse[]={1.0,1.0,1.0};
  GLfloat light_position[] = { 2.0, 2.0, 2.0, 1.0 };
 
  GLfloat light1_ambient[]={0.3,0.3,0.2};
  GLfloat light1_diffuse[]={1.0,1.0,1.0};
  GLfloat light1_position[] = { -2.0, -2.0, -2.0, 1.0 };
 
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
 
  glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
  glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
 
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);
 
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
 
  glColorMaterial(GL_FRONT_AND_BACK,GL_DIFFUSE);
  glEnable(GL_COLOR_MATERIAL);
///////////////////////////////////////////	
 
	glFlush();
	glBegin (GL_QUADS);
	glColor3fv(c1);
	glNormal3fv(m1);
	glVertex3fv(p1);
	glColor3fv(c2);
	glVertex3fv(p2);
	glColor3fv(c3);
	glVertex3fv(p3);
	glColor3fv(c4);
	glVertex3fv(p4);
 
	glColor3fv(c5);
	glNormal3fv(m5);
	glVertex3fv(p5);
	glColor3fv(c6);
	glVertex3fv(p6);
	glColor3fv(c7);
	glVertex3fv(p7);
	glColor3fv(c8);
	glVertex3fv(p8);
 
	glColor3fv(c5);
	glNormal3fv(m3);
	glVertex3fv(p5);
	glColor3fv(c6);
	glVertex3fv(p6);
	glColor3fv(c3);
	glVertex3fv(p3);
	glColor3fv(c4);
	glVertex3fv(p4);
 
	glColor3fv(c1);
	glNormal3fv(m4);
	glVertex3fv(p1);
	glColor3fv(c2);
	glVertex3fv(p2);
	glColor3fv(c7);
	glVertex3fv(p7);
	glColor3fv(c8);
	glVertex3fv(p8);
 
	glColor3fv(c2);
	glNormal3fv(m5);
	glVertex3fv(p2);
	glColor3fv(c3);
	glVertex3fv(p3);
	glColor3fv(c6);
	glVertex3fv(p6);
	glColor3fv(c7);
	glVertex3fv(p7);
 
	glColor3fv(c1);
	glNormal3fv(m6);
	glVertex3fv(p1);
	glColor3fv(c4);
	glVertex3fv(p4);
	glColor3fv(c5);
	glVertex3fv(p5);
	glColor3fv(c8);
 
	glEnd();
	glPopMatrix();
	if(FALSE==::SwapBuffers(m_pContextDC->GetSafeHdc()))
		AfxMessageBox("½»»»»º³åÇøÊ§°Ü");
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// COPENGLCubeView printing

BOOL COPENGLCubeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COPENGLCubeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COPENGLCubeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// COPENGLCubeView diagnostics

#ifdef _DEBUG
void COPENGLCubeView::AssertValid() const
{
	CView::AssertValid();
}

void COPENGLCubeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COPENGLCubeDoc* COPENGLCubeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COPENGLCubeDoc)));
	return (COPENGLCubeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COPENGLCubeView message handlers

void COPENGLCubeView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	if ( 0 >= cx || 0 >= cy )
		{
		return;
		}
	CView::OnSize(nType,cx,cy);
	::glViewport(0,0,cx,cy);
	::glMatrixMode(GL_PROJECTION);
    ::glLoadIdentity();
	GLdouble dblaspect = (GLdouble)cx/(GLdouble)cy;
	::gluPerspective(40.0f,dblaspect,.1f, 20.0f);
	::glMatrixMode(GL_MODELVIEW);
    ::glLoadIdentity();
	::glTranslatef(0.0f,0.0f,-5.0f);
	::glRotatef(20.0f, 1.0f, 0.0f, 0.0f);
}


int COPENGLCubeView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_pContextDC=new CClientDC(this);
	ASSERT(m_pContextDC);
	static PIXELFORMATDESCRIPTOR pfd = 
	{
        sizeof(PIXELFORMATDESCRIPTOR),  // 
        1,                              // 
        PFD_DRAW_TO_WINDOW |            // 
          PFD_SUPPORT_OPENGL |          // 
          PFD_DOUBLEBUFFER,             //
        PFD_TYPE_RGBA,                  // 
        24,                             // 
        0, 0, 0, 0, 0, 0,               // 
        0,                              // 
        0,                              // 
        0,                              // 
        0, 0, 0, 0,                     // 

		16,	// 
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

BOOL COPENGLCubeView::DestroyWindow() 
{
	wglDeleteContext(m_hOpenglRC);
	delete m_pContextDC;
	return CView::DestroyWindow();
}
