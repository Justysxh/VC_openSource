// SemaphoreSynchDlg.h : header file
//

#if !defined(AFX_SEMAPHORESYNCHDLG_H__7043B8CD_32B6_48C4_8819_BA3EE7E72C5F__INCLUDED_)
#define AFX_SEMAPHORESYNCHDLG_H__7043B8CD_32B6_48C4_8819_BA3EE7E72C5F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSemaphoreSynchDlg dialog

class CSemaphoreSynchDlg : public CDialog
{
// Construction
public:
	CSemaphoreSynchDlg(CWnd* pParent = NULL);	// standard constructor
	CString filename;
	CString desname;
	CString sourcename;
	HGLOBAL hGlobal;
	long readlen,poslen,filelen;
	LPVOID pvData;
// Dialog Data
	//{{AFX_DATA(CSemaphoreSynchDlg)
	enum { IDD = IDD_SEMAPHORESYNCH_DIALOG };
	CProgressCtrl	m_pos;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSemaphoreSynchDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSemaphoreSynchDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddSource();
	afx_msg void OnAddDes();
	afx_msg void OnCopy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEMAPHORESYNCHDLG_H__7043B8CD_32B6_48C4_8819_BA3EE7E72C5F__INCLUDED_)
