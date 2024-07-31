// SearchBookings.cpp : implementation file
//

#include "stdafx.h"
#include "bokning.h"
#include "SearchBookings.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSearchBookings dialog


CSearchBookings::CSearchBookings(CWnd* pParent /*=NULL*/)
	: CDialog(CSearchBookings::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSearchBookings)
	m_From = 0;
	m_To = 0;
	m_bFirstName = FALSE;
	m_bLastName = FALSE;
	m_bTimeSpan = FALSE;
	m_bPersonID = FALSE;
	m_bBookingID = FALSE;
	m_BookingID = _T("");
	m_FirstName = _T("");
	m_LastName = _T("");
	m_PersonID = _T("");
	m_iPerson = -1;
	//}}AFX_DATA_INIT
	m_ListPersons=NULL;
	m_FoundPersons=NULL;
	m_ListBookings=NULL;
	m_FoundBookins=NULL;
	m_ListRooms=NULL;
	m_FoundRooms=NULL;
}


void CSearchBookings::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSearchBookings)
	DDX_Control(pDX, IDC_TREE_RESULT, m_Tree);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_FROM, m_From);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_TO, m_To);
	DDX_Text(pDX, IDC_EDIT_BOOKINGID, m_BookingID);
	DDX_Text(pDX, IDC_EDIT_FIRSTNAME, m_FirstName);
	DDX_Text(pDX, IDC_EDIT_LASTNAME, m_LastName);
	DDX_Text(pDX, IDC_EDIT_PERSONID, m_PersonID);
	DDX_Radio(pDX, IDC_RADIO_PERSON, m_iPerson);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSearchBookings, CDialog)
	//{{AFX_MSG_MAP(CSearchBookings)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchBookings message handlers

void CSearchBookings::OnButtonSearch() 
{
	UpdateData(TRUE);
	if(m_iPerson==0)
	{

	}
	else
	{

	}
	UpdateData(FALSE);
}

void CSearchBookings::SetPersons(List<CPerson>* persons)
{
	m_ListPersons=persons;
}

void CSearchBookings::SetBookings(List<CBooking>* bookings)
{
	m_ListBookings=bookings;
}

void CSearchBookings::SetRooms(List<CRoom>* rooms)
{
	m_ListRooms=rooms;
}

void CSearchBookings::OnClose() 
{
	if(m_ListPersons!=NULL)
	{
		m_ListPersons->ReleaseAll();
		delete m_ListPersons;
	}
	if(m_FoundPersons!=NULL)
	{
		m_FoundPersons->ReleaseAll();
		delete m_FoundPersons;
	}
	if(m_ListBookings!=NULL)
	{
		m_ListBookings->ReleaseAll();
		delete m_ListBookings;
	}
	if(m_FoundBookins!=NULL)
	{
		m_FoundBookins->ReleaseAll();
		delete m_FoundBookins;
	}
	if(m_ListRooms!=NULL)
	{
		m_ListRooms->ReleaseAll();
		delete m_ListRooms;
	}
	if(m_FoundRooms!=NULL)
	{
		m_FoundRooms->ReleaseAll();
		delete m_FoundRooms;
	}

	CDialog::OnClose();
}
