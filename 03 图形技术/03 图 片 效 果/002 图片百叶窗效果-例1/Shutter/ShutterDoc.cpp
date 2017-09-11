// ShutterDoc.cpp : implementation of the CShutterDoc class
//

#include "stdafx.h"
#include "Shutter.h"

#include "ShutterDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShutterDoc

IMPLEMENT_DYNCREATE(CShutterDoc, CDocument)

BEGIN_MESSAGE_MAP(CShutterDoc, CDocument)
	//{{AFX_MSG_MAP(CShutterDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShutterDoc construction/destruction

CShutterDoc::CShutterDoc()
{
	// TODO: add one-time construction code here

}

CShutterDoc::~CShutterDoc()
{
}

BOOL CShutterDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CShutterDoc serialization

void CShutterDoc::Serialize(CArchive& ar)
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
// CShutterDoc diagnostics

#ifdef _DEBUG
void CShutterDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CShutterDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShutterDoc commands
