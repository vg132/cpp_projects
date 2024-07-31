#ifndef __CID__H__
#define __CID__H__

#include <time.h>

class CId  
{
private:
	char* m_Id;
	static int m_Counter;
public:
	char* GetId(){return(m_Id);};

	void SetId(char* id);

	CId();
	CId(char ch);
	virtual ~CId();

	void operator =(const CId *id);
	bool operator ==(const CId *id);
	bool operator !=(const CId *id);
};

#endif
