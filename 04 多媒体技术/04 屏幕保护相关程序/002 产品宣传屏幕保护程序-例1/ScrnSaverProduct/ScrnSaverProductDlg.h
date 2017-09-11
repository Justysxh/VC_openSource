// ScrnSaverProductDlg.h : header file
//

#if !defined(AFX_SCRNSAVERPRODUCTDLG_H__AB1B7EB8_6CF2_4EC0_B654_76DE6841F913__INCLUDED_)
#define AFX_SCRNSAVERPRODUCTDLG_H__AB1B7EB8_6CF2_4EC0_B654_76DE6841F913__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CScrnSaverProductDlg dialog

class CScrnSaverProductDlg : public CDialog
{
// Construction
public:
	CScrnSaverProductDlg(CWnd* pParent = NULL);	// standard constructor
	CPoint curpt;
	int x;
	int y;
	int idirect;
	int a;
	int b;
	void DrawBitmap(CDC &dc, int nIndexBit);
// Dialog Data
	//{{AFX_DATA(CScrnSaverProductDlg)
	enum { IDD = IDD_SCRNSAVERPRODUCT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrnSaverProductDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CScrnSaverProductDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCRNSAVERPRODUCTDLG_H__AB1B7EB8_6CF2_4EC0_B654_76DE6841F913__INCLUDED_)
