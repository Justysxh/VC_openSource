// BmpAccessDlg.h : header file
//

#if !defined(AFX_BMPACCESSDLG_H__6C552F46_CE43_4C03_899B_48F15E0B40E3__INCLUDED_)
#define AFX_BMPACCESSDLG_H__6C552F46_CE43_4C03_899B_48F15E0B40E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBmpAccessDlg dialog

class CBmpAccessDlg : public CDialog
{
// Construction
public:
	void AddToGrid();
	CString strText;
	HBITMAP m_hbitmap;
	void Display();
	BOOL m_bExpand;
	int m_nExpandedHeight,m_nNormalHeight;
	CBmpAccessDlg(CWnd* pParent = NULL);	// standard constructor
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
// Dialog Data
	//{{AFX_DATA(CBmpAccessDlg)
	enum { IDD = IDD_BMPACCESS_DIALOG };
	CStatic	m_pictureshow;
	CListCtrl	m_grid;
	CStatic	m_picture;
	CString	m_id;
	CString	m_name;
	CString	m_sex;
	CString	m_knowledge;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpAccessDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBmpAccessDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButliulan();
	afx_msg void OnButshow();
	afx_msg void OnButsave();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPACCESSDLG_H__6C552F46_CE43_4C03_899B_48F15E0B40E3__INCLUDED_)
