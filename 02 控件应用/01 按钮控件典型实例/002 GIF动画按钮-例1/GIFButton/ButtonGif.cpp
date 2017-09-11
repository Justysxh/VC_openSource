// ButtonGif.cpp : implementation file
//

#include "stdafx.h"
#include "GIFButton.h"
#include "ButtonGif.h"
#include <afxpriv2.h>
#include <Atlbase.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CButtonGif

CButtonGif::CButtonGif()
{
	m_play = false;
}

CButtonGif::~CButtonGif()
{
}


BEGIN_MESSAGE_MAP(CButtonGif, CButton)
	//{{AFX_MSG_MAP(CButtonGif)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CButtonGif message handlers
typedef struct GifImage{
	WORD lWidth;
	WORD lHeight;
	WORD width;
	WORD height;
	BYTE flag;
}Gif,*pGif;

static UINT GifThread(LPVOID GifDC)
{
	CDC* pDC = (CDC*)GifDC;
	HINSTANCE hAndle = ::AfxGetResourceHandle();
	HRSRC hRsrc = ::FindResource(hAndle,MAKEINTRESOURCE(IDR_GIF1),"GIF");
    DWORD word = ::SizeofResource(hAndle,hRsrc);
    BYTE* lpBy = (BYTE*)LoadResource(hAndle,hRsrc);
	BYTE* pByte[200];
	DWORD nu[200];
	int num = 0;
	DWORD firstLocation = 0;
	for(DWORD i=0;i<word;i++)
	{
		if(lpBy[i]==0x2c)
		{
			if(num==0)
			{
				firstLocation = i;
			}
			pGif nImage = (pGif)&lpBy[i+1];
			DWORD number = 1+sizeof(Gif);
			while(lpBy[i+number]!=0)
			{
			    number = number+(DWORD)lpBy[i+number]+1;
			}
			number++;
			pByte[num] = new BYTE[number];
			for(DWORD n=0;n<number;n++)
			{
				*(BYTE*)(pByte[num]+n) = lpBy[i+n];
			}
			nu[num] = number;
			i = i+number-1;
			num++;
		}
	}
	while(1)
	{
		for(int m=0;m<num;m++)
		{
			DWORD dWord;
			VirtualProtect(lpBy,word,PAGE_READWRITE,&dWord);
            for(DWORD n=0;n<nu[m];n++)
			{
				lpBy[firstLocation+n] = *(BYTE*)(pByte[m]+n);
			}
			VirtualProtect(lpBy,word,dWord,NULL);

	        CMemFile mfile(lpBy,word);
            CArchive aRc(&mfile,CArchive::load|CArchive::bNoFlushOnDelete);
            CArchiveStream aRcstream(&aRc);
            CComQIPtr<IPicture> m_picture;
			OleLoadPicture((LPSTREAM)&aRcstream,0,false,IID_IPicture,(void**)&m_picture);
			long x,y;
			m_picture->get_Width(&x);
			m_picture->get_Height(&y);
			CSize size(x,y);
			pDC->HIMETRICtoDP(&size);
			CRect rect;
			m_picture->Render(*pDC,0,0,size.cx,size.cy,0,y,x,-y,&rect);
			Sleep(30);
		}
	}
	return 1;
}

void CButtonGif::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CDC* pDC = this->GetDC();
	if(!m_play)
	{
		AfxBeginThread(GifThread,(LPVOID)pDC);
		m_play = true;
	}
	CRect rect(-1,-1,180,59);
	UINT State = lpDrawItemStruct->itemState;
	DrawButton(pDC,State,rect);
}

void CButtonGif::DrawButton(CDC *pDC, UINT nState, CRect rect)
{
	COLORREF UpCol,DownCol;
	if ((nState & ODS_SELECTED) == ODS_SELECTED)
	{
		UpCol=RGB(0,0,0);
		DownCol=RGB(0,0,0);
	}
	else if ((nState & ODS_DISABLED) != ODS_DISABLED)
	{
		UpCol=RGB(255,255,255);
		DownCol=RGB(128,128,128);
	}
	//画按钮的左边和上边
	CPen pen1,pen2;
	pen1.CreatePen(PS_SOLID,3,UpCol);
	pDC->SelectObject(&pen1);
	pDC->MoveTo(-1,rect.Height());
	pDC->LineTo(-1,-1);                                                             
	pDC->LineTo(rect.Width()-1,-1);
	//画按钮的右边和下边
	pen2.CreatePen(PS_SOLID,2,DownCol);
	pDC->SelectObject(&pen2);
	pDC->MoveTo(rect.Width(),-1);
	pDC->LineTo(rect.Width(),rect.Height()+1);
	pDC->LineTo(-1,rect.Height()+1);

	pen1.DeleteObject();
	pen2.DeleteObject();
}
