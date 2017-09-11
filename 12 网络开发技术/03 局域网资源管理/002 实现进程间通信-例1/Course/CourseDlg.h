// CourseDlg.h : header file
//

#if !defined(AFX_COURSEDLG_H__8FFDAC90_475D_4146_B12E_23E4A8534E8F__INCLUDED_)
#define AFX_COURSEDLG_H__8FFDAC90_475D_4146_B12E_23E4A8534E8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCourseDlg dialog

class CCourseDlg : public CDialog
{
// Construction
public:
	CCourseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCourseDlg)
	enum { IDD = IDD_COURSE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCourseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCourseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButmax();
	afx_msg void OnButmin();
	afx_msg void OnButrevert();
	afx_msg void OnButexit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COURSEDLG_H__8FFDAC90_475D_4146_B12E_23E4A8534E8F__INCLUDED_)
