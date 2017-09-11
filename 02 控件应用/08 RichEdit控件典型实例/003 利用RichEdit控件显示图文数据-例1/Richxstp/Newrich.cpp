// Newrich.cpp : implementation file
//

#include "stdafx.h"
#include "Richxstp.h"
#include "Newrich.h"

#include <Richole.h>
#include <afxodlgs.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewrich

CNewrich::CNewrich()
{
}

CNewrich::~CNewrich()
{
}


BEGIN_MESSAGE_MAP(CNewrich, CRichEditCtrl)
	//{{AFX_MSG_MAP(CNewrich)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewrich message handlers
void CNewrich::InsertBitmap(CString *pBmpFile)
{
	HBITMAP bmp;
	//创建HBITMAP
	bmp = (HBITMAP)::LoadImage(NULL, *pBmpFile, IMAGE_BITMAP, 0, 0, 
		LR_LOADFROMFILE|LR_DEFAULTCOLOR|LR_DEFAULTSIZE);

	STGMEDIUM stgm;
	stgm.tymed = TYMED_GDI;
	stgm.hBitmap = bmp;
	stgm.pUnkForRelease = NULL;
	
	FORMATETC fm;
	fm.cfFormat = CF_BITMAP;
	fm.ptd = NULL;
	fm.dwAspect = DVASPECT_CONTENT;
	fm.lindex = -1;
	fm.tymed = TYMED_GDI;  
	
	//创建输入数据源
	IStorage *pStorage; 
	
	//分配内存
	LPLOCKBYTES lpLockBytes = NULL;
	SCODE sc = ::CreateILockBytesOnHGlobal(NULL, TRUE, &lpLockBytes);
	if (sc != S_OK)
		AfxThrowOleException(sc);
	ASSERT(lpLockBytes != NULL);
	
	sc = ::StgCreateDocfileOnILockBytes(lpLockBytes,
		STGM_SHARE_EXCLUSIVE|STGM_CREATE|STGM_READWRITE, 0, &pStorage);
	if (sc != S_OK)
	{
		VERIFY(lpLockBytes->Release() == 0);
		lpLockBytes = NULL;
		AfxThrowOleException(sc);
	}
	ASSERT(pStorage != NULL);
	
	COleDataSource *pDataSource = new COleDataSource;
	pDataSource->CacheData(CF_BITMAP, &stgm);
	LPDATAOBJECT lpDataObject = 
		(LPDATAOBJECT)pDataSource->GetInterface(&IID_IDataObject);
	
	//获取RichEdit的OLEClientSite
	LPOLECLIENTSITE lpClientSite;
	this->GetIRichEditOle()->GetClientSite( &lpClientSite );
	
	//创建OLE对象
	IOleObject *pOleObject;
	sc = OleCreateStaticFromData(lpDataObject,IID_IOleObject,OLERENDER_FORMAT,
		&fm,lpClientSite,pStorage,(void **)&pOleObject);
	if(sc!=S_OK)
		AfxThrowOleException(sc);
	
	//插入OLE对象
	REOBJECT reobject;
	ZeroMemory(&reobject, sizeof(REOBJECT));
	reobject.cbStruct = sizeof(REOBJECT);
	
	CLSID clsid;
	sc = pOleObject->GetUserClassID(&clsid);
	if (sc != S_OK)
		AfxThrowOleException(sc);
	
	reobject.clsid = clsid;
	reobject.cp = REO_CP_SELECTION;
	reobject.dvaspect = DVASPECT_CONTENT;
	reobject.poleobj = pOleObject;
	reobject.polesite = lpClientSite;
	reobject.pstg = pStorage;
	
	HRESULT hr = this->GetIRichEditOle()->InsertObject( &reobject );

	delete pDataSource;
}