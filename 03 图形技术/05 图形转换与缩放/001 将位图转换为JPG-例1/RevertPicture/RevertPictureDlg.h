// RevertPictureDlg.h : header file
//
//{{AFX_INCLUDES()
#include "jpg.h"
//}}AFX_INCLUDES
#if !defined(AFX_REVERTPICTUREDLG_H__6CFDA0C3_1864_4AA7_80E4_51561EC9A5F1__INCLUDED_)
#define AFX_REVERTPICTUREDLG_H__6CFDA0C3_1864_4AA7_80E4_51561EC9A5F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRevertPictureDlg dialog

class CRevertPictureDlg : public CDialog
{
// Construction
public:
	CRevertPictureDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRevertPictureDlg)
	enum { IDD = IDD_REVERTPICTURE_DIALOG };
	CStatic	m_image;
	CEdit	m_dir;
	CString m_filename ;
	CJPG	m_JPG;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRevertPictureDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRevertPictureDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnBrown();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REVERTPICTUREDLG_H__6CFDA0C3_1864_4AA7_80E4_51561EC9A5F1__INCLUDED_)
