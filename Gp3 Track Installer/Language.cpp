// Language.cpp: implementation of the CLanguage class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "gp3trackinstaller.h"
#include "Language.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLanguage::CLanguage()
{
	m_pTextList=NULL;
}

CLanguage::~CLanguage()
{
	if(m_pTextList!=NULL)
		delete m_pTextList;
}

char* CLanguage::GetText(eValueName value)
{/*
	char* pNewText;
	pNewText=new char[strlen(m_pTextList->GetItem(value))+1];
	strcpy(pNewText,m_pTextList->GetItem(value));
	return(pNewText);*/
	return(m_pTextList->GetItem(value));
}

bool CLanguage::LoadLanguageFile(char *file)
{
	if(m_pTextList!=NULL)
		delete m_pTextList;
	m_pTextList=new List<char>;
	DWORD dSize=500;
	char* pBuffer=new char[dSize];

	GetPrivateProfileString("MENU","FILE_MENU","File",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("MENU","FILE_OPEN","Open",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("MENU","FILE_CLOSE","Close",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("MENU","FILE_EXIT","Exit",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("MENU","HELP_MENU","Help",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("MENU","HELP_ONLINE","VG Software Online",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("MENU","HELP_HELP","Help...",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("MENU","HELP_ABOUT","About...",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","TRACK_FILE_FRAME","Track File",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","NO_TRACK","-[ No Track File ]-",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","GP3_SETTINGS_FRAME","Gp3 Settings",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","GP3_PATH","Gp3 Path",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","GP3_2000_PATH","Gp3-2000 Path",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","GP3_TRACK_DIR","Gp3 Track Directory",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","INSTALL_FRAME","Install",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","GP3_INSTALL_BUTTON","Gp3",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","GP3_2000_INSTALL_BUTTON","Gp3 2000",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","BOTH_INSTALL_BUTTON","Both",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","ZIP_SETTINGS_FRAME","Zip Settings",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","EXTRACT_TO_TEMP","Extract to temp forlder and remove after installation",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","EXTRACT_TO","Extract to:",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","REMOVE_FILES","Remove files after installation",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","MISC_SETTINGS_FRAME","Misc Settings",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","ALWAYS_OVERWRITE","Always overwrite files",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","SHOW_REPORT","Show status report after installation",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","SHOW_GP3FORM","Show Gp3 form after installation",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("MESSAGES","NO_GP3_DIRECTORY","You have to enter the path to your Gp3 directory",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("MESSAGES","NO_GP3_2000_DIRECTORY","You have to enter the path to your Gp3 2000 directory",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("MESSAGES","NO_GP3_AND_2000_DIRECTORY","You have to enter the path to your Gp3 and Gp3 2000 directory",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("MESSAGES","FOLDER_CONTAINS_FILE","The folder '%s' already contains a file named '%s'.\n\nWould you like to replace the existing file?",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("MESSAGES","NO_JAM_FILES_INSTALLED","No jam files was installed. This my not be a problem but it can be.\n\nPlease check if you have all the jam files for this track in the correct directory.\nFor more information one how to install track's with this software please read the help file.",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("MESSAGES","NO_GP3_TRACK_FILE","This is not a Gp3 track file.",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("MESSAGES","FILE_NOT_FOUND","File not found.",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("MESSAGES","EXTRACT_ERROR","Error when extracting zip file, %s, to temp directory. Please try to extract the file with another zip utility (WinZip, http://www.winzip.com/).",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","SETTINGS_CAPTION","Options",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("MENU","FILE_SETTINGS","Settings...", pBuffer, dSize, file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","SELECT_LANGUAGE","Select language",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("GP3INFO","GP3INFO_NAME","Track Name:",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("GP3INFO","GP3INFO_COUNTRY","Country:",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("GP3INFO","GP3INFO_LENGTH","Length:",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("GP3INFO","GP3INFO_LAPS","Laps:",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("GP3INFO","GP3INFO_YEAR","Year:",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("GP3INFO","GP3INFO_SLOT","Slot:",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("GP3INFO","GP3INFO_EVENT","Event:",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("GP3INFO","GP3INFO_AUTHOR","Author:",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("GP3INFO","GP3INFO_DESC","Description:",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("GP3INFO","GP3INFO_FRAME_TITLE","Gp3 Info",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","PROGRESS_TITLE","Installing:",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","PROGRESS_SUB_TITLE","Now processing...",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","REPORT_TITLE","Report",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","GP3FORM_TITLE","Gp3 Form",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","REPORT_OK_BUTTON","OK",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
	pBuffer=new char[dSize];

	GetPrivateProfileString("INTERFACE","GP3FORM_OK_BUTTON","OK",pBuffer,dSize,file);
	m_pTextList->Add(pBuffer);
//	pBuffer=new char[dSize];
	return(true);
}
