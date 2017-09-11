// SellGoodsDlg.h : header file
//

#if !defined(AFX_SELLGOODSDLG_H__083F5BE0_0852_4FA8_B169_5571716B0E3F__INCLUDED_)
#define AFX_SELLGOODSDLG_H__083F5BE0_0852_4FA8_B169_5571716B0E3F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSellGoodsDlg dialog

class CSellGoodsDlg : public CDialog
{
// Construction
public:
	int IsExistInList(CString barcode);
	void OnEditEnter();
	CSellGoodsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSellGoodsDlg)
	enum { IDD = IDD_SELLGOODS_DIALOG };
	CButton	m_Save;
	CListCtrl	m_ListInfo;
	CEdit	    m_Barcode;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSellGoodsDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSellGoodsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELLGOODSDLG_H__083F5BE0_0852_4FA8_B169_5571716B0E3F__INCLUDED_)
