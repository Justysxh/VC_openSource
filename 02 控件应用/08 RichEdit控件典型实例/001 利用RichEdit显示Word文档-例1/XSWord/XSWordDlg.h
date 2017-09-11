// XSWordDlg.h : header file
//

#if !defined(AFX_XSWORDDLG_H__14864FC6_52DB_49CE_8174_D0AC178F6964__INCLUDED_)
#define AFX_XSWORDDLG_H__14864FC6_52DB_49CE_8174_D0AC178F6964__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CXSWordDlg dialog

class CXSWordDlg : public CDialog
{
// Construction
public:
	CString strText;
	CXSWordDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CXSWordDlg)
	enum { IDD = IDD_XSWORD_DIALOG };
	CRichEditCtrl	m_rich;
	CEdit	m_edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXSWordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CXSWordDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButxs();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XSWORDDLG_H__14864FC6_52DB_49CE_8174_D0AC178F6964__INCLUDED_)
