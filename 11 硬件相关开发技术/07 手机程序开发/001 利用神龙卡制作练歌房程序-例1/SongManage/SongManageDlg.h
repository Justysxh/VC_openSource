// SongManageDlg.h : header file
//

#if !defined(AFX_SONGMANAGEDLG_H__FCDC8E21_CBFA_4FA2_B991_5D869B8289FC__INCLUDED_)
#define AFX_SONGMANAGEDLG_H__FCDC8E21_CBFA_4FA2_B991_5D869B8289FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSongManageDlg dialog
#include "nnsrealmagicctrl.h"
class CSongManageDlg : public CDialog
{
// Construction
public:
	CSongManageDlg(CWnd* pParent = NULL);	// standard constructor
	IREALmagicCtrl m_Play;
// Dialog Data
	//{{AFX_DATA(CSongManageDlg)
	enum { IDD = IDD_SONGMANAGE_DIALOG };
	CButton	m_Whisht;
	CSliderCtrl	m_SetVolumn;
	CListCtrl	m_SongList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSongManageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSongManageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnPlay();
	afx_msg void OnSpeed();
	afx_msg void OnBack();
	afx_msg void OnPause();
	afx_msg void OnTerminal();
	afx_msg void OnQuit();
	afx_msg void OnLeftwav();
	afx_msg void OnRightwave();
	afx_msg void OnSolidwave();
	afx_msg void OnReleasedcaptureSetvolumn(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnWhisht();
	afx_msg void OnTv();
	afx_msg void OnVga();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SONGMANAGEDLG_H__FCDC8E21_CBFA_4FA2_B991_5D869B8289FC__INCLUDED_)
