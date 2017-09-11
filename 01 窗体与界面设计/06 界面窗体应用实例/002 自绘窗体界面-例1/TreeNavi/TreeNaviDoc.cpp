// TreeNaviDoc.cpp : implementation of the CTreeNaviDoc class
//

#include "stdafx.h"
#include "TreeNavi.h"

#include "TreeNaviDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreeNaviDoc

IMPLEMENT_DYNCREATE(CTreeNaviDoc, CDocument)

BEGIN_MESSAGE_MAP(CTreeNaviDoc, CDocument)
	//{{AFX_MSG_MAP(CTreeNaviDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreeNaviDoc construction/destruction

CTreeNaviDoc::CTreeNaviDoc()
{
	// TODO: add one-time construction code here

}

CTreeNaviDoc::~CTreeNaviDoc()
{
}

BOOL CTreeNaviDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTreeNaviDoc serialization

void CTreeNaviDoc::Serialize(CArchive& ar)
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
// CTreeNaviDoc diagnostics

#ifdef _DEBUG
void CTreeNaviDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTreeNaviDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTreeNaviDoc commands
