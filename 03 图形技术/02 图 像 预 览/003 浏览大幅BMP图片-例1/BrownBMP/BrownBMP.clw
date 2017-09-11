; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CBrownBMPDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "BrownBMP.h"

ClassCount=5
Class1=CBrownBMPApp
Class2=CBrownBMPDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_BROWNBMP_DIALOG
Resource2=IDR_MAINFRAME
Class4=CBrownBmp
Resource3=IDD_ABOUTBOX
Class5=CBmpDlg
Resource4=IDD_BMPDLG_DIALOG

[CLS:CBrownBMPApp]
Type=0
HeaderFile=BrownBMP.h
ImplementationFile=BrownBMP.cpp
Filter=N

[CLS:CBrownBMPDlg]
Type=0
HeaderFile=BrownBMPDlg.h
ImplementationFile=BrownBMPDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_PATH

[CLS:CAboutDlg]
Type=0
HeaderFile=BrownBMPDlg.h
ImplementationFile=BrownBMPDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_BROWNBMP_DIALOG]
Type=1
Class=CBrownBMPDlg
ControlCount=5
Control1=IDC_STATIC,static,1342308352
Control2=IDC_PATH,edit,1350631552
Control3=IDC_BROWN,button,1342242816
Control4=IDC_BMP,static,1342179342
Control5=IDC_FRAME,static,1342177287

[CLS:CBrownBmp]
Type=0
HeaderFile=BrownBmp1.h
ImplementationFile=BrownBmp1.cpp
BaseClass=CStatic
Filter=W
VirtualFilter=WC

[DLG:IDD_BMPDLG_DIALOG]
Type=1
Class=CBmpDlg
ControlCount=0

[CLS:CBmpDlg]
Type=0
HeaderFile=BmpDlg.h
ImplementationFile=BmpDlg.cpp
BaseClass=CDialog
Filter=W
VirtualFilter=dWC

