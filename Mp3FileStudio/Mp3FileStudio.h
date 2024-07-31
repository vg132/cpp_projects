// Mp3FileStudio.h : main header file for the MP3FILESTUDIO application
//

#if !defined(AFX_MP3FILESTUDIO_H__CC92B58B_B4F0_4A94_B191_DA495B5521B3__INCLUDED_)
#define AFX_MP3FILESTUDIO_H__CC92B58B_B4F0_4A94_B191_DA495B5521B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "LogTrace.h"


/////////////////////////////////////////////////////////////////////////////
// CMp3FileStudioApp:
// See Mp3FileStudio.cpp for the implementation of this class
//

class CMp3FileStudioApp : public CWinApp
{
public:
	CMp3FileStudioApp();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMp3FileStudioApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMp3FileStudioApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MP3FILESTUDIO_H__CC92B58B_B4F0_4A94_B191_DA495B5521B3__INCLUDED_)
