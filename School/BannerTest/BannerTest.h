// BannerTest.h : main header file for the BANNERTEST application
//

#if !defined(AFX_BANNERTEST_H__0499946D_749F_4D13_B4E0_3A8EA727609F__INCLUDED_)
#define AFX_BANNERTEST_H__0499946D_749F_4D13_B4E0_3A8EA727609F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBannerTestApp:
// See BannerTest.cpp for the implementation of this class
//

class CBannerTestApp : public CWinApp
{
public:
	CBannerTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBannerTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBannerTestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BANNERTEST_H__0499946D_749F_4D13_B4E0_3A8EA727609F__INCLUDED_)
