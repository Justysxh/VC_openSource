// FloatMenuDoc.cpp : implementation of the CFloatMenuDoc class
//

#include "stdafx.h"
#include "FloatMenu.h"

#include "FloatMenuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFloatMenuDoc

IMPLEMENT_DYNCREATE(CFloatMenuDoc, CDocument)

BEGIN_MESSAGE_MAP(CFloatMenuDoc, CDocument)
	//{{AFX_MSG_MAP(CFloatMenuDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFloatMenuDoc construction/destruction

CFloatMenuDoc::CFloatMenuDoc()
{
	// TODO: add one-time construction code here

}

CFloatMenuDoc::~CFloatMenuDoc()
{
}

BOOL CFloatMenuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFloatMenuDoc serialization

void CFloatMenuDoc::Serialize(CArchive& ar)
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
// CFloatMenuDoc diagnostics

#ifdef _DEBUG
void CFloatMenuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFloatMenuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFloatMenuDoc commands
