// CTdrawDoc.cpp : implementation of the CCTdrawDoc class
//

#include "stdafx.h"
#include "CTdraw.h"

#include "CTdrawDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCTdrawDoc

IMPLEMENT_DYNCREATE(CCTdrawDoc, CDocument)

BEGIN_MESSAGE_MAP(CCTdrawDoc, CDocument)
	//{{AFX_MSG_MAP(CCTdrawDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCTdrawDoc construction/destruction

CCTdrawDoc::CCTdrawDoc()
{
	// TODO: add one-time construction code here

}

CCTdrawDoc::~CCTdrawDoc()
{
}

BOOL CCTdrawDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCTdrawDoc serialization

void CCTdrawDoc::Serialize(CArchive& ar)
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
// CCTdrawDoc diagnostics

#ifdef _DEBUG
void CCTdrawDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCTdrawDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCTdrawDoc commands
