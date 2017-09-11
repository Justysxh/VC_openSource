#if !defined(AFX_CARDID_H__A4006517_F1C8_4435_81CE_520A9A77DAA0__INCLUDED_)
#define AFX_CARDID_H__A4006517_F1C8_4435_81CE_520A9A77DAA0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CardID.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCardID window

class CCardID : public CStatic
{
// Construction
public:
	CCardID();

// Attributes
public:
	CFont m_Font;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCardID)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCardID();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCardID)
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARDID_H__A4006517_F1C8_4435_81CE_520A9A77DAA0__INCLUDED_)
