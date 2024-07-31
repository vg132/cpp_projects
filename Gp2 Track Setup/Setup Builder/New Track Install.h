// New Track Install.h : main header file for the NEW TRACK INSTALL application
//

#if !defined(AFX_NEWTRACKINSTALL_H__E3681864_CFFA_11D3_999B_0008C7636E27__INCLUDED_)
#define AFX_NEWTRACKINSTALL_H__E3681864_CFFA_11D3_999B_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNewTrackInstallApp:
// See New Track Install.cpp for the implementation of this class
//

class CNewTrackInstallApp : public CWinApp
{
public:
	CNewTrackInstallApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewTrackInstallApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNewTrackInstallApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWTRACKINSTALL_H__E3681864_CFFA_11D3_999B_0008C7636E27__INCLUDED_)
