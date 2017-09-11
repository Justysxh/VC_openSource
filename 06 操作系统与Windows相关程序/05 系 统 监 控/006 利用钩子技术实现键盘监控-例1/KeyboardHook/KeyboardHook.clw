; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CKeyboardHookDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "KeyboardHook.h"

ClassCount=3
Class1=CKeyboardHookApp
Class2=CKeyboardHookDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_KEYBOARDHOOK_DIALOG

[CLS:CKeyboardHookApp]
Type=0
HeaderFile=KeyboardHook.h
ImplementationFile=KeyboardHook.cpp
Filter=N

[CLS:CKeyboardHookDlg]
Type=0
HeaderFile=KeyboardHookDlg.h
ImplementationFile=KeyboardHookDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDUSRINPUT

[CLS:CAboutDlg]
Type=0
HeaderFile=KeyboardHookDlg.h
ImplementationFile=KeyboardHookDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_KEYBOARDHOOK_DIALOG]
Type=1
Class=CKeyboardHookDlg
ControlCount=2
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDUSRINPUT,edit,1350635652

