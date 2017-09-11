// RotationFontDlg.h : header file
//

#if !defined(AFX_ROTATIONFONTDLG_H__0D52A507_EE48_4C8B_955A_CE5F671964E5__INCLUDED_)
#define AFX_ROTATIONFONTDLG_H__0D52A507_EE48_4C8B_955A_CE5F671964E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRotationFontDlg dialog

class CRotationFontDlg : public CDialog
{
// Construction
public:
	CRotationFontDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRotationFontDlg)
	enum { IDD = IDD_ROTATIONFONT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRotationFontDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRotationFontDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROTATIONFONTDLG_H__0D52A507_EE48_4C8B_955A_CE5F671964E5__INCLUDED_)
