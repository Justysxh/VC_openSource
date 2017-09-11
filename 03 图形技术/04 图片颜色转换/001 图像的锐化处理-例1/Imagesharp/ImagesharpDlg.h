// ImagesharpDlg.h : header file
//

#if !defined(AFX_IMAGESHARPDLG_H__72532522_D019_4D0B_8763_D3E327DBFEC2__INCLUDED_)
#define AFX_IMAGESHARPDLG_H__72532522_D019_4D0B_8763_D3E327DBFEC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CImagesharpDlg dialog

class CImagesharpDlg : public CDialog
{
// Construction
public:
	CImagesharpDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CImagesharpDlg)
	enum { IDD = IDD_IMAGESHARP_DIALOG };
	CStatic	m_image1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImagesharpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CImagesharpDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnSharp();
	afx_msg void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGESHARPDLG_H__72532522_D019_4D0B_8763_D3E327DBFEC2__INCLUDED_)
