// TextScreenSaveDlg.h : header file
//

#if !defined(AFX_TEXTSCREENSAVEDLG_H__B888C1DD_4F60_4F34_910B_5D97545817D3__INCLUDED_)
#define AFX_TEXTSCREENSAVEDLG_H__B888C1DD_4F60_4F34_910B_5D97545817D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTextScreenSaveDlg dialog

class CTextScreenSaveDlg : public CDialog
{
// Construction
public:
	CTextScreenSaveDlg(CWnd* pParent = NULL);	// standard constructor
	CPoint curpt;
	int x,y;
	int iscreenx;
	int iscreeny;
// Dialog Data
	//{{AFX_DATA(CTextScreenSaveDlg)
	enum { IDD = IDD_TEXTSCREENSAVE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextScreenSaveDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTextScreenSaveDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTSCREENSAVEDLG_H__B888C1DD_4F60_4F34_910B_5D97545817D3__INCLUDED_)
