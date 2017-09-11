#if !defined(AFX_SHADDLG2_H__B170286D_E173_4648_99DB_DC79C5DD46BF__INCLUDED_)
#define AFX_SHADDLG2_H__B170286D_E173_4648_99DB_DC79C5DD46BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Shaddlg2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CShaddlg2 dialog

class CShaddlg2 : public CDialog
{
// Construction
public:
	CShaddlg2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CShaddlg2)
	enum { IDD = IDD_DIALOG2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShaddlg2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CShaddlg2)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHADDLG2_H__B170286D_E173_4648_99DB_DC79C5DD46BF__INCLUDED_)
