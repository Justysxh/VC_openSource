#if !defined(AFX_FLOATDLG_H__65C40FD5_408F_422C_9A2B_2499B961EE24__INCLUDED_)
#define AFX_FLOATDLG_H__65C40FD5_408F_422C_9A2B_2499B961EE24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FloatDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFloatDlg dialog

class CFloatDlg : public CDialog
{
// Construction
public:
	CFloatDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFloatDlg)
	enum { IDD = IDD_FLOATDLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFloatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFloatDlg)
	virtual void OnOK();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnButton32776();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLOATDLG_H__65C40FD5_408F_422C_9A2B_2499B961EE24__INCLUDED_)
