// OPENGLActDoc.cpp : implementation of the COPENGLActDoc class
//

#include "stdafx.h"
#include "OPENGLAct.h"

#include "OPENGLActDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COPENGLActDoc

IMPLEMENT_DYNCREATE(COPENGLActDoc, CDocument)

BEGIN_MESSAGE_MAP(COPENGLActDoc, CDocument)
	//{{AFX_MSG_MAP(COPENGLActDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COPENGLActDoc construction/destruction

COPENGLActDoc::COPENGLActDoc()
{
	// TODO: add one-time construction code here

}

COPENGLActDoc::~COPENGLActDoc()
{
}

BOOL COPENGLActDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COPENGLActDoc serialization

void COPENGLActDoc::Serialize(CArchive& ar)
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
// COPENGLActDoc diagnostics

#ifdef _DEBUG
void COPENGLActDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COPENGLActDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COPENGLActDoc commands
