// Person.cpp: implementation of the Person class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Adressbok.h"
#include "Person.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Person::Person()
{
	city=NULL;
	postnr=NULL;
	address=NULL;
	phone=NULL;
	lastname=NULL;
	firstname=NULL;
}

Person::~Person()
{
	delete[] firstname;
	delete[] lastname;
	delete[] phone;
	delete[] address;
	delete[] postnr;
	delete[] city;
}

void Person::SetFirstName(char *firstname)
{
	this->firstname=new char[strlen(firstname)+1];
	strcpy(this->firstname,firstname);
}	

void Person::SetLastName(char *lastname)
{
	this->lastname=new char[strlen(lastname)+1];
	strcpy(this->lastname,lastname);
}

void Person::SetPhone(char *phone)
{
	this->phone=new char[strlen(phone)+1];
	strcpy(this->phone,phone);
}

void Person::SetAddress(char *address)
{
	this->address=new char[strlen(address)+1];
	strcpy(this->address,address);
}

void Person::SetPostNr(char *postnr)
{
	this->postnr=new char[strlen(postnr)+1];
	strcpy(this->postnr,postnr);
}

void Person::SetCity(char *city)
{
	this->city=new char[strlen(city)+1];
	strcpy(this->city,city);
}

char* Person::GetData()
{
	char* data=new char[GetSize()+14];
	char* convdata=new char[9];
	data[0]='\0';
	if(firstname!=NULL)
		strcat(data,firstname);
	strcat(data,"|");
	if(lastname!=NULL)
		strcat(data,lastname);
	strcat(data,"|");
	if(city!=NULL)
		strcat(data,city);
	strcat(data,"|");
	if(phone!=NULL)
		strcat(data,phone);
	strcat(data,"|");
	if(address!=NULL)
		strcat(data,address);
	strcat(data,"|");
	if(postnr!=NULL)
		strcat(data,postnr);
	strcat(data,"|");
	itoa(id,convdata,10);
	strcat(data,convdata);
	return(data);
}

int Person::GetSize()
{
	int size(0);
	if(firstname!=NULL)
		size+=strlen(firstname);
	if(lastname!=NULL)
		size+=strlen(lastname);
	if(city!=NULL)
		size+=strlen(city);
	if(phone!=NULL)
		size+=strlen(phone);
	if(address!=NULL)
		size+=strlen(address);
	if(postnr!=NULL)
		size+=strlen(postnr);
	return(size);
}