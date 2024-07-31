; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGp1LapEditorDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Gp1 Lap Editor.h"

ClassCount=3
Class1=CGp1LapEditorApp
Class2=CGp1LapEditorDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_GP1LAPEDITOR_DIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Resource5=IDD_GP1LAPEDITOR_DIALOG (English (U.S.))
Resource6=IDR_MAIN

[CLS:CGp1LapEditorApp]
Type=0
HeaderFile=Gp1 Lap Editor.h
ImplementationFile=Gp1 Lap Editor.cpp
Filter=N

[CLS:CGp1LapEditorDlg]
Type=0
HeaderFile=Gp1 Lap EditorDlg.h
ImplementationFile=Gp1 Lap EditorDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_FILE_SAVEAS

[CLS:CAboutDlg]
Type=0
HeaderFile=Gp1 Lap EditorDlg.h
ImplementationFile=Gp1 Lap EditorDlg.cpp
Filter=D
LastObject=IDC_INET
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_GP1LAPEDITOR_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CGp1LapEditorDlg

[DLG:IDD_GP1LAPEDITOR_DIALOG (English (U.S.))]
Type=1
Class=CGp1LapEditorDlg
ControlCount=5
Control1=IDC_FILES,SysListView32,1350631583
Control2=IDC_SAVE,button,1342242817
Control3=IDC_LAPS,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_FILEEXT,combobox,1344339971

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=6
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[MNU:IDR_MAIN]
Type=1
Class=?
Command1=ID_FILE_OPEN
Command2=ID_FILE_SAVE
Command3=ID_FILE_SAVEAS
Command4=ID_FILE_EXIT
Command5=ID_EDIT_SETTRACKPATH
Command6=ID_HELP_ONLINE
Command7=ID_HELP_ABOUT
CommandCount=7

