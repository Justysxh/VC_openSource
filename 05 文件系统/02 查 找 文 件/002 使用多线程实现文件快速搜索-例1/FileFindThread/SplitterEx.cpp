// SplitterEx.cpp: implementation of the CSplitterEx class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FileFindThread.h"
#include "SplitterEx.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSplitterEx::CSplitterEx()
{

}

CSplitterEx::~CSplitterEx()
{

}

CWnd* CSplitterEx::GetActivePane(int* pRow, int* pCol)
{
	ASSERT_VALID(this);

	CWnd* pView = GetFocus();

	// make sure the pane is a child pane of the splitter
	if (pView != NULL && !IsChildPane(pView, pRow, pCol))
		pView = NULL;

	return pView;
	//return CSplitterWnd::GetActivePane(pRow,pCol);
}

void CSplitterEx::SetActivePane( int row, int col, CWnd* pWnd)
{
	// set the focus to the pane
	CWnd* pPane = pWnd == NULL ? GetPane(row, col) : pWnd;
	pPane->SetFocus();
}

void CSplitterEx::StartTracking(int ht)
{
	ASSERT_VALID(this);
	if (ht == noHit)
		return;

	// GetHitRect will restrict 'm_rectLimit' as appropriate
	GetInsideRect(m_rectLimit);

	if (ht >= splitterIntersection1 && ht <= splitterIntersection225)
	{
		// split two directions (two tracking rectangles)
		int row = (ht - splitterIntersection1) / 15;
		int col = (ht - splitterIntersection1) % 15;

		GetHitRect(row + vSplitterBar1, m_rectTracker);
		int yTrackOffset = m_ptTrackOffset.y;
		m_bTracking2 = TRUE;
		GetHitRect(col + hSplitterBar1, m_rectTracker2);
		m_ptTrackOffset.y = yTrackOffset;
	}
	else if (ht == bothSplitterBox)
	{
		// hit on splitter boxes (for keyboard)
		GetHitRect(vSplitterBox, m_rectTracker);
		int yTrackOffset = m_ptTrackOffset.y;
		m_bTracking2 = TRUE;
		GetHitRect(hSplitterBox, m_rectTracker2);
		m_ptTrackOffset.y = yTrackOffset;

		// center it
		m_rectTracker.OffsetRect(0, m_rectLimit.Height()/2);
		m_rectTracker2.OffsetRect(m_rectLimit.Width()/2, 0);
	}
	else
	{
		// only hit one bar
		GetHitRect(ht, m_rectTracker);
	}

	// steal focus and capture
	SetCapture();
	SetFocus();

	// make sure no updates are pending
	RedrawWindow(NULL, NULL, RDW_ALLCHILDREN | RDW_UPDATENOW);

	// set tracking state and appropriate cursor
	m_bTracking = TRUE;
	OnInvertTracker(m_rectTracker);
	if (m_bTracking2)
		OnInvertTracker(m_rectTracker2);
	m_htTrack = ht;
	SetSplitCursor(ht);
}

BOOL CSplitterEx::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (CWnd::OnCommand(wParam, lParam))
		return TRUE;

	// route commands to the splitter to the parent frame window
	return GetParent()->SendMessage(WM_COMMAND, wParam, lParam);
}

BOOL CSplitterEx::OnNotify( WPARAM wParam, LPARAM lParam, LRESULT* pResult )
{
	if (CWnd::OnNotify(wParam, lParam, pResult))
		return TRUE;

	// route commands to the splitter to the parent frame window
	*pResult = GetParent()->SendMessage(WM_NOTIFY, wParam, lParam);
	return TRUE;
}

BOOL CSplitterEx::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
//	AFX_MANAGE_STATE(AfxGetStaticModuleState());  // for usage in ActiveX control
	return CWnd::OnWndMsg(message, wParam, lParam, pResult);
}
