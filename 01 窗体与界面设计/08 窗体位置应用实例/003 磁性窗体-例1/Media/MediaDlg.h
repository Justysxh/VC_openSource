// MediaDlg.h : header file
//

#if !defined(AFX_MEDIADLG_H__371E6D68_C49B_44AC_898C_14C86C7F8C24__INCLUDED_)
#define AFX_MEDIADLG_H__371E6D68_C49B_44AC_898C_14C86C7F8C24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMediaDlg dialog

class CMediaDlg : public CDialog
{
// Construction
public:
	CMediaDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMediaDlg)
	enum { IDD = IDD_MEDIA_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMediaDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMediaDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg UINT OnNcHitTest(CPoint point);
	afx_msg void OnQuit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEDIADLG_H__371E6D68_C49B_44AC_898C_14C86C7F8C24__INCLUDED_)
