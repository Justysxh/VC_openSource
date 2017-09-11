// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "msacc9.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// _ObjectFrame properties

/////////////////////////////////////////////////////////////////////////////
// _ObjectFrame operations

LPDISPATCH _ObjectFrame::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x7d5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _ObjectFrame::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x827, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

VARIANT _ObjectFrame::GetOldValue()
{
	VARIANT result;
	InvokeHelper(0x836, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
	return result;
}

LPDISPATCH _ObjectFrame::GetObject()
{
	LPDISPATCH result;
	InvokeHelper(0x838, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _ObjectFrame::GetObjectVerbs(long Index)
{
	CString result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x839, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, parms,
		Index);
	return result;
}

LPDISPATCH _ObjectFrame::GetProperties()
{
	LPDISPATCH result;
	InvokeHelper(0x82b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SizeToFit()
{
	InvokeHelper(0x867, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _ObjectFrame::Requery()
{
	InvokeHelper(0x7e2, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _ObjectFrame::SetFocus()
{
	InvokeHelper(0x7e6, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH _ObjectFrame::GetControls()
{
	LPDISPATCH result;
	InvokeHelper(0x88e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _ObjectFrame::GetEventProcPrefix()
{
	CString result;
	InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetEventProcPrefix(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x16, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ObjectFrame::GetOLEClass()
{
	CString result;
	InvokeHelper(0x4c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetOLEClass(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x4c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ObjectFrame::GetItem()
{
	CString result;
	InvokeHelper(0x2f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetItem(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x2f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ObjectFrame::GetRowSourceType()
{
	CString result;
	InvokeHelper(0x5d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetRowSourceType(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x5d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ObjectFrame::GetRowSource()
{
	CString result;
	InvokeHelper(0x5b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetRowSource(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x5b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ObjectFrame::GetLinkChildFields()
{
	CString result;
	InvokeHelper(0x31, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetLinkChildFields(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x31, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ObjectFrame::GetLinkMasterFields()
{
	CString result;
	InvokeHelper(0x32, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetLinkMasterFields(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x32, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

short _ObjectFrame::GetAutoActivate()
{
	short result;
	InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetAutoActivate(short nNewValue)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _ObjectFrame::GetDisplayType()
{
	BOOL result;
	InvokeHelper(0x110, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetDisplayType(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x110, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

short _ObjectFrame::GetUpdateOptions()
{
	short result;
	InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetUpdateOptions(short nNewValue)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _ObjectFrame::GetVerb()
{
	long result;
	InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetVerb(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString _ObjectFrame::GetSourceObject()
{
	CString result;
	InvokeHelper(0x84, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetSourceObject(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x84, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ObjectFrame::GetClass()
{
	CString result;
	InvokeHelper(0x112, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetClass(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x112, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ObjectFrame::GetSourceDoc()
{
	CString result;
	InvokeHelper(0x85, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetSourceDoc(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x85, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ObjectFrame::GetSourceItem()
{
	CString result;
	InvokeHelper(0x30, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetSourceItem(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x30, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

short _ObjectFrame::GetColumnCount()
{
	short result;
	InvokeHelper(0x46, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetColumnCount(short nNewValue)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x46, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _ObjectFrame::GetColumnHeads()
{
	BOOL result;
	InvokeHelper(0x83, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetColumnHeads(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x83, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _ObjectFrame::GetVisible()
{
	BOOL result;
	InvokeHelper(0x94, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetVisible(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x94, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

short _ObjectFrame::GetUpdateMethod()
{
	short result;
	InvokeHelper(0x8e, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetUpdateMethod(short nNewValue)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x8e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _ObjectFrame::GetEnabled()
{
	BOOL result;
	InvokeHelper(0x19, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetEnabled(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x19, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _ObjectFrame::GetLocked()
{
	BOOL result;
	InvokeHelper(0x38, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetLocked(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x38, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString _ObjectFrame::GetStatusBarText()
{
	CString result;
	InvokeHelper(0x87, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetStatusBarText(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x87, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL _ObjectFrame::GetTabStop()
{
	BOOL result;
	InvokeHelper(0x106, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetTabStop(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x106, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

short _ObjectFrame::GetTabIndex()
{
	short result;
	InvokeHelper(0x105, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetTabIndex(short nNewValue)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x105, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

short _ObjectFrame::GetLeft()
{
	short result;
	InvokeHelper(0x36, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetLeft(short nNewValue)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x36, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

short _ObjectFrame::GetTop()
{
	short result;
	InvokeHelper(0x8d, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetTop(short nNewValue)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x8d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

short _ObjectFrame::GetWidth()
{
	short result;
	InvokeHelper(0x96, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetWidth(short nNewValue)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x96, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

short _ObjectFrame::GetHeight()
{
	short result;
	InvokeHelper(0x2c, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetHeight(short nNewValue)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x2c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _ObjectFrame::GetBackColor()
{
	long result;
	InvokeHelper(0x1c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetBackColor(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _ObjectFrame::GetBorderColor()
{
	long result;
	InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetBorderColor(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString _ObjectFrame::GetShortcutMenuBar()
{
	CString result;
	InvokeHelper(0x130, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetShortcutMenuBar(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x130, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ObjectFrame::GetControlTipText()
{
	CString result;
	InvokeHelper(0x13d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetControlTipText(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x13d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long _ObjectFrame::GetHelpContextId()
{
	long result;
	InvokeHelper(0xdb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetHelpContextId(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xdb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

short _ObjectFrame::GetSection()
{
	short result;
	InvokeHelper(0xed, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetSection(short nNewValue)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0xed, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString _ObjectFrame::GetTag()
{
	CString result;
	InvokeHelper(0x10a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetTag(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x10a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

VARIANT _ObjectFrame::GetObjectPalette()
{
	VARIANT result;
	InvokeHelper(0x63, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetObjectPalette(const VARIANT& newValue)
{
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x63, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 &newValue);
}

long _ObjectFrame::GetLpOleObject()
{
	long result;
	InvokeHelper(0xac, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetLpOleObject(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xac, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _ObjectFrame::GetObjectVerbsCount()
{
	long result;
	InvokeHelper(0xad, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetObjectVerbsCount(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xad, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

short _ObjectFrame::GetAction()
{
	short result;
	InvokeHelper(0x111, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetAction(short nNewValue)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x111, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _ObjectFrame::GetIsVisible()
{
	BOOL result;
	InvokeHelper(0x8c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetIsVisible(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x8c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _ObjectFrame::GetInSelection()
{
	BOOL result;
	InvokeHelper(0x118, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetInSelection(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x118, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString _ObjectFrame::GetOnUpdated()
{
	CString result;
	InvokeHelper(0x76, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetOnUpdated(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x76, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ObjectFrame::GetOnEnter()
{
	CString result;
	InvokeHelper(0xde, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetOnEnter(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xde, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ObjectFrame::GetOnExit()
{
	CString result;
	InvokeHelper(0xdf, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetOnExit(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xdf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ObjectFrame::GetOnGotFocus()
{
	CString result;
	InvokeHelper(0x73, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetOnGotFocus(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x73, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ObjectFrame::GetOnLostFocus()
{
	CString result;
	InvokeHelper(0x74, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetOnLostFocus(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x74, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ObjectFrame::GetOnClick()
{
	CString result;
	InvokeHelper(0x7e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetOnClick(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x7e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ObjectFrame::GetOnDblClick()
{
	CString result;
	InvokeHelper(0xe0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetOnDblClick(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xe0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ObjectFrame::GetOnMouseDown()
{
	CString result;
	InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetOnMouseDown(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ObjectFrame::GetOnMouseMove()
{
	CString result;
	InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetOnMouseMove(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ObjectFrame::GetOnMouseUp()
{
	CString result;
	InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetOnMouseUp(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _ObjectFrame::GetName()
{
	CString result;
	InvokeHelper(0x80010000, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _ObjectFrame::SetName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x80010000, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}


/////////////////////////////////////////////////////////////////////////////
// _Application properties

/////////////////////////////////////////////////////////////////////////////
// _Application operations

LPDISPATCH _Application::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x7d5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x827, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetCodeContextObject()
{
	LPDISPATCH result;
	InvokeHelper(0x822, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _Application::NewCurrentDatabase(LPCTSTR filepath)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x85e, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 filepath);
}

void _Application::OpenCurrentDatabase(LPCTSTR filepath, BOOL Exclusive)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BOOL;
	InvokeHelper(0x85c, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 filepath, Exclusive);
}

CString _Application::GetMenuBar()
{
	CString result;
	InvokeHelper(0x7da, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Application::SetMenuBar(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x7da, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long _Application::GetCurrentObjectType()
{
	long result;
	InvokeHelper(0x7db, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CString _Application::GetCurrentObjectName()
{
	CString result;
	InvokeHelper(0x7dc, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

VARIANT _Application::GetOption(LPCTSTR OptionName)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x7dd, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		OptionName);
	return result;
}

void _Application::SetOption(LPCTSTR OptionName, const VARIANT& Setting)
{
	static BYTE parms[] =
		VTS_BSTR VTS_VARIANT;
	InvokeHelper(0x7de, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 OptionName, &Setting);
}

void _Application::Echo(short EchoOn, LPCTSTR bstrStatusBarText)
{
	static BYTE parms[] =
		VTS_I2 VTS_BSTR;
	InvokeHelper(0x7df, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 EchoOn, bstrStatusBarText);
}

void _Application::CloseCurrentDatabase()
{
	InvokeHelper(0x85d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Application::Quit(long Option)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7e0, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Option);
}

LPDISPATCH _Application::GetForms()
{
	LPDISPATCH result;
	InvokeHelper(0x7d2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetReports()
{
	LPDISPATCH result;
	InvokeHelper(0x7d3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetScreen()
{
	LPDISPATCH result;
	InvokeHelper(0x7d4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetDoCmd()
{
	LPDISPATCH result;
	InvokeHelper(0x7e9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _Application::GetShortcutMenuBar()
{
	CString result;
	InvokeHelper(0x83b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Application::SetShortcutMenuBar(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x83b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL _Application::GetVisible()
{
	BOOL result;
	InvokeHelper(0x864, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetVisible(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x864, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Application::GetUserControl()
{
	BOOL result;
	InvokeHelper(0x865, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetUserControl(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x865, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

VARIANT _Application::SysCmd(long Action, const VARIANT& Argument2, const VARIANT& Argument3)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_I4 VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x7ec, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		Action, &Argument2, &Argument3);
	return result;
}

LPDISPATCH _Application::CreateForm(const VARIANT& Database, const VARIANT& FormTemplate)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x7ed, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		&Database, &FormTemplate);
	return result;
}

LPDISPATCH _Application::CreateReport(const VARIANT& Database, const VARIANT& ReportTemplate)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x7ee, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		&Database, &ReportTemplate);
	return result;
}

LPDISPATCH _Application::CreateControl(LPCTSTR FormName, long ControlType, long Section, const VARIANT& Parent, const VARIANT& ColumnName, const VARIANT& Left, const VARIANT& Top, const VARIANT& Width, const VARIANT& Height)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR VTS_I4 VTS_I4 VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x7ef, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		FormName, ControlType, Section, &Parent, &ColumnName, &Left, &Top, &Width, &Height);
	return result;
}

LPDISPATCH _Application::CreateReportControl(LPCTSTR ReportName, long ControlType, long Section, const VARIANT& Parent, const VARIANT& ColumnName, const VARIANT& Left, const VARIANT& Top, const VARIANT& Width, const VARIANT& Height)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR VTS_I4 VTS_I4 VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x7f0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		ReportName, ControlType, Section, &Parent, &ColumnName, &Left, &Top, &Width, &Height);
	return result;
}

void _Application::DeleteControl(LPCTSTR FormName, LPCTSTR ControlName)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR;
	InvokeHelper(0x7f1, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 FormName, ControlName);
}

void _Application::DeleteReportControl(LPCTSTR ReportName, LPCTSTR ControlName)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR;
	InvokeHelper(0x7f2, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ReportName, ControlName);
}

long _Application::CreateGroupLevel(LPCTSTR ReportName, LPCTSTR Expression, short Header, short Footer)
{
	long result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_I2 VTS_I2;
	InvokeHelper(0x803, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		ReportName, Expression, Header, Footer);
	return result;
}

VARIANT _Application::DMin(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_VARIANT;
	InvokeHelper(0x7f3, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		Expr, Domain, &Criteria);
	return result;
}

VARIANT _Application::DMax(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_VARIANT;
	InvokeHelper(0x7f4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		Expr, Domain, &Criteria);
	return result;
}

VARIANT _Application::DSum(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_VARIANT;
	InvokeHelper(0x7f5, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		Expr, Domain, &Criteria);
	return result;
}

VARIANT _Application::DAvg(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_VARIANT;
	InvokeHelper(0x7f6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		Expr, Domain, &Criteria);
	return result;
}

VARIANT _Application::DLookup(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_VARIANT;
	InvokeHelper(0x7f7, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		Expr, Domain, &Criteria);
	return result;
}

VARIANT _Application::DLast(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_VARIANT;
	InvokeHelper(0x7f8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		Expr, Domain, &Criteria);
	return result;
}

VARIANT _Application::DVar(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_VARIANT;
	InvokeHelper(0x7f9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		Expr, Domain, &Criteria);
	return result;
}

VARIANT _Application::DVarP(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_VARIANT;
	InvokeHelper(0x7fa, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		Expr, Domain, &Criteria);
	return result;
}

VARIANT _Application::DStDev(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_VARIANT;
	InvokeHelper(0x7fb, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		Expr, Domain, &Criteria);
	return result;
}

VARIANT _Application::DStDevP(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_VARIANT;
	InvokeHelper(0x7fc, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		Expr, Domain, &Criteria);
	return result;
}

VARIANT _Application::DFirst(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_VARIANT;
	InvokeHelper(0x7fd, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		Expr, Domain, &Criteria);
	return result;
}

VARIANT _Application::DCount(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_VARIANT;
	InvokeHelper(0x7fe, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		Expr, Domain, &Criteria);
	return result;
}

VARIANT _Application::Eval(LPCTSTR StringExpr)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x7ff, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		StringExpr);
	return result;
}

CString _Application::CurrentUser()
{
	CString result;
	InvokeHelper(0x800, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
	return result;
}

VARIANT _Application::DDEInitiate(LPCTSTR Application, LPCTSTR Topic)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR;
	InvokeHelper(0x804, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		Application, Topic);
	return result;
}

void _Application::DDEExecute(const VARIANT& ChanNum, LPCTSTR Command)
{
	static BYTE parms[] =
		VTS_VARIANT VTS_BSTR;
	InvokeHelper(0x805, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &ChanNum, Command);
}

void _Application::DDEPoke(const VARIANT& ChanNum, LPCTSTR Item, LPCTSTR Data)
{
	static BYTE parms[] =
		VTS_VARIANT VTS_BSTR VTS_BSTR;
	InvokeHelper(0x806, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &ChanNum, Item, Data);
}

CString _Application::DDERequest(const VARIANT& ChanNum, LPCTSTR Item)
{
	CString result;
	static BYTE parms[] =
		VTS_VARIANT VTS_BSTR;
	InvokeHelper(0x807, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		&ChanNum, Item);
	return result;
}

void _Application::DDETerminate(const VARIANT& ChanNum)
{
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x808, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &ChanNum);
}

void _Application::DDETerminateAll()
{
	InvokeHelper(0x809, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH _Application::GetDBEngine()
{
	LPDISPATCH result;
	InvokeHelper(0x83e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::CurrentDb()
{
	LPDISPATCH result;
	InvokeHelper(0x801, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::CodeDb()
{
	LPDISPATCH result;
	InvokeHelper(0x802, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _Application::BuildCriteria(LPCTSTR Field, short FieldType, LPCTSTR Expression)
{
	CString result;
	static BYTE parms[] =
		VTS_BSTR VTS_I2 VTS_BSTR;
	InvokeHelper(0x85a, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		Field, FieldType, Expression);
	return result;
}

LPDISPATCH _Application::DefaultWorkspaceClone()
{
	LPDISPATCH result;
	InvokeHelper(0x86d, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _Application::RefreshTitleBar()
{
	InvokeHelper(0x86e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

long _Application::hWndAccessApp()
{
	long result;
	InvokeHelper(0x873, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

VARIANT _Application::Run(LPCTSTR Procedure, VARIANT* Arg1, VARIANT* Arg2, VARIANT* Arg3, VARIANT* Arg4, VARIANT* Arg5, VARIANT* Arg6, VARIANT* Arg7, VARIANT* Arg8, VARIANT* Arg9, VARIANT* Arg10, VARIANT* Arg11, VARIANT* Arg12, VARIANT* Arg13, 
		VARIANT* Arg14, VARIANT* Arg15, VARIANT* Arg16, VARIANT* Arg17, VARIANT* Arg18, VARIANT* Arg19, VARIANT* Arg20, VARIANT* Arg21, VARIANT* Arg22, VARIANT* Arg23, VARIANT* Arg24, VARIANT* Arg25, VARIANT* Arg26, VARIANT* Arg27, 
		VARIANT* Arg28, VARIANT* Arg29, VARIANT* Arg30)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT 
		VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
	InvokeHelper(0x856, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		Procedure, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19, Arg20, Arg21, Arg22, Arg23, Arg24, Arg25, Arg26, Arg27, Arg28, Arg29, Arg30);
	return result;
}

VARIANT _Application::Nz(const VARIANT& Value, const VARIANT& ValueIfNull)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x857, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		&Value, &ValueIfNull);
	return result;
}

LPDISPATCH _Application::LoadPicture(LPCTSTR FileName)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x876, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		FileName);
	return result;
}

VARIANT _Application::AccessError(const VARIANT& ErrorNumber)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x879, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		&ErrorNumber);
	return result;
}

VARIANT _Application::StringFromGUID(const VARIANT& Guid)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x87b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		&Guid);
	return result;
}

VARIANT _Application::GUIDFromString(const VARIANT& String)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x87c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		&String);
	return result;
}

LPDISPATCH _Application::GetCommandBars()
{
	LPDISPATCH result;
	InvokeHelper(0x87e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetAssistant()
{
	LPDISPATCH result;
	InvokeHelper(0x87f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _Application::FollowHyperlink(LPCTSTR Address, LPCTSTR SubAddress, BOOL NewWindow, BOOL AddHistory, const VARIANT& ExtraInfo, long Method, LPCTSTR HeaderInfo)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_BOOL VTS_BOOL VTS_VARIANT VTS_I4 VTS_BSTR;
	InvokeHelper(0x880, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Address, SubAddress, NewWindow, AddHistory, &ExtraInfo, Method, HeaderInfo);
}

void _Application::AddToFavorites()
{
	InvokeHelper(0x888, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Application::RefreshDatabaseWindow()
{
	InvokeHelper(0x88a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH _Application::GetReferences()
{
	LPDISPATCH result;
	InvokeHelper(0x88b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetModules()
{
	LPDISPATCH result;
	InvokeHelper(0x88c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetFileSearch()
{
	LPDISPATCH result;
	InvokeHelper(0x88d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _Application::GetIsCompiled()
{
	BOOL result;
	InvokeHelper(0x891, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::RunCommand(long Command)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x892, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Command);
}

CString _Application::HyperlinkPart(const VARIANT& Hyperlink, long Part)
{
	CString result;
	static BYTE parms[] =
		VTS_VARIANT VTS_I4;
	InvokeHelper(0x893, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		&Hyperlink, Part);
	return result;
}

BOOL _Application::GetHiddenAttribute(long ObjectType, LPCTSTR ObjectName)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x895, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		ObjectType, ObjectName);
	return result;
}

void _Application::SetHiddenAttribute(long ObjectType, LPCTSTR ObjectName, BOOL fHidden)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR VTS_BOOL;
	InvokeHelper(0x896, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ObjectType, ObjectName, fHidden);
}

LPDISPATCH _Application::GetVbe()
{
	LPDISPATCH result;
	InvokeHelper(0x8a2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetDataAccessPages()
{
	LPDISPATCH result;
	InvokeHelper(0x8a4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::CreateDataAccessPage(const VARIANT& FileName, BOOL CreateNewFile)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_VARIANT VTS_BOOL;
	InvokeHelper(0x8a5, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		&FileName, CreateNewFile);
	return result;
}

LPDISPATCH _Application::GetCurrentProject()
{
	LPDISPATCH result;
	InvokeHelper(0x8a7, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetCurrentData()
{
	LPDISPATCH result;
	InvokeHelper(0x8a8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetCodeProject()
{
	LPDISPATCH result;
	InvokeHelper(0x8a9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetCodeData()
{
	LPDISPATCH result;
	InvokeHelper(0x8aa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _Application::NewAccessProject(LPCTSTR filepath, const VARIANT& Connect)
{
	static BYTE parms[] =
		VTS_BSTR VTS_VARIANT;
	InvokeHelper(0x8d6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 filepath, &Connect);
}

void _Application::OpenAccessProject(LPCTSTR filepath, BOOL Exclusive)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BOOL;
	InvokeHelper(0x8d7, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 filepath, Exclusive);
}

void _Application::CreateAccessProject(LPCTSTR filepath, const VARIANT& Connect)
{
	static BYTE parms[] =
		VTS_BSTR VTS_VARIANT;
	InvokeHelper(0x8d8, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 filepath, &Connect);
}

CString _Application::GetProductCode()
{
	CString result;
	InvokeHelper(0x8da, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetCOMAddIns()
{
	LPDISPATCH result;
	InvokeHelper(0x8e5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _Application::GetName()
{
	CString result;
	InvokeHelper(0x82e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetDefaultWebOptions()
{
	LPDISPATCH result;
	InvokeHelper(0x8e6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetLanguageSettings()
{
	LPDISPATCH result;
	InvokeHelper(0x8fd, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetAnswerWizard()
{
	LPDISPATCH result;
	InvokeHelper(0x900, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _Application::GetFeatureInstall()
{
	long result;
	InvokeHelper(0x912, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetFeatureInstall(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x912, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

double _Application::EuroConvert(double Number, LPCTSTR SourceCurrency, LPCTSTR TargetCurrency, const VARIANT& FullPrecision, const VARIANT& TriangulationPrecision)
{
	double result;
	static BYTE parms[] =
		VTS_R8 VTS_BSTR VTS_BSTR VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x915, DISPATCH_METHOD, VT_R8, (void*)&result, parms,
		Number, SourceCurrency, TargetCurrency, &FullPrecision, &TriangulationPrecision);
	return result;
}
