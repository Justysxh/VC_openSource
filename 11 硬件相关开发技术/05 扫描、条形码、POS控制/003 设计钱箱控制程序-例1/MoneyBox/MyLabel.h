#if !defined(AFX_MYLABEL_H__A55C2FED_6658_40C3_BD79_2EE7D0083BB6__INCLUDED_)
#define AFX_MYLABEL_H__A55C2FED_6658_40C3_BD79_2EE7D0083BB6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyLabel.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyLabel window

class CMyLabel : public CStatic
{
// Construction

protected:
	CFont m_Font;
public:
	CMyLabel();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyLabel)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyLabel();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyLabel)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYLABEL_H__A55C2FED_6658_40C3_BD79_2EE7D0083BB6__INCLUDED_)
