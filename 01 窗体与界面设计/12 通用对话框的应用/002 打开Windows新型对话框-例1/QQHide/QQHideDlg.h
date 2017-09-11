// QQHideDlg.h : header file
//

#if !defined(AFX_QQHIDEDLG_H__86B22F8D_39C7_4F44_976E_5785A0BCA153__INCLUDED_)
#define AFX_QQHIDEDLG_H__86B22F8D_39C7_4F44_976E_5785A0BCA153__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CQQHideDlg dialog

class CQQHideDlg : public CDialog
{
// Construction
public:
	CQQHideDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CQQHideDlg)
	enum { IDD = IDD_QQHIDE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQQHideDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CQQHideDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QQHIDEDLG_H__86B22F8D_39C7_4F44_976E_5785A0BCA153__INCLUDED_)
