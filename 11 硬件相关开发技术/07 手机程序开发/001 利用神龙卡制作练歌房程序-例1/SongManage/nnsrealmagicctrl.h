// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// IREALmagicCtrl wrapper class

class IREALmagicCtrl : public COleDispatchDriver
{
public:
	IREALmagicCtrl() {}		// Calls COleDispatchDriver default constructor
	IREALmagicCtrl(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IREALmagicCtrl(const IREALmagicCtrl& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void AboutBox();
	long GetAudioChannel();
	void SetAudioChannel(long nNewValue);
	BOOL GetAutoCloseDriver();
	void SetAutoCloseDriver(BOOL bNewValue);
	long GetBrightness();
	void SetBrightness(long nNewValue);
	long GetSaturation();
	void SetSaturation(long nNewValue);
	long GetContrast();
	void SetContrast(long nNewValue);
	long GetCurrentFrame();
	void SetCurrentFrame(long nNewValue);
	long GetCurrentDVDTrack();
	void SetCurrentDVDTrack(long nNewValue);
	CString GetFilename();
	void SetFilename(LPCTSTR lpszNewValue);
	BOOL GetMute();
	void SetMute(BOOL bNewValue);
	long GetVolume();
	void SetVolume(long nNewValue);
	long GetDVDTrackCount();
	long GetFrameCount();
	void CloseDriver();
	void Play();
	void Pause();
	void Stop();
	void CloseFile();
	BOOL OpenFile();
	BOOL OpenDriver();
	void SetSerialString(LPCTSTR lpszNewValue);
	long GetDisplayDevice();
	void SetDisplayDevice(long nNewValue);
	long GetVideoMode();
	void SetVideoMode(long nNewValue);
	long GetDeviceState();
	long GetMediaFormat();
	long GetPlayMode();
	void SetPlayMode(long nNewValue);
};
/////////////////////////////////////////////////////////////////////////////
// IREALmagicCtrlEvents wrapper class

class IREALmagicCtrlEvents : public COleDispatchDriver
{
public:
	IREALmagicCtrlEvents() {}		// Calls COleDispatchDriver default constructor
	IREALmagicCtrlEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IREALmagicCtrlEvents(const IREALmagicCtrlEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
};
