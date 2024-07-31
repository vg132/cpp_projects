#ifndef __PERSON__
#define __PERSON__
#include "Person.h"

class CPerson  
{
private:
	char *FirstName;
	char *LastName;
	char *Address;
	char *Phone;
	COleDateTime BirthDay;
	int BirthId;
	char *tmp;

public:
	CPerson();
	~CPerson();

	void SetLastName(char *lastname);
	void SetFirstName(char *firstname);
	void SetAddress(char *address);
	void SetPhone(char *phone);
	void SetBirthDay(int year, int month, int day);
	void SetBirthDay(COleDateTime *birthday);
	void SetBirthId(int birthid);

	char* GetLastName();
	char* GetFirstName();
	char* GetAddress();
	char* GetPhone();
	COleDateTime GetBirthDay();
	int GetBirthId();
};
#endif