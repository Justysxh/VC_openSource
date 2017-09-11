// SliderDlg.h : header file
//

#if !defined(AFX_SLIDERDLG_H__239403D2_11CF_4832_928B_84E70D07279B__INCLUDED_)
#define AFX_SLIDERDLG_H__239403D2_11CF_4832_928B_84E70D07279B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSliderDlg dialog

class CSliderDlg : public CDialog
{
// Construction
public:
	void DrawColor();
	CSliderDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSliderDlg)
	enum { IDD = IDD_SLIDER_DIALOG };
	CStatic	m_Color;
	CSliderCtrl	m_Blue;
	CSliderCtrl	m_Green;
	CSliderCtrl	m_Red;
	int		m_bEdit;
	int		m_gEdit;
	int		m_rEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSliderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSliderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnReleasedcaptureSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnReleasedcaptureSlider2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnReleasedcaptureSlider3(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SLIDERDLG_H__239403D2_11CF_4832_928B_84E70D07279B__INCLUDED_)
