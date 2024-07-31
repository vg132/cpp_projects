#ifndef __MYLIST__H__
#define __MYLIST__H__

#include "MyNode.h"

class CMyList
{
private:
	CMyNode* m_First;
	CMyNode* m_Last;
	CMyNode* m_Current;
	int m_Size;
public:
	void AddPerson(CPerson* p);
	CPerson* GetPerson(int pos);
	void RemovePerson(int pos);
	int GetSize();
	CMyList();
	~CMyList();
};

#endif