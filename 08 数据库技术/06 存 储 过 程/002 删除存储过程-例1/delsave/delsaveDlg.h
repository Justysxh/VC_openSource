// delsaveDlg.h : header file
//

#if !defined(AFX_DELSAVEDLG_H__36DBF476_50C2_4F84_A268_A4BEB8065081__INCLUDED_)
#define AFX_DELSAVEDLG_H__36DBF476_50C2_4F84_A268_A4BEB8065081__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDelsaveDlg dialog

class CDelsaveDlg : public CDialog
{
// Construction
public:
	CDelsaveDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDelsaveDlg)
	enum { IDD = IDD_DELSAVE_DIALOG };
	CString	m_edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDelsaveDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDelsaveDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELSAVEDLG_H__36DBF476_50C2_4F84_A268_A4BEB8065081__INCLUDED_)
