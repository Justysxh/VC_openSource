// CGif.cpp : Implementation of CCGif

#include "stdafx.h"
#include "Gif.h"
#include "CGif.h"
#include "afxwin.h"
#include <afxpriv.h> 
#include "comutil.h"

//G:\改进\TestGif\Debug\TestGif.exe

/////////////////////////////////////////////////////////////////////////////
// CCGif

//初始化静态成员
BOOL CCGif::m_bSetHook	= FALSE;
BOOL  CCGif::m_bChange	= FALSE;
WNDPROC CCGif::RichProc = NULL;
int CCGif::m_ImageNum	= 0;
HANDLE CCGif::m_hThread = NULL;
HHOOK CCGif::m_hHook	= NULL;
CCGif *CCGif::m_ImageInfo[MAX_IMGNUM ] = {0};


STDMETHODIMP CCGif::LoadFromFile(LPCTSTR FileName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		if (m_ImageNum >MAX_IMGNUM )
		{
			return 1;
		}
		m_bChange = FALSE;
		RECT rc;
		rc.left = 2;
		rc.top = 2;
		rc.right = 30;
		rc.bottom = 30;

		GdiplusStartup(&m_pGdiToken,&m_Gdiplus,NULL);
		
		m_FileName = (BSTR)FileName;
		if (m_hMem != NULL)
		{
			GlobalFree(m_hMem);
			m_hMem = NULL;
		}
		int nLen = WideCharToMultiByte(CP_ACP,0,(unsigned short*)FileName,-1,NULL,0,NULL,NULL);
		char* pdata = new  char[nLen];
		WideCharToMultiByte(CP_ACP,0,(unsigned short*)FileName,-1,pdata,nLen,NULL,NULL);

		CFile file;
		file.Open(pdata,CFile::modeRead);
		DWORD dwLen = file.GetLength();
		delete []pdata;
		m_hMem = GlobalAlloc(GMEM_FIXED, dwLen);
		
		BYTE * pData = (BYTE*)GlobalLock(m_hMem);
		file.ReadHuge(pData,dwLen);
		file.Close();
		IStream* pStm = NULL;
		CreateStreamOnHGlobal(m_hMem,FALSE,&pStm);
		m_pBmp = Bitmap::FromStream(pStm);
		GlobalUnlock(m_hMem);

		if (m_pBmp != NULL)
		{
			
			m_pBmp->GetRawFormat(&ImageID); 
			if (ImageID == ImageFormatGIF)
			{
				m_ImageType = IT_DYNAMIC;
			}
			else if (ImageID==ImageFormatBMP || ImageID==ImageFormatIcon ||
				ImageID==ImageFormatJPEG)
			{
				m_ImageType = IT_STATIC;
			}
			if(m_ImageType==IT_DYNAMIC)
			{
				m_Count = m_pBmp->GetFrameDimensionsCount();
				GUID *pGuids = new GUID[m_Count];
				m_pBmp->GetFrameDimensionsList(pGuids,m_Count);
				m_FrameCount = m_pBmp->GetFrameCount(pGuids);
				UINT size = 0;
				delay = PropertyTagFrameDelay;
				m_Count = 0;
				m_pBmp->GetPropertySize(&size,&delay);
				PropertyItem *pItem = NULL;
				pItem = (PropertyItem*)malloc(size);
				Status status= m_pBmp->GetAllPropertyItems(size,delay,pItem);
				delay = ((long*)pItem->value)[1];
				free(pItem);
				delete [] pGuids;
				fcount = 0;
			}
			if (m_ImageType==IT_UNKNOWN)
				return S_OK;	//不加载图像m_bLoaded为false

			m_rcPos.left = 1;
			m_rcPos.top = 1;
			m_rcPos.right = m_pBmp->GetWidth()+1;
			m_rcPos.bottom = m_pBmp->GetHeight()+1;
			CSize pixelsize,newsize;
			pixelsize.cx = m_pBmp->GetWidth()+2;
			pixelsize.cy = m_pBmp->GetHeight()+2;
			
			AtlPixelToHiMetric(&pixelsize,&newsize);
			m_sizeExtent.cx = newsize.cx;
			m_sizeExtent.cy = newsize.cy;
			SendOnViewChange(DVASPECT_CONTENT);	//重新修改显示区域，是m_sizeExtent成员生效
			//put_DrawWidth(100);				//重新修改显示区域，是m_sizeExtent成员生效
			m_bLoaded = TRUE;
			m_bNewInsert = TRUE;
			m_ImageNum++;
			m_ImageInfo[m_ImageNum-1] = this;
			hTmp = NULL;
			::GetSystemTime(&m_DrawTime);
		}
		return S_OK;
}


STDMETHODIMP CCGif::get_FileName(BSTR *pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	*pVal =m_FileName;// m_FileName;
	// TODO: Add your implementation code here
	return S_OK;
}

STDMETHODIMP CCGif::put_FileName(BSTR newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	m_FileName = newVal;
	LoadFromFile((LPCTSTR)m_FileName);
	// TODO: Add your implementation code here
	return S_OK;
}




STDMETHODIMP CCGif::put_FName(long hParent, BSTR newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
//	m_FileName = newVal;
//	LoadFrmFile((LPCTSTR)m_FileName,hParent);
	// TODO: Add your implementation code here

	return S_OK;
}

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

STDMETHODIMP CCGif::SaveToFile(BSTR FileName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	CLSID clsid;
	int nRet = -1;
	if (ImageID == ImageFormatGIF)
	{
		nRet = GetCodecClsid(L"image/gif", &clsid);
	}
	else if (ImageID==ImageFormatBMP)
	{
		nRet = GetCodecClsid(L"image/bmp", &clsid);
	}
	else if (ImageID==ImageFormatIcon )
	{
		nRet = GetCodecClsid(L"image/bmp", &clsid);
	}
	else if (ImageID==ImageFormatJPEG)
	{
		nRet = GetCodecClsid(L"image/jpeg", &clsid);
	}
	if (nRet== -1)
		return S_FALSE;

	IStream *pstm=NULL;
	CreateStreamOnHGlobal(m_hMem, TRUE, &pstm);


	int nLen = WideCharToMultiByte(CP_ACP,0,(unsigned short*)FileName,-1,NULL,0,NULL,NULL);
	char* pdata = new  char[nLen];
	WideCharToMultiByte(CP_ACP,0,(unsigned short*)FileName,-1,pdata,nLen,NULL,NULL);

	CFile file;
	file.Open(pdata,CFile::modeCreate|CFile::modeReadWrite);
	BYTE* pData = (BYTE*)GlobalLock(m_hMem);
	DWORD dwSize = GlobalSize(m_hMem);
	file.WriteHuge(pData,dwSize);
	file.Close();
	delete []pdata;
	GlobalUnlock(m_hMem);

	return S_OK;
}
