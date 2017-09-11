// PrintBearingDlg.h : header file
//

#if !defined(AFX_PRINTBEARINGDLG_H__CCD6B05C_3DF1_4B6E_827B_8BEAC6D26F32__INCLUDED_)
#define AFX_PRINTBEARINGDLG_H__CCD6B05C_3DF1_4B6E_827B_8BEAC6D26F32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPrintBearingDlg dialog

class CPrintBearingDlg : public CDialog
{
// Construction
public:
	CPrintBearingDlg(CWnd* pParent = NULL);	// standard constructor
	CString merchandise[4][5];
	CFont titlefont,bodyfont;
	int screenx,screeny;
// Dialog Data
	//{{AFX_DATA(CPrintBearingDlg)
	enum { IDD = IDD_PRINTBEARING_DIALOG };
	CStatic	m_frame;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintBearingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPrintBearingDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButprint();
	afx_msg void OnButexit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTBEARINGDLG_H__CCD6B05C_3DF1_4B6E_827B_8BEAC6D26F32__INCLUDED_)
