#ifndef __FINDFILE__H__
#define __FINDFILE__H__

#include "List.h"

class CFindFile  
{
private:
	bool SearchDir(char* Dir, char* FileType);
	bool Push(char* data);

	List<char>* m_pFileList;
	int m_PosCounter;
public:
	CFindFile();
	virtual ~CFindFile();

	bool StartSearch(char* Dir, char* FileType);
	char* Pop();
};

#endif
