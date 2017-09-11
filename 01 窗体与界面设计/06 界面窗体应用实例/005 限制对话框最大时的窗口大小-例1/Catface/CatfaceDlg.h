// CatfaceDlg.h : header file
//

#if !defined(AFX_CATFACEDLG_H__4BFAE433_7B92_437A_B3FD_8A5C11257E21__INCLUDED_)
#define AFX_CATFACEDLG_H__4BFAE433_7B92_437A_B3FD_8A5C11257E21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCatfaceDlg dialog

class CCatfaceDlg : public CDialog
{
// Construction
public:
	CCatfaceDlg(CWnd* pParent = NULL);	// standard constructor


// Dialog Data
	//{{AFX_DATA(CCatfaceDlg)
	enum { IDD = IDD_CATFACE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCatfaceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCatfaceDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CATFACEDLG_H__4BFAE433_7B92_437A_B3FD_8A5C11257E21__INCLUDED_)
