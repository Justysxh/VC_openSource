// PictureOverturnView.cpp : implementation of the CPictureOverturnView class
//

#include "stdafx.h"
#include "PictureOverturn.h"

#include "PictureOverturnDoc.h"
#include "PictureOverturnView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPictureOverturnView

IMPLEMENT_DYNCREATE(CPictureOverturnView, CView)

BEGIN_MESSAGE_MAP(CPictureOverturnView, CView)
	//{{AFX_MSG_MAP(CPictureOverturnView)
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPictureOverturnView construction/destruction

CPictureOverturnView::CPictureOverturnView()
{
	// TODO: add construction code here

}

CPictureOverturnView::~CPictureOverturnView()
{
}

BOOL CPictureOverturnView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	m_BS_now=IDB_BITMAP1;
	m_ID_now=IDB_BITMAP1;
	m_ID_next=IDB_BITMAP2;

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPictureOverturnView drawing

void CPictureOverturnView::OnDraw(CDC* pDC)
{
	CPictureOverturnDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	//防止了，重绘时发生的屏幕闪烁。只在刚开始时显示一次图片。
	DrawPicture(m_BS_now);	//根据m_BS_now存储的位图ID进行绘制位图
}

/////////////////////////////////////////////////////////////////////////////
// CPictureOverturnView printing

BOOL CPictureOverturnView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPictureOverturnView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPictureOverturnView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPictureOverturnView diagnostics

#ifdef _DEBUG
void CPictureOverturnView::AssertValid() const
{
	CView::AssertValid();
}

void CPictureOverturnView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPictureOverturnDoc* CPictureOverturnView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPictureOverturnDoc)));
	return (CPictureOverturnDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPictureOverturnView message handlers

BOOL CPictureOverturnView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
//	
	return true;
//	return CView::OnEraseBkgnd(pDC);
}



void CPictureOverturnView::DrawPicture(int ID_PICTURE)
{
	CDC *pDC= GetDC();		//得到客户区的设备环境
	CBitmap bitmap;			//定义一个位图变量
	bitmap.LoadBitmap(ID_PICTURE);	//将位图加载到位图变量中

	BITMAP bmp;			//定义位图结构
	bitmap.GetBitmap(&bmp);		//用位图信息填充位图结构

	CDC dcCompatible;		//定义设备上下文对象
	dcCompatible.CreateCompatibleDC(pDC);//建立内存设备上下文与pDC设备上下文相匹配
	dcCompatible.SelectObject(&bitmap);//将位图选入内存设备上下文

	CRect rect;
	GetClientRect(rect);		//得到客户区的大小

	pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&dcCompatible,
			0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);//将位图绘制在指定区域中
	ReleaseDC(pDC);
}

void CPictureOverturnView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	static int i=IDB_BITMAP1;
	//判断鼠标的位置
	CRect ClientRect;
	GetClientRect(ClientRect);
	int Clientwidth=ClientRect.Width();
	Clientwidth /=2;
	CString str;
	if(point.x>Clientwidth)
	{		
		
		if(i==IDB_BITMAP1+16)
		{
			i=IDB_BITMAP1+16;
		}
		else
		{
			int picture_pos=i;
			//传递图片的ID，并且在内部调用SetTimer函数
			DrawLToR(picture_pos,picture_pos+1);
			i++;//页面加一
			m_BS_now++;//保存当前的页面，放大缩小时使用。
		}
		
	}
	else
	{
		
		if(i==IDB_BITMAP1)
		{	
			i=IDB_BITMAP1;
		}
		else
		{
			int picture_pos=i;
			DrawRToL(picture_pos,picture_pos-1);
			i--;
			m_BS_now--;
		}

	}
	CView::OnLButtonDown(nFlags, point);
}

void CPictureOverturnView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nIDEvent)
	{
	case 1 :	//图片由左向右翻，左页的翻转(第一步)
		{
			OverPicture_LToR();
			break;
		}

	case 2:		//图片由左向右翻，右页的翻转（第二步）
		{
			OverPicture_LToR2();
			break;
		}
	case 3:
		{
			OverPicture_RToL();
			break;
		}
	case 4:
		{
			OverPicture_RToL2();
			break;
		}
	default:
		{
			break;
		}

	}
	CView::OnTimer(nIDEvent);
}



////////////////////////
//从左向右的翻页
void CPictureOverturnView::OverPicture_LToR()
{

	static int page_step=0;
	
	CDC *pDC= GetDC();
	//bitmapnow是当前的位图，bitmap是下一张位图
	CBitmap bitmapnow,bitmapnext;
	bitmapnow.LoadBitmap(m_ID_now);
	bitmapnext.LoadBitmap(m_ID_next);

	//定义bitmapnow位图的结构
	BITMAP bmpnow ,bmpnext;
	bitmapnow.GetBitmap(&bmpnow);//当前的位图结构
	bitmapnow.GetBitmap(&bmpnext);//下一张的位图结构

	//将当前图片选入设备描述表中
	CDC dcnow;
	dcnow.CreateCompatibleDC(pDC);
	dcnow.SelectObject(&bitmapnow);
	//将下一张图片选入设备描述表中
	CDC dcnext;
	dcnext.CreateCompatibleDC(pDC);
	dcnext.SelectObject(&bitmapnext);


	CRect rect;
	GetClientRect(rect);
	//将位图复制显示到一个矩形中（填入矩形）
	//填入矩形的右上点，宽，高， 设备描述表。
	//选择位图的右上点，宽，高， 复制的方式
	//先画出左边不动的当前位图。
	pDC->StretchBlt(0,0,rect.Width()/2,rect.Height(),&dcnow,
			0,0,bmpnow.bmWidth/2,bmpnow.bmHeight,SRCCOPY);
	//画出右边下一张的位图
	pDC->StretchBlt(rect.Width()-rect.Width()/12*page_step,//填入矩形的x点
			0,				//填入矩形的y点
			rect.Width()/12*page_step,	//填入矩形的宽度
			rect.Height(),			//填入矩形的高度
			&dcnext,			//存放位图的设备描述表
			bmpnext.bmWidth/2+bmpnext.bmWidth/2-bmpnext.bmWidth/12*page_step,//位图的起始x点
			0,				//位图的起始y点
			bmpnext.bmWidth/12*page_step,	//位图的宽度
			bmpnext.bmHeight,		//位图的高度
			SRCCOPY);			//复制的方式
	//画出右边当前变形的位图，覆盖了下一张位图。
	pDC->StretchBlt(rect.Width()/2,0,rect.Width()/2-rect.Width()/12*page_step,rect.Height(),&dcnow,
			bmpnow.bmWidth/2,0,bmpnow.bmWidth/2,bmpnow.bmHeight,SRCCOPY);

	page_step++;
	if(page_step>6)
	{
		page_step=0;
		KillTimer(1);		//取消1号定时器的掉用	
		ReleaseDC(&dcnow);//释放内存设备上下文
		ReleaseDC(&dcnext);
		ReleaseDC(pDC);
		SetTimer(2,150,NULL);	//调用2号定时器
	}
	ReleaseDC(&dcnow);
	ReleaseDC(&dcnext);
	ReleaseDC(pDC);

	
}


//传递图片的ID，调用定时器中1号定时器
void CPictureOverturnView::DrawLToR(int IDNOW, int IDNEXT)
{
	m_ID_now=IDNOW;
	m_ID_next= IDNEXT;
	SetTimer(1,150,NULL);
}

void CPictureOverturnView::OverPicture_LToR2()
{
	static int page_step=0;
	
	//bitmapnow是当前的位图，bitmap是下一张位图
	CDC *pDC = GetDC();
	CBitmap bitmapnow,bitmapnext;
	bitmapnow.LoadBitmap(m_ID_now);
	bitmapnext.LoadBitmap(m_ID_next);
	
	//定义bitmapnow位图的结构
	BITMAP bmpnow ,bmpnext;
	bitmapnow.GetBitmap(&bmpnow);//当前的位图结构
	bitmapnow.GetBitmap(&bmpnext);//下一张的位图结构
	
	//将当前图片选入设备描述表中
	CDC dcnow;
	dcnow.CreateCompatibleDC(pDC);
	dcnow.SelectObject(&bitmapnow);
	//将下一张图片选入设备描述表中
	CDC dcnext;
	dcnext.CreateCompatibleDC(pDC);
	dcnext.SelectObject(&bitmapnext);
	
	
	CRect rect;
	GetClientRect(rect);
	//将位图复制显示到一个矩形中（填入矩形）
	//填入矩形的右上点，宽，高， 设备描述表。
	//选择位图的右上点，宽，高， 复制的方式
	//先画出右边不动的下一张位图。
	pDC->StretchBlt(rect.Width()/2,0,rect.Width()/2,rect.Height(),&dcnext,
		bmpnext.bmWidth/2,0,bmpnext.bmWidth/2,bmpnext.bmHeight,SRCCOPY);
	//画出左边当前的位图
	pDC->StretchBlt(
		0,				//填入矩形的x点
		0,				//填入矩形的y点
		rect.Width()/2-rect.Width()/12*page_step,	//填入矩形的宽度
		rect.Height(),			//填入矩形的高度
		&dcnow,			//存放位图的设备描述表
		0,//位图的起始x点
		0,				//位图的起始y点
		bmpnow.bmWidth/2-bmpnow.bmWidth/12*page_step,	//位图的宽度
		bmpnow.bmHeight,		//位图的高度
		SRCCOPY);			//复制的方式
	//画出左边下一张变形的位图，覆盖了当前位图。
	pDC->StretchBlt(rect.Width()/2-rect.Width()/12*page_step,//矩形的x点
		0,			//矩形的y点
		rect.Width()/12*page_step,//矩形的宽度
		rect.Height(),
		&dcnext,
		0,			//位图的x点
		0,			//位图的y点
		bmpnext.bmWidth/2,
		bmpnext.bmHeight,
		SRCCOPY);
	
	page_step++;
	if(page_step>6)
	{
		page_step=0;
		KillTimer(2);
		ReleaseDC(&dcnow);
		ReleaseDC(&dcnext);
		ReleaseDC(pDC);
		//再画一遍当前的图片，这样效果会好一些
		DrawPicture(m_BS_now);
	}
	ReleaseDC(&dcnow);
	ReleaseDC(&dcnext);
	ReleaseDC(pDC);
	
}



void CPictureOverturnView::OverPicture_RToL()
{
	static int page_step=0;
	
	CDC *pDC= GetDC();
	//bitmapnow是当前的位图，bitmapnext是上一张位图
	CBitmap bitmapnow,bitmapnext;
	bitmapnow.LoadBitmap(m_ID_now);//当前页
	bitmapnext.LoadBitmap(m_ID_next);//前一页
	
	//定义bitmapnow位图的结构
	BITMAP bmpnow ,bmpnext;
	bitmapnow.GetBitmap(&bmpnow);//当前的位图结构
	bitmapnow.GetBitmap(&bmpnext);//下一张的位图结构
	
	//将当前图片选入设备描述表中
	CDC dcnow;
	dcnow.CreateCompatibleDC(pDC);
	dcnow.SelectObject(&bitmapnow);
	//将下一张图片选入设备描述表中
	CDC dcnext;
	dcnext.CreateCompatibleDC(pDC);
	dcnext.SelectObject(&bitmapnext);
	
	
	CRect rect;
	GetClientRect(rect);
	//将位图复制显示到一个矩形中（填入矩形）
	//填入矩形的右上点，宽，高， 设备描述表。
	//选择位图的右上点，宽，高， 复制的方式
	//先画出右边不动的当前位图。
	pDC->StretchBlt(rect.Width()/2,0,rect.Width()/2,rect.Height(),&dcnow,
		bmpnow.bmWidth/2,0,bmpnow.bmWidth/2,bmpnow.bmHeight,SRCCOPY);
	//画出右边下一张的位图
	pDC->StretchBlt(0,			//填入矩形的x点
		0,				//填入矩形的y点
		rect.Width()/12*page_step,	//填入矩形的宽度
		rect.Height(),			//填入矩形的高度
		&dcnext,			//存放位图的设备描述表
		0,//位图的起始x点
		0,				//位图的起始y点
		bmpnext.bmWidth/12*page_step,	//位图的宽度
		bmpnext.bmHeight,		//位图的高度
		SRCCOPY);			//复制的方式
	//画出右边当前变形的位图，覆盖了下一张位图。
	pDC->StretchBlt(rect.Width()/12*page_step,0,rect.Width()/2-rect.Width()/12*page_step,rect.Height(),&dcnow,
		0,0,bmpnow.bmWidth/2,bmpnow.bmHeight,SRCCOPY);					
	page_step++;
	if(page_step>6)
	{
		page_step=0;
		KillTimer(3);
		ReleaseDC(&dcnow);
		ReleaseDC(&dcnext);
		ReleaseDC(pDC);
		SetTimer(4,150,NULL);//调用4号定时器
	}
	ReleaseDC(&dcnow);
	ReleaseDC(&dcnext);
	ReleaseDC(pDC);
	
	
}



void CPictureOverturnView::DrawRToL(int IDNOW, int IDNEXT)
{
	m_ID_now=IDNOW;
	m_ID_next= IDNEXT;
	SetTimer(3,150,NULL);
}

void CPictureOverturnView::OverPicture_RToL2()
{
	static int page_step=0;
	
	CDC *pDC= GetDC();
	//bitmapnow是当前的位图，bitmapnext是上一张位图
	CBitmap bitmapnow,bitmapnext;
	bitmapnow.LoadBitmap(m_ID_now);//大的
	bitmapnext.LoadBitmap(m_ID_next);//小的
	
	//定义bitmapnow位图的结构
	BITMAP bmpnow ,bmpnext;
	bitmapnow.GetBitmap(&bmpnow);//当前的位图结构
	bitmapnow.GetBitmap(&bmpnext);//下一张的位图结构
	
	//将当前图片选入设备描述表中
	CDC dcnow;
	dcnow.CreateCompatibleDC(pDC);
	dcnow.SelectObject(&bitmapnow);
	//将下一张图片选入设备描述表中
	CDC dcnext;
	dcnext.CreateCompatibleDC(pDC);
	dcnext.SelectObject(&bitmapnext);
	
	
	CRect rect;
	GetClientRect(rect);
	//将位图复制显示到一个矩形中（填入矩形）
	//填入矩形的右上点，宽，高， 设备描述表。
	//选择位图的右上点，宽，高， 复制的方式
	//先画出左边不动的当前位图。
	pDC->StretchBlt(0,0,rect.Width()/2,rect.Height(),&dcnext,
		0,0,bmpnext.bmWidth/2,bmpnext.bmHeight,SRCCOPY);
	//画出右边下一张的位图
	pDC->StretchBlt(
		rect.Width()/2+rect.Width()/12*page_step,			//填入矩形的x点
		0,				//填入矩形的y点
		rect.Width()/2-rect.Width()/12*page_step,	//填入矩形的宽度
		rect.Height(),			//填入矩形的高度
		&dcnow,			//存放位图的设备描述表
		bmpnow.bmWidth/2+bmpnow.bmWidth/12*page_step,//位图的起始x点
		0,				//位图的起始y点
		bmpnow.bmWidth/2-bmpnow.bmWidth/12*page_step,	//位图的宽度
		bmpnow.bmHeight,		//位图的高度
		SRCCOPY);			//复制的方式
	//画出右边当前变形的位图，覆盖了下一张位图。
	pDC->StretchBlt(rect.Width()/2,			//填入矩形的x点
		0,				//填入矩形的y点
		rect.Width()/12*page_step,	//填入矩形的宽度
		rect.Height(),			//填入矩形的高度
		&dcnext,			//存放位图的设备描述表
		bmpnext.bmWidth/2,//位图的起始x点
		0,				//位图的起始y点
		bmpnext.bmWidth/2,	//位图的宽度
		bmpnext.bmHeight,		//位图的高度
		SRCCOPY);			//复制的方式					
	page_step++;
	if(page_step>6)
	{
		page_step=0;
		KillTimer(4);
		ReleaseDC(&dcnow);
		ReleaseDC(&dcnext);
		ReleaseDC(pDC);
		//再画一遍当前的图片，这样效果会好一些
		DrawPicture(m_BS_now);
	}
	ReleaseDC(&dcnow);
	ReleaseDC(&dcnext);
	ReleaseDC(pDC);
}
