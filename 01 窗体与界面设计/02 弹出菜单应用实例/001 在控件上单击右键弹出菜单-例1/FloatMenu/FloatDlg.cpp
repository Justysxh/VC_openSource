// FloatDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FloatMenu.h"
#include "FloatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFloatDlg dialog


CFloatDlg::CFloatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFloatDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFloatDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFloatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFloatDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFloatDlg, CDialog)
	//{{AFX_MSG_MAP(CFloatDlg)
	ON_WM_LBUTTONDOWN()
	//ON_COMMAND(ID_BUTTON32776, OnButton32776)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFloatDlg message handlers

void CFloatDlg::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CFloatDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	::PostMessage(GetParent()->m_hWnd,WM_LBUTTONDOWN,10,10);	
	CDialog::OnLButtonDown(nFlags, point);
}

void CFloatDlg::OnButton32776() 
{
		
}
