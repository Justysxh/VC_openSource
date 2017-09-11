// HuodeDKDlg.h : header file
//

#if !defined(AFX_HUODEDKDLG_H__2FED8F74_88FB_4099_A102_AF1152618A72__INCLUDED_)
#define AFX_HUODEDKDLG_H__2FED8F74_88FB_4099_A102_AF1152618A72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHuodeDKDlg dialog

class CHuodeDKDlg : public CDialog
{
// Construction
public:
	CHuodeDKDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHuodeDKDlg)
	enum { IDD = IDD_HUODEDK_DIALOG };
	CRichEditCtrl	m_richedit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHuodeDKDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHuodeDKDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnInspect();
	afx_msg void OnButexit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HUODEDKDLG_H__2FED8F74_88FB_4099_A102_AF1152618A72__INCLUDED_)
