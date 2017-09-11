// MyBrowerDoc.cpp : implementation of the CMyBrowerDoc class
//

#include "stdafx.h"
#include "MyBrower.h"

#include "MyBrowerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyBrowerDoc

IMPLEMENT_DYNCREATE(CMyBrowerDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyBrowerDoc, CDocument)
	//{{AFX_MSG_MAP(CMyBrowerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyBrowerDoc construction/destruction

CMyBrowerDoc::CMyBrowerDoc()
{
	// TODO: add one-time construction code here

}

CMyBrowerDoc::~CMyBrowerDoc()
{
}

BOOL CMyBrowerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyBrowerDoc serialization

void CMyBrowerDoc::Serialize(CArchive& ar)
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
// CMyBrowerDoc diagnostics

#ifdef _DEBUG
void CMyBrowerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyBrowerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyBrowerDoc commands
