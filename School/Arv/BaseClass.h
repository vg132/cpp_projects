#ifndef __BASECLASS__H__
#define __BASECLASS__H__

class BaseClass
{
private:
	int m_BaseValue;
	static int m_StaticBaseValue;
public:
	void SetBaseValue(int value){m_BaseValue=value;};
	int GetBaseValue(){return(m_BaseValue);};

	void SetStaticBaseValue(const int value){m_StaticBaseValue=value;};
	int GetStaticBaseValue(){return(m_StaticBaseValue);};
};
int BaseClass::m_StaticBaseValue = 0;
#endif