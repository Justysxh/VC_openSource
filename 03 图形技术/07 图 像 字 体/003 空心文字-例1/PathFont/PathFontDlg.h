// PathFontDlg.h : header file
//

#if !defined(AFX_PATHFONTDLG_H__03765F00_122A_4161_AC12_615FCA4842B3__INCLUDED_)
#define AFX_PATHFONTDLG_H__03765F00_122A_4161_AC12_615FCA4842B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPathFontDlg dialog

class CPathFontDlg : public CDialog
{
// Construction
public:
	void DrawForm();
	CPathFontDlg(CWnd* pParent = NULL);	// standard constructor
	CFont m_font;
// Dialog Data
	//{{AFX_DATA(CPathFontDlg)
	enum { IDD = IDD_PATHFONT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPathFontDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPathFontDlg)
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

#endif // !defined(AFX_PATHFONTDLG_H__03765F00_122A_4161_AC12_615FCA4842B3__INCLUDED_)
