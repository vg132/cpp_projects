#include "Person.h"
#include "String.h"

CPerson::CPerson()
{
	m_Name=NULL;	
}

CPerson::~CPerson()
{
	if(m_Name!=NULL)
		delete[] m_Name;
}

void CPerson::SetName(char* name)
{
	if(m_Name!=NULL)
		delete[] m_Name;
	m_Name=new char[strlen(name)+1];
	strcpy(m_Name,name);
}

void CPerson::operator =(const CPerson* person)
{
	if(m_Name!=NULL)
		delete[] m_Name;
	m_Name=new char[strlen(person->m_Name)+1];
	strcpy(m_Name,person->m_Name);
}

bool CPerson::operator ==(const CPerson* person)
{
	return(!strcmp(m_Name,person->m_Name));
}

ostream & operator<<(ostream & out, CPerson & person)
{
	out << person.GetName();
	return(out);
}