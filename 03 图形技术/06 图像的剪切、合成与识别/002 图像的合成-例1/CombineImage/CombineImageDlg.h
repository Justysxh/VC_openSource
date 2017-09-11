// CombineImageDlg.h : header file
//

#if !defined(AFX_COMBINEIMAGEDLG_H__1BA4A8B8_97FB_4CDA_BD75_3DD80714C73D__INCLUDED_)
#define AFX_COMBINEIMAGEDLG_H__1BA4A8B8_97FB_4CDA_BD75_3DD80714C73D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCombineImageDlg dialog

class CCombineImageDlg : public CDialog
{
// Construction
public:
	CCombineImageDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCombineImageDlg)
	enum { IDD = IDD_COMBINEIMAGE_DIALOG };
	CStatic	m_back;
	CStatic	m_baby;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCombineImageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCombineImageDlg)
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

#endif // !defined(AFX_COMBINEIMAGEDLG_H__1BA4A8B8_97FB_4CDA_BD75_3DD80714C73D__INCLUDED_)
