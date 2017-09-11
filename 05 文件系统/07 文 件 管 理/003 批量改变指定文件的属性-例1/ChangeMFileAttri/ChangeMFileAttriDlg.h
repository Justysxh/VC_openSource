// ChangeMFileAttriDlg.h : header file
//

#if !defined(AFX_CHANGEMFILEATTRIDLG_H__ADC7E646_6862_4D42_BA14_F7A591D43E65__INCLUDED_)
#define AFX_CHANGEMFILEATTRIDLG_H__ADC7E646_6862_4D42_BA14_F7A591D43E65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChangeMFileAttriDlg dialog

class CChangeMFileAttriDlg : public CDialog
{
// Construction
public:
	CChangeMFileAttriDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CChangeMFileAttriDlg)
	enum { IDD = IDD_CHANGEMFILEATTRI_DIALOG };
	CButton	m_chsystem;
	CButton	m_chreadonly;
	CButton	m_chhide;
	CListCtrl	m_filelist;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeMFileAttriDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChangeMFileAttriDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddFile();
	afx_msg void OnSetFile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGEMFILEATTRIDLG_H__ADC7E646_6862_4D42_BA14_F7A591D43E65__INCLUDED_)
