#if !defined(AFX_INFO_H__F73FA520_6BD0_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_INFO_H__F73FA520_6BD0_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Info.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInfo form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CInfo : public CFormView
{
protected:
	CInfo();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CInfo)

// Form Data
public:
	//{{AFX_DATA(CInfo)
	enum { IDD = IDD_FILEINFO };
	int		m_CHPoints;
	int		m_CHPos;
	CString	m_Created;
	int		m_CurrentYear;
	CString	m_Modified;
	CString	m_Player;
	int		m_Score;
	int		m_Seasons;
	CString	m_NextRace;
	CString	m_Team;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:
	bool Load(CString file);
	CString appPath;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInfo)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CInfo();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CInfo)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INFO_H__F73FA520_6BD0_11D4_8FC7_0008C7636E27__INCLUDED_)
