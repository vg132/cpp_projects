#ifndef __CROOM_H__
#define __CROOM_H__

#include <iostream.h>
#include <fstream.h>

#include "List.h"
#include "Booking.h"
#include "Person.h"

class CRoom
{
private:
	List<CBooking> m_Bookings;
	int m_Price;
	int m_Type;
	char* m_Name;
	static int m_Id;
public:
	bool IsRoomFree(CTime from, CTime to);
	bool AddBokning(CPerson* person, CTime from, CTime to);
	void SetPrice(int price){m_Price=price;};
	void SetType(int type){m_Type=type;};
	void SetName(char* name);

	int GetPrice(){return(m_Price);};
	int GetType(){return(m_Type);};	
	char* GetName(){return(m_Name);};
	CRoom();
	virtual ~CRoom();

	friend ofstream & operator<<(ofstream & fos, CRoom & room);
};

#endif