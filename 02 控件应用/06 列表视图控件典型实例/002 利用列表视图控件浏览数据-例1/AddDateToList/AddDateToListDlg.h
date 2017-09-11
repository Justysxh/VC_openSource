// AddDateToListDlg.h : header file
//

#if !defined(AFX_ADDDATETOLISTDLG_H__EFCF4108_190B_4B1A_8AE2_7B407C33E96D__INCLUDED_)
#define AFX_ADDDATETOLISTDLG_H__EFCF4108_190B_4B1A_8AE2_7B407C33E96D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAddDateToListDlg dialog

class CAddDateToListDlg : public CDialog
{
// Construction
public:
	CAddDateToListDlg(CWnd* pParent = NULL);	// standard constructor
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
	CString xm,xb,csrq,gzdw,yddh,gddh ;
// Dialog Data
	//{{AFX_DATA(CAddDateToListDlg)
	enum { IDD = IDD_ADDDATETOLIST_DIALOG };
	CListCtrl	m_datalist;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddDateToListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAddDateToListDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDDATETOLISTDLG_H__EFCF4108_190B_4B1A_8AE2_7B407C33E96D__INCLUDED_)
