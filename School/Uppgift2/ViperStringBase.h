#ifndef __CVIPERSTRINGBASE__H__
#define __CVIPERSTRINGBASE__H__

class CViperStringBase  
{
public:
	int strcmp(const char* string1, const char* string2);
	int stricmp(const char *string1, const char *string2, const int len);
	int strcmpi(const char* string1, const char* string2);
	int stricmpi(const char *string1, const char *string2, const int len);
	bool stricpy(char* target, const char* source, const int len);
	bool strcpy(char* target, const char* source);
	char* stricat(char* target, const char* source, const int len);
	int strlen(const char* str);
	char* strcat(char* target, const char* source);

	CViperStringBase();
	virtual ~CViperStringBase();

};

#endif