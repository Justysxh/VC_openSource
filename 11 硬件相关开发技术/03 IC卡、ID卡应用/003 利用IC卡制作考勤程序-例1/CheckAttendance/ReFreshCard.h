#if !defined(AFX_REFRESHCARD_H__FA091B97_6C7A_47FF_A976_AA7FB7C0E6DA__INCLUDED_)
#define AFX_REFRESHCARD_H__FA091B97_6C7A_47FF_A976_AA7FB7C0E6DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReFreshCard.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReFreshCard dialog

class CReFreshCard : public CDialog
{
// Construction
public:
	CReFreshCard(CWnd* pParent = NULL);   // standard constructor

	HANDLE  m_icdev;
	BOOL    m_IsCard;  //¶Á¿¨Æ÷ÖÐÊÇ·ñÓÐ¿¨
// Dialog Data
	//{{AFX_DATA(CReFreshCard)
	enum { IDD = IDD_REFRESHCARD_DIALOG };
	CStatic	m_HINT;
	CEdit	m_WorkID;
	CEdit	m_Name;
	CComboBox	m_Sex;
	CEdit	m_ID;
	CEdit	m_Duty;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReFreshCard)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReFreshCard)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REFRESHCARD_H__FA091B97_6C7A_47FF_A976_AA7FB7C0E6DA__INCLUDED_)
