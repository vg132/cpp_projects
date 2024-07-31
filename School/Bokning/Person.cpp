// Person.cpp: implementation of the CPerson class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Bokning.h"
#include "Person.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPerson::CPerson()
{
	m_FirstName=NULL;
	m_LastName=NULL;
	m_Address=NULL;
	m_PostNr=NULL;
	m_City=NULL;
	m_Phone=NULL;
	m_Country=NULL;
}

CPerson::~CPerson()
{
	if(m_FirstName!=NULL)
		delete[] m_FirstName;
	if(m_LastName!=NULL)
		delete[] m_LastName;
	if(m_Address!=NULL)
		delete[] m_Address;
	if(m_PostNr!=NULL)
		delete[] m_PostNr;
	if(m_City!=NULL)
		delete[] m_City;
	if(m_Phone!=NULL)
		delete[] m_Phone;
	if(m_Country!=NULL)
		delete[] m_Country;
}

void CPerson::SetFirstName(char* firstname)
{
	if(m_FirstName!=NULL)
		delete[] m_FirstName;
	m_FirstName=new char[strlen(firstname)+1];
	strcpy(m_FirstName,firstname);
}

void CPerson::SetLastName(char* lastname)
{
	if(m_LastName!=NULL)
		delete[] m_LastName;
	m_LastName=new char[strlen(lastname)+1];
	strcpy(m_LastName,lastname);
}

void CPerson::SetAddress(char* address)
{
	if(m_Address!=NULL)
		delete[] m_Address;
	m_Address=new char[strlen(address)+1];
	strcpy(m_Address,address);
}

void CPerson::SetPostNr(char* postnr)
{
	if(m_PostNr!=NULL)
		delete[] m_PostNr;
	m_PostNr=new char[strlen(postnr)+1];
	strcpy(m_PostNr,postnr);
}

void CPerson::SetCity(char* city)
{
	if(m_City!=NULL)
		delete[] m_City;
	m_City=new char[strlen(city)+1];
	strcpy(m_City,city);
}

void CPerson::SetPhone(char* phone)
{
	if(m_Phone!=NULL)
		delete[] m_Phone;
	m_Phone=new char[strlen(phone)+1];
	strcpy(m_Phone,phone);
}

void CPerson::SetCountry(char* country)
{
	if(m_Country!=NULL)
		delete[] m_Country;
	m_Country=new char[strlen(country)+1];
	strcpy(m_Country,country);
}

ofstream & operator<<(ofstream & fos, CPerson & person)
{
	fos << person.m_FirstName << "|" << person.m_LastName << "|" << person.m_Address << "|" << person.m_PostNr << "|" << person.m_City << "|" << person.m_Country << "|" << person.m_Phone << "|" << person.m_Invoice << "|" << person.m_Payd << "\n";
	return(fos);
}