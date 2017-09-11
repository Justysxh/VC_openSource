// inputvoiceDlg.h : header file
//

#if !defined(AFX_INPUTVOICEDLG_H__62539D28_0702_4DFB_99FF_575C3FC44AF3__INCLUDED_)
#define AFX_INPUTVOICEDLG_H__62539D28_0702_4DFB_99FF_575C3FC44AF3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CInputvoiceDlg dialog

class CInputvoiceDlg : public CDialog
{
// Construction
public:
	void AddToCombo();
	CString strText,strName,strkzm,strPath;
	CInputvoiceDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CInputvoiceDlg)
	enum { IDD = IDD_INPUTVOICE_DIALOG };
	CEdit	m_kzm;
	CEdit	m_editlj;
	CComboBox	m_combo;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInputvoiceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CInputvoiceDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButliulan();
	afx_msg void OnButsave();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnButcreate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTVOICEDLG_H__62539D28_0702_4DFB_99FF_575C3FC44AF3__INCLUDED_)
