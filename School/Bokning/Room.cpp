// Room.cpp: implementation of the CRoom class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Bokning.h"
#include "Room.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int CRoom::m_Id=0;

CRoom::CRoom()
{
	m_Name=NULL;
	m_Id++;
}

CRoom::~CRoom()
{
	if(m_Name!=NULL)
		delete[] m_Name;
}

void CRoom::SetName(char* name)
{
	if(m_Name!=NULL)
		delete[] m_Name;
	m_Name=new char[strlen(name)+1];
	strcpy(m_Name,name);
}

bool CRoom::AddBokning(CPerson *person, CTime from, CTime to)
{
	CBooking* booking=new CBooking();
	booking->SetPerson(person);
	booking->SetRoomId(m_Id);
	booking->SetFrom(from);
	booking->SetTo(to);
	person->AddBookingId(booking->GetId());
	m_Bookings.Add(booking);
	return(true);
}

bool CRoom::IsRoomFree(CTime from, CTime to)
{
	CBooking* booking;
	for(int i=0;i<m_Bookings.GetSize();i++)
	{
		booking=m_Bookings.GetItem(i);
		if(from<booking->GetTo()&&to>booking->GetFrom())
			return(false);
	}
	return(true);
}

ofstream & operator<<(ofstream & fos, CRoom & room)
{
	fos << room.m_Name << "|" << room.GetType() << "|" <<  room.GetPrice() << "\n";
	return(fos);
}