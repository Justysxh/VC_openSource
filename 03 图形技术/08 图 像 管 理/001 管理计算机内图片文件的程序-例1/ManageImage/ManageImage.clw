; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CManageImageDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ManageImage.h"

ClassCount=3
Class1=CManageImageApp
Class2=CManageImageDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MANAGEIMAGE_DIALOG

[CLS:CManageImageApp]
Type=0
HeaderFile=ManageImage.h
ImplementationFile=ManageImage.cpp
Filter=N

[CLS:CManageImageDlg]
Type=0
HeaderFile=ManageImageDlg.h
ImplementationFile=ManageImageDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_TREE

[CLS:CAboutDlg]
Type=0
HeaderFile=ManageImageDlg.h
ImplementationFile=ManageImageDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MANAGEIMAGE_DIALOG]
Type=1
Class=CManageImageDlg
ControlCount=4
Control1=IDC_DISK,combobox,1344340227
Control2=IDC_DIR,listbox,1353777408
Control3=IDC_TREE,SysTreeView32,1350632487
Control4=IDC_SAVE,button,1342275584

