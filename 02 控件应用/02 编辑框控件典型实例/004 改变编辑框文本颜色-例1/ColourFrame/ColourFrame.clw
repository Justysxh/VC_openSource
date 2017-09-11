; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CColourFrameDlg
LastTemplate=CEdit
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ColourFrame.h"

ClassCount=5
Class1=CColourFrameApp
Class2=CColourFrameDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=ColourEdit
Class5=CColourEdit
Resource3=IDD_COLOURFRAME_DIALOG

[CLS:CColourFrameApp]
Type=0
HeaderFile=ColourFrame.h
ImplementationFile=ColourFrame.cpp
Filter=N

[CLS:CColourFrameDlg]
Type=0
HeaderFile=ColourFrameDlg.h
ImplementationFile=ColourFrameDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ColourFrameDlg.h
ImplementationFile=ColourFrameDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_COLOURFRAME_DIALOG]
Type=1
Class=CColourFrameDlg
ControlCount=8
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_EDIT2,edit,1350631552
Control3=IDC_EDIT3,edit,1350631552
Control4=IDC_EDIT4,edit,1350631552
Control5=IDC_EDIT5,edit,1350631552
Control6=IDC_EDIT6,edit,1350631552
Control7=IDC_EDIT7,edit,1350631552
Control8=IDC_EDIT8,edit,1350631552

[CLS:ColourEdit]
Type=0
HeaderFile=olourEdit.h
ImplementationFile=olourEdit.cpp
BaseClass=CEdit
Filter=W
VirtualFilter=WC

[CLS:CColourEdit]
Type=0
HeaderFile=ColourEdit.h
ImplementationFile=ColourEdit.cpp
BaseClass=CEdit
Filter=W
VirtualFilter=WC

