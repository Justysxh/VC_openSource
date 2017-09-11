// SetFileAttriDlg.h : header file
//

#if !defined(AFX_SETFILEATTRIDLG_H__BE743CB5_5AFA_4CB3_B28E_94CFE684E433__INCLUDED_)
#define AFX_SETFILEATTRIDLG_H__BE743CB5_5AFA_4CB3_B28E_94CFE684E433__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSetFileAttriDlg dialog

class CSetFileAttriDlg : public CDialog
{
// Construction
public:
	CSetFileAttriDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSetFileAttriDlg)
	enum { IDD = IDD_SETFILEATTRI_DIALOG };
	CButton	m_vol;
	CButton	m_system;
	CButton	m_readonly;
	CButton	m_normal;
	CButton	m_hide;
	CButton	m_dir;
	CButton	m_ar;
	CStatic	m_filename;
	CString pathname;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetFileAttriDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSetFileAttriDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnSet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETFILEATTRIDLG_H__BE743CB5_5AFA_4CB3_B28E_94CFE684E433__INCLUDED_)
