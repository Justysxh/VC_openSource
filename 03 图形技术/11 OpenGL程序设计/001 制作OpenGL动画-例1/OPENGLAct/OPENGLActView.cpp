// OPENGLActView.cpp : implementation of the COPENGLActView class
//

#include "stdafx.h"
#include "OPENGLAct.h"

#include "OPENGLActDoc.h"
#include "OPENGLActView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
GLfloat sgenparams[] = {1.0, 1.0, 1.0, 0.0};
GLubyte stripeImage[3*64];
 
/////////////////////////////////////////////////////////////////////////////
// COPENGLActView

IMPLEMENT_DYNCREATE(COPENGLActView, CView)

BEGIN_MESSAGE_MAP(COPENGLActView, CView)
	//{{AFX_MSG_MAP(COPENGLActView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_COMMAND(ID_ACT, OnAct)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COPENGLActView construction/destruction

COPENGLActView::COPENGLActView()
{
	// TODO: add construction code here

}

COPENGLActView::~COPENGLActView()
{
}

BOOL COPENGLActView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// COPENGLActView drawing

void COPENGLActView::OnDraw(CDC* pDC)
{
	COPENGLActDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	static GLfloat  xangle = 10.0f;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix ();
	glTranslatef(0.0f, 0.0f, -8.5);
	glRotatef(xangle, 1.0f, 0.0f, 0.0f);
	xangle+= 10.0f;
	auxSolidTeapot(1.5);
	glPopMatrix ();
	glFlush();
	if(FALSE==::SwapBuffers(m_pContextDC->GetSafeHdc()))
		AfxMessageBox("½»»»»º³åÇøÊ§°Ü");

}

/////////////////////////////////////////////////////////////////////////////
// COPENGLActView printing

BOOL COPENGLActView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COPENGLActView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COPENGLActView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// COPENGLActView diagnostics

#ifdef _DEBUG
void COPENGLActView::AssertValid() const
{
	CView::AssertValid();
}

void COPENGLActView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COPENGLActDoc* COPENGLActView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COPENGLActDoc)));
	return (COPENGLActDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COPENGLActView message handlers

int COPENGLActView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
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

	glClearColor (0.0, 0.0, 0.0, 0.0);
 
	int j;
 
	for (j = 0; j < 64; j++)
	{
		stripeImage[3*j] = 255;
		stripeImage[3*j+1] =255-2*j;
		stripeImage[3*j+2] =255;
	}

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage1D(GL_TEXTURE_1D, 0, 3,64, 0, GL_RGB, GL_UNSIGNED_BYTE, stripeImage);
 
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_S, GL_OBJECT_PLANE, sgenparams);
 
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_1D);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glMaterialf (GL_FRONT, GL_SHININESS, 64.0);

	return 0;
}

BOOL COPENGLActView::DestroyWindow() 
{
	wglDeleteContext(m_hOpenglRC);
	delete m_pContextDC;
	return CView::DestroyWindow();
}

void COPENGLActView::OnSize(UINT nType, int cx, int cy) 
{


	if ( 0 >= cx || 0 >= cy )
		{
		return;
		}
	CView::OnSize(nType,cx,cy);
	::glViewport(0,0,cx,cy);
	::glMatrixMode(GL_PROJECTION);
    ::glLoadIdentity();
	GLdouble dblaspect = (GLdouble)cx/(GLdouble)cy;
	::gluPerspective(40.0f,dblaspect,0.1f, 20.0f);
	::glMatrixMode(GL_MODELVIEW);
    ::glLoadIdentity();
	::glTranslatef(0.0f,0.0f,-5.0f);
	::glRotatef(20.0f, 1.0f, 0.0f, 0.0f);

}


void COPENGLActView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	this->OnDraw(this->GetDC());
	CView::OnTimer(nIDEvent);
}

void COPENGLActView::OnAct() 
{
	SetTimer(1,15,NULL);
}
