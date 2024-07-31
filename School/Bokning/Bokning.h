// Bokning.h : main header file for the BOKNING application
//

#if !defined(AFX_BOKNING_H__D48708CF_B281_4828_B2C4_108821B81221__INCLUDED_)
#define AFX_BOKNING_H__D48708CF_B281_4828_B2C4_108821B81221__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBokningApp:
// See Bokning.cpp for the implementation of this class
//

class CBokningApp : public CWinApp
{
public:
	CBokningApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBokningApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBokningApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOKNING_H__D48708CF_B281_4828_B2C4_108821B81221__INCLUDED_)
