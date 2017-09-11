

#include "stdafx.h"
#include <windows.h>
#include <Dinput.h>


LPDIRECTINPUT           g_lpDInput = NULL ;
LPDIRECTINPUTDEVICE     g_lpDIDeviceKeyboard = NULL; 
LPDIRECTINPUTDEVICE2    g_lpDIDeviceJoystick = NULL ;

BOOL CALLBACK EnumJoy(LPCDIDEVICEINSTANCE lpddi, LPVOID pvRef)
{
   BOOL                 bEnumForce ;
   DIPROPRANGE          dipRange ;
   DIPROPDWORD          dipDWORD ;
   LPDIRECTINPUTDEVICE  lpDIDeviceJoystickTemp ;
   HRESULT              hr ;


   bEnumForce = (BOOL) pvRef ;


   if( FAILED(g_lpDInput->CreateDevice(lpddi->guidInstance,
               &lpDIDeviceJoystickTemp, NULL)))
   {
      g_lpDIDeviceJoystick = NULL ;
      return DIENUM_CONTINUE ;
   }


   hr = lpDIDeviceJoystickTemp->QueryInterface(IID_IDirectInputDevice2,
                                              (void **) &g_lpDIDeviceJoystick) ;
   lpDIDeviceJoystickTemp->Release() ;
   if( FAILED( hr ) )
   {
      g_lpDIDeviceJoystick = NULL ;
      return DIENUM_CONTINUE ;
   }


   g_lpDIDeviceJoystick->SetDataFormat(&c_dfDIJoystick) ;


   g_lpDIDeviceJoystick->SetCooperativeLevel(AfxGetApp()->GetMainWnd()->m_hWnd,
                                            DISCL_EXCLUSIVE|DISCL_BACKGROUND) ;

   dipRange.diph.dwSize       = sizeof(dipRange) ;
   dipRange.diph.dwHeaderSize = sizeof(dipRange.diph) ;
   dipRange.diph.dwObj        = DIJOFS_X ;
   dipRange.diph.dwHow        = DIPH_BYOFFSET ;
   dipRange.lMin              = -100 ;
   dipRange.lMax              = +100 ;
   g_lpDIDeviceJoystick->SetProperty( DIPROP_RANGE, &dipRange.diph) ;

   dipRange.diph.dwSize       = sizeof(dipRange) ;
   dipRange.diph.dwHeaderSize = sizeof(dipRange.diph) ;
   dipRange.diph.dwObj        = DIJOFS_Y ;
   dipRange.diph.dwHow        = DIPH_BYOFFSET ;
   dipRange.lMin              = -100 ;
   dipRange.lMax              = +100 ;
   g_lpDIDeviceJoystick->SetProperty( DIPROP_RANGE, &dipRange.diph) ;


   dipDWORD.diph.dwSize       = sizeof(dipDWORD) ;
   dipDWORD.diph.dwHeaderSize = sizeof(dipDWORD.diph) ;
   dipDWORD.diph.dwObj        = DIJOFS_Y ;
   dipDWORD.diph.dwHow        = DIPH_BYOFFSET ;
   dipDWORD.dwData            = 2000 ;
   g_lpDIDeviceJoystick->SetProperty( DIPROP_DEADZONE, &dipDWORD.diph) ;

   dipDWORD.diph.dwSize       = sizeof(dipDWORD) ;
   dipDWORD.diph.dwHeaderSize = sizeof(dipDWORD.diph) ;
   dipDWORD.diph.dwObj        = DIJOFS_X ;
   dipDWORD.diph.dwHow        = DIPH_BYOFFSET ;
   dipDWORD.dwData            = 2000 ;
   g_lpDIDeviceJoystick->SetProperty( DIPROP_DEADZONE, &dipDWORD.diph) ;

   return DIENUM_STOP ;
}

BOOL InitDirectInput( void ) 
{
	//创建IDIRECTINPUT接口
    if( FAILED(CoCreateInstance(CLSID_DirectInput, NULL, CLSCTX_INPROC_SERVER,
               IID_IDirectInput, (void **)&g_lpDInput)) )
		return FALSE ;
	if( FAILED(g_lpDInput->Initialize(AfxGetApp()->m_hInstance,DIRECTINPUT_VERSION) ) )
        return FALSE ;

	if( !FAILED(g_lpDInput->CreateDevice(GUID_SysKeyboard,
										 &g_lpDIDeviceKeyboard, NULL)) )
	{
		g_lpDIDeviceKeyboard->SetDataFormat(&c_dfDIKeyboard) ;
		g_lpDIDeviceKeyboard->SetCooperativeLevel(AfxGetApp()->
			GetMainWnd()->m_hWnd,DISCL_FOREGROUND | DISCL_NONEXCLUSIVE) ;
	}else
		g_lpDIDeviceKeyboard = NULL ;

	g_lpDInput->EnumDevices( DIDEVTYPE_JOYSTICK, EnumJoy, (LPVOID)TRUE,
							 DIEDFL_FORCEFEEDBACK|DIEDFL_ATTACHEDONLY) ;
	if( !g_lpDIDeviceJoystick )
		g_lpDInput->EnumDevices( DIDEVTYPE_JOYSTICK, EnumJoy, (LPVOID)FALSE,
								DIEDFL_ATTACHEDONLY) ;

	return true;
}


//初始化DirectX
BOOL InitDirectX( void )
{
   // Initialize COM for this process
   if (FAILED(CoInitialize(NULL)))
      return FALSE ;

   // Initialize Direct Input -- DXInput.h
   if( !InitDirectInput() )
      return FALSE ;

   return TRUE ;
}

BOOL GetKeyboardInput( int *nX, int *nY, BOOL *bButton )
{
   char     cBuffer[256] ;
   HRESULT  hr ;

   if(!g_lpDIDeviceKeyboard)
      return FALSE ;

   //*nX = 0 ; *nY = 0 ; 
   *bButton = FALSE ;

   hr = g_lpDIDeviceKeyboard->GetDeviceState(sizeof(cBuffer),(LPVOID)cBuffer) ;
   if(hr== DIERR_INPUTLOST || hr== DIERR_NOTACQUIRED )
   {
      g_lpDIDeviceKeyboard->Acquire() ;
      hr = g_lpDIDeviceKeyboard->GetDeviceState( sizeof(cBuffer),
                                                 (LPVOID)cBuffer) ;
   }

   if( FAILED(hr) )
      return FALSE ;

   if(cBuffer[DIK_RIGHT]&0x80)
      (*nX)++ ;

   if(cBuffer[DIK_LEFT]&0x80)
      (*nX)-- ;

   if(cBuffer[DIK_UP]&0x80)
      (*nY)-- ;

   if(cBuffer[DIK_DOWN]&0x80)
      (*nY)++ ;

   if(cBuffer[DIK_LCONTROL]&0x80)
      *bButton = TRUE ;

   return TRUE ;

}

BOOL GetJoystickInput( int *nX, int *nY, BOOL *bButton )
{
   HRESULT     hr ;
   DIJOYSTATE  diJoyState ;

   if(!g_lpDIDeviceJoystick)
      return FALSE ;

   //*nX = 0 ;    *nY = 0 ; 
   *bButton = FALSE ;

   hr = g_lpDIDeviceJoystick->Poll() ;
    if(hr== DIERR_INPUTLOST || hr== DIERR_NOTACQUIRED )
    {
      g_lpDIDeviceJoystick->Acquire() ;

      /*if(g_lpdiEffectWavy)
         g_lpdiEffectWavy->Download() ;
      if(g_lpdiEffectRamp)
         g_lpdiEffectRamp->Download() ;*/

      hr = g_lpDIDeviceJoystick->Poll() ;
    }
   if( FAILED(hr) )
      return FALSE ;

   if( FAILED(g_lpDIDeviceJoystick->GetDeviceState( sizeof(DIJOYSTATE), &
                                                     diJoyState)) )
      return FALSE ;

   *nX += diJoyState.lX ;
   //*nY = diJoyState.lY ;
   *bButton = diJoyState.rgbButtons[0] ;

   return TRUE ;

}

void UnInitDirectInput( void )
{
   if(g_lpDIDeviceKeyboard)
   {
      g_lpDIDeviceKeyboard->Unacquire() ;
      g_lpDIDeviceKeyboard->Release() ;
   }

   if(g_lpDIDeviceJoystick)
   {
      g_lpDIDeviceJoystick->Unacquire() ;
      g_lpDIDeviceJoystick->Release() ;
   }

   if(g_lpDInput)
      g_lpDInput->Release() ;

   return ;
}

void UnInitDirectX( void )
{
   UnInitDirectInput() ;

   CoUninitialize() ;
}