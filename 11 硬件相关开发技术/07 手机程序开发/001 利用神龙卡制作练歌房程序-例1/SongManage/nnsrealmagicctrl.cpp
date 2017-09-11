// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "nnsrealmagicctrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// IREALmagicCtrl properties

/////////////////////////////////////////////////////////////////////////////
// IREALmagicCtrl operations

void IREALmagicCtrl::AboutBox()
{
	InvokeHelper(0xfffffdd8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

long IREALmagicCtrl::GetAudioChannel()
{
	long result;
	InvokeHelper(0x23, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void IREALmagicCtrl::SetAudioChannel(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x23, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL IREALmagicCtrl::GetAutoCloseDriver()
{
	BOOL result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void IREALmagicCtrl::SetAutoCloseDriver(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long IREALmagicCtrl::GetBrightness()
{
	long result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void IREALmagicCtrl::SetBrightness(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long IREALmagicCtrl::GetSaturation()
{
	long result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void IREALmagicCtrl::SetSaturation(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long IREALmagicCtrl::GetContrast()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void IREALmagicCtrl::SetContrast(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long IREALmagicCtrl::GetCurrentFrame()
{
	long result;
	InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void IREALmagicCtrl::SetCurrentFrame(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long IREALmagicCtrl::GetCurrentDVDTrack()
{
	long result;
	InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void IREALmagicCtrl::SetCurrentDVDTrack(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString IREALmagicCtrl::GetFilename()
{
	CString result;
	InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void IREALmagicCtrl::SetFilename(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL IREALmagicCtrl::GetMute()
{
	BOOL result;
	InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void IREALmagicCtrl::SetMute(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long IREALmagicCtrl::GetVolume()
{
	long result;
	InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void IREALmagicCtrl::SetVolume(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long IREALmagicCtrl::GetDVDTrackCount()
{
	long result;
	InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long IREALmagicCtrl::GetFrameCount()
{
	long result;
	InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void IREALmagicCtrl::CloseDriver()
{
	InvokeHelper(0x16, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void IREALmagicCtrl::Play()
{
	InvokeHelper(0x17, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void IREALmagicCtrl::Pause()
{
	InvokeHelper(0x18, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void IREALmagicCtrl::Stop()
{
	InvokeHelper(0x19, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void IREALmagicCtrl::CloseFile()
{
	InvokeHelper(0x1a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

BOOL IREALmagicCtrl::OpenFile()
{
	BOOL result;
	InvokeHelper(0x1e, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL IREALmagicCtrl::OpenDriver()
{
	BOOL result;
	InvokeHelper(0x1f, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}

void IREALmagicCtrl::SetSerialString(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long IREALmagicCtrl::GetDisplayDevice()
{
	long result;
	InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void IREALmagicCtrl::SetDisplayDevice(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x13, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long IREALmagicCtrl::GetVideoMode()
{
	long result;
	InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void IREALmagicCtrl::SetVideoMode(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x14, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long IREALmagicCtrl::GetDeviceState()
{
	long result;
	InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long IREALmagicCtrl::GetMediaFormat()
{
	long result;
	InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long IREALmagicCtrl::GetPlayMode()
{
	long result;
	InvokeHelper(0x1d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void IREALmagicCtrl::SetPlayMode(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}


/////////////////////////////////////////////////////////////////////////////
// IREALmagicCtrlEvents properties

/////////////////////////////////////////////////////////////////////////////
// IREALmagicCtrlEvents operations
