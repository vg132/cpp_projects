#ifndef __PERSON_H__
#define __PERSON_H__

class Person
{
private:
	char* city;
	char* postnr;
	char* address;
	char* phone;
	char* lastname;
	char* firstname;
	int size;
	int id;

	int GetSize();
public:
	void SetCity(char* city);
	void SetPostNr(char* postnr);
	void SetAddress(char* address);
	void SetPhone(char* phone);
	void SetLastName(char* lastname);
	void SetFirstName(char* firstname);
	void SetId(int id){this->id = id;};

	char* GetCity(){return city;};
	char* GetPostNr(){return postnr;};
	char* GetAddress(){return address;};
	char* GetPhone(){return phone;};
	char* GetLastName(){return lastname;};
	char* GetFirstName(){return firstname;};
	int GetId(){return id;};

	char* GetData();

	Person();
	~Person();
};

#endif
