; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCourseDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Course.h"

ClassCount=4
Class1=CCourseApp
Class2=CCourseDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_COURSE_DIALOG

[CLS:CCourseApp]
Type=0
HeaderFile=Course.h
ImplementationFile=Course.cpp
Filter=N

[CLS:CCourseDlg]
Type=0
HeaderFile=CourseDlg.h
ImplementationFile=CourseDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=CourseDlg.h
ImplementationFile=CourseDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_COURSE_DIALOG]
Type=1
Class=CCourseDlg
ControlCount=5
Control1=IDC_STATIC,button,1342177287
Control2=IDC_BUTMAX,button,1342242816
Control3=IDC_BUTMIN,button,1342242816
Control4=IDC_BUTREVERT,button,1342242816
Control5=IDC_BUTEXIT,button,1342242816

