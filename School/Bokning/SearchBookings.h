#if !defined(AFX_SEARCHBOOKINGS_H__3A98D046_A1EB_11D5_95E2_00B0D064C66D__INCLUDED_)
#define AFX_SEARCHBOOKINGS_H__3A98D046_A1EB_11D5_95E2_00B0D064C66D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SearchBookings.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSearchBookings dialog

#include "Person.h"
#include "Booking.h"
#include "Room.h"
#include "List.h"
#include "Id.h"

class CSearchBookings : public CDialog
{
private:
	List<CPerson>* m_ListPersons;
	List<CPerson>* m_FoundPersons;
	List<CBooking>* m_ListBookings;
	List<CBooking>* m_FoundBookins;
	List<CRoom>* m_ListRooms;
	List<CRoom>* m_FoundRooms;
public:
	void SetRooms(List<CRoom>* rooms);
	void SetBookings(List<CBooking>* bookings);
	void SetPersons(List<CPerson>* persons);
	CSearchBookings(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSearchBookings)
	enum { IDD = IDD_VIEW_BOOKINGS };
	CTreeCtrl	m_Tree;
	CTime	m_From;
	CTime	m_To;
	BOOL	m_bFirstName;
	BOOL	m_bLastName;
	BOOL	m_bTimeSpan;
	BOOL	m_bPersonID;
	BOOL	m_bBookingID;
	CString	m_BookingID;
	CString	m_FirstName;
	CString	m_LastName;
	CString	m_PersonID;
	int		m_iPerson;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchBookings)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSearchBookings)
	afx_msg void OnButtonSearch();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHBOOKINGS_H__3A98D046_A1EB_11D5_95E2_00B0D064C66D__INCLUDED_)
