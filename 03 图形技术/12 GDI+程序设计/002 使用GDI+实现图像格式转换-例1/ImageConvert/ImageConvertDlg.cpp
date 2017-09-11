// ImageConvertDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ImageConvert.h"
#include "ImageConvertDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
/*
//获取文件名，不包含扩展名和路径
CString GetFileName(CString & str)
{
	int extendpos = str.ReverseFind('.');
	CString csFileName =  str.Left(extendpos);
	int dirpos = csFileName.ReverseFind('\\');
	return csFileName.Mid(dirpos + 1, extendpos - 1);
}

CString ExtractFileName(CString & str)
{
	int pos = str.ReverseFind('.');
	return str.Left(pos);
}

CString GetFileExtendedName(CString &strFile)
{
	int pos = strFile.ReverseFind('.');
	return strFile.Right(strFile.GetLength() - pos - 1);	
}
*/

int GetCodecClsid(const WCHAR* format, CLSID* pClsid)
{
   UINT  codenum = 0;   
   UINT  size = 0;   
   ImageCodecInfo* pImageCodecInfo = NULL;
   GetImageEncodersSize(&codenum, &size);
   if(size == 0)
      return -1 ;  
   pImageCodecInfo = new ImageCodecInfo[size];
   if(pImageCodecInfo == NULL)
      return -1; 
   GetImageEncoders(codenum, size, pImageCodecInfo);
   for(UINT j = 0; j < codenum; ++j)
   {
      if( wcscmp(pImageCodecInfo[j].MimeType, format) == 0 )
      {
         *pClsid = pImageCodecInfo[j].Clsid;
		 delete []pImageCodecInfo;
         return 0;  
      }    
   } 
   delete []pImageCodecInfo;
   return -1;  
}

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
// CImageConvertDlg dialog

CImageConvertDlg::CImageConvertDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImageConvertDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CImageConvertDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CImageConvertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImageConvertDlg)
	DDX_Control(pDX, IDC_FILEDIR, m_FileDir);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CImageConvertDlg, CDialog)
	//{{AFX_MSG_MAP(CImageConvertDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	ON_BN_CLICKED(IDC_TRANSFORM, OnTransform)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageConvertDlg message handlers

BOOL CImageConvertDlg::OnInitDialog()
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
	
	//初始化GDI+库
	GdiplusStartup(&m_pGdiToken, &m_Gdiplus, NULL);


	//将单选按钮设置为默认的选中状态
	CButton* pBtn = (CButton*)GetDlgItem(IDC_BMPTOJPEG);
	if (pBtn)
	{
		pBtn->SetCheck(TRUE);
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CImageConvertDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CImageConvertDlg::OnPaint() 
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
HCURSOR CImageConvertDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CImageConvertDlg::OnOK() 
{

}

void CImageConvertDlg::OnBrowse() 
{
	//定义文件打开对话框
	CFileDialog flDlg(TRUE, "", "", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
				"图像文件|*.bmp;*.jpg;*.jpeg||");
	if (flDlg.DoModal()==IDOK)		//打开文件对话框
	{
		CString szFileName = flDlg.GetPathName();
		m_Strextend = flDlg.GetFileExt();
		m_FileName  = flDlg.GetFileName();
		m_FileDir.SetWindowText(szFileName);
		
	}
}

void CImageConvertDlg::OnTransform() 
{
	//获取文件目录
	CString	szFileDir;
	m_FileDir.GetWindowText(szFileDir);
	if (szFileDir.IsEmpty())
	{
		MessageBox("请选择文件!", "提示");
		return;
	}
	//确定转换的源文件和目标文件的格式
	IImageType itSrc, itDes;
	GetImageType(itSrc, itDes);
	CLSID clsid;
	CString szSrcExt, szDesExt;			//定义文件扩展名

	if (itSrc == IT_JPG)
	{
		szSrcExt = "jpg";
	}
	else if (itSrc == IT_BMP)
	{
		szSrcExt = "bmp";
	}
	else if (itSrc == IT_PNG)
	{
		szSrcExt = "png";
	}

	if (itDes == IT_JPG)
	{
		GetCodecClsid(L"image/jpeg", &clsid);
		szDesExt = "jpg";
	}
	else if (itDes == IT_BMP)
	{
		GetCodecClsid(L"image/bmp", &clsid);	
		szDesExt = "bmp";
	}
	else if (itDes == IT_PNG)
	{
		GetCodecClsid(L"image/png", &clsid);
		szDesExt = "png";
	}

	try
	{
		BOOL ret = TRUE;
		//定义压缩参数
		int nQuality = 95;
		EncoderParameters Encoders;
		Encoders.Count = 1;
		Encoders.Parameter[0].Guid = EncoderQuality;
		Encoders.Parameter[0].Type = EncoderParameterValueTypeLong;
		Encoders.Parameter[0].NumberOfValues = 1;
		Encoders.Parameter[0].Value = &nQuality;

		if (m_Strextend == szSrcExt)
		{
			//根据源位图文件构建一个GDI+位图对象
			Bitmap *pBmp = Bitmap::FromFile(szFileDir.AllocSysString());
			if (pBmp)
			{							
				char chName[MAX_PATH] = {0};
				int pos = szFileDir.ReverseFind('\\');
				strcpy(chName, szFileDir.Left(pos));

				strcat(chName, "//");
				strcat(chName, szDesExt);
				CreateDirectory(chName, NULL);
				strcat(chName, "//");
				CString JpgFile = chName;
				JpgFile += m_FileName.Left(m_FileName.GetLength()-m_Strextend.GetLength());
				JpgFile += ".";		//添加扩展名
				JpgFile += szDesExt;
				if (itDes == IT_JPG)
				{
					pBmp->Save(JpgFile.AllocSysString(), &clsid, &Encoders);
				}
				else
				{
					pBmp->Save(JpgFile.AllocSysString(), &clsid);
				}
			}
			delete pBmp;	//释放位图对象
			MessageBox("转换成功!");
		}
	}
	catch(...)
	{
		MessageBox("转换失败!");
	}
	
}

void CImageConvertDlg::GetImageType(enum IImageType &itSrc, enum IImageType &itDes)
{
	CButton* pBtn = NULL;
	for(UINT nID=IDC_BMPTOJPEG; nID<=IDC_PNGTOBMP; nID++)
	{
		pBtn = (CButton*) GetDlgItem(nID);
		if (pBtn != NULL)
		{
			//单选按钮被选中
			if (pBtn->GetCheck() > 0)
			{
				switch (nID)
				{
				case IDC_BMPTOJPEG:
					{
						itSrc = IT_BMP;
						itDes = IT_JPG;
						break;
					}
				case IDC_JPEGTOBMP:
					{
						itSrc = IT_JPG;
						itDes = IT_BMP;
						break;
					}
				case IDC_BMPTOPNG:
					{
						itSrc = IT_BMP;
						itDes = IT_PNG;
						break;
					}
				case IDC_PNGTOBMP:
					{
						itSrc = IT_PNG;
						itDes = IT_BMP;
						break;
					}
				}
				break;
			}
		}
	}
}
