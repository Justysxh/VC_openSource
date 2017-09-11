; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTextNewMenuDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TextNewMenu.h"

ClassCount=2
Class1=CTextNewMenuApp
Class2=CTextNewMenuDlg

ResourceCount=4
Resource2=IDR_MAINFRAME
Resource3=IDD_TEXTNEWMENU_DIALOG
Resource4=IDR_TEXTMENU

[CLS:CTextNewMenuApp]
Type=0
HeaderFile=TextNewMenu.h
ImplementationFile=TextNewMenu.cpp
Filter=N

[CLS:CTextNewMenuDlg]
Type=0
HeaderFile=TextNewMenuDlg.h
ImplementationFile=TextNewMenuDlg.cpp
Filter=D
LastObject=CTextNewMenuDlg
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_TEXTNEWMENU_DIALOG]
Type=1
Class=CTextNewMenuDlg
ControlCount=2
Control1=IDC_EDTEXT,edit,1350631552
Control2=IDC_STATIC,static,1342308352

[MNU:IDR_TEXTMENU]
Type=1
Class=?
Command1=ID_VIEW1
Command2=ID_VIEW2
Command3=ID_VIEW3
Command4=ID_VIEW4
CommandCount=4

