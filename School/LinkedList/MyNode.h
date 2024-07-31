#ifndef __MYNODE__H__
#define __MYNODE__H__

#include "Person.h"

class CMyNode
{
public:
	CPerson* m_Item;
	CMyNode* m_NextItem;
	CMyNode()
	{
		m_NextItem=NULL;
		m_Item=NULL;
	};
	~CMyNode()
	{
		if(m_NextItem!=NULL)
			delete m_NextItem;
		delete m_Item;
	}

};

#endif