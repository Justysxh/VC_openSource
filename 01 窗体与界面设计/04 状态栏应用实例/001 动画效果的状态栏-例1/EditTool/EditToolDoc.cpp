// EditToolDoc.cpp : implementation of the CEditToolDoc class
//

#include "stdafx.h"
#include "EditTool.h"

#include "EditToolDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditToolDoc

IMPLEMENT_DYNCREATE(CEditToolDoc, CDocument)

BEGIN_MESSAGE_MAP(CEditToolDoc, CDocument)
	//{{AFX_MSG_MAP(CEditToolDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditToolDoc construction/destruction

CEditToolDoc::CEditToolDoc()
{
	// TODO: add one-time construction code here

}

CEditToolDoc::~CEditToolDoc()
{
}

BOOL CEditToolDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEditToolDoc serialization

void CEditToolDoc::Serialize(CArchive& ar)
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
// CEditToolDoc diagnostics

#ifdef _DEBUG
void CEditToolDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEditToolDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEditToolDoc commands
