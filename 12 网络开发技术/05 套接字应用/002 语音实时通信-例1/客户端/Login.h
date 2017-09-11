#if !defined(AFX_LOGIN_H__7226D3AF_8A3B_4312_99D9_599DD62A0AC0__INCLUDED_)
#define AFX_LOGIN_H__7226D3AF_8A3B_4312_99D9_599DD62A0AC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Login.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogin dialog

class CLogin : public CDialog
{
// Construction
public:
	CLogin(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLogin)
	enum { IDD = IDD_LOGIN };
	CString	m_Port;
	CString	m_ServerAddr;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLogin)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGIN_H__7226D3AF_8A3B_4312_99D9_599DD62A0AC0__INCLUDED_)
