// RegSoftDlg.h : header file
//

#if !defined(AFX_REGSOFTDLG_H__CD77D1CB_79FA_4416_BD1E_C44726B928E4__INCLUDED_)
#define AFX_REGSOFTDLG_H__CD77D1CB_79FA_4416_BD1E_C44726B928E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRegSoftDlg dialog

class CRegSoftDlg : public CDialog
{
// Construction
public:
	CRegSoftDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRegSoftDlg)
	enum { IDD = IDD_REGSOFT_DIALOG };
	CStatic	m_spare;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegSoftDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRegSoftDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGSOFTDLG_H__CD77D1CB_79FA_4416_BD1E_C44726B928E4__INCLUDED_)
