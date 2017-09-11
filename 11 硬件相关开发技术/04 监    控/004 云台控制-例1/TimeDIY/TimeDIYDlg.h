// TimeDIYDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mscomm.h"
//}}AFX_INCLUDES

#if !defined(AFX_TIMEDIYDLG_H__CA1B6400_281A_4E4B_B308_1D51F4E057F3__INCLUDED_)
#define AFX_TIMEDIYDLG_H__CA1B6400_281A_4E4B_B308_1D51F4E057F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Sa7134Capture.h"
#include "Global.h"


/////////////////////////////////////////////////////////////////////////////
// CTimeDIYDlg dialog
#pragma comment (lib,"Sa7134Capture.lib")
#pragma comment (lib,"MediaTransmit.lib")

//定义按钮状态
enum ButtonState  {bsNormal,bsHot,bsDown};
//按钮包装类
class CDrawButton  
{
public:
	ButtonState m_State;           //按钮当前状态
	WNDPROC     m_OldProc;         //记录按钮的窗口函数
	int         m_Flag;            //是否释放关联按钮的CDrawButton对象
	static int  m_Style;           //按钮风格
public:

	CDrawButton( )
	{
		m_State   = bsNormal;
		m_OldProc = NULL;
		m_Flag    = 0;
	}

	virtual ~CDrawButton()
	{
		m_State   = bsNormal;
		m_OldProc = NULL;		
	};

	LRESULT OnPaint( HWND hWnd ) 
	{
		CWnd* pWnd = CWnd::FromHandle(hWnd);
		
		CPaintDC	dc(pWnd);
		CString		Text;
		CRect		RC;
		CFont		Font;
		CFont		*pOldFont;
		CBrush		Brush;
		CBrush		*pOldBrush;
		CPoint		PT(2,2);
		
		dc.SetBkMode( TRANSPARENT );
		Font.CreateFont( 12, 0, 0, 0, FW_HEAVY, 0, 0, 0, ANSI_CHARSET, \
			OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, \
			VARIABLE_PITCH | FF_SWISS, "MS Sans Serif" );

		pOldFont = dc.SelectObject( &Font );
		
		if( m_State == bsNormal)
		{
			
			if (m_Style==2)
			{
				CBitmap bmp;
				bmp.LoadBitmap(IDB_BKBUTTON);
				Brush.CreatePatternBrush(&bmp); 
			}
			else
				Brush.CreateSolidBrush( RGB( 200, 200, 200 ) );
			dc.SetTextColor( RGB( 80, 80, 80) );
		}
		else if( m_State == bsDown )
		{
			Brush.CreateSolidBrush( RGB( 160, 160, 160 ) );
			dc.SetTextColor( RGB( 50, 50, 250 ) );
		}
		else if( m_State == bsHot )
		{
			Brush.CreateSolidBrush( RGB( 100, 100, 180 ) );
			dc.SetTextColor( RGB( 250, 250, 0 ) );
		}
		
		pOldBrush = dc.SelectObject( &Brush );
		pWnd->GetClientRect( &RC );
		dc.RoundRect( &RC, PT );
		
		HRGN hRgn = CreateRectRgn( RC.left, RC.top, RC.right, RC.bottom );
		pWnd->SetWindowRgn( hRgn, TRUE );
		DeleteObject( hRgn );
		
		pWnd->GetWindowText(Text );
		dc.DrawText( Text, &RC, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
		
		dc.SelectObject( pOldFont );
		dc.SelectObject( pOldBrush );
		
		return TRUE;
	}
	LRESULT OnLButtonDown( HWND hWnd, UINT nFlags, CPoint point )
	{
		m_State = bsDown;		
		SetCapture(hWnd);
		SetFocus(hWnd);
		return TRUE;
	}
	
	LRESULT OnLButtonUp( HWND hWnd, UINT nFlags, CPoint point )
	{
		if( m_State != bsNormal )
		{
			m_State = bsNormal;
			ReleaseCapture();
			InvalidateRect(hWnd,NULL,TRUE);
			SendMessage( GetParent(hWnd), WM_COMMAND, GetDlgCtrlID(hWnd), (LPARAM) (hWnd) );
		}
		return TRUE;
	}

	LRESULT LoseFocus(HWND  hWnd)
	{
		m_State = bsNormal;
		InvalidateRect(hWnd,NULL,TRUE);
		SendMessage( hWnd, WM_KILLFOCUS, (long)hWnd, 0);	
		return TRUE;
	}

	LRESULT OnMouseMove(HWND hWnd, UINT nFlags, CPoint point ) {
		HRGN hRgn = CreateRectRgn( 0, 0, 0, 0 );
		GetWindowRgn( hWnd,hRgn );
		BOOL ret = PtInRegion( hRgn, point.x, point.y );
		if( ret ) 
		{
			
			if( m_State == bsDown) 
				return TRUE;
			if( m_State != bsHot ) 
			{
				m_State = bsHot;
				InvalidateRect(hWnd,NULL,TRUE);
				UpdateWindow(hWnd);
				SetCapture(hWnd);
			}
		} 
		else 
		{
			m_State = bsNormal;
			InvalidateRect(hWnd,NULL,TRUE);	
			ReleaseCapture();
		}	
		DeleteObject( hRgn );
		return TRUE;
	}
};

class CTimeDIYDlg : public CDialog
{

public:
	//成员变量
	unsigned char (*m_pData) [100];  //端口数据
	int      m_Len ;                //云台协议使用的字节数
	int      m_ActoinCount;         //云台控制动作数
	int      m_Port;                //端口号
	CString  m_Setting;             //端口信息
	BOOL     m_Tail;                //是否开始监控
	HANDLE   m_hThread;             //线程句柄

// Construction
public:
	CTimeDIYDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTimeDIYDlg)
	enum { IDD = IDD_TIMEDIY_DIALOG };
	CDateTimeCtrl	m_Time;
	CStatic	m_Panel;
	CMSComm	m_Com;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeDIYDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTimeDIYDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnWindowPosChanged(WINDOWPOS FAR* lpwndpos);
	afx_msg void OnStartTail();
	afx_msg void OnStopTail();
	afx_msg void OnCloudMsg();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnQuit();
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnLeft();
	afx_msg void OnRight();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMEDIYDLG_H__CA1B6400_281A_4E4B_B308_1D51F4E057F3__INCLUDED_)
