# Microsoft Developer Studio Project File - Name="Gp3TrackInstaller" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Gp3TrackInstaller - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Gp3TrackInstaller.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Gp3TrackInstaller.mak" CFG="Gp3TrackInstaller - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Gp3TrackInstaller - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Gp3TrackInstaller - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Gp3TrackInstaller - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x41d /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x41d /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:"Release/Gp3 Track Installer.exe"

!ELSEIF  "$(CFG)" == "Gp3TrackInstaller - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x41d /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x41d /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Gp3TrackInstaller - Win32 Release"
# Name "Gp3TrackInstaller - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "InfoZip Source"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\InfoZip\InfoZip.cpp
# End Source File
# End Group
# Begin Group "Banner Source"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Banner\BannerStatic.cpp
# End Source File
# Begin Source File

SOURCE=.\Banner\ColorString.cpp
# End Source File
# Begin Source File

SOURCE=.\Banner\MultiColorStatic.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\DlgOptions.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgProgress.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgReport.cpp
# End Source File
# Begin Source File

SOURCE=.\Gp3Info.cpp
# End Source File
# Begin Source File

SOURCE=.\Gp3TrackInstaller.cpp
# End Source File
# Begin Source File

SOURCE=.\Gp3TrackInstaller.rc
# End Source File
# Begin Source File

SOURCE=.\Gp3TrackInstallerDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Language.cpp
# End Source File
# Begin Source File

SOURCE=.\LogTrace.cpp
# End Source File
# Begin Source File

SOURCE=.\RegEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "InfoZip Header"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\InfoZip\InfoZip.h
# End Source File
# Begin Source File

SOURCE=.\InfoZip\UnzipDLL.h
# End Source File
# Begin Source File

SOURCE=.\InfoZip\ZCallBck.h
# End Source File
# Begin Source File

SOURCE=.\InfoZip\ZipDLL.h
# End Source File
# End Group
# Begin Group "Banner Header"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Banner\BannerStatic.h
# End Source File
# Begin Source File

SOURCE=.\Banner\ColorString.h
# End Source File
# Begin Source File

SOURCE=.\Banner\MultiColorStatic.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\DlgOptions.h
# End Source File
# Begin Source File

SOURCE=.\DlgProgress.h
# End Source File
# Begin Source File

SOURCE=.\DlgReport.h
# End Source File
# Begin Source File

SOURCE=.\Gp3Info.h
# End Source File
# Begin Source File

SOURCE=.\Gp3TrackInstaller.h
# End Source File
# Begin Source File

SOURCE=.\Gp3TrackInstallerDlg.h
# End Source File
# Begin Source File

SOURCE=.\Language.h
# End Source File
# Begin Source File

SOURCE=.\List.h
# End Source File
# Begin Source File

SOURCE=.\LogTrace.h
# End Source File
# Begin Source File

SOURCE=.\RegEdit.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\Gp3TrackInstaller.ico
# End Source File
# Begin Source File

SOURCE=.\res\Gp3TrackInstaller.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
