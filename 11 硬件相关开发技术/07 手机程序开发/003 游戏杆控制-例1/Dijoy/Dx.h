/******************************************************************************
FILE: Dx.h
******************************************************************************/


BOOL InitDirectX( void );
void UnInitDirectX( void );
BOOL GetJoystickInput( int *nX, int *nY, BOOL *bButton );
BOOL GetKeyboardInput( int *nX, int *nY, BOOL *bButton );