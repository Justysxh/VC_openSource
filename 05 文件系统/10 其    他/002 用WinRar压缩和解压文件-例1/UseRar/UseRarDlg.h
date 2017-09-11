// UseRarDlg.h : header file
//

#if !defined(AFX_USERARDLG_H__06A970F1_AFC5_4F12_BFC4_D3D47F175282__INCLUDED_)
#define AFX_USERARDLG_H__06A970F1_AFC5_4F12_BFC4_D3D47F175282__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUseRarDlg dialog

class CUseRarDlg : public CDialog
{
// Construction
public:
	CUseRarDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUseRarDlg)
	enum { IDD = IDD_USERAR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseRarDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUseRarDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnUnZip();
	afx_msg void OnView();
	afx_msg void OnZip();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERARDLG_H__06A970F1_AFC5_4F12_BFC4_D3D47F175282__INCLUDED_)
