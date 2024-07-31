#ifndef __DEFFIX__H__
#define __DEFFIX__H__

#include <fstream.h>

class CDefFix  
{
private:
	bool Replace();
	bool FindMatch(char* line, char* find);
	int Vipercmp(const char* string1, const char* string2, const int len);

	ifstream m_Fin;
	ofstream m_Fout;
	char* m_FileName;
	char* m_Find;
	char* m_Add;
public:
	CDefFix();
	virtual ~CDefFix();

	bool FixFile(char* File, char* Find, char* Add);
};

#endif
