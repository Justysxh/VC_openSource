#if !defined(AFX_DISPLAYWND_H__88A7FB4B_79C7_4381_A2C6_6AEF2EA3AC09__INCLUDED_)
#define AFX_DISPLAYWND_H__88A7FB4B_79C7_4381_A2C6_6AEF2EA3AC09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DisplayWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDisplayWnd dialog



class CDisplayWnd : public CDialog
{
// Construction
public:
	CDisplayWnd(CWnd* pParent = NULL);   // standard constructor
	CBitmap bmp;
// Dialog Data
	//{{AFX_DATA(CDisplayWnd)
	enum { IDD = IDD_DISPLAYWND_DIALOG };
	CStatic	m_Panel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDisplayWnd)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDisplayWnd)
	virtual void OnOK();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnFullscreen();
	afx_msg void OnGrayimage();
	afx_msg void OnStopplay();
	afx_msg void OnPlayfile();
	afx_msg void OnVideoset();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISPLAYWND_H__88A7FB4B_79C7_4381_A2C6_6AEF2EA3AC09__INCLUDED_)
