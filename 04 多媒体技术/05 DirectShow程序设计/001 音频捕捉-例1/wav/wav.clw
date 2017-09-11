; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWavDlg
LastTemplate=CPropertyPage
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "wav.h"

ClassCount=5
Class1=CWavApp
Class2=CWavDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_WAV_DIALOG
Resource2=IDR_MAINFRAME
Class5=CPage1
Resource3=IDD_ABOUTBOX
Class4=CMySheet
Resource4=IDD_DIALOG1

[CLS:CWavApp]
Type=0
HeaderFile=wav.h
ImplementationFile=wav.cpp
Filter=N

[CLS:CWavDlg]
Type=0
HeaderFile=wavDlg.h
ImplementationFile=wavDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CWavDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=wavDlg.h
ImplementationFile=wavDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_WAV_DIALOG]
Type=1
Class=CWavDlg
ControlCount=8
Control1=IDOK,button,1342275584
Control2=IDCANCEL,button,1342275584
Control3=IDC_STATIC,static,1342308364
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_STATIC,button,1342177415
Control6=IDC_BUTBROWN,button,1342242816
Control7=IDOK2,button,1342275584
Control8=IDOK3,button,1342275584

[CLS:CMySheet]
Type=0
HeaderFile=MySheet.h
ImplementationFile=MySheet.cpp
BaseClass=CPropertySheet
Filter=W
VirtualFilter=hWC

[CLS:CPage1]
Type=0
HeaderFile=Page1.h
ImplementationFile=Page1.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=CPage1

[DLG:IDD_DIALOG1]
Type=1
Class=CPage1
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_BUTTON1,button,1342242816

