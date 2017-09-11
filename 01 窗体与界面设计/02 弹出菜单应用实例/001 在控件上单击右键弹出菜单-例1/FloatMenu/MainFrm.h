// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__751A3B2D_CD5F_4C80_8F05_6034170E2AEE__INCLUDED_)
#define AFX_MAINFRM_H__751A3B2D_CD5F_4C80_8F05_6034170E2AEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MyDock.h"
#include "afxpriv.h"
#include "FloatDlg.h"
#include "FloatMenu1.h"
class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)
	CReBar  m_rebar;
	BOOL m_ispressed;
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:

	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CFloatMenu m_wndFloatTool;

	CToolBar    m_wndToolBar;

	CMyDock m_dock;

	CDockBar m_bar;
	CFloatDlg m_Dlg;
// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnButton32776();
	afx_msg void OnToolbarDropDown(NMTOOLBAR* pnmtb,LRESULT* plr);
	afx_msg void OnMenuitem32780111();
	afx_msg void OnButton32772();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__751A3B2D_CD5F_4C80_8F05_6034170E2AEE__INCLUDED_)
