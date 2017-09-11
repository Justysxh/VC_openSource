// BKydctDlg.h : header file
//

#if !defined(AFX_BKYDCTDLG_H__DEE9E2F3_080B_4EAC_94C2_1865253F4EFA__INCLUDED_)
#define AFX_BKYDCTDLG_H__DEE9E2F3_080B_4EAC_94C2_1865253F4EFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBKydctDlg dialog

class CBKydctDlg : public CDialog
{
// Construction
public:
	CBKydctDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBKydctDlg)
	enum { IDD = IDD_BKYDCT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBKydctDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBKydctDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BKYDCTDLG_H__DEE9E2F3_080B_4EAC_94C2_1865253F4EFA__INCLUDED_)
