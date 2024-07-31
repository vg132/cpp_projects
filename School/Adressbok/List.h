#ifndef __LIST__H__
#define __LIST__H__

#include <stdlib.h>

template <class U>
class Node
{
public:
	U *Item;
	Node *NextNode;
	Node() { NextNode = NULL; }
	~Node()	{ if (NextNode != NULL) delete NextNode; }
};

template <class T>
class List
{
private:
	Node <T> *FirstItem;
	Node <T> *LastItem;
	Node <T> *CurrentItem;
	int Size;
public:
	List() { Size = 0; FirstItem = NULL; LastItem = NULL;}
	bool Add(T *ItemData);
	bool Remove(int pos);
	int GetSize();
	T* GetItem(int pos);
	T* GetCurrentItem();
};

template <class T>
bool List<T>::Add(T *ItemData)
{
	Node <T> *temp;
	temp = new Node <T>;
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
bool List<T>::Remove(int pos)
{
	Node<T> *Free, *NewNext;

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
int List<T>::GetSize()
{
	return(Size);
}

template <class T>
T* List<T>::GetItem(int pos)
{
	CurrentItem=FirstItem;
	for(int i=0;i<pos;i++)
		CurrentItem=CurrentItem->NextNode;
	return(CurrentItem->Item);
}

template <class T>
T* List<T>::GetCurrentItem()
{
	return(&CurrentItem->Item);
}

#endif