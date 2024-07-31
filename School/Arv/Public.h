#ifndef __PUBLIC__H__
#define __PUBLIC__H__

#include "BaseClass.h"

class CPublic : public BaseClass
{
private:
	int m_PublicValue;
public:
	int GetPublicValue(){return(m_PublicValue);};
	void SetPublicValue(int value){m_PublicValue=value;};
};

#endif