// TreeFrame.cpp : implementation file
//

#include "stdafx.h"
#include "FileFindThread.h"
#include "TreeFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreeFrame

IMPLEMENT_DYNCREATE(CTreeFrame, CTreeView)

CTreeFrame::CTreeFrame()
{
}

CTreeFrame::~CTreeFrame()
{
}


BEGIN_MESSAGE_MAP(CTreeFrame, CTreeView)
	//{{AFX_MSG_MAP(CTreeFrame)
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDING, OnItemexpanding)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreeFrame drawing

void CTreeFrame::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CTreeFrame diagnostics

#ifdef _DEBUG
void CTreeFrame::AssertValid() const
{
	CTreeView::AssertValid();
}

void CTreeFrame::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTreeFrame message handlers

void CTreeFrame::InitTree()
{
	GetTreeCtrl().ModifyStyle(0,TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT | TVS_CHECKBOXES);
	TreeItemRoot = GetTreeCtrl().InsertItem("ÎÒµÄµçÄÔ",0,0);
	GetLogicalDrives(TreeItemRoot);
	GetTreeCtrl().Expand(TreeItemRoot,TVE_EXPAND);
}

void CTreeFrame::OnInitialUpdate() 
{
	CTreeView::OnInitialUpdate();
	
	InitTree();	
}

void CTreeFrame::GetLogicalDrives(HTREEITEM hParent)
{
	ASSERT( hParent );

	DWORD dwAllDriveStrings = GetLogicalDriveStrings( 0, NULL );
	ASSERT( dwAllDriveStrings >= 1 );

	LPTSTR lpDriveStrings = NULL;
	lpDriveStrings = new TCHAR[ dwAllDriveStrings + sizeof( _T( "" ) ) ];
	ASSERT( lpDriveStrings != NULL );

	// Save the original address for the drive strings...
	LPTSTR lpTmp = lpDriveStrings;

	GetLogicalDriveStrings( dwAllDriveStrings, lpDriveStrings );

	size_t szDriveString = lstrlen( lpDriveStrings );
	while ( szDriveString > 1 )
	{
		HTREEITEM childitem = GetTreeCtrl().InsertItem( lpDriveStrings, hParent );
		AddSubDirectory(childitem,false);
		lpDriveStrings += szDriveString + 1;
		szDriveString = lstrlen( lpDriveStrings );
	}

	lpDriveStrings = lpTmp;
	if ( lpDriveStrings )
	{
		delete lpDriveStrings;
		lpDriveStrings = NULL;
	}
	ASSERT( lpDriveStrings == NULL );
}

void CTreeFrame::OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	NM_TREEVIEW TreeView = (NM_TREEVIEW)(*pNMTreeView);
	if (TreeView.itemNew.hItem == TreeItemRoot)
		return;

	AddSubDirectory( TreeView.itemNew.hItem );
	*pResult = 0;
}

void CTreeFrame::AddSubDirectory( HTREEITEM hParent,BOOL All)
{
	ASSERT( hParent );
	if (All == false)
	{
		
		if (::GetDriveType(GetTreeCtrl().GetItemText(hParent)) == DRIVE_FIXED)
		GetTreeCtrl().InsertItem("",0,0,hParent);
		return;
	}
	// Delete the previous added child items
	HTREEITEM hChild = GetTreeCtrl().GetChildItem( hParent );
	while ( hChild )
	{
		GetTreeCtrl().DeleteItem( hChild );
		hChild = GetTreeCtrl().GetChildItem( hParent );
	}

	while ( hParent )
	{
		CString strPath = GetFullPath( hParent );
		if ( strPath.Right( 1 ) != "\\" )
			strPath += "\\";
		strPath += _T( "*.*" );

		CFileFind file;

		BOOL bContinue = file.FindFile( strPath );
		while ( bContinue )
		{
			bContinue = file.FindNextFile();
			if ( file.IsDirectory() && ! file.IsDots() )
			{
				GetTreeCtrl().InsertItem( file.GetFileName(), hParent );
			}
		}
		hParent = GetTreeCtrl().GetNextItem( hParent, TVGN_NEXT );
	}
}

CString CTreeFrame::GetFullPath( HTREEITEM hItem)
{
	ASSERT( hItem );

	CString strTmp	= _T( "" );
	CString strPath	= _T( "" );

	while ( hItem != TreeItemRoot )
	{
		strTmp = GetTreeCtrl().GetItemText( hItem );
		if ( strTmp.Right( 1 ) != _T( "\\" ) )
			strTmp += _T( "\\" );
		strPath = strTmp + strPath;

		hItem = GetTreeCtrl().GetParentItem( hItem );
	}

	return strPath;
}