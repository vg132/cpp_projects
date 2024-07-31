// F1C_ReplaySaver.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols


// CF1C_ReplaySaverApp:
// See F1C_ReplaySaver.cpp for the implementation of this class
//

class CF1C_ReplaySaverApp : public CWinApp
{
public:
	CF1C_ReplaySaverApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CF1C_ReplaySaverApp theApp;