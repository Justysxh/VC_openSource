// ToolTipDlg.h : header file
//

#if !defined(AFX_TOOLTIPDLG_H__46F3DC7A_5984_47A4_81F6_53A08EF4A488__INCLUDED_)
#define AFX_TOOLTIPDLG_H__46F3DC7A_5984_47A4_81F6_53A08EF4A488__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CToolTipDlg dialog

class CToolTipDlg : public CDialog
{
// Construction
public:
	void UpdateToolBar(BOOL bUpdate);
	CToolTipDlg(CWnd* pParent = NULL);	// standard constructor
	CToolBar	m_ToolBar;
	CImageList	m_ImageList;
	BOOL        m_bText;
// Dialog Data
	//{{AFX_DATA(CToolTipDlg)
	enum { IDD = IDD_TOOLTIP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolTipDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CToolTipDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonupdate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLTIPDLG_H__46F3DC7A_5984_47A4_81F6_53A08EF4A488__INCLUDED_)
