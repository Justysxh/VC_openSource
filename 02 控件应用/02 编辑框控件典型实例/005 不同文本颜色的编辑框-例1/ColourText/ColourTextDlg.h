// ColourTextDlg.h : header file
//

#if !defined(AFX_COLOURTEXTDLG_H__741ABF1E_2458_4649_8777_5696537D4662__INCLUDED_)
#define AFX_COLOURTEXTDLG_H__741ABF1E_2458_4649_8777_5696537D4662__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CColourTextDlg dialog

class CColourTextDlg : public CDialog
{
// Construction
public:
	CColourTextDlg(CWnd* pParent = NULL);	// standard constructor
	COLORREF colour;
// Dialog Data
	//{{AFX_DATA(CColourTextDlg)
	enum { IDD = IDD_COLOURTEXT_DIALOG };
	CEdit	m_edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColourTextDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CColourTextDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnRed();
	afx_msg void OnBlue();
	afx_msg void OnGreen();
	afx_msg void OnYellow();
	afx_msg void OnAmethyst();
	afx_msg void OnCyan();
	afx_msg void OnBlack();
	afx_msg void OnGray();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLOURTEXTDLG_H__741ABF1E_2458_4649_8777_5696537D4662__INCLUDED_)
