// EnumServerDlg.h : header file
//

#if !defined(AFX_ENUMSERVERDLG_H__8F1D0439_EBD6_488D_8BF7_DA3930FE3008__INCLUDED_)
#define AFX_ENUMSERVERDLG_H__8F1D0439_EBD6_488D_8BF7_DA3930FE3008__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEnumServerDlg dialog

class CEnumServerDlg : public CDialog
{
// Construction
public:
	void FormatString(CString sText, CListBox *pListBox);
	CString GetServer();
	CEnumServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEnumServerDlg)
	enum { IDD = IDD_ENUMSERVER_DIALOG };
	CListBox	m_Server;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnumServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEnumServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENUMSERVERDLG_H__8F1D0439_EBD6_488D_8BF7_DA3930FE3008__INCLUDED_)
