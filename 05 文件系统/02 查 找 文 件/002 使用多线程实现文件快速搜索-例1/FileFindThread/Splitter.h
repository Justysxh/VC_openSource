#if !defined(AFX_SPLITTER_H__C90288D7_5D4B_4182_9195_0BAA303C3FF9__INCLUDED_)
#define AFX_SPLITTER_H__C90288D7_5D4B_4182_9195_0BAA303C3FF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Splitter.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSplitter window
#define SPLITTER_CLASSNAME    _T("MFCSplitter")
#define DEFAULT_WIDTH 8


class CSplitter : public CWnd
{
DECLARE_DYNCREATE(CSplitter);
private:
	BOOL m_CanMove;
	int m_MoveX;
protected:
	int m_Height;
	int m_Width;
	int m_Left;
	int m_Top;

	BOOL RegisterWindowClass();
	CRect GetRect();
// Construction
public:
	CSplitter();
	BOOL Create(CWnd* parent, UINT nID,
                DWORD dwStyle = WS_CHILD | WS_BORDER | WS_TABSTOP | WS_VISIBLE);
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSplitter)
	public:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSplitter();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSplitter)
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLITTER_H__C90288D7_5D4B_4182_9195_0BAA303C3FF9__INCLUDED_)
