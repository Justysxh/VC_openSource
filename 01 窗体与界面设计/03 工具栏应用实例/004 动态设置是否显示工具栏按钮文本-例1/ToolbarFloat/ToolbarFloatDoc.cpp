// ToolbarFloatDoc.cpp : implementation of the CToolbarFloatDoc class
//

#include "stdafx.h"
#include "ToolbarFloat.h"

#include "ToolbarFloatDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToolbarFloatDoc

IMPLEMENT_DYNCREATE(CToolbarFloatDoc, CDocument)

BEGIN_MESSAGE_MAP(CToolbarFloatDoc, CDocument)
	//{{AFX_MSG_MAP(CToolbarFloatDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToolbarFloatDoc construction/destruction

CToolbarFloatDoc::CToolbarFloatDoc()
{
	// TODO: add one-time construction code here

}

CToolbarFloatDoc::~CToolbarFloatDoc()
{
}

BOOL CToolbarFloatDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CToolbarFloatDoc serialization

void CToolbarFloatDoc::Serialize(CArchive& ar)
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
// CToolbarFloatDoc diagnostics

#ifdef _DEBUG
void CToolbarFloatDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CToolbarFloatDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CToolbarFloatDoc commands
