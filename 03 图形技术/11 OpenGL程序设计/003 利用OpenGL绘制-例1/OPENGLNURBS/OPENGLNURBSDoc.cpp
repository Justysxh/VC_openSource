// OPENGLNURBSDoc.cpp : implementation of the COPENGLNURBSDoc class
//

#include "stdafx.h"
#include "OPENGLNURBS.h"

#include "OPENGLNURBSDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COPENGLNURBSDoc

IMPLEMENT_DYNCREATE(COPENGLNURBSDoc, CDocument)

BEGIN_MESSAGE_MAP(COPENGLNURBSDoc, CDocument)
	//{{AFX_MSG_MAP(COPENGLNURBSDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COPENGLNURBSDoc construction/destruction

COPENGLNURBSDoc::COPENGLNURBSDoc()
{
	// TODO: add one-time construction code here

}

COPENGLNURBSDoc::~COPENGLNURBSDoc()
{
}

BOOL COPENGLNURBSDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COPENGLNURBSDoc serialization

void COPENGLNURBSDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// COPENGLNURBSDoc diagnostics

#ifdef _DEBUG
void COPENGLNURBSDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COPENGLNURBSDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COPENGLNURBSDoc commands
