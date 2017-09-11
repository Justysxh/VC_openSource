// FetchObjectDlg.h : header file
//

#if !defined(AFX_FETCHOBJECTDLG_H__0E1CE616_0C4E_4838_A114_15CD2416F96C__INCLUDED_)
#define AFX_FETCHOBJECTDLG_H__0E1CE616_0C4E_4838_A114_15CD2416F96C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFetchObjectDlg dialog

class CFetchObjectDlg : public CDialog
{
// Construction
public:
	CFetchObjectDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFetchObjectDlg)
	enum { IDD = IDD_FETCHOBJECT_DIALOG };
	CStatic	m_image;
	CStatic	m_demo;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFetchObjectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFetchObjectDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnFetch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FETCHOBJECTDLG_H__0E1CE616_0C4E_4838_A114_15CD2416F96C__INCLUDED_)
