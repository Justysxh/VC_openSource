// DiskSerialDlg.h : header file
//

#if !defined(AFX_DISKSERIALDLG_H__10442AFF_4913_42CC_983B_5F19D45E9D49__INCLUDED_)
#define AFX_DISKSERIALDLG_H__10442AFF_4913_42CC_983B_5F19D45E9D49__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDiskSerialDlg dialog

class CDiskSerialDlg : public CDialog
{
// Construction
public:
	CDiskSerialDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDiskSerialDlg)
	enum { IDD = IDD_DISKSERIAL_DIALOG };
	CListCtrl	m_disklist;
	CImageList imglist;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDiskSerialDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDiskSerialDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISKSERIALDLG_H__10442AFF_4913_42CC_983B_5F19D45E9D49__INCLUDED_)
