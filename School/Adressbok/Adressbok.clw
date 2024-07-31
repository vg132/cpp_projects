; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAdressbokDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Adressbok.h"

ClassCount=4
Class1=CAdressbokApp
Class2=CAdressbokDlg
Class3=CAboutDlg

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_ADRESSBOK_DIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Resource5=IDD_SEARCH
Resource6=IDD_ADRESSBOK_DIALOG (English (U.S.))
Class4=CSearchDlg
Resource7=IDR_MAINMENU

[CLS:CAdressbokApp]
Type=0
HeaderFile=Adressbok.h
ImplementationFile=Adressbok.cpp
Filter=N
LastObject=CAdressbokApp

[CLS:CAdressbokDlg]
Type=0
HeaderFile=AdressbokDlg.h
ImplementationFile=AdressbokDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_FILE_CLOSE

[CLS:CAboutDlg]
Type=0
HeaderFile=AdressbokDlg.h
ImplementationFile=AdressbokDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_ADRESSBOK_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CAdressbokDlg

[DLG:IDD_ADRESSBOK_DIALOG (English (U.S.))]
Type=1
Class=CAdressbokDlg
ControlCount=22
Control1=IDC_CONTACT_LIST,SysListView32,1350631437
Control2=IDC_STATIC,static,1342177287
Control3=IDC_FRAME_LIST,button,1342177287
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_FIRSTNAME,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_LASTNAME,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT_ADDRESS,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT_POSTNR,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_EDIT_CITY,edit,1350631552
Control15=IDC_STATIC,static,1342308352
Control16=IDC_EDIT_PHONE,edit,1350631552
Control17=IDC_BUTTON_ADD,button,1342242816
Control18=IDC_BUTTON_REMOVE,button,1342242816
Control19=IDC_BUTTON_SAVE,button,1342242816
Control20=IDC_BUTTON_SEARCH,button,1342242816
Control21=IDC_BUTTON_SHOWALL,button,1342242816
Control22=IDC_BUTTON2,button,1073807361

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINMENU]
Type=1
Class=?
Command1=ID_FILE_NY
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SPARASOM
Command6=ID_APP_EXIT
Command7=ID_APP_ABOUT
CommandCount=7

[DLG:IDD_SEARCH]
Type=1
Class=CSearchDlg
ControlCount=14
Control1=IDC_CHECK_FIRSTNAME,button,1342242819
Control2=IDC_CHECK_ADDRESS,button,1342242819
Control3=IDC_CHECK_LASTNAME,button,1342242819
Control4=IDC_CHECK_POSTNR,button,1342242819
Control5=IDC_CHECK_CITY,button,1342242819
Control6=IDC_CHECK_PHONE,button,1342242819
Control7=IDC_EDIT_FIRSTNAME,edit,1484849280
Control8=IDC_EDIT_LASTNAME,edit,1484849280
Control9=IDC_EDIT_ADDRESS,edit,1484849280
Control10=IDC_EDIT_POSTNR,edit,1484849280
Control11=IDC_EDIT_CITY,edit,1484849280
Control12=IDC_EDIT_PHONE,edit,1484849280
Control13=IDC_BUTTON_SEARCH,button,1342242817
Control14=IDC_BUTTON_CANCEL,button,1342242816

[CLS:CSearchDlg]
Type=0
HeaderFile=SearchDlg.h
ImplementationFile=SearchDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSearchDlg
VirtualFilter=dWC

