// GetPropDlg.h : header file
//

#if !defined(AFX_GETPROPDLG_H__2118A09E_7D71_492D_BFB5_4E3F7028E46F__INCLUDED_)
#define AFX_GETPROPDLG_H__2118A09E_7D71_492D_BFB5_4E3F7028E46F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetPropDlg dialog

class CGetPropDlg : public CDialog
{
// Construction
public:
	CGetPropDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetPropDlg)
	enum { IDD = IDD_GETPROP_DIALOG };
	CListCtrl	m_PropertyList;
	CString	m_FileName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetPropDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetPropDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnProperty();
	afx_msg void OnBrown();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETPROPDLG_H__2118A09E_7D71_492D_BFB5_4E3F7028E46F__INCLUDED_)
