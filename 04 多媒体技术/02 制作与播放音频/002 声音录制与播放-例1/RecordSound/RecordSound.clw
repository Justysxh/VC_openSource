; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRecordSoundDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "RecordSound.h"

ClassCount=3
Class1=CRecordSoundApp
Class2=CRecordSoundDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_RECORDSOUND_DIALOG

[CLS:CRecordSoundApp]
Type=0
HeaderFile=RecordSound.h
ImplementationFile=RecordSound.cpp
Filter=N

[CLS:CRecordSoundDlg]
Type=0
HeaderFile=RecordSoundDlg.h
ImplementationFile=RecordSoundDlg.cpp
Filter=D
LastObject=IDC_BTSTOP
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=RecordSoundDlg.h
ImplementationFile=RecordSoundDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_RECORDSOUND_DIALOG]
Type=1
Class=CRecordSoundDlg
ControlCount=3
Control1=IDC_BTRECORD,button,1342242816
Control2=IDC_BTPLAY,button,1342242816
Control3=IDC_BTSTOP,button,1342242816

