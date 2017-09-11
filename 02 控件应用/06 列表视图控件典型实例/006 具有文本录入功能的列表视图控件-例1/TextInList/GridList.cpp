// GridList.cpp : implementation file
//

#include "stdafx.h"
#include "TextInList.h"
#include "GridList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
BOOL S;
/////////////////////////////////////////////////////////////////////////////
// CGridList

CGridList::CGridList()
{
}

CGridList::~CGridList()
{
}


BEGIN_MESSAGE_MAP(CGridList, CListCtrl)
	//{{AFX_MSG_MAP(CGridList)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGridList message handlers

void CGridList::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	ModifyStyle(LVS_EDITLABELS,0);
	ModifyStyle(0,LVS_REPORT);
	ModifyStyle(0,LVS_SHOWSELALWAYS);
	SetExtendedStyle(LVS_EX_FLATSB
		|LVS_EX_FULLROWSELECT
		|LVS_EX_HEADERDRAGDROP
		|LVS_EX_ONECLICKACTIVATE
		|LVS_EX_GRIDLINES);
	edit.Create(WS_CHILD|WS_CLIPSIBLINGS|WS_EX_TOOLWINDOW|WS_BORDER,
		CRect(0,40,10,50),this,1001);
	CListCtrl::PreSubclassWindow();
}

void CGridList::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CListCtrl::OnLButtonDown(nFlags, point);
	LVHITTESTINFO info;
	info.pt=point;
	info.flags=LVHT_ONITEMLABEL;
	if(SubItemHitTest(&info)>=0)
	{
		row=info.iItem;
		col=info.iSubItem;
		ShowEdit();
	}
}

void CGridList::ShowEdit()
{
	CRect rect;
	GetSubItemRect(row,col,LVIR_LABEL,rect);
	CString str;
	str = GetItemText(row,col);
	edit.MoveWindow(rect);
	edit.SetWindowText(str);
	edit.ShowWindow(SW_SHOW);
	edit.SetSel(0,100);
	edit.SetFocus();
	UpdateWindow();
}

BOOL CGridList::DisposeEdit()
{
	CString sLabel;
	edit.GetWindowText(sLabel);
	this->SetItemText(row,col,sLabel);
	edit.ShowWindow(SW_HIDE);
	::SendMessage(this->GetParent()->GetSafeHwnd(),NULL,NULL,NULL);
	return true;
}
