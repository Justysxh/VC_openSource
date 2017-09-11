#if !defined(AFX_PREVIEW_H__94FD81EB_C7B7_485D_9148_45775834F9A9__INCLUDED_)
#define AFX_PREVIEW_H__94FD81EB_C7B7_485D_9148_45775834F9A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Preview.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPreview dialog

class CPreview : public CDialog
{
// Construction
public:
	void hanshu();
	void DrawReport(CRect rect, CDC *pDC, BOOL isprinted);
	CPreview(CWnd* pParent = NULL);   // standard constructor
	
	CString edit,m_yb,m_dz,m_sxr;
	CString strsxr;
	CString strText;
	CString sarrays[2][6];
	CFont titlefont;
	int screenx,screeny;
// Dialog Data
	//{{AFX_DATA(CPreview)
	enum { IDD = IDD_DIAPREVIEW };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPreview)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPreview)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PREVIEW_H__94FD81EB_C7B7_485D_9148_45775834F9A9__INCLUDED_)
