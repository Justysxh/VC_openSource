// Shaddlg1.cpp : implementation file
//

#include "stdafx.h"
#include "Shadow.h"
#include "Shaddlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShaddlg1 dialog


CShaddlg1::CShaddlg1(CWnd* pParent /*=NULL*/)
	: CDialog(CShaddlg1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShaddlg1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CShaddlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShaddlg1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CShaddlg1, CDialog)
	//{{AFX_MSG_MAP(CShaddlg1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShaddlg1 message handlers

BOOL CShaddlg1::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//设置窗口扩展风格
	SetWindowLong(GetSafeHwnd(),GWL_EXSTYLE,
		GetWindowLong(GetSafeHwnd(),GWL_EXSTYLE) | 0x80000);
	typedef BOOL (WINAPI *FSetLayeredWindowAttributes)(HWND,COLORREF,BYTE,DWORD);
	FSetLayeredWindowAttributes SetLayeredWindowAttributes ;
	HINSTANCE hInst = LoadLibrary("User32.DLL");
	SetLayeredWindowAttributes = (FSetLayeredWindowAttributes)
	GetProcAddress(hInst,"SetLayeredWindowAttributes");
	if(SetLayeredWindowAttributes)
	SetLayeredWindowAttributes(GetSafeHwnd(),RGB(0,0,0),128,1);
	FreeLibrary(hInst);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
