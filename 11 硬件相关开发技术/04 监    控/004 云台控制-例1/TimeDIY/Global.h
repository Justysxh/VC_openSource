#ifndef SAA7134_DEMO_GLOBAL
#define SAA7134_DEMO_GLOBAL

#include "sa7134Capture.h"
typedef struct OSD_INFO
{
	OSDPARAM	OSDParam;
	BOOL		cfEnableOSD;
	TCHAR		cfText[256];
	BOOL		cfTransparent;
	POINT		cfTopLeft;
}OSD_Info;

typedef struct DEVICE_INFO
{
	HWND			hWnd;
	BOOL			bOpen;
	BOOL			bDbClick;
	BOOL			bCapStart;
	DWORD			dwCard;
	
	DWORD			dwCapTime;
	DWORD			dwRealFrameRate;
	DWORD			dwFileNum;
	
	char			strCapDir[261];
	DWORD			dwDispWidth;
	DWORD			dwDispHeight;
	DWORD			dwDispPosX;
	DWORD			dwDispPosY;
	DWORD			dwCapHeight;
	DWORD			dwCapWeight;
	
	DWORD			dwFrameRate;
	DWORD			dwSwitchFreq;
	DWORD			dwBitRate;
	DWORD			dwKeyFrmInterval;
	CAPMODEL		enVidCapModel;
	MP4MODEL		enVidMpegModel;
	CAPMODEL		enAudCapModel;
	MP4MODEL		enAudMpegModel;
	
	DWORD			dwSharpness;
	DWORD			dwSaturation;
	DWORD			dwHue;
	DWORD			dwContrast;
	DWORD			dwBrightness;
	
	BOOL			bNetTrans;
	BOOL			bFrameRateReduction;
	BOOL			bMotionDetect;
	BOOL			bAudioOut;
	OSD_Info		stuOSDPARAM[2];
	BOOL			bSignl;
	DWORD			dwQuantizer;
//	DWORD			dwMotionPrecision;
	COMPRESSMODE	enCompessMode;
	DWORD			dwVBRPeakrate;
	DWORD			dwVBRMaxrate;
	BOOL	        bPrev;
//	BOOL			bIOLowLevelIn;
//	BOOL			bFirstIoAlert;
}Device_Info;

const DWORD dwBackColor = RGB( 255, 0, 255 );
#endif
