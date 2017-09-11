// PrintImageDlg.h : header file
//

#if !defined(AFX_PRINTIMAGEDLG_H__B3CD041A_FCE3_4C82_94E9_2A848ECBDF30__INCLUDED_)
#define AFX_PRINTIMAGEDLG_H__B3CD041A_FCE3_4C82_94E9_2A848ECBDF30__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPrintImageDlg dialog

class CPrintImageDlg : public CDialog
{
// Construction
public:
	CPrintImageDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPrintImageDlg)
	enum { IDD = IDD_PRINTIMAGE_DIALOG };
	CStatic	m_image;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintImageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPrintImageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButtonprint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTIMAGEDLG_H__B3CD041A_FCE3_4C82_94E9_2A848ECBDF30__INCLUDED_)
