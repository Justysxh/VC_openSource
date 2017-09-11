#if !defined(AFX_SUPERLABEL_H__3027B777_6D85_416C_A768_EC7BC3C03E3A__INCLUDED_)
#define AFX_SUPERLABEL_H__3027B777_6D85_416C_A768_EC7BC3C03E3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SuperLabel.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSuperLabel window

class CSuperLabel : public CStatic
{
// Construction
public:
	CSuperLabel();

// Attributes
public:
	CFont     m_Font;
	CString   m_ConnectStr;
	LOGFONT   lfont;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSuperLabel)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSuperLabel();
	

	// Generated message map functions
protected:
	//{{AFX_MSG(CSuperLabel)
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUPERLABEL_H__3027B777_6D85_416C_A768_EC7BC3C03E3A__INCLUDED_)
