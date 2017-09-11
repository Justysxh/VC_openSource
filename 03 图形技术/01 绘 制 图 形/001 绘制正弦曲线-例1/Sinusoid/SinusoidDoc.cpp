// SinusoidDoc.cpp : implementation of the CSinusoidDoc class
//

#include "stdafx.h"
#include "Sinusoid.h"

#include "SinusoidDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSinusoidDoc

IMPLEMENT_DYNCREATE(CSinusoidDoc, CDocument)

BEGIN_MESSAGE_MAP(CSinusoidDoc, CDocument)
	//{{AFX_MSG_MAP(CSinusoidDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSinusoidDoc construction/destruction

CSinusoidDoc::CSinusoidDoc()
{
	// TODO: add one-time construction code here

}

CSinusoidDoc::~CSinusoidDoc()
{
}

BOOL CSinusoidDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSinusoidDoc serialization

void CSinusoidDoc::Serialize(CArchive& ar)
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
// CSinusoidDoc diagnostics

#ifdef _DEBUG
void CSinusoidDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSinusoidDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSinusoidDoc commands
