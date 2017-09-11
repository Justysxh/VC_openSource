// Login.cpp : implementation file
//

#include "stdafx.h"
#include "kinescode.h"
#include "Login.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogin dialog


CLogin::CLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CLogin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogin)
	m_Port = _T("");
	m_ServerAddr = _T("");
	//}}AFX_DATA_INIT
}


void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogin)
	DDX_Text(pDX, IDC_PORT, m_Port);
	DDX_Text(pDX, IDC_SERVERADDR, m_ServerAddr);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogin, CDialog)
	//{{AFX_MSG_MAP(CLogin)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogin message handlers
