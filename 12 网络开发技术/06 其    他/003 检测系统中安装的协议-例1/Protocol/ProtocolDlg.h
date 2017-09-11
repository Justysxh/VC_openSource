// ProtocolDlg.h : header file
//

#if !defined(AFX_PROTOCOLDLG_H__C8500E57_9161_47D4_8617_E21A50F1EF4D__INCLUDED_)
#define AFX_PROTOCOLDLG_H__C8500E57_9161_47D4_8617_E21A50F1EF4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CProtocolDlg dialog

class CProtocolDlg : public CDialog
{
// Construction
public:
	CProtocolDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CProtocolDlg)
	enum { IDD = IDD_PROTOCOL_DIALOG };
	CListCtrl	m_Grid;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProtocolDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CProtocolDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButenumerate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROTOCOLDLG_H__C8500E57_9161_47D4_8617_E21A50F1EF4D__INCLUDED_)
