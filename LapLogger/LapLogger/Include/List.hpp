#pragma once

#define NULL 0
#include "Lap.hpp"
#include <iostream>

class CNode
{
private:
	//static int _size=0;
	CLap *_lap;
	CNode *_nextNode;
public:
	CLap* GetLap(){return _lap;};

	//int GetSize(){return _size;};

	void SetNextNode(CNode *node){_nextNode=node;};
	CNode* GetNextNode(){return _nextNode;};

	CNode(CLap* lap)
	{
		_lap=lap;
		_nextNode=NULL;
	};

	~CNode()
	{
		if(_nextNode!=NULL)
		{
			delete _nextNode;
		}
		delete _lap;
	};
};

class CList
{
private:
	CNode *_first;
	CNode *_last;
public:
	void AddLap(CLap *lap);

	CNode* GetFirst(){return _first;};

	CList(void);
	~CList(void);
};
