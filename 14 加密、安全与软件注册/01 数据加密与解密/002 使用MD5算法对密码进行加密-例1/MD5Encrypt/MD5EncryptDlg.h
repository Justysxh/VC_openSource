// MD5EncryptDlg.h : header file
//

#if !defined(AFX_MD5ENCRYPTDLG_H__B8555288_B8BC_4544_9409_769CDEE77FDC__INCLUDED_)
#define AFX_MD5ENCRYPTDLG_H__B8555288_B8BC_4544_9409_769CDEE77FDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////


#define MD5_INIT_STATE_0 0x67452301
#define MD5_INIT_STATE_1 0xefcdab89
#define MD5_INIT_STATE_2 0x98badcfe
#define MD5_INIT_STATE_3 0x10325476

static DWORD MD5_S[4][16] = 
{	{7,12,17,22,9,6,8,5,7,4,17,3,7,2,17,10},
	{5,9,14,20,7,4,10,12,5,8,14,6,5,9,3,20}, 
	{4,11,16,23,5,8,10,12,4,7,9,23,8,11,22,14},
	{6,10,15,21,6,10,15,21,6,10,15,21,6,10,15,21}
};

static int XINDEX[4][16] = 
{	{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
	{1,6,11,0,5,10,15,4,9,14,3,8,13,2,7,12}, 
	{5,8,11,14,1,4,7,10,13,0,3,6,9,12,15,2},
	{0,7,14,5,12,3,10,1,8,15,6,13,4,11,2,9}
};

static DWORD MD5_T[64] = 
{
	0xd76aa478,0xe8c7b756,0x242070db,0xc1bdceee,
	0xf57c0faf,0x4787c62a,0xa8304613,0xfd469501,
	0x698098d8,0x8b44f7af,0xffff5bb1,0x895cd7be,
	0x6b901122,0xfd987193,0xa679438e,0x49b40821,

	0xf61e2562,0xc040b340,0x265e5a51,0xe9b6c7aa,
	0xd62f105d,0x02441453,0xd8a1e681,0xe7d3fbc8,
	0x21e1cde6,0xc33707d6,0xf4d50d87,0x455a14ed,
	0xa9e3e905,0xfcefa3f8,0x676f02d9,0x8d2a4c8a,

	0xfffa3942,0x8771f681,0x6d9d6122,0xfde5380c,
	0xa4beea44,0x4bdecfa9,0xf6bb4b60,0xbebfbc70,
	0x289b7ec6,0xeaa127fa,0xd4ef3085,0x04881d05,
	0xd9d4d039,0xe6db99e5,0x1fa27cf8,0xc4ac5665,

	0xf4292244,0x432aff97,0xab9423a7,0xfc93a039,
	0x655b59c3,0x8f0ccc92,0xffeff47d,0x85845dd1,
	0x6fa87e4f,0xfe2ce6e0,0xa3014314,0x4e0811a1,
	0xf7537e82,0xbd3af235,0x2ad7d2bb,0xeb86d391
};

static unsigned char PADDING[64] = {
  0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};


class CMD5Class  
{
private:
	BYTE  m_lpszBuffer[64];
	ULONG m_nCount[2]; 
	ULONG m_lMD5[4]; 

	void Transform(BYTE Block[64]);
	void Update(BYTE* Input, ULONG nInputLen);
	CString Final();
	inline DWORD RotateLeft(DWORD x, int n);
	inline void FF( DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T);
	inline void GG( DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T);
	inline void HH( DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T);
	inline void II( DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T);

	void DWordToByte(BYTE* Output, DWORD* Input, UINT nLength);
	void ByteToDWord(DWORD* Output, BYTE* Input, UINT nLength);
public:
	CMD5Class();
	virtual ~CMD5Class() {};
	static CString GetMD5(BYTE* pBuf, UINT nLength);
};

// CMD5EncryptDlg dialog

class CMD5EncryptDlg : public CDialog
{
// Construction
public:
	CMD5Class MD;
	CMD5EncryptDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMD5EncryptDlg)
	enum { IDD = IDD_MD5ENCRYPT_DIALOG };
	CString	m_edit;
	CString	m_password;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMD5EncryptDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMD5EncryptDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnEncrypt();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MD5ENCRYPTDLG_H__B8555288_B8BC_4544_9409_769CDEE77FDC__INCLUDED_)
