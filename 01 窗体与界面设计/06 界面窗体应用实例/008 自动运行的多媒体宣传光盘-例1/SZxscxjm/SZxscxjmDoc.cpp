// SZxscxjmDoc.cpp : implementation of the CSZxscxjmDoc class
//

#include "stdafx.h"
#include "SZxscxjm.h"

#include "SZxscxjmDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSZxscxjmDoc

IMPLEMENT_DYNCREATE(CSZxscxjmDoc, CDocument)

BEGIN_MESSAGE_MAP(CSZxscxjmDoc, CDocument)
	//{{AFX_MSG_MAP(CSZxscxjmDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSZxscxjmDoc construction/destruction

CSZxscxjmDoc::CSZxscxjmDoc()
{
	// TODO: add one-time construction code here

}

CSZxscxjmDoc::~CSZxscxjmDoc()
{
}

BOOL CSZxscxjmDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSZxscxjmDoc serialization

void CSZxscxjmDoc::Serialize(CArchive& ar)
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
// CSZxscxjmDoc diagnostics

#ifdef _DEBUG
void CSZxscxjmDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSZxscxjmDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSZxscxjmDoc commands
