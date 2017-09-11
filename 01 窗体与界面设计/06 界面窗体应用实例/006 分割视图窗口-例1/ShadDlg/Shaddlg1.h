#if !defined(AFX_SHADDLG1_H__E6E6CFBB_5199_44F9_A18A_637DE4A2A4B0__INCLUDED_)
#define AFX_SHADDLG1_H__E6E6CFBB_5199_44F9_A18A_637DE4A2A4B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Shaddlg1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CShaddlg1 dialog

class CShaddlg1 : public CDialog
{
// Construction
public:
	CShaddlg1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CShaddlg1)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShaddlg1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CShaddlg1)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHADDLG1_H__E6E6CFBB_5199_44F9_A18A_637DE4A2A4B0__INCLUDED_)
