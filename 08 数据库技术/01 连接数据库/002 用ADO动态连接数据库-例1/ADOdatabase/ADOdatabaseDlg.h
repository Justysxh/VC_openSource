// ADOdatabaseDlg.h : header file
//

#if !defined(AFX_ADODATABASEDLG_H__2747DC46_4055_47C4_A483_770ABF309000__INCLUDED_)
#define AFX_ADODATABASEDLG_H__2747DC46_4055_47C4_A483_770ABF309000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CADOdatabaseDlg dialog

class CADOdatabaseDlg : public CDialog
{
// Construction
public:
	void ExitConnect();
	void OnInitADOConn(CString strsjk);
	CADOdatabaseDlg(CWnd* pParent = NULL);	// standard constructor
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
// Dialog Data
	//{{AFX_DATA(CADOdatabaseDlg)
	enum { IDD = IDD_ADODATABASE_DIALOG };
	CListBox	m_list;
	CString	m_edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADOdatabaseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CADOdatabaseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButconnect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADODATABASEDLG_H__2747DC46_4055_47C4_A483_770ABF309000__INCLUDED_)
