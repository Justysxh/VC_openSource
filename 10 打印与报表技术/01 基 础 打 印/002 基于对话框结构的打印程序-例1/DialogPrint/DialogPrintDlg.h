// DialogPrintDlg.h : header file
//

#if !defined(AFX_DIALOGPRINTDLG_H__AFF6A28C_9E0D_421C_8C7E_8C84A6342AAC__INCLUDED_)
#define AFX_DIALOGPRINTDLG_H__AFF6A28C_9E0D_421C_8C7E_8C84A6342AAC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDialogPrintDlg dialog

class CDialogPrintDlg : public CDialog
{
// Construction
public:
	void DrawReport(CRect rect, CDC *pDC, BOOL isprinted);
	CDialogPrintDlg(CWnd* pParent = NULL);	// standard constructor
	CString merchandise[4][5];
	CFont titlefont,bodyfont;
	int screenx,screeny;
// Dialog Data
	//{{AFX_DATA(CDialogPrintDlg)
	enum { IDD = IDD_DIALOGPRINT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogPrintDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDialogPrintDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButprint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGPRINTDLG_H__AFF6A28C_9E0D_421C_8C7E_8C84A6342AAC__INCLUDED_)
