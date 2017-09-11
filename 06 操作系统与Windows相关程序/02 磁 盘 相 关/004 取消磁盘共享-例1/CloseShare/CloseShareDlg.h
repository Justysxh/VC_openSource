// CloseShareDlg.h : header file
//

#if !defined(AFX_CLOSESHAREDLG_H__7D98F1A5_8B35_412E_AA2B_30EAAAA9BE22__INCLUDED_)
#define AFX_CLOSESHAREDLG_H__7D98F1A5_8B35_412E_AA2B_30EAAAA9BE22__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCloseShareDlg dialog

class CCloseShareDlg : public CDialog
{
// Construction
public:
	CCloseShareDlg(CWnd* pParent = NULL);	// standard constructor
	CString strsel;
// Dialog Data
	//{{AFX_DATA(CCloseShareDlg)
	enum { IDD = IDD_CLOSESHARE_DIALOG };
	CComboBox	m_drivercomb;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCloseShareDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCloseShareDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCloseShare();
	afx_msg void OnSelchangeCmbdriver();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLOSESHAREDLG_H__7D98F1A5_8B35_412E_AA2B_30EAAAA9BE22__INCLUDED_)
