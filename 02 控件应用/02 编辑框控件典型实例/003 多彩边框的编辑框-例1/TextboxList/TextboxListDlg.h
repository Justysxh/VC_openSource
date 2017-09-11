// TextboxListDlg.h : header file
//

#if !defined(AFX_TEXTBOXLISTDLG_H__AB28FE2B_E1EB_4504_A221_84B171A05D64__INCLUDED_)
#define AFX_TEXTBOXLISTDLG_H__AB28FE2B_E1EB_4504_A221_84B171A05D64__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTextboxListDlg dialog

class CTextboxListDlg : public CDialog
{
// Construction
public:
	CTextboxListDlg(CWnd* pParent = NULL);	// standard constructor
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
	CString xm,xb,csrq,gzdw,yddh,gddh ;
	bool IsShowing;
public:
	void AutoPostion();
	void SetDataBase(CString sql);
// Dialog Data
	//{{AFX_DATA(CTextboxListDlg)
	enum { IDD = IDD_TEXTBOXLIST_DIALOG };
	CEdit	m_edobj;
	CListCtrl	m_tiplist;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextboxListDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTextboxListDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnChangeEdobj();
	afx_msg void OnDblclkTiplist(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTBOXLISTDLG_H__AB28FE2B_E1EB_4504_A221_84B171A05D64__INCLUDED_)
