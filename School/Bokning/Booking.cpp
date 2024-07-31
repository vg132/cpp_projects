// Booking.cpp: implementation of the CBooking class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Bokning.h"
#include "Booking.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int CBooking::m_Id=0;

CBooking::CBooking()
{
	m_Id++;
}

CBooking::~CBooking()
{
}

ofstream & operator<<(ofstream & fos, CBooking & booking)
{
	fos << /*booking.m_From << "|" << booking.m_To << */"|" << booking.m_Person << "|" << booking.m_RoomId << "\n";
	return(fos);
}