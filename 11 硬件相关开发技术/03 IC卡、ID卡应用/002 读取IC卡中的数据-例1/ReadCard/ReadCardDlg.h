// ReadCardDlg.h : header file
//

#if !defined(AFX_READCARDDLG_H__170A5BB1_8BB1_4D2C_8432_F52463EA28AC__INCLUDED_)
#define AFX_READCARDDLG_H__170A5BB1_8BB1_4D2C_8432_F52463EA28AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CReadCardDlg dialog

class CReadCardDlg : public CDialog
{
// Construction
public:
	CReadCardDlg(CWnd* pParent = NULL);	// standard constructor
	
	HANDLE icdev;
// Dialog Data
	//{{AFX_DATA(CReadCardDlg)
	enum { IDD = IDD_READCARD_DIALOG };
	CEdit	m_Data;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReadCardDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CReadCardDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCancel();
	afx_msg void OnRead();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READCARDDLG_H__170A5BB1_8BB1_4D2C_8432_F52463EA28AC__INCLUDED_)
