// JComboBox.cpp : implementation file
//
#include "stdafx.h"
#include "JComboBx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// CTitleTip

CTitleTip::CTitleTip()
{
	    // Register the window class if it has not already been registered.
	    WNDCLASS wndcls;
	    HINSTANCE hInst = AfxGetInstanceHandle();
	    if(!(::GetClassInfo(hInst, TITLETIP_CLASSNAME, &wndcls)))
	    {
		    // otherwise we need to register a new class
		    wndcls.style = CS_SAVEBITS ;
		    wndcls.lpfnWndProc = ::DefWindowProc;
		    wndcls.cbClsExtra = wndcls.cbWndExtra = 0;
		    wndcls.hInstance = hInst;
		    wndcls.hIcon = NULL;
		    wndcls.hCursor = LoadCursor( hInst, IDC_ARROW );
		    wndcls.hbrBackground = (HBRUSH)(COLOR_INFOBK + 1);	//COLOR_HIGHLIGHT;//
		    wndcls.lpszMenuName = NULL;
		    wndcls.lpszClassName = TITLETIP_CLASSNAME;
		    if (!AfxRegisterClass(&wndcls))
			    AfxThrowResourceException();
	    }
		TITLETIP_SHOW = TRUE;
		bFocusRect = FALSE;
}

CTitleTip::~CTitleTip()
{
}



BOOL CTitleTip::Create(CWnd * pParentWnd)
{
	    ASSERT_VALID(pParentWnd);
		//ASSERT( !::IsWindow( m_hWnd ) );
	    DWORD dwStyle = WS_BORDER | WS_POPUP; 
	    DWORD dwExStyle = WS_EX_TOOLWINDOW | WS_EX_TOPMOST;
	    m_pParentWnd = pParentWnd;
		//if (m_hWnd == NULL)
			return CreateEx( dwExStyle, 
							 TITLETIP_CLASSNAME, 
							 NULL, 
							 dwStyle, 
							 0, 
							 0, 
							 0, 
							 0, 
							 NULL, 
							 NULL, 
							 NULL );
		
		//return FALSE;
}


// Show		    - Show the titletip if needed
// rectTitle	    - The rectangle within which the original 
//			      title is constrained - in client coordinates
// lpszTitleText	    - The text to be displayed
// xoffset		    - Number of pixel that the text is offset from
//			      left border of the cell
void CTitleTip::Show(CRect rectTitle, LPCTSTR lpszTitleText, int xoffset /*=0*/)
{
	    ASSERT( ::IsWindow( m_hWnd ) );
	    //ASSERT( !rectTitle.IsRectEmpty() );

	  // Do not display the titletip is app does not have focus
	    if(( GetFocus() == NULL )||(!TITLETIP_SHOW))
		{
			if( IsWindowVisible() ) 
				ShowWindow(FALSE);	
			return;
		}


	    // Determine the width of the text
	    m_pParentWnd->ClientToScreen( rectTitle );

	   CClientDC dctmp(this);
		dc = CDC::FromHandle(dctmp.m_hDC);

		
	    CString strTitle(lpszTitleText);
		strTitle += _T("  ");
	    CFont *pFont = m_pParentWnd->GetFont(); // use same font as ctrl
	    dc->SelectObject( pFont );

	   CRect rectDisplay = rectTitle;
	    CSize size = dc->GetTextExtent( strTitle );

		rectDisplay.top   += 24;
		rectDisplay.bottom  += 25;
	    rectDisplay.left += xoffset-4;
	    rectDisplay.right = rectDisplay.left + size.cx +1;




	    // Do not display if the text fits within available space 
	    if( rectDisplay.right < rectTitle.right-xoffset-5 ){
			if( IsWindowVisible() ) 
				ShowWindow(FALSE);	//DestroyWindow();

			return;
		}

		
		//;
		if ( DCB_RESET == dc->GetBoundsRect(&rectTitle,DCB_RESET))
			 dc->SetBoundsRect(NULL,DCB_ENABLE);

		dc->SetTextColor(GetSysColor(COLOR_HIGHLIGHTTEXT));
	    dc->SetBkColor(GetSysColor(COLOR_HIGHLIGHT));
	 
	   // Show the titletip
	   // If titletip is already displayed, don't do anything.

	   if( IsWindowVisible() ) 
		{
				MoveWindow(rectDisplay.left, rectDisplay.top, 
		       rectDisplay.Width(), rectDisplay.Height());
				
				dc->FillSolidRect(&rectTitle,::GetSysColor(COLOR_HIGHLIGHT));
				//if rectDisplay is not being used, let me use it for Text area
				rectDisplay = rectTitle;
				rectDisplay.left += 2;
				dc->DrawText(strTitle,-1,rectDisplay, DT_LEFT | DT_SINGLELINE |
DT_NOPREFIX | DT_NOCLIP | DT_VCENTER);
				dc->DrawFocusRect(&rectTitle); 
		}
		else
		{
			SetWindowPos( &wndTop, rectDisplay.left, rectDisplay.top, 
			    rectDisplay.Width(), rectDisplay.Height(), 
			    SWP_SHOWWINDOW|SWP_NOACTIVATE );
			dc->SetBkMode( OPAQUE );
			dc->FillSolidRect(&rectTitle,::GetSysColor(COLOR_HIGHLIGHT));
			dc->DrawText(strTitle,-1,rectDisplay, DT_LEFT | DT_SINGLELINE | DT_NOPREFIX |
DT_NOCLIP | DT_VCENTER);
			dc->DrawFocusRect(&rectTitle);
		}

}




/////////////////////////////////////////////////////////////////////////////
// CJComboBox

CJComboBox::CJComboBox()
{
	TotalCol = 1;
	CHECKBOX = FALSE;
	m_pJStruct = NULL;
/*	pFirst = NULL;
	pCurrent = NULL;
	pObjDump = NULL;
*/
}
						
CJComboBox::~CJComboBox()
{
	////////////////////////////////////////////////////////////////
	// Yes, I could use MFC Collection class
	// But, it looks crappy anyway.
	// It doesn't give me a good practice approach.
	// Maybe one of these days I will use it (-; (when I became lazy)
	/////////////////////////////////////////////////////////////////
	POSITION pos = m_jcbList.GetHeadPosition();
	while (pos != NULL)
	{
		delete m_jcbList.GetNext(pos);
	}
	m_jcbList.RemoveAll();	
	
	///////////////////////////////////////////////////
	BOOL bSuccess = m_titletip.DestroyWindow();
/*	for(pCurrent = pFirst; pCurrent != NULL ; ){
		pObjDump = pCurrent;
		pCurrent = pCurrent->next;
		delete pObjDump;
	}*/
	CComboBox::~CComboBox();


}


BEGIN_MESSAGE_MAP(CJComboBox, CComboBox)
	//{{AFX_MSG_MAP(CJComboBox)
	ON_WM_MOUSEMOVE()
	ON_CONTROL_REFLECT(CBN_CLOSEUP, OnCloseup)
	//}}AFX_MSG_MAP

END_MESSAGE_MAP()




/////////////////////////////////////////////////////////////////////////////
// CJComboBox message handlers

 
// if your sorting scheme is different than a standard collating sequence, 
// such as one where the comparisons need to be case-insensitive.)
int CJComboBox::CompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct)
{
	return -1;
}


void CJComboBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	BOOL bFocus=(lpDrawItemStruct->itemAction & ODA_FOCUS);
	BOOL bDrawEntire=(lpDrawItemStruct->itemAction & ODA_FOCUS);
	BOOL bSelected = ((lpDrawItemStruct->itemState & ODS_SELECTED));

	//Hide the titletip first until dropdown is active
	//but titletip window has been initialised.... (-:
	m_titletip.TITLETIP_SHOW = GetDroppedState();

	if (bFocus||bSelected)
	{
		if (EDGE_STYLE == EDGE) 
			DrawDropList(lpDrawItemStruct, EDGE_HIGHLIGHT);
		else
			DrawDropList(lpDrawItemStruct,HIGH_LIGHT);
	}
	else
	{
		if (EDGE_STYLE == EDGE) 
			DrawDropList(lpDrawItemStruct, EDGE_NORMAL);
		else
			DrawDropList(lpDrawItemStruct,NORMAL);
	}
	
	if (CHECKBOX)
		if( (lpDrawItemStruct->itemID == CurSel))	//(bSelected)||
			DrawDropList(lpDrawItemStruct,CHECKED);
}


 
// You can actually specify variable heights as long as you set the 
// CBS_OWNERDRAWVARIABLE style.
void CJComboBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	// all items are of fixed size
	// must use CBS_OWNERDRAWVARIABLE for this to work
	if (EDGE_STYLE == EDGE)
		lpMeasureItemStruct->itemHeight = ITEM_HEIGHT;

}

//////////////////////////////////////////
//********************************************
//
/////////////////////////////////////////////
int CJComboBox::AddString(LPCTSTR lpszString)
{	
	//AfxMessageBox(lpszString);
	return CJComboBox::AddItem(lpszString,0,CComboBox::GetCount()); 
}

int CJComboBox::AddItem(CString strItem,int nCol,int nRow,int nMask,int nFmt)
{
	int CB_MSG;
	if (nColShow == nCol) //nRow == PrevRow && 
		CB_MSG = CComboBox::AddString(strItem);

	cItem[nCol].AddTail( strItem );
//	if(EDGE_STYLE == NORMAL)
		AddItemPtr(nCol,cItem[nCol].GetCount()-1);

	PrevRow = cItem[nCol].GetCount()-1;

	return CB_MSG; 

}
////////////////////////////////////////
//For index key lookup operations//////
/////////////////////////////////////////

void CJComboBox::AddItemPtr(int nCol, int nRow)
{												 
/////////////////////////////////////////////////////////////
// This portion of the code can be used if user set the 
// index starting from 0..n  
// I keep it for my half-day-wasting-time lesson.
// where pCurrent->next cannot be constructed 
// if the pCurrent is invalid.
////////////////////////////////////////////////////////////
// The portion below, the index can be starting anywhere
////////////////////////////////////////////////////////////
/*	// set Head position here
	if (!nRow)
	{
		if (!nCol)
		{
			//pFirst = (class CJStruct *) new (class CJStruct);
			pFirst = new CJStruct();
			pFirst->m_strKey[nCol] = cItem[nCol][nRow];
			pCurrent = pFirst;
		}	
		else
		if (nCol > 0)
			pCurrent->m_strKey[nCol] = cItem[nCol][nRow];
					
		if (pCurrent != NULL){
			pCurrent->m_nKey = nRow;
			CComboBox::SetItemDataPtr(nRow,pCurrent);
		}

	}
	else	
	if (nRow > 0)
	{	 */
//////////////////////////////////////////////////////////////////////////	
//THIS PORTION ! is my favorite. Without MFC Collection class, 
// I use a normal singly link-list to manipulate the entire Combobox.
// It works perfectly, and better than MFC, but cumbersome to use (must call Finish())..
// You are welcome to uncomment it, but you need to uncomment all the MFC Pointer List below.
// Don't forget to uncomment the portion in the header file too.
// Or, call me Combobox Guru at jack@fsec.ucf.edu  (-:
////////////////////////////////////////////////////////////////
/*		if (!nCol) 
		{
			if (pCurrent == NULL)
			{  
				// set Head position here
				pFirst = new CJStruct();
			    pCurrent = pFirst;
			}
			else
			{
				//////////////////////
				//Add the list here
				pCurrent->next = new CJStruct();
				pCurrent = pCurrent->next;
			}

			pCurrent->m_strKey[nCol] = cItem[nCol][nRow];
		}
		else
		if (nCol > 0)
			pCurrent->m_strKey[nCol] = cItem[nCol][nRow];

		if (pCurrent != NULL)
		{
			pCurrent->m_nKey = nRow;
			CComboBox::SetItemDataPtr(nRow,pCurrent);
		}
*/
//////////////////////////////////////////////////////////////////
//	}
//////////////////////////////////////////////////////////////////////
// This portion of the code is only applicable to MFC pointer Lists
// I keep it for my own reference in the future.
//////////////////////////////////////////////////////////////////////


	///////////////////////////////////////////////
	//Here we could use 
	//MFC Collection class method, too easy.
			
	if (!nCol) 
	{
		// set Head position here
		m_pJStruct = new CJStruct();
		m_jcbList.AddTail(m_pJStruct);
		POSITION pos = cItem[nCol].FindIndex(nRow);
		m_pJStruct->m_strKey[nCol] = cItem[nCol].GetAt(pos);
	}
	else
	if (nCol > 0)
		m_pJStruct->m_strKey[nCol] = cItem[nCol].GetAt(cItem[nCol].FindIndex(nRow));

	if (m_pJStruct != NULL)
	{
		m_pJStruct->m_nKey = nRow;
		CComboBox::SetItemDataPtr(nRow,m_pJStruct);
	}
			
		
}



void CJComboBox::DrawDropList(LPDRAWITEMSTRUCT lpDrawItemStruct,UINT STATE)
{
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	CRect rcItem(lpDrawItemStruct->rcItem);
	CRect rcText;
CString ss;
	switch(STATE)
	{
		case EDGE_HIGHLIGHT:
			pDC->SetTextColor(GetSysColor(COLOR_HIGHLIGHTTEXT));
			pDC->SetBkColor(GetSysColor(COLOR_HIGHLIGHT));
			rcItem.SetRect(rcItem.left+1,rcItem.top,rcItem.right-2,rcItem.bottom);
			pDC->FillRect(&rcItem,&CBrush(::GetSysColor(COLOR_HIGHLIGHT)));
			if(lpDrawItemStruct->itemID>=0)
				rcText =
OnDrawThisText(pDC,lpDrawItemStruct->rcItem,lpDrawItemStruct->itemID);		       

			
			if (CHECKBOX) 
			{
				rcItem.SetRect(rcItem.right-14,rcItem.top,rcItem.right+3,rcItem.bottom);
				pDC->DrawFrameControl(&rcItem, DFC_BUTTON, DFCS_CHECKED );
			}

			
			//rcItem = lpDrawItemStruct->rcItem;
			// You can set your own position for the Tooltip here
			rcText.SetRect(rcText.left+5,rcText.top,rcText.right+5,rcText.bottom); 
			//m_titletip.Show(rcItem, cItem[TotalCol-1][lpDrawItemStruct->itemID], 43 );
			m_titletip.Show(rcText,
cItem[TotalCol-1].GetAt(cItem[TotalCol-1].FindIndex(lpDrawItemStruct->itemID)), 0);
									 

		break;

		case EDGE_NORMAL:
			pDC->SetTextColor(GetSysColor(COLOR_WINDOWTEXT));
			pDC->SetBkColor(GetSysColor(COLOR_WINDOW));
		       
pDC->FillRect(&lpDrawItemStruct->rcItem,&CBrush(::GetSysColor(COLOR_WINDOW)));
			
			if(lpDrawItemStruct->itemID>=0)
				OnDrawThisText(pDC,lpDrawItemStruct->rcItem,lpDrawItemStruct->itemID);
			if (CHECKBOX) {
				rcItem.SetRect(rcItem.right-17,rcItem.top,rcItem.right+1,rcItem.bottom);
				ss.Format("%d-%d-%d-%d",rcItem.top,rcItem.left,rcItem.Height(),rcItem.Width());
			AfxMessageBox(ss);
				//if (lpDrawItemStruct->itemID == CurSel)
				//	pDC->DrawFrameControl(&rcItem, DFC_BUTTON, DFCS_CHECKED);
				//else
					pDC->DrawFrameControl(&rcItem, DFC_BUTTON, DFCS_BUTTONCHECK);
				// We don't need Focus Rect with border. it's too ugly.
				//pDC->DrawFocusRect(&lpDrawItemStruct->rcItem);
			}
	    break;

		case HIGH_LIGHT:
			pDC->SetTextColor(GetSysColor(COLOR_HIGHLIGHTTEXT));
			pDC->SetBkColor(GetSysColor(COLOR_HIGHLIGHT));
			pDC->FillRect(&rcItem,&CBrush(::GetSysColor(COLOR_HIGHLIGHT)));

			if (CHECKBOX) 
			{
				rcItem.SetRect(rcItem.right-17,rcItem.top,rcItem.right+1,rcItem.bottom);
				pDC->DrawFrameControl(&rcItem, DFC_BUTTON, DFCS_CHECKED );
			}
			
			rcItem = lpDrawItemStruct->rcItem;	
			rcItem.SetRect(rcItem.left-3,rcItem.top,rcItem.right,rcItem.bottom);
			if(lpDrawItemStruct->itemID>=0)
				OnDrawThisText(pDC,rcItem,lpDrawItemStruct->itemID);
			rcItem.SetRect(rcItem.left-3,rcItem.top,rcItem.right+20,rcItem.bottom);
			ss.Format("%d-%d-%d-%d",rcItem.top,rcItem.left,rcItem.Height(),rcItem.Width());
			AfxMessageBox(ss);
			pDC->DrawFocusRect(&rcItem);
			//int tmpCol;
			//if (EDGE_STYLE == NORMAL) 
			//	tmpCol = nColShow; 
			//else
			//	tmpCol = TotalCol-1;
			m_titletip.Show(rcItem,
cItem[nColShow].GetAt(cItem[nColShow].FindIndex(lpDrawItemStruct->itemID)), 10 );
			
		break;

		case NORMAL:
			pDC->SetTextColor(GetSysColor(COLOR_WINDOWTEXT));
			pDC->SetBkColor(GetSysColor(COLOR_WINDOW));
		       
pDC->FillRect(&lpDrawItemStruct->rcItem,&CBrush(::GetSysColor(COLOR_WINDOW)));
			
			if (CHECKBOX) {
				rcItem.SetRect(rcItem.right-17,rcItem.top,rcItem.right+1,rcItem.bottom);
				pDC->DrawFrameControl(&rcItem, DFC_BUTTON, DFCS_BUTTONCHECK);	     
		  
				pDC->DrawFocusRect(&lpDrawItemStruct->rcItem);
			}
			rcItem = lpDrawItemStruct->rcItem;	
			rcItem.SetRect(rcItem.left-3,rcItem.top,rcItem.right,rcItem.bottom);
			ss.Format("%d-%d-%d-%d",rcItem.top,rcItem.left,rcItem.Height(),rcItem.Width());
			AfxMessageBox(ss);
			if(lpDrawItemStruct->itemID>=0)
				OnDrawThisText(pDC,rcItem,lpDrawItemStruct->itemID);

	   break;

		case CHECKED:
			pDC->SetTextColor(GetSysColor(COLOR_WINDOWTEXT));
			pDC->SetBkColor(GetSysColor(COLOR_WINDOW));
		       
pDC->FillRect(&lpDrawItemStruct->rcItem,&CBrush(::GetSysColor(COLOR_WINDOW)));
	
			if(lpDrawItemStruct->itemID>=0)
				OnDrawThisText(pDC,lpDrawItemStruct->rcItem,lpDrawItemStruct->itemID);
			rcItem.SetRect(rcItem.right-17,rcItem.top,rcItem.right+1,rcItem.bottom);
			pDC->DrawFrameControl(&rcItem, DFC_BUTTON, DFCS_CHECKED);
	   break;

	}


	
}




BOOL CJComboBox::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT&
rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{

	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}




void CJComboBox::ResetContent(int tCol,int nJustify, BOOL bCheckBox, UINT nEdge,int ColDisplay)
{
	FormatList(tCol,nJustify, bCheckBox, nEdge,ColDisplay);
	CComboBox::ResetContent();
}

/////////////////////////////////////////////////////////////////
///// The older version of this CJComboBox will still be using FormatList()   ///////
/////  I override the ResetContent to be used the same way///
/////////////////////////////////////////////////
//	ColDisplay > -1 means you can HIDE the column that 
//	   is not ColDisplay as an index key for  database purposes...
//	   BUT tCol must be 0 to hide your selected column
void CJComboBox::FormatList(int tCol,int nJustify, BOOL bCheckBox, UINT nEdge,int ColDisplay)
{
	//Everything gets initialised here
	TotalCol = tCol;
	JUSTIFY = nJustify;
	CHECKBOX = bCheckBox;
	EDGE_STYLE = nEdge;
	PrevRow = -1;
	PrevCol = -1;
	CurSel = -1; 
	nColShow = ColDisplay;
	EnableToolTips(TRUE);
	m_pJStruct = NULL;
	//////////////////////////
	//Use for singly link-list only
	//pFirst = NULL;
	//pCurrent = NULL;
	//pCurrent->next = NULL;

}

CRect CJComboBox::OnDrawThisText(CDC* pDC,CRect rcItem,int itemID)
{

	CRect rcText = rcItem;
	CRect rcBorder = rcItem;	
	rcText.SetRect(rcText.left,rcText.top,rcText.left+3,rcText.bottom);
	rcBorder.SetRect(rcBorder.left,rcBorder.top,rcText.left+1,rcBorder.bottom);
	int wid = 0;
	for(int j=1;j<=TotalCol;j++){

		if (j!=TotalCol)
		{	
			rcText.SetRect(rcBorder.right+2,rcText.top,rcText.right+ wid,rcText.bottom);
			wid = DrawThisText(pDC,rcText,j-1,itemID);
	
			rcBorder.SetRect(rcBorder.right,rcBorder.top,rcBorder.right+wid,rcBorder.bottom);
			if ((EDGE_STYLE == EDGE)&&(itemID >= -1))
			{
				pDC->DrawEdge(&rcBorder,EDGE_ETCHED,BF_RECT);
			}
		}
		else
		if (j == TotalCol)
		{
			rcText.SetRect(rcBorder.right+4,rcText.top,rcBorder.right+ OFFSET_END,rcText.bottom);
			wid = DrawThisText(pDC,rcText,j-1,itemID);
			rcBorder.SetRect(rcBorder.right,rcBorder.top,rcItem.right-1,rcBorder.bottom);
			if ((EDGE_STYLE == EDGE)&&(itemID >= -1))
			{
				pDC->DrawEdge(&rcBorder,EDGE_ETCHED,BF_RECT); //
			}
		}
		
	}
	

	return rcBorder;// for One column 
}

int CJComboBox::DrawThisText(CDC * pDC,CRect rcText,
									 int nColumn,int nItem)
{
	CString str;


	if (EDGE_STYLE == EDGE) 
		rcText.SetRect(rcText.left,rcText.top+1,rcText.right,rcText.bottom);

	if ((nColumn >= 0)&&(nItem >= 0))
		if (nColShow >= TotalCol) //TRY WITH  (nColShow >= 0) I added this for version 2.0.99999 
			str = cItem[nColShow].GetAt(cItem[nColShow].FindIndex(nItem)); // so, you can hide the column you want
		else
			str = cItem[nColumn].GetAt(cItem[nColumn].FindIndex(nItem));

	if (str == _T("")) return 0;

	if (EDGE_STYLE == EDGE)
		pDC->DrawText(str,-1,rcText, JUSTIFY | DT_SINGLELINE | DT_NOPREFIX | DT_NOCLIP |
DT_VCENTER);
	else
	{	///////This operation is for showing hint when the box is droping down.////
		//rcText.SetRect(rcText.left,rcText.top,rcText.right+30,rcText.bottom);
		pDC->TabbedTextOut(rcText.left,rcText.top,str,0,NULL,rcText.left);

	}


	//plus offset for additional space between columns
	/////////////////////////////////////////////////////
	/* ALGORITHM (1)
	// This algorithm is faster but inaccurate-out-of-proof
	// Use can use this one by uncomment it and comment the other one
	//if (cItem[nColumn][GetCount()-nItem].GetLength() > cItem[nColumn][0].GetLength())
	 if (pDC->GetTextExtent(cItem[nColumn][GetCount()-nItem]).cx >
pDC->GetTextExtent(cItem[nColumn][0]).cx)
	{
		ColWidth[nColumn] = pDC->GetTextExtent(cItem[nColumn][nItem]).cx +12;
		SetRedraw(TRUE); // Redraw if the columns are different
	} 
	else
	if ((nItem==0) ||
		(pDC->GetTextExtent(cItem[nColumn][GetCount()-nItem]).cx ==
pDC->GetTextExtent(cItem[nColumn][0]).cx) )
		//Draw the first item then compare
		ColWidth[nColumn] = pDC->GetTextExtent(cItem[nColumn][0]).cx +12;
	else
		ColWidth[nColumn] = 0;
	*/
	////////////////////////////////////////////////////////////////
	//ALGORITHM (2)
	//This algorithm is slow but discretely proven to be accurate.
	//////////////////////////////////////////////////
	for (int i=0;i<=nItem;i++)
	{
		if (pDC->GetTextExtent(cItem[nColumn].GetAt(cItem[nColumn].FindIndex(i))).cx >=
pDC->GetTextExtent(cItem[nColumn].GetAt(cItem[nColumn].FindIndex(0))).cx)
			ColWidth[nColumn] =
pDC->GetTextExtent(cItem[nColumn].GetAt(cItem[nColumn].FindIndex(0))).cx +12; 
	}

    
	return ColWidth[nColumn];  

}


void CJComboBox::PreSubclassWindow() 
{
	ModifyStyleEx(WS_EX_TOPMOST,NULL,0);
	CComboBox::PreSubclassWindow();
	m_titletip.Create(this);

}




void CJComboBox::OnMouseMove(UINT nFlags, CPoint point) 
{
	m_titletip.TITLETIP_SHOW = TRUE;
	CComboBox::OnMouseMove(nFlags, point);
}

void CJComboBox::OnCloseup() 
{
	m_titletip.TITLETIP_SHOW = FALSE;
	CJComboBox::SetCurSel(CJComboBox::GetCurSel());

}




int CJComboBox::GetLBText(int nIndex, CString & rString,int col)
{
	rString = cItem[col].GetAt(cItem[col].FindIndex(nIndex));
	//CComboBox::GetLBText(nIndex,rString);
	return rString.GetLength();

}

int CJComboBox::SetCurSel(int nSelect)
{
	CurSel = nSelect;
	return CComboBox::SetCurSel(nSelect);
}

// nStartAfter = -1 to search for entire combobox
// nColSelect = which column you want to get data from
//	lpszString = returning the value you are requesting
//////////////////////////////////////////////////////
int CJComboBox::SelectString(LPCTSTR lpszString,int nStartAfter, int nColSelect)
{
// MFC Collection class search
	CJStruct * pCurrent;
	for (int nCol=-1;TotalCol>nCol;nCol++)
	{

		if (nStartAfter == -1) //search for entire combobox
		{
			POSITION pos = m_jcbList.GetHeadPosition();
			while (pos != NULL)
			{
				if (lpszString == (pCurrent = m_jcbList.GetNext(pos))->m_strKey[nCol+1])
					return CComboBox::SetCurSel(pCurrent->m_nKey);		     
	  
			}
	
		}
		else
		{	//if you don't want to search the entire Combobox
			POSITION pos = m_jcbList.GetHeadPosition();
			while (pos != NULL)
			{
				
				if (nStartAfter == (pCurrent = m_jcbList.GetNext(pos))->m_nKey)
				{
					if (lpszString == pCurrent->m_strKey[nCol+1])
						return CComboBox::SetCurSel(pCurrent->m_nKey);
					break;
				}
		
			}
		} //END ELSE

	} //end for
	//////////////////////////////////////////////////////////////////////////
	//Inductive proof to search for unknown column and row
/*	for (int nCol=-1;TotalCol>nCol;nCol++)
	{

		if (nStartAfter == -1) //search for entire combobox
		{
			for(pCurrent = pFirst; pCurrent!= NULL ;)
			{
				if (lpszString == pCurrent->m_strKey[nCol+1])
					return CComboBox::SetCurSel(pCurrent->m_nKey);
				pCurrent = pCurrent->next;
			}
	
		}
		else
		{	//if you don't want to search the entire Combobox
			for(pCurrent = pFirst; pCurrent != NULL ;)
			{
				if (nStartAfter == pCurrent->m_nKey)
					break;
				pCurrent = pCurrent->next;
			}
			//Start to search from nStartAfter
			if (pCurrent != NULL)
			{
				while(pCurrent != NULL)
				{
					if (lpszString == pCurrent->m_strKey[nCol+1])
						return CComboBox::SetCurSel(pCurrent->m_nKey);
					pCurrent = pCurrent->next;
				}
			}
		} //END ELSE

	} //end for
*/
	return CB_ERR;
	///////////////////////////////////////////////////////////////////////
}

CString CJComboBox::GetItemDataString(int nIndex, int nColumn)
{
	if (nIndex >= 0)
	{
		CJStruct* m_pJStruct = (CJStruct*)CComboBox::GetItemDataPtr(nIndex);
	if (m_pJStruct != NULL)
		return m_pJStruct->m_strKey[nColumn];
	}
	return _T("");
}


void CJComboBox::Finish()
{
	//pCurrent->next = NULL;

}

