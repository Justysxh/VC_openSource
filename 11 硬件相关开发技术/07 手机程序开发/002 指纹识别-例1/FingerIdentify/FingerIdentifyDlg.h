// FingerIdentifyDlg.h : header file
//
//{{AFX_INCLUDES()
#include "zkfpengx.h"
//}}AFX_INCLUDES

#if !defined(AFX_FINGERIDENTIFYDLG_H__7FE4DB50_2381_46BC_9679_72762B9E1D21__INCLUDED_)
#define AFX_FINGERIDENTIFYDLG_H__7FE4DB50_2381_46BC_9679_72762B9E1D21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFingerIdentifyDlg dialog

class CFingerIdentifyDlg : public CDialog
{
// Construction
public:
	int IdentifyType;
	void OnAddRow();
	CFingerIdentifyDlg(CWnd* pParent = NULL);	// standard constructor
	void UpdateList();
// Dialog Data
	//{{AFX_DATA(CFingerIdentifyDlg)
	enum { IDD = IDD_FINGERIDENTIFY_DIALOG };
	CStatic	m_image;
	CEdit	m_dept;
	CEdit	m_name;
	CEdit	m_id;
	CListCtrl	m_list;
	CZKFPEngX	m_zkeng;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFingerIdentifyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFingerIdentifyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnEnroll(BOOL ActionResult, const VARIANT FAR& ATemplate);
	afx_msg void OnImageReceived(BOOL FAR* AImageValid);
	afx_msg void OnCapture(BOOL ActionResult, const VARIANT FAR& ATemplate);
	afx_msg void OnFeatureInfo(long AQuality);
	afx_msg void OnInitfacility();
	afx_msg void OnClosefacility();
	afx_msg void OnClose();
	afx_msg void OnItemchangingList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAdd();
	afx_msg void OnDestroy();
	afx_msg void OnRegister();
	afx_msg void OnButton3();
	afx_msg void OnButton7();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINGERIDENTIFYDLG_H__7FE4DB50_2381_46BC_9679_72762B9E1D21__INCLUDED_)
