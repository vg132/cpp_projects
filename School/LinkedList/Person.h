#ifndef __PERSON__H__
#define __PERSON__H__

#define NULL 0

class CPerson
{
private:
	char* m_Name;
public:
	void SetName(char* name);
	char* GetName(){return(m_Name);};
	CPerson();
	~CPerson();
};

#endif