#if !defined(AFX_EMPLOYEE_H__D36A3514_9ADE_4D34_ABB1_165918EE589D__INCLUDED_)
#define AFX_EMPLOYEE_H__D36A3514_9ADE_4D34_ABB1_165918EE589D__INCLUDED_

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
	BOOL InfoIsNull();
	virtual void OnCancel();
	virtual void OnOK();
	CEmployee(CWnd* pParent = NULL);   // standard constructor
	HANDLE  m_icdev;
// Dialog Data
	//{{AFX_DATA(CEmployee)
	enum { IDD = IDD_EMPLOYEE_DIALOG };
	CEdit	m_WordID;
	CEdit	m_Name;
	CComboBox	m_Sex;
	CEdit	m_Card;
	CEdit	m_Duty;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmployee)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEmployee)
	afx_msg void OnRefreshCard();
	afx_msg void OnExit();
	afx_msg void OnButtoncancel();
	afx_msg void OnAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMPLOYEE_H__D36A3514_9ADE_4D34_ABB1_165918EE589D__INCLUDED_)
