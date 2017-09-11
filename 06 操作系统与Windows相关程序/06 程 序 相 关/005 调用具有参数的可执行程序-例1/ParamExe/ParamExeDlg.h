// ParamExeDlg.h : header file
//

#if !defined(AFX_PARAMEXEDLG_H__3D054956_72CC_44CE_851A_BAAF712DF78D__INCLUDED_)
#define AFX_PARAMEXEDLG_H__3D054956_72CC_44CE_851A_BAAF712DF78D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CParamExeDlg dialog

class CParamExeDlg : public CDialog
{
// Construction
public:
	CParamExeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CParamExeDlg)
	enum { IDD = IDD_PARAMEXE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CParamExeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CParamExeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnBackup();
	afx_msg void OnDetatch();
	afx_msg void OnStopserver();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARAMEXEDLG_H__3D054956_72CC_44CE_851A_BAAF712DF78D__INCLUDED_)
