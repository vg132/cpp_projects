#ifndef __TELEFONBOK_H__
#define __TELEFONBOK_H__

#include <iostream>
using namespace std;
#include <fstream>

#include "Person.h"
#include "List.h"
#include "StringTokenizer.h"

class Telefonbok  
{
private:
	char* filename;
	List<Person>* personlista;
	List<Person>* resultlist;
	StringTokenizer* st;
	ofstream fout;
	ifstream fin;
	Person* p;
	int id;
public:
	void Close();
	void New();
	int GetSearchResultSize();
	Person* GetSearchResult(int pos);
	void Search(char *buffer);
	bool AddPerson(Person* p);
	Person* GetPersonByPos(int pos);
	Person* GetPersonById(int id);
	bool RemovePersonById(int id);
	bool RemovePersonByPos(int pos);
	bool Save(char* filename=NULL);
	bool Open(char* filename);

	int GetSize(){return personlista->GetSize();};
	Telefonbok();
	~Telefonbok();
};

#endif
