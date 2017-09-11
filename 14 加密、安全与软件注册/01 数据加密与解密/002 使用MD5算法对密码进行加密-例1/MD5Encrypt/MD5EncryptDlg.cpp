// MD5EncryptDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MD5Encrypt.h"
#include "MD5EncryptDlg.h"
#include <math.h>

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
// CMD5EncryptDlg dialog

CMD5EncryptDlg::CMD5EncryptDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMD5EncryptDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMD5EncryptDlg)
	m_edit = _T("");
	m_password = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMD5EncryptDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMD5EncryptDlg)
	DDX_Text(pDX, IDC_EDIT1, m_edit);
	DDX_Text(pDX, IDC_EDIT2, m_password);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMD5EncryptDlg, CDialog)
	//{{AFX_MSG_MAP(CMD5EncryptDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, OnEncrypt)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMD5EncryptDlg message handlers

BOOL CMD5EncryptDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMD5EncryptDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMD5EncryptDlg::OnPaint() 
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
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMD5EncryptDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMD5EncryptDlg::OnEncrypt() 
{
	UpdateData();
	CString str = MD.GetMD5((BYTE *)m_password.GetBuffer(0),
		m_password.GetLength());
	m_edit = str;
	UpdateData(false);
}


/////////////////////////

CString CMD5Class::GetMD5(BYTE* pBuf, UINT nLength)
{
	AfxIsValidAddress(pBuf,nLength,FALSE);
	CMD5Class MD5;
	MD5.Update( pBuf, nLength );
	return MD5.Final();
}

DWORD CMD5Class::RotateLeft(DWORD x, int n)
{
	ASSERT( sizeof(x) == 4 );
	return (x << n) | (x >> (32-n));
}

void CMD5Class::FF( DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T)
{
	DWORD F = (B & C) | (~B & D);
	A += F + X + T;
	A = RotateLeft(A, S);
	A += B;
}

void CMD5Class::GG( DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T)
{
	DWORD G = (B & D) | (C & ~D);
	A += G + X + T;
	A = RotateLeft(A, S);
	A += B;
}

void CMD5Class::HH( DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T)
{
	DWORD H = (B ^ C ^ D);
	A += H + X + T;
	A = RotateLeft(A, S);
	A += B;
}

void CMD5Class::II( DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T)
{
	DWORD I = (C ^ (B | ~D));
	A += I + X + T;
	A = RotateLeft(A, S);
	A += B;
}

void CMD5Class::ByteToDWord(DWORD* Output, BYTE* Input, UINT nLength)
{
	ASSERT( nLength % 4 == 0 );
	ASSERT( AfxIsValidAddress(Output, nLength/4, TRUE) );
	ASSERT( AfxIsValidAddress(Input, nLength, FALSE) );

	UINT i=0;
	UINT j=0; 

	for ( ; j < nLength; i++, j += 4)
	{
		Output[i] = (ULONG)Input[j]   | 
			(ULONG)Input[j+1] << 8 | 
			(ULONG)Input[j+2] << 16 | 
			(ULONG)Input[j+3] << 24;
	}
}

void CMD5Class::Transform(BYTE Block[64])
{
	ULONG a = m_lMD5[0];
	ULONG b = m_lMD5[1];
	ULONG c = m_lMD5[2];
	ULONG d = m_lMD5[3];

	ULONG X[16];
	ByteToDWord( X, Block, 64 );
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<16;j++)
		{
			switch (i)
			{
			case 0:
				FF(a,b,c,d,X[XINDEX[i][j]],MD5_S[i][j],MD5_T[(i+1)*(j+1)]);
				break;
			case 1:
				GG(a,b,c,d,X[XINDEX[i][j]],MD5_S[i][j],MD5_T[(i+1)*(j+1)]);
				break;
			case 2:
				HH(a,b,c,d,X[XINDEX[i][j]],MD5_S[i][j],MD5_T[(i+1)*(j+1)]);
				break;
			case 3:
				II(a,b,c,d,X[XINDEX[i][j]],MD5_S[i][j],MD5_T[(i+1)*(j+1)]);
			break;			 
			}
		}
	}

	m_lMD5[0] += a;
	m_lMD5[1] += b;
	m_lMD5[2] += c;
	m_lMD5[3] += d;
}

CMD5Class::CMD5Class()
{
	memset( m_lpszBuffer, 0, 64 );
	m_nCount[0] = m_nCount[1] = 0;

	m_lMD5[0] = MD5_INIT_STATE_0;
	m_lMD5[1] = MD5_INIT_STATE_1;
	m_lMD5[2] = MD5_INIT_STATE_2;
	m_lMD5[3] = MD5_INIT_STATE_3;
}

void CMD5Class::DWordToByte(BYTE* Output, DWORD* Input, UINT nLength )
{
	ASSERT( nLength % 4 == 0 );
	ASSERT( AfxIsValidAddress(Output, nLength, TRUE) );
	ASSERT( AfxIsValidAddress(Input, nLength/4, FALSE) );

	UINT i = 0;
	UINT j = 0;
	for ( ; j < nLength; i++, j += 4) 
	{
		Output[j] =   (UCHAR)(Input[i] & 0xff);
		Output[j+1] = (UCHAR)((Input[i] >> 8) & 0xff);
		Output[j+2] = (UCHAR)((Input[i] >> 16) & 0xff);
		Output[j+3] = (UCHAR)((Input[i] >> 24) & 0xff);
	}
}

CString CMD5Class::Final()
{
	BYTE Bits[8];
	DWordToByte( Bits, m_nCount, 8 );

	UINT nIndex = (UINT)((m_nCount[0] >> 3) & 0x3f);
	//56ÊÇ64-8;120ÊÇ64*2-8
	UINT nPadLen = (nIndex < 56) ? (56 - nIndex) : (120 - nIndex);
	Update( PADDING, nPadLen );

	Update( Bits, 8 );

	const int nMD5Size = 16;
	unsigned char lpszMD5[ nMD5Size ];
	DWordToByte( lpszMD5, m_lMD5, nMD5Size );

	CString strMD5;
	for ( int i=0; i < nMD5Size; i++) 
	{
		CString Str;
		if (lpszMD5[i] == 0) {
			Str = CString("00");
		}
		else if (lpszMD5[i] <= 15)  {
			Str.Format("0%x",lpszMD5[i]);
		}
		else {
			Str.Format("%x",lpszMD5[i]);
		}

		ASSERT( Str.GetLength() == 2 );
		strMD5 += Str;
	}
	ASSERT( strMD5.GetLength() == 32 );
	return strMD5;
}

void CMD5Class::Update( BYTE* Input, ULONG nInputLen )
{
	UINT nIndex = (UINT)((m_nCount[0] >> 3) & 0x3F);

	if ( ( m_nCount[0] += nInputLen << 3 )  <  ( nInputLen << 3) )
	{
		m_nCount[1]++;
	}
	m_nCount[1] += (nInputLen >> 29);

	UINT i=0;  
	UINT nPartLen = 64 - nIndex;
	if (nInputLen >= nPartLen)  
	{
		memcpy( &m_lpszBuffer[nIndex], Input, nPartLen );
		Transform( m_lpszBuffer );
		for (i = nPartLen; i + 63 < nInputLen; i += 64) 
		{
			Transform( &Input[i] );
		}
		nIndex = 0;
	} 
	else 
	{
		i = 0;
	}

	memcpy( &m_lpszBuffer[nIndex], &Input[i], nInputLen-i);
}
