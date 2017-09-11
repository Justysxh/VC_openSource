// IECaptionDlg.h : header file
//

#if !defined(AFX_IECAPTIONDLG_H__C974043E_2F34_4B52_A90E_51CD2413427B__INCLUDED_)
#define AFX_IECAPTIONDLG_H__C974043E_2F34_4B52_A90E_51CD2413427B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CIECaptionDlg dialog

class CIECaptionDlg : public CDialog
{
// Construction
public:
	CIECaptionDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CIECaptionDlg)
	enum { IDD = IDD_IECAPTION_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIECaptionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CIECaptionDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSet();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IECAPTIONDLG_H__C974043E_2F34_4B52_A90E_51CD2413427B__INCLUDED_)
