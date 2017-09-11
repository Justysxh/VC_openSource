// MainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DocViewPrint.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainDlg dialog


CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainDlg::IDD, pParent)
{
	IsPreview = FALSE;
	//{{AFX_DATA_INIT(CMainDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	//{{AFX_MSG_MAP(CMainDlg)
	ON_BN_CLICKED(IDC_PRINT, OnPrint)
	ON_BN_CLICKED(IDC_QUIT, OnQuit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainDlg message handlers

void CMainDlg::OnOK() 
{


}

void CMainDlg::OnPrint() 
{
	AfxGetApp()->m_pMainWnd = NULL;
	AfxGetApp()->m_pDocManager->OnFileNew();
	IsPreview= TRUE;
}

void CMainDlg::OnQuit() 
{
	OnCancel();	
}

BOOL CMainDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//add  columns for list
	m_list.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);

	m_list.InsertColumn(100,"姓名",LVCFMT_LEFT,100);
	m_list.InsertColumn(100,"语文",LVCFMT_LEFT,70);
	m_list.InsertColumn(100,"数学",LVCFMT_LEFT,70);	
	m_list.InsertColumn(100,"英语",LVCFMT_LEFT,70);
	m_list.InsertColumn(100,"政治",LVCFMT_LEFT,70);	
	m_list.InsertColumn(100,"历史",LVCFMT_LEFT,70);

	CString temp;
	int grade;
	//add data to list
	for (int i = 0;i<10;i++)
	{
		m_list.InsertItem(i,"");
		for (int c = 1;c<6;c++)
		{
			grade = c*2+80+i;
			temp.Format("%d",grade);
			m_list.SetItemText(i,c,temp);
		}
	}

	m_list.SetItemText(0,0,"王平");
	m_list.SetItemText(1,0,"李可");
	m_list.SetItemText(2,0,"张红");
	m_list.SetItemText(3,0,"周亮");
	m_list.SetItemText(4,0,"孙军");
	m_list.SetItemText(5,0,"刘海");
	m_list.SetItemText(6,0,"王中华");
	m_list.SetItemText(7,0,"宋可平");
	m_list.SetItemText(8,0,"张男");
	m_list.SetItemText(9,0,"李菊");

	return TRUE; 
}

void CMainDlg::OnCancel()
{
	if (!IsPreview)
		PostQuitMessage(0);
}
