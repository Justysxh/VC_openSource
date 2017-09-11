// Preview.cpp : implementation file
//

#include "stdafx.h"
#include "envelopprint.h"
#include "Preview.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPreview dialog


CPreview::CPreview(CWnd* pParent /*=NULL*/)
	: CDialog(CPreview::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPreview)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPreview::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPreview)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPreview, CDialog)
	//{{AFX_MSG_MAP(CPreview)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPreview message handlers

void CPreview::DrawReport(CRect rect, CDC *pDC, BOOL isprinted)
{
	titlefont.CreatePointFont(110,_T("ËÎÌå"),pDC);
	int printx,printy;
	printx = pDC->GetDeviceCaps(LOGPIXELSX);
	printy = pDC->GetDeviceCaps(LOGPIXELSY);
	double ratex = (double)(printx)/screenx;
	double ratey = (double)(printy)/screeny;
	if(isprinted)
	{
		pDC->StartDoc("printinformation");	
	}
	else
	{
		ratex=1,ratey=1;
	}
	for(int i=0;i<6;i++)
	{
		pDC->SelectObject(&titlefont);
		pDC->Rectangle((int)((20+i*30)*ratex),(int)(20*ratey),(int)((40+i*30)*ratex),(int)(40*ratey));	
		if(i==0)
		{
			rect.DeflateRect((int)(25*ratex),(int)(23*ratey),0,0);
			pDC->DrawText(sarrays[0][i],rect,DT_LEFT);
		}
		else
		{
			rect.DeflateRect((int)(-330*ratex),(int)(-240*ratey),0,0);
			pDC->DrawText(sarrays[0][i],rect,DT_LEFT);
		}
		pDC->Rectangle((int)((380+i*30)*ratex),(int)(260*ratey),(int)((400+i*30)*ratex),(int)(280*ratey));
		rect.DeflateRect((int)(360*ratex),(int)(240*ratey),0,0);
		pDC->DrawText(sarrays[1][i],rect,DT_LEFT);
	}
	pDC->MoveTo((int)(150*ratex),(int)(120*ratey));
	pDC->LineTo((int)(450*ratex),(int)(120*ratey));
	pDC->MoveTo((int)(150*ratex),(int)(150*ratey));
	pDC->LineTo((int)(450*ratex),(int)(150*ratey));
	pDC->MoveTo((int)(150*ratex),(int)(180*ratey));
	pDC->LineTo((int)(450*ratex),(int)(180*ratey));
	CString str1,str2;
	int n;
	n = strText.GetLength();
	if(n/3<42)
	{
		str1=strText.Left(42);
		rect.DeflateRect((int)(-385*ratex),(int)(-160*ratey),0,0);
		pDC->DrawText(str1,rect,DT_LEFT);
		str2=strText.Right(n-42);
		rect.DeflateRect(0,(int)(30*ratey),0,0);
		pDC->DrawText(str2,rect,DT_LEFT);
		rect.DeflateRect(0,(int)(30*ratey),0,0);
		pDC->DrawText(strsxr,rect,DT_LEFT);
	}
	else
	{
		str1=strText.Left(n/2);
		rect.DeflateRect((int)(-385*ratex),(int)(-160*ratey),0,0);
		pDC->DrawText(str1,rect,DT_LEFT);
		str2=strText.Right(n-n/2);
		rect.DeflateRect(0,(int)(30*ratey),0,0);
		pDC->DrawText(str2,rect,DT_LEFT);
		rect.DeflateRect(0,(int)(30*ratey),0,0);
		pDC->DrawText(strsxr,rect,DT_LEFT);
	}
	if(isprinted)
	{
		pDC->EndDoc();
	}
	titlefont.DeleteObject();
}

void CPreview::hanshu()
{
	strText = m_dz;
	strsxr = m_sxr+"£¨ÊÕ£©";
	CString str1,str2,str3,str4;
	int n,m,i=1,p,q,j=1;
	n=m_yb.GetLength();
	str1=m_yb.Left(1);
	sarrays[0][0]= str1;
	str2=m_yb.Right(n-1);
	m=str2.GetLength();
	while(m>0)
	{
		str1=str2.Left(1);
		sarrays[0][i]= str1;
		str2=str2.Right(m-1);
		m=str2.GetLength();
		i++;
	}
	p=edit.GetLength();
	str3=edit.Left(1);
	sarrays[1][0]= str3;
	str4=edit.Right(p-1);
	q=str4.GetLength();
	while(q>0)
	{
		str3=str4.Left(1);
		sarrays[1][j]= str3;
		str4=str4.Right(q-1);
		q=str4.GetLength();
		j++;
	}
}

HBRUSH CPreview::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	CBrush m_brush (RGB(255,255,255));
	CRect m_rect;
	GetClientRect(m_rect);
	pDC->FillRect(m_rect,&m_brush);
	// TODO: Return a different brush if the default is not desired
	return m_brush;
}

void CPreview::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CRect m_rect;
	GetClientRect(m_rect);	
	CDC* pDC = GetDC();
	screenx = pDC->GetDeviceCaps(LOGPIXELSX);
	screeny = pDC->GetDeviceCaps(LOGPIXELSY);
	DrawReport(m_rect,GetDC(),false);
	// Do not call CDialog::OnPaint() for painting messages
}
