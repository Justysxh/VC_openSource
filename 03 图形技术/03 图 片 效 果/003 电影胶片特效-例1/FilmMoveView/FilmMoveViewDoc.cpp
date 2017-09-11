// FilmMoveViewDoc.cpp : implementation of the CFilmMoveViewDoc class
//

#include "stdafx.h"
#include "FilmMoveView.h"

#include "FilmMoveViewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFilmMoveViewDoc

IMPLEMENT_DYNCREATE(CFilmMoveViewDoc, CDocument)

BEGIN_MESSAGE_MAP(CFilmMoveViewDoc, CDocument)
	//{{AFX_MSG_MAP(CFilmMoveViewDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFilmMoveViewDoc construction/destruction

CFilmMoveViewDoc::CFilmMoveViewDoc()
{
	// TODO: add one-time construction code here

}

CFilmMoveViewDoc::~CFilmMoveViewDoc()
{
}

BOOL CFilmMoveViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFilmMoveViewDoc serialization

void CFilmMoveViewDoc::Serialize(CArchive& ar)
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
// CFilmMoveViewDoc diagnostics

#ifdef _DEBUG
void CFilmMoveViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFilmMoveViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFilmMoveViewDoc commands
