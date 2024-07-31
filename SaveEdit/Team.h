#if !defined(AFX_TEAM_H__5A697A0B_6ECD_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_TEAM_H__5A697A0B_6ECD_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Team.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTeam form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CTeam : public CFormView
{
protected:
	CTeam();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTeam)

// Form Data
public:
	//{{AFX_DATA(CTeam)
	enum { IDD = IDD_TEAM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTeam)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTeam();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CTeam)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEAM_H__5A697A0B_6ECD_11D4_8FC7_0008C7636E27__INCLUDED_)
