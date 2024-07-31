#include <iostream.h>
#include "Person.h"


void main()
{
	CPerson* p1=new CPerson();
	CPerson* p2=new CPerson();

	p1->SetName("Kalle Anka");
	p2->SetName("Viktor Gars");
	if(*p1==p2)	//Typ samma som nedan
		cout << "Lika som bär!!!" << endl;
	else
		cout << "Olika som blåbär!!!" << endl;
	cout << p1->GetName() << endl << p2->GetName() << endl << endl;
	*p1=p2;	//Anroppa objektets tilldelnings operator, INTE pekarens
	if(*p1==p2) //Typ samma som ovan
		cout << "Lika som bär!!!" << endl;
	else
		cout << "Olika som blåbär!!!" << endl;
	cout << *p1 << endl << *p2 << endl; //typ igen samma som ovan
}