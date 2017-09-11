// DrawBezierDlg.h : header file
//

#if !defined(AFX_DRAWBEZIERDLG_H__0BF113CA_54D2_4406_84D9_0794BDD3E879__INCLUDED_)
#define AFX_DRAWBEZIERDLG_H__0BF113CA_54D2_4406_84D9_0794BDD3E879__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDrawBezierDlg dialog

class CDrawBezierDlg : public CDialog
{
// Construction
public:
	CDrawBezierDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDrawBezierDlg)
	enum { IDD = IDD_DRAWBEZIER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawBezierDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDrawBezierDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWBEZIERDLG_H__0BF113CA_54D2_4406_84D9_0794BDD3E879__INCLUDED_)
