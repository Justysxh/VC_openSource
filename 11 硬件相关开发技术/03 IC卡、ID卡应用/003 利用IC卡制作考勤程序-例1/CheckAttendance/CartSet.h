#if !defined(AFX_CARTSET_H__1FF993E8_E889_485F_BADC_32832D8F8927__INCLUDED_)
#define AFX_CARTSET_H__1FF993E8_E889_485F_BADC_32832D8F8927__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CartSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCartSet dialog
#include "CardID.h"

class CCartSet : public CDialog
{
// Construction
public:
	CCartSet(CWnd* pParent = NULL);   // standard constructor
	
	BOOL    m_IsWrite;  //IC¿¨ÊÇ·ñ¿ÉÐ´
	HANDLE  m_icdev;
// Dialog Data
	//{{AFX_DATA(CCartSet)
	enum { IDD = IDD_DIALOG1 };
	CButton	m_Write;
	CCardID	m_Card;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCartSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCartSet)
	afx_msg void OnGenerateid();
	virtual BOOL OnInitDialog();
	afx_msg void OnWrite();
	afx_msg void OnRefreshcard();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARTSET_H__1FF993E8_E889_485F_BADC_32832D8F8927__INCLUDED_)
