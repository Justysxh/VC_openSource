// CPUAndDiskRegDlg.h : header file
//

#if !defined(AFX_CPUANDDISKREGDLG_H__1C4C65B1_F5A5_42C3_B193_BD0102B66A27__INCLUDED_)
#define AFX_CPUANDDISKREGDLG_H__1C4C65B1_F5A5_42C3_B193_BD0102B66A27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCPUAndDiskRegDlg dialog

class CCPUAndDiskRegDlg : public CDialog
{
// Construction
public:
	CCPUAndDiskRegDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCPUAndDiskRegDlg)
	enum { IDD = IDD_CPUANDDISKREG_DIALOG };
	CStatic	m_machine;
	CStatic	m_cdisk;
	CStatic	m_cpu;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCPUAndDiskRegDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCPUAndDiskRegDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnReg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CPUANDDISKREGDLG_H__1C4C65B1_F5A5_42C3_B193_BD0102B66A27__INCLUDED_)
