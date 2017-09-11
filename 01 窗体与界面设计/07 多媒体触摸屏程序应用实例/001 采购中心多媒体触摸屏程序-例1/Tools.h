#if !defined(AFX_TOOLS_H__DCBE8F1A_A3CE_4E8B_BC4F_59C4C20D6EB2__INCLUDED_)
#define AFX_TOOLS_H__DCBE8F1A_A3CE_4E8B_BC4F_59C4C20D6EB2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Tools.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTools dialog

class CTools : public CDialog
{
// Construction
public:
	CTools(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTools)
	enum { IDD = IDD_TOOLS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTools)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTools)
	virtual void OnOK();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLS_H__DCBE8F1A_A3CE_4E8B_BC4F_59C4C20D6EB2__INCLUDED_)
