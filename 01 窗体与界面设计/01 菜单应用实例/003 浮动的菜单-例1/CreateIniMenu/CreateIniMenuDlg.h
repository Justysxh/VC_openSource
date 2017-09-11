// CreateIniMenuDlg.h : header file
//

#if !defined(AFX_CREATEINIMENUDLG_H__BB783A88_7836_4C6B_B3CA_15DB3D8C59E1__INCLUDED_)
#define AFX_CREATEINIMENUDLG_H__BB783A88_7836_4C6B_B3CA_15DB3D8C59E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCreateIniMenuDlg dialog

class CCreateIniMenuDlg : public CDialog
{
// Construction
public:
	CCreateIniMenuDlg(CWnd* pParent = NULL);	// standard constructor
	void CreateMenuFromFile();
	void LoadSubMenu(CMenu* m_menu,CString str);
	BOOL IsHaveSubMenu(CString);
	CMenu m_cMenu;
// Dialog Data
	//{{AFX_DATA(CCreateIniMenuDlg)
	enum { IDD = IDD_CREATEINIMENU_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateIniMenuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCreateIniMenuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEINIMENUDLG_H__BB783A88_7836_4C6B_B3CA_15DB3D8C59E1__INCLUDED_)
