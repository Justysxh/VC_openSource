// ReverseColorDlg.h : header file
//

#if !defined(AFX_REVERSECOLORDLG_H__1E7B375B_B08D_4237_A710_63D0DD91877F__INCLUDED_)
#define AFX_REVERSECOLORDLG_H__1E7B375B_B08D_4237_A710_63D0DD91877F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CReverseColorDlg dialog

class CReverseColorDlg : public CDialog
{
// Construction
public:
	CReverseColorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CReverseColorDlg)
	enum { IDD = IDD_REVERSECOLOR_DIALOG };
	CStatic	m_image;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReverseColorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CReverseColorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REVERSECOLORDLG_H__1E7B375B_B08D_4237_A710_63D0DD91877F__INCLUDED_)
