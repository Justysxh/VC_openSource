// OPENGLCubeDoc.cpp : implementation of the COPENGLCubeDoc class
//

#include "stdafx.h"
#include "OPENGLCube.h"

#include "OPENGLCubeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COPENGLCubeDoc

IMPLEMENT_DYNCREATE(COPENGLCubeDoc, CDocument)

BEGIN_MESSAGE_MAP(COPENGLCubeDoc, CDocument)
	//{{AFX_MSG_MAP(COPENGLCubeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COPENGLCubeDoc construction/destruction

COPENGLCubeDoc::COPENGLCubeDoc()
{
	// TODO: add one-time construction code here

}

COPENGLCubeDoc::~COPENGLCubeDoc()
{
}

BOOL COPENGLCubeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COPENGLCubeDoc serialization

void COPENGLCubeDoc::Serialize(CArchive& ar)
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
// COPENGLCubeDoc diagnostics

#ifdef _DEBUG
void COPENGLCubeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COPENGLCubeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COPENGLCubeDoc commands
