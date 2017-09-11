; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CChildDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Magnetism.h"

ClassCount=4
Class1=CMagnetismApp
Class2=CMagnetismDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MAGNETISM_DIALOG
Class4=CChildDlg
Resource4=IDD_CHILD_DIALOG

[CLS:CMagnetismApp]
Type=0
HeaderFile=Magnetism.h
ImplementationFile=Magnetism.cpp
Filter=N

[CLS:CMagnetismDlg]
Type=0
HeaderFile=MagnetismDlg.h
ImplementationFile=MagnetismDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CMagnetismDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=MagnetismDlg.h
ImplementationFile=MagnetismDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MAGNETISM_DIALOG]
Type=1
Class=CMagnetismDlg
ControlCount=1
Control1=IDC_STATIC,static,1342177294

[DLG:IDD_CHILD_DIALOG]
Type=1
Class=CChildDlg
ControlCount=1
Control1=IDC_STATIC,static,1342177294

[CLS:CChildDlg]
Type=0
HeaderFile=ChildDlg.h
ImplementationFile=ChildDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CChildDlg

