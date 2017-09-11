// OvertimeDlg.h : header file
//

#if !defined(AFX_OVERTIMEDLG_H__7CEC08A0_BAD1_47A7_8CCD_62F86096B458__INCLUDED_)
#define AFX_OVERTIMEDLG_H__7CEC08A0_BAD1_47A7_8CCD_62F86096B458__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COvertimeDlg dialog

class COvertimeDlg : public CDialog
{
// Construction
public:
	COvertimeDlg(CWnd* pParent = NULL);	// standard constructor
	CImageList m_ImageList;
	CMenu Menu;
	CToolTipCtrl m_ToolTip;
	CString STR;
// Dialog Data
	//{{AFX_DATA(COvertimeDlg)
	enum { IDD = IDD_OVERTIME_DIALOG };
	CButton	m_close;
	CButton	m_ok;
	CStatic	m_Time;
	CListCtrl	m_Jbyg;
	CListCtrl	m_Gsyg;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COvertimeDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COvertimeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnMenuclear();
	afx_msg void OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OVERTIMEDLG_H__7CEC08A0_BAD1_47A7_8CCD_62F86096B458__INCLUDED_)
