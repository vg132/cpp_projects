#ifndef __MEMBER__
#define __MEMBER__
#include "Person.h"

class CMember : public CPerson  
{
private:
	int ID;
	int MemberType;
	COleDateTime MemberSence;
	COleDateTime MemberTo;
public:
	CMember();
	~CMember();
	void SetMemberSence(int year, int month, int day);
	void SetMemberSence(COleDateTime *membersence);
	void SetMemberTo(int year, int month, int day);
	void SetMemberTo(COleDateTime *memberto);
	void SetMemberId(int id);
	void SetMemberType(int type);

	COleDateTime GetMemberSence();
	COleDateTime GetMemberTo();
	int GetMemberId();
	int GetMemberType();
};
#endif