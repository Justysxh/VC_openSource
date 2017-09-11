// CustomStatic.cpp : implementation file
//

#include "stdafx.h"
#include "FetchAndSaveIcon.h"
#include "CustomStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustomStatic

CCustomStatic::CCustomStatic()
{
}

CCustomStatic::~CCustomStatic()
{
}


BEGIN_MESSAGE_MAP(CCustomStatic, CStatic)
	//{{AFX_MSG_MAP(CCustomStatic)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomStatic message handlers

void CCustomStatic::Serialize(CArchive& ar) 
{
	if (ar.IsStoring())
	{	
		//
		// storing code
	}
	else
	{	// loading code
	}
}
