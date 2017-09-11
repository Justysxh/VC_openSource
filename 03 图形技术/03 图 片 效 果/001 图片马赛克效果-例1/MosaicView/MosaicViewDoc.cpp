// MosaicViewDoc.cpp : implementation of the CMosaicViewDoc class
//

#include "stdafx.h"
#include "MosaicView.h"

#include "MosaicViewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMosaicViewDoc

IMPLEMENT_DYNCREATE(CMosaicViewDoc, CDocument)

BEGIN_MESSAGE_MAP(CMosaicViewDoc, CDocument)
	//{{AFX_MSG_MAP(CMosaicViewDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMosaicViewDoc construction/destruction

CMosaicViewDoc::CMosaicViewDoc()
{
	// TODO: add one-time construction code here

}

CMosaicViewDoc::~CMosaicViewDoc()
{
}

BOOL CMosaicViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMosaicViewDoc serialization

void CMosaicViewDoc::Serialize(CArchive& ar)
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
// CMosaicViewDoc diagnostics

#ifdef _DEBUG
void CMosaicViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMosaicViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMosaicViewDoc commands
