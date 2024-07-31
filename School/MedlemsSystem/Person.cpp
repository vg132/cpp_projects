#include "StdAfx.h"
#include "Person.h"

CPerson::CPerson()
{
	FirstName=NULL;
	LastName=NULL;
	Address=NULL;
	Phone=NULL;
	BirthDay=BirthDay.GetCurrentTime();
}

CPerson::~CPerson()
{
	delete[] Phone;
	delete[] Address;
	delete[] LastName;
	delete[] FirstName;
}

void CPerson::SetLastName(char *lastname)
{
	LastName = new char[strlen(lastname)];
	strcpy(LastName,lastname);
}

void CPerson::SetFirstName(char *firstname)
{
	FirstName = new char[strlen(firstname)];
	strcpy(FirstName,firstname);
}

void CPerson::SetAddress(char *address)
{
	Address = new char[strlen(address)];
	strcpy(Address,address);
}

void CPerson::SetPhone(char *phone)
{
	Phone = new char[strlen(phone)];
	strcpy(Phone,phone);
}

void CPerson::SetBirthDay(int year, int month, int day)
{
	BirthDay.SetDate(year,month,day);
}

void CPerson::SetBirthDay(COleDateTime *birthday)
{
	BirthDay.SetDate(birthday->GetYear(),birthday->GetMonth(),birthday->GetDay());
}

void CPerson::SetBirthId(int birthid)
{
	BirthId=birthid;
}

char* CPerson::GetLastName()
{
	if(LastName!=NULL)
		return(LastName);
	else
		return("");
}

char* CPerson::GetFirstName()
{
	if(FirstName!=NULL)
		return(FirstName);
	else
		return("");
}

char* CPerson::GetAddress()
{
	if(Address!=NULL)
		return(Address);
	else
		return("");
}

char* CPerson::GetPhone()
{
	if(Phone!=NULL)
		return(Phone);
	else
		return("");
}

COleDateTime CPerson::GetBirthDay()
{
	return(BirthDay);
}

int CPerson::GetBirthId()
{
	return(BirthId);
}
