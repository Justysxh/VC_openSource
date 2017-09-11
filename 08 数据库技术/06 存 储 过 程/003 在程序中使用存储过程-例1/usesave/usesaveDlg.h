// usesaveDlg.h : header file
//

#if !defined(AFX_USESAVEDLG_H__434F2D26_E88A_4F8A_8D37_9D7DD643343A__INCLUDED_)
#define AFX_USESAVEDLG_H__434F2D26_E88A_4F8A_8D37_9D7DD643343A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUsesaveDlg dialog

class CUsesaveDlg : public CDialog
{
// Construction
public:
	CUsesaveDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUsesaveDlg)
	enum { IDD = IDD_USESAVE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUsesaveDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUsesaveDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USESAVEDLG_H__434F2D26_E88A_4F8A_8D37_9D7DD643343A__INCLUDED_)
