// F1ImageInfo.h : main header file for the F1IMAGEINFO application
//

#if !defined(AFX_F1IMAGEINFO_H__9156718F_48BE_40C7_9BCA_35C4A717CED1__INCLUDED_)
#define AFX_F1IMAGEINFO_H__9156718F_48BE_40C7_9BCA_35C4A717CED1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include <fstream.h>
#define BUFFERSIZE	65535

/////////////////////////////////////////////////////////////////////////////
// CF1ImageInfoApp:
// See F1ImageInfo.cpp for the implementation of this class
//

class CF1ImageInfoApp : public CWinApp
{
public:
	CF1ImageInfoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CF1ImageInfoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CF1ImageInfoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_F1IMAGEINFO_H__9156718F_48BE_40C7_9BCA_35C4A717CED1__INCLUDED_)
