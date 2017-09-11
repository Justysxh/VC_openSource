// RegFigureDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RegFigure.h"
#include "RegFigureDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegFigureDlg dialog

CRegFigureDlg::CRegFigureDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRegFigureDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegFigureDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_Buttondowned = FALSE;
	m_curpen= 0;
	m_Isreg = FALSE;
	
	m_Figure.DotCount = 0;
}

void CRegFigureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegFigureDlg)
	DDX_Control(pDX, IDC_PANEL, m_Panel);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRegFigureDlg, CDialog)
	//{{AFX_MSG_MAP(CRegFigureDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_REG, OnReg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegFigureDlg message handlers

BOOL CRegFigureDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	pen.CreatePen(PS_SOLID,5,RGB(0,0,0));
	
	m_Panel.GetClientRect(m_rect);
	//MapWindowPoints(&m_Panel,m_rect);

	m_Figure.DotCount = 0;

	for (int i =0; i<16; i++)
	{
		m_Figure.Direction[i]= none;
	}


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRegFigureDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRegFigureDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
	//m_rect.CopyRect(CRect (50,80,200,300));
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRegFigureDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRegFigureDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	m_Buttondowned = TRUE;
	m_Startpt = point;
	m_Prept = point;
	
	if(m_rect.PtInRect(point))
			m_Figure.DotCount += 1;
	CDialog::OnLButtonDown(nFlags, point);
}

void CRegFigureDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	m_curpen ++;
	m_Endpt = point;
	m_Buttondowned = FALSE;	
	CDialog::OnLButtonUp(nFlags, point);
}

void CRegFigureDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	if (m_Buttondowned)
		if (m_rect.PtInRect(point))
		{
			CDC* pDC = m_Panel.GetDC();
			pDC->SelectObject(&pen);
			pDC->MoveTo(point);
			pDC->LineTo(CPoint(point.x+1,point.y+1));
			
			if (m_curpen>15)
				return;
			if (point.x>m_Prept.x+30) //ÏòÓÒ
			{
				if (m_Figure.Direction[m_curpen]==none)
					m_Figure.Direction[m_curpen] = right;
				else if (m_Figure.Direction[m_curpen] != right)
				{
					m_curpen+=1;
					m_Figure.Direction[m_curpen] = right;		
				}
				m_Prept = point;
			}
			else if (point.y>m_Prept.y+30)
			{
				if (m_Figure.Direction[m_curpen]==none)
					m_Figure.Direction[m_curpen] = down;
				else if (m_Figure.Direction[m_curpen] != down)
				{
					m_curpen+=1;
					m_Figure.Direction[m_curpen] = down;		
				}
				m_Prept = point;
			}
			else if (point.x<m_Prept.x-30)
			{
				if (m_Figure.Direction[m_curpen]==none)
					m_Figure.Direction[m_curpen] = left;
				else if (m_Figure.Direction[m_curpen] != left)
				{
					m_curpen+=1;
					m_Figure.Direction[m_curpen] = left;						
				}
				m_Prept = point;
			}
			else if (point.y< m_Prept.y-30)
			{
				if (m_Figure.Direction[m_curpen]==none)
					m_Figure.Direction[m_curpen]= up;
				else if (m_Figure.Direction[m_curpen] != up)
				{
					m_curpen+=1;
					m_Figure.Direction[m_curpen] = up;						
				}
				m_Prept = point;
			}		
		}	
	CDialog::OnMouseMove(nFlags, point);
}

void CRegFigureDlg::DrawGrid(int row, int col)
{
	CDC* pDC = m_Panel.GetDC();
	CRect rect;
	m_Panel.GetClientRect(rect);
	for (int i = 0; i<row+1; i++)
	{	
		pDC->MoveTo(0,i*30);
		pDC->LineTo(rect.Width(),i*30);
	}
	
	for (int j = 0; j<col+1;j++)
	{
		pDC->MoveTo(j*30,0);
		pDC->LineTo(j*30,rect.Height());	
	}
}

void CRegFigureDlg::OnOK() 
{
	DrawGrid(9,9);
}

void CRegFigureDlg::OnReg() 
{
	m_curpen = 0;
	if (m_Figure.Direction[0]==down) //ÅÐ¶Ï1
		if (m_Figure.Direction[1]==none)
		{
			if ( m_Figure.DotCount == 1)
			{
				MessageBox("1");
				for (int i =0; i<16; i++)
				{
					m_Figure.Direction[i]= none;
				}
				m_Figure.DotCount = 0;
				m_Panel.Invalidate();
				return;
			}
		}
	
	if (m_Figure.Direction[0]==right) //ÅÐ¶Ï7
		if (m_Figure.Direction[1]==down)
			if (m_Figure.Direction[2]==none)
		{
			if ( m_Figure.DotCount == 1)
			{
				MessageBox("7");
				for (int i =0; i<16; i++)
				{
					m_Figure.Direction[i]= none;
				}
				m_Figure.DotCount = 0;
				m_Panel.Invalidate();
				return;
			}
		}

	if (m_Figure.Direction[0]==right) //ÅÐ¶Ï2 
		if (m_Figure.Direction[1]==down)
		{
			if (m_Figure.DotCount == 1)
			{
				if (m_Figure.Direction[2]==left)
				{
					if (m_Figure.Direction[3]==right)
						if ( m_Figure.Direction[4]==none)
						{
							MessageBox("2");
							for (int i =0; i<16; i++)
							{
								m_Figure.Direction[i]= none;
							}
							m_Figure.DotCount = 0;
							m_Panel.Invalidate();
							return;
						}
				}
				else if (m_Figure.Direction[2]==right)
				{
					if (m_Figure.Direction[3]==none)
					{
						MessageBox("2");
					
						for (int i =0; i<16; i++)
						{
							m_Figure.Direction[i]= none;
						}
						m_Figure.DotCount = 0;
						m_Panel.Invalidate();
						return;
					}
				}
			}
		}
	if (m_Figure.Direction[0]==right) //ÅÐ¶Ï3
		if (m_Figure.Direction[1]==down)
			if (m_Figure.DotCount==1)
			{
				if (m_Figure.Direction[2]==left)
					if (m_Figure.Direction[3]==right)
						
					{
						MessageBox("3");					
					}
			
				for (int i =0; i<16; i++)
				{
					m_Figure.Direction[i]= none;
				}
				m_Figure.DotCount = 0;
				m_Panel.Invalidate();
				return;			
			}

	if (m_Figure.Direction[0]==down) //ÅÐ¶Ï4
		if (m_Figure.Direction[1]==right)
			if (m_Figure.DotCount==2)
			{
				if(m_Figure.Direction[2]==down)
					if(m_Figure.Direction[3]==none)				
					{
						for (int i =0; i<16; i++)
						{
							m_Figure.Direction[i]= none;
						}
						m_Figure.DotCount = 0;
						m_Panel.Invalidate();
						MessageBox("4");
						return;	
					}		
			}

	if (m_Figure.Direction[0]==down) //ÅÐ¶Ï5
		if (m_Figure.Direction[1]==right)
			if (m_Figure.DotCount==2)

				if(m_Figure.Direction[2]==down)
					if(m_Figure.Direction[3]==left)
						if(m_Figure.Direction[4]==right)
							if (m_Figure.Direction[5]==none)
							{
								MessageBox("5");
								for (int i =0; i<16; i++)
								{
									m_Figure.Direction[i]= none;
								}
								m_Figure.DotCount = 0;
								m_Panel.Invalidate();
								return;			
							}
		if (m_Figure.DotCount==1)//ÅÐ¶Ï6
			if (m_Figure.Direction[1]==down) 
				if (m_Figure.Direction[2]==right)
				if(m_Figure.Direction[3]==up)
					if(m_Figure.Direction[4]==left)
							{
								MessageBox("6");
								for (int i =0; i<16; i++)
								{
									m_Figure.Direction[i]= none;
								}
								m_Figure.DotCount = 0;
								m_Panel.Invalidate();
								return;			
							}

		if (m_Figure.DotCount==1)//ÅÐ¶Ï8
		{
			if ( m_Figure.Direction[0]==left)
			{
				if (m_Figure.Direction[1]==down)
					if(m_Figure.Direction[2]==left)
						if(m_Figure.Direction[3]==up)
							if(m_Figure.Direction[4]==right)
								if(m_Figure.Direction[5]==up)
								{
									MessageBox("8");
									for (int i =0; i<16; i++)
									{
										m_Figure.Direction[i]= none;
									}
									m_Figure.DotCount = 0;
									m_Panel.Invalidate();
									return;			
								}
			}
			if ( m_Figure.Direction[0]==down)
			{
				if (m_Figure.Direction[1]==right)
					if(m_Figure.Direction[2]==down)
						if(m_Figure.Direction[3]==right)
							if(m_Figure.Direction[4]==up)
								if(m_Figure.Direction[5]==left)
								{
									MessageBox("8");
									for (int i =0; i<16; i++)
									{
										m_Figure.Direction[i]= none;
									}
									m_Figure.DotCount = 0;
									m_Panel.Invalidate();
									return;			
								}
			}
			if ( m_Figure.Direction[0]==left)
			{
				if (m_Figure.Direction[1]==down)
					if(m_Figure.Direction[2]==right)
						if(m_Figure.Direction[3]==down)
							if(m_Figure.Direction[4]==left)
								if(m_Figure.Direction[5]==up)
								{
									MessageBox("8");
									for (int i =0; i<16; i++)
									{
										m_Figure.Direction[i]= none;
									}
									m_Figure.DotCount = 0;
									m_Panel.Invalidate();
									return;			
								}
			}
		}

		if (m_Figure.DotCount==1)//ÅÐ¶Ï9
		{
			if ( m_Figure.Direction[0]==left) 
			{
				if (m_Figure.Direction[1]==down )
					if(m_Figure.Direction[2]==right)
					{
						MessageBox("9");
						for (int i=0; i<16; i++)
						{
							m_Figure.Direction[i]= none;
						}
						m_Figure.DotCount = 0;
						m_Panel.Invalidate();
						return;			
					}
			}
			if ( m_Figure.Direction[0]==right)
				if ( m_Figure.Direction[1]==up)
					if ( m_Figure.Direction[2]==left)
						if ( m_Figure.Direction[3]==down)
						{
							MessageBox("9");
							for (int i=0; i<16; i++)
							{
								m_Figure.Direction[i] = none;
							}
							m_Figure.DotCount = 0;
							m_Panel.Invalidate();
							return;								
						}
		}
	for (int i =0; i<16; i++)
	{
		m_Figure.Direction[i]= none;
	}
	m_Figure.DotCount = 0;
	m_Panel.Invalidate();
}
