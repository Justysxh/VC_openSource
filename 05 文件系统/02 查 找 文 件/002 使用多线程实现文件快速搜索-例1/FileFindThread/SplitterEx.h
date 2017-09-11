// SplitterEx.h: interface for the CSplitterEx class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPLITTEREX_H__13F2A60C_3023_4EE6_BC4E_668C8787FFF2__INCLUDED_)
#define AFX_SPLITTEREX_H__13F2A60C_3023_4EE6_BC4E_668C8787FFF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum HitTestValue
{
	noHit                   = 0,
	vSplitterBox            = 1,
	hSplitterBox            = 2,
	bothSplitterBox         = 3,        // just for keyboard
	vSplitterBar1           = 101,
	vSplitterBar15          = 115,
	hSplitterBar1           = 201,
	hSplitterBar15          = 215,
	splitterIntersection1   = 301,
	splitterIntersection225 = 525
};

class CSplitterEx : public CSplitterWnd  
{
public:
	CSplitterEx();
	virtual ~CSplitterEx();
	virtual CWnd* GetActivePane(int* pRow = NULL, int* pCol = NULL);
	virtual void SetActivePane( int row, int col, CWnd* pWnd = NULL );
	virtual void StartTracking(int ht);

	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL OnNotify( WPARAM wParam, LPARAM lParam, LRESULT* pResult );
	virtual BOOL OnWndMsg( UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult );
};

#endif // !defined(AFX_SPLITTEREX_H__13F2A60C_3023_4EE6_BC4E_668C8787FFF2__INCLUDED_)
