#if !defined(AFX_NUMLABEL_H__6C13EEE9_F503_4104_A521_DC25E684604B__INCLUDED_)
#define AFX_NUMLABEL_H__6C13EEE9_F503_4104_A521_DC25E684604B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NumLabel.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNumLabel window

class CNumLabel : public CStatic
{
// Construction
public:
	CNumLabel();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNumLabel)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetText(CString csText);
	virtual ~CNumLabel();

	// Generated message map functions
protected:
	CString m_Text;
	CFont font;
	//{{AFX_MSG(CNumLabel)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUMLABEL_H__6C13EEE9_F503_4104_A521_DC25E684604B__INCLUDED_)
