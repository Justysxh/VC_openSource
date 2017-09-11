// ManageImageDlg.h : header file
//

#if !defined(AFX_MANAGEIMAGEDLG_H__5361FD20_2BD8_42FC_A4BF_1BB11DA6BD13__INCLUDED_)
#define AFX_MANAGEIMAGEDLG_H__5361FD20_2BD8_42FC_A4BF_1BB11DA6BD13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CManageImageDlg dialog

class CManageImageDlg : public CDialog
{
// Construction
public:
	CString ExtractFileName(CString m_fullname);
	CString ExtractFilePath(CString m_path);
	void EnumFiles(LPSTR filepath);
	CString GetFullPath(HTREEITEM htreeitem);

	void EnumDIR(CString dirname,HTREEITEM hparentitem);
	void EnumSysDisk();
	CManageImageDlg(CWnd* pParent = NULL);	// standard constructor

	CImageList m_imagelist;
	HTREEITEM hroot;

// Dialog Data
	//{{AFX_DATA(CManageImageDlg)
	enum { IDD = IDD_MANAGEIMAGE_DIALOG };
	CTreeCtrl	m_tree;
	CListBox	m_dir;
	CComboBox	m_disk;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManageImageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CManageImageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnSelchangeDisk();
	afx_msg void OnClickTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGEIMAGEDLG_H__5361FD20_2BD8_42FC_A4BF_1BB11DA6BD13__INCLUDED_)
