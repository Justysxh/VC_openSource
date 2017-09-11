#if !defined(AFX_PREVIEW_H__E445A3BD_99C9_4F7A_8691_9ECE3B7E3691__INCLUDED_)
#define AFX_PREVIEW_H__E445A3BD_99C9_4F7A_8691_9ECE3B7E3691__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PreviewDialog.h"
// PreView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPreView dialog

class CPreView : public CDialog
{
// Construction
protected:
	CToolBar MainBar;
	CStatusBar StatusBar;
	CPreviewDialog PreviewDlg;

	void CalcPreviewRect();
public:
	CPreView(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPreView)
	enum { IDD = IDD_PreviewView };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPreView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPreView)
	virtual BOOL OnInitDialog();
	afx_msg void OnPagesetup();
	afx_msg void OnPrintsetup();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnNext();
	afx_msg void OnFirst();
	afx_msg void OnClose();
	afx_msg void OnZoomout();
	afx_msg void OnZoomin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PREVIEW_H__E445A3BD_99C9_4F7A_8691_9ECE3B7E3691__INCLUDED_)
