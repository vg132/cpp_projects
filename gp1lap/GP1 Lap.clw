; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGP1LapDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GP1 Lap.h"

ClassCount=3
Class1=CGP1LapApp
Class2=CGP1LapDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_GP1LAP_DIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Resource5=IDD_GP1LAP_DIALOG (English (U.S.))
Resource6=IDR_MENU1

[CLS:CGP1LapApp]
Type=0
HeaderFile=GP1 Lap.h
ImplementationFile=GP1 Lap.cpp
Filter=N

[CLS:CGP1LapDlg]
Type=0
HeaderFile=GP1 LapDlg.h
ImplementationFile=GP1 LapDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CGP1LapDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=GP1 LapDlg.h
ImplementationFile=GP1 LapDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_GP1LAP_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CGP1LapDlg

[DLG:IDD_GP1LAP_DIALOG (English (U.S.))]
Type=1
Class=CGP1LapDlg
ControlCount=7
Control1=IDC_Import,button,1342242816
Control2=IDC_EDIT1,edit,1350639616
Control3=IDC_STATIC,static,1342308352
Control4=IDC_Export,button,1342242816
Control5=IDC_FileName,static,1073872896
Control6=IDC_About,button,1342242816
Control7=IDC_Exit,button,1342242816

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=MNU_TrackDir
Command2=MNU_Exit
Command3=MNU_About
CommandCount=3

