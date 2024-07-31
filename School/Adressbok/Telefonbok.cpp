// Telefonbok.cpp: implementation of the Telefonbok class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Adressbok.h"
#include "Telefonbok.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Telefonbok::Telefonbok()
{
	filename=NULL;
	personlista=NULL;
	resultlist=NULL;
	id=0;
//	personlista=new List<Person>;
}

Telefonbok::~Telefonbok()
{
	delete[] filename;
	delete resultlist;
}

bool Telefonbok::AddPerson(Person* p)
{
	p->SetId(id++);
	personlista->Add(p);
	return(true);
}

Person* Telefonbok::GetPersonByPos(int pos)
{
	return(personlista->GetItem(pos));
}

Person* Telefonbok::GetPersonById(int id)
{
	for(int i=0;i<personlista->GetSize();i++)
	{
		if((personlista->GetItem(i))->GetId()==id)
			return(personlista->GetItem(i));
	};
	return(NULL);
}

bool Telefonbok::RemovePersonById(int id)
{
	for(int i=0;i<personlista->GetSize();i++)
	{
		if((personlista->GetItem(i))->GetId()==id)
			return(personlista->Remove(i));
	};
	return(false);
}

bool Telefonbok::RemovePersonByPos(int pos)
{
	return(personlista->Remove(id));
}

bool Telefonbok::Open(char* filename)
{
	id=0;
	char buffer[600];

	fin.open(filename);
	fin.seekg(0,ios::beg);

	if(this->filename!=NULL)
		delete[] this->filename;
	this->filename=new char[strlen(filename)+1];
	strcpy(this->filename,filename);
	delete personlista;
	personlista=new List<Person>;
	while(fin.getline(buffer,600,'\0'))
	{
		st=new StringTokenizer(buffer,'|');
		if(st->HasMoreTokens())
		{
			p=new Person;
			p->SetFirstName(st->NextToken());
			p->SetLastName(st->NextToken());
			p->SetCity(st->NextToken());
			p->SetPhone(st->NextToken());
			p->SetAddress(st->NextToken());
			p->SetPostNr(st->NextToken());
			p->SetId(atoi(st->NextToken()));
			if(p->GetId()>id)
				id=p->GetId();
			personlista->Add(p);
		}
		delete st;
	};
	fin.close();
	fin.clear();
	id++;
	return(true);
}

bool Telefonbok::Save(char* filename)
{
	if(filename!=NULL)
		fout.open(filename);
	else if(this->filename!=NULL)
		fout.open(this->filename);
	else
		return(false);
	for(int i=0;i<personlista->GetSize();i++)
	{
		p=personlista->GetItem(i);
		fout << p->GetData() << '\0';
	}
	fout.close();
	return(true);
}

void Telefonbok::Search(char *buffer)
{
	int iLoop(0);
	int i(0);
	char* tmp;
	char* buffer2;
	Person* p;
	resultlist=new List<Person>;
	StringTokenizer* st=new StringTokenizer(buffer,'|');
	for(i=0;i<personlista->GetSize();i++)
	{
		buffer2=new char[600];
		buffer2[0]='\0';
		st->Reset();
		p=personlista->GetItem(i);
		tmp=st->NextToken();
		if(tmp!=NULL&&strcmp(tmp,""))
			strcat(buffer2,p->GetFirstName());
		strcat(buffer2,"|");
		tmp=st->NextToken();
		if(tmp!=NULL&&strcmp(tmp,""))
			strcat(buffer2,p->GetLastName());
		strcat(buffer2,"|");
		tmp=st->NextToken();
		if(tmp!=NULL&&strcmp(tmp,""))
			strcat(buffer2,p->GetAddress());
		strcat(buffer2,"|");
		tmp=st->NextToken();
		if(tmp!=NULL&&strcmp(tmp,""))
			strcat(buffer2,p->GetPostNr());
		strcat(buffer2,"|");
		tmp=st->NextToken();
		if(tmp!=NULL&&strcmp(tmp,""))
			strcat(buffer2,p->GetCity());
		strcat(buffer2,"|");
		tmp=st->NextToken();
		if(tmp!=NULL&&strcmp(tmp,""))
			strcat(buffer2,p->GetPhone());
		if(!strcmp(buffer,buffer2))
			resultlist->Add(p);
		delete[] buffer2;
	}
}

Person* Telefonbok::GetSearchResult(int pos)
{
	return(resultlist->GetItem(pos));
}

int Telefonbok::GetSearchResultSize()
{
	return(resultlist->GetSize());
}

void Telefonbok::New()
{
	delete[] filename;
	delete resultlist;
	delete personlista;
	personlista=new List<Person>;
	filename=NULL;
	resultlist=NULL;
}

void Telefonbok::Close()
{
	delete[] filename;
	delete resultlist;
	delete personlista;
	filename=NULL;
	resultlist=NULL;
}
