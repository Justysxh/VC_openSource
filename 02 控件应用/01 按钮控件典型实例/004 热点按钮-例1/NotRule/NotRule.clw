; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNotRuleDlg
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "NotRule.h"

ClassCount=5
Class1=CNotRuleApp
Class2=CNotRuleDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CBmpButton
Class4=CCustomButton
Resource3=IDD_NOTRULE_DIALOG

[CLS:CNotRuleApp]
Type=0
HeaderFile=NotRule.h
ImplementationFile=NotRule.cpp
Filter=N

[CLS:CNotRuleDlg]
Type=0
HeaderFile=NotRuleDlg.h
ImplementationFile=NotRuleDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CNotRuleDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=NotRuleDlg.h
ImplementationFile=NotRuleDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_NOTRULE_DIALOG]
Type=1
Class=CNotRuleDlg
ControlCount=6
Control1=IDC_BUTTON2,button,1342242827
Control2=IDC_BUTTON1,button,1342242827
Control3=IDC_BUTTON3,button,1342242827
Control4=IDC_BUTTON4,button,1342242827
Control5=IDC_BUTTON5,button,1342242827
Control6=IDC_BUTTON6,button,1342242827

[CLS:CCustomButton]
Type=0
HeaderFile=CustomButton.h
ImplementationFile=CustomButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC
LastObject=CCustomButton

[CLS:CBmpButton]
Type=0
HeaderFile=BmpButton.h
ImplementationFile=BmpButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC

