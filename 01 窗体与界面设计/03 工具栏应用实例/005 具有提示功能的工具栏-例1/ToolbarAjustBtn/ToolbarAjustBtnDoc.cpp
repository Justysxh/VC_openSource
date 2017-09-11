// ToolbarAjustBtnDoc.cpp : implementation of the CToolbarAjustBtnDoc class
//

#include "stdafx.h"
#include "ToolbarAjustBtn.h"

#include "ToolbarAjustBtnDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToolbarAjustBtnDoc

IMPLEMENT_DYNCREATE(CToolbarAjustBtnDoc, CDocument)

BEGIN_MESSAGE_MAP(CToolbarAjustBtnDoc, CDocument)
	//{{AFX_MSG_MAP(CToolbarAjustBtnDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToolbarAjustBtnDoc construction/destruction

CToolbarAjustBtnDoc::CToolbarAjustBtnDoc()
{
	// TODO: add one-time construction code here

}

CToolbarAjustBtnDoc::~CToolbarAjustBtnDoc()
{
}

BOOL CToolbarAjustBtnDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CToolbarAjustBtnDoc serialization

void CToolbarAjustBtnDoc::Serialize(CArchive& ar)
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
// CToolbarAjustBtnDoc diagnostics

#ifdef _DEBUG
void CToolbarAjustBtnDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CToolbarAjustBtnDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CToolbarAjustBtnDoc commands
