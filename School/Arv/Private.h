#ifndef __PRIVATE__H__
#define __PRIVATE__H__

#include "BaseClass.h"

class CPrivate : private BaseClass
{
private:
	int m_PrivateValue;
public:
	int GetPrivateValue(){return(m_PrivateValue);};
	void SetPrivateValue(int value){m_PrivateValue=value;};

	void SetPrivateBaseValue(int value){BaseClass::SetBaseValue(value);};
	int GetPrivateBaseValue(){return(BaseClass::GetBaseValue());};

	void SetPrivateStaticValue(int value){BaseClass::SetStaticBaseValue(value);};
	int GetPrivateStaticValue(){return(BaseClass::GetStaticBaseValue());};
};

#endif
