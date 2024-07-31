#ifndef __CPERSON_H__
#define __CPERSON_H__

#include <iostream.h>
#include <fstream.h>

#include "IntList.h"

class CPerson  
{
private:
	IntList<int> m_BookingIds;
	char* m_FirstName;
	char* m_LastName;
	char* m_Address;
	char* m_PostNr;
	char* m_City;
	char* m_Phone;
	char* m_Country;
	bool m_Invoice;
	bool m_Payd;
public:
	int GetBookings(){return(m_BookingIds.GetSize());};
	int GetBookingId(int id){return(m_BookingIds.GetItem(id));};
	void AddBookingId(int id){m_BookingIds.Add(id);};

	void SetFirstName(char* firstname);
	void SetLastName(char* lastname);
	void SetAddress(char* address);
	void SetPostNr(char* postnr);
	void SetCity(char* city);
	void SetPhone(char* phone);
	void SetCountry(char* country);
	void SetInvoice(bool invoice){m_Invoice=invoice;};
	void SetPayd(bool payd){m_Payd=payd;};

	char* GetFirstName(){return(m_FirstName);};
	char* GetLastName(){return(m_LastName);};
	char* GetAddress(){return(m_Address);};
	char* GetPostNr(){return(m_PostNr);};
	char* GetCity(){return(m_City);};
	char* GetPhone(){return(m_Phone);};
	char* GetCountry(){return(m_Country);};
	bool GetInvoice(bool invoice){return(m_Invoice);};
	bool GetPayd(bool payd){return(m_Payd);};

	CPerson();
	virtual ~CPerson();

	friend ofstream & operator<<(ofstream & fos, CPerson & person);
};

#endif
