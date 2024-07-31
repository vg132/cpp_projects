#ifndef __INTLIST_H__
#define __INTLIST_H__

#include "StdAfx.h"

template <class U>
class IntNode
{
public:
	U Item;
	IntNode *NextNode;
	void ReleaseAll()
	{
		if(NextNode!=NULL)
			NextNode->ReleaseAll();
//		Item=NULL;
	};
	IntNode()
	{
		NextNode = NULL;	
	};
	~IntNode()
	{
		if (NextNode != NULL) 
			delete NextNode;
//		delete Item;
	};
};

template <class T>
class IntList
{
private:
	IntNode <T> *FirstItem;
	IntNode <T> *LastItem;
	IntNode <T> *CurrentItem;
	int Size;
public:
	IntList()
	{
		Size = 0;
		FirstItem = NULL;
		LastItem = NULL;
	}
	bool Add(T ItemData);
	bool Remove(int pos);
	bool Clear();
	int GetSize();
	T GetItem(int pos);
	T GetCurrentItem();
	void ReleaseAll();
	~IntList()
	{
		if(FirstItem!=NULL)
			delete FirstItem;
	};
};

template <class T>
bool IntList<T>::Add(T ItemData)
{
	IntNode <T> *temp;
	temp = new IntNode <T>;
	temp->Item = ItemData;
	if(LastItem!=NULL)
		LastItem->NextNode = temp;
	else
		FirstItem=temp;
	LastItem = temp;
	CurrentItem=temp;
  Size++;
	return true;
}

template <class T>
bool IntList<T>::Remove(int pos)
{
	IntNode<T> *Free, *NewNext;

	if(pos<0||pos>Size)
		return(false);
	if(Size==1)
	{
		delete FirstItem;
		FirstItem=NULL;
		LastItem=NULL;
		CurrentItem=NULL;
	}
	else if(pos==Size-1)
	{
		CurrentItem=FirstItem;
		for(int i=0;i<pos-1;i++)
			CurrentItem=CurrentItem->NextNode;
		Free=CurrentItem->NextNode;
		LastItem=CurrentItem;
		CurrentItem->NextNode=NULL;
		delete Free;
	}
	else if(pos==0)
	{
		NewNext=FirstItem->NextNode;
		FirstItem->NextNode=NULL;
		delete FirstItem;
		FirstItem=NewNext;
	}
	else
	{
		CurrentItem=FirstItem;
		for(int i=0;i<pos-1;i++)
			CurrentItem=CurrentItem->NextNode;
		Free=CurrentItem->NextNode;
		NewNext=Free->NextNode;
		Free->NextNode=NULL;
		CurrentItem->NextNode=NewNext;
		delete Free;
	}
	Size--;
	return(true);
}

template <class T>
int IntList<T>::GetSize()
{
	return(Size);
}

template <class T>
T IntList<T>::GetItem(int pos)
{
	CurrentItem=FirstItem;
	for(int i=0;i<pos;i++)
		CurrentItem=CurrentItem->NextNode;
	return(CurrentItem->Item);
}

template <class T>
T IntList<T>::GetCurrentItem()
{
	return(CurrentItem->Item);
}

template <class T>
bool IntList<T>::Clear()
{
	if(FirstItem==NULL)
		return(true);
	delete FirstItem;
	Size=0;
	FirstItem=NULL;
	LastItem=NULL;
	CurrentItem=NULL;
	return(true);
}

template <class T>
void IntList<T>::ReleaseAll()
{
	if(FirstItem!=NULL)
	{
		FirstItem->ReleaseAll();
		delete FirstItem;
	}
	FirstItem=NULL;
	LastItem=NULL;
	CurrentItem=NULL;
}

#endif