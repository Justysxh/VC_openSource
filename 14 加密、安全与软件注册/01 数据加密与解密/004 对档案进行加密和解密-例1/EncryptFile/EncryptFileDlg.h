// EncryptFileDlg.h : header file
//

#if !defined(AFX_ENCRYPTFILEDLG_H__EE47C17A_273A_4F41_9DE0_D642DA4D2CFF__INCLUDED_)
#define AFX_ENCRYPTFILEDLG_H__EE47C17A_273A_4F41_9DE0_D642DA4D2CFF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEncryptFileDlg dialog
#include "AES.h"
class CEncryptFileDlg : public CDialog
{
// Construction
public:
	CEncryptFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEncryptFileDlg)
	enum { IDD = IDD_ENCRYPTFILE_DIALOG };
	CString	m_sourcepath;
	CString	m_encryptpath;
	CString	m_decryptpath;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEncryptFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	
	HICON m_hIcon;
	// Generated message map functions
	//{{AFX_MSG(CEncryptFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnEncrypt();
	afx_msg void OnDecrypt();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENCRYPTFILEDLG_H__EE47C17A_273A_4F41_9DE0_D642DA4D2CFF__INCLUDED_)
