// Gp3TrackInstaller.h : main header file for the GP3TRACKINSTALLER application
//

#if !defined(AFX_GP3TRACKINSTALLER_H__52F95F14_7744_4307_850D_24773346A2C1__INCLUDED_)
#define AFX_GP3TRACKINSTALLER_H__52F95F14_7744_4307_850D_24773346A2C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGp3TrackInstallerApp:
// See Gp3TrackInstaller.cpp for the implementation of this class
//

class CGp3TrackInstallerApp : public CWinApp
{
public:
	CGp3TrackInstallerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGp3TrackInstallerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGp3TrackInstallerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GP3TRACKINSTALLER_H__52F95F14_7744_4307_850D_24773346A2C1__INCLUDED_)
