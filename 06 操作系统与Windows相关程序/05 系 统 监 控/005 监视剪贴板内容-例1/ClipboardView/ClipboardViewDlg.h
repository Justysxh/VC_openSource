// ClipboardViewDlg.h : header file
//

#if !defined(AFX_CLIPBOARDVIEWDLG_H__7CDCEABF_F481_484B_A0FC_E3244CF08D4D__INCLUDED_)
#define AFX_CLIPBOARDVIEWDLG_H__7CDCEABF_F481_484B_A0FC_E3244CF08D4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClipboardViewDlg dialog

class CClipboardViewDlg : public CDialog
{
// Construction
public:
	CClipboardViewDlg(CWnd* pParent = NULL);	// standard constructor
	HWND view;
	CString GetName(int value);
	//CString strdata;
// Dialog Data
	//{{AFX_DATA(CClipboardViewDlg)
	enum { IDD = IDD_CLIPBOARDVIEW_DIALOG };
	CListBox	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClipboardViewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClipboardViewDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnView();
	afx_msg void OnSelchangeListtype();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIPBOARDVIEWDLG_H__7CDCEABF_F481_484B_A0FC_E3244CF08D4D__INCLUDED_)
