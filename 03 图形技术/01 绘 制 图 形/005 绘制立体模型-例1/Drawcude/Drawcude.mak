# Microsoft Developer Studio Generated NMAKE File, Based on Drawcude.dsp
!IF "$(CFG)" == ""
CFG=Drawcude - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Drawcude - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Drawcude - Win32 Release" && "$(CFG)" != "Drawcude - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Drawcude.mak" CFG="Drawcude - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Drawcude - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Drawcude - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Drawcude - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Drawcude.exe"


CLEAN :
	-@erase "$(INTDIR)\Drawcude.obj"
	-@erase "$(INTDIR)\Drawcude.pch"
	-@erase "$(INTDIR)\Drawcude.res"
	-@erase "$(INTDIR)\DrawcudeDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Drawcude.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Drawcude.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\Drawcude.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Drawcude.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Drawcude.pdb" /machine:I386 /out:"$(OUTDIR)\Drawcude.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Drawcude.obj" \
	"$(INTDIR)\DrawcudeDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Drawcude.res"

"$(OUTDIR)\Drawcude.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Drawcude - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Drawcude.exe"


CLEAN :
	-@erase "$(INTDIR)\Drawcude.obj"
	-@erase "$(INTDIR)\Drawcude.pch"
	-@erase "$(INTDIR)\Drawcude.res"
	-@erase "$(INTDIR)\DrawcudeDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Drawcude.exe"
	-@erase "$(OUTDIR)\Drawcude.ilk"
	-@erase "$(OUTDIR)\Drawcude.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Drawcude.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ   /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\Drawcude.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Drawcude.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Drawcude.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Drawcude.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\Drawcude.obj" \
	"$(INTDIR)\DrawcudeDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Drawcude.res"

"$(OUTDIR)\Drawcude.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Drawcude.dep")
!INCLUDE "Drawcude.dep"
!ELSE 
!MESSAGE Warning: cannot find "Drawcude.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Drawcude - Win32 Release" || "$(CFG)" == "Drawcude - Win32 Debug"
SOURCE=.\Drawcude.cpp

"$(INTDIR)\Drawcude.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Drawcude.pch"


SOURCE=.\Drawcude.rc

"$(INTDIR)\Drawcude.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\DrawcudeDlg.cpp

"$(INTDIR)\DrawcudeDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Drawcude.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "Drawcude - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Drawcude.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Drawcude.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Drawcude - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Drawcude.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ   /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Drawcude.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

