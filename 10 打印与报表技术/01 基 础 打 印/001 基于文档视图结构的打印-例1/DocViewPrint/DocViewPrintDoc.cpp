// DocViewPrintDoc.cpp : implementation of the CDocViewPrintDoc class
//

#include "stdafx.h"
#include "DocViewPrint.h"

#include "DocViewPrintDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDocViewPrintDoc

IMPLEMENT_DYNCREATE(CDocViewPrintDoc, CDocument)

BEGIN_MESSAGE_MAP(CDocViewPrintDoc, CDocument)
	//{{AFX_MSG_MAP(CDocViewPrintDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDocViewPrintDoc construction/destruction

CDocViewPrintDoc::CDocViewPrintDoc()
{
	// TODO: add one-time construction code here

}

CDocViewPrintDoc::~CDocViewPrintDoc()
{
}

BOOL CDocViewPrintDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDocViewPrintDoc serialization

void CDocViewPrintDoc::Serialize(CArchive& ar)
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
// CDocViewPrintDoc diagnostics

#ifdef _DEBUG
void CDocViewPrintDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDocViewPrintDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDocViewPrintDoc commands

void CDocViewPrintDoc::SetTitle(LPCTSTR lpszTitle) 
{
	lpszTitle = "明日科技";	
	CDocument::SetTitle(lpszTitle);
}
