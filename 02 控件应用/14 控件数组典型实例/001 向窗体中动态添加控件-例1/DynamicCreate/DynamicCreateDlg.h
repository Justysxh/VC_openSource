// DynamicCreateDlg.h : header file
//

#if !defined(AFX_DYNAMICCREATEDLG_H__0006AB4F_0AF8_4B55_99B6_8BAF661E415F__INCLUDED_)
#define AFX_DYNAMICCREATEDLG_H__0006AB4F_0AF8_4B55_99B6_8BAF661E415F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDynamicCreateDlg dialog

class CDynamicCreateDlg : public CDialog
{
// Construction
public:
	void CreateControl();
	CDynamicCreateDlg(CWnd* pParent = NULL);	// standard constructor
	~CDynamicCreateDlg();

	CStatic m_statics[6]; //标签1中的静态控件
	CStatic m_static2[6]; //标签2中的静态控件

	CEdit   m_edits1 [6]; //标签1中的编辑框
	CEdit   m_edits2 [6]; //标签2中的编辑框

	CStatic*  m_spage1, * m_spage2;
	CEdit *   m_epage1, * m_epage2;
	
	CStringList m_list1,m_list;  //记录静态控件文本

// Dialog Data
	//{{AFX_DATA(CDynamicCreateDlg)
	enum { IDD = IDD_DYNAMICCREATE_DIALOG };
	CTabCtrl	m_tab;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynamicCreateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDynamicCreateDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClose();
	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNAMICCREATEDLG_H__0006AB4F_0AF8_4B55_99B6_8BAF661E415F__INCLUDED_)
