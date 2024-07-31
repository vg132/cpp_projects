#include <iostream>
using namespace std;
#include "MyList.h"

CMyList* m_MyList;

void TestFunc();

void main()
{
	m_MyList=new CMyList();
	TestFunc();
	CPerson* p;
	m_MyList->RemovePerson(1);
	p=m_MyList->GetPerson(1);
	cout << p->GetName() << endl;
}

void TestFunc()
{
	CPerson* p;
	p=new CPerson();
	p->SetName("Viktor");
	m_MyList->AddPerson(p);
	p=new CPerson();
	p->SetName("Gars1");
	m_MyList->AddPerson(p);
	p=new CPerson();
	p->SetName("Gars3");
	m_MyList->AddPerson(p);
}