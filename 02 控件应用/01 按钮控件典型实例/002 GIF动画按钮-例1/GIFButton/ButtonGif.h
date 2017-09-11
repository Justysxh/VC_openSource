#if !defined(AFX_BUTTONGIF_H__D0B98118_FD00_4F0C_8392_FAB0E32F8068__INCLUDED_)
#define AFX_BUTTONGIF_H__D0B98118_FD00_4F0C_8392_FAB0E32F8068__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ButtonGif.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CButtonGif window

class CButtonGif : public CButton
{
// Construction
public:
	CButtonGif();
	BOOL m_play;
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CButtonGif)
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawButton(CDC *pDC,UINT nState,CRect rect);
	void DrawItem(LPDRAWITEMSTRUCT lpDraw);
	virtual ~CButtonGif();

	// Generated message map functions
protected:
	//{{AFX_MSG(CButtonGif)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUTTONGIF_H__D0B98118_FD00_4F0C_8392_FAB0E32F8068__INCLUDED_)
