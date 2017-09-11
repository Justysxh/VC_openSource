// HideDriverDlg.h : header file
//

#if !defined(AFX_HIDEDRIVERDLG_H__E6A47BC1_AA35_40CC_B287_8BC74D3588B1__INCLUDED_)
#define AFX_HIDEDRIVERDLG_H__E6A47BC1_AA35_40CC_B287_8BC74D3588B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHideDriverDlg dialog

class CHideDriverDlg : public CDialog
{
// Construction
public:
	CHideDriverDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHideDriverDlg)
	enum { IDD = IDD_HIDEDRIVER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHideDriverDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHideDriverDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHide();
	afx_msg void OnShow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIDEDRIVERDLG_H__E6A47BC1_AA35_40CC_B287_8BC74D3588B1__INCLUDED_)
