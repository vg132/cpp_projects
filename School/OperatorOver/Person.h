#ifndef __PERSON__H__
#define __PERSON__H__

#include <iostream.h>

#define NULL 0

class CPerson
{
private:
	char* m_Name;
public:
	void operator =(const CPerson* person);
	bool operator ==(const CPerson* person);

	void SetName(char* name);
	char* GetName(){return(m_Name);};
	CPerson::CPerson();
	CPerson::~CPerson();

	friend ostream & operator<<(ostream & out, CPerson & person);
};

#endif