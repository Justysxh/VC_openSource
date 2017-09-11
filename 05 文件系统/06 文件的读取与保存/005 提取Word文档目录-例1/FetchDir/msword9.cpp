// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "msword9.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// _Application properties

/////////////////////////////////////////////////////////////////////////////
// _Application operations

LPDISPATCH _Application::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _Application::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _Application::GetName()
{
	CString result;
	InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetDocuments()
{
	LPDISPATCH result;
	InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetWindows()
{
	LPDISPATCH result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetActiveDocument()
{
	LPDISPATCH result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetActiveWindow()
{
	LPDISPATCH result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetSelection()
{
	LPDISPATCH result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetWordBasic()
{
	LPDISPATCH result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetRecentFiles()
{
	LPDISPATCH result;
	InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetNormalTemplate()
{
	LPDISPATCH result;
	InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetSystem()
{
	LPDISPATCH result;
	InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetAutoCorrect()
{
	LPDISPATCH result;
	InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetFontNames()
{
	LPDISPATCH result;
	InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetLandscapeFontNames()
{
	LPDISPATCH result;
	InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetPortraitFontNames()
{
	LPDISPATCH result;
	InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetLanguages()
{
	LPDISPATCH result;
	InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetAssistant()
{
	LPDISPATCH result;
	InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetBrowser()
{
	LPDISPATCH result;
	InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetFileConverters()
{
	LPDISPATCH result;
	InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetMailingLabel()
{
	LPDISPATCH result;
	InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetDialogs()
{
	LPDISPATCH result;
	InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetCaptionLabels()
{
	LPDISPATCH result;
	InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetAutoCaptions()
{
	LPDISPATCH result;
	InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetAddIns()
{
	LPDISPATCH result;
	InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _Application::GetVisible()
{
	BOOL result;
	InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetVisible(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x17, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString _Application::GetVersion()
{
	CString result;
	InvokeHelper(0x18, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

BOOL _Application::GetScreenUpdating()
{
	BOOL result;
	InvokeHelper(0x1a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetScreenUpdating(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x1a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Application::GetPrintPreview()
{
	BOOL result;
	InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetPrintPreview(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x1b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH _Application::GetTasks()
{
	LPDISPATCH result;
	InvokeHelper(0x1c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _Application::GetDisplayStatusBar()
{
	BOOL result;
	InvokeHelper(0x1d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetDisplayStatusBar(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x1d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Application::GetSpecialMode()
{
	BOOL result;
	InvokeHelper(0x1e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

long _Application::GetUsableWidth()
{
	long result;
	InvokeHelper(0x21, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _Application::GetUsableHeight()
{
	long result;
	InvokeHelper(0x22, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL _Application::GetMathCoprocessorAvailable()
{
	BOOL result;
	InvokeHelper(0x24, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL _Application::GetMouseAvailable()
{
	BOOL result;
	InvokeHelper(0x25, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

VARIANT _Application::GetInternational(long Index)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x2e, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, parms,
		Index);
	return result;
}

CString _Application::GetBuild()
{
	CString result;
	InvokeHelper(0x2f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

BOOL _Application::GetCapsLock()
{
	BOOL result;
	InvokeHelper(0x30, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL _Application::GetNumLock()
{
	BOOL result;
	InvokeHelper(0x31, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

CString _Application::GetUserName_()
{
	CString result;
	InvokeHelper(0x34, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Application::SetUserName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x34, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _Application::GetUserInitials()
{
	CString result;
	InvokeHelper(0x35, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Application::SetUserInitials(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x35, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _Application::GetUserAddress()
{
	CString result;
	InvokeHelper(0x36, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Application::SetUserAddress(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x36, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

LPDISPATCH _Application::GetMacroContainer()
{
	LPDISPATCH result;
	InvokeHelper(0x37, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _Application::GetDisplayRecentFiles()
{
	BOOL result;
	InvokeHelper(0x38, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetDisplayRecentFiles(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x38, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH _Application::GetCommandBars()
{
	LPDISPATCH result;
	InvokeHelper(0x39, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetSynonymInfo(LPCTSTR Word, VARIANT* LanguageID)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR VTS_PVARIANT;
	InvokeHelper(0x3b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms,
		Word, LanguageID);
	return result;
}

LPDISPATCH _Application::GetVbe()
{
	LPDISPATCH result;
	InvokeHelper(0x3d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _Application::GetDefaultSaveFormat()
{
	CString result;
	InvokeHelper(0x40, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Application::SetDefaultSaveFormat(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x40, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

LPDISPATCH _Application::GetListGalleries()
{
	LPDISPATCH result;
	InvokeHelper(0x41, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _Application::GetActivePrinter()
{
	CString result;
	InvokeHelper(0x42, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Application::SetActivePrinter(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x42, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

LPDISPATCH _Application::GetTemplates()
{
	LPDISPATCH result;
	InvokeHelper(0x43, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetCustomizationContext()
{
	LPDISPATCH result;
	InvokeHelper(0x44, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _Application::SetCustomizationContext(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x44, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH _Application::GetKeyBindings()
{
	LPDISPATCH result;
	InvokeHelper(0x45, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetKeysBoundTo(long KeyCategory, LPCTSTR Command, VARIANT* CommandParameter)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4 VTS_BSTR VTS_PVARIANT;
	InvokeHelper(0x46, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms,
		KeyCategory, Command, CommandParameter);
	return result;
}

LPDISPATCH _Application::GetFindKey(long KeyCode, VARIANT* KeyCode2)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4 VTS_PVARIANT;
	InvokeHelper(0x47, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms,
		KeyCode, KeyCode2);
	return result;
}

CString _Application::GetCaption()
{
	CString result;
	InvokeHelper(0x50, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Application::SetCaption(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x50, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _Application::GetPath()
{
	CString result;
	InvokeHelper(0x51, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

BOOL _Application::GetDisplayScrollBars()
{
	BOOL result;
	InvokeHelper(0x52, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetDisplayScrollBars(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x52, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString _Application::GetStartupPath()
{
	CString result;
	InvokeHelper(0x53, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Application::SetStartupPath(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x53, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long _Application::GetBackgroundSavingStatus()
{
	long result;
	InvokeHelper(0x55, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _Application::GetBackgroundPrintingStatus()
{
	long result;
	InvokeHelper(0x56, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _Application::GetLeft()
{
	long result;
	InvokeHelper(0x57, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetLeft(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x57, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Application::GetTop()
{
	long result;
	InvokeHelper(0x58, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetTop(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x58, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Application::GetWidth()
{
	long result;
	InvokeHelper(0x59, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetWidth(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x59, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Application::GetHeight()
{
	long result;
	InvokeHelper(0x5a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetHeight(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x5a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Application::GetWindowState()
{
	long result;
	InvokeHelper(0x5b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetWindowState(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x5b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _Application::GetDisplayAutoCompleteTips()
{
	BOOL result;
	InvokeHelper(0x5c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetDisplayAutoCompleteTips(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x5c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH _Application::GetOptions()
{
	LPDISPATCH result;
	InvokeHelper(0x5d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _Application::GetDisplayAlerts()
{
	long result;
	InvokeHelper(0x5e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetDisplayAlerts(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x5e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

LPDISPATCH _Application::GetCustomDictionaries()
{
	LPDISPATCH result;
	InvokeHelper(0x5f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _Application::GetPathSeparator()
{
	CString result;
	InvokeHelper(0x60, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Application::SetStatusBar(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x61, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL _Application::GetMAPIAvailable()
{
	BOOL result;
	InvokeHelper(0x62, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL _Application::GetDisplayScreenTips()
{
	BOOL result;
	InvokeHelper(0x63, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetDisplayScreenTips(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x63, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long _Application::GetEnableCancelKey()
{
	long result;
	InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetEnableCancelKey(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _Application::GetUserControl()
{
	BOOL result;
	InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetFileSearch()
{
	LPDISPATCH result;
	InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _Application::GetMailSystem()
{
	long result;
	InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CString _Application::GetDefaultTableSeparator()
{
	CString result;
	InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Application::SetDefaultTableSeparator(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x69, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL _Application::GetShowVisualBasicEditor()
{
	BOOL result;
	InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetShowVisualBasicEditor(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString _Application::GetBrowseExtraFileTypes()
{
	CString result;
	InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Application::SetBrowseExtraFileTypes(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL _Application::GetIsObjectValid(LPDISPATCH Object)
{
	BOOL result;
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms,
		Object);
	return result;
}

LPDISPATCH _Application::GetHangulHanjaDictionaries()
{
	LPDISPATCH result;
	InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetMailMessage()
{
	LPDISPATCH result;
	InvokeHelper(0x15c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _Application::GetFocusInMailHeader()
{
	BOOL result;
	InvokeHelper(0x182, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::Quit(VARIANT* SaveChanges, VARIANT* OriginalFormat, VARIANT* RouteDocument)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x451, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 SaveChanges, OriginalFormat, RouteDocument);
}

void _Application::ScreenRefresh()
{
	InvokeHelper(0x12d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Application::LookupNameProperties(LPCTSTR Name)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x12f, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Name);
}

void _Application::SubstituteFont(LPCTSTR UnavailableFont, LPCTSTR SubstituteFont)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR;
	InvokeHelper(0x130, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 UnavailableFont, SubstituteFont);
}

BOOL _Application::Repeat(VARIANT* Times)
{
	BOOL result;
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x131, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Times);
	return result;
}

void _Application::DDEExecute(long Channel, LPCTSTR Command)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x136, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Channel, Command);
}

long _Application::DDEInitiate(LPCTSTR App, LPCTSTR Topic)
{
	long result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR;
	InvokeHelper(0x137, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		App, Topic);
	return result;
}

void _Application::DDEPoke(long Channel, LPCTSTR Item, LPCTSTR Data)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR VTS_BSTR;
	InvokeHelper(0x138, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Channel, Item, Data);
}

CString _Application::DDERequest(long Channel, LPCTSTR Item)
{
	CString result;
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x139, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		Channel, Item);
	return result;
}

void _Application::DDETerminate(long Channel)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x13a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Channel);
}

void _Application::DDETerminateAll()
{
	InvokeHelper(0x13b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

long _Application::BuildKeyCode(long Arg1, VARIANT* Arg2, VARIANT* Arg3, VARIANT* Arg4)
{
	long result;
	static BYTE parms[] =
		VTS_I4 VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x13c, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Arg1, Arg2, Arg3, Arg4);
	return result;
}

CString _Application::KeyString(long KeyCode, VARIANT* KeyCode2)
{
	CString result;
	static BYTE parms[] =
		VTS_I4 VTS_PVARIANT;
	InvokeHelper(0x13d, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		KeyCode, KeyCode2);
	return result;
}

void _Application::OrganizerCopy(LPCTSTR Source, LPCTSTR Destination, LPCTSTR Name, long Object)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4;
	InvokeHelper(0x13e, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Source, Destination, Name, Object);
}

void _Application::OrganizerDelete(LPCTSTR Source, LPCTSTR Name, long Object)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_I4;
	InvokeHelper(0x13f, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Source, Name, Object);
}

void _Application::OrganizerRename(LPCTSTR Source, LPCTSTR Name, LPCTSTR NewName, long Object)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4;
	InvokeHelper(0x140, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Source, Name, NewName, Object);
}

CString _Application::GetAddress(VARIANT* Name, VARIANT* AddressProperties, VARIANT* UseAutoText, VARIANT* DisplaySelectDialog, VARIANT* SelectDialog, VARIANT* CheckNamesDialog, VARIANT* RecentAddressesChoice, VARIANT* UpdateRecentAddresses)
{
	CString result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x142, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		Name, AddressProperties, UseAutoText, DisplaySelectDialog, SelectDialog, CheckNamesDialog, RecentAddressesChoice, UpdateRecentAddresses);
	return result;
}

BOOL _Application::CheckGrammar(LPCTSTR String)
{
	BOOL result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x143, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		String);
	return result;
}

BOOL _Application::CheckSpelling(LPCTSTR Word, VARIANT* CustomDictionary, VARIANT* IgnoreUppercase, VARIANT* MainDictionary, VARIANT* CustomDictionary2, VARIANT* CustomDictionary3, VARIANT* CustomDictionary4, VARIANT* CustomDictionary5, 
		VARIANT* CustomDictionary6, VARIANT* CustomDictionary7, VARIANT* CustomDictionary8, VARIANT* CustomDictionary9, VARIANT* CustomDictionary10)
{
	BOOL result;
	static BYTE parms[] =
		VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x144, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Word, CustomDictionary, IgnoreUppercase, MainDictionary, CustomDictionary2, CustomDictionary3, CustomDictionary4, CustomDictionary5, CustomDictionary6, CustomDictionary7, CustomDictionary8, CustomDictionary9, CustomDictionary10);
	return result;
}

void _Application::ResetIgnoreAll()
{
	InvokeHelper(0x146, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH _Application::GetSpellingSuggestions(LPCTSTR Word, VARIANT* CustomDictionary, VARIANT* IgnoreUppercase, VARIANT* MainDictionary, VARIANT* SuggestionMode, VARIANT* CustomDictionary2, VARIANT* CustomDictionary3, VARIANT* CustomDictionary4, 
		VARIANT* CustomDictionary5, VARIANT* CustomDictionary6, VARIANT* CustomDictionary7, VARIANT* CustomDictionary8, VARIANT* CustomDictionary9, VARIANT* CustomDictionary10)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x147, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Word, CustomDictionary, IgnoreUppercase, MainDictionary, SuggestionMode, CustomDictionary2, CustomDictionary3, CustomDictionary4, CustomDictionary5, CustomDictionary6, CustomDictionary7, CustomDictionary8, CustomDictionary9, 
		CustomDictionary10);
	return result;
}

void _Application::GoBack()
{
	InvokeHelper(0x148, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Application::Help(VARIANT* HelpType)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x149, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 HelpType);
}

void _Application::AutomaticChange()
{
	InvokeHelper(0x14a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Application::ShowMe()
{
	InvokeHelper(0x14b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Application::HelpTool()
{
	InvokeHelper(0x14c, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH _Application::NewWindow()
{
	LPDISPATCH result;
	InvokeHelper(0x159, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _Application::ListCommands(BOOL ListAllCommands)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x15a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ListAllCommands);
}

void _Application::ShowClipboard()
{
	InvokeHelper(0x15d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Application::OnTime(VARIANT* When, LPCTSTR Name, VARIANT* Tolerance)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_BSTR VTS_PVARIANT;
	InvokeHelper(0x15e, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 When, Name, Tolerance);
}

void _Application::NextLetter()
{
	InvokeHelper(0x15f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

short _Application::MountVolume(LPCTSTR Zone, LPCTSTR Server, LPCTSTR Volume, VARIANT* User, VARIANT* UserPassword, VARIANT* VolumePassword)
{
	short result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x161, DISPATCH_METHOD, VT_I2, (void*)&result, parms,
		Zone, Server, Volume, User, UserPassword, VolumePassword);
	return result;
}

CString _Application::CleanString(LPCTSTR String)
{
	CString result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x162, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		String);
	return result;
}

void _Application::SendFax()
{
	InvokeHelper(0x164, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Application::ChangeFileOpenDirectory(LPCTSTR Path)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x165, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Path);
}

void _Application::GoForward()
{
	InvokeHelper(0x167, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Application::Move(long Left, long Top)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x168, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Left, Top);
}

void _Application::Resize(long Width, long Height)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x169, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Width, Height);
}

float _Application::InchesToPoints(float Inches)
{
	float result;
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x172, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
		Inches);
	return result;
}

float _Application::CentimetersToPoints(float Centimeters)
{
	float result;
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x173, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
		Centimeters);
	return result;
}

float _Application::MillimetersToPoints(float Millimeters)
{
	float result;
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x174, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
		Millimeters);
	return result;
}

float _Application::PicasToPoints(float Picas)
{
	float result;
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x175, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
		Picas);
	return result;
}

float _Application::LinesToPoints(float Lines)
{
	float result;
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x176, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
		Lines);
	return result;
}

float _Application::PointsToInches(float Points)
{
	float result;
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x17c, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
		Points);
	return result;
}

float _Application::PointsToCentimeters(float Points)
{
	float result;
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x17d, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
		Points);
	return result;
}

float _Application::PointsToMillimeters(float Points)
{
	float result;
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x17e, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
		Points);
	return result;
}

float _Application::PointsToPicas(float Points)
{
	float result;
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x17f, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
		Points);
	return result;
}

float _Application::PointsToLines(float Points)
{
	float result;
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x180, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
		Points);
	return result;
}

void _Application::Activate()
{
	InvokeHelper(0x181, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

float _Application::PointsToPixels(float Points, VARIANT* fVertical)
{
	float result;
	static BYTE parms[] =
		VTS_R4 VTS_PVARIANT;
	InvokeHelper(0x183, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
		Points, fVertical);
	return result;
}

float _Application::PixelsToPoints(float Pixels, VARIANT* fVertical)
{
	float result;
	static BYTE parms[] =
		VTS_R4 VTS_PVARIANT;
	InvokeHelper(0x184, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
		Pixels, fVertical);
	return result;
}

void _Application::KeyboardLatin()
{
	InvokeHelper(0x190, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Application::KeyboardBidi()
{
	InvokeHelper(0x191, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Application::ToggleKeyboard()
{
	InvokeHelper(0x192, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

long _Application::Keyboard(long LangId)
{
	long result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1be, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		LangId);
	return result;
}

CString _Application::ProductCode()
{
	CString result;
	InvokeHelper(0x194, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::DefaultWebOptions()
{
	LPDISPATCH result;
	InvokeHelper(0x195, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _Application::SetDefaultTheme(LPCTSTR Name, long DocumentType)
{
	static BYTE parms[] =
		VTS_BSTR VTS_I4;
	InvokeHelper(0x19e, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Name, DocumentType);
}

CString _Application::GetDefaultTheme(long DocumentType)
{
	CString result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1a0, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		DocumentType);
	return result;
}

LPDISPATCH _Application::GetEmailOptions()
{
	LPDISPATCH result;
	InvokeHelper(0x185, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _Application::GetLanguage()
{
	long result;
	InvokeHelper(0x187, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetCOMAddIns()
{
	LPDISPATCH result;
	InvokeHelper(0x6f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _Application::GetCheckLanguage()
{
	BOOL result;
	InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetCheckLanguage(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x70, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH _Application::GetLanguageSettings()
{
	LPDISPATCH result;
	InvokeHelper(0x193, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetAnswerWizard()
{
	LPDISPATCH result;
	InvokeHelper(0x199, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _Application::GetFeatureInstall()
{
	long result;
	InvokeHelper(0x1bf, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetFeatureInstall(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1bf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

void _Application::PrintOut(VARIANT* Background, VARIANT* Append, VARIANT* Range, VARIANT* OutputFileName, VARIANT* From, VARIANT* To, VARIANT* Item, VARIANT* Copies, VARIANT* Pages, VARIANT* PageType, VARIANT* PrintToFile, VARIANT* Collate, 
		VARIANT* FileName, VARIANT* ActivePrinterMacGX, VARIANT* ManualDuplexPrint, VARIANT* PrintZoomColumn, VARIANT* PrintZoomRow, VARIANT* PrintZoomPaperWidth, VARIANT* PrintZoomPaperHeight)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT 
		VTS_PVARIANT;
	InvokeHelper(0x1bc, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Background, Append, Range, OutputFileName, From, To, Item, Copies, Pages, PageType, PrintToFile, Collate, FileName, ActivePrinterMacGX, ManualDuplexPrint, PrintZoomColumn, PrintZoomRow, PrintZoomPaperWidth, PrintZoomPaperHeight);
}

VARIANT _Application::Run(LPCTSTR MacroName, VARIANT* varg1, VARIANT* varg2, VARIANT* varg3, VARIANT* varg4, VARIANT* varg5, VARIANT* varg6, VARIANT* varg7, VARIANT* varg8, VARIANT* varg9, VARIANT* varg10, VARIANT* varg11, VARIANT* varg12, VARIANT* varg13, 
		VARIANT* varg14, VARIANT* varg15, VARIANT* varg16, VARIANT* varg17, VARIANT* varg18, VARIANT* varg19, VARIANT* varg20, VARIANT* varg21, VARIANT* varg22, VARIANT* varg23, VARIANT* varg24, VARIANT* varg25, VARIANT* varg26, VARIANT* varg27, 
		VARIANT* varg28, VARIANT* varg29, VARIANT* varg30)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT 
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x1bd, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		MacroName, varg1, varg2, varg3, varg4, varg5, varg6, varg7, varg8, varg9, varg10, varg11, varg12, varg13, varg14, varg15, varg16, varg17, varg18, varg19, varg20, varg21, varg22, varg23, varg24, varg25, varg26, varg27, varg28, varg29, 
		varg30);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// Documents properties

/////////////////////////////////////////////////////////////////////////////
// Documents operations

LPUNKNOWN Documents::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

long Documents::GetCount()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Documents::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Documents::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Documents::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Documents::Item(VARIANT* Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}

void Documents::Close(VARIANT* SaveChanges, VARIANT* OriginalFormat, VARIANT* RouteDocument)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x451, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 SaveChanges, OriginalFormat, RouteDocument);
}

void Documents::Save(VARIANT* NoPrompt, VARIANT* OriginalFormat)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 NoPrompt, OriginalFormat);
}

LPDISPATCH Documents::Add(VARIANT* Template, VARIANT* NewTemplate, VARIANT* DocumentType, VARIANT* Visible)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0xe, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Template, NewTemplate, DocumentType, Visible);
	return result;
}

LPDISPATCH Documents::Open(VARIANT* FileName, VARIANT* ConfirmConversions, VARIANT* ReadOnly, VARIANT* AddToRecentFiles, VARIANT* PasswordDocument, VARIANT* PasswordTemplate, VARIANT* Revert, VARIANT* WritePasswordDocument, 
		VARIANT* WritePasswordTemplate, VARIANT* Format, VARIANT* Encoding, VARIANT* Visible)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0xf, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		FileName, ConfirmConversions, ReadOnly, AddToRecentFiles, PasswordDocument, PasswordTemplate, Revert, WritePasswordDocument, WritePasswordTemplate, Format, Encoding, Visible);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// _Document properties

/////////////////////////////////////////////////////////////////////////////
// _Document operations

CString _Document::GetName()
{
	CString result;
	InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _Document::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetBuiltInDocumentProperties()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetCustomDocumentProperties()
{
	LPDISPATCH result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _Document::GetPath()
{
	CString result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetBookmarks()
{
	LPDISPATCH result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetTables()
{
	LPDISPATCH result;
	InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetFootnotes()
{
	LPDISPATCH result;
	InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetEndnotes()
{
	LPDISPATCH result;
	InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetComments()
{
	LPDISPATCH result;
	InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _Document::GetType()
{
	long result;
	InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL _Document::GetAutoHyphenation()
{
	BOOL result;
	InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetAutoHyphenation(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Document::GetHyphenateCaps()
{
	BOOL result;
	InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetHyphenateCaps(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long _Document::GetHyphenationZone()
{
	long result;
	InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Document::SetHyphenationZone(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Document::GetConsecutiveHyphensLimit()
{
	long result;
	InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Document::SetConsecutiveHyphensLimit(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

LPDISPATCH _Document::GetSections()
{
	LPDISPATCH result;
	InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetParagraphs()
{
	LPDISPATCH result;
	InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetWords()
{
	LPDISPATCH result;
	InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetSentences()
{
	LPDISPATCH result;
	InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetCharacters()
{
	LPDISPATCH result;
	InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetFields()
{
	LPDISPATCH result;
	InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetFormFields()
{
	LPDISPATCH result;
	InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetStyles()
{
	LPDISPATCH result;
	InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetFrames()
{
	LPDISPATCH result;
	InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetTablesOfFigures()
{
	LPDISPATCH result;
	InvokeHelper(0x19, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetVariables()
{
	LPDISPATCH result;
	InvokeHelper(0x1a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetMailMerge()
{
	LPDISPATCH result;
	InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetEnvelope()
{
	LPDISPATCH result;
	InvokeHelper(0x1c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _Document::GetFullName()
{
	CString result;
	InvokeHelper(0x1d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetRevisions()
{
	LPDISPATCH result;
	InvokeHelper(0x1e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetTablesOfContents()
{
	LPDISPATCH result;
	InvokeHelper(0x1f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetTablesOfAuthorities()
{
	LPDISPATCH result;
	InvokeHelper(0x20, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetPageSetup()
{
	LPDISPATCH result;
	InvokeHelper(0x44d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _Document::SetPageSetup(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x44d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH _Document::GetWindows()
{
	LPDISPATCH result;
	InvokeHelper(0x22, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _Document::GetHasRoutingSlip()
{
	BOOL result;
	InvokeHelper(0x23, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetHasRoutingSlip(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x23, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH _Document::GetRoutingSlip()
{
	LPDISPATCH result;
	InvokeHelper(0x24, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _Document::GetRouted()
{
	BOOL result;
	InvokeHelper(0x25, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetTablesOfAuthoritiesCategories()
{
	LPDISPATCH result;
	InvokeHelper(0x26, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetIndexes()
{
	LPDISPATCH result;
	InvokeHelper(0x27, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _Document::GetSaved()
{
	BOOL result;
	InvokeHelper(0x28, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetSaved(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x28, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH _Document::GetContent()
{
	LPDISPATCH result;
	InvokeHelper(0x29, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetActiveWindow()
{
	LPDISPATCH result;
	InvokeHelper(0x2a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _Document::GetKind()
{
	long result;
	InvokeHelper(0x2b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Document::SetKind(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x2b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _Document::GetReadOnly()
{
	BOOL result;
	InvokeHelper(0x2c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetSubdocuments()
{
	LPDISPATCH result;
	InvokeHelper(0x2d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _Document::GetIsMasterDocument()
{
	BOOL result;
	InvokeHelper(0x2e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

float _Document::GetDefaultTabStop()
{
	float result;
	InvokeHelper(0x30, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void _Document::SetDefaultTabStop(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x30, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

BOOL _Document::GetEmbedTrueTypeFonts()
{
	BOOL result;
	InvokeHelper(0x32, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetEmbedTrueTypeFonts(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x32, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Document::GetSaveFormsData()
{
	BOOL result;
	InvokeHelper(0x33, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetSaveFormsData(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x33, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Document::GetReadOnlyRecommended()
{
	BOOL result;
	InvokeHelper(0x34, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetReadOnlyRecommended(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x34, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Document::GetSaveSubsetFonts()
{
	BOOL result;
	InvokeHelper(0x35, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetSaveSubsetFonts(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x35, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Document::GetCompatibility(long Type)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x37, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms,
		Type);
	return result;
}

void _Document::SetCompatibility(long Type, BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_I4 VTS_BOOL;
	InvokeHelper(0x37, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 Type, bNewValue);
}

LPDISPATCH _Document::GetStoryRanges()
{
	LPDISPATCH result;
	InvokeHelper(0x38, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetCommandBars()
{
	LPDISPATCH result;
	InvokeHelper(0x39, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _Document::GetIsSubdocument()
{
	BOOL result;
	InvokeHelper(0x3a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

long _Document::GetSaveFormat()
{
	long result;
	InvokeHelper(0x3b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _Document::GetProtectionType()
{
	long result;
	InvokeHelper(0x3c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetHyperlinks()
{
	LPDISPATCH result;
	InvokeHelper(0x3d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetShapes()
{
	LPDISPATCH result;
	InvokeHelper(0x3e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetListTemplates()
{
	LPDISPATCH result;
	InvokeHelper(0x3f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetLists()
{
	LPDISPATCH result;
	InvokeHelper(0x40, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _Document::GetUpdateStylesOnOpen()
{
	BOOL result;
	InvokeHelper(0x42, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetUpdateStylesOnOpen(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x42, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

VARIANT _Document::GetAttachedTemplate()
{
	VARIANT result;
	InvokeHelper(0x43, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
	return result;
}

void _Document::SetAttachedTemplate(VARIANT* newValue)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x43, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH _Document::GetInlineShapes()
{
	LPDISPATCH result;
	InvokeHelper(0x44, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetBackground()
{
	LPDISPATCH result;
	InvokeHelper(0x45, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _Document::SetBackground(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x45, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

BOOL _Document::GetGrammarChecked()
{
	BOOL result;
	InvokeHelper(0x46, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetGrammarChecked(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x46, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Document::GetSpellingChecked()
{
	BOOL result;
	InvokeHelper(0x47, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetSpellingChecked(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x47, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Document::GetShowGrammaticalErrors()
{
	BOOL result;
	InvokeHelper(0x48, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetShowGrammaticalErrors(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x48, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Document::GetShowSpellingErrors()
{
	BOOL result;
	InvokeHelper(0x49, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetShowSpellingErrors(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x49, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH _Document::GetVersions()
{
	LPDISPATCH result;
	InvokeHelper(0x4b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _Document::GetShowSummary()
{
	BOOL result;
	InvokeHelper(0x4c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetShowSummary(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x4c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long _Document::GetSummaryViewMode()
{
	long result;
	InvokeHelper(0x4d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Document::SetSummaryViewMode(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x4d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Document::GetSummaryLength()
{
	long result;
	InvokeHelper(0x4e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Document::SetSummaryLength(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x4e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _Document::GetPrintFractionalWidths()
{
	BOOL result;
	InvokeHelper(0x4f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetPrintFractionalWidths(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x4f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Document::GetPrintPostScriptOverText()
{
	BOOL result;
	InvokeHelper(0x50, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetPrintPostScriptOverText(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x50, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH _Document::GetContainer()
{
	LPDISPATCH result;
	InvokeHelper(0x52, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _Document::GetPrintFormsData()
{
	BOOL result;
	InvokeHelper(0x53, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetPrintFormsData(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x53, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH _Document::GetListParagraphs()
{
	LPDISPATCH result;
	InvokeHelper(0x54, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _Document::SetPassword(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x55, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

void _Document::SetWritePassword(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x56, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL _Document::GetHasPassword()
{
	BOOL result;
	InvokeHelper(0x57, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL _Document::GetWriteReserved()
{
	BOOL result;
	InvokeHelper(0x58, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

CString _Document::GetActiveWritingStyle(VARIANT* LanguageID)
{
	CString result;
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x5a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, parms,
		LanguageID);
	return result;
}

void _Document::SetActiveWritingStyle(VARIANT* LanguageID, LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_BSTR;
	InvokeHelper(0x5a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 LanguageID, lpszNewValue);
}

BOOL _Document::GetUserControl()
{
	BOOL result;
	InvokeHelper(0x5c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetUserControl(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x5c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Document::GetHasMailer()
{
	BOOL result;
	InvokeHelper(0x5d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetHasMailer(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x5d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH _Document::GetMailer()
{
	LPDISPATCH result;
	InvokeHelper(0x5e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetReadabilityStatistics()
{
	LPDISPATCH result;
	InvokeHelper(0x60, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetGrammaticalErrors()
{
	LPDISPATCH result;
	InvokeHelper(0x61, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetSpellingErrors()
{
	LPDISPATCH result;
	InvokeHelper(0x62, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetVBProject()
{
	LPDISPATCH result;
	InvokeHelper(0x63, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _Document::GetFormsDesign()
{
	BOOL result;
	InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

CString _Document::Get_CodeName()
{
	CString result;
	InvokeHelper(0x80010000, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Document::Set_CodeName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x80010000, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _Document::GetCodeName()
{
	CString result;
	InvokeHelper(0x106, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

BOOL _Document::GetSnapToGrid()
{
	BOOL result;
	InvokeHelper(0x12c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetSnapToGrid(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x12c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Document::GetSnapToShapes()
{
	BOOL result;
	InvokeHelper(0x12d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetSnapToShapes(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x12d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

float _Document::GetGridDistanceHorizontal()
{
	float result;
	InvokeHelper(0x12e, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void _Document::SetGridDistanceHorizontal(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x12e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float _Document::GetGridDistanceVertical()
{
	float result;
	InvokeHelper(0x12f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void _Document::SetGridDistanceVertical(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x12f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float _Document::GetGridOriginHorizontal()
{
	float result;
	InvokeHelper(0x130, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void _Document::SetGridOriginHorizontal(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x130, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float _Document::GetGridOriginVertical()
{
	float result;
	InvokeHelper(0x131, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void _Document::SetGridOriginVertical(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x131, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long _Document::GetGridSpaceBetweenHorizontalLines()
{
	long result;
	InvokeHelper(0x132, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Document::SetGridSpaceBetweenHorizontalLines(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x132, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Document::GetGridSpaceBetweenVerticalLines()
{
	long result;
	InvokeHelper(0x133, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Document::SetGridSpaceBetweenVerticalLines(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x133, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _Document::GetGridOriginFromMargin()
{
	BOOL result;
	InvokeHelper(0x134, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetGridOriginFromMargin(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x134, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Document::GetKerningByAlgorithm()
{
	BOOL result;
	InvokeHelper(0x135, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetKerningByAlgorithm(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x135, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long _Document::GetJustificationMode()
{
	long result;
	InvokeHelper(0x136, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Document::SetJustificationMode(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x136, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Document::GetFarEastLineBreakLevel()
{
	long result;
	InvokeHelper(0x137, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Document::SetFarEastLineBreakLevel(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x137, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString _Document::GetNoLineBreakBefore()
{
	CString result;
	InvokeHelper(0x138, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Document::SetNoLineBreakBefore(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x138, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _Document::GetNoLineBreakAfter()
{
	CString result;
	InvokeHelper(0x139, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Document::SetNoLineBreakAfter(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x139, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL _Document::GetTrackRevisions()
{
	BOOL result;
	InvokeHelper(0x13a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetTrackRevisions(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x13a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Document::GetPrintRevisions()
{
	BOOL result;
	InvokeHelper(0x13b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetPrintRevisions(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x13b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Document::GetShowRevisions()
{
	BOOL result;
	InvokeHelper(0x13c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetShowRevisions(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x13c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

void _Document::Close(VARIANT* SaveChanges, VARIANT* OriginalFormat, VARIANT* RouteDocument)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x451, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 SaveChanges, OriginalFormat, RouteDocument);
}

void _Document::SaveAs(VARIANT* FileName, VARIANT* FileFormat, VARIANT* LockComments, VARIANT* Password, VARIANT* AddToRecentFiles, VARIANT* WritePassword, VARIANT* ReadOnlyRecommended, VARIANT* EmbedTrueTypeFonts, VARIANT* SaveNativePictureFormat, 
		VARIANT* SaveFormsData, VARIANT* SaveAsAOCELetter)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 FileName, FileFormat, LockComments, Password, AddToRecentFiles, WritePassword, ReadOnlyRecommended, EmbedTrueTypeFonts, SaveNativePictureFormat, SaveFormsData, SaveAsAOCELetter);
}

void _Document::Repaginate()
{
	InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::FitToPages()
{
	InvokeHelper(0x68, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::ManualHyphenation()
{
	InvokeHelper(0x69, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::Select()
{
	InvokeHelper(0xffff, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::DataForm()
{
	InvokeHelper(0x6a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::Route()
{
	InvokeHelper(0x6b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::Save()
{
	InvokeHelper(0x6c, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::SendMail()
{
	InvokeHelper(0x6e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH _Document::Range(VARIANT* Start, VARIANT* End)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x7d0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Start, End);
	return result;
}

void _Document::RunAutoMacro(long Which)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x70, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Which);
}

void _Document::Activate()
{
	InvokeHelper(0x71, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::PrintPreview()
{
	InvokeHelper(0x72, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH _Document::GoTo(VARIANT* What, VARIANT* Which, VARIANT* Count, VARIANT* Name)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x73, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		What, Which, Count, Name);
	return result;
}

BOOL _Document::Undo(VARIANT* Times)
{
	BOOL result;
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x74, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Times);
	return result;
}

BOOL _Document::Redo(VARIANT* Times)
{
	BOOL result;
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x75, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Times);
	return result;
}

long _Document::ComputeStatistics(long Statistic, VARIANT* IncludeFootnotesAndEndnotes)
{
	long result;
	static BYTE parms[] =
		VTS_I4 VTS_PVARIANT;
	InvokeHelper(0x76, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Statistic, IncludeFootnotesAndEndnotes);
	return result;
}

void _Document::MakeCompatibilityDefault()
{
	InvokeHelper(0x77, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::Protect(long Type, VARIANT* NoReset, VARIANT* Password)
{
	static BYTE parms[] =
		VTS_I4 VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x78, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Type, NoReset, Password);
}

void _Document::Unprotect(VARIANT* Password)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x79, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Password);
}

void _Document::EditionOptions(long Type, long Option, LPCTSTR Name, VARIANT* Format)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_BSTR VTS_PVARIANT;
	InvokeHelper(0x7a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Type, Option, Name, Format);
}

void _Document::RunLetterWizard(VARIANT* LetterContent, VARIANT* WizardMode)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x7b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 LetterContent, WizardMode);
}

LPDISPATCH _Document::GetLetterContent()
{
	LPDISPATCH result;
	InvokeHelper(0x7c, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _Document::SetLetterContent(VARIANT* LetterContent)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x7d, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 LetterContent);
}

void _Document::CopyStylesFromTemplate(LPCTSTR Template)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x7e, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Template);
}

void _Document::UpdateStyles()
{
	InvokeHelper(0x7f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::CheckGrammar()
{
	InvokeHelper(0x83, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::CheckSpelling(VARIANT* CustomDictionary, VARIANT* IgnoreUppercase, VARIANT* AlwaysSuggest, VARIANT* CustomDictionary2, VARIANT* CustomDictionary3, VARIANT* CustomDictionary4, VARIANT* CustomDictionary5, VARIANT* CustomDictionary6, 
		VARIANT* CustomDictionary7, VARIANT* CustomDictionary8, VARIANT* CustomDictionary9, VARIANT* CustomDictionary10)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x84, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 CustomDictionary, IgnoreUppercase, AlwaysSuggest, CustomDictionary2, CustomDictionary3, CustomDictionary4, CustomDictionary5, CustomDictionary6, CustomDictionary7, CustomDictionary8, CustomDictionary9, CustomDictionary10);
}

void _Document::FollowHyperlink(VARIANT* Address, VARIANT* SubAddress, VARIANT* NewWindow, VARIANT* AddHistory, VARIANT* ExtraInfo, VARIANT* Method, VARIANT* HeaderInfo)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x87, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Address, SubAddress, NewWindow, AddHistory, ExtraInfo, Method, HeaderInfo);
}

void _Document::AddToFavorites()
{
	InvokeHelper(0x88, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::Reload()
{
	InvokeHelper(0x89, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH _Document::AutoSummarize(VARIANT* Length, VARIANT* Mode, VARIANT* UpdateProperties)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x8a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Length, Mode, UpdateProperties);
	return result;
}

void _Document::RemoveNumbers(VARIANT* NumberType)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x8c, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 NumberType);
}

void _Document::ConvertNumbersToText(VARIANT* NumberType)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x8d, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 NumberType);
}

long _Document::CountNumberedItems(VARIANT* NumberType, VARIANT* Level)
{
	long result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x8e, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		NumberType, Level);
	return result;
}

void _Document::Post()
{
	InvokeHelper(0x8f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::ToggleFormsDesign()
{
	InvokeHelper(0x90, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::Compare(LPCTSTR Name)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x91, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Name);
}

void _Document::UpdateSummaryProperties()
{
	InvokeHelper(0x92, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

VARIANT _Document::GetCrossReferenceItems(VARIANT* ReferenceType)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x93, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		ReferenceType);
	return result;
}

void _Document::AutoFormat()
{
	InvokeHelper(0x94, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::ViewCode()
{
	InvokeHelper(0x95, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::ViewPropertyBrowser()
{
	InvokeHelper(0x96, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::ForwardMailer()
{
	InvokeHelper(0xfa, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::Reply()
{
	InvokeHelper(0xfb, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::ReplyAll()
{
	InvokeHelper(0xfc, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::SendMailer(VARIANT* FileFormat, VARIANT* Priority)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0xfd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 FileFormat, Priority);
}

void _Document::UndoClear()
{
	InvokeHelper(0xfe, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::PresentIt()
{
	InvokeHelper(0xff, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::SendFax(LPCTSTR Address, VARIANT* Subject)
{
	static BYTE parms[] =
		VTS_BSTR VTS_PVARIANT;
	InvokeHelper(0x100, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Address, Subject);
}

void _Document::Merge(LPCTSTR FileName)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x101, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 FileName);
}

void _Document::ClosePrintPreview()
{
	InvokeHelper(0x102, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::CheckConsistency()
{
	InvokeHelper(0x103, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH _Document::CreateLetterContent(LPCTSTR DateFormat, BOOL IncludeHeaderFooter, LPCTSTR PageDesign, long LetterStyle, BOOL Letterhead, long LetterheadLocation, float LetterheadSize, LPCTSTR RecipientName, LPCTSTR RecipientAddress, 
		LPCTSTR Salutation, long SalutationType, LPCTSTR RecipientReference, LPCTSTR MailingInstructions, LPCTSTR AttentionLine, LPCTSTR Subject, LPCTSTR CCList, LPCTSTR ReturnAddress, LPCTSTR SenderName, LPCTSTR Closing, LPCTSTR SenderCompany, 
		LPCTSTR SenderJobTitle, LPCTSTR SenderInitials, long EnclosureNumber, VARIANT* InfoBlock, VARIANT* RecipientCode, VARIANT* RecipientGender, VARIANT* ReturnAddressShortForm, VARIANT* SenderCity, VARIANT* SenderCode, VARIANT* SenderGender, 
		VARIANT* SenderReference)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR VTS_BOOL VTS_BSTR VTS_I4 VTS_BOOL VTS_I4 VTS_R4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT 
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x104, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		DateFormat, IncludeHeaderFooter, PageDesign, LetterStyle, Letterhead, LetterheadLocation, LetterheadSize, RecipientName, RecipientAddress, Salutation, SalutationType, RecipientReference, MailingInstructions, AttentionLine, Subject, 
		CCList, ReturnAddress, SenderName, Closing, SenderCompany, SenderJobTitle, SenderInitials, EnclosureNumber, InfoBlock, RecipientCode, RecipientGender, ReturnAddressShortForm, SenderCity, SenderCode, SenderGender, SenderReference);
	return result;
}

void _Document::AcceptAllRevisions()
{
	InvokeHelper(0x13d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::RejectAllRevisions()
{
	InvokeHelper(0x13e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::DetectLanguage()
{
	InvokeHelper(0x97, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::ApplyTheme(LPCTSTR Name)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x142, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Name);
}

void _Document::RemoveTheme()
{
	InvokeHelper(0x143, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::WebPagePreview()
{
	InvokeHelper(0x145, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Document::ReloadAs(long Encoding)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x14b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Encoding);
}

CString _Document::GetActiveTheme()
{
	CString result;
	InvokeHelper(0x21c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _Document::GetActiveThemeDisplayName()
{
	CString result;
	InvokeHelper(0x21d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetEmail()
{
	LPDISPATCH result;
	InvokeHelper(0x13f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetScripts()
{
	LPDISPATCH result;
	InvokeHelper(0x140, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _Document::GetLanguageDetected()
{
	BOOL result;
	InvokeHelper(0x141, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetLanguageDetected(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x141, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long _Document::GetFarEastLineBreakLanguage()
{
	long result;
	InvokeHelper(0x146, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Document::SetFarEastLineBreakLanguage(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x146, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

LPDISPATCH _Document::GetFrameset()
{
	LPDISPATCH result;
	InvokeHelper(0x147, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

VARIANT _Document::GetClickAndTypeParagraphStyle()
{
	VARIANT result;
	InvokeHelper(0x148, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
	return result;
}

void _Document::SetClickAndTypeParagraphStyle(VARIANT* newValue)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x148, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH _Document::GetHTMLProject()
{
	LPDISPATCH result;
	InvokeHelper(0x149, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Document::GetWebOptions()
{
	LPDISPATCH result;
	InvokeHelper(0x14a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _Document::GetOpenEncoding()
{
	long result;
	InvokeHelper(0x14c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _Document::GetSaveEncoding()
{
	long result;
	InvokeHelper(0x14d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Document::SetSaveEncoding(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x14d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _Document::GetOptimizeForWord97()
{
	BOOL result;
	InvokeHelper(0x14e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::SetOptimizeForWord97(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x14e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Document::GetVBASigned()
{
	BOOL result;
	InvokeHelper(0x14f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Document::PrintOut(VARIANT* Background, VARIANT* Append, VARIANT* Range, VARIANT* OutputFileName, VARIANT* From, VARIANT* To, VARIANT* Item, VARIANT* Copies, VARIANT* Pages, VARIANT* PageType, VARIANT* PrintToFile, VARIANT* Collate, 
		VARIANT* ActivePrinterMacGX, VARIANT* ManualDuplexPrint, VARIANT* PrintZoomColumn, VARIANT* PrintZoomRow, VARIANT* PrintZoomPaperWidth, VARIANT* PrintZoomPaperHeight)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x1bc, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Background, Append, Range, OutputFileName, From, To, Item, Copies, Pages, PageType, PrintToFile, Collate, ActivePrinterMacGX, ManualDuplexPrint, PrintZoomColumn, PrintZoomRow, PrintZoomPaperWidth, PrintZoomPaperHeight);
}


/////////////////////////////////////////////////////////////////////////////
// Template properties

/////////////////////////////////////////////////////////////////////////////
// Template operations

CString Template::GetName()
{
	CString result;
	InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH Template::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Template::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Template::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString Template::GetPath()
{
	CString result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH Template::GetAutoTextEntries()
{
	LPDISPATCH result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Template::GetLanguageID()
{
	long result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Template::SetLanguageID(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL Template::GetSaved()
{
	BOOL result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Template::SetSaved(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long Template::GetType()
{
	long result;
	InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CString Template::GetFullName()
{
	CString result;
	InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH Template::GetBuiltInDocumentProperties()
{
	LPDISPATCH result;
	InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Template::GetCustomDocumentProperties()
{
	LPDISPATCH result;
	InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Template::GetListTemplates()
{
	LPDISPATCH result;
	InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Template::GetLanguageIDFarEast()
{
	long result;
	InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Template::SetLanguageIDFarEast(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

LPDISPATCH Template::GetVBProject()
{
	LPDISPATCH result;
	InvokeHelper(0x63, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL Template::GetKerningByAlgorithm()
{
	BOOL result;
	InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Template::SetKerningByAlgorithm(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long Template::GetJustificationMode()
{
	long result;
	InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Template::SetJustificationMode(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Template::GetFarEastLineBreakLevel()
{
	long result;
	InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Template::SetFarEastLineBreakLevel(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString Template::GetNoLineBreakBefore()
{
	CString result;
	InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void Template::SetNoLineBreakBefore(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString Template::GetNoLineBreakAfter()
{
	CString result;
	InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void Template::SetNoLineBreakAfter(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

LPDISPATCH Template::OpenAsDocument()
{
	LPDISPATCH result;
	InvokeHelper(0x64, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void Template::Save()
{
	InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

long Template::GetNoProofing()
{
	long result;
	InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Template::SetNoProofing(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x11, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Template::GetFarEastLineBreakLanguage()
{
	long result;
	InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Template::SetFarEastLineBreakLanguage(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x12, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}


/////////////////////////////////////////////////////////////////////////////
// Templates properties

/////////////////////////////////////////////////////////////////////////////
// Templates operations

LPDISPATCH Templates::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Templates::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Templates::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Templates::GetCount()
{
	long result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPUNKNOWN Templates::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

LPDISPATCH Templates::Item(VARIANT* Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// Bookmark properties

/////////////////////////////////////////////////////////////////////////////
// Bookmark operations

CString Bookmark::GetName()
{
	CString result;
	InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH Bookmark::GetRange()
{
	LPDISPATCH result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL Bookmark::GetEmpty()
{
	BOOL result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

long Bookmark::GetStart()
{
	long result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Bookmark::SetStart(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Bookmark::GetEnd()
{
	long result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Bookmark::SetEnd(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL Bookmark::GetColumn()
{
	BOOL result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

long Bookmark::GetStoryType()
{
	long result;
	InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Bookmark::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Bookmark::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Bookmark::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void Bookmark::Select()
{
	InvokeHelper(0xffff, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Bookmark::Delete()
{
	InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH Bookmark::Copy(LPCTSTR Name)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xc, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Name);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// Bookmarks properties

/////////////////////////////////////////////////////////////////////////////
// Bookmarks operations

LPUNKNOWN Bookmarks::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

long Bookmarks::GetCount()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long Bookmarks::GetDefaultSorting()
{
	long result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Bookmarks::SetDefaultSorting(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL Bookmarks::GetShowHidden()
{
	BOOL result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Bookmarks::SetShowHidden(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH Bookmarks::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Bookmarks::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Bookmarks::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Bookmarks::Item(VARIANT* Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}

LPDISPATCH Bookmarks::Add(LPCTSTR Name, VARIANT* Range)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR VTS_PVARIANT;
	InvokeHelper(0x5, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Name, Range);
	return result;
}

BOOL Bookmarks::Exists(LPCTSTR Name)
{
	BOOL result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Name);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// Variable properties

/////////////////////////////////////////////////////////////////////////////
// Variable operations

LPDISPATCH Variable::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Variable::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Variable::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString Variable::GetName()
{
	CString result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString Variable::GetValue()
{
	CString result;
	InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void Variable::SetValue(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long Variable::GetIndex()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Variable::Delete()
{
	InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// Variables properties

/////////////////////////////////////////////////////////////////////////////
// Variables operations

LPUNKNOWN Variables::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

long Variables::GetCount()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Variables::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Variables::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Variables::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Variables::Item(VARIANT* Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}

LPDISPATCH Variables::Add(LPCTSTR Name, VARIANT* Value)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR VTS_PVARIANT;
	InvokeHelper(0x7, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Name, Value);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// Window properties

/////////////////////////////////////////////////////////////////////////////
// Window operations

LPDISPATCH Window::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Window::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Window::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Window::GetActivePane()
{
	LPDISPATCH result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Window::GetDocument()
{
	LPDISPATCH result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Window::GetPanes()
{
	LPDISPATCH result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Window::GetSelection()
{
	LPDISPATCH result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Window::GetLeft()
{
	long result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Window::SetLeft(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Window::GetTop()
{
	long result;
	InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Window::SetTop(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Window::GetWidth()
{
	long result;
	InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Window::SetWidth(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Window::GetHeight()
{
	long result;
	InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Window::SetHeight(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL Window::GetSplit()
{
	BOOL result;
	InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Window::SetSplit(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long Window::GetSplitVertical()
{
	long result;
	InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Window::SetSplitVertical(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString Window::GetCaption()
{
	CString result;
	InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void Window::SetCaption(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long Window::GetWindowState()
{
	long result;
	InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Window::SetWindowState(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL Window::GetDisplayRulers()
{
	BOOL result;
	InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Window::SetDisplayRulers(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL Window::GetDisplayVerticalRuler()
{
	BOOL result;
	InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Window::SetDisplayVerticalRuler(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH Window::GetView()
{
	LPDISPATCH result;
	InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Window::GetType()
{
	long result;
	InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Window::GetNext()
{
	LPDISPATCH result;
	InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Window::GetPrevious()
{
	LPDISPATCH result;
	InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Window::GetWindowNumber()
{
	long result;
	InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL Window::GetDisplayVerticalScrollBar()
{
	BOOL result;
	InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Window::SetDisplayVerticalScrollBar(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x13, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL Window::GetDisplayHorizontalScrollBar()
{
	BOOL result;
	InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Window::SetDisplayHorizontalScrollBar(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x14, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

float Window::GetStyleAreaWidth()
{
	float result;
	InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Window::SetStyleAreaWidth(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x15, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

BOOL Window::GetDisplayScreenTips()
{
	BOOL result;
	InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Window::SetDisplayScreenTips(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x16, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long Window::GetHorizontalPercentScrolled()
{
	long result;
	InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Window::SetHorizontalPercentScrolled(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x17, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Window::GetVerticalPercentScrolled()
{
	long result;
	InvokeHelper(0x18, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Window::SetVerticalPercentScrolled(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x18, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL Window::GetDocumentMap()
{
	BOOL result;
	InvokeHelper(0x19, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Window::SetDocumentMap(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x19, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL Window::GetActive()
{
	BOOL result;
	InvokeHelper(0x1a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

long Window::GetDocumentMapPercentWidth()
{
	long result;
	InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Window::SetDocumentMapPercentWidth(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Window::GetIndex()
{
	long result;
	InvokeHelper(0x1c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long Window::GetIMEMode()
{
	long result;
	InvokeHelper(0x1e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Window::SetIMEMode(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

void Window::Activate()
{
	InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Window::Close(VARIANT* SaveChanges, VARIANT* RouteDocument)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 SaveChanges, RouteDocument);
}

void Window::LargeScroll(VARIANT* Down, VARIANT* Up, VARIANT* ToRight, VARIANT* ToLeft)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Down, Up, ToRight, ToLeft);
}

void Window::SmallScroll(VARIANT* Down, VARIANT* Up, VARIANT* ToRight, VARIANT* ToLeft)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x68, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Down, Up, ToRight, ToLeft);
}

LPDISPATCH Window::NewWindow()
{
	LPDISPATCH result;
	InvokeHelper(0x69, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void Window::PageScroll(VARIANT* Down, VARIANT* Up)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x6c, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Down, Up);
}

void Window::SetFocus()
{
	InvokeHelper(0x6d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH Window::RangeFromPoint(long x, long y)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x6e, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		x, y);
	return result;
}

void Window::ScrollIntoView(LPDISPATCH obj, VARIANT* Start)
{
	static BYTE parms[] =
		VTS_DISPATCH VTS_PVARIANT;
	InvokeHelper(0x6f, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 obj, Start);
}

void Window::GetPoint(long* ScreenPixelsLeft, long* ScreenPixelsTop, long* ScreenPixelsWidth, long* ScreenPixelsHeight, LPDISPATCH obj)
{
	static BYTE parms[] =
		VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_DISPATCH;
	InvokeHelper(0x70, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ScreenPixelsLeft, ScreenPixelsTop, ScreenPixelsWidth, ScreenPixelsHeight, obj);
}

void Window::PrintOut(VARIANT* Background, VARIANT* Append, VARIANT* Range, VARIANT* OutputFileName, VARIANT* From, VARIANT* To, VARIANT* Item, VARIANT* Copies, VARIANT* Pages, VARIANT* PageType, VARIANT* PrintToFile, VARIANT* Collate, 
		VARIANT* ActivePrinterMacGX, VARIANT* ManualDuplexPrint, VARIANT* PrintZoomColumn, VARIANT* PrintZoomRow, VARIANT* PrintZoomPaperWidth, VARIANT* PrintZoomPaperHeight)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x1bc, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Background, Append, Range, OutputFileName, From, To, Item, Copies, Pages, PageType, PrintToFile, Collate, ActivePrinterMacGX, ManualDuplexPrint, PrintZoomColumn, PrintZoomRow, PrintZoomPaperWidth, PrintZoomPaperHeight);
}

long Window::GetUsableWidth()
{
	long result;
	InvokeHelper(0x1f, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long Window::GetUsableHeight()
{
	long result;
	InvokeHelper(0x20, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL Window::GetEnvelopeVisible()
{
	BOOL result;
	InvokeHelper(0x21, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Window::SetEnvelopeVisible(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x21, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL Window::GetDisplayRightRuler()
{
	BOOL result;
	InvokeHelper(0x23, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Window::SetDisplayRightRuler(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x23, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL Window::GetDisplayLeftScrollBar()
{
	BOOL result;
	InvokeHelper(0x22, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Window::SetDisplayLeftScrollBar(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x22, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL Window::GetVisible()
{
	BOOL result;
	InvokeHelper(0x24, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Window::SetVisible(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x24, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}


/////////////////////////////////////////////////////////////////////////////
// Windows properties

/////////////////////////////////////////////////////////////////////////////
// Windows operations

LPUNKNOWN Windows::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

long Windows::GetCount()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Windows::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Windows::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Windows::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Windows::Item(VARIANT* Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}

LPDISPATCH Windows::Add(VARIANT* Window)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0xa, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Window);
	return result;
}

void Windows::Arrange(VARIANT* ArrangeStyle)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ArrangeStyle);
}


/////////////////////////////////////////////////////////////////////////////
// Pane properties

/////////////////////////////////////////////////////////////////////////////
// Pane operations

LPDISPATCH Pane::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Pane::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Pane::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Pane::GetDocument()
{
	LPDISPATCH result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Pane::GetSelection()
{
	LPDISPATCH result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL Pane::GetDisplayRulers()
{
	BOOL result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Pane::SetDisplayRulers(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL Pane::GetDisplayVerticalRuler()
{
	BOOL result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Pane::SetDisplayVerticalRuler(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH Pane::GetZooms()
{
	LPDISPATCH result;
	InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Pane::GetIndex()
{
	long result;
	InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Pane::GetView()
{
	LPDISPATCH result;
	InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Pane::GetNext()
{
	LPDISPATCH result;
	InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Pane::GetPrevious()
{
	LPDISPATCH result;
	InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Pane::GetHorizontalPercentScrolled()
{
	long result;
	InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Pane::SetHorizontalPercentScrolled(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Pane::GetVerticalPercentScrolled()
{
	long result;
	InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Pane::SetVerticalPercentScrolled(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Pane::GetMinimumFontSize()
{
	long result;
	InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Pane::SetMinimumFontSize(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Pane::GetBrowseWidth()
{
	long result;
	InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Pane::Activate()
{
	InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Pane::Close()
{
	InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Pane::LargeScroll(VARIANT* Down, VARIANT* Up, VARIANT* ToRight, VARIANT* ToLeft)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Down, Up, ToRight, ToLeft);
}

void Pane::SmallScroll(VARIANT* Down, VARIANT* Up, VARIANT* ToRight, VARIANT* ToLeft)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Down, Up, ToRight, ToLeft);
}

void Pane::AutoScroll(long Velocity)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x68, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Velocity);
}

void Pane::PageScroll(VARIANT* Down, VARIANT* Up)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x69, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Down, Up);
}

void Pane::NewFrameset()
{
	InvokeHelper(0x6a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Pane::TOCInFrameset()
{
	InvokeHelper(0x6b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH Pane::GetFrameset()
{
	LPDISPATCH result;
	InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// Panes properties

/////////////////////////////////////////////////////////////////////////////
// Panes operations

LPUNKNOWN Panes::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

long Panes::GetCount()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Panes::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Panes::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Panes::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Panes::Item(long Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}

LPDISPATCH Panes::Add(VARIANT* SplitVertical)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x3, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		SplitVertical);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// Range properties

/////////////////////////////////////////////////////////////////////////////
// Range operations

CString Range::GetText()
{
	CString result;
	InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void Range::SetText(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

LPDISPATCH Range::GetFormattedText()
{
	LPDISPATCH result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void Range::SetFormattedText(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long Range::GetStart()
{
	long result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Range::SetStart(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Range::GetEnd()
{
	long result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Range::SetEnd(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

LPDISPATCH Range::GetFont()
{
	LPDISPATCH result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void Range::SetFont(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH Range::GetDuplicate()
{
	LPDISPATCH result;
	InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Range::GetStoryType()
{
	long result;
	InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetTables()
{
	LPDISPATCH result;
	InvokeHelper(0x32, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetWords()
{
	LPDISPATCH result;
	InvokeHelper(0x33, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetSentences()
{
	LPDISPATCH result;
	InvokeHelper(0x34, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetCharacters()
{
	LPDISPATCH result;
	InvokeHelper(0x35, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetFootnotes()
{
	LPDISPATCH result;
	InvokeHelper(0x36, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetEndnotes()
{
	LPDISPATCH result;
	InvokeHelper(0x37, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetComments()
{
	LPDISPATCH result;
	InvokeHelper(0x38, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetCells()
{
	LPDISPATCH result;
	InvokeHelper(0x39, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetSections()
{
	LPDISPATCH result;
	InvokeHelper(0x3a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetParagraphs()
{
	LPDISPATCH result;
	InvokeHelper(0x3b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetBorders()
{
	LPDISPATCH result;
	InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void Range::SetBorders(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH Range::GetShading()
{
	LPDISPATCH result;
	InvokeHelper(0x3d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetTextRetrievalMode()
{
	LPDISPATCH result;
	InvokeHelper(0x3e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void Range::SetTextRetrievalMode(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x3e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH Range::GetFields()
{
	LPDISPATCH result;
	InvokeHelper(0x40, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetFormFields()
{
	LPDISPATCH result;
	InvokeHelper(0x41, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetFrames()
{
	LPDISPATCH result;
	InvokeHelper(0x42, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetParagraphFormat()
{
	LPDISPATCH result;
	InvokeHelper(0x44e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void Range::SetParagraphFormat(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x44e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH Range::GetListFormat()
{
	LPDISPATCH result;
	InvokeHelper(0x44, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetBookmarks()
{
	LPDISPATCH result;
	InvokeHelper(0x4b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Range::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Range::GetBold()
{
	long result;
	InvokeHelper(0x82, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Range::SetBold(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x82, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Range::GetItalic()
{
	long result;
	InvokeHelper(0x83, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Range::SetItalic(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x83, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Range::GetUnderline()
{
	long result;
	InvokeHelper(0x8b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Range::SetUnderline(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Range::GetEmphasisMark()
{
	long result;
	InvokeHelper(0x8c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Range::SetEmphasisMark(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL Range::GetDisableCharacterSpaceGrid()
{
	BOOL result;
	InvokeHelper(0x8d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Range::SetDisableCharacterSpaceGrid(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x8d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH Range::GetRevisions()
{
	LPDISPATCH result;
	InvokeHelper(0x96, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

VARIANT Range::GetStyle()
{
	VARIANT result;
	InvokeHelper(0x97, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
	return result;
}

void Range::SetStyle(VARIANT* newValue)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x97, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long Range::GetStoryLength()
{
	long result;
	InvokeHelper(0x98, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long Range::GetLanguageID()
{
	long result;
	InvokeHelper(0x99, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Range::SetLanguageID(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x99, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

LPDISPATCH Range::GetSynonymInfo()
{
	LPDISPATCH result;
	InvokeHelper(0x9b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetHyperlinks()
{
	LPDISPATCH result;
	InvokeHelper(0x9c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetListParagraphs()
{
	LPDISPATCH result;
	InvokeHelper(0x9d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetSubdocuments()
{
	LPDISPATCH result;
	InvokeHelper(0x9f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL Range::GetGrammarChecked()
{
	BOOL result;
	InvokeHelper(0x104, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Range::SetGrammarChecked(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x104, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL Range::GetSpellingChecked()
{
	BOOL result;
	InvokeHelper(0x105, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Range::SetSpellingChecked(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x105, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long Range::GetHighlightColorIndex()
{
	long result;
	InvokeHelper(0x12d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Range::SetHighlightColorIndex(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x12d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

LPDISPATCH Range::GetColumns()
{
	LPDISPATCH result;
	InvokeHelper(0x12e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetRows()
{
	LPDISPATCH result;
	InvokeHelper(0x12f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL Range::GetIsEndOfRowMark()
{
	BOOL result;
	InvokeHelper(0x133, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

long Range::GetBookmarkID()
{
	long result;
	InvokeHelper(0x134, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long Range::GetPreviousBookmarkID()
{
	long result;
	InvokeHelper(0x135, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetFind()
{
	LPDISPATCH result;
	InvokeHelper(0x106, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetPageSetup()
{
	LPDISPATCH result;
	InvokeHelper(0x44d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void Range::SetPageSetup(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x44d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH Range::GetShapeRange()
{
	LPDISPATCH result;
	InvokeHelper(0x137, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Range::GetCase()
{
	long result;
	InvokeHelper(0x138, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Range::SetCase(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x138, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

VARIANT Range::GetInformation(long Type)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x139, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, parms,
		Type);
	return result;
}

LPDISPATCH Range::GetReadabilityStatistics()
{
	LPDISPATCH result;
	InvokeHelper(0x13a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetGrammaticalErrors()
{
	LPDISPATCH result;
	InvokeHelper(0x13b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetSpellingErrors()
{
	LPDISPATCH result;
	InvokeHelper(0x13c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Range::GetOrientation()
{
	long result;
	InvokeHelper(0x13d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Range::SetOrientation(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x13d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

LPDISPATCH Range::GetInlineShapes()
{
	LPDISPATCH result;
	InvokeHelper(0x13f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetNextStoryRange()
{
	LPDISPATCH result;
	InvokeHelper(0x140, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Range::GetLanguageIDFarEast()
{
	long result;
	InvokeHelper(0x141, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Range::SetLanguageIDFarEast(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x141, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Range::GetLanguageIDOther()
{
	long result;
	InvokeHelper(0x142, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Range::SetLanguageIDOther(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x142, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

void Range::Select()
{
	InvokeHelper(0xffff, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Range::SetRange(long Start, long End)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Start, End);
}

void Range::Collapse(VARIANT* Direction)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Direction);
}

void Range::InsertBefore(LPCTSTR Text)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Text);
}

void Range::InsertAfter(LPCTSTR Text)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Text);
}

LPDISPATCH Range::Next(VARIANT* Unit, VARIANT* Count)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x69, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Unit, Count);
	return result;
}

LPDISPATCH Range::Previous(VARIANT* Unit, VARIANT* Count)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x6a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Unit, Count);
	return result;
}

long Range::StartOf(VARIANT* Unit, VARIANT* Extend)
{
	long result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x6b, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Unit, Extend);
	return result;
}

long Range::EndOf(VARIANT* Unit, VARIANT* Extend)
{
	long result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x6c, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Unit, Extend);
	return result;
}

long Range::Move(VARIANT* Unit, VARIANT* Count)
{
	long result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x6d, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Unit, Count);
	return result;
}

long Range::MoveStart(VARIANT* Unit, VARIANT* Count)
{
	long result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x6e, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Unit, Count);
	return result;
}

long Range::MoveEnd(VARIANT* Unit, VARIANT* Count)
{
	long result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x6f, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Unit, Count);
	return result;
}

long Range::MoveWhile(VARIANT* Cset, VARIANT* Count)
{
	long result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x70, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Cset, Count);
	return result;
}

long Range::MoveStartWhile(VARIANT* Cset, VARIANT* Count)
{
	long result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x71, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Cset, Count);
	return result;
}

long Range::MoveEndWhile(VARIANT* Cset, VARIANT* Count)
{
	long result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x72, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Cset, Count);
	return result;
}

long Range::MoveUntil(VARIANT* Cset, VARIANT* Count)
{
	long result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x73, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Cset, Count);
	return result;
}

long Range::MoveStartUntil(VARIANT* Cset, VARIANT* Count)
{
	long result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x74, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Cset, Count);
	return result;
}

long Range::MoveEndUntil(VARIANT* Cset, VARIANT* Count)
{
	long result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x75, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Cset, Count);
	return result;
}

void Range::Cut()
{
	InvokeHelper(0x77, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Range::Copy()
{
	InvokeHelper(0x78, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Range::Paste()
{
	InvokeHelper(0x79, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Range::InsertBreak(VARIANT* Type)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x7a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Type);
}

void Range::InsertFile(LPCTSTR FileName, VARIANT* Range, VARIANT* ConfirmConversions, VARIANT* Link, VARIANT* Attachment)
{
	static BYTE parms[] =
		VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x7b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 FileName, Range, ConfirmConversions, Link, Attachment);
}

BOOL Range::InStory(LPDISPATCH Range)
{
	BOOL result;
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x7d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Range);
	return result;
}

BOOL Range::InRange(LPDISPATCH Range)
{
	BOOL result;
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x7e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Range);
	return result;
}

long Range::Delete(VARIANT* Unit, VARIANT* Count)
{
	long result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x7f, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Unit, Count);
	return result;
}

void Range::WholeStory()
{
	InvokeHelper(0x80, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

long Range::Expand(VARIANT* Unit)
{
	long result;
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x81, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Unit);
	return result;
}

void Range::InsertParagraph()
{
	InvokeHelper(0xa0, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Range::InsertParagraphAfter()
{
	InvokeHelper(0xa1, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Range::InsertSymbol(long CharacterNumber, VARIANT* Font, VARIANT* Unicode, VARIANT* Bias)
{
	static BYTE parms[] =
		VTS_I4 VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0xa4, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 CharacterNumber, Font, Unicode, Bias);
}

void Range::InsertCrossReference(VARIANT* ReferenceType, long ReferenceKind, VARIANT* ReferenceItem, VARIANT* InsertAsHyperlink, VARIANT* IncludePosition)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_I4 VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0xa5, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ReferenceType, ReferenceKind, ReferenceItem, InsertAsHyperlink, IncludePosition);
}

void Range::InsertCaption(VARIANT* Label, VARIANT* Title, VARIANT* TitleAutoText, VARIANT* Position)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0xa6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Label, Title, TitleAutoText, Position);
}

void Range::CopyAsPicture()
{
	InvokeHelper(0xa7, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Range::SortAscending()
{
	InvokeHelper(0xa9, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Range::SortDescending()
{
	InvokeHelper(0xaa, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

BOOL Range::IsEqual(LPDISPATCH Range)
{
	BOOL result;
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0xab, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Range);
	return result;
}

float Range::Calculate()
{
	float result;
	InvokeHelper(0xac, DISPATCH_METHOD, VT_R4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GoTo(VARIANT* What, VARIANT* Which, VARIANT* Count, VARIANT* Name)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0xad, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		What, Which, Count, Name);
	return result;
}

LPDISPATCH Range::GoToNext(long What)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xae, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		What);
	return result;
}

LPDISPATCH Range::GoToPrevious(long What)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xaf, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		What);
	return result;
}

void Range::PasteSpecial(VARIANT* IconIndex, VARIANT* Link, VARIANT* Placement, VARIANT* DisplayAsIcon, VARIANT* DataType, VARIANT* IconFileName, VARIANT* IconLabel)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0xb0, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 IconIndex, Link, Placement, DisplayAsIcon, DataType, IconFileName, IconLabel);
}

void Range::LookupNameProperties()
{
	InvokeHelper(0xb1, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

long Range::ComputeStatistics(long Statistic)
{
	long result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xb2, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Statistic);
	return result;
}

void Range::Relocate(long Direction)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xb3, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Direction);
}

void Range::CheckSynonyms()
{
	InvokeHelper(0xb4, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Range::SubscribeTo(LPCTSTR Edition, VARIANT* Format)
{
	static BYTE parms[] =
		VTS_BSTR VTS_PVARIANT;
	InvokeHelper(0xb5, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Edition, Format);
}

void Range::CreatePublisher(VARIANT* Edition, VARIANT* ContainsPICT, VARIANT* ContainsRTF, VARIANT* ContainsText)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0xb6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Edition, ContainsPICT, ContainsRTF, ContainsText);
}

void Range::InsertAutoText()
{
	InvokeHelper(0xb7, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Range::InsertDatabase(VARIANT* Format, VARIANT* Style, VARIANT* LinkToSource, VARIANT* Connection, VARIANT* SQLStatement, VARIANT* SQLStatement1, VARIANT* PasswordDocument, VARIANT* PasswordTemplate, VARIANT* WritePasswordDocument, 
		VARIANT* WritePasswordTemplate, VARIANT* DataSource, VARIANT* From, VARIANT* To, VARIANT* IncludeFields)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0xc2, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Format, Style, LinkToSource, Connection, SQLStatement, SQLStatement1, PasswordDocument, PasswordTemplate, WritePasswordDocument, WritePasswordTemplate, DataSource, From, To, IncludeFields);
}

void Range::AutoFormat()
{
	InvokeHelper(0xc3, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Range::CheckGrammar()
{
	InvokeHelper(0xcc, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Range::CheckSpelling(VARIANT* CustomDictionary, VARIANT* IgnoreUppercase, VARIANT* AlwaysSuggest, VARIANT* CustomDictionary2, VARIANT* CustomDictionary3, VARIANT* CustomDictionary4, VARIANT* CustomDictionary5, VARIANT* CustomDictionary6, 
		VARIANT* CustomDictionary7, VARIANT* CustomDictionary8, VARIANT* CustomDictionary9, VARIANT* CustomDictionary10)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0xcd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 CustomDictionary, IgnoreUppercase, AlwaysSuggest, CustomDictionary2, CustomDictionary3, CustomDictionary4, CustomDictionary5, CustomDictionary6, CustomDictionary7, CustomDictionary8, CustomDictionary9, CustomDictionary10);
}

LPDISPATCH Range::GetSpellingSuggestions(VARIANT* CustomDictionary, VARIANT* IgnoreUppercase, VARIANT* MainDictionary, VARIANT* SuggestionMode, VARIANT* CustomDictionary2, VARIANT* CustomDictionary3, VARIANT* CustomDictionary4, 
		VARIANT* CustomDictionary5, VARIANT* CustomDictionary6, VARIANT* CustomDictionary7, VARIANT* CustomDictionary8, VARIANT* CustomDictionary9, VARIANT* CustomDictionary10)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0xd1, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		CustomDictionary, IgnoreUppercase, MainDictionary, SuggestionMode, CustomDictionary2, CustomDictionary3, CustomDictionary4, CustomDictionary5, CustomDictionary6, CustomDictionary7, CustomDictionary8, CustomDictionary9, CustomDictionary10);
	return result;
}

void Range::InsertParagraphBefore()
{
	InvokeHelper(0xd4, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Range::NextSubdocument()
{
	InvokeHelper(0xdb, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Range::PreviousSubdocument()
{
	InvokeHelper(0xdc, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Range::ConvertHangulAndHanja(VARIANT* ConversionsMode, VARIANT* FastConversion, VARIANT* CheckHangulEnding, VARIANT* EnableRecentOrdering, VARIANT* CustomDictionary)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0xdd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ConversionsMode, FastConversion, CheckHangulEnding, EnableRecentOrdering, CustomDictionary);
}

void Range::PasteAsNestedTable()
{
	InvokeHelper(0xde, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Range::ModifyEnclosure(VARIANT* Style, VARIANT* Symbol, VARIANT* EnclosedText)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0xdf, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Style, Symbol, EnclosedText);
}

void Range::PhoneticGuide(LPCTSTR Text, long Alignment, long Raise, long FontSize, LPCTSTR FontName)
{
	static BYTE parms[] =
		VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_BSTR;
	InvokeHelper(0xe0, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Text, Alignment, Raise, FontSize, FontName);
}

void Range::InsertDateTime(VARIANT* DateTimeFormat, VARIANT* InsertAsField, VARIANT* InsertAsFullWidth, VARIANT* DateLanguage, VARIANT* CalendarType)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x1bc, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 DateTimeFormat, InsertAsField, InsertAsFullWidth, DateLanguage, CalendarType);
}

void Range::Sort(VARIANT* ExcludeHeader, VARIANT* FieldNumber, VARIANT* SortFieldType, VARIANT* SortOrder, VARIANT* FieldNumber2, VARIANT* SortFieldType2, VARIANT* SortOrder2, VARIANT* FieldNumber3, VARIANT* SortFieldType3, VARIANT* SortOrder3, 
		VARIANT* SortColumn, VARIANT* Separator, VARIANT* CaseSensitive, VARIANT* BidiSort, VARIANT* IgnoreThe, VARIANT* IgnoreKashida, VARIANT* IgnoreDiacritics, VARIANT* IgnoreHe, VARIANT* LanguageID)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT 
		VTS_PVARIANT;
	InvokeHelper(0x1e4, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ExcludeHeader, FieldNumber, SortFieldType, SortOrder, FieldNumber2, SortFieldType2, SortOrder2, FieldNumber3, SortFieldType3, SortOrder3, SortColumn, Separator, CaseSensitive, BidiSort, IgnoreThe, IgnoreKashida, IgnoreDiacritics, 
		IgnoreHe, LanguageID);
}

void Range::DetectLanguage()
{
	InvokeHelper(0xcb, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH Range::ConvertToTable(VARIANT* Separator, VARIANT* NumRows, VARIANT* NumColumns, VARIANT* InitialColumnWidth, VARIANT* Format, VARIANT* ApplyBorders, VARIANT* ApplyShading, VARIANT* ApplyFont, VARIANT* ApplyColor, 
		VARIANT* ApplyHeadingRows, VARIANT* ApplyLastRow, VARIANT* ApplyFirstColumn, VARIANT* ApplyLastColumn, VARIANT* AutoFit, VARIANT* AutoFitBehavior, VARIANT* DefaultTableBehavior)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x1f2, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Separator, NumRows, NumColumns, InitialColumnWidth, Format, ApplyBorders, ApplyShading, ApplyFont, ApplyColor, ApplyHeadingRows, ApplyLastRow, ApplyFirstColumn, ApplyLastColumn, AutoFit, AutoFitBehavior, DefaultTableBehavior);
	return result;
}

void Range::TCSCConverter(long WdTCSCConverterDirection, BOOL CommonTerms, BOOL UseVariants)
{
	static BYTE parms[] =
		VTS_I4 VTS_BOOL VTS_BOOL;
	InvokeHelper(0x1f3, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 WdTCSCConverterDirection, CommonTerms, UseVariants);
}

BOOL Range::GetLanguageDetected()
{
	BOOL result;
	InvokeHelper(0x107, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Range::SetLanguageDetected(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x107, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

float Range::GetFitTextWidth()
{
	float result;
	InvokeHelper(0x108, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Range::SetFitTextWidth(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x108, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long Range::GetHorizontalInVertical()
{
	long result;
	InvokeHelper(0x109, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Range::SetHorizontalInVertical(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x109, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Range::GetTwoLinesInOne()
{
	long result;
	InvokeHelper(0x10a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Range::SetTwoLinesInOne(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x10a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL Range::GetCombineCharacters()
{
	BOOL result;
	InvokeHelper(0x10b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Range::SetCombineCharacters(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x10b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long Range::GetNoProofing()
{
	long result;
	InvokeHelper(0x143, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Range::SetNoProofing(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x143, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

LPDISPATCH Range::GetTopLevelTables()
{
	LPDISPATCH result;
	InvokeHelper(0x144, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Range::GetScripts()
{
	LPDISPATCH result;
	InvokeHelper(0x145, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Range::GetCharacterWidth()
{
	long result;
	InvokeHelper(0x146, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Range::SetCharacterWidth(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x146, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Range::GetKana()
{
	long result;
	InvokeHelper(0x147, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Range::SetKana(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x147, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Range::GetBoldBi()
{
	long result;
	InvokeHelper(0x190, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Range::SetBoldBi(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x190, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Range::GetItalicBi()
{
	long result;
	InvokeHelper(0x191, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Range::SetItalicBi(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x191, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString Range::GetId()
{
	CString result;
	InvokeHelper(0x195, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void Range::SetId(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x195, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}


/////////////////////////////////////////////////////////////////////////////
// ListFormat properties

/////////////////////////////////////////////////////////////////////////////
// ListFormat operations

long ListFormat::GetListLevelNumber()
{
	long result;
	InvokeHelper(0x44, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void ListFormat::SetListLevelNumber(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x44, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

LPDISPATCH ListFormat::GetList()
{
	LPDISPATCH result;
	InvokeHelper(0x45, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH ListFormat::GetListTemplate()
{
	LPDISPATCH result;
	InvokeHelper(0x46, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long ListFormat::GetListValue()
{
	long result;
	InvokeHelper(0x47, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL ListFormat::GetSingleList()
{
	BOOL result;
	InvokeHelper(0x48, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL ListFormat::GetSingleListTemplate()
{
	BOOL result;
	InvokeHelper(0x49, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

long ListFormat::GetListType()
{
	long result;
	InvokeHelper(0x4a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CString ListFormat::GetListString()
{
	CString result;
	InvokeHelper(0x4b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH ListFormat::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long ListFormat::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH ListFormat::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long ListFormat::CanContinuePreviousList(LPDISPATCH ListTemplate)
{
	long result;
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0xb8, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		ListTemplate);
	return result;
}

void ListFormat::RemoveNumbers(VARIANT* NumberType)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0xb9, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 NumberType);
}

void ListFormat::ConvertNumbersToText(VARIANT* NumberType)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0xba, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 NumberType);
}

long ListFormat::CountNumberedItems(VARIANT* NumberType, VARIANT* Level)
{
	long result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0xbb, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		NumberType, Level);
	return result;
}

void ListFormat::ListOutdent()
{
	InvokeHelper(0xd2, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void ListFormat::ListIndent()
{
	InvokeHelper(0xd3, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void ListFormat::ApplyBulletDefault(VARIANT* DefaultListBehavior)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0xd4, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 DefaultListBehavior);
}

void ListFormat::ApplyNumberDefault(VARIANT* DefaultListBehavior)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0xd5, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 DefaultListBehavior);
}

void ListFormat::ApplyOutlineNumberDefault(VARIANT* DefaultListBehavior)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0xd6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 DefaultListBehavior);
}

void ListFormat::ApplyListTemplate(LPDISPATCH ListTemplate, VARIANT* ContinuePreviousList, VARIANT* ApplyTo, VARIANT* DefaultListBehavior)
{
	static BYTE parms[] =
		VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0xd7, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ListTemplate, ContinuePreviousList, ApplyTo, DefaultListBehavior);
}


/////////////////////////////////////////////////////////////////////////////
// Characters properties

/////////////////////////////////////////////////////////////////////////////
// Characters operations

LPUNKNOWN Characters::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

long Characters::GetCount()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Characters::GetFirst()
{
	LPDISPATCH result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Characters::GetLast()
{
	LPDISPATCH result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Characters::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Characters::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Characters::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Characters::Item(long Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// Words properties

/////////////////////////////////////////////////////////////////////////////
// Words operations

LPUNKNOWN Words::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

long Words::GetCount()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Words::GetFirst()
{
	LPDISPATCH result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Words::GetLast()
{
	LPDISPATCH result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Words::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Words::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Words::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Words::Item(long Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// Sections properties

/////////////////////////////////////////////////////////////////////////////
// Sections operations

LPUNKNOWN Sections::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

long Sections::GetCount()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Sections::GetFirst()
{
	LPDISPATCH result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Sections::GetLast()
{
	LPDISPATCH result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Sections::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Sections::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Sections::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Sections::GetPageSetup()
{
	LPDISPATCH result;
	InvokeHelper(0x44d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void Sections::SetPageSetup(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x44d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH Sections::Item(long Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}

LPDISPATCH Sections::Add(VARIANT* Range, VARIANT* Start)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x5, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Range, Start);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// Section properties

/////////////////////////////////////////////////////////////////////////////
// Section operations

LPDISPATCH Section::GetRange()
{
	LPDISPATCH result;
	InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Section::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Section::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Section::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Section::GetPageSetup()
{
	LPDISPATCH result;
	InvokeHelper(0x44d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void Section::SetPageSetup(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x44d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH Section::GetHeaders()
{
	LPDISPATCH result;
	InvokeHelper(0x79, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Section::GetFooters()
{
	LPDISPATCH result;
	InvokeHelper(0x7a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL Section::GetProtectedForForms()
{
	BOOL result;
	InvokeHelper(0x7b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Section::SetProtectedForForms(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x7b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long Section::GetIndex()
{
	long result;
	InvokeHelper(0x7c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Section::GetBorders()
{
	LPDISPATCH result;
	InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void Section::SetBorders(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}


/////////////////////////////////////////////////////////////////////////////
// Paragraphs properties

/////////////////////////////////////////////////////////////////////////////
// Paragraphs operations

LPUNKNOWN Paragraphs::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

long Paragraphs::GetCount()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Paragraphs::GetFirst()
{
	LPDISPATCH result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Paragraphs::GetLast()
{
	LPDISPATCH result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Paragraphs::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Paragraphs::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Paragraphs::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Paragraphs::GetFormat()
{
	LPDISPATCH result;
	InvokeHelper(0x44e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetFormat(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x44e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH Paragraphs::GetTabStops()
{
	LPDISPATCH result;
	InvokeHelper(0x44f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetTabStops(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x44f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH Paragraphs::GetBorders()
{
	LPDISPATCH result;
	InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetBorders(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

VARIANT Paragraphs::GetStyle()
{
	VARIANT result;
	InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetStyle(VARIANT* newValue)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long Paragraphs::GetAlignment()
{
	long result;
	InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetAlignment(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraphs::GetKeepTogether()
{
	long result;
	InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetKeepTogether(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraphs::GetKeepWithNext()
{
	long result;
	InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetKeepWithNext(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraphs::GetPageBreakBefore()
{
	long result;
	InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetPageBreakBefore(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraphs::GetNoLineNumber()
{
	long result;
	InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetNoLineNumber(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x69, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

float Paragraphs::GetRightIndent()
{
	float result;
	InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetRightIndent(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float Paragraphs::GetLeftIndent()
{
	float result;
	InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetLeftIndent(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x6b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float Paragraphs::GetFirstLineIndent()
{
	float result;
	InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetFirstLineIndent(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x6c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float Paragraphs::GetLineSpacing()
{
	float result;
	InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetLineSpacing(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x6d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long Paragraphs::GetLineSpacingRule()
{
	long result;
	InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetLineSpacingRule(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

float Paragraphs::GetSpaceBefore()
{
	float result;
	InvokeHelper(0x6f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetSpaceBefore(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x6f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float Paragraphs::GetSpaceAfter()
{
	float result;
	InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetSpaceAfter(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x70, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long Paragraphs::GetHyphenation()
{
	long result;
	InvokeHelper(0x71, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetHyphenation(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x71, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraphs::GetWidowControl()
{
	long result;
	InvokeHelper(0x72, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetWidowControl(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x72, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

LPDISPATCH Paragraphs::GetShading()
{
	LPDISPATCH result;
	InvokeHelper(0x74, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Paragraphs::GetFarEastLineBreakControl()
{
	long result;
	InvokeHelper(0x75, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetFarEastLineBreakControl(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x75, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraphs::GetWordWrap()
{
	long result;
	InvokeHelper(0x76, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetWordWrap(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x76, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraphs::GetHangingPunctuation()
{
	long result;
	InvokeHelper(0x77, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetHangingPunctuation(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x77, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraphs::GetHalfWidthPunctuationOnTopOfLine()
{
	long result;
	InvokeHelper(0x78, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetHalfWidthPunctuationOnTopOfLine(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x78, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraphs::GetAddSpaceBetweenFarEastAndAlpha()
{
	long result;
	InvokeHelper(0x79, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetAddSpaceBetweenFarEastAndAlpha(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x79, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraphs::GetAddSpaceBetweenFarEastAndDigit()
{
	long result;
	InvokeHelper(0x7a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetAddSpaceBetweenFarEastAndDigit(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraphs::GetBaseLineAlignment()
{
	long result;
	InvokeHelper(0x7b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetBaseLineAlignment(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraphs::GetAutoAdjustRightIndent()
{
	long result;
	InvokeHelper(0x7c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetAutoAdjustRightIndent(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraphs::GetDisableLineHeightGrid()
{
	long result;
	InvokeHelper(0x7d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetDisableLineHeightGrid(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraphs::GetOutlineLevel()
{
	long result;
	InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetOutlineLevel(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xca, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

LPDISPATCH Paragraphs::Item(long Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}

LPDISPATCH Paragraphs::Add(VARIANT* Range)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x5, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Range);
	return result;
}

void Paragraphs::CloseUp()
{
	InvokeHelper(0x12d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Paragraphs::OpenUp()
{
	InvokeHelper(0x12e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Paragraphs::OpenOrCloseUp()
{
	InvokeHelper(0x12f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Paragraphs::TabHangingIndent(short Count)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x130, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Count);
}

void Paragraphs::TabIndent(short Count)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x132, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Count);
}

void Paragraphs::Reset()
{
	InvokeHelper(0x138, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Paragraphs::Space1()
{
	InvokeHelper(0x139, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Paragraphs::Space15()
{
	InvokeHelper(0x13a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Paragraphs::Space2()
{
	InvokeHelper(0x13b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Paragraphs::IndentCharWidth(short Count)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x140, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Count);
}

void Paragraphs::IndentFirstLineCharWidth(short Count)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x142, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Count);
}

void Paragraphs::OutlinePromote()
{
	InvokeHelper(0x144, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Paragraphs::OutlineDemote()
{
	InvokeHelper(0x145, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Paragraphs::OutlineDemoteToBody()
{
	InvokeHelper(0x146, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Paragraphs::Indent()
{
	InvokeHelper(0x14d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Paragraphs::Outdent()
{
	InvokeHelper(0x14e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

float Paragraphs::GetCharacterUnitRightIndent()
{
	float result;
	InvokeHelper(0x7e, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetCharacterUnitRightIndent(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x7e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float Paragraphs::GetCharacterUnitLeftIndent()
{
	float result;
	InvokeHelper(0x7f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetCharacterUnitLeftIndent(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x7f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float Paragraphs::GetCharacterUnitFirstLineIndent()
{
	float result;
	InvokeHelper(0x80, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetCharacterUnitFirstLineIndent(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x80, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float Paragraphs::GetLineUnitBefore()
{
	float result;
	InvokeHelper(0x81, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetLineUnitBefore(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x81, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float Paragraphs::GetLineUnitAfter()
{
	float result;
	InvokeHelper(0x82, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetLineUnitAfter(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x82, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long Paragraphs::GetReadingOrder()
{
	long result;
	InvokeHelper(0x83, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetReadingOrder(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x83, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraphs::GetSpaceBeforeAuto()
{
	long result;
	InvokeHelper(0x84, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetSpaceBeforeAuto(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x84, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraphs::GetSpaceAfterAuto()
{
	long result;
	InvokeHelper(0x85, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraphs::SetSpaceAfterAuto(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x85, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}


/////////////////////////////////////////////////////////////////////////////
// Paragraph properties

/////////////////////////////////////////////////////////////////////////////
// Paragraph operations

LPDISPATCH Paragraph::GetRange()
{
	LPDISPATCH result;
	InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Paragraph::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Paragraph::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Paragraph::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Paragraph::GetFormat()
{
	LPDISPATCH result;
	InvokeHelper(0x44e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void Paragraph::SetFormat(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x44e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH Paragraph::GetTabStops()
{
	LPDISPATCH result;
	InvokeHelper(0x44f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void Paragraph::SetTabStops(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x44f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH Paragraph::GetBorders()
{
	LPDISPATCH result;
	InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void Paragraph::SetBorders(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH Paragraph::GetDropCap()
{
	LPDISPATCH result;
	InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

VARIANT Paragraph::GetStyle()
{
	VARIANT result;
	InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
	return result;
}

void Paragraph::SetStyle(VARIANT* newValue)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long Paragraph::GetAlignment()
{
	long result;
	InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetAlignment(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraph::GetKeepTogether()
{
	long result;
	InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetKeepTogether(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraph::GetKeepWithNext()
{
	long result;
	InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetKeepWithNext(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraph::GetPageBreakBefore()
{
	long result;
	InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetPageBreakBefore(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraph::GetNoLineNumber()
{
	long result;
	InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetNoLineNumber(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x69, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

float Paragraph::GetRightIndent()
{
	float result;
	InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetRightIndent(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float Paragraph::GetLeftIndent()
{
	float result;
	InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetLeftIndent(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x6b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float Paragraph::GetFirstLineIndent()
{
	float result;
	InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetFirstLineIndent(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x6c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float Paragraph::GetLineSpacing()
{
	float result;
	InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetLineSpacing(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x6d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long Paragraph::GetLineSpacingRule()
{
	long result;
	InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetLineSpacingRule(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

float Paragraph::GetSpaceBefore()
{
	float result;
	InvokeHelper(0x6f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetSpaceBefore(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x6f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float Paragraph::GetSpaceAfter()
{
	float result;
	InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetSpaceAfter(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x70, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long Paragraph::GetHyphenation()
{
	long result;
	InvokeHelper(0x71, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetHyphenation(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x71, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraph::GetWidowControl()
{
	long result;
	InvokeHelper(0x72, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetWidowControl(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x72, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

LPDISPATCH Paragraph::GetShading()
{
	LPDISPATCH result;
	InvokeHelper(0x74, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Paragraph::GetFarEastLineBreakControl()
{
	long result;
	InvokeHelper(0x75, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetFarEastLineBreakControl(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x75, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraph::GetWordWrap()
{
	long result;
	InvokeHelper(0x76, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetWordWrap(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x76, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraph::GetHangingPunctuation()
{
	long result;
	InvokeHelper(0x77, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetHangingPunctuation(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x77, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraph::GetHalfWidthPunctuationOnTopOfLine()
{
	long result;
	InvokeHelper(0x78, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetHalfWidthPunctuationOnTopOfLine(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x78, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraph::GetAddSpaceBetweenFarEastAndAlpha()
{
	long result;
	InvokeHelper(0x79, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetAddSpaceBetweenFarEastAndAlpha(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x79, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraph::GetAddSpaceBetweenFarEastAndDigit()
{
	long result;
	InvokeHelper(0x7a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetAddSpaceBetweenFarEastAndDigit(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraph::GetBaseLineAlignment()
{
	long result;
	InvokeHelper(0x7b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetBaseLineAlignment(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraph::GetAutoAdjustRightIndent()
{
	long result;
	InvokeHelper(0x7c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetAutoAdjustRightIndent(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraph::GetDisableLineHeightGrid()
{
	long result;
	InvokeHelper(0x7d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetDisableLineHeightGrid(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraph::GetOutlineLevel()
{
	long result;
	InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetOutlineLevel(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xca, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

void Paragraph::CloseUp()
{
	InvokeHelper(0x12d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Paragraph::OpenUp()
{
	InvokeHelper(0x12e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Paragraph::OpenOrCloseUp()
{
	InvokeHelper(0x12f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Paragraph::TabHangingIndent(short Count)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x130, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Count);
}

void Paragraph::TabIndent(short Count)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x132, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Count);
}

void Paragraph::Reset()
{
	InvokeHelper(0x138, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Paragraph::Space1()
{
	InvokeHelper(0x139, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Paragraph::Space15()
{
	InvokeHelper(0x13a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Paragraph::Space2()
{
	InvokeHelper(0x13b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Paragraph::IndentCharWidth(short Count)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x140, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Count);
}

void Paragraph::IndentFirstLineCharWidth(short Count)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x142, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Count);
}

LPDISPATCH Paragraph::Next(VARIANT* Count)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x144, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Count);
	return result;
}

LPDISPATCH Paragraph::Previous(VARIANT* Count)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x145, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Count);
	return result;
}

void Paragraph::OutlinePromote()
{
	InvokeHelper(0x146, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Paragraph::OutlineDemote()
{
	InvokeHelper(0x147, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Paragraph::OutlineDemoteToBody()
{
	InvokeHelper(0x148, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Paragraph::Indent()
{
	InvokeHelper(0x14d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Paragraph::Outdent()
{
	InvokeHelper(0x14e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

float Paragraph::GetCharacterUnitRightIndent()
{
	float result;
	InvokeHelper(0x7e, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetCharacterUnitRightIndent(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x7e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float Paragraph::GetCharacterUnitLeftIndent()
{
	float result;
	InvokeHelper(0x7f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetCharacterUnitLeftIndent(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x7f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float Paragraph::GetCharacterUnitFirstLineIndent()
{
	float result;
	InvokeHelper(0x80, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetCharacterUnitFirstLineIndent(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x80, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float Paragraph::GetLineUnitBefore()
{
	float result;
	InvokeHelper(0x81, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetLineUnitBefore(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x81, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float Paragraph::GetLineUnitAfter()
{
	float result;
	InvokeHelper(0x82, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetLineUnitAfter(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x82, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long Paragraph::GetReadingOrder()
{
	long result;
	InvokeHelper(0xcb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetReadingOrder(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xcb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString Paragraph::GetId()
{
	CString result;
	InvokeHelper(0xcc, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void Paragraph::SetId(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xcc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long Paragraph::GetSpaceBeforeAuto()
{
	long result;
	InvokeHelper(0x84, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetSpaceBeforeAuto(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x84, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Paragraph::GetSpaceAfterAuto()
{
	long result;
	InvokeHelper(0x85, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Paragraph::SetSpaceAfterAuto(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x85, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}


/////////////////////////////////////////////////////////////////////////////
// _ParagraphFormat properties

/////////////////////////////////////////////////////////////////////////////
// _ParagraphFormat operations

LPDISPATCH _ParagraphFormat::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _ParagraphFormat::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _ParagraphFormat::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _ParagraphFormat::GetDuplicate()
{
	LPDISPATCH result;
	InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

VARIANT _ParagraphFormat::GetStyle()
{
	VARIANT result;
	InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetStyle(VARIANT* newValue)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long _ParagraphFormat::GetAlignment()
{
	long result;
	InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetAlignment(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _ParagraphFormat::GetKeepTogether()
{
	long result;
	InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetKeepTogether(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _ParagraphFormat::GetKeepWithNext()
{
	long result;
	InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetKeepWithNext(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _ParagraphFormat::GetPageBreakBefore()
{
	long result;
	InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetPageBreakBefore(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _ParagraphFormat::GetNoLineNumber()
{
	long result;
	InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetNoLineNumber(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x69, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

float _ParagraphFormat::GetRightIndent()
{
	float result;
	InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetRightIndent(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float _ParagraphFormat::GetLeftIndent()
{
	float result;
	InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetLeftIndent(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x6b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float _ParagraphFormat::GetFirstLineIndent()
{
	float result;
	InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetFirstLineIndent(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x6c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float _ParagraphFormat::GetLineSpacing()
{
	float result;
	InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetLineSpacing(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x6d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long _ParagraphFormat::GetLineSpacingRule()
{
	long result;
	InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetLineSpacingRule(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

float _ParagraphFormat::GetSpaceBefore()
{
	float result;
	InvokeHelper(0x6f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetSpaceBefore(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x6f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float _ParagraphFormat::GetSpaceAfter()
{
	float result;
	InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetSpaceAfter(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x70, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long _ParagraphFormat::GetHyphenation()
{
	long result;
	InvokeHelper(0x71, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetHyphenation(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x71, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _ParagraphFormat::GetWidowControl()
{
	long result;
	InvokeHelper(0x72, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetWidowControl(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x72, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _ParagraphFormat::GetFarEastLineBreakControl()
{
	long result;
	InvokeHelper(0x75, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetFarEastLineBreakControl(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x75, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _ParagraphFormat::GetWordWrap()
{
	long result;
	InvokeHelper(0x76, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetWordWrap(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x76, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _ParagraphFormat::GetHangingPunctuation()
{
	long result;
	InvokeHelper(0x77, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetHangingPunctuation(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x77, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _ParagraphFormat::GetHalfWidthPunctuationOnTopOfLine()
{
	long result;
	InvokeHelper(0x78, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetHalfWidthPunctuationOnTopOfLine(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x78, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _ParagraphFormat::GetAddSpaceBetweenFarEastAndAlpha()
{
	long result;
	InvokeHelper(0x79, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetAddSpaceBetweenFarEastAndAlpha(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x79, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _ParagraphFormat::GetAddSpaceBetweenFarEastAndDigit()
{
	long result;
	InvokeHelper(0x7a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetAddSpaceBetweenFarEastAndDigit(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _ParagraphFormat::GetBaseLineAlignment()
{
	long result;
	InvokeHelper(0x7b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetBaseLineAlignment(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _ParagraphFormat::GetAutoAdjustRightIndent()
{
	long result;
	InvokeHelper(0x7c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetAutoAdjustRightIndent(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _ParagraphFormat::GetDisableLineHeightGrid()
{
	long result;
	InvokeHelper(0x7d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetDisableLineHeightGrid(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

LPDISPATCH _ParagraphFormat::GetTabStops()
{
	LPDISPATCH result;
	InvokeHelper(0x44f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetTabStops(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x44f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH _ParagraphFormat::GetBorders()
{
	LPDISPATCH result;
	InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetBorders(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH _ParagraphFormat::GetShading()
{
	LPDISPATCH result;
	InvokeHelper(0x44d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _ParagraphFormat::GetOutlineLevel()
{
	long result;
	InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetOutlineLevel(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xca, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

void _ParagraphFormat::CloseUp()
{
	InvokeHelper(0x12d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _ParagraphFormat::OpenUp()
{
	InvokeHelper(0x12e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _ParagraphFormat::OpenOrCloseUp()
{
	InvokeHelper(0x12f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _ParagraphFormat::TabHangingIndent(short Count)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x130, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Count);
}

void _ParagraphFormat::TabIndent(short Count)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x132, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Count);
}

void _ParagraphFormat::Reset()
{
	InvokeHelper(0x138, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _ParagraphFormat::Space1()
{
	InvokeHelper(0x139, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _ParagraphFormat::Space15()
{
	InvokeHelper(0x13a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _ParagraphFormat::Space2()
{
	InvokeHelper(0x13b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _ParagraphFormat::IndentCharWidth(short Count)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x140, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Count);
}

void _ParagraphFormat::IndentFirstLineCharWidth(short Count)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x142, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Count);
}

float _ParagraphFormat::GetCharacterUnitRightIndent()
{
	float result;
	InvokeHelper(0x7e, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetCharacterUnitRightIndent(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x7e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float _ParagraphFormat::GetCharacterUnitLeftIndent()
{
	float result;
	InvokeHelper(0x7f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetCharacterUnitLeftIndent(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x7f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float _ParagraphFormat::GetCharacterUnitFirstLineIndent()
{
	float result;
	InvokeHelper(0x80, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetCharacterUnitFirstLineIndent(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x80, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float _ParagraphFormat::GetLineUnitBefore()
{
	float result;
	InvokeHelper(0x81, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetLineUnitBefore(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x81, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float _ParagraphFormat::GetLineUnitAfter()
{
	float result;
	InvokeHelper(0x82, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetLineUnitAfter(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x82, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long _ParagraphFormat::GetReadingOrder()
{
	long result;
	InvokeHelper(0x83, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetReadingOrder(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x83, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _ParagraphFormat::GetSpaceBeforeAuto()
{
	long result;
	InvokeHelper(0x84, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetSpaceBeforeAuto(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x84, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _ParagraphFormat::GetSpaceAfterAuto()
{
	long result;
	InvokeHelper(0x85, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ParagraphFormat::SetSpaceAfterAuto(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x85, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}


/////////////////////////////////////////////////////////////////////////////
// _Font properties

/////////////////////////////////////////////////////////////////////////////
// _Font operations

LPDISPATCH _Font::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _Font::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Font::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Font::GetDuplicate()
{
	LPDISPATCH result;
	InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _Font::GetBold()
{
	long result;
	InvokeHelper(0x82, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetBold(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x82, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Font::GetItalic()
{
	long result;
	InvokeHelper(0x83, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetItalic(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x83, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Font::GetHidden()
{
	long result;
	InvokeHelper(0x84, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetHidden(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x84, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Font::GetSmallCaps()
{
	long result;
	InvokeHelper(0x85, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetSmallCaps(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x85, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Font::GetAllCaps()
{
	long result;
	InvokeHelper(0x86, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetAllCaps(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x86, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Font::GetStrikeThrough()
{
	long result;
	InvokeHelper(0x87, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetStrikeThrough(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x87, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Font::GetDoubleStrikeThrough()
{
	long result;
	InvokeHelper(0x88, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetDoubleStrikeThrough(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x88, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Font::GetColorIndex()
{
	long result;
	InvokeHelper(0x89, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetColorIndex(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x89, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Font::GetSubscript()
{
	long result;
	InvokeHelper(0x8a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetSubscript(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Font::GetSuperscript()
{
	long result;
	InvokeHelper(0x8b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetSuperscript(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Font::GetUnderline()
{
	long result;
	InvokeHelper(0x8c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetUnderline(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

float _Font::GetSize()
{
	float result;
	InvokeHelper(0x8d, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void _Font::SetSize(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x8d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

CString _Font::GetName()
{
	CString result;
	InvokeHelper(0x8e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Font::SetName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long _Font::GetPosition()
{
	long result;
	InvokeHelper(0x8f, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetPosition(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

float _Font::GetSpacing()
{
	float result;
	InvokeHelper(0x90, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void _Font::SetSpacing(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x90, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long _Font::GetScaling()
{
	long result;
	InvokeHelper(0x91, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetScaling(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x91, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Font::GetShadow()
{
	long result;
	InvokeHelper(0x92, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetShadow(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x92, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Font::GetOutline()
{
	long result;
	InvokeHelper(0x93, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetOutline(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x93, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Font::GetEmboss()
{
	long result;
	InvokeHelper(0x94, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetEmboss(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x94, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

float _Font::GetKerning()
{
	float result;
	InvokeHelper(0x95, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void _Font::SetKerning(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x95, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long _Font::GetEngrave()
{
	long result;
	InvokeHelper(0x96, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetEngrave(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x96, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Font::GetAnimation()
{
	long result;
	InvokeHelper(0x97, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetAnimation(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x97, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

LPDISPATCH _Font::GetBorders()
{
	LPDISPATCH result;
	InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _Font::SetBorders(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH _Font::GetShading()
{
	LPDISPATCH result;
	InvokeHelper(0x99, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _Font::GetEmphasisMark()
{
	long result;
	InvokeHelper(0x9a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetEmphasisMark(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x9a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _Font::GetDisableCharacterSpaceGrid()
{
	BOOL result;
	InvokeHelper(0x9b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Font::SetDisableCharacterSpaceGrid(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x9b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString _Font::GetNameFarEast()
{
	CString result;
	InvokeHelper(0x9c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Font::SetNameFarEast(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x9c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _Font::GetNameAscii()
{
	CString result;
	InvokeHelper(0x9d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Font::SetNameAscii(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x9d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _Font::GetNameOther()
{
	CString result;
	InvokeHelper(0x9e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Font::SetNameOther(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x9e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

void _Font::Grow()
{
	InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Font::Shrink()
{
	InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Font::Reset()
{
	InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Font::SetAsTemplateDefault()
{
	InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

long _Font::GetColor()
{
	long result;
	InvokeHelper(0x9f, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetColor(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x9f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Font::GetBoldBi()
{
	long result;
	InvokeHelper(0xa0, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetBoldBi(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xa0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Font::GetItalicBi()
{
	long result;
	InvokeHelper(0xa1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetItalicBi(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xa1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

float _Font::GetSizeBi()
{
	float result;
	InvokeHelper(0xa2, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void _Font::SetSizeBi(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0xa2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

CString _Font::GetNameBi()
{
	CString result;
	InvokeHelper(0xa3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Font::SetNameBi(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xa3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long _Font::GetColorIndexBi()
{
	long result;
	InvokeHelper(0xa4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetColorIndexBi(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xa4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Font::GetDiacriticColor()
{
	long result;
	InvokeHelper(0xa5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetDiacriticColor(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xa5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Font::GetUnderlineColor()
{
	long result;
	InvokeHelper(0xa6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Font::SetUnderlineColor(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xa6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}


/////////////////////////////////////////////////////////////////////////////
// LineNumbering properties

/////////////////////////////////////////////////////////////////////////////
// LineNumbering operations

LPDISPATCH LineNumbering::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long LineNumbering::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH LineNumbering::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long LineNumbering::GetRestartMode()
{
	long result;
	InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void LineNumbering::SetRestartMode(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long LineNumbering::GetStartingNumber()
{
	long result;
	InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void LineNumbering::SetStartingNumber(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

float LineNumbering::GetDistanceFromText()
{
	float result;
	InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void LineNumbering::SetDistanceFromText(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long LineNumbering::GetCountBy()
{
	long result;
	InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void LineNumbering::SetCountBy(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long LineNumbering::GetActive()
{
	long result;
	InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void LineNumbering::SetActive(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}


/////////////////////////////////////////////////////////////////////////////
// TextColumns properties

/////////////////////////////////////////////////////////////////////////////
// TextColumns operations

LPUNKNOWN TextColumns::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

long TextColumns::GetCount()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH TextColumns::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long TextColumns::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH TextColumns::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long TextColumns::GetEvenlySpaced()
{
	long result;
	InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void TextColumns::SetEvenlySpaced(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long TextColumns::GetLineBetween()
{
	long result;
	InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void TextColumns::SetLineBetween(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

float TextColumns::GetWidth()
{
	float result;
	InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void TextColumns::SetWidth(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float TextColumns::GetSpacing()
{
	float result;
	InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void TextColumns::SetSpacing(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH TextColumns::Item(long Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}

LPDISPATCH TextColumns::Add(VARIANT* Width, VARIANT* Spacing, VARIANT* EvenlySpaced)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0xc9, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Width, Spacing, EvenlySpaced);
	return result;
}

void TextColumns::SetCount(long NumColumns)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xca, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 NumColumns);
}

long TextColumns::GetFlowDirection()
{
	long result;
	InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void TextColumns::SetFlowDirection(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}


/////////////////////////////////////////////////////////////////////////////
// TextColumn properties

/////////////////////////////////////////////////////////////////////////////
// TextColumn operations

LPDISPATCH TextColumn::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long TextColumn::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH TextColumn::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

float TextColumn::GetWidth()
{
	float result;
	InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void TextColumn::SetWidth(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float TextColumn::GetSpaceAfter()
{
	float result;
	InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void TextColumn::SetSpaceAfter(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}


/////////////////////////////////////////////////////////////////////////////
// Indexes properties

/////////////////////////////////////////////////////////////////////////////
// Indexes operations

LPDISPATCH Indexes::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Indexes::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Indexes::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPUNKNOWN Indexes::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

long Indexes::GetCount()
{
	long result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long Indexes::GetFormat()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Indexes::SetFormat(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

LPDISPATCH Indexes::Item(long Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}

LPDISPATCH Indexes::MarkEntry(LPDISPATCH Range, VARIANT* Entry, VARIANT* EntryAutoText, VARIANT* CrossReference, VARIANT* CrossReferenceAutoText, VARIANT* BookmarkName, VARIANT* Bold, VARIANT* Italic, VARIANT* Reading)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Range, Entry, EntryAutoText, CrossReference, CrossReferenceAutoText, BookmarkName, Bold, Italic, Reading);
	return result;
}

void Indexes::MarkAllEntries(LPDISPATCH Range, VARIANT* Entry, VARIANT* EntryAutoText, VARIANT* CrossReference, VARIANT* CrossReferenceAutoText, VARIANT* BookmarkName, VARIANT* Bold, VARIANT* Italic)
{
	static BYTE parms[] =
		VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Range, Entry, EntryAutoText, CrossReference, CrossReferenceAutoText, BookmarkName, Bold, Italic);
}

void Indexes::AutoMarkEntries(LPCTSTR ConcordanceFileName)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ConcordanceFileName);
}

LPDISPATCH Indexes::Add(LPDISPATCH Range, VARIANT* HeadingSeparator, VARIANT* RightAlignPageNumbers, VARIANT* Type, VARIANT* NumberOfColumns, VARIANT* AccentedLetters, VARIANT* SortBy, VARIANT* IndexLanguage)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x68, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Range, HeadingSeparator, RightAlignPageNumbers, Type, NumberOfColumns, AccentedLetters, SortBy, IndexLanguage);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// Index properties

/////////////////////////////////////////////////////////////////////////////
// Index operations

LPDISPATCH Index::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Index::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Index::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Index::GetHeadingSeparator()
{
	long result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Index::SetHeadingSeparator(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL Index::GetRightAlignPageNumbers()
{
	BOOL result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Index::SetRightAlignPageNumbers(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long Index::GetType()
{
	long result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Index::SetType(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Index::GetNumberOfColumns()
{
	long result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Index::SetNumberOfColumns(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

LPDISPATCH Index::GetRange()
{
	LPDISPATCH result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Index::GetTabLeader()
{
	long result;
	InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Index::SetTabLeader(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL Index::GetAccentedLetters()
{
	BOOL result;
	InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Index::SetAccentedLetters(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long Index::GetSortBy()
{
	long result;
	InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Index::SetSortBy(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long Index::GetFilter()
{
	long result;
	InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Index::SetFilter(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

void Index::Delete()
{
	InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Index::Update()
{
	InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

long Index::GetIndexLanguage()
{
	long result;
	InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Index::SetIndexLanguage(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}


/////////////////////////////////////////////////////////////////////////////
// PageNumbers properties

/////////////////////////////////////////////////////////////////////////////
// PageNumbers operations

LPDISPATCH PageNumbers::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long PageNumbers::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH PageNumbers::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPUNKNOWN PageNumbers::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

long PageNumbers::GetCount()
{
	long result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long PageNumbers::GetNumberStyle()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void PageNumbers::SetNumberStyle(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL PageNumbers::GetIncludeChapterNumber()
{
	BOOL result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void PageNumbers::SetIncludeChapterNumber(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long PageNumbers::GetHeadingLevelForChapter()
{
	long result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void PageNumbers::SetHeadingLevelForChapter(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long PageNumbers::GetChapterPageSeparator()
{
	long result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void PageNumbers::SetChapterPageSeparator(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL PageNumbers::GetRestartNumberingAtSection()
{
	BOOL result;
	InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void PageNumbers::SetRestartNumberingAtSection(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long PageNumbers::GetStartingNumber()
{
	long result;
	InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void PageNumbers::SetStartingNumber(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL PageNumbers::GetShowFirstPageNumber()
{
	BOOL result;
	InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void PageNumbers::SetShowFirstPageNumber(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH PageNumbers::Item(long Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}

LPDISPATCH PageNumbers::Add(VARIANT* PageNumberAlignment, VARIANT* FirstPage)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		PageNumberAlignment, FirstPage);
	return result;
}

BOOL PageNumbers::GetDoubleQuote()
{
	BOOL result;
	InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void PageNumbers::SetDoubleQuote(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}


/////////////////////////////////////////////////////////////////////////////
// PageNumber properties

/////////////////////////////////////////////////////////////////////////////
// PageNumber operations

LPDISPATCH PageNumber::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long PageNumber::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH PageNumber::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long PageNumber::GetIndex()
{
	long result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long PageNumber::GetAlignment()
{
	long result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void PageNumber::SetAlignment(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

void PageNumber::Select()
{
	InvokeHelper(0xffff, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void PageNumber::Copy()
{
	InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void PageNumber::Cut()
{
	InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void PageNumber::Delete()
{
	InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// List properties

/////////////////////////////////////////////////////////////////////////////
// List operations

LPDISPATCH List::GetRange()
{
	LPDISPATCH result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH List::GetListParagraphs()
{
	LPDISPATCH result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL List::GetSingleListTemplate()
{
	BOOL result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

LPDISPATCH List::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long List::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH List::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void List::ConvertNumbersToText(VARIANT* NumberType)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 NumberType);
}

void List::RemoveNumbers(VARIANT* NumberType)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 NumberType);
}

long List::CountNumberedItems(VARIANT* NumberType, VARIANT* Level)
{
	long result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x67, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		NumberType, Level);
	return result;
}

long List::CanContinuePreviousList(LPDISPATCH ListTemplate)
{
	long result;
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x69, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		ListTemplate);
	return result;
}

void List::ApplyListTemplate(LPDISPATCH ListTemplate, VARIANT* ContinuePreviousList, VARIANT* DefaultListBehavior)
{
	static BYTE parms[] =
		VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x6a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ListTemplate, ContinuePreviousList, DefaultListBehavior);
}


/////////////////////////////////////////////////////////////////////////////
// Lists properties

/////////////////////////////////////////////////////////////////////////////
// Lists operations

LPUNKNOWN Lists::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

long Lists::GetCount()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Lists::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Lists::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Lists::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Lists::Item(long Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// ListGallery properties

/////////////////////////////////////////////////////////////////////////////
// ListGallery operations

LPDISPATCH ListGallery::GetListTemplates()
{
	LPDISPATCH result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH ListGallery::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long ListGallery::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH ListGallery::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL ListGallery::GetModified(long Index)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms,
		Index);
	return result;
}

void ListGallery::Reset(long Index)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Index);
}


/////////////////////////////////////////////////////////////////////////////
// ListGalleries properties

/////////////////////////////////////////////////////////////////////////////
// ListGalleries operations

LPUNKNOWN ListGalleries::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

long ListGalleries::GetCount()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH ListGalleries::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long ListGalleries::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH ListGalleries::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH ListGalleries::Item(long Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// Dictionary properties

/////////////////////////////////////////////////////////////////////////////
// Dictionary operations

LPDISPATCH Dictionary::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Dictionary::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Dictionary::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString Dictionary::GetName()
{
	CString result;
	InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString Dictionary::GetPath()
{
	CString result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

long Dictionary::GetLanguageID()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Dictionary::SetLanguageID(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL Dictionary::GetReadOnly()
{
	BOOL result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

long Dictionary::GetType()
{
	long result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL Dictionary::GetLanguageSpecific()
{
	BOOL result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Dictionary::SetLanguageSpecific(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

void Dictionary::Delete()
{
	InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// Styles properties

/////////////////////////////////////////////////////////////////////////////
// Styles operations

LPDISPATCH Styles::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Styles::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Styles::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPUNKNOWN Styles::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

long Styles::GetCount()
{
	long result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Styles::Item(VARIANT* Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}

LPDISPATCH Styles::Add(LPCTSTR Name, VARIANT* Type)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR VTS_PVARIANT;
	InvokeHelper(0x64, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Name, Type);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// Style properties

/////////////////////////////////////////////////////////////////////////////
// Style operations

LPDISPATCH Style::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Style::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Style::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString Style::GetNameLocal()
{
	CString result;
	InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void Style::SetNameLocal(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

VARIANT Style::GetBaseStyle()
{
	VARIANT result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
	return result;
}

void Style::SetBaseStyle(VARIANT* newValue)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

CString Style::GetDescription()
{
	CString result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

long Style::GetType()
{
	long result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL Style::GetBuiltIn()
{
	BOOL result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

VARIANT Style::GetNextParagraphStyle()
{
	VARIANT result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
	return result;
}

void Style::SetNextParagraphStyle(VARIANT* newValue)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

BOOL Style::GetInUse()
{
	BOOL result;
	InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

LPDISPATCH Style::GetShading()
{
	LPDISPATCH result;
	InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Style::GetBorders()
{
	LPDISPATCH result;
	InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void Style::SetBorders(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH Style::GetParagraphFormat()
{
	LPDISPATCH result;
	InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void Style::SetParagraphFormat(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH Style::GetFont()
{
	LPDISPATCH result;
	InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void Style::SetFont(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH Style::GetFrame()
{
	LPDISPATCH result;
	InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Style::GetLanguageID()
{
	long result;
	InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Style::SetLanguageID(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL Style::GetAutomaticallyUpdate()
{
	BOOL result;
	InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Style::SetAutomaticallyUpdate(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH Style::GetListTemplate()
{
	LPDISPATCH result;
	InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Style::GetListLevelNumber()
{
	long result;
	InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long Style::GetLanguageIDFarEast()
{
	long result;
	InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Style::SetLanguageIDFarEast(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

void Style::Delete()
{
	InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Style::LinkToListTemplate(LPDISPATCH ListTemplate, VARIANT* ListLevelNumber)
{
	static BYTE parms[] =
		VTS_DISPATCH VTS_PVARIANT;
	InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ListTemplate, ListLevelNumber);
}

long Style::GetNoProofing()
{
	long result;
	InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Style::SetNoProofing(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x12, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}


/////////////////////////////////////////////////////////////////////////////
// HeadingStyles properties

/////////////////////////////////////////////////////////////////////////////
// HeadingStyles operations

LPDISPATCH HeadingStyles::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long HeadingStyles::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH HeadingStyles::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPUNKNOWN HeadingStyles::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

long HeadingStyles::GetCount()
{
	long result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH HeadingStyles::Item(long Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}

LPDISPATCH HeadingStyles::Add(VARIANT* Style, short Level)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_I2;
	InvokeHelper(0x64, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Style, Level);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// HeadingStyle properties

/////////////////////////////////////////////////////////////////////////////
// HeadingStyle operations

LPDISPATCH HeadingStyle::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long HeadingStyle::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH HeadingStyle::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

VARIANT HeadingStyle::GetStyle()
{
	VARIANT result;
	InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
	return result;
}

void HeadingStyle::SetStyle(VARIANT* newValue)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

short HeadingStyle::GetLevel()
{
	short result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
	return result;
}

void HeadingStyle::SetLevel(short nNewValue)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

void HeadingStyle::Delete()
{
	InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// Table properties

/////////////////////////////////////////////////////////////////////////////
// Table operations

LPDISPATCH Table::GetRange()
{
	LPDISPATCH result;
	InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Table::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Table::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Table::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Table::GetColumns()
{
	LPDISPATCH result;
	InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Table::GetRows()
{
	LPDISPATCH result;
	InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Table::GetBorders()
{
	LPDISPATCH result;
	InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void Table::SetBorders(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH Table::GetShading()
{
	LPDISPATCH result;
	InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL Table::GetUniform()
{
	BOOL result;
	InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

long Table::GetAutoFormatType()
{
	long result;
	InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Table::Select()
{
	InvokeHelper(0xc8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Table::Delete()
{
	InvokeHelper(0x9, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Table::SortAscending()
{
	InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Table::SortDescending()
{
	InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void Table::AutoFormat(VARIANT* Format, VARIANT* ApplyBorders, VARIANT* ApplyShading, VARIANT* ApplyFont, VARIANT* ApplyColor, VARIANT* ApplyHeadingRows, VARIANT* ApplyLastRow, VARIANT* ApplyFirstColumn, VARIANT* ApplyLastColumn, VARIANT* AutoFit)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Format, ApplyBorders, ApplyShading, ApplyFont, ApplyColor, ApplyHeadingRows, ApplyLastRow, ApplyFirstColumn, ApplyLastColumn, AutoFit);
}

void Table::UpdateAutoFormat()
{
	InvokeHelper(0xf, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH Table::Cell(long Row, long Column)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x11, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Row, Column);
	return result;
}

LPDISPATCH Table::Split(VARIANT* BeforeRow)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x12, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		BeforeRow);
	return result;
}

LPDISPATCH Table::ConvertToText(VARIANT* Separator, VARIANT* NestedTables)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x13, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Separator, NestedTables);
	return result;
}

void Table::AutoFitBehavior(long Behavior)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x14, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Behavior);
}

void Table::Sort(VARIANT* ExcludeHeader, VARIANT* FieldNumber, VARIANT* SortFieldType, VARIANT* SortOrder, VARIANT* FieldNumber2, VARIANT* SortFieldType2, VARIANT* SortOrder2, VARIANT* FieldNumber3, VARIANT* SortFieldType3, VARIANT* SortOrder3, 
		VARIANT* CaseSensitive, VARIANT* BidiSort, VARIANT* IgnoreThe, VARIANT* IgnoreKashida, VARIANT* IgnoreDiacritics, VARIANT* IgnoreHe, VARIANT* LanguageID)
{
	static BYTE parms[] =
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x17, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ExcludeHeader, FieldNumber, SortFieldType, SortOrder, FieldNumber2, SortFieldType2, SortOrder2, FieldNumber3, SortFieldType3, SortOrder3, CaseSensitive, BidiSort, IgnoreThe, IgnoreKashida, IgnoreDiacritics, IgnoreHe, LanguageID);
}

LPDISPATCH Table::GetTables()
{
	LPDISPATCH result;
	InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Table::GetNestingLevel()
{
	long result;
	InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL Table::GetAllowPageBreaks()
{
	BOOL result;
	InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Table::SetAllowPageBreaks(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x6d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL Table::GetAllowAutoFit()
{
	BOOL result;
	InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void Table::SetAllowAutoFit(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x6e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

float Table::GetPreferredWidth()
{
	float result;
	InvokeHelper(0x6f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Table::SetPreferredWidth(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x6f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long Table::GetPreferredWidthType()
{
	long result;
	InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Table::SetPreferredWidthType(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x70, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

float Table::GetTopPadding()
{
	float result;
	InvokeHelper(0x71, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Table::SetTopPadding(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x71, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float Table::GetBottomPadding()
{
	float result;
	InvokeHelper(0x72, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Table::SetBottomPadding(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x72, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float Table::GetLeftPadding()
{
	float result;
	InvokeHelper(0x73, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Table::SetLeftPadding(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x73, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float Table::GetRightPadding()
{
	float result;
	InvokeHelper(0x74, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Table::SetRightPadding(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x74, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

float Table::GetSpacing()
{
	float result;
	InvokeHelper(0x75, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void Table::SetSpacing(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x75, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long Table::GetTableDirection()
{
	long result;
	InvokeHelper(0x76, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void Table::SetTableDirection(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x76, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString Table::GetId()
{
	CString result;
	InvokeHelper(0x77, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void Table::SetId(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x77, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}


/////////////////////////////////////////////////////////////////////////////
// Tables properties

/////////////////////////////////////////////////////////////////////////////
// Tables operations

LPUNKNOWN Tables::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

long Tables::GetCount()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Tables::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Tables::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Tables::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Tables::Item(long Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}

LPDISPATCH Tables::Add(LPDISPATCH Range, long NumRows, long NumColumns, VARIANT* DefaultTableBehavior, VARIANT* AutoFitBehavior)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_DISPATCH VTS_I4 VTS_I4 VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0xc8, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Range, NumRows, NumColumns, DefaultTableBehavior, AutoFitBehavior);
	return result;
}

long Tables::GetNestingLevel()
{
	long result;
	InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// TablesOfFigures properties

/////////////////////////////////////////////////////////////////////////////
// TablesOfFigures operations

LPDISPATCH TablesOfFigures::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long TablesOfFigures::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH TablesOfFigures::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPUNKNOWN TablesOfFigures::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

long TablesOfFigures::GetCount()
{
	long result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long TablesOfFigures::GetFormat()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void TablesOfFigures::SetFormat(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

LPDISPATCH TablesOfFigures::Item(long Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}

LPDISPATCH TablesOfFigures::MarkEntry(LPDISPATCH Range, VARIANT* Entry, VARIANT* EntryAutoText, VARIANT* TableID, VARIANT* Level)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Range, Entry, EntryAutoText, TableID, Level);
	return result;
}

LPDISPATCH TablesOfFigures::Add(LPDISPATCH Range, VARIANT* Caption, VARIANT* IncludeLabel, VARIANT* UseHeadingStyles, VARIANT* UpperHeadingLevel, VARIANT* LowerHeadingLevel, VARIANT* UseFields, VARIANT* TableID, VARIANT* RightAlignPageNumbers, 
		VARIANT* IncludePageNumbers, VARIANT* AddedStyles, VARIANT* UseHyperlinks, VARIANT* HidePageNumbersInWeb)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x1bc, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Range, Caption, IncludeLabel, UseHeadingStyles, UpperHeadingLevel, LowerHeadingLevel, UseFields, TableID, RightAlignPageNumbers, IncludePageNumbers, AddedStyles, UseHyperlinks, HidePageNumbersInWeb);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// TableOfFigures properties

/////////////////////////////////////////////////////////////////////////////
// TableOfFigures operations

LPDISPATCH TableOfFigures::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long TableOfFigures::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH TableOfFigures::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString TableOfFigures::GetCaption()
{
	CString result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void TableOfFigures::SetCaption(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL TableOfFigures::GetIncludeLabel()
{
	BOOL result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void TableOfFigures::SetIncludeLabel(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL TableOfFigures::GetRightAlignPageNumbers()
{
	BOOL result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void TableOfFigures::SetRightAlignPageNumbers(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL TableOfFigures::GetUseHeadingStyles()
{
	BOOL result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void TableOfFigures::SetUseHeadingStyles(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long TableOfFigures::GetLowerHeadingLevel()
{
	long result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void TableOfFigures::SetLowerHeadingLevel(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long TableOfFigures::GetUpperHeadingLevel()
{
	long result;
	InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void TableOfFigures::SetUpperHeadingLevel(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL TableOfFigures::GetIncludePageNumbers()
{
	BOOL result;
	InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void TableOfFigures::SetIncludePageNumbers(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH TableOfFigures::GetRange()
{
	LPDISPATCH result;
	InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL TableOfFigures::GetUseFields()
{
	BOOL result;
	InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void TableOfFigures::SetUseFields(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString TableOfFigures::GetTableID()
{
	CString result;
	InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void TableOfFigures::SetTableID(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

LPDISPATCH TableOfFigures::GetHeadingStyles()
{
	LPDISPATCH result;
	InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long TableOfFigures::GetTabLeader()
{
	long result;
	InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void TableOfFigures::SetTabLeader(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

void TableOfFigures::Delete()
{
	InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void TableOfFigures::UpdatePageNumbers()
{
	InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void TableOfFigures::Update()
{
	InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

BOOL TableOfFigures::GetUseHyperlinks()
{
	BOOL result;
	InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void TableOfFigures::SetUseHyperlinks(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL TableOfFigures::GetHidePageNumbersInWeb()
{
	BOOL result;
	InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void TableOfFigures::SetHidePageNumbersInWeb(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}


/////////////////////////////////////////////////////////////////////////////
// TablesOfContents properties

/////////////////////////////////////////////////////////////////////////////
// TablesOfContents operations

LPDISPATCH TablesOfContents::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long TablesOfContents::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH TablesOfContents::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPUNKNOWN TablesOfContents::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

long TablesOfContents::GetCount()
{
	long result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long TablesOfContents::GetFormat()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void TablesOfContents::SetFormat(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

LPDISPATCH TablesOfContents::Item(long Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}

LPDISPATCH TablesOfContents::MarkEntry(LPDISPATCH Range, VARIANT* Entry, VARIANT* EntryAutoText, VARIANT* TableID, VARIANT* Level)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Range, Entry, EntryAutoText, TableID, Level);
	return result;
}

LPDISPATCH TablesOfContents::Add(LPDISPATCH Range, VARIANT* UseHeadingStyles, VARIANT* UpperHeadingLevel, VARIANT* LowerHeadingLevel, VARIANT* UseFields, VARIANT* TableID, VARIANT* RightAlignPageNumbers, VARIANT* IncludePageNumbers, VARIANT* AddedStyles, 
		VARIANT* UseHyperlinks, VARIANT* HidePageNumbersInWeb)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x66, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Range, UseHeadingStyles, UpperHeadingLevel, LowerHeadingLevel, UseFields, TableID, RightAlignPageNumbers, IncludePageNumbers, AddedStyles, UseHyperlinks, HidePageNumbersInWeb);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// TableOfContents properties

/////////////////////////////////////////////////////////////////////////////
// TableOfContents operations

LPDISPATCH TableOfContents::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long TableOfContents::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH TableOfContents::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL TableOfContents::GetUseHeadingStyles()
{
	BOOL result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void TableOfContents::SetUseHeadingStyles(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL TableOfContents::GetUseFields()
{
	BOOL result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void TableOfContents::SetUseFields(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long TableOfContents::GetUpperHeadingLevel()
{
	long result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void TableOfContents::SetUpperHeadingLevel(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long TableOfContents::GetLowerHeadingLevel()
{
	long result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void TableOfContents::SetLowerHeadingLevel(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString TableOfContents::GetTableID()
{
	CString result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void TableOfContents::SetTableID(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

LPDISPATCH TableOfContents::GetHeadingStyles()
{
	LPDISPATCH result;
	InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL TableOfContents::GetRightAlignPageNumbers()
{
	BOOL result;
	InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void TableOfContents::SetRightAlignPageNumbers(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL TableOfContents::GetIncludePageNumbers()
{
	BOOL result;
	InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void TableOfContents::SetIncludePageNumbers(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH TableOfContents::GetRange()
{
	LPDISPATCH result;
	InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long TableOfContents::GetTabLeader()
{
	long result;
	InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void TableOfContents::SetTabLeader(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

void TableOfContents::Delete()
{
	InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void TableOfContents::UpdatePageNumbers()
{
	InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void TableOfContents::Update()
{
	InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

BOOL TableOfContents::GetUseHyperlinks()
{
	BOOL result;
	InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void TableOfContents::SetUseHyperlinks(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL TableOfContents::GetHidePageNumbersInWeb()
{
	BOOL result;
	InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void TableOfContents::SetHidePageNumbersInWeb(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}


/////////////////////////////////////////////////////////////////////////////
// CaptionLabels properties

/////////////////////////////////////////////////////////////////////////////
// CaptionLabels operations

LPDISPATCH CaptionLabels::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long CaptionLabels::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH CaptionLabels::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPUNKNOWN CaptionLabels::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

long CaptionLabels::GetCount()
{
	long result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH CaptionLabels::Item(VARIANT* Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}

LPDISPATCH CaptionLabels::Add(LPCTSTR Name)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x64, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Name);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// CaptionLabel properties

/////////////////////////////////////////////////////////////////////////////
// CaptionLabel operations

LPDISPATCH CaptionLabel::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long CaptionLabel::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH CaptionLabel::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString CaptionLabel::GetName()
{
	CString result;
	InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

BOOL CaptionLabel::GetBuiltIn()
{
	BOOL result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

long CaptionLabel::GetId()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL CaptionLabel::GetIncludeChapterNumber()
{
	BOOL result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CaptionLabel::SetIncludeChapterNumber(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long CaptionLabel::GetNumberStyle()
{
	long result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CaptionLabel::SetNumberStyle(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CaptionLabel::GetChapterStyleLevel()
{
	long result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CaptionLabel::SetChapterStyleLevel(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CaptionLabel::GetSeparator()
{
	long result;
	InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CaptionLabel::SetSeparator(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CaptionLabel::GetPosition()
{
	long result;
	InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CaptionLabel::SetPosition(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

void CaptionLabel::Delete()
{
	InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// AutoCaptions properties

/////////////////////////////////////////////////////////////////////////////
// AutoCaptions operations

LPDISPATCH AutoCaptions::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long AutoCaptions::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH AutoCaptions::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPUNKNOWN AutoCaptions::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

long AutoCaptions::GetCount()
{
	long result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH AutoCaptions::Item(VARIANT* Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}

void AutoCaptions::CancelAutoInsert()
{
	InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// AutoCaption properties

/////////////////////////////////////////////////////////////////////////////
// AutoCaption operations

LPDISPATCH AutoCaption::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long AutoCaption::GetCreator()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH AutoCaption::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString AutoCaption::GetName()
{
	CString result;
	InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

BOOL AutoCaption::GetAutoInsert()
{
	BOOL result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void AutoCaption::SetAutoInsert(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long AutoCaption::GetIndex()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

VARIANT AutoCaption::GetCaptionLabel()
{
	VARIANT result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
	return result;
}

void AutoCaption::SetCaptionLabel(VARIANT* newValue)
{
	static BYTE parms[] =
		VTS_PVARIANT;
	InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}
