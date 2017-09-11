# Microsoft Developer Studio Project File - Name="Overtime" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Overtime - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Overtime.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Overtime.mak" CFG="Overtime - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Overtime - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Overtime - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Overtime - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Overtime - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 mpr.lib ws2_32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Overtime - Win32 Release"
# Name "Overtime - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Overtime.cpp
# End Source File
# Begin Source File

SOURCE=.\Overtime.rc
# End Source File
# Begin Source File

SOURCE=.\OvertimeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Overtime.h
# End Source File
# Begin Source File

SOURCE=.\OvertimeDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\1.ico
# End Source File
# Begin Source File

SOURCE=.\res\10.ico
# End Source File
# Begin Source File

SOURCE=.\res\11.ico
# End Source File
# Begin Source File

SOURCE=.\res\12.ico
# End Source File
# Begin Source File

SOURCE=.\res\13.ico
# End Source File
# Begin Source File

SOURCE=.\res\14.ico
# End Source File
# Begin Source File

SOURCE=.\res\15.ICO
# End Source File
# Begin Source File

SOURCE=.\res\16.ico
# End Source File
# Begin Source File

SOURCE=.\res\17.ico
# End Source File
# Begin Source File

SOURCE=.\res\18.ico
# End Source File
# Begin Source File

SOURCE=.\res\19.ico
# End Source File
# Begin Source File

SOURCE=.\res\2.ico
# End Source File
# Begin Source File

SOURCE=.\res\20.ico
# End Source File
# Begin Source File

SOURCE=.\res\21.ico
# End Source File
# Begin Source File

SOURCE=.\res\22.ico
# End Source File
# Begin Source File

SOURCE=.\res\23.ico
# End Source File
# Begin Source File

SOURCE=.\res\24.ico
# End Source File
# Begin Source File

SOURCE=.\res\25.ico
# End Source File
# Begin Source File

SOURCE=.\res\26.ico
# End Source File
# Begin Source File

SOURCE=.\res\27.ico
# End Source File
# Begin Source File

SOURCE=.\res\28.ico
# End Source File
# Begin Source File

SOURCE=.\res\29.ico
# End Source File
# Begin Source File

SOURCE=.\res\3.ico
# End Source File
# Begin Source File

SOURCE=.\res\30.ico
# End Source File
# Begin Source File

SOURCE=.\res\31.ico
# End Source File
# Begin Source File

SOURCE=.\res\32.ico
# End Source File
# Begin Source File

SOURCE=.\res\33.ico
# End Source File
# Begin Source File

SOURCE=.\res\34.ico
# End Source File
# Begin Source File

SOURCE=.\res\35.ico
# End Source File
# Begin Source File

SOURCE=.\res\36.ico
# End Source File
# Begin Source File

SOURCE=.\res\37.ico
# End Source File
# Begin Source File

SOURCE=.\res\38.ico
# End Source File
# Begin Source File

SOURCE=.\res\39.ico
# End Source File
# Begin Source File

SOURCE=.\res\4.ico
# End Source File
# Begin Source File

SOURCE=.\res\40.ico
# End Source File
# Begin Source File

SOURCE=.\res\41.ico
# End Source File
# Begin Source File

SOURCE=.\res\42.ico
# End Source File
# Begin Source File

SOURCE=.\res\43.ico
# End Source File
# Begin Source File

SOURCE=.\res\44.ico
# End Source File
# Begin Source File

SOURCE=.\res\45.ico
# End Source File
# Begin Source File

SOURCE=.\res\46.ico
# End Source File
# Begin Source File

SOURCE=.\res\5.ico
# End Source File
# Begin Source File

SOURCE=.\res\6.ico
# End Source File
# Begin Source File

SOURCE=.\res\7.ico
# End Source File
# Begin Source File

SOURCE=.\res\8.ico
# End Source File
# Begin Source File

SOURCE=.\res\9.ico
# End Source File
# Begin Source File

SOURCE=.\res\Overtime.ico
# End Source File
# Begin Source File

SOURCE=.\res\Overtime.rc2
# End Source File
# Begin Source File

SOURCE=".\res\加班信使服务界面设计(应用版).bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
