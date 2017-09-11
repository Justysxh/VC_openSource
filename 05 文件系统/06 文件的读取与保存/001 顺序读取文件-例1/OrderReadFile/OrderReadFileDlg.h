// OrderReadFileDlg.h : header file
//

#if !defined(AFX_ORDERREADFILEDLG_H__04B4D146_876A_4376_B374_6E04F2340C0D__INCLUDED_)
#define AFX_ORDERREADFILEDLG_H__04B4D146_876A_4376_B374_6E04F2340C0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COrderReadFileDlg dialog

class COrderReadFileDlg : public CDialog
{
// Construction
public:
	COrderReadFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(COrderReadFileDlg)
	enum { IDD = IDD_ORDERREADFILE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COrderReadFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CStdioFile file;
	DWORD readlen;
	// Generated message map functions
	//{{AFX_MSG(COrderReadFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRead();
	afx_msg void OnOpen();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ORDERREADFILEDLG_H__04B4D146_876A_4376_B374_6E04F2340C0D__INCLUDED_)
