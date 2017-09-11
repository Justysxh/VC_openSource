// ComboCatalogDlg.h : header file
//

#if !defined(AFX_COMBOCATALOGDLG_H__C5D76604_AF31_470E_A7AD_B3E36EC4E5E5__INCLUDED_)
#define AFX_COMBOCATALOGDLG_H__C5D76604_AF31_470E_A7AD_B3E36EC4E5E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CComboCatalogDlg dialog

class CComboCatalogDlg : public CDialog
{
// Construction
public:
	void LoadSysDisk();
	CComboCatalogDlg(CWnd* pParent = NULL);	// standard constructor
	CImageList		m_ImageList;				//定义图像列表

// Dialog Data
	//{{AFX_DATA(CComboCatalogDlg)
	enum { IDD = IDD_COMBOCATALOG_DIALOG };
	CComboBoxEx	m_ComboEx;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboCatalogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CComboCatalogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOCATALOGDLG_H__C5D76604_AF31_470E_A7AD_B3E36EC4E5E5__INCLUDED_)
