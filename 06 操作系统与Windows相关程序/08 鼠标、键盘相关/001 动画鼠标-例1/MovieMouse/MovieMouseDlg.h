// MovieMouseDlg.h : header file
//

#if !defined(AFX_MOVIEMOUSEDLG_H__F7B975D9_029D_429E_A619_1EC360A06D9D__INCLUDED_)
#define AFX_MOVIEMOUSEDLG_H__F7B975D9_029D_429E_A619_1EC360A06D9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMovieMouseDlg dialog

class CMovieMouseDlg : public CDialog
{
// Construction
public:
	CMovieMouseDlg(CWnd* pParent = NULL);	// standard constructor
	HCURSOR m_mycursor;
	HCURSOR m_oldcursor;
// Dialog Data
	//{{AFX_DATA(CMovieMouseDlg)
	enum { IDD = IDD_MOVIEMOUSE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMovieMouseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMovieMouseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtmouse();
	afx_msg void OnBtre();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOVIEMOUSEDLG_H__F7B975D9_029D_429E_A619_1EC360A06D9D__INCLUDED_)
