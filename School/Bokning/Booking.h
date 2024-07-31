#ifndef __CBOOKING__H__
#define __CBOOKING__H__

#include <iostream.h>
#include <fstream.h>

#include "Person.h"

class CBooking
{
private:
	CPerson* m_Person;
	CTime m_From;
	CTime m_To;
	int m_RoomId;

	static int m_Id;
public:
	void SetPerson(CPerson* person){m_Person=person;};
	void SetTo(CTime to){m_To=to;};
	void SetFrom(CTime from){m_From=from;};
	void SetRoomId(int roomId){m_RoomId=roomId;};

	CPerson* GetPerson(){return(m_Person);};
	int GetId(){return(m_Id);};
	int GetRoomId(){return(m_RoomId);};
	CTime GetTo(){return(m_To);};
	CTime GetFrom(){return(m_From);};


	CBooking();
	virtual ~CBooking();

	friend ofstream & operator<<(ofstream & fos, CBooking & booking);
};

#endif