#if !defined(AFX_TEAMTECH_H__4CE8A836_6AF3_11D4_8FC7_0008C7636E27__INCLUDED_)
#define AFX_TEAMTECH_H__4CE8A836_6AF3_11D4_8FC7_0008C7636E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TeamTech.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTeamTech form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CTeamTech : public CFormView
{
public:
	CTeamTech();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTeamTech)

// Form Data
public:
	//{{AFX_DATA(CTeamTech)
	enum { IDD = IDD_WORK_ENGINEER };
	CSpinButtonCtrl	m_Spin_Spares;
	CSpinButtonCtrl	m_Spin_ThisCar;
	CSpinButtonCtrl	m_Spin_Tech;
	CSpinButtonCtrl	m_Spin_NextCar;
	CSpinButtonCtrl	m_Spin_Chassis;
	CSpinButtonCtrl	m_Spin_Aids;
	int		m_Aids;
	int		m_Chassis;
	int		m_NextCar;
	int		m_Spares;
	int		m_Tech;
	int		m_ThisCar;
	//}}AFX_DATA

// Attributes
public:
	int m_Id;
// Operations
public:
	void Save(CString file);
	void SetSpin();
	void Load(int id, CString file);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTeamTech)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTeamTech();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CTeamTech)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEAMTECH_H__4CE8A836_6AF3_11D4_8FC7_0008C7636E27__INCLUDED_)
