// ChangeDisktopDlg.h : header file
//

#if !defined(AFX_CHANGEDISKTOPDLG_H__A9D84AE0_0D35_4984_BCB3_B5170E80DD11__INCLUDED_)
#define AFX_CHANGEDISKTOPDLG_H__A9D84AE0_0D35_4984_BCB3_B5170E80DD11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChangeDisktopDlg dialog

class CChangeDisktopDlg : public CDialog
{
// Construction
public:
	CChangeDisktopDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CChangeDisktopDlg)
	enum { IDD = IDD_CHANGEDISKTOP_DIALOG };
	CListBox	m_list;
	CEdit	m_edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeDisktopDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChangeDisktopDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnLoad();
	afx_msg void Onrand();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGEDISKTOPDLG_H__A9D84AE0_0D35_4984_BCB3_B5170E80DD11__INCLUDED_)
