// BuildAviDlg.h : header file
//

#if !defined(AFX_BUILDAVIDLG_H__D4CF5375_7F0F_4940_AC65_12F95774C852__INCLUDED_)
#define AFX_BUILDAVIDLG_H__D4CF5375_7F0F_4940_AC65_12F95774C852__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBuildAviDlg dialog

class CBuildAviDlg : public CDialog
{
// Construction
public:
	void BmpsToAvi(LPCSTR szFileName, LPCSTR szDir);
	CBuildAviDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBuildAviDlg)
	enum { IDD = IDD_BUILDAVI_DIALOG };
	CEdit	m_BmpDir;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBuildAviDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBuildAviDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUILDAVIDLG_H__D4CF5375_7F0F_4940_AC65_12F95774C852__INCLUDED_)
