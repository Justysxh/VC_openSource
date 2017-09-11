// KeyboardHookDlg.h : header file
//

#if !defined(AFX_KEYBOARDHOOKDLG_H__DB56130A_B9FD_4943_9C92_6A147B06DCA5__INCLUDED_)
#define AFX_KEYBOARDHOOKDLG_H__DB56130A_B9FD_4943_9C92_6A147B06DCA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CKeyboardHookDlg dialog

class CKeyboardHookDlg : public CDialog
{
// Construction
public:
	CKeyboardHookDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CKeyboardHookDlg)
	enum { IDD = IDD_KEYBOARDHOOK_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyboardHookDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CKeyboardHookDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYBOARDHOOKDLG_H__DB56130A_B9FD_4943_9C92_6A147B06DCA5__INCLUDED_)
