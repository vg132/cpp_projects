#include "StdAfx.h"
#include "Member.h"

CMember::CMember()
{
	ID=0;
	MemberType=0;
	MemberSence=MemberSence.GetCurrentTime();
	MemberTo=MemberTo.GetCurrentTime();
}

CMember::~CMember()
{

}

void CMember::SetMemberSence(int year, int month, int day)
{
	MemberSence.SetDate(year,month,day);
}

void CMember::SetMemberSence(COleDateTime *membersence)
{
	MemberSence.SetDate(membersence->GetYear(),membersence->GetMonth(),membersence->GetDay());
}

void CMember::SetMemberTo(int year, int month, int day)
{
	MemberTo.SetDate(year,month,day);
}

void CMember::SetMemberTo(COleDateTime *memberto)
{
	MemberTo.SetDate(memberto->GetYear(),memberto->GetMonth(),memberto->GetDay());
}

void CMember::SetMemberId(int id)
{
	ID=id;
}

void CMember::SetMemberType(int type)
{
	MemberType = type;
}

COleDateTime CMember::GetMemberSence()
{
	return(MemberSence);
}

COleDateTime CMember::GetMemberTo()
{
	return(MemberTo);
}

int CMember::GetMemberId()
{
	return(ID);
}

int CMember::GetMemberType()
{
	return(MemberType);
}