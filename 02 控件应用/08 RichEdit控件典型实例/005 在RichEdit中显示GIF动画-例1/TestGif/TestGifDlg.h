// TestGifDlg.h : header file
//

#if !defined(AFX_TESTGIFDLG_H__E5D31A41_AFDF_43CD_9A20_CD053BAF1ECC__INCLUDED_)
#define AFX_TESTGIFDLG_H__E5D31A41_AFDF_43CD_9A20_CD053BAF1ECC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestGifDlg dialog
#include <richole.h>
#import "Gif.dll" named_guids

class CTestGifDlg : public CDialog
{
// Construction
public:
	BOOL InsertImage(IRichEditOle *lpRichEditOle,CString &csFileName);
	CTestGifDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTestGifDlg)
	enum { IDD = IDD_TESTGIF_DIALOG };
	CRichEditCtrl	m_RichEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestGifDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestGifDlg)
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

#endif // !defined(AFX_TESTGIFDLG_H__E5D31A41_AFDF_43CD_9A20_CD053BAF1ECC__INCLUDED_)
