// MoveFIleDlg.h : header file
//

#if !defined(AFX_MOVEFILEDLG_H__052AB89A_A18D_4221_BAAD_3F9ECD74F190__INCLUDED_)
#define AFX_MOVEFILEDLG_H__052AB89A_A18D_4221_BAAD_3F9ECD74F190__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMoveFIleDlg dialog

class CMoveFIleDlg : public CDialog
{
// Construction
public:
	CMoveFIleDlg(CWnd* pParent = NULL);	// standard constructor
	CString GetNameFromPath(CString path);
// Dialog Data
	//{{AFX_DATA(CMoveFIleDlg)
	enum { IDD = IDD_MOVEFILE_DIALOG };
	CListCtrl	m_filelist;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMoveFIleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMoveFIleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddFile();
	afx_msg void OnMove();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOVEFILEDLG_H__052AB89A_A18D_4221_BAAD_3F9ECD74F190__INCLUDED_)
