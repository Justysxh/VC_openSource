// RotateImgDlg.h : header file
//

#if !defined(AFX_ROTATEIMGDLG_H__D91A6B30_0ACA_45E8_B387_E49A5D2DC659__INCLUDED_)
#define AFX_ROTATEIMGDLG_H__D91A6B30_0ACA_45E8_B387_E49A5D2DC659__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRotateImgDlg dialog

class CRotateImgDlg : public CDialog
{
// Construction
public:
	CRotateImgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRotateImgDlg)
	enum { IDD = IDD_ROTATEIMG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRotateImgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRotateImgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROTATEIMGDLG_H__D91A6B30_0ACA_45E8_B387_E49A5D2DC659__INCLUDED_)
