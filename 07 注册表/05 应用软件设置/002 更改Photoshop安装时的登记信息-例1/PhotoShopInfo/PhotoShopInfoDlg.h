// PhotoShopInfoDlg.h : header file
//

#if !defined(AFX_PHOTOSHOPINFODLG_H__84DFFC57_8C62_443F_A5B8_DE8FC083C137__INCLUDED_)
#define AFX_PHOTOSHOPINFODLG_H__84DFFC57_8C62_443F_A5B8_DE8FC083C137__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPhotoShopInfoDlg dialog

class CPhotoShopInfoDlg : public CDialog
{
// Construction
public:
	CPhotoShopInfoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPhotoShopInfoDlg)
	enum { IDD = IDD_PHOTOSHOPINFO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPhotoShopInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPhotoShopInfoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnExit();
	afx_msg void OnEnter();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PHOTOSHOPINFODLG_H__84DFFC57_8C62_443F_A5B8_DE8FC083C137__INCLUDED_)
