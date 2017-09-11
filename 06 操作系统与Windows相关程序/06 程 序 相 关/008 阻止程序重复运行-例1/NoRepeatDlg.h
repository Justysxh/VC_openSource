// NoRepeatDlg.h : header file
//

#if !defined(AFX_NOREPEATDLG_H__739B39C9_0A91_4D24_AE2C_58FF7FEDF5EF__INCLUDED_)
#define AFX_NOREPEATDLG_H__739B39C9_0A91_4D24_AE2C_58FF7FEDF5EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNoRepeatDlg dialog

class CNoRepeatDlg : public CDialog
{
// Construction
public:
	CNoRepeatDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNoRepeatDlg)
	enum { IDD = IDD_NOREPEAT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoRepeatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNoRepeatDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOREPEATDLG_H__739B39C9_0A91_4D24_AE2C_58FF7FEDF5EF__INCLUDED_)
