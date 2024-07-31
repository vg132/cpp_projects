#include "MyList.h"

CMyList::CMyList()
{
	m_Last=NULL;
	m_First=NULL;
	m_Current=NULL;
	m_Size=0;
}

CMyList::~CMyList()
{
	delete m_First;
}

void CMyList::AddPerson(CPerson* p)
{
	CMyNode* tmpNode=new CMyNode();
	tmpNode->m_Item=p;
	if(m_Last!=NULL)
		m_Last->m_NextItem=tmpNode;
	if(m_First==NULL)
		m_First=tmpNode;
	m_Last=tmpNode;
	m_Current=tmpNode;
	m_Size++;
}

CPerson* CMyList::GetPerson(int pos)
{
	if(m_Size-1<pos)
		return(NULL);
	m_Current=m_First;
	for(int i=0;i<pos;i++)
		m_Current=m_Current->m_NextItem;
	return(m_Current->m_Item);
}

void CMyList::RemovePerson(int pos)
{
	if(m_Size-1<pos)
		return;
	m_Current=m_First;
	CMyNode* tmp;
	for(int i=0;i<pos-1;i++)
	{
		m_Current=m_Current->m_NextItem;
	}
	if(pos!=0)
		tmp=m_Current->m_NextItem;
	else
		tmp=m_Current;
	if(tmp==m_First)
	{
		m_Current=m_Current->m_NextItem;
		m_First->m_NextItem=NULL;
		delete m_First;
		m_First=m_Current;
	}
	else if(tmp==m_Last)
	{
		delete m_Last;
		m_Current->m_NextItem=NULL;
		m_Last=m_Current;
	}
	else
	{
		tmp=m_Current->m_NextItem;
		m_Current->m_NextItem=tmp->m_NextItem;
		tmp->m_NextItem=NULL;
		delete tmp;
	}
	m_Size--;
}

int CMyList::GetSize()
{
	return(m_Size);
}