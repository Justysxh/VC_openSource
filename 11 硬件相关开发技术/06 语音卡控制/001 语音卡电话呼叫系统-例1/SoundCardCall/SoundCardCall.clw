; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSoundCardCallDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SoundCardCall.h"

ClassCount=3
Class1=CSoundCardCallApp
Class2=CSoundCardCallDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SOUNDCARDCALL_DIALOG

[CLS:CSoundCardCallApp]
Type=0
HeaderFile=SoundCardCall.h
ImplementationFile=SoundCardCall.cpp
Filter=N

[CLS:CSoundCardCallDlg]
Type=0
HeaderFile=SoundCardCallDlg.h
ImplementationFile=SoundCardCallDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_CARDLIST

[CLS:CAboutDlg]
Type=0
HeaderFile=SoundCardCallDlg.h
ImplementationFile=SoundCardCallDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SOUNDCARDCALL_DIALOG]
Type=1
Class=CSoundCardCallDlg
ControlCount=8
Control1=IDC_STATIC,button,1342177287
Control2=IDC_CARDLIST,SysListView32,1350631425
Control3=IDC_STATIC,static,1342308352
Control4=IDC_COMCHANEL,combobox,1344339971
Control5=IDC_STATIC,static,1342308352
Control6=IDC_PHONE,edit,1350631552
Control7=IDC_BUTTON1,button,1342275584
Control8=IDC_BUTTON2,button,1342275584

