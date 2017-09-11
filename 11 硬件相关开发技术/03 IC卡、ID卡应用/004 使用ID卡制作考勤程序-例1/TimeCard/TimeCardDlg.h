// TimeCardDlg.h : header file
//

#if !defined(AFX_TIMECARDDLG_H__099E4445_6611_4F39_8B14_48D4A6438518__INCLUDED_)
#define AFX_TIMECARDDLG_H__099E4445_6611_4F39_8B14_48D4A6438518__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTimeCardDlg dialog

class CTimeCardDlg : public CDialog
{
// Construction
public:
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;

	void InitPersonList();
	void UpdateCardList();
	void AddRow();
	void DeleteRow();
public:
	CTimeCardDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTimeCardDlg)
	enum { IDD = IDD_TIMECARD_DIALOG };
	CEdit	m_xl;
	CEdit	m_sex;
	CEdit	m_name;
	CEdit	m_id;
	CListCtrl	m_cardlist;
	CListCtrl	m_personlist;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeCardDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTimeCardDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnClose();
	afx_msg void OnAddRow();
	afx_msg void OnItemchangingList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeleteRow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMECARDDLG_H__099E4445_6611_4F39_8B14_48D4A6438518__INCLUDED_)
