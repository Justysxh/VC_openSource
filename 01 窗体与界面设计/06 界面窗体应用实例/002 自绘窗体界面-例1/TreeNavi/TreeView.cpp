// TreeView.cpp : implementation file
//

#include "stdafx.h"
#include "TreeNavi.h"
#include "TreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// TreeView

IMPLEMENT_DYNCREATE(TreeView, CTreeView)

TreeView::TreeView()
{
}

TreeView::~TreeView()
{
}


BEGIN_MESSAGE_MAP(TreeView, CTreeView)
	//{{AFX_MSG_MAP(TreeView)
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TreeView drawing

void TreeView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// TreeView diagnostics

#ifdef _DEBUG
void TreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void TreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// TreeView message handlers

void TreeView::OnInitialUpdate() 
{

	CTreeView::OnInitialUpdate();

	list.Create(32,32,ILC_COLOR32|ILC_MASK,0,0);
	list.Add(::AfxGetApp()->LoadIcon(IDI_ICON1));
	list.Add(::AfxGetApp()->LoadIcon(IDI_ICON2));
	list.Add(::AfxGetApp()->LoadIcon(IDI_ICON3));
	list.Add(::AfxGetApp()->LoadIcon(IDI_ICON4));
	list.Add(::AfxGetApp()->LoadIcon(IDI_ICON5));
	list.Add(::AfxGetApp()->LoadIcon(IDI_ICON6));
	list.Add(::AfxGetApp()->LoadIcon(IDI_ICON7));
	list.Add(::AfxGetApp()->LoadIcon(IDI_ICON8));
	list.Add(::AfxGetApp()->LoadIcon(IDI_ICON9));
	list.Add(::AfxGetApp()->LoadIcon(IDI_ICON10));
	list.Add(::AfxGetApp()->LoadIcon(IDI_ICON11));
	list.Add(::AfxGetApp()->LoadIcon(IDI_ICON12));
	list.Add(::AfxGetApp()->LoadIcon(IDI_ICON13));
	list.Add(::AfxGetApp()->LoadIcon(IDI_ICON14));
	list.Add(::AfxGetApp()->LoadIcon(IDI_ICON15));
	this->GetTreeCtrl().SetImageList(&list,TVSIL_NORMAL);
	HTREEITEM tree;
	tree=this->GetTreeCtrl().InsertItem("导航1",0,1);
	this->GetTreeCtrl().InsertItem("子导航1",6,6,tree);
	this->GetTreeCtrl().InsertItem("子导航2",7,7,tree);
	this->GetTreeCtrl().InsertItem("子导航3",8,8,tree);
	tree=this->GetTreeCtrl().InsertItem("导航2",2,3);
	this->GetTreeCtrl().InsertItem("子导航4",9,19,tree);
	this->GetTreeCtrl().InsertItem("子导航5",10,10,tree);
	this->GetTreeCtrl().InsertItem("子导航6",11,11,tree);
	tree=this->GetTreeCtrl().InsertItem("导航3",4,5);
	this->GetTreeCtrl().InsertItem("子导航7",12,12,tree);
	this->GetTreeCtrl().InsertItem("子导航8",13,13,tree);
	this->GetTreeCtrl().InsertItem("子导航9",14,14,tree);
	// TODO: Add your specialized code here and/or call the base class
	
}

void TreeView::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	HTREEITEM tree=this->GetTreeCtrl().GetSelectedItem();
	if(!this->GetTreeCtrl().GetChildItem(tree))
	{
		CString str=this->GetTreeCtrl().GetItemText(tree);
		AfxMessageBox(str);
	}
	*pResult = 0;
}


