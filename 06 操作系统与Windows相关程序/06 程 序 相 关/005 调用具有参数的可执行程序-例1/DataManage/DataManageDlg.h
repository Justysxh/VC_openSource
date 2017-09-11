// DataManageDlg.h : header file
//

#if !defined(AFX_DATAMANAGEDLG_H__3705B166_6D6E_42CB_8DA0_3A3FBA080B26__INCLUDED_)
#define AFX_DATAMANAGEDLG_H__3705B166_6D6E_42CB_8DA0_3A3FBA080B26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDataManageDlg dialog

class CDataManageDlg : public CDialog
{
// Construction
public:
	CDataManageDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDataManageDlg)
	enum { IDD = IDD_DATAMANAGE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataManageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDataManageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATAMANAGEDLG_H__3705B166_6D6E_42CB_8DA0_3A3FBA080B26__INCLUDED_)
