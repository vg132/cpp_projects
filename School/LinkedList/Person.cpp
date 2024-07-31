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
