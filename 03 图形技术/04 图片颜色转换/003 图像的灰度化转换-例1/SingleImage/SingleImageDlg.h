// SingleImageDlg.h : header file
//

#if !defined(AFX_SINGLEIMAGEDLG_H__F992B41C_C5B8_4B6E_855C_D2F20C1A31B3__INCLUDED_)
#define AFX_SINGLEIMAGEDLG_H__F992B41C_C5B8_4B6E_855C_D2F20C1A31B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSingleImageDlg dialog

class CSingleImageDlg : public CDialog
{
// Construction
public:
	CSingleImageDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSingleImageDlg)
	enum { IDD = IDD_SINGLEIMAGE_DIALOG };
	CStatic	m_image;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSingleImageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSingleImageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINGLEIMAGEDLG_H__F992B41C_C5B8_4B6E_855C_D2F20C1A31B3__INCLUDED_)
