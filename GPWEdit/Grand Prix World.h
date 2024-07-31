// Grand Prix World.h : main header file for the GRAND PRIX WORLD application
//

#if !defined(AFX_GRANDPRIXWORLD_H__7DC6BD1A_E594_4C64_97B6_F4BF07EA10B4__INCLUDED_)
#define AFX_GRANDPRIXWORLD_H__7DC6BD1A_E594_4C64_97B6_F4BF07EA10B4__INCLUDED_


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGrandPrixWorldApp:
// See Grand Prix World.cpp for the implementation of this class
//

class CGrandPrixWorldApp : public CWinApp
{
public:
	CGrandPrixWorldApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGrandPrixWorldApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGrandPrixWorldApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRANDPRIXWORLD_H__7DC6BD1A_E594_4C64_97B6_F4BF07EA10B4__INCLUDED_)
