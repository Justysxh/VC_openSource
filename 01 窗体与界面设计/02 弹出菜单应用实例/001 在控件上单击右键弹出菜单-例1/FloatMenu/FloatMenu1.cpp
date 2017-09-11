// FloatMenu1.cpp : implementation file
//

#include "stdafx.h"
#include "FloatMenu.h"
#include "FloatMenu1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFloatMenu

CFloatMenu::CFloatMenu()
{
	MenuPopIndex = -1;
}

CFloatMenu::~CFloatMenu()
{

}


BEGIN_MESSAGE_MAP(CFloatMenu, CToolBar)
	//{{AFX_MSG_MAP(CFloatMenu)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFloatMenu message handlers

BOOL CFloatMenu::AddButtonFromMenu(UINT IDresource)
{
	CMenu Menu ;
	if (Menu.LoadMenu(IDresource))
	{
		//获取菜单顶层菜单数
		UINT ButtonCount = Menu.GetMenuItemCount();
		UINT * array = new UINT[ButtonCount];

		CString text;
		for (int n = 0; n<ButtonCount;n++)
		{
			array[n]=ID_BUTTON1 +n;
		}
		SetButtons(array,ButtonCount);
		for (int i=0;i<ButtonCount;i++)
		{
			Menu.GetMenuString(i,text,MF_BYPOSITION);
			SetButtonText(i,text);
			SetButtonStyle(i,TBSTYLE_DROPDOWN);	
		}

		delete array;
		Menu.DestroyMenu();
		return true;
	}
	else
		return FALSE;
}

void CFloatMenu::OnMouseMove(UINT nFlags, CPoint point) 
{
	CToolBar::OnMouseMove(nFlags, point);
	if (MenuPopIndex!= -1)
	{
		if(m_pSubMenu)
		{
			if (MenuPopIndex==GetIndexFromPoint(point))
				m_pSubMenu->DestroyMenu();
		}
	}
}

UINT CFloatMenu::GetIndexFromPoint(CPoint pot)
{
	CRect rect;
	for (int i = 0;i< GetToolBarCtrl().GetButtonCount()-1;i++)
	{
		GetItemRect(i,rect);
		if (rect.PtInRect(pot))
			return i;
	}
	return -1;
}
