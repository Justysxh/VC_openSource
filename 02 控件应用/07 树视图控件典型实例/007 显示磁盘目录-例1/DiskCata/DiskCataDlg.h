// DiskCataDlg.h : header file
//

#if !defined(AFX_DISKCATADLG_H__23FC9448_46FC_4D05_AC08_44F37B957906__INCLUDED_)
#define AFX_DISKCATADLG_H__23FC9448_46FC_4D05_AC08_44F37B957906__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDiskCataDlg dialog

class CDiskCataDlg : public CDialog
{
// Construction
public:
	CDiskCataDlg(CWnd* pParent = NULL);	// standard constructor
	CImageList imlst;
	int imindex;
	SHFILEINFO fileinfo;
// Dialog Data
	//{{AFX_DATA(CDiskCataDlg)
	enum { IDD = IDD_DISKCATA_DIALOG };
	CTreeCtrl	m_trdisktree;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDiskCataDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDiskCataDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangedTrdisktree(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISKCATADLG_H__23FC9448_46FC_4D05_AC08_44F37B957906__INCLUDED_)
