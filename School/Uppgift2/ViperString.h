#ifndef __CVIPERSTRING_H__
#define __CVIPERSTRING_H__

#include <iostream>
#include <fstream>
using namespace std;
#include "ViperStringBase.h"

class CViperString
{
private:
	CViperStringBase vsb;
	char* m_Str;
	char* m_TmpStr;
	char* s1;
	char* s2;
public:
	char* ToChar();
	CViperString uppercase();
	CViperString lowercase();
	CViperString replace(const char* find, const char* replace);
	CViperString reverse();
	int count();
	void operator =(const CViperString &cvs);
	void operator =(const char* str);
	CViperString operator +(const CViperString &cvs);
	CViperString operator +(const char* str);
	void operator +=(const char *str);
	void operator +=(const char str);

	CViperString();
	CViperString(const char* str);
	CViperString(const CViperString &s);
	virtual ~CViperString();

	friend istream & operator>>(istream & is, CViperString & vs);
	friend ostream & operator<<(ostream & os, CViperString & vs);
	friend ifstream & operator>>(ifstream & fis, CViperString & vs);

};

#endif
