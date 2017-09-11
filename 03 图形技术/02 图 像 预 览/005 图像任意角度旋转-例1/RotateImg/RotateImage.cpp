// RotateImage.cpp : implementation file
//

#include "stdafx.h"
#include "RotateImg.h"
#include "RotateImage.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRotateImage dialog


CRotateImage::CRotateImage(CWnd* pParent /*=NULL*/)
	: CDialog(CRotateImage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRotateImage)
	m_nDegree = 0;
	//}}AFX_DATA_INIT
	m_hBmp = NULL;
	m_bLoaded = FALSE;
	m_pBmpData = NULL;

}


void CRotateImage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRotateImage)
	DDX_Control(pDX, IDC_SETDEGREE, m_SetDegree);
	DDX_Control(pDX, IDC_PANEL, m_Panel);
	DDX_Control(pDX, IDC_IMAGE, m_Image);
	DDX_Control(pDX, IDC_BMPNAME, m_BmpName);
	DDX_Text(pDX, IDC_DEGREE, m_nDegree);
	DDV_MinMaxUInt(pDX, m_nDegree, 0, 360);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRotateImage, CDialog)
	//{{AFX_MSG_MAP(CRotateImage)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_WM_MOUSEWHEEL()
	ON_BN_CLICKED(IDC_BT_LOAD, OnBtLoad)
	ON_BN_CLICKED(IDC_BT_SAVE, OnBtSave)
	ON_BN_CLICKED(IDC_BT_ROTATE, OnBtRotate)
	ON_EN_CHANGE(IDC_DEGREE, OnChangeDegree)
	ON_BN_CLICKED(IDC_FIXDEGREE, OnFixdegree)
	ON_BN_CLICKED(IDC_RANDDEGREE, OnRanddegree)
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(IDC_ROTATE45,IDC_ROTATE270,OnLBtnRadio)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRotateImage message handlers

void CRotateImage::OnCancel() 
{
	//在对话框关闭时释放位图数据
	if (m_pBmpData != NULL)
	{
		delete []m_pBmpData;
		m_pBmpData = NULL;
	}
	CDialog::OnCancel();
}

void CRotateImage::OnOK() 
{

}

BOOL CRotateImage::OnInitDialog() 
{
	CDialog::OnInitDialog();

	//创建显示图片的容器窗口
	m_ImagePanel.Create(IDD_IMAGEPANEL_DIALOG,this);
	
	CRect rcClient,rcFrame;
	//获取容器窗口的客户区域
	m_ImagePanel.GetClientRect(rcClient);
	
	//设置容器窗口显示的区域
	m_Panel.GetClientRect(rcFrame);
	m_Panel.MapWindowPoints(this,rcFrame);
	m_ImagePanel.MoveWindow(rcFrame);
	m_ImagePanel.ShowWindow(SW_SHOW);
	//设置图片控件的父窗口为容器窗口
	m_Image.SetParent(&m_ImagePanel);
	CRect rcBmp;
	//将图片控件显示在容器窗口的左上角
	m_Image.GetClientRect(rcBmp);
	m_Image.MoveWindow(0,0,rcBmp.Width(),rcBmp.Height());	
	//将某一个单选按钮设置为选中窗台
	CButton* pButton =  (CButton*)GetDlgItem(IDC_ROTATE45);
	if (pButton != NULL)
	{
		pButton->SetCheck(TRUE);
	}
	//将预定角度的单选按钮设置为选中状态
	pButton =  (CButton*)GetDlgItem(IDC_FIXDEGREE);
	if (pButton != NULL)
	{
		pButton->SetCheck(TRUE);
	}
	//设置滑块的滑动范围
	m_SetDegree.SetRange(0,360);

	return TRUE;  
}

void CRotateImage::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	//在窗口的WM_VSCROLL消息触发时调用容器窗口的OnVScroll方法
	m_ImagePanel.OnVScroll(nSBCode, nPos, pScrollBar);			
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CRotateImage::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	//如果是滑块控件触发的WM_HSCROLL消息
	if (pScrollBar != NULL && pScrollBar->m_hWnd == m_SetDegree.m_hWnd)
	{
		m_nDegree = m_SetDegree.GetPos();
		UpdateData(FALSE);
	}
	else	//容器控件触发的WM_HSCROLL消息
	{
		m_ImagePanel.OnHScroll(nSBCode, nPos, pScrollBar);	
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

BOOL CRotateImage::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	//在鼠标滚轮的消息触发时执行容器窗口的OnMouseWheel方法
	m_ImagePanel.OnMouseWheel(nFlags, zDelta, pt);			
	return CDialog::OnMouseWheel(nFlags, zDelta, pt);
}


void CRotateImage::OnBtLoad() 
{
	//定义一个文件打开对话框
	CFileDialog flDlg(TRUE, "", "",
			OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "位图文件|*.bmp||", this);
	if (flDlg.DoModal()==IDOK)	//模式显示文件打开对话框
	{
		//获取文件名称
		CString csFileName = flDlg.GetPathName();
		m_SrcFile = flDlg.GetPathName();
		//设置编辑框文本
		m_BmpName.SetWindowText(csFileName);
		//判断之前是否加载了位图
		if (m_hBmp != NULL)
		{
			//释放位图
			DeleteObject(m_hBmp);
			m_hBmp = NULL;
		}
		//加载位图
		m_hBmp = (HBITMAP)LoadImage(NULL,csFileName,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		if (m_hBmp)
		{
			//显示位图
			m_Image.SetBitmap(m_hBmp);
			m_bLoaded = TRUE;	//设置加载标记
		}
		CFile file;		//定义文件对象
		//打开文件
		file.Open(csFileName,CFile::modeRead);
		//读取位图文件头
		file.Read(&m_bmFileHeader,sizeof(BITMAPFILEHEADER));
		//读取位图信息头
		file.Read(&m_bmInfoHeader,sizeof(BITMAPINFOHEADER));
		int szPalette = 0;	//定义调色板大小
		//判断是否为真彩色位图
		if (m_bmInfoHeader.biBitCount != 24)
		{
			file.Close();
			MessageBox("请选择真彩色位图!","提示");
			return;
		}
		//读取位图实际数据大小
		int nBmpData = m_bmInfoHeader.biSizeImage;
		//如果之前加载了位图数据，则删除位图数据
		if (m_pBmpData != NULL)
		{
			delete []m_pBmpData;
			m_pBmpData = NULL;
		}
		//根据位图数据大小为位图数据分配空间
		m_pBmpData = new BYTE[nBmpData];
		//读取位图数据到堆空间中
		file.ReadHuge(m_pBmpData,nBmpData);
		//关闭文件
		file.Close();

		//修改位图数据，是位图每一个像素占用4个字节，这样每一行位图数据将是4的整数倍
		//计算修改后位图数据的大小
		int sizeofbuffer = m_bmInfoHeader.biWidth * m_bmInfoHeader.biHeight * 4;
		int externWidth;
		//计算源位图每行使用的字节数
		externWidth = m_bmInfoHeader.biWidth * 3;
		if(externWidth % 4 != 0)
			externWidth = 4 - externWidth % 4;
		else
			externWidth = 0;
		int k = 0;
		//构建新位图数据的缓冲区
		BYTE* m_pImageTempBuffer = new BYTE[sizeofbuffer];

		//真彩色位图通常是倒序的，因此，从底部向上访问位图数据
		for (int n = m_bmInfoHeader.biHeight - 1; n >= 0; n--) 
		{
			//遍历每一个位图数据
			for (UINT m = 0; m < m_bmInfoHeader.biWidth * 3; m += 3) 
			{
				//获取源位图数据中的像素颜色值(RGB值)
				m_pImageTempBuffer[k]   = m_pBmpData[n*(m_bmInfoHeader.biWidth*3+externWidth)+m];	//blue
				m_pImageTempBuffer[k+1] = m_pBmpData[n*(m_bmInfoHeader.biWidth*3+externWidth)+m+1];//green
				m_pImageTempBuffer[k+2] = m_pBmpData[n*(m_bmInfoHeader.biWidth*3+externWidth)+m+2];//red
				m_pImageTempBuffer[k+3] = 255;
				k += 4;	//设置下一个像素颜色值
			}
		}
		//释放源位图数据
		delete []m_pBmpData;
		//复制新的位图数据
		m_pBmpData = new BYTE[sizeofbuffer];
		memcpy(m_pBmpData, m_pImageTempBuffer, sizeofbuffer);
		//释放m_pImageTempBuffer对象
		delete []m_pImageTempBuffer;

		//设置滚动范围
		CRect bmpRC,wndRC;
		m_ImagePanel.GetClientRect(wndRC);
		m_Image.GetClientRect(bmpRC); 

		m_ImagePanel.OnHScroll(SB_LEFT, 1, NULL); 
		m_ImagePanel.OnVScroll(SB_LEFT, 1, NULL); 

		//设置容器控件滚动范围
		m_ImagePanel.SetScrollRange(SB_VERT,0,bmpRC.Height()-wndRC.Height());
		m_ImagePanel.SetScrollRange(SB_HORZ,0,bmpRC.Width()-wndRC.Width());
	}	
}

void CRotateImage::OnBtSave() 
{
	//已经加载图像
	if (m_bLoaded)
	{
		//定义文件保存对话框
		CFileDialog flDlg(FALSE, "bmp", "Demo.bmp", 
						OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "位图文件|*.bmp||");
		if (flDlg.DoModal()==IDOK)	//打开文件保存对话框
		{
			try
			{
				//获取保存的文件名称
				CString csSaveName = flDlg.GetPathName();
				CFile file;	//定义文件对象
				file.Open(csSaveName,CFile::modeCreate|CFile::modeReadWrite);
				//写入位图文件信息头
				file.Write(&m_bmFileHeader,sizeof(m_bmFileHeader));
				//写入位图信息头
				file.Write(&m_bmInfoHeader,sizeof(m_bmInfoHeader));
				//写入位图实际数据

				BYTE byByteAlign;
				//确定转换后的位图的宽度和高度
				UINT outHeight = m_bmInfoHeader.biHeight;
				UINT outWidth = m_bmInfoHeader.biWidth;

				//定义一个指针，指向最后一行位图数据
				BYTE * pListData = m_pBmpData+((DWORD)outHeight-1)*outWidth*4;

				//计算字节对齐，如果每行位图数据字节数不是4的整数倍，需要进行补齐
				if (outWidth % 4 != 0) 
					byByteAlign = 4-((outWidth * 3L) % 4);
				else
					byByteAlign = 0; 

				BYTE byZeroData = 0; 
				//按行和列遍历位图数据
				for (int y=0; y<outHeight; y++)
				{
					for (int x=0; x<outWidth; x++)
					{
						//向文件中写入一个像素的位图数据
						file.Write(pListData, 3);
						pListData += 4;	//指向下一个像素
					}
					//如果需要字节补齐，在每一行结尾需要填充适当的字节数据
					for (int i=0; i<byByteAlign; i++)
					{
						file.Write(&byZeroData,1);
					}
					//指向上一行数据
					pListData -= 2L*outWidth*4;
				}	
				file.Close();	//关闭文件
			}
			catch(...)
			{
				MessageBox("文件保存失败!","提示");
			}
		}	
	}		
}

//RotationImage方法用于根据指定的角度转换位图数据
void CRotateImage::RotationImage(BITMAPINFOHEADER *pBmInfo, int nDegree)
{
	//源图像宽度和高度
	UINT srcWidth = pBmInfo->biWidth;
	UINT srcHeight = pBmInfo->biHeight;

	double pi = 3.1415926535;
	//将角度转换为弧度
	double dRadian =nDegree* (pi/180.0);
	//计算目标图像宽度和高度
	UINT desWidth = (abs)(srcHeight*sin(dRadian)) + (abs)(srcWidth*cos(dRadian))+1;
	UINT desHeight = (abs)(srcHeight*cos(dRadian)) + (abs)(srcWidth*sin(dRadian))+1;

	//每行字节数
	UINT desLineBytes = desWidth * pBmInfo->biBitCount / 8;
	int mod = desLineBytes % 4;
	if (mod != 0)
		desLineBytes += 4 - mod;
	//获取源图像数据
	BYTE* psrcData = m_pBmpData;
	BYTE* psrcPixData  = NULL;
	BYTE* pdesPixData = NULL;
	//在堆中为旋转后的位图分配空间
	m_hGlobal = GlobalAlloc(GMEM_MOVEABLE,desHeight*desLineBytes);
	//锁定堆空间
	m_RotData = (BYTE*)GlobalLock(m_hGlobal);
	//初始化堆空间
	memset(m_RotData,0,desHeight*desLineBytes);
	//设置旋转后的位图信息
	desBmInfo.biBitCount = pBmInfo->biBitCount;
	desBmInfo.biClrImportant = pBmInfo->biClrImportant;
	desBmInfo.biClrUsed = pBmInfo->biClrUsed;
	desBmInfo.biCompression = pBmInfo->biCompression;
	desBmInfo.biPlanes = pBmInfo->biPlanes;
	desBmInfo.biSize = sizeof(BITMAPINFOHEADER);
	desBmInfo.biXPelsPerMeter = pBmInfo->biXPelsPerMeter;
	desBmInfo.biYPelsPerMeter = pBmInfo->biYPelsPerMeter;

	BYTE* pTemp = NULL;
	//调用RotateBmp方法旋转位图数据
	RotateBmp(psrcData,pTemp,srcWidth,srcHeight,desWidth,desHeight,dRadian);
	
	//设置目标图像宽度和高度
	desBmInfo.biHeight = desHeight;
	desBmInfo.biWidth = desWidth;

	desLineBytes = desWidth * pBmInfo->biBitCount / 8;
	mod = desLineBytes % 4;
	if (mod != 0)
		desLineBytes += 4 - mod;
	//设置图像数据大小
	desBmInfo.biSizeImage = desHeight*desLineBytes;

	m_bmInfoHeader = desBmInfo;

	//如果m_pBmpData包含位图数据，则先释放位图数据
	if (m_pBmpData != NULL)
	{
		delete []m_pBmpData;
		m_pBmpData = NULL;
	}
	//重新复制旋转之后的位图数据
	m_pBmpData = new BYTE[desHeight*desWidth*4];
	memset(m_pBmpData,255,desHeight*desWidth*4);
	memcpy(m_pBmpData,pTemp,desHeight*desWidth*4);
	//释放临时对象
	delete [] pTemp;
	pTemp = NULL;
}

void CRotateImage::OnBtRotate() 
{
	if (m_bLoaded)
	{
		//确定旋转方式
		CButton* pButton =  (CButton*)GetDlgItem(IDC_FIXDEGREE);
		int nState = 0;
		int nDegree = 0;
		if (pButton != NULL)
		{
			nState = pButton->GetCheck();
		}
		if (nState)		//预定角度
		{
			for (int nID = IDC_ROTATE45; nID <= IDC_ROTATE270; nID++)
			{
				pButton = (CButton*)GetDlgItem(nID);
				if (pButton != NULL)
				{
					nState = pButton->GetCheck();
					if (nState)
					{
						CString csText;
						pButton->GetWindowText(csText);
						int nPos = csText.Find("°");
						nDegree = atoi(csText.Left(nPos));
						break;
					}
				}
			}	
		}
		else			//固定角度
		{
			UpdateData(FALSE);
			nDegree = m_nDegree;
		}
		//确定旋转角度，调用RotationImage方法进行图像旋转
		RotationImage(&m_bmInfoHeader,nDegree);

		BYTE byByteAlign ;	//位图行字节对齐
		//获取旋转后的位图大小
		UINT outHeight = m_bmInfoHeader.biHeight;
		UINT outWidth = m_bmInfoHeader.biWidth;
		//为新位图分配堆空间
		BYTE* pBmpData  = new BYTE [m_bmInfoHeader.biSizeImage];
		//初始化堆空间
		memset(pBmpData,0,m_bmInfoHeader.biSizeImage);
		//获取位图数据中的最后以行数据
		BYTE * pListData =m_pBmpData+((DWORD)outHeight-1)*outWidth*4;
		
		//计算位图数据每行补齐的字节数
		if (outWidth %4 != 0) 
			byByteAlign = 4- ((outWidth*3L) % 4);
		else
			byByteAlign = 0;

		BYTE byZeroData = 0;
		BYTE* pTmpData = pBmpData;
		//对旋转后的位图数据进行修改，使得使用3个字节表示一个像素数据
		for (int y=0 ;y<outHeight;y++)
		{
			for (int x=0;x<outWidth;x++)
			{
				memcpy(pTmpData,pListData,3);
				pTmpData += 3;
				pListData += 4;
			}
			for (int i=0; i<byByteAlign; i++)
			{
				memcpy(pTmpData,&byZeroData,1);
				pTmpData =pTmpData + 1;
			}
			pListData -= 2L*outWidth*4;
		}

		CDC *pDC = m_Image.GetDC();

		BITMAPINFO bInfo;
		bInfo.bmiHeader = m_bmInfoHeader;
		//在图像控件中显示旋转后的位图
		HBITMAP hBmp = m_Image.SetBitmap(CreateDIBitmap(pDC->m_hDC,
				&m_bmInfoHeader, CBM_INIT, pBmpData, &bInfo, DIB_RGB_COLORS));
		if (hBmp != NULL)
		{
			::DeleteObject(hBmp);
		}
		delete [] pBmpData;

		//设置滚动范围
		CRect bmpRC,wndRC;
		m_ImagePanel.GetClientRect(wndRC);
		m_Image.GetClientRect(bmpRC);

		m_ImagePanel.OnHScroll(SB_LEFT, 1, NULL); 
		m_ImagePanel.OnVScroll(SB_LEFT, 1, NULL); 

		m_ImagePanel.SetScrollRange(SB_VERT,0,bmpRC.Height()-wndRC.Height());
		m_ImagePanel.SetScrollRange(SB_HORZ,0,bmpRC.Width()-wndRC.Width());
	}
}

void CRotateImage::OnChangeDegree() 
{
	UpdateData(TRUE);
	m_SetDegree.SetPos(m_nDegree);
	
}

//方法RotateBmp用于按指定角度旋转位图数据
void CRotateImage::RotateBmp(BYTE *pBmpData, BYTE *&pDesData, int nWidth, int nHeight, 
							 int nDesWidth, int nDesHeight, double dAngle)
{
	// 计算正弦和余弦值
	double dSin = sin(dAngle);
	double dCos = cos(dAngle);
	//在堆中分配一个空间，用于存储旋转后的位图数据
	pDesData = new BYTE[nDesWidth * nDesHeight * 4];
	//初始堆空间中的数据
	memset(pDesData, 255, nDesWidth * nDesHeight * 4);

	//计算dx和dy
	double dX = -0.5*nDesWidth*dCos - 0.5*nDesHeight*dSin + 0.5*nWidth;
	double dY = 0.5*nDesWidth*dSin - 0.5*nDesHeight*dCos + 0.5*nHeight;

	BYTE* pSrc = NULL;	
	BYTE* pDes = NULL;	
	int x = 0;				
	int	y = 0;				
	for (int h = 0; h < nDesHeight; h++)
	{
		for (int w = 0; w < nDesWidth; w++) 
		{
			//加0.5是为了向上取整
			//x,y表示目标区域w,h坐标点对应的源图像中的坐标
			x = (int)(w * dCos + h * dSin + dX + 0.5);
			y = (int)(-w * dSin + h * dCos + dY + 0.5);
			if (x == nWidth)
			{
				x--;
			}
			if (y == nHeight)
			{
				y--;
			}

			pSrc = pBmpData + y * nWidth * 4 + x * 4;
			pDes = pDesData + h * nDesWidth * 4 + w * 4;
			//判断目标区域中的坐标是在源位图中存在坐标点，通常目标区域会比源位图区域大
			//因此，有些目标区域中的有些坐标在源位图中是没有对应的坐标点，程序过滤掉这些坐标点
			if (x >= 0 && x < nWidth && y >= 0 && y < nHeight)
			{
				memcpy(pDes, pSrc, 4);
			}
		}
	}
}

void CRotateImage::OnFixdegree() 
{
	CButton *pButton = (CButton*)GetDlgItem(IDC_FIXDEGREE);	
	if (pButton!=NULL)
	{
		pButton->SetCheck(TRUE);
		pButton = (CButton*)GetDlgItem(IDC_RANDDEGREE);	
		pButton->SetCheck(FALSE);
	}	
}

void CRotateImage::OnRanddegree() 
{
	CButton *pButton = (CButton*)GetDlgItem(IDC_RANDDEGREE);	
	if (pButton!=NULL)
	{
		pButton->SetCheck(TRUE);
		pButton = (CButton*)GetDlgItem(IDC_FIXDEGREE);	
		pButton->SetCheck(FALSE);
	}	
}

void CRotateImage::OnLBtnRadio(UINT nID)
{
	for (UINT i = IDC_ROTATE45; i<IDC_ROTATE270+1 ; i++)
	{
		CButton* pButton = (CButton*)GetDlgItem(i);
		if (i==nID)	
		{
			pButton->SetCheck(TRUE);
		}
		else
		{
			pButton->SetCheck(FALSE);
		}
	}
}
