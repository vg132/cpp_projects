// Gp1 Lap Editor.h : main header file for the GP1 LAP EDITOR application
//

#if !defined(AFX_GP1LAPEDITOR_H__E5BC7004_3681_11D4_A39C_0008C7636E27__INCLUDED_)
#define AFX_GP1LAPEDITOR_H__E5BC7004_3681_11D4_A39C_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGp1LapEditorApp:
// See Gp1 Lap Editor.cpp for the implementation of this class
//

class CGp1LapEditorApp : public CWinApp
{
public:
	CGp1LapEditorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGp1LapEditorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGp1LapEditorApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GP1LAPEDITOR_H__E5BC7004_3681_11D4_A39C_0008C7636E27__INCLUDED_)
