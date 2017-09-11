// UseTabDlg.h : header file
//

#if !defined(AFX_USETABDLG_H__DFB0FCA3_3025_4A71_96B4_E958CDB1C077__INCLUDED_)
#define AFX_USETABDLG_H__DFB0FCA3_3025_4A71_96B4_E958CDB1C077__INCLUDED_
#include "Employee.h"
#include "Client.h"
#include "Providedlg.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUseTabDlg dialog

class CUseTabDlg : public CDialog
{
// Construction
public:
	CUseTabDlg(CWnd* pParent = NULL);	// standard constructor
	CImageList  m_ImageList;
	CEmployee*   m_eDlg;
	CClient*     m_cDlg;
	CProvidedlg* m_pDlg;
// Dialog Data
	//{{AFX_DATA(CUseTabDlg)
	enum { IDD = IDD_USETAB_DIALOG };
	CTabCtrl	m_Tab;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseTabDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUseTabDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USETABDLG_H__DFB0FCA3_3025_4A71_96B4_E958CDB1C077__INCLUDED_)
