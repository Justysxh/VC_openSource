// FetchPageDlg.h : header file
//

#if !defined(AFX_FETCHPAGEDLG_H__11DCB42C_645B_4557_B9D5_5CB8D1128849__INCLUDED_)
#define AFX_FETCHPAGEDLG_H__11DCB42C_645B_4557_B9D5_5CB8D1128849__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFetchPageDlg dialog


#define MAX_COMPUTER 128

class CFetchPageDlg : public CDialog
{
// Construction
public:
	void OnCancel();

	CFetchPageDlg(CWnd* pParent = NULL);	// standard constructor
    SHDocVw::IShellWindowsPtr m_pSHWnd; 
	
	DWORD m_Num;  //Á´½ÓÊýÁ¿

// Dialog Data
	//{{AFX_DATA(CFetchPageDlg)
	enum { IDD = IDD_FETCHPAGE_DIALOG };
	CListCtrl	m_List;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFetchPageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFetchPageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnLookup();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FETCHPAGEDLG_H__11DCB42C_645B_4557_B9D5_5CB8D1128849__INCLUDED_)
