// MyBrowerView.cpp : implementation of the CMyBrowerView class
//

#include "stdafx.h"
#include "MyBrower.h"
#include "MainFrm.h"
#include "MyBrowerDoc.h"
#include "MyBrowerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyBrowerView

IMPLEMENT_DYNCREATE(CMyBrowerView, CHtmlView)

BEGIN_MESSAGE_MAP(CMyBrowerView, CHtmlView)
	//{{AFX_MSG_MAP(CMyBrowerView)
	ON_BN_CLICKED(IDC_RUN, OnButtonsite)
	ON_EN_CHANGE(IDC_EDADDRESS, OnChangeEdaddress)
	ON_BN_CLICKED(IDC_BTBACK, OnButtonback)
	ON_BN_CLICKED(IDC_BTFORWARD, OnButtonfroward)
	ON_BN_CLICKED(IDC_BTSTOP, OnButtonstop)
	ON_BN_CLICKED(IDC_BTREFRESH, OnButtonrefresh)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CHtmlView::OnFilePrint)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyBrowerView construction/destruction

CMyBrowerView::CMyBrowerView()
{
	// TODO: add construction code here

}

CMyBrowerView::~CMyBrowerView()
{
}

BOOL CMyBrowerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyBrowerView drawing

void CMyBrowerView::OnDraw(CDC* pDC)
{
	CMyBrowerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CMyBrowerView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	// TODO: This code navigates to a popular spot on the web.
	//  change the code to go where you'd like.
	Navigate2(_T("abuout blank"),NULL,NULL);
}

/////////////////////////////////////////////////////////////////////////////
// CMyBrowerView printing


/////////////////////////////////////////////////////////////////////////////
// CMyBrowerView diagnostics

#ifdef _DEBUG
void CMyBrowerView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CMyBrowerView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CMyBrowerDoc* CMyBrowerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyBrowerDoc)));
	return (CMyBrowerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyBrowerView message handlers

void CMyBrowerView::OnButtonsite() 
{
	CClientDC dc(this);
	Navigate2(strsite,NULL,NULL);
	Invalidate(FALSE);
}

void CMyBrowerView::OnChangeEdaddress() 
{
	CMainFrame *pw=(CMainFrame *)AfxGetMainWnd();
	CDialogBar *pb=&(pw->m_DlgToolBar);
	pb->GetDlgItemText(IDC_EDADDRESS,strsite);
	
}
void CMyBrowerView::OnButtonback()
{
	this->GoBack();
}

void CMyBrowerView::OnButtonfroward()
{
	this->GoForward();
}
void CMyBrowerView::OnButtonstop()
{
	this->Stop();
}
void CMyBrowerView::OnButtonrefresh()
{
	this->Refresh();
}