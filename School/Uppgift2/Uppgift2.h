// Uppgift2.h : main header file for the UPPGIFT2 application
//

#if !defined(AFX_UPPGIFT2_H__B6D99625_9ADA_11D5_95D4_00B0D064C66D__INCLUDED_)
#define AFX_UPPGIFT2_H__B6D99625_9ADA_11D5_95D4_00B0D064C66D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUppgift2App:
// See Uppgift2.cpp for the implementation of this class
//

class CUppgift2App : public CWinApp
{
public:
	CUppgift2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUppgift2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUppgift2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPPGIFT2_H__B6D99625_9ADA_11D5_95D4_00B0D064C66D__INCLUDED_)
