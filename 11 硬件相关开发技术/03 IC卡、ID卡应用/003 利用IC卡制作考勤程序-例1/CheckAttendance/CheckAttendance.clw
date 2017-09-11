; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CReFreshCard
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CheckAttendance.h"

ClassCount=7
Class1=CCheckAttendanceApp
Class2=CCheckAttendanceDlg
Class3=CAboutDlg

ResourceCount=8
Resource1=IDD_REFRESHCARD_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_EMPLOYEE_DIALOG
Resource4=IDD_DIALOG1
Class4=CCartSet
Class5=CCardID
Resource5=IDR_MAINMENU
Class6=CEmployee
Resource6=IDD_CHECKATTENDANCE_DIALOG
Resource7=IDD_ABOUTBOX
Class7=CReFreshCard
Resource8=IDR_TOOLBAR

[CLS:CCheckAttendanceApp]
Type=0
HeaderFile=CheckAttendance.h
ImplementationFile=CheckAttendance.cpp
Filter=N

[CLS:CCheckAttendanceDlg]
Type=0
HeaderFile=CheckAttendanceDlg.h
ImplementationFile=CheckAttendanceDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_MENUCHECK

[CLS:CAboutDlg]
Type=0
HeaderFile=CheckAttendanceDlg.h
ImplementationFile=CheckAttendanceDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CHECKATTENDANCE_DIALOG]
Type=1
Class=CCheckAttendanceDlg
ControlCount=1
Control1=IDC_STATIC,static,1342177294

[MNU:IDR_MAINMENU]
Type=1
Class=?
Command1=ID_MENUITEM32771
Command2=ID_MENUITEMEXIT
Command3=ID_CARTSET
Command4=ID_MENUADD
Command5=ID_MENUDELETE
Command6=ID_MENUCHECK
CommandCount=6

[CLS:CCartSet]
Type=0
HeaderFile=CartSet.h
ImplementationFile=CartSet.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_WRITE

[DLG:IDD_DIALOG1]
Type=1
Class=CCartSet
ControlCount=6
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_CARDID,static,1342308620
Control4=IDC_GENERATEID,button,1342275584
Control5=IDC_WRITE,button,1476493312
Control6=IDC_REFRESHCARD,button,1342275584

[CLS:CCardID]
Type=0
HeaderFile=CardID.h
ImplementationFile=CardID.cpp
BaseClass=CStatic
Filter=W
VirtualFilter=WC
LastObject=CCardID

[DLG:IDD_EMPLOYEE_DIALOG]
Type=1
Class=CEmployee
ControlCount=15
Control1=IDC_WORDID,edit,1350631552
Control2=IDC_WORDERNAME,edit,1350631552
Control3=IDC_SEX,combobox,1344339971
Control4=IDC_DUTY,edit,1350631552
Control5=IDC_ICID,edit,1350633600
Control6=IDC_REFRESH,button,1342242816
Control7=IDC_ADD,button,1342275584
Control8=IDC_BUTTONCANCEL,button,1342275584
Control9=IDC_EXIT,button,1342275584
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352

[CLS:CEmployee]
Type=0
HeaderFile=Employee.h
ImplementationFile=Employee.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CEmployee

[TB:IDR_TOOLBAR]
Type=1
Class=?
Command1=ID_CARTSET
Command2=ID_MENUADD
Command3=ID_MENUDELETE
Command4=ID_MENUCHECK
Command5=ID_MENUITEMEXIT
CommandCount=5

[DLG:IDD_REFRESHCARD_DIALOG]
Type=1
Class=CReFreshCard
ControlCount=12
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_WORDID,edit,1350631552
Control5=IDC_WORDERNAME,edit,1350631552
Control6=IDC_SEX,combobox,1344339970
Control7=IDC_DUTY,edit,1350631552
Control8=IDC_ICID,edit,1350633600
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_HINT,static,1342308352

[CLS:CReFreshCard]
Type=0
HeaderFile=ReFreshCard.h
ImplementationFile=ReFreshCard.cpp
BaseClass=CDialog
Filter=W
VirtualFilter=dWC
LastObject=IDC_HINT

