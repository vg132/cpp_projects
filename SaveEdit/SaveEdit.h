// SaveEdit.h : main header file for the SAVEEDIT application
//

#if !defined(AFX_SAVEEDIT_H__4CE8A824_6AF3_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_SAVEEDIT_H__4CE8A824_6AF3_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "SaveEditDoc.h"
#include "MainFrm.h"
/////////////////////////////////////////////////////////////////////////////
// CSaveEditApp:
// See SaveEdit.cpp for the implementation of this class
//

class CSaveEditApp : public CWinApp
{
public:
	CSaveEditApp();
	CSaveEditDoc* m_pDoc;
	CMainFrame* m_MainFrame;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSaveEditApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSaveEditApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAVEEDIT_H__4CE8A824_6AF3_11D4_8FC7_0008C7636E27__INCLUDED_)
