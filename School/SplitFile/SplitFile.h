// SplitFile.h : main header file for the SPLITFILE application
//

#if !defined(AFX_SPLITFILE_H__56CA1E66_551B_4E5F_B73B_95D38617FC52__INCLUDED_)
#define AFX_SPLITFILE_H__56CA1E66_551B_4E5F_B73B_95D38617FC52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSplitFileApp:
// See SplitFile.cpp for the implementation of this class
//

class CSplitFileApp : public CWinApp
{
public:
	CSplitFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSplitFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSplitFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLITFILE_H__56CA1E66_551B_4E5F_B73B_95D38617FC52__INCLUDED_)
