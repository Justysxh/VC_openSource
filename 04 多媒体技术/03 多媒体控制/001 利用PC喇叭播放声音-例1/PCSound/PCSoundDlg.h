// PCSoundDlg.h : header file
//

#if !defined(AFX_PCSOUNDDLG_H__AFF45670_BD8F_4B76_B344_EFBB5768FC08__INCLUDED_)
#define AFX_PCSOUNDDLG_H__AFF45670_BD8F_4B76_B344_EFBB5768FC08__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPCSoundDlg dialog

class CPCSoundDlg : public CDialog
{
// Construction
public:
	CPCSoundDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPCSoundDlg)
	enum { IDD = IDD_PCSOUND_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPCSoundDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPCSoundDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOne();
	afx_msg void OnTwo();
	afx_msg void OnThree();
	afx_msg void OnFour();
	afx_msg void OnFive();
	afx_msg void OnSix();
	afx_msg void OnSeven();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PCSOUNDDLG_H__AFF45670_BD8F_4B76_B344_EFBB5768FC08__INCLUDED_)
