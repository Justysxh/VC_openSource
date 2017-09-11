// DonghuaDlg.h : header file
//

#if !defined(AFX_DONGHUADLG_H__CE3B27D7_1D17_409A_93EC_ABF30E52D1A6__INCLUDED_)
#define AFX_DONGHUADLG_H__CE3B27D7_1D17_409A_93EC_ABF30E52D1A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDonghuaDlg dialog

class CDonghuaDlg : public CDialog
{
// Construction
public:
	CDonghuaDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDonghuaDlg)
	enum { IDD = IDD_DONGHUA_DIALOG };
	CString	m_edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDonghuaDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDonghuaDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DONGHUADLG_H__CE3B27D7_1D17_409A_93EC_ABF30E52D1A6__INCLUDED_)
