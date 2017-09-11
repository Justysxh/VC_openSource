// browsebmpsDlg.h : header file
//

#if !defined(AFX_BROWSEBMPSDLG_H__CAB73B60_FE01_4638_80E9_057EBE7F7212__INCLUDED_)
#define AFX_BROWSEBMPSDLG_H__CAB73B60_FE01_4638_80E9_057EBE7F7212__INCLUDED_
#include "Picture.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBrowsebmpsDlg dialog

class CBrowsebmpsDlg : public CDialog
{
// Construction
public:
	CString strFile[4];
	CString strText,strName;
	void Loadpicture(CString str);
	CPicture picture[4];
	char buffer[1000];
	CString Search(CString curstr,bool judge);
	CImageList m_imagelist;
	CToolBar m_toolbar;
	CBrowsebmpsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBrowsebmpsDlg)
	enum { IDD = IDD_BROWSEBMPS_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBrowsebmpsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBrowsebmpsDlg)
	afx_msg void OnNext();
	afx_msg void OnAhead();
	afx_msg void OnNextRow();
	afx_msg void OnAheadRow();
	afx_msg void OnOpen();
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BROWSEBMPSDLG_H__CAB73B60_FE01_4638_80E9_057EBE7F7212__INCLUDED_)
