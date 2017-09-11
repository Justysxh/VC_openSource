// GetIPDlg.h : header file
//

#if !defined(AFX_GETIPDLG_H__7D2F4462_52DD_49F5_9757_18E77ACEB859__INCLUDED_)
#define AFX_GETIPDLG_H__7D2F4462_52DD_49F5_9757_18E77ACEB859__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetIPDlg dialog

class CGetIPDlg : public CDialog
{
// Construction
public:
	CGetIPDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetIPDlg)
	enum { IDD = IDD_GETIP_DIALOG };
	CIPAddressCtrl	m_ip;
	CEdit	m_name;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetIPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetIPDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButok();
	afx_msg void OnButexit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETIPDLG_H__7D2F4462_52DD_49F5_9757_18E77ACEB859__INCLUDED_)
