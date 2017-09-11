; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSerialInterfaceDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SerialInterface.h"

ClassCount=3
Class1=CSerialInterfaceApp
Class2=CSerialInterfaceDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SERIALINTERFACE_DIALOG

[CLS:CSerialInterfaceApp]
Type=0
HeaderFile=SerialInterface.h
ImplementationFile=SerialInterface.cpp
Filter=N

[CLS:CSerialInterfaceDlg]
Type=0
HeaderFile=SerialInterfaceDlg.h
ImplementationFile=SerialInterfaceDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=SerialInterfaceDlg.h
ImplementationFile=SerialInterfaceDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SERIALINTERFACE_DIALOG]
Type=1
Class=CSerialInterfaceDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_BUTOBTAIN,button,1342242816
Control3=IDC_MSCOMM1,{648A5600-2C6E-101B-82B6-000000000014},1342242816
Control4=IDC_EDIT1,edit,1350631552

