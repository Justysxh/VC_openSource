// HideDesktopDlg.h : header file
//

#if !defined(AFX_HIDEDESKTOPDLG_H__400700C0_1BD8_4E0E_B9D6_207E7F65F712__INCLUDED_)
#define AFX_HIDEDESKTOPDLG_H__400700C0_1BD8_4E0E_B9D6_207E7F65F712__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHideDesktopDlg dialog

class CHideDesktopDlg : public CDialog
{
// Construction
public:
	CHideDesktopDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHideDesktopDlg)
	enum { IDD = IDD_HIDEDESKTOP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHideDesktopDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHideDesktopDlg)
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

#endif // !defined(AFX_HIDEDESKTOPDLG_H__400700C0_1BD8_4E0E_B9D6_207E7F65F712__INCLUDED_)
