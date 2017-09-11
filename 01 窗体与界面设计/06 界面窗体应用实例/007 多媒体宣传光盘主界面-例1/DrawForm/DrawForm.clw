; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDrawFormDlg
LastTemplate=CStatic
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DrawForm.h"

ClassCount=4
Class1=CDrawFormApp
Class2=CDrawFormDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CMyStatic
Resource3=IDD_DRAWFORM_DIALOG

[CLS:CDrawFormApp]
Type=0
HeaderFile=DrawForm.h
ImplementationFile=DrawForm.cpp
Filter=N

[CLS:CDrawFormDlg]
Type=0
HeaderFile=DrawFormDlg.h
ImplementationFile=DrawFormDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_STATIC2

[CLS:CAboutDlg]
Type=0
HeaderFile=DrawFormDlg.h
ImplementationFile=DrawFormDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DRAWFORM_DIALOG]
Type=1
Class=CDrawFormDlg
ControlCount=7
Control1=IDC_STATIC2,static,1342308363
Control2=IDC_STATIC1,static,1342308363
Control3=IDC_EDIT2,edit,1350631584
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_BUTTON1,button,1342275584
Control6=IDC_STATIC,static,1342181383
Control7=IDC_BUTTON2,button,1342275584

[CLS:CMyStatic]
Type=0
HeaderFile=MyStatic.h
ImplementationFile=MyStatic.cpp
BaseClass=CStatic
Filter=W
VirtualFilter=WC
LastObject=CMyStatic

