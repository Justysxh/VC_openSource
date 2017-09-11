; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CComboBoxClrDlg
LastTemplate=CComboBox
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ComboBoxClr.h"

ClassCount=4
Class1=CComboBoxClrApp
Class2=CComboBoxClrDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CColorCombox
Resource3=IDD_COMBOBOXCLR_DIALOG

[CLS:CComboBoxClrApp]
Type=0
HeaderFile=ComboBoxClr.h
ImplementationFile=ComboBoxClr.cpp
Filter=N

[CLS:CComboBoxClrDlg]
Type=0
HeaderFile=ComboBoxClrDlg.h
ImplementationFile=ComboBoxClrDlg.cpp
Filter=D
LastObject=IDC_COLORBOX
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ComboBoxClrDlg.h
ImplementationFile=ComboBoxClrDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_COMBOBOXCLR_DIALOG]
Type=1
Class=CComboBoxClrDlg
ControlCount=2
Control1=IDC_COLORBOX,combobox,1344340753
Control2=IDC_DEMO,static,1342177289

[CLS:CColorCombox]
Type=0
HeaderFile=ColorCombox.h
ImplementationFile=ColorCombox.cpp
BaseClass=CComboBox
Filter=W
VirtualFilter=cWC

