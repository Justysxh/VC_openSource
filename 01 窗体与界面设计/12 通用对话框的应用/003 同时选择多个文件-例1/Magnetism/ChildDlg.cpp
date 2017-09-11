// ChildDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Magnetism.h"
#include "ChildDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildDlg dialog


CChildDlg::CChildDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChildDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChildDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_IsCreate = FALSE;
}


void CChildDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChildDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChildDlg, CDialog)
	//{{AFX_MSG_MAP(CChildDlg)
	ON_WM_MOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildDlg message handlers

void CChildDlg::OnMove(int x, int y) 
{
	CDialog::OnMove(x, y);
	
	// TODO: Add your message handler code here
	if(m_IsCreate == TRUE)
	{
		CRect pRect,cRect;
		GetWindowRect(cRect);
		this->GetParent()->GetWindowRect(pRect);
		if(cRect.left-pRect.right<20 && cRect.left-pRect.right>0 && (
			cRect.top>pRect.top-m_Height && cRect.bottom<pRect.bottom+m_Height))
			cRect.left = pRect.right;
		else if(pRect.left-cRect.right<20 && pRect.left-cRect.right>0 && (
			cRect.top>pRect.top-m_Height && cRect.bottom<pRect.bottom+m_Height))
			cRect.left = pRect.left - m_Width;
		else if(pRect.top-cRect.bottom<20 && pRect.top-cRect.bottom>0 && (
			cRect.left>pRect.left-m_Width && cRect.right<pRect.right+m_Width))
			cRect.top = pRect.top - m_Height;
		else if(cRect.top-pRect.bottom<20 && cRect.top-pRect.bottom>0 && (
			cRect.left>pRect.left-m_Width && cRect.right<pRect.right+m_Width))
			cRect.top = pRect.bottom;
		MoveWindow(cRect.left,cRect.top,m_Width,m_Height);
	}
}

BOOL CChildDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CRect rect;
	GetWindowRect(rect);
	m_Width = rect.Width();
	m_Height = rect.Height();
	m_IsCreate = TRUE;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
