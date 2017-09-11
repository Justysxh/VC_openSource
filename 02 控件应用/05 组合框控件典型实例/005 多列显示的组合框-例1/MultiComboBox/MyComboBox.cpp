// MyComboBox.cpp : implementation file
//

#include "stdafx.h"
#include "MultiComboBox.h"
#include "MyComboBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MyComboBox

MyComboBox::MyComboBox()
{
}

MyComboBox::~MyComboBox()
{
}


BEGIN_MESSAGE_MAP(MyComboBox, CComboBox)
	//{{AFX_MSG_MAP(MyComboBox)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MyComboBox message handlers
void MyComboBox::init()
{
	UINT itemindex;
	itemindex=CComboBox::AddString("row1");
	litem[0].AddHead("row1");
	litem[1].AddTail("1.00");
	litem[2].AddTail("11");
	itemindex=CComboBox::AddString("row2");
	litem[0].AddHead("row2");
	litem[1].AddTail("2.00");
	litem[2].AddTail("22");
	itemindex=CComboBox::AddString("row3");
	litem[0].AddHead("row3");
	litem[1].AddTail("3.00");
	litem[2].AddTail("3");
	this->SetCurSel(0);


}
void MyComboBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	
	CPen* pen; 
	CDC* pDC=CDC::FromHandle(lpDrawItemStruct->hDC);
	CWnd* pListBox=pDC->GetWindow();
	CRect rc1,rc2,rc3;
	CRect allrc=lpDrawItemStruct->rcItem;
	BOOL select=lpDrawItemStruct->itemState&ODS_SELECTED;
	BOOL focus=lpDrawItemStruct->itemAction&ODA_FOCUS;
	BOOL textfocus=lpDrawItemStruct->itemState&ODS_FOCUS;
	COLORREF textcolor=GetSysColor(COLOR_WINDOWTEXT);
	COLORREF selectcolor=GetSysColor(COLOR_HIGHLIGHT);
	COLORREF normalcolor= GetSysColor( COLOR_WINDOW );
	int width=allrc.Width()/3;
	rc1.SetRect(allrc.left,allrc.top,width,allrc.bottom);
	rc2.SetRect(rc1.right,rc1.top,2*width,allrc.bottom);
	rc3.SetRect(rc2.right,rc2.top,3*width,allrc.bottom);
	
	if(select)
	{
		POSITION pos=litem[0].FindIndex(lpDrawItemStruct->itemID);
		CString str1;str1=litem[0].GetAt(pos);
		pDC->DrawText(str1,-1,rc1,DT_CENTER);
	}
	else
	{
		POSITION pos=litem[0].FindIndex(lpDrawItemStruct->itemID);
		CString str1;str1=litem[0].GetAt(pos);
		pDC->DrawText(str1,-1,rc1,DT_CENTER);
		pos=litem[1].FindIndex(lpDrawItemStruct->itemID);
		CString str2;str2=litem[1].GetAt(pos);
		pDC->DrawText(str2,-1,rc2,DT_CENTER);
		pos=litem[2].FindIndex(lpDrawItemStruct->itemID);
		CString str3;str3=litem[2].GetAt(pos);
		pDC->DrawText(str3,-1,rc3,DT_CENTER);
		pDC->MoveTo(allrc.left,allrc.bottom-1);
		pDC->LineTo(allrc.right,allrc.bottom-1);
		pDC->MoveTo(rc1.right,rc1.top);
		pDC->LineTo(rc1.right,allrc.bottom-1);
		pDC->MoveTo(rc2.right,rc2.top);
		pDC->LineTo(rc2.right,allrc.bottom-1);
	}
	
	if(focus)
	{
		pDC->DrawFocusRect(allrc);
		
	}		
}

int MyComboBox::AddString(LPCTSTR lpszString)
{
	return AddItem(lpszString,0,CComboBox::GetCount());
}
int MyComboBox::AddItem(CString strItem,int nCol,int nRow,int nMask,int nFmt)
{
	int item;
	if(nRow==CComboBox::GetCount())
	item=CComboBox::AddString(strItem);
	litem[nCol].AddTail(strItem);
	return 1;
}
