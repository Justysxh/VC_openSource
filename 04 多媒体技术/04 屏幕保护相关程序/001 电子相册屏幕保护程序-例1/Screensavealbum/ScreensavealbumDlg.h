// ScreensavealbumDlg.h : header file
//

#if !defined(AFX_SCREENSAVEALBUMDLG_H__E922E388_5E52_41CD_932D_EB6DE7BCDD1D__INCLUDED_)
#define AFX_SCREENSAVEALBUMDLG_H__E922E388_5E52_41CD_932D_EB6DE7BCDD1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CScreensavealbumDlg dialog

class CScreensavealbumDlg : public CDialog
{
// Construction
public:
	CScreensavealbumDlg(CWnd* pParent = NULL);	// standard constructor
	CPoint curpt;
	int x,y;
	void DrawBitmap(CDC &dc, int nIndexBit);
// Dialog Data
	//{{AFX_DATA(CScreensavealbumDlg)
	enum { IDD = IDD_SCREENSAVEALBUM_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScreensavealbumDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CScreensavealbumDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCREENSAVEALBUMDLG_H__E922E388_5E52_41CD_932D_EB6DE7BCDD1D__INCLUDED_)
