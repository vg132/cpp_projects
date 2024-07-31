#ifndef __CBOOKINGVIEW__H__
#define __CBOOKINGVIEW__H__

#include <iostream.h>
#include <fstream.h>

#include "Person.h"
#include "List.h"
#include "Room.h"

class CBokningView : public CFormView
{
private:
	CPerson* m_Person;
	CRoom* m_Room;
	List<CRoom> m_ListRooms;
	List<CPerson> m_ListPersons;

protected: // create from serialization only
	CBokningView();
	DECLARE_DYNCREATE(CBokningView)

public:
	//{{AFX_DATA(CBokningView)
	enum { IDD = IDD_BOKNING_FORM };
	CListCtrl	m_Rooms;
	CString	m_PostNr;
	CString	m_Phone;
	CString	m_LastName;
	CString	m_FirstName;
	CString	m_Country;
	CString	m_City;
	CString	m_Address;
	CTime	m_To;
	CTime	m_From;
	int		m_Type;
	BOOL	m_Invoice;
	//}}AFX_DATA

// Attributes
public:
	CBokningDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBokningView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void EnableBooking(bool enable);
	virtual ~CBokningView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBokningView)
	afx_msg void OnButtonSearch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BokningView.cpp
inline CBokningDoc* CBokningView::GetDocument()
   { return (CBokningDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif
