// envelopprintDlg.h : header file
//

#if !defined(AFX_ENVELOPPRINTDLG_H__2B646739_A668_446F_8078_9BD10F7E0F34__INCLUDED_)
#define AFX_ENVELOPPRINTDLG_H__2B646739_A668_446F_8078_9BD10F7E0F34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEnvelopprintDlg dialog

class CEnvelopprintDlg : public CDialog
{
// Construction
public:
	CEnvelopprintDlg(CWnd* pParent = NULL);	// standard constructor

	CString sxr;
	CString dz;
	CString yb;
// Dialog Data
	//{{AFX_DATA(CEnvelopprintDlg)
	enum { IDD = IDD_ENVELOPPRINT_DIALOG };
	CListCtrl	m_grid;
	CString	m_edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnvelopprintDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEnvelopprintDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButpreview();
	afx_msg void OnButprint();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENVELOPPRINTDLG_H__2B646739_A668_446F_8078_9BD10F7E0F34__INCLUDED_)
