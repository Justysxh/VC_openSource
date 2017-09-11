#if !defined(AFX_FRAMEDLG_H__61D80BFB_CD11_4F75_AD0A_7F1CCCE9E36A__INCLUDED_)
#define AFX_FRAMEDLG_H__61D80BFB_CD11_4F75_AD0A_7F1CCCE9E36A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FrameDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFrameDlg dialog

class CFrameDlg : public CDialog
{
// Construction
public:
	CFrameDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFrameDlg)
	enum { IDD = IDD_DIALOGFRAME };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFrameDlg)
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FRAMEDLG_H__61D80BFB_CD11_4F75_AD0A_7F1CCCE9E36A__INCLUDED_)
