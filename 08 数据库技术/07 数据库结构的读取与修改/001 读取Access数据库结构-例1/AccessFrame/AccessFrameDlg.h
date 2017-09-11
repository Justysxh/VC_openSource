// AccessFrameDlg.h : header file
//

#if !defined(AFX_ACCESSFRAMEDLG_H__86A86CBB_9DC5_4173_8B3D_E4536D557821__INCLUDED_)
#define AFX_ACCESSFRAMEDLG_H__86A86CBB_9DC5_4173_8B3D_E4536D557821__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAccessFrameDlg dialog

class CAccessFrameDlg : public CDialog
{
// Construction
public:
	CAccessFrameDlg(CWnd* pParent = NULL);	// standard constructor
	//添加一个指向Connection对象的指针
	_ConnectionPtr m_pConnection;
	//添加一个指向Recordset对象的指针
	_RecordsetPtr m_pRecordset;
	CString strText;
// Dialog Data
	//{{AFX_DATA(CAccessFrameDlg)
	enum { IDD = IDD_ACCESSFRAME_DIALOG };
	CEdit	m_Edit;
	CListBox	m_List;
	CListCtrl	m_Grid;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAccessFrameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAccessFrameDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDblclkList2();
	afx_msg void OnButsjk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACCESSFRAMEDLG_H__86A86CBB_9DC5_4173_8B3D_E4536D557821__INCLUDED_)
