// DiskSpaceDlg.h : header file
//

#if !defined(AFX_DISKSPACEDLG_H__970BB39D_66D6_4470_B123_27A757D707EC__INCLUDED_)
#define AFX_DISKSPACEDLG_H__970BB39D_66D6_4470_B123_27A757D707EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDiskSpaceDlg dialog

class CDiskSpaceDlg : public CDialog
{
// Construction
public:
	CDiskSpaceDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDiskSpaceDlg)
	enum { IDD = IDD_DISKSPACE_DIALOG };
	CListCtrl	m_disklist;
	CImageList imglist;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDiskSpaceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDiskSpaceDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISKSPACEDLG_H__970BB39D_66D6_4470_B123_27A757D707EC__INCLUDED_)
