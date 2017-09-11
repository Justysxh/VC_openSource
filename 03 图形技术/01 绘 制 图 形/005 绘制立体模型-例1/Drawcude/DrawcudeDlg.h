// DrawcudeDlg.h : header file
//

#if !defined(AFX_DRAWCUDEDLG_H__390954FC_4D42_4D36_9A73_14D15A4066E0__INCLUDED_)
#define AFX_DRAWCUDEDLG_H__390954FC_4D42_4D36_9A73_14D15A4066E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDrawcudeDlg dialog

class CDrawcudeDlg : public CDialog
{
// Construction
public:
	CDrawcudeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDrawcudeDlg)
	enum { IDD = IDD_DRAWCUDE_DIALOG };
	CStatic	m_palette;
	CEdit	m_angle;
	CEdit	m_height;
	CEdit	m_width;
	CEdit	m_length;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawcudeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDrawcudeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButdraw();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWCUDEDLG_H__390954FC_4D42_4D36_9A73_14D15A4066E0__INCLUDED_)
