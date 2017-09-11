// ListEdit.cpp : implementation file
//

#include "stdafx.h"
#include "TextInList.h"
#include "ListEdit.h"
#include "GridList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListEdit

CListEdit::CListEdit()
{
}

CListEdit::~CListEdit()
{
}


BEGIN_MESSAGE_MAP(CListEdit, CEdit)
	//{{AFX_MSG_MAP(CListEdit)
	ON_WM_KILLFOCUS()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListEdit message handlers

void CListEdit::OnKillFocus(CWnd* pNewWnd) 
{
	CGridList * temp = (CGridList *)GetParent();
	if(temp)
	{
		temp->DisposeEdit();
	}
}



