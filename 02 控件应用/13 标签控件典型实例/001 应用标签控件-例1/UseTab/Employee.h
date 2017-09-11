#if !defined(AFX_EMPLOYEE_H__60DB1F6B_4B85_4305_AA3D_D40ABE157324__INCLUDED_)
#define AFX_EMPLOYEE_H__60DB1F6B_4B85_4305_AA3D_D40ABE157324__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Employee.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEmployee dialog

class CEmployee : public CDialog
{
// Construction
public:
	CEmployee(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEmployee)
	enum { IDD = IDD_DIALOG_EMP };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmployee)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEmployee)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMPLOYEE_H__60DB1F6B_4B85_4305_AA3D_D40ABE157324__INCLUDED_)
