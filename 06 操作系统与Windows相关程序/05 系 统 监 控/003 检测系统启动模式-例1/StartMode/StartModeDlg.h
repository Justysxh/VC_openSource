// StartModeDlg.h : header file
//

#if !defined(AFX_STARTMODEDLG_H__167F3E09_3428_4D3A_9D93_45F2D4C8A123__INCLUDED_)
#define AFX_STARTMODEDLG_H__167F3E09_3428_4D3A_9D93_45F2D4C8A123__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStartModeDlg dialog

class CStartModeDlg : public CDialog
{
// Construction
public:
	CStartModeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CStartModeDlg)
	enum { IDD = IDD_STARTMODE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStartModeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStartModeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STARTMODEDLG_H__167F3E09_3428_4D3A_9D93_45F2D4C8A123__INCLUDED_)
