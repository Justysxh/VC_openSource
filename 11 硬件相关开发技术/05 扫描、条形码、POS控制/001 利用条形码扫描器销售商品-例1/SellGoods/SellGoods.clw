; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSellGoodsDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SellGoods.h"

ClassCount=3
Class1=CSellGoodsApp
Class2=CSellGoodsDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SELLGOODS_DIALOG

[CLS:CSellGoodsApp]
Type=0
HeaderFile=SellGoods.h
ImplementationFile=SellGoods.cpp
Filter=N

[CLS:CSellGoodsDlg]
Type=0
HeaderFile=SellGoodsDlg.h
ImplementationFile=SellGoodsDlg.cpp
Filter=D
LastObject=IDC_BARCODE
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=SellGoodsDlg.h
ImplementationFile=SellGoodsDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SELLGOODS_DIALOG]
Type=1
Class=CSellGoodsDlg
ControlCount=5
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_BARCODE,edit,1350574208
Control4=IDC_LISTINFO,SysListView32,1350631425
Control5=IDC_SAVE,button,1342242816

