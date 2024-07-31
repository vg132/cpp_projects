#if !defined(AFX_MAIN_H__E85C70B3_6C76_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_MAIN_H__E85C70B3_6C76_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Main.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMain form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CMain : public CFormView
{
protected:
	CMain();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMain)

// Form Data
public:
	//{{AFX_DATA(CMain)
	enum { IDD = IDD_MAIN };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMain)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMain();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CMain)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAIN_H__E85C70B3_6C76_11D4_8FC7_0008C7636E27__INCLUDED_)
