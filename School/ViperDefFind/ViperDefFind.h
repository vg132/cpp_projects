// ViperDefFind.h : main header file for the VIPERDEFFIND application
//

#if !defined(AFX_VIPERDEFFIND_H__3FAD26AC_E871_44D1_B154_D07679A20E7A__INCLUDED_)
#define AFX_VIPERDEFFIND_H__3FAD26AC_E871_44D1_B154_D07679A20E7A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CViperDefFindApp:
// See ViperDefFind.cpp for the implementation of this class
//

class CViperDefFindApp : public CWinApp
{
public:
	CViperDefFindApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViperDefFindApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CViperDefFindApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIPERDEFFIND_H__3FAD26AC_E871_44D1_B154_D07679A20E7A__INCLUDED_)
