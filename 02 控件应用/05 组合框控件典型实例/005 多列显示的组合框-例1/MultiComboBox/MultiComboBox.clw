; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMultiComboBoxDlg
LastTemplate=CComboBox
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MultiComboBox.h"

ClassCount=4
Class1=CMultiComboBoxApp
Class2=CMultiComboBoxDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=MyComboBox
Resource3=IDD_MULTICOMBOBOX_DIALOG

[CLS:CMultiComboBoxApp]
Type=0
HeaderFile=MultiComboBox.h
ImplementationFile=MultiComboBox.cpp
Filter=N

[CLS:CMultiComboBoxDlg]
Type=0
HeaderFile=MultiComboBoxDlg.h
ImplementationFile=MultiComboBoxDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_MULCMB

[CLS:CAboutDlg]
Type=0
HeaderFile=MultiComboBoxDlg.h
ImplementationFile=MultiComboBoxDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MULTICOMBOBOX_DIALOG]
Type=1
Class=CMultiComboBoxDlg
ControlCount=1
Control1=IDC_MULCMB,combobox,1344340755

[CLS:MyComboBox]
Type=0
HeaderFile=MyComboBox.h
ImplementationFile=MyComboBox.cpp
BaseClass=CComboBox
Filter=W
VirtualFilter=cWC
LastObject=MyComboBox

