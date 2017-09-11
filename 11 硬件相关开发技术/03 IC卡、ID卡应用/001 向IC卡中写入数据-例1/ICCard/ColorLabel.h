#if !defined(AFX_COLORLABEL_H__DCBC1D02_0AA3_42D7_BF95_5E95662C09ED__INCLUDED_)
#define AFX_COLORLABEL_H__DCBC1D02_0AA3_42D7_BF95_5E95662C09ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColorLabel.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColorLabel window

class CColorLabel : public CStatic
{
// Construction
public:
	CColorLabel();
private:
	COLORREF  m_TextColor;   //ÎÄ±¾ÑÕÉ«
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorLabel)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetTextColor(COLORREF Color);
	COLORREF GetTextColor();
	virtual ~CColorLabel();

	// Generated message map functions
protected:
	//{{AFX_MSG(CColorLabel)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORLABEL_H__DCBC1D02_0AA3_42D7_BF95_5E95662C09ED__INCLUDED_)
