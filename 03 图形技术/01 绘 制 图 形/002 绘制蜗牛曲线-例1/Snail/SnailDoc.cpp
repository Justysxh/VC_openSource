// SnailDoc.cpp : implementation of the CSnailDoc class
//

#include "stdafx.h"
#include "Snail.h"

#include "SnailDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSnailDoc

IMPLEMENT_DYNCREATE(CSnailDoc, CDocument)

BEGIN_MESSAGE_MAP(CSnailDoc, CDocument)
	//{{AFX_MSG_MAP(CSnailDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnailDoc construction/destruction

CSnailDoc::CSnailDoc()
{
	// TODO: add one-time construction code here

}

CSnailDoc::~CSnailDoc()
{
}

BOOL CSnailDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSnailDoc serialization

void CSnailDoc::Serialize(CArchive& ar)
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
// CSnailDoc diagnostics

#ifdef _DEBUG
void CSnailDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSnailDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSnailDoc commands
