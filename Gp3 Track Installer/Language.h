#ifndef __LANGUAGE__H__
#define __LANGUAGE__H__

#include "List.h"

class CLanguage  
{
private:
	List<char>* m_pTextList;
public:
	enum eValueName {FILE_MENU,
									 FILE_OPEN,
									 FILE_CLOSE,
									 FILE_EXIT,
									 HELP_MENU,
									 HELP_ONLINE,
									 HELP_HELP,
									 HELP_ABOUT,
									 TRACK_FILE_FRAME,
									 NO_TRACK,
									 GP3_SETTINGS_FRAME,
									 GP3_PATH,
									 GP3_2000_PATH,
									 GP3_TRACK_DIR,
									 INSTALL_FRAME,
									 GP3_INSTALL_BUTTON,
									 GP3_2000_INSTALL_BUTTON,
									 BOTH_INSTALL_BUTTON,
									 ZIP_SETTINGS_FRAME,
									 EXTRACT_TO_TEMP,
									 EXTRACT_TO,
									 REMOVE_FILES,
									 MISC_SETTINGS_FRAME,
									 ALWAYS_OVERWRITE,
									 SHOW_REPORT,
									 SHOW_GP3FORM,
									 NO_GP3_DIRECTORY,
									 NO_GP3_2000_DIRECTORY,
									 NO_GP3_AND_2000_DIRECTORY,
									 FOLDER_CONTAINS_FILE,
									 NO_JAM_FILES_INSTALLED,
									 NO_GP3_TRACK_FILE,
									 FILE_NOT_FOUND,
									 EXTRACT_ERROR,
									 SETTINGS_CAPTION,
									 FILE_SETTINGS,
									 SELECT_LANGUAGE,
									 GP3INFO_NAME,
									 GP3INFO_COUNTRY,
									 GP3INFO_LENGTH,
									 GP3INFO_LAPS,
									 GP3INFO_YEAR,
									 GP3INFO_SLOT,
									 GP3INFO_EVENT,
									 GP3INFO_AUTHOR,
									 GP3INFO_DESC,
									 GP3INFO_FRAME_TITLE,
									 PROGRESS_TITLE,
									 PROGRESS_SUB_TITLE,
									 REPORT_TITLE,
									 GP3FORM_TITLE,
									 REPORT_OK_BUTTON,
									 GP3FORM_OK_BUTTON};

	bool LoadLanguageFile(char* file);
	char* GetText(eValueName value);
	CLanguage();
	virtual ~CLanguage();
};

#endif
