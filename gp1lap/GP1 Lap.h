// GP1 Lap.h : main header file for the GP1 LAP application
//

#if !defined(AFX_GP1LAP_H__3A0AF5A6_BB9E_11D3_999B_0008C7636E27__INCLUDED_)
#define AFX_GP1LAP_H__3A0AF5A6_BB9E_11D3_999B_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGP1LapApp:
// See GP1 Lap.cpp for the implementation of this class
//

class CGP1LapApp : public CWinApp
{
public:
	CGP1LapApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGP1LapApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGP1LapApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GP1LAP_H__3A0AF5A6_BB9E_11D3_999B_0008C7636E27__INCLUDED_)
