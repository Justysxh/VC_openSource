// FetchDirDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FetchDir.h"
#include "FetchDirDlg.h"
#include "msword9.h"
#include "atlbase.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

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
// CFetchDirDlg dialog

CFetchDirDlg::CFetchDirDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFetchDirDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFetchDirDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFetchDirDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFetchDirDlg)
	DDX_Control(pDX, IDC_LIST, m_List);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFetchDirDlg, CDialog)
	//{{AFX_MSG_MAP(CFetchDirDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_FETCH, OnFetch)
	ON_BN_CLICKED(IDC_SAVETOFILE, OnSaveToFile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFetchDirDlg message handlers

BOOL CFetchDirDlg::OnInitDialog()
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
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFetchDirDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFetchDirDlg::OnPaint() 
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
HCURSOR CFetchDirDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFetchDirDlg::OnFetch() 
{
	//选择word文档
	CFileDialog flDlg(TRUE, "", "", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
						"word文档|*.doc||");
	if (flDlg.DoModal()==IDOK)
	{

		CString szFileName = flDlg.GetPathName();
		_Application	wordApp;
		Documents		wordDocs;
		wordApp.CreateDispatch("word.Application");
		wordDocs.AttachDispatch(wordApp.GetDocuments());
		_Document		wordDoc;
		
		CComVariant filename(szFileName.AllocSysString()), visible(TRUE), doctype(0), doctemplate(TRUE);
		szFileName.ReleaseBuffer();
		wordDoc.AttachDispatch(wordDocs.Add(&filename, &visible, &doctype, &doctemplate));

		Paragraphs pgraphs;
		pgraphs.AttachDispatch(wordDoc.GetParagraphs());

		m_List.ResetContent();	//删除列表中的内容

		long pgraphCount = pgraphs.GetCount();
		for (long i = 1; i<= pgraphCount; i++)
		{
			Paragraph pgraph;
			pgraph.AttachDispatch(pgraphs.Item(i));
			Range pragRange;
			pragRange.AttachDispatch(pgraph.GetRange());
			_ParagraphFormat format;
			format.AttachDispatch(pragRange.GetParagraphFormat());
			CComVariant value;

			Style style;
		
			value = format.GetStyle();
			style.AttachDispatch(value.pdispVal);
			
			CString szHeaderName = style.GetNameLocal();
			char  szName[10] = {0};
			strncpy(szName, szHeaderName.GetBuffer(0), 6);
			szHeaderName.ReleaseBuffer(0);
			if (strcmp(szName, "标题 1") == 0)
			{
				//读取标题内容
				CString szText = pragRange.GetText();
				int nIndex = m_List.AddString(szText);
				m_List.SetItemData(nIndex, 1);
			}
			else if (strcmp(szName, "标题 2") == 0)
			{
				//读取标题内容
				CString szText = pragRange.GetText();
				int nIndex = m_List.AddString(szText);
				m_List.SetItemData(nIndex, 2);
			}
			else if (strcmp(szName, "标题 3") == 0)
			{
				//读取标题内容
				CString szText = pragRange.GetText();
				int nIndex = m_List.AddString(szText);
				m_List.SetItemData(nIndex, 3);
			}

		}
	
		CComVariant save(0), format(0), route(0);
		wordDoc.Close(&save, &format, &route);
		wordApp.Quit(&save, &format, &route);		
	}
}

//保存列表中的内容到.txt文件中
void CFetchDirDlg::OnSaveToFile() 
{
	CFileDialog flDlg(FALSE, "txt", "directory.txt", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
						"文本文件|*.txt||");
	if (flDlg.DoModal()==IDOK)
	{
		CString szSaveName = flDlg.GetPathName();
		CFile file;
		file.Open(szSaveName, CFile::modeCreate|CFile::modeReadWrite);
		int nLineCount = m_List.GetCount();
		DWORD dwItemData = 0;
		char szReturn[2] = {"\n"};	//换行符
		char szIndent[5] = {' ', ' ',' ', ' ', ' '};	//缩进4个空格
		for (int i=0; i<nLineCount; i++)
		{
			CString szText;
			m_List.GetText(i, szText);
			dwItemData = m_List.GetItemData(i);
			if (dwItemData == 1)	//一级目录
			{
				file.Write(szText.GetBuffer(0), szText.GetLength());
				file.Write(szReturn, 2);
			}
			else if (dwItemData == 2)	//二级目录
			{
				for(int j = 0; j< dwItemData-1; j++)
				{
					file.Write(szIndent, 5);
				}
				file.Write(szText.GetBuffer(0), szText.GetLength());
				file.Write(szReturn, 2);
			}
			else if(dwItemData == 3)	//三级目录
			{
				for(int j = 0; j< dwItemData-1; j++)
				{
					file.Write(szIndent, 5);
				}
				file.Write(szText.GetBuffer(0), szText.GetLength());
				file.Write(szReturn, 2);
			}
			
			szText.ReleaseBuffer();
		}
		file.Close();
	}

}
