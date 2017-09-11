// NetMACRegDlg.h : header file
//

#if !defined(AFX_NETMACREGDLG_H__C0381C1C_1D50_4FA8_85E3_FD11B7E576DB__INCLUDED_)
#define AFX_NETMACREGDLG_H__C0381C1C_1D50_4FA8_85E3_FD11B7E576DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNetMACRegDlg dialog

class CNetMACRegDlg : public CDialog
{
// Construction
public:
	CNetMACRegDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNetMACRegDlg)
	enum { IDD = IDD_NETMACREG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetMACRegDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNetMACRegDlg)
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

#endif // !defined(AFX_NETMACREGDLG_H__C0381C1C_1D50_4FA8_85E3_FD11B7E576DB__INCLUDED_)
