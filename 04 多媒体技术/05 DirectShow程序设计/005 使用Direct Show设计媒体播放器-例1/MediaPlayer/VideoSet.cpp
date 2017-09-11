// VideoSet.cpp : implementation file
//

#include "stdafx.h"
#include "MediaPlayer.h"
#include "VideoSet.h"
#include "DirectShowEventDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVideoSet dialog


CVideoSet::CVideoSet(CWnd* pParent /*=NULL*/)
	: CDialog(CVideoSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVideoSet)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CVideoSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVideoSet)
	DDX_Control(pDX, IDC_CONTRASTNUM, m_ConNum);
	DDX_Control(pDX, IDC_BRIGHTNUM, m_BrightNum);
	DDX_Control(pDX, IDC_SATNUM, m_SatNum);
	DDX_Control(pDX, IDC_HUENUM, m_HueNum);
	DDX_Control(pDX, IDC_SATURATION, m_Saturation);
	DDX_Control(pDX, IDC_HUE, m_Hue);
	DDX_Control(pDX, IDC_CONTRAST, m_Contrast);
	DDX_Control(pDX, IDC_BRIGHTNESS, m_Brightness);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CVideoSet, CDialog)
	//{{AFX_MSG_MAP(CVideoSet)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_HUENUM, OnChangeHuenum)
	ON_EN_CHANGE(IDC_SATNUM, OnChangeSatnum)
	ON_EN_CHANGE(IDC_BRIGHTNUM, OnChangeBrightnum)
	ON_EN_CHANGE(IDC_CONTRASTNUM, OnChangeContrastnum)
	ON_BN_CLICKED(IDC_TB_CANCEL, OnTbCancel)
	ON_BN_CLICKED(IDC_DEFAULT, OnDefault)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVideoSet message handlers

void CVideoSet::OnOK() 
{

}

BOOL CVideoSet::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CDirectShowEventDlg *pMainDlg = NULL;
	pMainDlg = (CDirectShowEventDlg *)AfxGetMainWnd();
	if (pMainDlg)
	{
		m_Hue.SetRange(pMainDlg->m_HueRange.MinValue,pMainDlg->m_HueRange.MaxValue);		
		WPARAM wParam;
		MAKEWPARAM(SB_THUMBPOSITION,pMainDlg->m_fHue);
		m_Hue.SetPos(100);
		m_Hue.SetPos(pMainDlg->m_fHue);
		SendMessage(WM_HSCROLL,wParam,(LPARAM)m_Hue.m_hWnd);


		m_Saturation.SetRange(pMainDlg->m_SatRange.MinValue*100,pMainDlg->m_SatRange.MaxValue*100);		
		MAKEWPARAM(SB_THUMBPOSITION,pMainDlg->m_fSaturation*100);
		m_Saturation.SetPos(100);
		m_Saturation.SetPos(pMainDlg->m_fSaturation*100);
		SendMessage(WM_HSCROLL,wParam,(LPARAM)m_Saturation.m_hWnd);

		m_Brightness.SetRange(pMainDlg->m_BrightRange.MinValue,pMainDlg->m_BrightRange.MaxValue);		
		MAKEWPARAM(SB_THUMBPOSITION,pMainDlg->m_fBright);
		m_Brightness.SetPos(100);
		m_Brightness.SetPos(pMainDlg->m_fBright);
		SendMessage(WM_HSCROLL,wParam,(LPARAM)m_Brightness.m_hWnd);

		m_Contrast.SetRange(pMainDlg->m_ConRange.MinValue*100,pMainDlg->m_ConRange.MaxValue*100);		
		MAKEWPARAM(SB_THUMBPOSITION,1*100);
		m_Contrast.SetPos(100);
		m_Contrast.SetPos(1*100);
		SendMessage(WM_HSCROLL,wParam,(LPARAM)m_Contrast.m_hWnd);
	}

	return TRUE;  
}

void CVideoSet::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	if (pScrollBar != NULL)
	{
		CDirectShowEventDlg *pMainDlg = NULL;
		pMainDlg = (CDirectShowEventDlg *)AfxGetMainWnd();

		pMainDlg->m_bGrayImage = FALSE;

		pMainDlg->m_GrayBtn.SetWindowText("ºÚ°×Í¼Ïñ");
		pMainDlg->m_GrayBtn.Invalidate();
		if (pScrollBar->m_hWnd==m_Hue.m_hWnd)
		{
			if (nSBCode==SB_THUMBPOSITION)
			{
				m_Hue.SetPos(nPos);
			}
			int nCurPos = m_Hue.GetPos();
			CString csPos;
			csPos.Format("%i",nCurPos);
			m_HueNum.SetWindowText(csPos);

			pMainDlg->SetViewInfo(ProcAmpControl9_Hue,nCurPos);
			pMainDlg->m_fHue = nCurPos;


		}
		else if (pScrollBar->m_hWnd==m_Saturation.m_hWnd)
		{
			if (nSBCode==SB_THUMBPOSITION)
			{
				m_Saturation.SetPos(nPos);
			}
			int nCurPos = m_Saturation.GetPos();
			CString csPos;
			csPos.Format("%i",nCurPos);
			m_SatNum.SetWindowText(csPos);	

			pMainDlg->SetViewInfo(ProcAmpControl9_Saturation,nCurPos/100.0);
			pMainDlg->m_fSaturation = nCurPos/100.0;
		}
		else if (pScrollBar->m_hWnd==m_Brightness.m_hWnd)
		{
			if (nSBCode==SB_THUMBPOSITION)
			{
				m_Brightness.SetPos(nPos);
			}
			int nCurPos = m_Brightness.GetPos();
			CString csPos;
			csPos.Format("%i",nCurPos);
			m_BrightNum.SetWindowText(csPos);	
			pMainDlg->SetViewInfo(ProcAmpControl9_Brightness,nCurPos);	
			pMainDlg->m_fBright = nCurPos;

		}
		else if (pScrollBar->m_hWnd==m_Contrast.m_hWnd)
		{
			if (nSBCode==SB_THUMBPOSITION)
			{
				m_Contrast.SetPos(nPos);
			}
			int nCurPos = m_Contrast.GetPos();
			CString csPos;
			csPos.Format("%i",nCurPos);
			m_ConNum.SetWindowText(csPos);	
			pMainDlg->SetViewInfo(ProcAmpControl9_Contrast,nCurPos/100.0);	
			pMainDlg->m_fContrast = nCurPos/100.0;
		}
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CVideoSet::OnChangeHuenum() 
{
	CString csText;
	m_HueNum.GetWindowText(csText);
	if (!csText.IsEmpty())
	{
		m_Hue.SetPos(atoi(csText));
	}
}


void CVideoSet::OnChangeSatnum() 
{
	CString csText;
	m_SatNum.GetWindowText(csText);
	if (!csText.IsEmpty())
	{
		m_Saturation.SetPos(atoi(csText));
	}
}

void CVideoSet::OnChangeBrightnum() 
{
	CString csText;
	m_BrightNum.GetWindowText(csText);
	if (!csText.IsEmpty())
	{
		m_Brightness.SetPos(atoi(csText));
	}	
}

void CVideoSet::OnChangeContrastnum() 
{
	CString csText;
	m_ConNum.GetWindowText(csText);
	if (!csText.IsEmpty())
	{
		m_Contrast.SetPos(atoi(csText));
	}	
}

void CVideoSet::OnTbCancel() 
{
	CDialog::OnCancel();	
}

void CVideoSet::OnDefault() 
{
	CDirectShowEventDlg *pMainDlg = NULL;
	pMainDlg = (CDirectShowEventDlg *)AfxGetMainWnd();
	if (pMainDlg)
	{
		m_Hue.SetRange(pMainDlg->m_HueRange.MinValue,pMainDlg->m_HueRange.MaxValue);		
		WPARAM wParam;
		MAKEWPARAM(SB_THUMBPOSITION,1);
		m_Hue.SetPos(100);
		m_Hue.SetPos(1);
		SendMessage(WM_HSCROLL,wParam,(LPARAM)m_Hue.m_hWnd);
		pMainDlg->m_fHue = 1;

		m_Saturation.SetRange(pMainDlg->m_SatRange.MinValue*100,pMainDlg->m_SatRange.MaxValue*100);		
		MAKEWPARAM(SB_THUMBPOSITION,1*100);
		m_Saturation.SetPos(100);
		m_Saturation.SetPos(1*100);
		SendMessage(WM_HSCROLL,wParam,(LPARAM)m_Saturation.m_hWnd);
		pMainDlg->m_fSaturation = 1;

		m_Brightness.SetRange(pMainDlg->m_BrightRange.MinValue,pMainDlg->m_BrightRange.MaxValue);		
		MAKEWPARAM(SB_THUMBPOSITION,1);
		m_Brightness.SetPos(100);
		m_Brightness.SetPos(1);
		SendMessage(WM_HSCROLL,wParam,(LPARAM)m_Brightness.m_hWnd);
		pMainDlg->m_fBright = 1;

		m_Contrast.SetRange(pMainDlg->m_ConRange.MinValue*100,pMainDlg->m_ConRange.MaxValue*100);		
		MAKEWPARAM(SB_THUMBPOSITION,1*100);
		m_Contrast.SetPos(100);
		m_Contrast.SetPos(1*100);
		SendMessage(WM_HSCROLL,wParam,(LPARAM)m_Contrast.m_hWnd);
		pMainDlg->m_fContrast = 1;
	}
}
