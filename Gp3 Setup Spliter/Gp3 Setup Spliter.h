// Gp3 Setup Spliter.h : main header file for the GP3 SETUP SPLITER application
//

#if !defined(AFX_GP3SETUPSPLITER_H__E5435496_E3AA_4C93_8117_069DA2276287__INCLUDED_)
#define AFX_GP3SETUPSPLITER_H__E5435496_E3AA_4C93_8117_069DA2276287__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
/////////////////////////////////////////////////////////////////////////////
// CGp3SetupSpliterApp:
// See Gp3 Setup Spliter.cpp for the implementation of this class
//

class CGp3SetupSpliterApp : public CWinApp
{
public:
	CGp3SetupSpliterApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGp3SetupSpliterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGp3SetupSpliterApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GP3SETUPSPLITER_H__E5435496_E3AA_4C93_8117_069DA2276287__INCLUDED_)
