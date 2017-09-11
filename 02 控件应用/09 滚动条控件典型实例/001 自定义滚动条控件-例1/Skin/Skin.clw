; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSkinDlg
LastTemplate=CStatic
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Skin.h"

ClassCount=5
Class1=CSkinApp
Class2=CSkinDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_SKIN_DIALOG
Resource2=IDR_MAINFRAME
Class4=CMyScroll
Resource3=IDD_ABOUTBOX
Class5=CCustomScroll
Resource4=IDD_MY_DIALOG

[CLS:CSkinApp]
Type=0
HeaderFile=Skin.h
ImplementationFile=Skin.cpp
Filter=N

[CLS:CSkinDlg]
Type=0
HeaderFile=SkinDlg.h
ImplementationFile=SkinDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_COLOR

[CLS:CAboutDlg]
Type=0
HeaderFile=SkinDlg.h
ImplementationFile=SkinDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SKIN_DIALOG]
Type=1
Class=CSkinDlg
ControlCount=8
Control1=IDC_RED,static,1350696972
Control2=IDC_COLOR,static,1350565895
Control3=IDC_BLUE,static,1350696972
Control4=IDC_GREEN,static,1350696972
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC1,static,1342312448
Control7=IDC_STATIC2,static,1342312448
Control8=IDC_STATIC3,static,1342312448

[CLS:CMyScroll]
Type=0
HeaderFile=MyScroll.h
ImplementationFile=MyScroll.cpp
BaseClass=CScrollBar
Filter=W
VirtualFilter=WC

[DLG:IDD_MY_DIALOG]
Type=1
Class=?
ControlCount=3
Control1=IDC_LEFTARROW,static,1342177294
Control2=IDC_RIGHTARROW,static,1342177294
Control3=IDC_THUMB,static,1342177294

[CLS:CCustomScroll]
Type=0
HeaderFile=CustomScroll.h
ImplementationFile=CustomScroll.cpp
BaseClass=CStatic
Filter=W
VirtualFilter=WC

