// RichTextCharDlg.h : header file
//

#if !defined(AFX_RICHTEXTCHARDLG_H__42E43653_4464_4047_9517_CCD6BE23D9D3__INCLUDED_)
#define AFX_RICHTEXTCHARDLG_H__42E43653_4464_4047_9517_CCD6BE23D9D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRichTextCharDlg dialog

class CRichTextCharDlg : public CDialog
{
// Construction
public:
	CRichTextCharDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRichTextCharDlg)
	enum { IDD = IDD_RICHTEXTCHAR_DIALOG };
	CEdit	m_edfind;
	CButton	m_btnFind;
	CRichEditCtrl	m_richedit;
	CString str;
	CString tmp;
	int istartpos;
	int lineindex;
	int movepos;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRichTextCharDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRichTextCharDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnFind();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RICHTEXTCHARDLG_H__42E43653_4464_4047_9517_CCD6BE23D9D3__INCLUDED_)
