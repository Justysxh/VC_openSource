// LineTree.cpp : implementation file
//

#include "stdafx.h"
#include "LineColor.h"
#include "LineTree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLineTree

CLineTree::CLineTree()
{
	m_clText = RGB(58, 79, 107);
	m_clBk = RGB(234, 242, 255);
	m_clLine = RGB(0, 0, 255);
}

CLineTree::~CLineTree()
{
}


BEGIN_MESSAGE_MAP(CLineTree, CTreeCtrl)
	//{{AFX_MSG_MAP(CLineTree)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLineTree message handlers

void CLineTree::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	//设置文本颜色
	SetTextColor(m_clText);
	//设置背景颜色
	SetBkColor(m_clBk);
	//设置线条颜色
	SendMessage(TV_FIRST + 40, 0, (LPARAM)m_clLine);
	CTreeCtrl::PreSubclassWindow();
}
