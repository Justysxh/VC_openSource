; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEncryptLockDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "EncryptLock.h"

ClassCount=3
Class1=CEncryptLockApp
Class2=CEncryptLockDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_ENCRYPTLOCK_DIALOG

[CLS:CEncryptLockApp]
Type=0
HeaderFile=EncryptLock.h
ImplementationFile=EncryptLock.cpp
Filter=N

[CLS:CEncryptLockDlg]
Type=0
HeaderFile=EncryptLockDlg.h
ImplementationFile=EncryptLockDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=EncryptLockDlg.h
ImplementationFile=EncryptLockDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ENCRYPTLOCK_DIALOG]
Type=1
Class=CEncryptLockDlg
ControlCount=3
Control1=IDS_ABOUTBOX,static,1342177294
Control2=IDC_BUTLOGIN,button,1342242944
Control3=IDC_EDIT1,edit,1342242944

