#if !defined(AFX_CHILDDLG_H__2806C486_7BC1_41D3_945D_F6358B9F754D__INCLUDED_)
#define AFX_CHILDDLG_H__2806C486_7BC1_41D3_945D_F6358B9F754D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChildDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChildDlg dialog

class CChildDlg : public CDialog
{
// Construction
public:
	CChildDlg(CWnd* pParent = NULL);   // standard constructor
	int m_Width;
	int m_Height;
	BOOL m_IsCreate;

// Dialog Data
	//{{AFX_DATA(CChildDlg)
	enum { IDD = IDD_CHILD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChildDlg)
	afx_msg void OnMove(int x, int y);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDDLG_H__2806C486_7BC1_41D3_945D_F6358B9F754D__INCLUDED_)
