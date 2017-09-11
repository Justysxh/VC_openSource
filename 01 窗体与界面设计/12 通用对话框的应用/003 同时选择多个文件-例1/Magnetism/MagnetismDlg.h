// MagnetismDlg.h : header file
//

#if !defined(AFX_MAGNETISMDLG_H__9C8A49B4_019E_4A10_8963_B755F63F1C5D__INCLUDED_)
#define AFX_MAGNETISMDLG_H__9C8A49B4_019E_4A10_8963_B755F63F1C5D__INCLUDED_
#include "ChildDlg.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMagnetismDlg dialog

class CMagnetismDlg : public CDialog
{
// Construction
public:
	CMagnetismDlg(CWnd* pParent = NULL);	// standard constructor
	CChildDlg* m_Dlg;
	BOOL m_IsCreate;
	int m_Width;
	int m_Height;
	BOOL m_Berth;
	CPoint m_Point;
// Dialog Data
	//{{AFX_DATA(CMagnetismDlg)
	enum { IDD = IDD_MAGNETISM_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMagnetismDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMagnetismDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	afx_msg void OnMove(int x, int y);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAGNETISMDLG_H__9C8A49B4_019E_4A10_8963_B755F63F1C5D__INCLUDED_)
