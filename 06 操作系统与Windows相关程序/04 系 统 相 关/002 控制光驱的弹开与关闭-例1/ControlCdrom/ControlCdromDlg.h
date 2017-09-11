// ControlCdromDlg.h : header file
//

#if !defined(AFX_CONTROLCDROMDLG_H__246BDB11_8815_4153_8C95_2D0F46D2720C__INCLUDED_)
#define AFX_CONTROLCDROMDLG_H__246BDB11_8815_4153_8C95_2D0F46D2720C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CControlCdromDlg dialog

class CControlCdromDlg : public CDialog
{
// Construction
public:
	CControlCdromDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CControlCdromDlg)
	enum { IDD = IDD_CONTROLCDROM_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControlCdromDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CControlCdromDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpen();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROLCDROMDLG_H__246BDB11_8815_4153_8C95_2D0F46D2720C__INCLUDED_)
