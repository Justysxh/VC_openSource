#if !defined(AFX_PREVIEW_H__BB764567_B85D_4483_8C4E_E6CB77D9687F__INCLUDED_)
#define AFX_PREVIEW_H__BB764567_B85D_4483_8C4E_E6CB77D9687F__INCLUDED_

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
	bool isfont;
	LOGFONT logfont;
	int LineWidth;
	CListCtrl *PrintGrid;
	CPreview(CWnd* pParent = NULL);   // standard constructor
	void PreviewGrid(CDC * dc,bool isprint);
	void GetPrintRate(double &ratex,double &ratey);
// Dialog Data
	//{{AFX_DATA(CPreview)
	enum { IDD = IDD_DIALOG1 };
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
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PREVIEW_H__BB764567_B85D_4483_8C4E_E6CB77D9687F__INCLUDED_)
