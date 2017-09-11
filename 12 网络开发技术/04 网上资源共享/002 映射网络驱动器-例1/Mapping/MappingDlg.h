// MappingDlg.h : header file
//

#if !defined(AFX_MAPPINGDLG_H__9A4C754D_E57D_4154_9D4E_540126744712__INCLUDED_)
#define AFX_MAPPINGDLG_H__9A4C754D_E57D_4154_9D4E_540126744712__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMappingDlg dialog

class CMappingDlg : public CDialog
{
// Construction
public:
	CMappingDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMappingDlg)
	enum { IDD = IDD_MAPPING_DIALOG };
	CString	m_drive;
	CString	m_path;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMappingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMappingDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButjoin();
	afx_msg void OnButexit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPPINGDLG_H__9A4C754D_E57D_4154_9D4E_540126744712__INCLUDED_)
