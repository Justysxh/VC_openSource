; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDiskSerialDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DiskSerial.h"

ClassCount=3
Class1=CDiskSerialApp
Class2=CDiskSerialDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DISKSERIAL_DIALOG

[CLS:CDiskSerialApp]
Type=0
HeaderFile=DiskSerial.h
ImplementationFile=DiskSerial.cpp
Filter=N

[CLS:CDiskSerialDlg]
Type=0
HeaderFile=DiskSerialDlg.h
ImplementationFile=DiskSerialDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_DISKLIST

[CLS:CAboutDlg]
Type=0
HeaderFile=DiskSerialDlg.h
ImplementationFile=DiskSerialDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DISKSERIAL_DIALOG]
Type=1
Class=CDiskSerialDlg
ControlCount=1
Control1=IDC_DISKLIST,SysListView32,1350631425

