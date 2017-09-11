// StartXPDlg.h : header file
//

#if !defined(AFX_STARTXPDLG_H__683047A2_4977_4456_8D7E_D5EFD9BACC2D__INCLUDED_)
#define AFX_STARTXPDLG_H__683047A2_4977_4456_8D7E_D5EFD9BACC2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStartXPDlg dialog

class CStartXPDlg : public CDialog
{
// Construction
public:
	CStartXPDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CStartXPDlg)
	enum { IDD = IDD_STARTXP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStartXPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStartXPDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnMove();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STARTXPDLG_H__683047A2_4977_4456_8D7E_D5EFD9BACC2D__INCLUDED_)
