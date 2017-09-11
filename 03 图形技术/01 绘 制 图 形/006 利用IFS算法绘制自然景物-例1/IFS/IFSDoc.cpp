// IFSDoc.cpp : implementation of the CIFSDoc class
//

#include "stdafx.h"
#include "IFS.h"

#include "IFSDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIFSDoc

IMPLEMENT_DYNCREATE(CIFSDoc, CDocument)

BEGIN_MESSAGE_MAP(CIFSDoc, CDocument)
	//{{AFX_MSG_MAP(CIFSDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIFSDoc construction/destruction

CIFSDoc::CIFSDoc()
{
	// TODO: add one-time construction code here

}

CIFSDoc::~CIFSDoc()
{
}

BOOL CIFSDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CIFSDoc serialization

void CIFSDoc::Serialize(CArchive& ar)
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
// CIFSDoc diagnostics

#ifdef _DEBUG
void CIFSDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CIFSDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CIFSDoc commands
