// WinResManagerDlg.h : header file
//

#if !defined(AFX_WINRESMANAGERDLG_H__26900684_2E79_491A_9700_47FBCAC989FA__INCLUDED_)
#define AFX_WINRESMANAGERDLG_H__26900684_2E79_491A_9700_47FBCAC989FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWinResManagerDlg dialog
#include "FileListCtrl.h"

class CWinResManagerDlg : public CDialog
{
// Construction
public:
	void DiskItemChange();
	void LoadSysDisk();
	CWinResManagerDlg(CWnd* pParent = NULL);	// standard constructor
	CComboBoxEx m_DiskList;
// Dialog Data
	//{{AFX_DATA(CWinResManagerDlg)
	enum { IDD = IDD_WINRESMANAGER_DIALOG };
	CStatic	m_Frame;
	CFileListCtrl	m_FileList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinResManagerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWinResManagerDlg)
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

#endif // !defined(AFX_WINRESMANAGERDLG_H__26900684_2E79_491A_9700_47FBCAC989FA__INCLUDED_)
