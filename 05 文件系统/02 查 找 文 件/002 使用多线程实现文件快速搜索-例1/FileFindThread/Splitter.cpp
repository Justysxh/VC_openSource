// Splitter.cpp : implementation file
//

#include "stdafx.h"
#include "FileFindThread.h"
#include "Splitter.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSplitter
IMPLEMENT_DYNCREATE(CSplitter,CWnd)
CSplitter::CSplitter()
{
	RegisterWindowClass();
	m_CanMove = false;
}

CSplitter::~CSplitter()
{
}


BEGIN_MESSAGE_MAP(CSplitter, CWnd)
	//{{AFX_MSG_MAP(CSplitter)
	ON_WM_MBUTTONDOWN()
	ON_WM_MBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CSplitter message handlers

BOOL CSplitter::RegisterWindowClass()
{
    WNDCLASS wndcls;
    HINSTANCE hInst = AfxGetInstanceHandle();
   // HINSTANCE hInst = AfxGetResourceHandle(); 

    if (!(::GetClassInfo(hInst, SPLITTER_CLASSNAME, &wndcls)))
    {
        // otherwise we need to register a new class
        wndcls.style            = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
        wndcls.lpfnWndProc      = ::DefWindowProc;
        wndcls.cbClsExtra       = wndcls.cbWndExtra = 0;
        wndcls.hInstance        = hInst;
        wndcls.hIcon            = NULL;
        wndcls.hCursor          = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
        wndcls.hbrBackground    = (HBRUSH) (COLOR_3DFACE + 1);
        wndcls.lpszMenuName     = NULL;
        wndcls.lpszClassName    = SPLITTER_CLASSNAME;

        if (!AfxRegisterClass(&wndcls)) {
            AfxThrowResourceException();
            return FALSE;
        }
    }

    return TRUE;
}

BOOL CSplitter::Create(CWnd* pParentWnd, UINT nID, DWORD dwStyle)
{
    ASSERT(pParentWnd->GetSafeHwnd());

	m_Width = DEFAULT_WIDTH;
	CRect ParentRect;
	pParentWnd->GetClientRect(&ParentRect);
	m_Height = ParentRect.Height();
	m_Left = 0;
	m_Top = 0;
	
    if (!CWnd::Create(SPLITTER_CLASSNAME, NULL, dwStyle, GetRect(), pParentWnd, nID)) 
        return FALSE;

	//this->ModifyStyleEx(0,WS_EX_CLIENTEDGE);
    return TRUE;
}

CRect CSplitter::GetRect()
{
	return CRect(m_Left,m_Top,m_Left + m_Width,
				m_Top + m_Height);
}

void CSplitter::OnMButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	CWnd::OnMButtonDown(nFlags, point);
}

void CSplitter::OnMButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CWnd::OnMButtonUp(nFlags, point);
}

void CSplitter::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (nFlags = MK_LBUTTON && m_CanMove)
	{
		CRect rect = GetRect();
		if (m_MoveX > point.x)
		{
			rect.left = rect.left - (m_MoveX - point.x);
		}else if(m_MoveX < point.x)
		{
			rect.left = rect.left + (point.x - m_MoveX);
		}
		this->MoveWindow(&rect,true);
		m_Left = rect.left;

	}
	CWnd::OnMouseMove(nFlags, point);
}

void CSplitter::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if (m_CanMove == false)
	{
		m_CanMove = true;
		m_MoveX = point.x;
	}
	CWnd::OnLButtonDown(nFlags, point);
}

void CSplitter::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if (m_CanMove)
		m_CanMove = false;
	CWnd::OnLButtonUp(nFlags, point);
}
