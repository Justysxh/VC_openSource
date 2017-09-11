// RelievoDlg.h : header file
//

#if !defined(AFX_RELIEVODLG_H__71E736CA_65BB_4591_A3CC_AB7FDEFD0EB0__INCLUDED_)
#define AFX_RELIEVODLG_H__71E736CA_65BB_4591_A3CC_AB7FDEFD0EB0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRelievoDlg dialog

class CRelievoDlg : public CDialog
{
// Construction
public:
	void RelievoImage();
	CRelievoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRelievoDlg)
	enum { IDD = IDD_RELIEVO_DIALOG };
	CStatic	m_image;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRelievoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRelievoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTRelievo();
	afx_msg void OnButexit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RELIEVODLG_H__71E736CA_65BB_4591_A3CC_AB7FDEFD0EB0__INCLUDED_)
