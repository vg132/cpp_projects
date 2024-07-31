#include "../../Test/stdafx.h"
#include "..\Include\List.hpp"

CList::CList(void)
{
	_first=NULL;
	_last=NULL;
}

CList::~CList(void)
{
	if(_first!=NULL)
	{
		delete _first;
	}
}

void CList::AddLap(CLap *lap)
{
	CNode *node=new CNode(lap);
	if(_first==NULL)
	{
		_first=_last=node;
	}
	else if(_last!=NULL)
	{
		_last->SetNextNode(node);
		_last=_last->GetNextNode();
	}
}
