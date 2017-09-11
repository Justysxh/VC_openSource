// SetCursorDlg.h : header file
//

#if !defined(AFX_SETCURSORDLG_H__9CD53551_6E2A_4906_8AE1_16B5C525B687__INCLUDED_)
#define AFX_SETCURSORDLG_H__9CD53551_6E2A_4906_8AE1_16B5C525B687__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSetCursorDlg dialog

class CSetCursorDlg : public CDialog
{
// Construction
public:
	HCURSOR m_hCursor;
	bool isDefault;
	CSetCursorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSetCursorDlg)
	enum { IDD = IDD_SETCURSOR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetCursorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSetCursorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnChangeCursor();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETCURSORDLG_H__9CD53551_6E2A_4906_8AE1_16B5C525B687__INCLUDED_)
