// GPW Misc Edit.h : main header file for the GPW MISC EDIT application
//

#if !defined(AFX_GPWMISCEDIT_H__F8190658_81AA_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_GPWMISCEDIT_H__F8190658_81AA_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGPWMiscEditApp:
// See GPW Misc Edit.cpp for the implementation of this class
//

class CGPWMiscEditApp : public CWinApp
{
public:
	CGPWMiscEditApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGPWMiscEditApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGPWMiscEditApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GPWMISCEDIT_H__F8190658_81AA_11D4_8FC7_0008C7636E27__INCLUDED_)
