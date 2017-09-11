// FetchAndSaveIconDlg.h : header file
//

#if !defined(AFX_FETCHANDSAVEICONDLG_H__9BEB090E_C135_447C_85FF_6FC8ED6F0853__INCLUDED_)
#define AFX_FETCHANDSAVEICONDLG_H__9BEB090E_C135_447C_85FF_6FC8ED6F0853__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFetchAndSaveIconDlg dialog
#pragma pack( push )
#pragma pack( 2 )
typedef struct
{
	BYTE	bWidth;               
	BYTE	bHeight;      
	BYTE	bColorCount;  
	BYTE	bReserved;    
	WORD	wPlanes;      
	WORD	wBitCount;    
	DWORD	dwBytesInRes; 
	WORD	nID;          
} MEMICONDIRENTRY, *LPMEMICONDIRENTRY;

typedef struct 
{
	WORD			idReserved;   
	WORD			idType;       
	WORD			idCount;      
	MEMICONDIRENTRY	idEntries[1]; 
} MEMICONDIR, *LPMEMICONDIR;

#pragma pack( pop)
//定义图像数据
typedef struct
{

	LPBITMAPINFO   icheader;  // 位图信息头，可参照上节的位图头信息结构
	RGBQUAD         iccolors; //色彩表，同位图的色彩表。
	LPBYTE			lpXOR;    
	LPBYTE			lpAND;  
 
      // AND掩码
} iconimage, *lpiconimage;

//定义图标资源索引目录
typedef struct
{
	byte        bwidth;          // 图像宽度，以像素为单位
	byte        bheight;         // 图像高度，以像素为单位
	byte        bcolorcount;     //图像中的颜色数，如果是大于８的位图，此值为零
	byte        breserved;       //保留，必须为零
	WORD        wplanes;         //位面数，一般为１
	WORD        wbitcount;       //每像素所占位数
	DWORD       dwbytesinres;    // 资源的字节数
	DWORD       dwimageoffset;   //图像数据距离资源开始处偏移位置
} icondirentry, *lpicondirentry;

//定义图标文件头
typedef struct
{
WORD           idreserved;   // 保留，必须为零
WORD           idtype;       // 资源类型，１是图标，２是光标
WORD          idcount;       // 图像个数
icondirentry   identries[1]; // 每个图像的入口定义
} icondir, *lpicondir;


class CFetchAndSaveIconDlg : public CDialog
{
// Construction
public:
	DWORD GetImageOffset(HMODULE hmodule ,UINT index,DWORD& cursize ,LPBYTE pbitinfo =NULL);
	CFetchAndSaveIconDlg(CWnd* pParent = NULL);	// standard constructor

	lpicondirentry m_lpdirentry;
	lpicondir m_lpdir;
	lpiconimage m_lpicondata;

	LPMEMICONDIRENTRY m_lpMemEntry;
	LPMEMICONDIR m_lpMemDir;
	LPBYTE m_lpData;

// Dialog Data
	//{{AFX_DATA(CFetchAndSaveIconDlg)
	enum { IDD = IDD_FETCHANDSAVEICON_DIALOG };
	CStatic	m_demoicon;
	CEdit	m_filename;

	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFetchAndSaveIconDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFetchAndSaveIconDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnBrown();
	afx_msg void OnFetch();
	afx_msg void OnSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FETCHANDSAVEICONDLG_H__9BEB090E_C135_447C_85FF_6FC8ED6F0853__INCLUDED_)
