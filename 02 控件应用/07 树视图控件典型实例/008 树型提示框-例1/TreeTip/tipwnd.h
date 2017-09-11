#if !defined(AFX_TIPWND_H__BB13928A_530F_4699_A599_71706C4A1FB1__INCLUDED_)
#define AFX_TIPWND_H__BB13928A_530F_4699_A599_71706C4A1FB1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// tipwnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// tipwnd window

class tipwnd : public CTreeCtrl
{
// Construction
public:
	tipwnd();

// Attributes
public:

// Operations
public:
	void ShowTipWindow(CString strtip,CString strsepar,CWnd* pParent,CPoint ptmouse);
	void ClostTipWinow();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(tipwnd)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~tipwnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(tipwnd)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// treetipedit window

class treetipedit : public CEdit
{
// Construction
public:
	treetipedit();

// Attributes
public:
	tipwnd m_tipwnd;
// Operations
public:
	CString strseparator;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(treetipedit)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~treetipedit();

	// Generated message map functions
protected:
	//{{AFX_MSG(treetipedit)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIPWND_H__BB13928A_530F_4699_A599_71706C4A1FB1__INCLUDED_)
