// KeyboardNumLampDlg.h : header file
//

#if !defined(AFX_KEYBOARDNUMLAMPDLG_H__F01BA22E_3F9D_41A3_96BD_A0A80C45B0F1__INCLUDED_)
#define AFX_KEYBOARDNUMLAMPDLG_H__F01BA22E_3F9D_41A3_96BD_A0A80C45B0F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CKeyboardNumLampDlg dialog

class CKeyboardNumLampDlg : public CDialog
{
// Construction
public:
	CKeyboardNumLampDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CKeyboardNumLampDlg)
	enum { IDD = IDD_KEYBOARDNUMLAMP_DIALOG };
	CButton	m_scroll;
	CButton	m_num;
	CButton	m_cap;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyboardNumLampDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CKeyboardNumLampDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnNumLock();
	afx_msg void OnCapLock();
	afx_msg void OnScrollLock();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYBOARDNUMLAMPDLG_H__F01BA22E_3F9D_41A3_96BD_A0A80C45B0F1__INCLUDED_)
