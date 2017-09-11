// AviCompressDlg.h : header file
//

#if !defined(AFX_AVICOMPRESSDLG_H__89D78EFB_6CCA_42C5_B9C0_D9F1AD11923C__INCLUDED_)
#define AFX_AVICOMPRESSDLG_H__89D78EFB_6CCA_42C5_B9C0_D9F1AD11923C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAviCompressDlg dialog


class CAviCompressDlg : public CDialog
{
// Construction
public:

	CAviCompressDlg(CWnd* pParent = NULL);	// standard constructor

	void CompressAvi(LPCSTR lpstrOldFile,LPCSTR lpstrNewFile);
// Dialog Data
	//{{AFX_DATA(CAviCompressDlg)
	enum { IDD = IDD_AVICOMPRESS_DIALOG };
	CEdit	m_SrcFile;
	CEdit	m_DstFile;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAviCompressDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAviCompressDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnSrcBrown();
	afx_msg void OnDstBrown();
	afx_msg void OnCompress();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AVICOMPRESSDLG_H__89D78EFB_6CCA_42C5_B9C0_D9F1AD11923C__INCLUDED_)
