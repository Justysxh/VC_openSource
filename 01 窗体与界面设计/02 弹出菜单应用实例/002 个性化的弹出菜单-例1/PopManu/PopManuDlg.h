// PopManuDlg.h : header file
//

#if !defined(AFX_POPMANUDLG_H__4E207368_9019_45B4_8D11_483726236AA6__INCLUDED_)
#define AFX_POPMANUDLG_H__4E207368_9019_45B4_8D11_483726236AA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPopManuDlg dialog

class CPopManuDlg : public CDialog
{
// Construction
public:
	void LoadBookInfo(BOOL IsDesc = FALSE);
	CPopManuDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPopManuDlg)
	enum { IDD = IDD_POPMANU_DIALOG };
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPopManuDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPopManuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnMenuitemasc();
	afx_msg void OnMenuitemdesc();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POPMANUDLG_H__4E207368_9019_45B4_8D11_483726236AA6__INCLUDED_)
