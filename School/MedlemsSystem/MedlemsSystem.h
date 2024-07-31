// MedlemsSystem.h : main header file for the MEDLEMSSYSTEM application
//

#if !defined(AFX_MEDLEMSSYSTEM_H__3B3EC966_EF69_4741_BD41_F4BFD2B70111__INCLUDED_)
#define AFX_MEDLEMSSYSTEM_H__3B3EC966_EF69_4741_BD41_F4BFD2B70111__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "MedlemsSystemDoc.h"
#include "MainFrm.h"

/////////////////////////////////////////////////////////////////////////////
// CMedlemsSystemApp:
// See MedlemsSystem.cpp for the implementation of this class
//

class CMedlemsSystemApp : public CWinApp
{
public:
	CMedlemsSystemApp();
	CMedlemsSystemDoc* m_pDoc;
	CMainFrame* m_MainFrame;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMedlemsSystemApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMedlemsSystemApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEDLEMSSYSTEM_H__3B3EC966_EF69_4741_BD41_F4BFD2B70111__INCLUDED_)
