// tipwnd.cpp : implementation file
//

#include "stdafx.h"
#include "TreeTip.h"
#include "tipwnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// tipwnd

tipwnd::tipwnd()
{
}

tipwnd::~tipwnd()
{
}


BEGIN_MESSAGE_MAP(tipwnd, CTreeCtrl)
	//{{AFX_MSG_MAP(tipwnd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// tipwnd message handlers

void tipwnd::ShowTipWindow(CString strtip,CString strsepar,CWnd* pParent,CPoint ptmouse)
{
	if ( ::IsWindow( m_hWnd ) )
	return;

	CRect rctWnd;
		CWnd* pMain = CWnd::GetDesktopWindow();
	pParent->GetWindowRect( &rctWnd );
	pMain->ScreenToClient( &rctWnd );

	CPoint ptParent( ptmouse.x + rctWnd.left -3, ptmouse.y+ rctWnd.top -3 );
	CRect rct( ptParent.x, ptParent.y, ptParent.x + 500, ptParent.y+ 300);
	Create( WS_BORDER|TVS_HASLINES|TVS_NOTOOLTIPS ,rct, pMain,-1 );
	

	HTREEITEM parent=TVI_ROOT;
	CString strleft;
	int pos=strtip.Find(strsepar);

	if(pos<=0)return;
	while(pos>0)
	{
	strleft=strtip.Left(pos);
	strtip=strtip.Right(strtip.GetLength()-pos-strsepar.GetLength());
	parent=InsertItem(strleft,parent);

	pos=strtip.Find(strsepar);
	if(pos<0)
	{
		parent=InsertItem(strtip,parent);
	}
	}
	Expand(TVI_ROOT,TVE_EXPAND);
	SetItemState(parent,TVIS_SELECTED ,0);
	Select(parent,TVGN_CARET);

	MoveWindow(rct.left,rct.top,200,100,FALSE);
	SetFocus();
	SetWindowPos( &wndTopMost ,0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE );
	DWORD style = GetWindowLong( m_hWnd, GWL_EXSTYLE ); 
	SetWindowLong( m_hWnd, GWL_EXSTYLE, style | WS_EX_TOPMOST );
	ShowWindow(SW_SHOW);
	
}
void tipwnd::ClostTipWinow()
{
	
	DestroyWindow();

}
/////////////////////////////////////////////////////////////////////////////
// treetipedit

treetipedit::treetipedit()
{
}

treetipedit::~treetipedit()
{
}


BEGIN_MESSAGE_MAP(treetipedit, CEdit)
	//{{AFX_MSG_MAP(treetipedit)
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// treetipedit message handlers

void treetipedit::OnRButtonDown(UINT nFlags, CPoint point) 
{
	CString edittext;
	GetWindowText(edittext);
	m_tipwnd.ShowTipWindow(edittext,strseparator,this,point);

	CEdit::OnRButtonDown(nFlags, point);
}

void treetipedit::OnLButtonDown(UINT nFlags, CPoint point) 
{
	m_tipwnd.ClostTipWinow();
	CEdit::OnLButtonDown(nFlags, point);
}

void treetipedit::OnRButtonUp(UINT nFlags, CPoint point) 
{
	//CEdit::OnRButtonUp(nFlags, point);
}
