#ifndef __CFILELIST__H__
#define __CFILELIST__H__

#include "List.h"

class CFileList  
{
public:
	int GetNrOfFiles();
	char* Pop();
	bool FindFiles(char* Folder, int Type, char* Filter);
	CFileList();
	~CFileList();

private:
	char* m_Folder;
	int m_Type;
	void Search(char* Folder=NULL);
	List<char> m_ListFilter;
	List<char> m_ListFiles;
	void SplitFileFilter(char* Filter);
};

#endif
