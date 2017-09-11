// aaaaaDlg.h : header file
//

#if !defined(AFX_AAAAADLG_H__5E52CFE1_BE34_46A1_95B6_9E11F7E60484__INCLUDED_)
#define AFX_AAAAADLG_H__5E52CFE1_BE34_46A1_95B6_9E11F7E60484__INCLUDED_
#include "QQList.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAaaaaDlg dialog

class CAaaaaDlg : public CDialog
{
// Construction
public:
	static	void OnItemDouble(const CListCtrl* pListCtrl,int nIndex);
	CAaaaaDlg(CWnd* pParent = NULL);	// standard constructor
	CImageList m_Imagelist;
	BOOL m_Result;
// Dialog Data
	//{{AFX_DATA(CAaaaaDlg)
	enum { IDD = IDD_AAAAA_DIALOG };
	CQQList	m_List;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAaaaaDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAaaaaDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AAAAADLG_H__5E52CFE1_BE34_46A1_95B6_9E11F7E60484__INCLUDED_)
