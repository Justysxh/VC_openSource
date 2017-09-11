// ToolIconDoc.cpp : implementation of the CToolIconDoc class
//

#include "stdafx.h"
#include "ToolIcon.h"

#include "ToolIconDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToolIconDoc

IMPLEMENT_DYNCREATE(CToolIconDoc, CDocument)

BEGIN_MESSAGE_MAP(CToolIconDoc, CDocument)
	//{{AFX_MSG_MAP(CToolIconDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToolIconDoc construction/destruction

CToolIconDoc::CToolIconDoc()
{
	// TODO: add one-time construction code here

}

CToolIconDoc::~CToolIconDoc()
{
}

BOOL CToolIconDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CToolIconDoc serialization

void CToolIconDoc::Serialize(CArchive& ar)
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
// CToolIconDoc diagnostics

#ifdef _DEBUG
void CToolIconDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CToolIconDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CToolIconDoc commands
