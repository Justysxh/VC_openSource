// OutInterfaceDlg.h : header file
//

#if !defined(AFX_OUTINTERFACEDLG_H__0D6A438A_04F2_41CC_8F5E_00046FA0C248__INCLUDED_)
#define AFX_OUTINTERFACEDLG_H__0D6A438A_04F2_41CC_8F5E_00046FA0C248__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COutInterfaceDlg dialog
#include "OutlookList.h"


class COutInterfaceDlg : public CDialog
{
// Construction
public:
	static	void OnItemDouble(const CListCtrl* pListCtrl,int nIndex);

	COutInterfaceDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(COutInterfaceDlg)
	enum { IDD = IDD_OUTINTERFACE_DIALOG };
	COutlookList	m_List;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutInterfaceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL


// Implementation
protected:
	HICON m_hIcon;
	
	CImageList m_Imagelist;
	CToolBar m_ToolBar;
	// Generated message map functions
	//{{AFX_MSG(COutInterfaceDlg)
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

#endif // !defined(AFX_OUTINTERFACEDLG_H__0D6A438A_04F2_41CC_8F5E_00046FA0C248__INCLUDED_)
