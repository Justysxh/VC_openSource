// PictureOverturnDoc.cpp : implementation of the CPictureOverturnDoc class
//

#include "stdafx.h"
#include "PictureOverturn.h"

#include "PictureOverturnDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPictureOverturnDoc

IMPLEMENT_DYNCREATE(CPictureOverturnDoc, CDocument)

BEGIN_MESSAGE_MAP(CPictureOverturnDoc, CDocument)
	//{{AFX_MSG_MAP(CPictureOverturnDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPictureOverturnDoc construction/destruction

CPictureOverturnDoc::CPictureOverturnDoc()
{
	// TODO: add one-time construction code here

}

CPictureOverturnDoc::~CPictureOverturnDoc()
{
}

BOOL CPictureOverturnDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPictureOverturnDoc serialization

void CPictureOverturnDoc::Serialize(CArchive& ar)
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
// CPictureOverturnDoc diagnostics

#ifdef _DEBUG
void CPictureOverturnDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPictureOverturnDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPictureOverturnDoc commands
