; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CColourTextDlg
LastTemplate=CEdit
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ColourText.h"

ClassCount=4
Class1=CColourTextApp
Class2=CColourTextDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CEditText
Resource3=IDD_COLOURTEXT_DIALOG

[CLS:CColourTextApp]
Type=0
HeaderFile=ColourText.h
ImplementationFile=ColourText.cpp
Filter=N

[CLS:CColourTextDlg]
Type=0
HeaderFile=ColourTextDlg.h
ImplementationFile=ColourTextDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_COMBO1

[CLS:CAboutDlg]
Type=0
HeaderFile=ColourTextDlg.h
ImplementationFile=ColourTextDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_COLOURTEXT_DIALOG]
Type=1
Class=CColourTextDlg
ControlCount=10
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_RED,button,1342177289
Control3=IDC_BLUE,button,1342177289
Control4=IDC_GREEN,button,1342177289
Control5=IDC_YELLOW,button,1342177289
Control6=IDC_AMETHYST,button,1342177289
Control7=IDC_CYAN,button,1342177289
Control8=IDC_BLACK,button,1342177289
Control9=IDC_GRAY,button,1342177289
Control10=IDC_STATIC,button,1342177287

[CLS:CEditText]
Type=0
HeaderFile=EditText.h
ImplementationFile=EditText.cpp
BaseClass=CEdit
Filter=W
VirtualFilter=WC
LastObject=CEditText

