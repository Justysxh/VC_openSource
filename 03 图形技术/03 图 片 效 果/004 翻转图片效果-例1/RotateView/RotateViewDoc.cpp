// RotateViewDoc.cpp : implementation of the CRotateViewDoc class
//

#include "stdafx.h"
#include "RotateView.h"

#include "RotateViewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRotateViewDoc

IMPLEMENT_DYNCREATE(CRotateViewDoc, CDocument)

BEGIN_MESSAGE_MAP(CRotateViewDoc, CDocument)
	//{{AFX_MSG_MAP(CRotateViewDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRotateViewDoc construction/destruction

CRotateViewDoc::CRotateViewDoc()
{
	// TODO: add one-time construction code here

}

CRotateViewDoc::~CRotateViewDoc()
{
}

BOOL CRotateViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRotateViewDoc serialization

void CRotateViewDoc::Serialize(CArchive& ar)
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
// CRotateViewDoc diagnostics

#ifdef _DEBUG
void CRotateViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRotateViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRotateViewDoc commands
