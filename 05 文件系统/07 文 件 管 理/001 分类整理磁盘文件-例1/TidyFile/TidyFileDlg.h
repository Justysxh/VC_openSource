// TidyFileDlg.h : header file
//

#if !defined(AFX_TIDYFILEDLG_H__C042ABFC_1127_4741_ABF2_13E96F7857AD__INCLUDED_)
#define AFX_TIDYFILEDLG_H__C042ABFC_1127_4741_ABF2_13E96F7857AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTidyFileDlg dialog

class CTidyFileDlg : public CDialog
{
// Construction
public:
	CTidyFileDlg(CWnd* pParent = NULL);	// standard constructor
	void TidyFile(CString path,CString strext);
	CString strpath;
// Dialog Data
	//{{AFX_DATA(CTidyFileDlg)
	enum { IDD = IDD_TIDYFILE_DIALOG };
	CComboBox	m_fileext;
	CListCtrl	m_filelist;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTidyFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTidyFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnSave();
	afx_msg void OnSelchangeCofileext();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIDYFILEDLG_H__C042ABFC_1127_4741_ABF2_13E96F7857AD__INCLUDED_)
