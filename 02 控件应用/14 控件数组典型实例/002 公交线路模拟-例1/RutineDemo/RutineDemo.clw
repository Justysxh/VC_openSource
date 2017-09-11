; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRutineDemoDlg
LastTemplate=CStatic
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "RutineDemo.h"

ClassCount=4
Class1=CRutineDemoApp
Class2=CRutineDemoDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CMyStatic
Resource3=IDD_RUTINEDEMO_DIALOG

[CLS:CRutineDemoApp]
Type=0
HeaderFile=RutineDemo.h
ImplementationFile=RutineDemo.cpp
Filter=N

[CLS:CRutineDemoDlg]
Type=0
HeaderFile=RutineDemoDlg.h
ImplementationFile=RutineDemoDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CRutineDemoDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=RutineDemoDlg.h
ImplementationFile=RutineDemoDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_RUTINEDEMO_DIALOG]
Type=1
Class=CRutineDemoDlg
ControlCount=6
Control1=IDC_TITILE,static,1342308352
Control2=IDC_STATIC,static,1342308363
Control3=IDC_STATIC,static,1342308363
Control4=IDC_STATIC,static,1342308363
Control5=IDC_STATIC,static,1342308363
Control6=IDC_STATIC,static,1342308363

[CLS:CMyStatic]
Type=0
HeaderFile=MyStatic.h
ImplementationFile=MyStatic.cpp
BaseClass=CStatic
Filter=W
VirtualFilter=WC

