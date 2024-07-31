#if !defined(AFX_MEMBEREDIT_H__A9BC0E13_8C6D_4EBD_ADA6_1C7F32D02337__INCLUDED_)
#define AFX_MEMBEREDIT_H__A9BC0E13_8C6D_4EBD_ADA6_1C7F32D02337__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MemberEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMemberEdit form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "Member.h"

class CMemberEdit : public CFormView
{
protected:
	CMemberEdit();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMemberEdit)

// Form Data
public:
	//{{AFX_DATA(CMemberEdit)
	enum { IDD = IDD_MEMBER };
	CString	m_Address;
	CString	m_FirstName;
	CString	m_LastName;
	int		m_MemberId;
	COleDateTime	m_MemberSence;
	COleDateTime	m_MemberTo;
	CString	m_Phone;
	COleDateTime	m_DateOfBirth;
	int		m_MemberType;
	//}}AFX_DATA

// Attributes
public:
// Operations
public:
	void LoadData();
	CMember *m;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMemberEdit)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMemberEdit();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CMemberEdit)
	afx_msg void OnSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEMBEREDIT_H__A9BC0E13_8C6D_4EBD_ADA6_1C7F32D02337__INCLUDED_)
