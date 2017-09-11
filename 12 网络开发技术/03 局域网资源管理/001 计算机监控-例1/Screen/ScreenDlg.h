// ScreenDlg.h : header file
//
#include "TCPServer.h"
#if !defined(AFX_SCREENDLG_H__9DB60DB4_6CA7_45EC_997B_1FC964D08D10__INCLUDED_)
#define AFX_SCREENDLG_H__9DB60DB4_6CA7_45EC_997B_1FC964D08D10__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CScreenDlg dialog

class CScreenDlg : public CDialog
{
// Construction
protected:
	bool run;
	BITMAP bitmap;
	int size;
	char * bmpdata;
	void GetScreen();
	void DrawScreen();
public:
	CTCPClientSocket clientsocket;
	CScreenDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CScreenDlg)
	enum { IDD = IDD_SCREEN_DIALOG };
	CStatic	m_drawscreen;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScreenDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CScreenDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCREENDLG_H__9DB60DB4_6CA7_45EC_997B_1FC964D08D10__INCLUDED_)
