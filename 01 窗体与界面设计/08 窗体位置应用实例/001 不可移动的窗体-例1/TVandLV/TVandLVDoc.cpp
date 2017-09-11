// TVandLVDoc.cpp : implementation of the CTVandLVDoc class
//

#include "stdafx.h"
#include "TVandLV.h"

#include "TVandLVDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTVandLVDoc

IMPLEMENT_DYNCREATE(CTVandLVDoc, CDocument)

BEGIN_MESSAGE_MAP(CTVandLVDoc, CDocument)
	//{{AFX_MSG_MAP(CTVandLVDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTVandLVDoc construction/destruction

CTVandLVDoc::CTVandLVDoc()
{
	// TODO: add one-time construction code here

}

CTVandLVDoc::~CTVandLVDoc()
{
}

BOOL CTVandLVDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTVandLVDoc serialization

void CTVandLVDoc::Serialize(CArchive& ar)
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
// CTVandLVDoc diagnostics

#ifdef _DEBUG
void CTVandLVDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTVandLVDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTVandLVDoc commands
