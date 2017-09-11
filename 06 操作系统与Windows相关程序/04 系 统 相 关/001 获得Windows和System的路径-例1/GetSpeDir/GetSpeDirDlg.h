// GetSpeDirDlg.h : header file
//

#if !defined(AFX_GETSPEDIRDLG_H__2FEA4D54_B6EC_45F7_A171_045064E061DA__INCLUDED_)
#define AFX_GETSPEDIRDLG_H__2FEA4D54_B6EC_45F7_A171_045064E061DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetSpeDirDlg dialog

class CGetSpeDirDlg : public CDialog
{
// Construction
public:
	CGetSpeDirDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetSpeDirDlg)
	enum { IDD = IDD_GETSPEDIR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetSpeDirDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetSpeDirDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETSPEDIRDLG_H__2FEA4D54_B6EC_45F7_A171_045064E061DA__INCLUDED_)
