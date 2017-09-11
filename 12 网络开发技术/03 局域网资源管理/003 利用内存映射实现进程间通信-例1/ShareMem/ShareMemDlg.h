// ShareMemDlg.h : header file
//

#if !defined(AFX_SHAREMEMDLG_H__1C996B65_9EDA_4A9E_B99F_5D57CAA551B4__INCLUDED_)
#define AFX_SHAREMEMDLG_H__1C996B65_9EDA_4A9E_B99F_5D57CAA551B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CShareMemDlg dialog

class CShareMemDlg : public CDialog
{
// Construction
public:
	CShareMemDlg(CWnd* pParent = NULL);	// standard constructor
	
	HANDLE m_hShareMem;
	void*  m_pViewData;

// Dialog Data
	//{{AFX_DATA(CShareMemDlg)
	enum { IDD = IDD_SHAREMEM_DIALOG };
	CEdit	m_Write;
	CEdit	m_Read;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShareMemDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CShareMemDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnWrite();
	afx_msg void OnRead();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHAREMEMDLG_H__1C996B65_9EDA_4A9E_B99F_5D57CAA551B4__INCLUDED_)
