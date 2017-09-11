// PictureGameDlg.h : header file
//

#if !defined(AFX_PICTUREGAMEDLG_H__AB074E82_A821_45B9_AB10_203714BEFBDD__INCLUDED_)
#define AFX_PICTUREGAMEDLG_H__AB074E82_A821_45B9_AB10_203714BEFBDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPictureGameDlg dialog

class CPictureGameDlg : public CDialog
{
// Construction
public:
	void Display();
	void RandPlace(int a,int b);
	void ShowPicture(int m,int n);
	void SetGrade(CString Grade);
	CPictureGameDlg(CWnd* pParent = NULL);	// standard constructor
	CStatusBar m_statusbar;
	CStatic Picture[100];
	CPoint arrays[200];
	CPoint cpoint[200];
	CString m_Grade;
	CString m_Path;
	CString Gtime;
	char buf[256];
	int m_num;
	int tm;
	BOOL m_bExpand;
	BOOL m_win;
	UINT m_nExpandedWidth,m_nNormalWidth;
// Dialog Data
	//{{AFX_DATA(CPictureGameDlg)
	enum { IDD = IDD_PICTUREGAME_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPictureGameDlg)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPictureGameDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMenueasy();
	afx_msg void OnMenumid();
	afx_msg void OnMenuhard();
	afx_msg void OnMenucustom();
	afx_msg void OnMenuhelp();
	afx_msg void OnMenustart();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMenubmp1();
	afx_msg void OnMenubmp2();
	afx_msg void OnMenubmp3();
	afx_msg void OnMenuexit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICTUREGAMEDLG_H__AB074E82_A821_45B9_AB10_203714BEFBDD__INCLUDED_)
