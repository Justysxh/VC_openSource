// FileFindThreadDlg.h : header file
//

#if !defined(AFX_FILEFINDTHREADDLG_H__248F046D_109D_4D5A_8177_43DA058D0D04__INCLUDED_)
#define AFX_FILEFINDTHREADDLG_H__248F046D_109D_4D5A_8177_43DA058D0D04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileFindThreadDlg dialog
#include "SplitterEx.h"
#include "ChildFrame.h"
#include "TreeFrame.h"

class CFileFindThreadDlg;
typedef struct _tagTHREADPARAM {
	char	FileName[255];
	CListCtrl *listCtrl;
	CFileFindThreadDlg *dlg;
} THREADPARAM;

class CFileFindThreadDlg : public CDialog
{
// Construction
public:
	CSplitterEx m_Splitter;
	CStringArray m_strArrPath;
	void CalcSplitterSize();
	void FindFiles( CString strPath, CString strFileName , CListCtrl *listCtrl );
	void GetSearchingPath( HTREEITEM hItem , CTreeCtrl *treeCtrl);
	CString GetFullPath( HTREEITEM hItem , CTreeCtrl *treeCtrl);
public:
	CFileFindThreadDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFileFindThreadDlg)
	enum { IDD = IDD_FILEFINDTHREAD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileFindThreadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileFindThreadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg LRESULT OnFindFile(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEFINDTHREADDLG_H__248F046D_109D_4D5A_8177_43DA058D0D04__INCLUDED_)
