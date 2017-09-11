// NetworkListDlg.h : header file
//

#if !defined(AFX_NETWORKLISTDLG_H__8FF17641_0171_48DE_8FFA_3F8B1AB50A51__INCLUDED_)
#define AFX_NETWORKLISTDLG_H__8FF17641_0171_48DE_8FFA_3F8B1AB50A51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNetworkListDlg dialog

class CNetworkListDlg : public CDialog
{
// Construction
public:
	CNetworkListDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNetworkListDlg)
	enum { IDD = IDD_NETWORKLIST_DIALOG };
	CListBox	m_List;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetworkListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNetworkListDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETWORKLISTDLG_H__8FF17641_0171_48DE_8FFA_3F8B1AB50A51__INCLUDED_)
