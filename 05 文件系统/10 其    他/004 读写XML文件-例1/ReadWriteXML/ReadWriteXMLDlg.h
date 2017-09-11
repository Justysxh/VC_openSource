// ReadWriteXMLDlg.h : header file
//

#if !defined(AFX_READWRITEXMLDLG_H__7DCC5E70_1081_41D4_B642_533B2254325C__INCLUDED_)
#define AFX_READWRITEXMLDLG_H__7DCC5E70_1081_41D4_B642_533B2254325C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//#include "MSXML.h"
//using namespace MSXML
/////////////////////////////////////////////////////////////////////////////
// CReadWriteXMLDlg dialog

class CReadWriteXMLDlg : public CDialog
{
// Construction
public:
	CString XMLFilePath;
	
	CReadWriteXMLDlg(CWnd* pParent = NULL);	// standard constructor
	CString GetAppPath();
	BOOL FileExists(CString FilePath);
	void UpdateXMLData();
	void ReadXMLData();
// Dialog Data
	//{{AFX_DATA(CReadWriteXMLDlg)
	enum { IDD = IDD_READWRITEXML_DIALOG };
	CEdit	m_age;
	CEdit	m_name;
	CEdit	m_code;
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReadWriteXMLDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CReadWriteXMLDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	afx_msg void OnAddRow();
	afx_msg void OnSave();
	afx_msg void OnEdit();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READWRITEXMLDLG_H__7DCC5E70_1081_41D4_B642_533B2254325C__INCLUDED_)
