// NameAndIPDlg.h : header file
//

#if !defined(AFX_NAMEANDIPDLG_H__03AE8A3A_A1C5_4C08_93B8_9A47F8F525F1__INCLUDED_)
#define AFX_NAMEANDIPDLG_H__03AE8A3A_A1C5_4C08_93B8_9A47F8F525F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNameAndIPDlg dialog

class CNameAndIPDlg : public CDialog
{
// Construction
public:
	CNameAndIPDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNameAndIPDlg)
	enum { IDD = IDD_NAMEANDIP_DIALOG };
	CListCtrl	m_grid;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNameAndIPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNameAndIPDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NAMEANDIPDLG_H__03AE8A3A_A1C5_4C08_93B8_9A47F8F525F1__INCLUDED_)
