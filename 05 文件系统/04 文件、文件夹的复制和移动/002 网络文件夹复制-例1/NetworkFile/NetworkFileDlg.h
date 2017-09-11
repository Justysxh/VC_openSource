// NetworkFileDlg.h : header file
//

#if !defined(AFX_NETWORKFILEDLG_H__78F653DC_1020_408B_A7F3_C849D49B4B04__INCLUDED_)
#define AFX_NETWORKFILEDLG_H__78F653DC_1020_408B_A7F3_C849D49B4B04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNetworkFileDlg dialog

class CNetworkFileDlg : public CDialog
{
// Construction
public:
	CNetworkFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNetworkFileDlg)
	enum { IDD = IDD_NETWORKFILE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetworkFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNetworkFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCopy();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETWORKFILEDLG_H__78F653DC_1020_408B_A7F3_C849D49B4B04__INCLUDED_)
