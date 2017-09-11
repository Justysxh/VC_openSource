// IconMenuDoc.cpp : implementation of the CIconMenuDoc class
//

#include "stdafx.h"
#include "IconMenu.h"

#include "IconMenuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIconMenuDoc

IMPLEMENT_DYNCREATE(CIconMenuDoc, CDocument)

BEGIN_MESSAGE_MAP(CIconMenuDoc, CDocument)
	//{{AFX_MSG_MAP(CIconMenuDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIconMenuDoc construction/destruction

CIconMenuDoc::CIconMenuDoc()
{
	// TODO: add one-time construction code here

}

CIconMenuDoc::~CIconMenuDoc()
{
}

BOOL CIconMenuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CIconMenuDoc serialization

void CIconMenuDoc::Serialize(CArchive& ar)
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
// CIconMenuDoc diagnostics

#ifdef _DEBUG
void CIconMenuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CIconMenuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CIconMenuDoc commands

void CIconMenuDoc::SetTitle(LPCTSTR lpszTitle) 
{
	lpszTitle = "带图标的程序菜单";	
	CDocument::SetTitle(lpszTitle);
}
