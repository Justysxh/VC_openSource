// FormatDriverDlg.h : header file
//

#if !defined(AFX_FORMATDRIVERDLG_H__3E4CFF7F_126E_4B58_A694_80F0C6690467__INCLUDED_)
#define AFX_FORMATDRIVERDLG_H__3E4CFF7F_126E_4B58_A694_80F0C6690467__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFormatDriverDlg dialog

class CFormatDriverDlg : public CDialog
{
// Construction
public:
	CFormatDriverDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFormatDriverDlg)
	enum { IDD = IDD_FORMATDRIVER_DIALOG };
	CComboBox	m_driver;
	int isel;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFormatDriverDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFormatDriverDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFormat();
	afx_msg void OnSelchangeDriver();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FORMATDRIVERDLG_H__3E4CFF7F_126E_4B58_A694_80F0C6690467__INCLUDED_)
