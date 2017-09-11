// WordToTxtDlg.h : header file
//

#if !defined(AFX_WORDTOTXTDLG_H__6C637E90_FE97_4CD4_B67F_3C9281E6D1D2__INCLUDED_)
#define AFX_WORDTOTXTDLG_H__6C637E90_FE97_4CD4_B67F_3C9281E6D1D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWordToTxtDlg dialog

class CWordToTxtDlg : public CDialog
{
// Construction
public:
	CWordToTxtDlg(CWnd* pParent = NULL);	// standard constructor
	CString GetFileExt(CString filepath);
// Dialog Data
	//{{AFX_DATA(CWordToTxtDlg)
	enum { IDD = IDD_WORDTOTXT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordToTxtDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWordToTxtDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConvert();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORDTOTXTDLG_H__6C637E90_FE97_4CD4_B67F_3C9281E6D1D2__INCLUDED_)
