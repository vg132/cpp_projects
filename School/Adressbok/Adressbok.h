// Adressbok.h : main header file for the ADRESSBOK application
//

#if !defined(AFX_ADRESSBOK_H__336B1A29_956B_11D5_95CA_00B0D064C66D__INCLUDED_)
#define AFX_ADRESSBOK_H__336B1A29_956B_11D5_95CA_00B0D064C66D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAdressbokApp:
// See Adressbok.cpp for the implementation of this class
//

class CAdressbokApp : public CWinApp
{
public:
	CAdressbokApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdressbokApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAdressbokApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADRESSBOK_H__336B1A29_956B_11D5_95CA_00B0D064C66D__INCLUDED_)
