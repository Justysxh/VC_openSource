// WinMineGameDlg.h : header file
//

#if !defined(AFX_WINMINEGAMEDLG_H__CF4320F9_D3D2_48E0_AF49_D6A4972D61BB__INCLUDED_)
#define AFX_WINMINEGAMEDLG_H__CF4320F9_D3D2_48E0_AF49_D6A4972D61BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWinMineGameDlg dialog

class CWinMineGameDlg : public CDialog
{
// Construction
public:
	CWinMineGameDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWinMineGameDlg)
	enum { IDD = IDD_WINMINEGAME_DIALOG };
	CButton	m_black;
	CComboBox	m_grade;
	CButton	m_sound;
	BOOL bcolor;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinMineGameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWinMineGameDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnEnter();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINMINEGAMEDLG_H__CF4320F9_D3D2_48E0_AF49_D6A4972D61BB__INCLUDED_)
