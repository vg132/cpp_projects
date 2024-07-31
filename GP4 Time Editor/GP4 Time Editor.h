// GP4 Time Editor.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols


// CGP4TimeEditorApp:
// See GP4 Time Editor.cpp for the implementation of this class
//

class CGP4TimeEditorApp : public CWinApp
{
public:
	CGP4TimeEditorApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CGP4TimeEditorApp theApp;