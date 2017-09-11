// bmpDoc.cpp : implementation of the CBmpDoc class
//

#include "stdafx.h"
#include "bmp.h"

#include "bmpDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBmpDoc

IMPLEMENT_DYNCREATE(CBmpDoc, CDocument)

BEGIN_MESSAGE_MAP(CBmpDoc, CDocument)
	//{{AFX_MSG_MAP(CBmpDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBmpDoc construction/destruction

CBmpDoc::CBmpDoc()
{
	// TODO: add one-time construction code here

}

CBmpDoc::~CBmpDoc()
{
}

BOOL CBmpDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBmpDoc serialization

void CBmpDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CBmpDoc diagnostics

#ifdef _DEBUG
void CBmpDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBmpDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBmpDoc commands

BOOL CBmpDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
//	if (!CDocument::OnOpenDocument(lpszPathName))
//		return FALSE;
	
	// TODO: Add your specialized creation code here
	if (IsModified())
		TRACE0("Warning: OnOpenDocument replaces an unsaved document\n");
	DeleteContents();
	//设置等待鼠标
	BeginWaitCursor();
	//打开位图文件
	HBITMAP hImage = (HBITMAP)LoadImage(NULL, lpszPathName, IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE|LR_CREATEDIBSECTION|LR_DEFAULTSIZE);
	EndWaitCursor();
	if (!hImage) {
		DWORD LastError = GetLastError();
		AfxMessageBox("LoadImage failed");
		return FALSE;
	}
	//构造位图对象
	if (!m_Bitmap.Attach(hImage)) 
	{
		AfxMessageBox("Bitmap could not be attached");
		return FALSE;
	}
	SetModifiedFlag(FALSE);
	//更新所有视图
	UpdateAllViews(NULL);
	return TRUE;
}

void CBmpDoc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
	//清除位图资源
	if (m_Bitmap.m_hObject != NULL)
		m_Bitmap.DeleteObject();
	CDocument::DeleteContents();
}
