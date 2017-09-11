// DriverAttriDlg.h : header file
//

#if !defined(AFX_DRIVERATTRIDLG_H__9CD6E73A_C0AB_4A90_B325_FB5C5A4B7860__INCLUDED_)
#define AFX_DRIVERATTRIDLG_H__9CD6E73A_C0AB_4A90_B325_FB5C5A4B7860__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDriverAttriDlg dialog

class CDriverAttriDlg : public CDialog
{
// Construction
public:
	CDriverAttriDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDriverAttriDlg)
	enum { IDD = IDD_DRIVERATTRI_DIALOG };
	CStatic	m_type;
	CComboBox	m_drivercomb;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDriverAttriDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDriverAttriDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeDrivercomb();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRIVERATTRIDLG_H__9CD6E73A_C0AB_4A90_B325_FB5C5A4B7860__INCLUDED_)
