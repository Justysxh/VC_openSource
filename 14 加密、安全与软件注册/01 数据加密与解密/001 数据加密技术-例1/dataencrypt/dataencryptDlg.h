// dataencryptDlg.h : header file
//

#if !defined(AFX_DATAENCRYPTDLG_H__9ACCD926_7DF1_43C4_805F_463A1BF312C8__INCLUDED_)
#define AFX_DATAENCRYPTDLG_H__9ACCD926_7DF1_43C4_805F_463A1BF312C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDataencryptDlg dialog

class CDataencryptDlg : public CDialog
{
// Construction
public:
	static CString Decrypt(CString S,WORD K);
	static CString Encrypt(CString S,WORD K);
	CDataencryptDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDataencryptDlg)
	enum { IDD = IDD_DATAENCRYPT_DIALOG };
	CString	m_edit2;
	CString	m_edit3;
	int		m_edit1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataencryptDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDataencryptDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATAENCRYPTDLG_H__9ACCD926_7DF1_43C4_805F_463A1BF312C8__INCLUDED_)
