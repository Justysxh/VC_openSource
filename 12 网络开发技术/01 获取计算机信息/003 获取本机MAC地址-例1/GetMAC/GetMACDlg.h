// GetMACDlg.h : header file
//

#if !defined(AFX_GETMACDLG_H__0DE08180_C0C7_4FBE_AB02_53F46DC9D446__INCLUDED_)
#define AFX_GETMACDLG_H__0DE08180_C0C7_4FBE_AB02_53F46DC9D446__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetMACDlg dialog

class CGetMACDlg : public CDialog
{
// Construction
public:
	CGetMACDlg(CWnd* pParent = NULL);	// standard constructor
	
// Dialog Data
	//{{AFX_DATA(CGetMACDlg)
	enum { IDD = IDD_GETMAC_DIALOG };
	CEdit	m_edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetMACDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetMACDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButmac();
	afx_msg void OnButexit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETMACDLG_H__0DE08180_C0C7_4FBE_AB02_53F46DC9D446__INCLUDED_)
